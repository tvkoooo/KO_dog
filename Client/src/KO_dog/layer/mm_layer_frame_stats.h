#ifndef __mm_layer_frame_stats_h__
#define __mm_layer_frame_stats_h__

#include "core/mm_core.h"

#include "flake/mm_flake_surface.h"

#include "dish/mm_event.h"

#include "math/mm_vector3.h"

#include "OgreSceneNode.h"
#include "OgreCamera.h"
#include "OgreViewport.h"
#include "OgreEntity.h"

#include "dish/mm_value.h"

namespace mm
{
	class mm_layer_frame_stats
	{
	public:
		Ogre::RenderWindow* d_render_window;
	public:
		CEGUI::Window* d_window;
		CEGUI::Window* l_frame_stats;
	public:
		CEGUI::Window* Label_val_0;
		CEGUI::Window* Label_val_1;
		CEGUI::Window* Label_val_2;
		CEGUI::Window* Label_val_3;
		CEGUI::Window* Label_val_4;
	public:
		float d_update_timecode;
		float d_update_interval;
	public:
		CEGUI::Event::Connection l_frame_stats_EventMouseButtonDown;
	public:
		mm_layer_frame_stats();
	public:
		void attach_window(CEGUI::Window* _window);
		void detach_window(CEGUI::Window* _window);
	public:
		void on_finish_launching(mm_flake_surface* surface);
		void on_before_terminate(mm_flake_surface* surface);
	public:
		void on_l_frame_stats_EventUpdated(const CEGUI::EventArgs& args);
	};
}

#endif//__mm_layer_frame_stats_h__