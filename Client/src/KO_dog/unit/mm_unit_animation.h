#ifndef __mm_unit_animation_h__
#define __mm_unit_animation_h__

#include "core/mm_core.h"
#include "dish/mm_event_args.h"
#include "dish/mm_event.h"
#include "OgreAnimationState.h"
#include "OgreSceneManager.h"
#include "OgreSceneNode.h"
#include <string>
#include <map>

namespace mm
{
	class mm_unit_animation;

	class mm_unit_animation_track
	{
	public:
		enum animation_state
		{
			AS_NONE,
			AS_PLAYING,
			AS_PAUSED,
			AS_STOPPED,
			AS_DESTROYED
		};
	public:
		class listener
		{
		public:
			listener() {}
			virtual ~listener() {}
			virtual void track_loaded(mm_unit_animation_track* track) {}
			virtual void track_destroyed(mm_unit_animation_track* track) {}
			virtual void track_played(mm_unit_animation_track* track) {}
			virtual void track_stopped(mm_unit_animation_track* track) {}
			virtual void track_finished(mm_unit_animation_track* track) {}
			virtual void track_paused(mm_unit_animation_track* track) {}
			virtual void track_looping(mm_unit_animation_track* track) {}
		};
		static listener default_unit_animation_track_listener;
	public:
		mm_unit_animation* d_unit_animation;
	public:
		listener* d_listener;
	public:
		std::string d_name;
		Ogre::AnimationState* d_animation;// weak ref.
		float d_speed;// default is 1.0f.
		int d_state;
	public:
		mm_unit_animation_track();
		virtual ~mm_unit_animation_track();
	public:
		void update(float _offset);
	public:
		void play();
		void pause();
		void resume();
		void rewind();
		void stop();
	public:
		void set_name(const std::string& _name);
		const std::string& get_name();

		void set_unit_animation(mm_unit_animation* _unit_animation);
		mm_unit_animation* get_unit_animation();

		void set_animation(Ogre::AnimationState* _animation);
		Ogre::AnimationState* get_animation();

		void set_state(int _state);
		int get_state() const;

		void set_listener(listener* _listener);
		listener* get_listener();
	public:
		void set_speed(float _speed);
		float get_speed() const;

		void set_enable(bool _enable);
		bool get_enable() const;

		void set_loop(bool _loop);
		bool get_loop() const;

		void set_time_position(float _pos);
		float get_time_position() const;
	};
	class mm_unit_animation
	{
	public:
		typedef std::map<std::string, mm_unit_animation_track*> active_animation_type;
		typedef std::map<std::string, mm_unit_animation_track*> active_source_map_type;
	public:
		active_animation_type d_active;
		active_source_map_type d_active_source;
		Ogre::SceneManager* d_scene_manager;
		Ogre::SceneNode* d_scene_node;// weak ref.
		Ogre::Entity* d_entity;
		std::string d_resource_group;
		std::string d_entity_asset;
		std::string d_entity_name;
	public:
		mm_unit_animation();
		virtual ~mm_unit_animation();
	public:
		void set_scene_manager(Ogre::SceneManager* _scene_manager);
		Ogre::SceneManager* get_scene_manager();

		void set_scene_node(Ogre::SceneNode* node);
		Ogre::SceneNode* get_scene_node();

		void set_ogre_entity(Ogre::Entity* entity);
		Ogre::Entity* get_ogre_entity();

		void set_resource_group(const char* _resource_group);
		const char* get_resource_group();

		void set_entity_asset(const char* _entity_asset);
		const char* get_entity_asset();

		void set_entity_name(const char* _entity_name);
		const char* get_entity_name();
	public:
		const active_source_map_type& get_active_source() const;
	public:
		mm_unit_animation_track* add_animation_track(const char* _anim_name, const char* _asset_name);
		mm_unit_animation_track* get_animation_track(const char* _anim_name);
		void rmv_animation_track(const char* _anim_name);
		void clear_animation_track();
	public:
		mm_unit_animation_track* play(const char* _anim_name, bool _loop = false, float _speed = 1.0f);
		mm_unit_animation_track* stop(const char* _anim_name);
		void stop_all();
	public:
		void update(float _offset);
	public:
		void on_animation_update_add(mm_unit_animation_track* _track);
		void on_animation_update_rmv(mm_unit_animation_track* _track);
	public:
		void make_entity_name();
		void make_entity();
		void entity_produce();
		void entity_recycle();
	};
}
#endif//__mm_unit_animation_h__