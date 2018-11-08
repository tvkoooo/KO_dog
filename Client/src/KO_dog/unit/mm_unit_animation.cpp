#include "mm_unit_animation.h"
#include "toolkit/mm_util_mesh.h"
#include "core/mm_logger.h"
#include "core/mm_string.h"
namespace mm
{
	mm_unit_animation_track::listener mm_unit_animation_track::default_unit_animation_track_listener;

	mm_unit_animation_track::mm_unit_animation_track()
		: d_unit_animation(NULL)
		, d_listener(&default_unit_animation_track_listener)
		, d_name("")
		, d_animation(NULL)
		, d_speed(1.0f)
		, d_state(AS_NONE)
	{

	}

	mm_unit_animation_track::~mm_unit_animation_track()
	{

	}
	void mm_unit_animation_track::update(float _offset)
	{
		if (AS_PLAYING == this->d_state)
		{
			Ogre::Real _curr = this->d_animation->getTimePosition();
			Ogre::Real _length = this->d_animation->getLength();
			Ogre::Real _real_time = _offset * this->d_speed;
			if (!this->d_animation->getLoop())
			{
				if ( _curr + _real_time >= _length )
				{
					this->d_listener->track_finished(this);
					this->d_unit_animation->on_animation_update_rmv(this);

					this->d_state = AS_STOPPED;
					this->d_animation->setEnabled(false);
				}
				else
				{
					this->d_animation->addTime(_real_time);
				}
			}
			else
			{
				if (_real_time >= _length )
				{
					this->d_listener->track_looping(this);
					this->d_animation->addTime(_real_time);
				}
				else
				{
					this->d_animation->addTime(_real_time);
				}
			}
		}
	}
	void mm_unit_animation_track::play()
	{
		this->d_state = AS_PLAYING;
		this->d_animation->setEnabled(true);
		this->d_listener->track_played(this);
		this->d_unit_animation->on_animation_update_add(this);
	}
	void mm_unit_animation_track::pause()
	{
		this->d_state = AS_PAUSED;
		this->d_animation->setEnabled(false);
		this->d_listener->track_paused(this);
		this->d_unit_animation->on_animation_update_rmv(this);
	}
	void mm_unit_animation_track::resume()
	{
		this->d_state = AS_PLAYING;
		this->d_animation->setEnabled(true);
		this->d_listener->track_played(this);
		this->d_unit_animation->on_animation_update_add(this);
	}
	void mm_unit_animation_track::rewind()
	{
		this->d_animation->setTimePosition(0);
	}
	void mm_unit_animation_track::stop()
	{
		this->d_state = AS_STOPPED;
		this->d_animation->setEnabled(false);
		this->d_listener->track_stopped(this);
		this->d_unit_animation->on_animation_update_rmv(this);
	}
	void mm_unit_animation_track::set_name(const std::string& _name)
	{
		this->d_name = _name;
	}
	const std::string& mm_unit_animation_track::get_name()
	{
		return this->d_name;
	}

	void mm_unit_animation_track::set_unit_animation(mm_unit_animation* _unit_animation)
	{
		this->d_unit_animation = _unit_animation;
	}
	mm_unit_animation* mm_unit_animation_track::get_unit_animation()
	{
		return this->d_unit_animation;
	}
	void mm_unit_animation_track::set_animation(Ogre::AnimationState* _animation)
	{
		this->d_animation = _animation;
		if (NULL != this->d_animation)
		{
			this->d_listener->track_loaded(this);
		}
		else
		{
			this->d_listener->track_destroyed(this);
		}
	}
	Ogre::AnimationState* mm_unit_animation_track::get_animation()
	{
		return this->d_animation;
	}

	void mm_unit_animation_track::set_state(int _state)
	{
		this->d_state = _state;
	}
	int mm_unit_animation_track::get_state() const
	{
		return this->d_state;
	}
	void mm_unit_animation_track::set_listener(listener* _listener)
	{
		assert(NULL != _listener && "_listener can not null.");
		this->d_listener = _listener;
	}
	mm_unit_animation_track::listener* mm_unit_animation_track::get_listener()
	{
		return this->d_listener;
	}

