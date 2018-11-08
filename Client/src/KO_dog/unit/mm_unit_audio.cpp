#include "mm_unit_audio.h"
namespace mm
{
	mm_unit_audio_track::listener mm_unit_audio_track::default_unit_audio_track_listener;

	mm_unit_audio_track::mm_unit_audio_track()
		: d_unit_audio(NULL)
		, d_listener(&default_unit_audio_track_listener)
		, d_name("")
		, d_audio(NULL)
		, d_speed(1.0f)
		, d_loop(false)
		, d_enable(false)
		, d_state(AS_NONE)
	{

	}
	mm_unit_audio_track::~mm_unit_audio_track()
	{

	}
	void mm_unit_audio_track::update(float _offset)
	{
		if (AS_PLAYING == this->d_state)
		{
			float _real_time = _offset * this->d_speed;
			this->d_audio->update(_real_time);
		}
	}
	void mm_unit_audio_track::play()
	{
		this->d_enable = true;

		this->d_state = AS_PLAYING;
		this->d_audio->play();
		this->d_unit_audio->on_audio_update_add(this);
	}
	void mm_unit_audio_track::pause()
	{
		this->d_enable = false;

		this->d_state = AS_PAUSED;
		this->d_audio->pause();
		this->d_unit_audio->on_audio_update_rmv(this);
	}
	void mm_unit_audio_track::resume()
	{
		this->d_enable = true;

		this->d_state = AS_PLAYING;
		this->d_audio->play();
		this->d_unit_audio->on_audio_update_add(this);
	}
	void mm_unit_audio_track::rewind()
	{
		this->d_audio->setPlayPosition(0);
	}
	void mm_unit_audio_track::stop()
	{
		this->d_enable = false;

		this->d_state = AS_STOPPED;
		this->d_audio->stop();
		this->d_unit_audio->on_audio_update_rmv(this);
	}
	void mm_unit_audio_track::set_name(const std::string& _name)
	{
		this->d_name = _name;
	}
	const std::string& mm_unit_audio_track::get_name()
	{
		return this->d_name;
	}

	void mm_unit_audio_track::set_unit_audio(mm_unit_audio* _unit_audio)
	{
		this->d_unit_audio = _unit_audio;
	}
	mm_unit_audio* mm_unit_audio_track::get_unit_audio()
	{
		return this->d_unit_audio;
	}
	void mm_unit_audio_track::set_audio(OgreOggSound::OgreOggISound* _audio)
	{
		this->d_audio = _audio;
	}
	OgreOggSound::OgreOggISound* mm_unit_audio_track::get_audio()
	{
		return this->d_audio;
	}

	void mm_unit_audio_track::set_state(int _state)
	{
		this->d_state = _state;
	}
	int mm_unit_audio_track::get_state() const
	{
		return this->d_state;
	}

	void mm_unit_audio_track::set_listener(listener* _listener)
	{
		assert(NULL != _listener && "_listener can not null.");
		this->d_listener = _listener;
	}
	mm_unit_audio_track::listener* mm_unit_audio_track::get_listener()
	{
		return this->d_listener;
	}
	void mm_unit_audio_track::set_speed(float _speed)
	{
		this->d_speed = _speed;
	}
	float mm_unit_audio_track::get_speed() const
	{
		return this->d_speed;
	}

	void mm_unit_audio_track::set_enable(bool _enable)
	{
		this->d_enable = _enable;
	}
	bool mm_unit_audio_track::get_enable() const
	{
		return this->d_enable;
	}

	void mm_unit_audio_track::set_loop(bool _loop)
	{
		this->d_loop = _loop;
		this->d_audio->loop(this->d_loop);
	}
	bool mm_unit_audio_track::get_loop() const
	{
		return this->d_loop;
	}

	void mm_unit_audio_track::set_time_position(float _pos)
	{
		this->d_audio->setPlayPosition(_pos);
	}
	float mm_unit_audio_track::get_time_position() const
	{
		return this->d_audio->getPlayPosition();
	}

	void mm_unit_audio_track::soundLoaded(OgreOggSound::OgreOggISound* sound) 
	{
		this->d_listener->track_loaded(this);
	}
	void mm_unit_audio_track::soundDestroyed(OgreOggSound::OgreOggISound* sound) 
	{
		this->d_listener->track_destroyed(this);
	}
	void mm_unit_audio_track::soundPlayed(OgreOggSound::OgreOggISound* sound) 
	{
		this->d_listener->track_played(this);
	}
	void mm_unit_audio_track::soundStopped(OgreOggSound::OgreOggISound* sound) 
	{
		this->d_listener->track_stopped(this);
	}
	void mm_unit_audio_track::soundFinished(OgreOggSound::OgreOggISound* sound) 
	{
		this->d_listener->track_finished(this);
		this->d_unit_audio->on_audio_update_rmv(this);
	}
	void mm_unit_audio_track::soundPaused(OgreOggSound::OgreOggISound* sound) 
	{
		this->d_listener->track_paused(this);
	}
	void mm_unit_audio_track::soundLooping(OgreOggSound::OgreOggISound* sound) 
	{
		this->d_listener->track_looping(this);
	}

