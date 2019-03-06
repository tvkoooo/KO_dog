#ifndef __mm_emu_audio_h__
#define __mm_emu_audio_h__

#include "core/mm_core.h"
#include "core/mm_string.h"

#include "container/mm_rbtset_u32.h"
#include "container/mm_rbtset_string.h"

//////////////////////////////////////////////////////////////////////////
#if MM_PLATFORM == MM_PLATFORM_WIN32

#	pragma warning( disable : 4244 )

/**
* Specifies whether EFX enhancements are supported
* 0 - EFX not supported
* 1 - Enable EFX suport
*/
#	ifndef HAVE_EFX
#		define HAVE_EFX 1
#	endif

#	include "al.h"
#	include "alc.h"
#	if HAVE_EFX
#		include "efx.h"
#		include "efx-util.h"
#		include "efx-creative.h"
#		include "xram.h"
#	endif
#elif MM_COMPILER == MM_COMPILER_GNUC || MM_COMPILER == MM_COMPILER_CLANG
#   if MM_PLATFORM == MM_PLATFORM_APPLE
#		include <al.h>
#		include <alc.h>
#   else
#		include <AL/al.h>
#		include <AL/alc.h>
#	endif
#else // Other Compilers
#	include <OpenAL/al.h>
#	include <OpenAL/alc.h>
#	include "xram.h"
#endif
//////////////////////////////////////////////////////////////////////////

#include "emu/mm_emu_emulator.h"

//#include "mm_emu_export.h"

#include "core/mm_prefix.h"

#define MM_EMU_AUDIO_RATE_TRIM_BORDER_DEFAULT 0.75
#define MM_EMU_AUDIO_RATE_TRIM_NUMBER_DEFAULT 0.25

#define MM_EMU_AUDIO_ACCUMULATION_LIMIT_DEFAULT 100

//////////////////////////////////////////////////////////////////////////
struct mm_emu_audio
{
	struct mm_string device_name;

	struct mm_rbtset_string devices;

	struct mm_rbtset_u32 pool;// strong ref.
	struct mm_rbtset_u32 used;// weak ref.
	struct mm_rbtset_u32 idle;// weak ref.
	float rate_trim_border;
	float rate_trim_number;

	int accumulation_limit;

	int nRate;
	ALenum nFormat;					// OpenAL format

	ALCdevice* device;
	ALCcontext* context;

	ALuint source;

	ALfloat ListenerOrientation[6];	// 3D orientation
};
void mm_emu_audio_init(struct mm_emu_audio* p);
void mm_emu_audio_destroy(struct mm_emu_audio* p);
//////////////////////////////////////////////////////////////////////////
void mm_emu_audio_SetDeviceName(struct mm_emu_audio* p, const char* device_name);
void mm_emu_audio_SetRate(struct mm_emu_audio* p, int nRate);
void mm_emu_audio_SetFormat(struct mm_emu_audio* p, ALenum nFormat);
//////////////////////////////////////////////////////////////////////////
ALuint mm_emu_audio_BufferAdd(struct mm_emu_audio* p);
void mm_emu_audio_BufferRmv(struct mm_emu_audio* p, ALuint e);
void mm_emu_audio_BufferClear(struct mm_emu_audio* p);

ALuint mm_emu_audio_BufferProduce(struct mm_emu_audio* p);
void mm_emu_audio_Bufferrecycle(struct mm_emu_audio* p, ALuint v);
//////////////////////////////////////////////////////////////////////////
void mm_emu_audio_DeviceList(struct mm_emu_audio* p);
//////////////////////////////////////////////////////////////////////////
void mm_emu_audio_CreateSource(struct mm_emu_audio* p);
void mm_emu_audio_DeleteSource(struct mm_emu_audio* p);
//////////////////////////////////////////////////////////////////////////
void mm_emu_audio_SetSourcePosition(struct mm_emu_audio* p, float x, float y, float z);
void mm_emu_audio_SetSourceDirection(struct mm_emu_audio* p, float dirx, float diry, float dirz);
void mm_emu_audio_SetSourceVelocity(struct mm_emu_audio* p, float velx, float vely, float velz);
void mm_emu_audio_SetSourceVolume(struct mm_emu_audio* p, float gain);
void mm_emu_audio_SetSourceMaxVolume(struct mm_emu_audio* p, float maxGain);
void mm_emu_audio_SetSourceMinVolume(struct mm_emu_audio* p, float minGain);
void mm_emu_audio_SetSourceConeAngles(struct mm_emu_audio* p, float innerConeAngle, float outerConeAngle);
void mm_emu_audio_SetSourceOuterConeVolume(struct mm_emu_audio* p, float gain);
void mm_emu_audio_SetSourceMaxDistance(struct mm_emu_audio* p, float maxDistance);
void mm_emu_audio_SetSourceRolloffFactor(struct mm_emu_audio* p, float rolloffFactor);
//////////////////////////////////////////////////////////////////////////
void mm_emu_audio_SetListenerPosition(struct mm_emu_audio* p, float x, float y, float z);
void mm_emu_audio_SetListenerVelocity(struct mm_emu_audio* p, float velx, float vely, float velz);
void mm_emu_audio_SetListenerOrientation(struct mm_emu_audio* p, float x, float y, float z, float upx, float upy, float upz);
//////////////////////////////////////////////////////////////////////////
void mm_emu_audio_play(struct mm_emu_audio* p);
void mm_emu_audio_stop(struct mm_emu_audio* p);
//////////////////////////////////////////////////////////////////////////
void mm_emu_audio_ProcessBuffer(struct mm_emu_audio* p, mm_byte_t* buffer, size_t length);
//////////////////////////////////////////////////////////////////////////
#include "core/mm_suffix.h"

#endif//__mm_emu_audio_h__