	void mm_unit_animation_track::set_speed(float _speed)
	{
		this->d_speed = _speed;
	}
	float mm_unit_animation_track::get_speed() const
	{
		return this->d_speed;
	}

	void mm_unit_animation_track::set_enable(bool _enable)
	{
		this->d_animation->setEnabled(_enable);
	}
	bool mm_unit_animation_track::get_enable() const
	{
		return this->d_animation->getEnabled();
	}
	void mm_unit_animation_track::set_loop(bool _loop)
	{
		this->d_animation->setLoop(_loop);
	}
	bool mm_unit_animation_track::get_loop() const
	{
		return this->d_animation->getLoop();
	}
	void mm_unit_animation_track::set_time_position(float _pos)
	{
		this->d_animation->setTimePosition(_pos);
	}
	float mm_unit_animation_track::get_time_position() const
	{
		return this->d_animation->getTimePosition();
	}
	//////////////////////////////////////////////////////////////////////////
	mm_unit_animation::mm_unit_animation()
		: d_scene_manager(NULL)
		, d_scene_node(NULL)
		, d_entity(NULL)
		, d_resource_group("")
		, d_entity_asset("")
		, d_entity_name("")
	{

	}

	mm_unit_animation::~mm_unit_animation()
	{
		this->clear_animation_track();
	}

	void mm_unit_animation::set_scene_manager(Ogre::SceneManager* _scene_manager)
	{
		this->d_scene_manager = _scene_manager;
	}
	Ogre::SceneManager* mm_unit_animation::get_scene_manager()
	{
		return this->d_scene_manager;
	}

	void mm_unit_animation::set_scene_node(Ogre::SceneNode* node)
	{
		this->d_scene_node = node;
	}
	Ogre::SceneNode* mm_unit_animation::get_scene_node()
	{
		return this->d_scene_node;
	}

	void mm_unit_animation::set_ogre_entity(Ogre::Entity* entity)
	{
		this->d_entity = entity;
	}
	Ogre::Entity* mm_unit_animation::get_ogre_entity()
	{
		return this->d_entity;
	}

	void mm_unit_animation::set_resource_group(const char* _resource_group)
	{
		this->d_resource_group = _resource_group;
	}
	const char* mm_unit_animation::get_resource_group()
	{
		return this->d_resource_group.c_str();
	}

	void mm_unit_animation::set_entity_asset(const char* _entity_asset)
	{
		this->d_entity_asset = _entity_asset;
	}
	const char* mm_unit_animation::get_entity_asset()
	{
		return this->d_entity_asset.c_str();
	}

	void mm_unit_animation::set_entity_name(const char* _entity_name)
	{
		this->d_entity_name = _entity_name;
	}
	const char* mm_unit_animation::get_entity_name()
	{
		return this->d_entity_name.c_str();
	}

	const mm_unit_animation::active_source_map_type& mm_unit_animation::get_active_source() const
	{
		return this->d_active_source;
	}

