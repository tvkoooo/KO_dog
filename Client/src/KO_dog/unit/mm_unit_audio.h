#ifndef __mm_unit_audio_h__
#define __mm_unit_audio_h__
#include <map>
#include <string>
#include "OgreOggSound.h"
namespace mm
{
	class mm_unit_audio;

	class mm_unit_audio_track : public OgreOggSound::OgreOggISound::SoundListener
	{
	public:
		enum audio_state
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
			virtual void track_loaded(mm_unit_audio_track* track) {}
			virtual void track_destroyed(mm_unit_audio_track* track) {}
			virtual void track_played(mm_unit_audio_track* track) {}
			virtual void track_stopped(mm_unit_audio_track* track) {}
			virtual void track_finished(mm_unit_audio_track* track) {}
			virtual void track_paused(mm_unit_audio_track* track) {}
			virtual void track_looping(mm_unit_audio_track* track) {}
		};
		static listener default_unit_audio_track_listener;
	public:
		mm_unit_audio* d_unit_audio;
	public:
		listener* d_listener;
	public:
		std::string d_name;
		OgreOggSound::OgreOggISound* d_audio;// weak ref.
		float d_speed;// default is 1.0f.
		bool d_loop;// default is false.
		bool d_enable;// default is false.
		int d_state;
	public:
		mm_unit_audio_track();
		virtual ~mm_unit_audio_track();
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

		void set_unit_audio(mm_unit_audio* _unit_audio);
		mm_unit_audio* get_unit_audio();

		void set_audio(OgreOggSound::OgreOggISound* _audio);
		OgreOggSound::OgreOggISound* get_audio();

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
	public:
		virtual void soundLoaded(OgreOggSound::OgreOggISound* sound);
		virtual void soundDestroyed(OgreOggSound::OgreOggISound* sound);
		virtual void soundPlayed(OgreOggSound::OgreOggISound* sound);
		virtual void soundStopped(OgreOggSound::OgreOggISound* sound);
		virtual void soundFinished(OgreOggSound::OgreOggISound* sound);
		virtual void soundPaused(OgreOggSound::OgreOggISound* sound);
		virtual void soundLooping(OgreOggSound::OgreOggISound* sound);
	};
	class mm_unit_audio
	{
	public:
		typedef std::map<std::string, mm_unit_audio_track*> active_audio_type;
		typedef std::map<std::string, mm_unit_audio_track*> active_source_map_type;
	public:
		active_audio_type d_active;
		active_source_map_type d_active_source;
		OgreOggSound::OgreOggSoundManager* d_audio_manager;
		Ogre::SceneNode* d_scene_node;// weak ref.
		std::string d_resource_group;
	public:
		mm_unit_audio();
		virtual ~mm_unit_audio();
	public:
		void set_audio_manager(OgreOggSound::OgreOggSoundManager* _audio_manager);
		OgreOggSound::OgreOggSoundManager* get_audio_manager();

		void set_scene_node(Ogre::SceneNode* node);
		Ogre::SceneNode* get_scene_node();

		void set_resource_group(const char* _resource_group);
		const char* get_resource_group();
	public:
		const active_source_map_type& get_active_source() const;
	public:
		mm_unit_audio_track* add_audio_track(const char* _audio_name, const char* _audio_file);
		mm_unit_audio_track* get_audio_track(const char* _audio_name);
		void rmv_audio_track(const char* _audio_name);
		void clear_audio_track();
	public:
		mm_unit_audio_track* play(const char* _audio_name, bool _loop = false, float _speed = 1.0f);
		mm_unit_audio_track* stop(const char* _audio_name);
		void stop_all();
	public:
		void update(float _offset);
	public:
		void on_audio_update_add(mm_unit_audio_track* _track);
		void on_audio_update_rmv(mm_unit_audio_track* _track);
	};
}
#endif//__mm_unit_audio_h__