#include "mm_emu_audio.h"

#include "core/mm_logger.h"

static void __static_error_check(ALenum code);
//////////////////////////////////////////////////////////////////////////
void mm_emu_audio_init(struct mm_emu_audio* p)
{
	mm_string_init(&p->device_name);

	mm_rbtset_string_init(&p->devices);

	mm_rbtset_u32_init(&p->pool);
	mm_rbtset_u32_init(&p->used);
	mm_rbtset_u32_init(&p->idle);
	p->rate_trim_border = MM_EMU_AUDIO_RATE_TRIM_BORDER_DEFAULT;
	p->rate_trim_number = MM_EMU_AUDIO_RATE_TRIM_NUMBER_DEFAULT;

	p->accumulation_limit = MM_EMU_AUDIO_ACCUMULATION_LIMIT_DEFAULT;

	p->nRate = 22050;
	p->nFormat = AL_FORMAT_MONO8;
	p->device = NULL;
	p->context = NULL;
	p->source = AL_NONE;

	mm_memset(p->ListenerOrientation, 0, sizeof(ALfloat) * 6);
}
void mm_emu_audio_destroy(struct mm_emu_audio* p)
{
	mm_emu_audio_BufferClear(p);

	assert(NULL == p->context && NULL == p->device && "you must DeleteSource.");
	//
	mm_string_destroy(&p->device_name);

	mm_rbtset_string_destroy(&p->devices);

	mm_rbtset_u32_destroy(&p->pool);
	mm_rbtset_u32_destroy(&p->used);
	mm_rbtset_u32_destroy(&p->idle);
	p->rate_trim_border = MM_EMU_AUDIO_RATE_TRIM_BORDER_DEFAULT;
	p->rate_trim_number = MM_EMU_AUDIO_RATE_TRIM_NUMBER_DEFAULT;

	p->accumulation_limit = MM_EMU_AUDIO_ACCUMULATION_LIMIT_DEFAULT;

	p->nRate = 22050;
	p->nFormat = AL_FORMAT_MONO8;
	p->device = NULL;
	p->context = NULL;
	p->source = AL_NONE;

	mm_memset(p->ListenerOrientation, 0, sizeof(ALfloat) * 6);
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_audio_SetDeviceName(struct mm_emu_audio* p, const char* device_name)
{
	mm_string_assigns(&p->device_name, device_name);
}
void mm_emu_audio_SetRate(struct mm_emu_audio* p, int nRate)
{
	p->nRate = nRate;
}
void mm_emu_audio_SetFormat(struct mm_emu_audio* p, ALenum nFormat)
{
	p->nFormat = nFormat;
}
//////////////////////////////////////////////////////////////////////////
ALuint mm_emu_audio_BufferAdd(struct mm_emu_audio* p)
{
	ALuint e = 0;

	alGenBuffers(1, &e);
	__static_error_check(alGetError());

	// add to pool set.
	mm_rbtset_u32_add(&p->pool, (mm_uint32_t)e);
	return e;
}
void mm_emu_audio_BufferRmv(struct mm_emu_audio* p, ALuint e)
{
	// rmv to pool set.
	mm_rbtset_u32_rmv(&p->pool, (mm_uint32_t)e);

	alDeleteBuffers(1, &e);
	__static_error_check(alGetError());
}
void mm_emu_audio_BufferClear(struct mm_emu_audio* p)
{
	struct mm_rb_node* n = NULL;
	struct mm_rbtset_u32_iterator* it = NULL;
	ALuint e = 0;
	//
	n = mm_rb_first(&p->pool.rbt);
	while (NULL != n)
	{
		it = (struct mm_rbtset_u32_iterator*)mm_rb_entry(n, struct mm_rbtset_u32_iterator, n);
		e = (ALuint)(it->k);
		n = mm_rb_next(n);
		mm_rbtset_u32_erase(&p->pool, it);

		alDeleteBuffers(1, &e);
		__static_error_check(alGetError());
	}
}
ALuint mm_emu_audio_BufferProduce(struct mm_emu_audio* p)
{
	ALuint v = 0;

	struct mm_rb_node* n = NULL;
	struct mm_rbtset_u32_iterator* it = NULL;
	// min.
	n = mm_rb_last(&p->idle.rbt);
	if (NULL != n)
	{
		it = (struct mm_rbtset_u32_iterator*)mm_rb_entry(n, struct mm_rbtset_u32_iterator, n);
		v = (ALuint)it->k;
		// rmv to idle set.
		mm_rbtset_u32_rmv(&p->idle, v);
	}
	else
	{
		// add new.
		v = mm_emu_audio_BufferAdd(p);
		// add to used set.
		mm_rbtset_u32_add(&p->used, (mm_uint32_t)v);
	}
	return v;
}
void mm_emu_audio_Bufferrecycle(struct mm_emu_audio* p, ALuint v)
{
	float idle_sz = 0;
	float memb_sz = 0;
	int trim_number = 0;

	// rmv to used set.
	mm_rbtset_u32_rmv(&p->used, (mm_uint32_t)v);
	// add to idle set.
	mm_rbtset_u32_add(&p->idle, (mm_uint32_t)v);
	// 
	idle_sz = (float)p->idle.size;
	memb_sz = (float)p->pool.size;
	trim_number = (int)(memb_sz * p->rate_trim_number);

	if (idle_sz / memb_sz > p->rate_trim_border)
	{
		int i = 0;
		// 
		struct mm_rb_node* n = NULL;
		struct mm_rbtset_u32_iterator* it = NULL;
		// max
		n = mm_rb_first(&p->idle.rbt);
		while (NULL != n && i < trim_number)
		{
			it = (struct mm_rbtset_u32_iterator*)mm_rb_entry(n, struct mm_rbtset_u32_iterator, n);
			v = (ALuint)it->k;
			n = mm_rb_next(n);
			mm_rbtset_u32_erase(&p->idle, it);
			mm_emu_audio_BufferRmv(p, v);
			i++;
		}
	}
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_audio_DeviceList(struct mm_emu_audio* p)
{
	struct mm_string device_name;

	const ALCchar* deviceList = alcGetString(NULL, ALC_ALL_DEVICES_SPECIFIER);

	/*
	** The list returned by the call to alcGetString has the names of the
	** devices seperated by NULL characters and the list is terminated by
	** two NULL characters, so we can cast the list into a string and it
	** will automatically stop at the first NULL that it sees, then we
	** can move the pointer ahead by the lenght of that string + 1 and we
	** will be at the begining of the next string.  Once we hit an empty
	** string we know that we've found the double NULL that terminates the
	** list and we can stop there.
	*/

	mm_rbtset_string_clear(&p->devices);

	while (*deviceList != 0)
	{
		mm_string_make_weak(&device_name, deviceList);

		mm_rbtset_string_add(&p->devices, &device_name);

		deviceList += strlen(deviceList) + 1;
	}
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_audio_CreateSource(struct mm_emu_audio* p)
{
	struct mm_logger* g_logger = mm_logger_instance();

	ALint attribs[1] = { 4 };

	do
	{
		mm_emu_audio_DeviceList(p);

		if (0 == p->devices.size)
		{
			mm_logger_log_E(g_logger, "%s %d audio we not find any devices.", __FUNCTION__, __LINE__);
			break;
		}

		if (mm_string_empty(&p->device_name) || 0 == mm_rbtset_string_get(&p->devices, &p->device_name))
		{
			// If the suggested device is in the list we use it, otherwise select the default device
			p->device = alcOpenDevice((const ALCchar*)NULL);

			if (NULL == p->device)
			{
				mm_logger_log_E(g_logger, "%s %d audio device: default open failure.", __FUNCTION__, __LINE__);
				break;
			}
			else
			{
				mm_logger_log_I(g_logger, "%s %d audio device: default open success.", __FUNCTION__, __LINE__);
			}
		}
		else
		{
			p->device = alcOpenDevice((const ALCchar*)p->device_name.s);

			if (NULL == p->device)
			{
				mm_logger_log_E(g_logger, "%s %d audio device: %s open failure.", __FUNCTION__, __LINE__, p->device_name.s);
				break;
			}
			else
			{
				mm_logger_log_I(g_logger, "%s %d audio device: %s open success.", __FUNCTION__, __LINE__, p->device_name.s);
			}
		}

		p->context = alcCreateContext(p->device, attribs);
		if (NULL == p->context)
		{
			mm_logger_log_E(g_logger, "%s %d audio context create failure.", __FUNCTION__, __LINE__);
			break;
		}
		else
		{
			mm_logger_log_I(g_logger, "%s %d audio context create success.", __FUNCTION__, __LINE__);
		}

		alcMakeContextCurrent(p->context);
		__static_error_check(alGetError());

		alGenSources(1, &p->source);

		if (AL_NONE == p->source)
		{
			mm_logger_log_E(g_logger, "%s %d audio source create failure.", __FUNCTION__, __LINE__);
			break;
		}
		else
		{
			mm_logger_log_I(g_logger, "%s %d audio source create success.", __FUNCTION__, __LINE__);
		}

		alSourcei(p->source, AL_LOOPING, AL_FALSE);
		alSourcef(p->source, AL_GAIN, 1.0f);
		__static_error_check(alGetError());
	} while (0);
}
void mm_emu_audio_DeleteSource(struct mm_emu_audio* p)
{
	struct mm_logger* g_logger = mm_logger_instance();

	mm_emu_audio_BufferClear(p);
	mm_logger_log_I(g_logger, "%s %d audio buffer delete success.", __FUNCTION__, __LINE__);

	alDeleteSources(1, &p->source);
	__static_error_check(alGetError());
	mm_logger_log_I(g_logger, "%s %d audio source delete success.", __FUNCTION__, __LINE__);

	alcDestroyContext(p->context);
	p->context = NULL;
	__static_error_check(alGetError());
	mm_logger_log_I(g_logger, "%s %d audio context delete success.", __FUNCTION__, __LINE__);

	alcCloseDevice(p->device);
	p->device = NULL;
	mm_logger_log_I(g_logger, "%s %d audio device delete success.", __FUNCTION__, __LINE__);
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_audio_SetSourcePosition(struct mm_emu_audio* p, float x, float y, float z)
{
	if (AL_NONE != p->source)
	{
		alSource3f(p->source, AL_POSITION, x, y, z);
		__static_error_check(alGetError());
	}
}
void mm_emu_audio_SetSourceDirection(struct mm_emu_audio* p, float dirx, float diry, float dirz)
{
	if (AL_NONE != p->source)
	{
		alSource3f(p->source, AL_DIRECTION, dirx, diry, dirz);
		__static_error_check(alGetError());
	}
}
void mm_emu_audio_SetSourceVelocity(struct mm_emu_audio* p, float velx, float vely, float velz)
{
	if (AL_NONE != p->source)
	{
		alSource3f(p->source, AL_VELOCITY, velx, vely, velz);
		__static_error_check(alGetError());
	}
}
void mm_emu_audio_SetSourceVolume(struct mm_emu_audio* p, float gain)
{
	if (gain < 0) return;

	if (AL_NONE != p->source)
	{
		alSourcef(p->source, AL_GAIN, gain);
		__static_error_check(alGetError());
	}
}
void mm_emu_audio_SetSourceMaxVolume(struct mm_emu_audio* p, float maxGain)
{
	if (maxGain < 0 || maxGain > 1) return;

	if (AL_NONE != p->source)
	{
		alSourcef(p->source, AL_MAX_GAIN, maxGain);
		__static_error_check(alGetError());
	}
}
void mm_emu_audio_SetSourceMinVolume(struct mm_emu_audio* p, float minGain)
{
	if (minGain < 0 || minGain > 1) return;

	if (AL_NONE != p->source)
	{

		alSourcef(p->source, AL_MIN_GAIN, minGain);
		__static_error_check(alGetError());
	}
}
void mm_emu_audio_SetSourceConeAngles(struct mm_emu_audio* p, float innerConeAngle, float outerConeAngle)
{
	if (innerConeAngle < 0 || innerConeAngle > 360)	return;
	if (outerConeAngle < 0 || outerConeAngle > 360)	return;

	if (AL_NONE != p->source)
	{
		alSourcef(p->source, AL_CONE_INNER_ANGLE, innerConeAngle);
		alSourcef(p->source, AL_CONE_OUTER_ANGLE, outerConeAngle);
	}
}
void mm_emu_audio_SetSourceOuterConeVolume(struct mm_emu_audio* p, float gain)
{
	if (gain < 0 || gain > 1)	return;

	if (AL_NONE != p->source)
	{
		alSourcef(p->source, AL_CONE_OUTER_GAIN, gain);
	}
}
void mm_emu_audio_SetSourceMaxDistance(struct mm_emu_audio* p, float maxDistance)
{
	if (maxDistance < 0) return;

	if (AL_NONE != p->source)
	{
		alSourcef(p->source, AL_MAX_DISTANCE, maxDistance);
	}
}
void mm_emu_audio_SetSourceRolloffFactor(struct mm_emu_audio* p, float rolloffFactor)
{
	if (rolloffFactor < 0) return;

	if (AL_NONE != p->source)
	{
		alSourcef(p->source, AL_ROLLOFF_FACTOR, rolloffFactor);
	}
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_audio_SetListenerPosition(struct mm_emu_audio* p, float x, float y, float z)
{
	alListener3f(AL_POSITION, x, y, z);
}
void mm_emu_audio_SetListenerVelocity(struct mm_emu_audio* p, float velx, float vely, float velz)
{
	alListener3f(AL_VELOCITY, velx, vely, velz);
}
void mm_emu_audio_SetListenerOrientation(struct mm_emu_audio* p, float x, float y, float z, float upx, float upy, float upz)
{
	p->ListenerOrientation[0] = x;
	p->ListenerOrientation[1] = y;
	p->ListenerOrientation[2] = z;
	p->ListenerOrientation[3] = upx;
	p->ListenerOrientation[4] = upy;
	p->ListenerOrientation[5] = upz;
	alListenerfv(AL_ORIENTATION, p->ListenerOrientation);
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_audio_play(struct mm_emu_audio* p)
{
	if (AL_NONE != p->source)
	{
		alSourcePlay(p->source);
		__static_error_check(alGetError());
	}
}
void mm_emu_audio_stop(struct mm_emu_audio* p)
{
	if (AL_NONE != p->source)
	{
		alSourceStop(p->source);
		__static_error_check(alGetError());
	}
}
//////////////////////////////////////////////////////////////////////////
void mm_emu_audio_ProcessBuffer(struct mm_emu_audio* p, mm_byte_t* buffer, size_t length)
{
	int processed;
	int queued;

	ALuint al_buffer;
	ALint source_state_value = 0;

	alGetSourcei(p->source, AL_BUFFERS_PROCESSED, &processed);
	__static_error_check(alGetError());

	alGetSourcei(p->source, AL_BUFFERS_QUEUED, &queued);
	__static_error_check(alGetError());

	if (queued - processed > p->accumulation_limit)
	{
		struct mm_logger* g_logger = mm_logger_instance();
		mm_logger_log_W(g_logger, "%s %d audio block number accumulation queued: %d processed: %d.", __FUNCTION__, __LINE__, queued, processed);
	}

	while (processed--)
	{
		alSourceUnqueueBuffers(p->source, 1, &al_buffer);
		__static_error_check(alGetError());

		mm_emu_audio_Bufferrecycle(p, al_buffer);
	}

	al_buffer = mm_emu_audio_BufferProduce(p);

	alBufferData(al_buffer, (ALenum)p->nFormat, (const ALvoid*)buffer, (ALsizei)length, (ALsizei)p->nRate);
	__static_error_check(alGetError());

	alSourceQueueBuffers(p->source, 1, &al_buffer);
	__static_error_check(alGetError());

	alGetSourcei(p->source, AL_SOURCE_STATE, &source_state_value);
	__static_error_check(alGetError());

	if (AL_STOPPED == source_state_value)
	{
		mm_emu_audio_play(p);
	}
}
//////////////////////////////////////////////////////////////////////////
static void __static_error_check(ALenum code)
{
	struct mm_logger* g_logger = mm_logger_instance();

	switch (code)
	{
	case AL_INVALID_NAME:
		mm_logger_log_I(g_logger, "%s %d Invalid name paramater passed to AL call.", __FUNCTION__, __LINE__);
	case AL_INVALID_ENUM:
		mm_logger_log_I(g_logger, "%s %d Invalid enum parameter passed to AL call.", __FUNCTION__, __LINE__);
	case AL_INVALID_VALUE:
		mm_logger_log_I(g_logger, "%s %d Invalid value parameter passed to AL call.", __FUNCTION__, __LINE__);
	case AL_INVALID_OPERATION:
		mm_logger_log_I(g_logger, "%s %d Illegal AL call.", __FUNCTION__, __LINE__);
	case AL_OUT_OF_MEMORY:
		mm_logger_log_I(g_logger, "%s %d Not enough memory.", __FUNCTION__, __LINE__);
	default:
		break;
	}
}