	mm_unit_animation_track* mm_unit_animation::add_animation_track(const char* _anim_name, const char* _asset_name)
	{
		mm_unit_animation_track* e = NULL;
		active_animation_type::iterator it = this->d_active.find(_anim_name);
		if (it == this->d_active.end())
		{
			typedef std::pair<active_animation_type::iterator,bool> insert_result_type;
			this->make_entity();
			Ogre::AnimationState* _state = this->d_entity->getAnimationState(_asset_name);
			e = new mm_unit_animation_track();
			e->set_unit_animation(this);
			e->set_animation(_state);
			e->set_speed(1.0f);
			e->set_name(_anim_name);
			insert_result_type _result = this->d_active.insert(active_animation_type::value_type(_anim_name,e));
			if (false == _result.second)
			{
				delete e;
				e = NULL;
				//unknown error.
				assert(false && "UnitAnimation::addAnimationTrack insert error.");
			}
		}
		else
		{
			e = it->second;
		}
		return e;
	}
	mm_unit_animation_track* mm_unit_animation::get_animation_track(const char* _anim_name)
	{
		mm_unit_animation_track* e = NULL;
		active_animation_type::iterator it = this->d_active.find(_anim_name);
		if (it != this->d_active.end())
		{
			e = it->second;
		}
		return e;
	}
	void mm_unit_animation::rmv_animation_track(const char* _anim_name)
	{
		mm_unit_animation_track* e = NULL;
		active_animation_type::iterator it = this->d_active.find(_anim_name);
		if (it != this->d_active.end())
		{
			e = it->second;
			this->on_animation_update_rmv(e);
			this->d_active.erase(it);
			delete e;
		}
	}
	void mm_unit_animation::clear_animation_track()
	{
		mm_unit_animation_track* e = NULL;
		active_animation_type::iterator it;
		while(!this->d_active.empty())
		{
			it = this->d_active.begin();
			e = it->second;
			this->on_animation_update_rmv(e);
			this->d_active.erase(it);
			delete e;
		}
	}
	mm_unit_animation_track* mm_unit_animation::play(const char* _anim_name, bool _loop /*= false*/, float _speed /*= 1.0f*/)
	{
		mm_unit_animation_track* e = this->get_animation_track(_anim_name);
		if (NULL != e)
		{
			e->rewind();
			e->set_loop(_loop);
			e->set_speed(_speed);
			e->play();
		}
		return e;
	}
	mm_unit_animation_track* mm_unit_animation::stop(const char* _anim_name)
	{
		mm_unit_animation_track* e = this->get_animation_track(_anim_name);
		if (NULL != e)
		{
			e->stop();
		}
		return e;
	}
	void mm_unit_animation::stop_all()
	{
		mm_unit_animation_track* e = NULL;
		active_animation_type::iterator it = this->d_active.begin();
		while(it!= this->d_active.end())
		{
			e = it->second;
			it++;
			e->stop();
		}
	}
	void mm_unit_animation::update(float _offset)
	{
		mm_unit_animation_track* e = NULL;
		active_source_map_type::iterator it = this->d_active_source.begin();
		while(it!= this->d_active_source.end())
		{
			e = it->second;
			it++;
			e->update(_offset);
		}
	}
	void mm_unit_animation::on_animation_update_add(mm_unit_animation_track* _track)
	{
		this->d_active_source.insert(active_source_map_type::value_type(_track->get_name(), _track));
	}
	void mm_unit_animation::on_animation_update_rmv(mm_unit_animation_track* _track)
	{
		this->d_active_source.erase(_track->get_name());
	}
	void mm_unit_animation::make_entity_name()
	{
		if (this->d_entity_name.empty())
		{
			this->d_entity_name.resize(this->d_resource_group.size() + this->d_entity_asset.size() + 64);
			mm_sprintf((char*)this->d_entity_name.data(), "%s/%s-%p", this->d_resource_group.c_str(), this->d_entity_asset.c_str(), this);
		}
	}
	void mm_unit_animation::make_entity()
	{
		if (NULL == this->d_entity)
		{
			this->entity_produce();
		}
	}
	void mm_unit_animation::entity_produce()
	{
		if (NULL == this->d_entity && !this->d_entity_asset.empty())
		{
			assert(NULL != this->d_scene_manager && "NULL != this->d_scene_manager is invalid.");
			assert(NULL != this->d_scene_node && "NULL != this->d_scene_node is invalid.");
			this->make_entity_name();
			this->d_entity = this->d_scene_manager->createEntity(this->d_entity_name.c_str(), this->d_entity_asset, this->d_resource_group);
			this->d_scene_node->attachObject(this->d_entity);
		}
	}
	void mm_unit_animation::entity_recycle()
	{
		if (NULL != this->d_entity)
		{
			assert(NULL != this->d_scene_manager && "NULL != this->d_scene_manager is invalid.");
			assert(NULL != this->d_scene_node && "NULL != this->d_scene_node is invalid.");
			this->d_scene_node->detachObject(this->d_entity);
			this->d_scene_manager->destroyEntity(this->d_entity);
			this->d_entity = NULL;
		}
	}

}

