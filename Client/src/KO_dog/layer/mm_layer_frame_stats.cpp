#include "mm_layer_frame_stats.h"

#include "math/mm_math_const.h"

#include "OgreSkeletonManager.h"
#include "OgreMesh.h"
#include "OgreMaterial.h"
#include "OgreTechnique.h"
#include "OgrePass.h"

#include "CEGUI/SchemeManager.h"
#include "CEGUI/WindowManager.h"
#include "CEGUI/AnimationManager.h"
#include "CEGUI/AnimationInstance.h"

#include "toolkit/mm_util_mesh.h"

#include "flake/mm_system_event_surface.h"

namespace mm
{
	mm_layer_frame_stats::mm_layer_frame_stats()
		: d_render_window(NULL)

		, d_window(NULL)
		, l_frame_stats(NULL)

		, Label_val_0(NULL)
		, Label_val_1(NULL)
		, Label_val_2(NULL)
		, Label_val_3(NULL)
		, Label_val_4(NULL)

		, d_update_timecode(1.0f)
		, d_update_interval(1.0f)
	{

	}

	void mm_layer_frame_stats::attach_window(CEGUI::Window* _window)
	{
		this->d_window = _window;
		this->d_window->addChild(this->l_frame_stats);
	}
	void mm_layer_frame_stats::detach_window(CEGUI::Window* _window)
	{
		this->d_window->removeChild(this->l_frame_stats);
		this->d_window = _window;
	}

	void mm_layer_frame_stats::on_finish_launching(mm_flake_surface* surface)
	{
		this->d_render_window = surface->d_render_window;

		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();
		this->l_frame_stats = _window_manager->loadLayoutFromFile("l_frame_stats.layout");

		this->l_frame_stats_EventMouseButtonDown = this->l_frame_stats->subscribeEvent(CEGUI::Window::EventUpdated, CEGUI::Event::Subscriber(&mm_layer_frame_stats::on_l_frame_stats_EventUpdated, this));

		this->Label_val_0 = this->l_frame_stats->getChild("Label_val_0");
		this->Label_val_1 = this->l_frame_stats->getChild("Label_val_1");
		this->Label_val_2 = this->l_frame_stats->getChild("Label_val_2");
		this->Label_val_3 = this->l_frame_stats->getChild("Label_val_3");
		this->Label_val_4 = this->l_frame_stats->getChild("Label_val_4");
	}
	void mm_layer_frame_stats::on_before_terminate(mm_flake_surface* surface)
	{
		this->Label_val_0 = NULL;
		this->Label_val_1 = NULL;
		this->Label_val_2 = NULL;
		this->Label_val_3 = NULL;
		this->Label_val_4 = NULL;

		this->l_frame_stats_EventMouseButtonDown->disconnect();

		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();
		_window_manager->destroyWindow(this->l_frame_stats);
		this->l_frame_stats = NULL;
	}
	void mm_layer_frame_stats::on_l_frame_stats_EventUpdated(const CEGUI::EventArgs& args)
	{
		const CEGUI::UpdateEventArgs& evt = (const CEGUI::UpdateEventArgs&)(args);
		this->d_update_timecode += evt.d_timeSinceLastFrame;
		if (this->d_update_interval <= this->d_update_timecode)
		{
			this->d_update_timecode = 0;
			
			const Ogre::RenderTarget::FrameStats& _frame_stats = this->d_render_window->getStatistics();
			std::string Label_val_0_string = mm_value::to_string(_frame_stats.avgFPS);
			this->Label_val_0->setText(Label_val_0_string.c_str());

			std::string Label_val_1_string = mm_value::to_string(_frame_stats.bestFPS);
			this->Label_val_1->setText(Label_val_1_string.c_str());

			std::string Label_val_2_string = mm_value::to_string(_frame_stats.worstFPS);
			this->Label_val_2->setText(Label_val_2_string.c_str());

			std::string Label_val_3_string = mm_value::to_string(_frame_stats.triangleCount);
			this->Label_val_3->setText(Label_val_3_string.c_str());

			std::string Label_val_4_string = mm_value::to_string(_frame_stats.batchCount);
			this->Label_val_4->setText(Label_val_4_string.c_str());
		}
	}
}