	mm_unit_audio::mm_unit_audio()
		: d_audio_manager(NULL)
		, d_scene_node(NULL)
		, d_resource_group("")
	{

	}

	mm_unit_audio::~mm_unit_audio()
	{
		this->clear_audio_track();
	}

	void mm_unit_audio::set_audio_manager(OgreOggSound::OgreOggSoundManager* _audio_manager)
	{
		this->d_audio_manager = _audio_manager;
	}
	OgreOggSound::OgreOggSoundManager* mm_unit_audio::get_audio_manager()
	{
		return this->d_audio_manager;
	}

	void mm_unit_audio::set_scene_node(Ogre::SceneNode* node)
	{
		this->d_scene_node = node;
	}
	Ogre::SceneNode* mm_unit_audio::get_scene_node()
	{
		return this->d_scene_node;
	}

	void mm_unit_audio::set_resource_group(const char* _resource_group)
	{
		this->d_resource_group = _resource_group;
	}
	const char* mm_unit_audio::get_resource_group()
	{
		return this->d_resource_group.c_str();
	}

	const mm_unit_audio::active_source_map_type& mm_unit_audio::get_active_source() const
	{
		return this->d_active_source;
	}

	mm_unit_audio_track* mm_unit_audio::add_audio_track(const char* _audio_name, const char* _audio_file)
	{
		mm_unit_audio_track* e = NULL;
		active_audio_type::iterator it = this->d_active.find(_audio_name);
		if (it == this->d_active.end())
		{
			this->d_audio_manager->setResourceGroupName(this->d_resource_group);
			e = new mm_unit_audio_track;
			e->set_unit_audio(this);
			e->set_audio(this->d_audio_manager->createSound(_audio_name, _audio_file));
			e->set_name(_audio_name);
			this->d_active.insert(active_audio_type::value_type(_audio_name,e));
			this->d_scene_node->attachObject(e->get_audio());
		}
		else
		{
			e = it->second;
		}
		return e;
	}
	void mm_unit_audio::rmv_audio_track(const char* _audio_name)
	{
		mm_unit_audio_track* e = NULL;
		active_audio_type::iterator it = this->d_active.find(_audio_name);
		if (it != this->d_active.end())
		{
			e = it->second;
			this->on_audio_update_rmv(e);
			this->d_active.erase(it);
			e->pause();
			e->stop();
			this->d_scene_node->detachObject(e->d_audio);
			this->d_audio_manager->destroySound(e->d_audio);
		}
	}
	mm_unit_audio_track* mm_unit_audio::get_audio_track(const char* _sound_name)
	{
		mm_unit_audio_track* e = NULL;
		active_audio_type::iterator it = this->d_active.find(_sound_name);
		if (it != this->d_active.end())
		{
			e = it->second;
		}
		return e;
	}
	void mm_unit_audio::clear_audio_track()
	{
		mm_unit_audio_track* e = NULL;
		active_audio_type::iterator it;
		while(!this->d_active.empty())
		{
			it = this->d_active.begin();
			e = it->second;
			this->on_audio_update_rmv(e);
			this->d_active.erase(it);
			e->pause();
			e->stop();
			this->d_scene_node->detachObject(e->d_audio);
			this->d_audio_manager->destroySound(e->d_audio);
		}
	}
	mm_unit_audio_track* mm_unit_audio::play(const char* _audio_name, bool _loop /*= false*/, float _speed /*= 1.0f*/)
	{
		mm_unit_audio_track* e = this->get_audio_track(_audio_name);
		if (NULL != e)
		{
			e->rewind();
			e->set_loop(_loop);
			e->set_speed(_speed);
			e->play();
		}
		return e;
	}
	mm_unit_audio_track* mm_unit_audio::stop(const char* _audio_name)
	{
		mm_unit_audio_track* e = this->get_audio_track(_audio_name);
		if (NULL != e)
		{
			e->stop();
		}
		return e;
	}
	void mm_unit_audio::stop_all()
	{
		mm_unit_audio_track* e = NULL;
		active_audio_type::iterator it = this->d_active.begin();
		while(it!= this->d_active.end())
		{
			e = it->second;
			it++;
			e->stop();
		}
	}
	void mm_unit_audio::update(float _offset)
	{
		mm_unit_audio_track* e = NULL;
		active_source_map_type::iterator it = this->d_active_source.begin();
		while (it != this->d_active_source.end())
		{
			e = it->second;
			it++;
			e->update(_offset);
		}
	}
	void mm_unit_audio::on_audio_update_add(mm_unit_audio_track* _track)
	{
		this->d_active_source.insert(active_source_map_type::value_type(_track->get_name(), _track));
	}
	void mm_unit_audio::on_audio_update_rmv(mm_unit_audio_track* _track)
	{
		this->d_active_source.erase(_track->get_name());
	}
}

