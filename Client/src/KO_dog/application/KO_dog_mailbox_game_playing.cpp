#include "KO_dog_mailbox_game_playing.h"

#include "OgreSkeletonManager.h"
#include "OgreMesh.h"
#include "OgreMaterial.h"
#include "OgreTechnique.h"
#include "OgrePass.h"

#include "CEGUI/System.h"
#include "CEGUI/GUIContext.h"
#include "CEGUI/SchemeManager.h"
#include "CEGUI/WindowManager.h"
#include "CEGUI/RenderingWindow.h"
#include "CEGUIOgreRenderer/Texture.h"
#include "CEGUIOgreRenderer/GeometryBuffer.h"

#include "toolkit/mm_util_mesh.h"

#include "flake/mm_system_event_surface.h"
#include "flake/mm_system_event_touch.h"
#include "math/mm_math_const.h"
#include "core/mm_value_transform.h"


namespace mm
{

	const std::string KO_dog_mailbox_game_playing::event_close("event_close");

	KO_dog_mailbox_game_playing::KO_dog_mailbox_game_playing()
		: d_flake_context(NULL)
		, d_surface(NULL)		

		, l_layer(NULL)
		, StaticImage_basic(NULL)
		, Button_A(NULL)
		, Button_B(NULL)
		, Button_C(NULL)
		, Button_D(NULL)
		, Button_select(NULL)
		, Button_start(NULL)
		, Button_quit(NULL)
		, StaticImage_yaogan(NULL)
		, DefaultWindow_mid(NULL)
		, StaticImage_table(NULL)
		, StaticText_test(NULL)
		, StaticImage_AB(NULL)
		, StaticImage_CD(NULL)
		, Button_AB(NULL)
		, Button_CD(NULL)

		, d_is_anchor_touch_began(false)
		, d_rotation(0)
		, d_data_path_prefix("emu")
	{
		mm_bitset_init(&this->keyb_s);
		mm_vector2_init(&this->d_anchor_center);
		mm_emu_machine_init(&this->d_emu_machine);
		mm_bitset_resize(&this->keyb_s, mm::mm_key::MediaSelect + 1);
	}
	KO_dog_mailbox_game_playing::~KO_dog_mailbox_game_playing()
	{
		mm_emu_machine_destroy(&this->d_emu_machine);
		mm_vector2_destroy(&this->d_anchor_center);
		mm_bitset_destroy(&this->keyb_s);
	}
	void KO_dog_mailbox_game_playing::set_data(mm_flake_context* flake_context , mm_flake_surface* surface)
	{
		this->d_flake_context = flake_context;	
		this->d_surface = surface;
	}
	void KO_dog_mailbox_game_playing::set_l_layer(CEGUI::Window* l_layer)
	{
		this->l_layer = l_layer;
	}
	void KO_dog_mailbox_game_playing::setVisible(bool b)
	{
		this->l_layer->setVisible(b);
	}
	void KO_dog_mailbox_game_playing::start_games()
	{
		mm_emu_machine_Play(&this->d_emu_machine);
	}
	void KO_dog_mailbox_game_playing::stop_games()
	{
		mm_emu_machine_Pause(&this->d_emu_machine);
	}
	void KO_dog_mailbox_game_playing::on_finish_launching()
	{
		struct mm_logger* g_logger = mm_logger_instance();
		//////////////////////////////////////////////////////////////////////////

		this->StaticImage_basic = this->l_layer->getChild("StaticImage_basic");
		this->Button_select = this->StaticImage_basic->getChild("Button_select");
		this->Button_start = this->StaticImage_basic->getChild("Button_start");
		this->Button_quit = this->StaticImage_basic->getChild("Button_quit");
		this->StaticImage_yaogan = this->StaticImage_basic->getChild("StaticImage_yaogan");
		this->DefaultWindow_mid = this->StaticImage_basic->getChild("DefaultWindow_mid");
		this->StaticImage_table = this->DefaultWindow_mid->getChild("StaticImage_table");
		this->StaticText_test = this->StaticImage_basic->getChild("StaticText_test");
		this->StaticImage_AB = this->StaticImage_basic->getChild("StaticImage_AB");
		this->StaticImage_CD = this->StaticImage_basic->getChild("StaticImage_CD");
		this->Button_AB = this->StaticImage_AB->getChild("Button_AB");
		this->Button_CD = this->StaticImage_CD->getChild("Button_CD");
		this->Button_A = this->StaticImage_AB->getChild("Button_A");
		this->Button_B = this->StaticImage_AB->getChild("Button_B");
		this->Button_C = this->StaticImage_CD->getChild("Button_C");
		this->Button_D = this->StaticImage_CD->getChild("Button_D");

		//
		CEGUI::Window* StaticImage_AB;
		CEGUI::Window* StaticImage_CD;
		CEGUI::Window* Button_AB;
		CEGUI::Window* Button_CD;

		this->StaticImage_yaogan->setProperty("Image", "imageset_battlefield/yaogan0");

		this->l_layer->setVisible(true);
		////////////////////////////////////////////////////////////////////////////////
		// d_anchor_center.
		double _window_size_x = this->d_surface->d_window_size.x;
		double _window_size_y = this->d_surface->d_window_size.y;

		const CEGUI::URect& area = this->StaticImage_yaogan->getArea();

		const CEGUI::UVector2& _r_min = area.d_min;
		const CEGUI::UVector2& _r_max = area.d_max;

		CEGUI::UVector2 _r_size = CEGUI::UVector2(_r_max.d_x - _r_min.d_x, _r_max.d_y - _r_min.d_y);
		CEGUI::UVector2 _r_center = _r_min + _r_size / CEGUI::UDim(2.0f, 0);

		this->d_anchor_center.x = (_r_center.d_x.d_scale * _window_size_x) + _r_center.d_x.d_offset;
		this->d_anchor_center.y = (_r_center.d_y.d_scale * _window_size_y) + _r_center.d_y.d_offset;

		/////////////////////////////////////////////////////////////////////////

		////////////////////////////////////////////////////////////////////////////////
		this->Button_quit->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_mailbox_game_playing::on_handle_l_s_button_out, this));
		this->Button_A->subscribeEvent(CEGUI::Window::EventMouseButtonUp, CEGUI::Event::Subscriber(&KO_dog_mailbox_game_playing::on_handle_l_s_button_A_UP, this));
		this->Button_B->subscribeEvent(CEGUI::Window::EventMouseButtonUp, CEGUI::Event::Subscriber(&KO_dog_mailbox_game_playing::on_handle_l_s_button_B_UP, this));
		this->Button_C->subscribeEvent(CEGUI::Window::EventMouseButtonUp, CEGUI::Event::Subscriber(&KO_dog_mailbox_game_playing::on_handle_l_s_button_C_UP, this));
		this->Button_D->subscribeEvent(CEGUI::Window::EventMouseButtonUp, CEGUI::Event::Subscriber(&KO_dog_mailbox_game_playing::on_handle_l_s_button_D_UP, this));
		this->Button_select->subscribeEvent(CEGUI::Window::EventMouseButtonUp, CEGUI::Event::Subscriber(&KO_dog_mailbox_game_playing::on_handle_l_s_button_select_UP, this));
		this->Button_start->subscribeEvent(CEGUI::Window::EventMouseButtonUp, CEGUI::Event::Subscriber(&KO_dog_mailbox_game_playing::on_handle_l_s_button_start_UP, this));
		this->Button_A->subscribeEvent(CEGUI::Window::EventMouseButtonDown, CEGUI::Event::Subscriber(&KO_dog_mailbox_game_playing::on_handle_l_s_button_A_DOWN, this));
		this->Button_B->subscribeEvent(CEGUI::Window::EventMouseButtonDown, CEGUI::Event::Subscriber(&KO_dog_mailbox_game_playing::on_handle_l_s_button_B_DOWN, this));
		this->Button_C->subscribeEvent(CEGUI::Window::EventMouseButtonDown, CEGUI::Event::Subscriber(&KO_dog_mailbox_game_playing::on_handle_l_s_button_C_DOWN, this));
		this->Button_D->subscribeEvent(CEGUI::Window::EventMouseButtonDown, CEGUI::Event::Subscriber(&KO_dog_mailbox_game_playing::on_handle_l_s_button_D_DOWN, this));
		this->Button_select->subscribeEvent(CEGUI::Window::EventMouseButtonDown, CEGUI::Event::Subscriber(&KO_dog_mailbox_game_playing::on_handle_l_s_button_select_DOWN, this));
		this->Button_start->subscribeEvent(CEGUI::Window::EventMouseButtonDown, CEGUI::Event::Subscriber(&KO_dog_mailbox_game_playing::on_handle_l_s_button_start_DOWN, this));

		this->StaticImage_table_EventUpdated = this->StaticImage_table->subscribeEvent(CEGUI::Window::EventUpdated, CEGUI::Event::Subscriber(&KO_dog_mailbox_game_playing::on_StaticImage_table_EventUpdated, this));

		/////////////////////////////////////////////////////////////////////
		this->d_event_updated_conn = this->d_surface->d_event_set.subscribe_event(mm_flake_surface::event_updated, &KO_dog_mailbox_game_playing::on_event_updated, this);

		this->d_event_mouse_moved_conn = this->d_surface->d_event_set.subscribe_event(mm_flake_surface::event_touchs_moved, &KO_dog_mailbox_game_playing::on_event_mouse_moved, this);
		this->d_event_mouse_began_conn = this->d_surface->d_event_set.subscribe_event(mm_flake_surface::event_touchs_began, &KO_dog_mailbox_game_playing::on_event_mouse_began, this);
		this->d_event_mouse_ended_conn = this->d_surface->d_event_set.subscribe_event(mm_flake_surface::event_touchs_ended, &KO_dog_mailbox_game_playing::on_event_mouse_ended, this);
		this->d_event_key_pressed_conn = this->d_surface->d_event_set.subscribe_event(mm_flake_surface::event_key_pressed, &KO_dog_mailbox_game_playing::on_event_key_pressed, this);
		this->d_event_key_release_conn = this->d_surface->d_event_set.subscribe_event(mm_flake_surface::event_key_release, &KO_dog_mailbox_game_playing::on_event_key_release, this);
		/////////////////////////////////////////////////////////////////////
		mm_emu_machine_SetContext(&this->d_emu_machine, this->d_flake_context);
		mm_emu_machine_SetDataPath(&this->d_emu_machine, "emu");
		mm_emu_machine_UpdateAssetsPath(&this->d_emu_machine);
		mm_emu_machine_SetName(&this->d_emu_machine, "emu_0");
		mm_emu_machine_SetRomPath(&this->d_emu_machine, "rom/Red Fortress.nes");
		mm_emu_machine_LoadRom(&this->d_emu_machine);
		mm_emu_machine_Start(&this->d_emu_machine);
		//////////////////////////////////////////////////////////////////////////
		mm_ogre_system* _ogre_system = &this->d_flake_context->d_ogre_system;
		_ogre_system->acquire_materials_resources(this->d_data_path_prefix, this->d_data_path_prefix + "/materials");

		CEGUI::GeometryBuffer* _GeometryBuffer = &this->StaticImage_table->getGeometryBuffer();
		CEGUI::CEGUIOgreGeometryBuffer* _CEGUIOgreGeometryBuffer = (CEGUI::CEGUIOgreGeometryBuffer*)_GeometryBuffer;

		Ogre::ResourceGroupManager& _resource_group_mgr = Ogre::ResourceGroupManager::getSingleton();
		_resource_group_mgr.initialiseResourceGroup(this->d_data_path_prefix + "/materials");
		//////////////////////////////////////////////////////////////////////////
		Ogre::MaterialManager* _MaterialManager = Ogre::MaterialManager::getSingletonPtr();
		Ogre::MaterialPtr _MaterialPtr = _MaterialManager->getByName("EMU/GeometryBuffer", this->d_data_path_prefix + "/materials");
		this->StaticImage_table->setProperty("Image", mm_emu_machine_GetImageName(&this->d_emu_machine));

		Ogre::AliasTextureNamePairList AliasTextureName;

		AliasTextureName["EMU/GeometryBuffer0"] = mm_emu_machine_GetAliasTextureName0(&this->d_emu_machine);
		AliasTextureName["EMU/GeometryBuffer1"] = mm_emu_machine_GetAliasTextureName1(&this->d_emu_machine);

		_MaterialPtr->applyTextureAliases(AliasTextureName);

		_CEGUIOgreGeometryBuffer->setMaterial(_MaterialPtr);

		// set rocker emu_machine
		this->rocker_key.set_emu_machine(&this->d_emu_machine);
	}
	void KO_dog_mailbox_game_playing::on_before_terminate()
	{
		mm_emu_machine_Shutdown(&this->d_emu_machine);
		mm_emu_machine_Join(&this->d_emu_machine);
		//////////////////////////////////////////////////////////////////////////
		mm_ogre_system* _ogre_system = &this->d_flake_context->d_ogre_system;
		_ogre_system->release_materials_resources(this->d_data_path_prefix, this->d_data_path_prefix + "/materials");

		//////////////////////////////////////////////////////////////////////////
		this->d_surface->d_event_set.unsubscribe_event(mm_flake_surface::event_updated, this->d_event_updated_conn);

		this->d_surface->d_event_set.unsubscribe_event(mm_flake_surface::event_touchs_moved, this->d_event_mouse_moved_conn);
		this->d_surface->d_event_set.unsubscribe_event(mm_flake_surface::event_touchs_began, this->d_event_mouse_began_conn);
		this->d_surface->d_event_set.unsubscribe_event(mm_flake_surface::event_touchs_ended, this->d_event_mouse_ended_conn);

		this->d_surface->d_event_set.unsubscribe_event(mm_flake_surface::event_key_pressed, this->d_event_key_pressed_conn);
		this->d_surface->d_event_set.unsubscribe_event(mm_flake_surface::event_key_release, this->d_event_key_release_conn);		
	}

	bool KO_dog_mailbox_game_playing::on_event_updated(const mm_event_args& args)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		return false;
	}

	bool KO_dog_mailbox_game_playing::on_event_mouse_moved(const mm_event_args& args)
	{
		const mm_event_touch_set& evt = (const mm_event_touch_set&)(args);
		this->update_anchor_quaternion(evt.content.touchs[0].abs_x, evt.content.touchs[0].abs_y);

		return false;
	}
	bool KO_dog_mailbox_game_playing::on_event_mouse_began(const mm_event_args& args)
	{
		const mm_event_touch_set& evt = (const mm_event_touch_set&)(args);

		struct mm_logger* g_logger = mm_logger_instance();
		for (size_t i = 0; i < evt.content.size; i++)
		{
			mm_logger_log_I(g_logger, "KO_dog_mailbox_game_playing::%s %d size=%d force_value=%lf major_radius=%lf button_mask=%d motion_id=%d abs_x=%lf  tap_count=%d phase= %d", 
				__FUNCTION__, __LINE__, evt.content.size, evt.content.touchs[i].force_value, evt.content.touchs[i].major_radius , evt.content.touchs[i].button_mask ,evt.content.touchs[i].motion_id,
				evt.content.touchs[i].abs_x, evt.content.touchs[i].tap_count, evt.content.touchs[i].phase);
		}
		

		/////////////////////////////////////////////////////////////////////////
		double _window_size_x = this->d_surface->d_window_size.x;
		double _window_size_y = this->d_surface->d_window_size.y;

		const CEGUI::URect& area = this->StaticImage_yaogan->getArea();

		const CEGUI::UVector2& _r_min = area.d_min;
		const CEGUI::UVector2& _r_max = area.d_max;

		struct mm_vector2 _r_min_f;
		struct mm_vector2 _r_max_f;

		_r_min_f.x = (_r_min.d_x.d_scale * _window_size_x) + _r_min.d_x.d_offset;
		_r_min_f.y = (_r_min.d_y.d_scale * _window_size_y) + _r_min.d_y.d_offset;

		_r_max_f.x = (_r_max.d_x.d_scale * _window_size_x) + _r_max.d_x.d_offset;
		_r_max_f.y = (_r_max.d_y.d_scale * _window_size_y) + _r_max.d_y.d_offset;

		if ((_r_min_f.x <= evt.content.touchs->abs_x) &&
			(_r_max_f.x > evt.content.touchs->abs_x) &&
			(_r_min_f.y <= evt.content.touchs->abs_y) &&
			(_r_max_f.y > evt.content.touchs->abs_y))
		{
			// touch position at area.
			this->d_is_anchor_touch_began = true;
			this->StaticImage_yaogan->setProperty("Image", "imageset_battlefield/yaogan");


			this->update_anchor_quaternion(evt.content.touchs->abs_x, evt.content.touchs->abs_y);
		}

		///////////////////////////////////////////////////////////////////////////
		//this->update_anchor_quaternion(args);
		return false;
	}
	bool KO_dog_mailbox_game_playing::on_event_mouse_ended(const mm_event_args& args)
	{
		const mm_event_touch_set& evt = (const mm_event_touch_set&)(args);
		struct mm_logger* g_logger = mm_logger_instance();
		for (size_t i = 0; i < evt.content.size; i++)
		{
			mm_logger_log_I(g_logger, "on_event_mouse_ended::%s %d size=%d force_value=%lf major_radius=%lf button_mask=%d motion_id=%d abs_x=%lf  tap_count=%d phase= %d",
				__FUNCTION__, __LINE__, evt.content.size, evt.content.touchs[i].force_value, evt.content.touchs[i].major_radius, evt.content.touchs[i].button_mask, evt.content.touchs[i].motion_id,
				evt.content.touchs[i].abs_x, evt.content.touchs[i].tap_count, evt.content.touchs[i].phase);
		}


		if (true == this->d_is_anchor_touch_began)
		{
			this->d_is_anchor_touch_began = false;
			this->StaticImage_yaogan->setProperty("Image", "imageset_battlefield/yaogan0");
			this->rocker_key.rocker_noting();
			this->StaticText_test->setText("0   du");
		}

		return false;
	}
	bool KO_dog_mailbox_game_playing::on_event_key_pressed(const mm_event_args& args)
	{
		const mm_event_key& evt = (const mm_event_key&)(args);	

		mm_emu_machine_KeyboardPressed(&this->d_emu_machine, evt.content.key);
		//		
		if (evt.content.key == mm::mm_key::ArrowUp && 1 != mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowUp))
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::ArrowUp, 1);
		}
		if (evt.content.key == mm::mm_key::ArrowDown && 1 != mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowDown))
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::ArrowDown, 1);
		}
		if (evt.content.key == mm::mm_key::ArrowLeft && 1 != mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowLeft))
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::ArrowLeft, 1);

		}
		if (evt.content.key == mm::mm_key::ArrowRight && 1 != mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowRight))
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::ArrowRight, 1);
		}

		//如果使用键盘，那么控制盘无效
		if (mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowUp) || mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowDown))
		{

		}
		else
		{

		}
		return false;
	}
	bool KO_dog_mailbox_game_playing::on_event_key_release(const mm_event_args& args)
	{
		const mm_event_key& evt = (const mm_event_key&)(args);

		mm_emu_machine_KeyboardRelease(&this->d_emu_machine, evt.content.key);
		//
		if (evt.content.key == mm::mm_key::ArrowUp)
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::ArrowUp, 0);
		}
		if (evt.content.key == mm::mm_key::ArrowDown)
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::ArrowDown, 0);
		}
		if (evt.content.key == mm::mm_key::ArrowLeft)
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::ArrowLeft, 0);
		}
		if (evt.content.key == mm::mm_key::ArrowRight)
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::ArrowRight, 0);
		}

		if (evt.content.key == mm::mm_key::C)
		{
			mm_bitset_set(&this->keyb_s, mm::mm_key::C, 0);
		}

		//如果使用键盘，那么控制盘无效
		if (mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowUp) || mm_bitset_get(&this->keyb_s, mm::mm_key::ArrowDown))
		{

		}
		else
		{

		}
		return false;
	}
	
	bool KO_dog_mailbox_game_playing::on_handle_StaticImage(const CEGUI::EventArgs& args)
	{
		return false;
	}
	bool KO_dog_mailbox_game_playing::on_handle_l_s_button_out(const CEGUI::EventArgs& args)
	{
		mm_event_args evt_ags;
		this->d_event_set.fire_event(KO_dog_mailbox_game_playing::event_close, evt_ags);
		return false;
	}
	bool KO_dog_mailbox_game_playing::on_handle_l_s_button_A_UP(const CEGUI::EventArgs& args)
	{
		mm_emu_machine_KeyboardRelease(&this->d_emu_machine, mm::mm_key::U);
		return false;
	}
	bool KO_dog_mailbox_game_playing::on_handle_l_s_button_B_UP(const CEGUI::EventArgs& args)
	{
		mm_emu_machine_KeyboardRelease(&this->d_emu_machine, mm::mm_key::I);
		return false;
	}
	bool KO_dog_mailbox_game_playing::on_handle_l_s_button_C_UP(const CEGUI::EventArgs& args)
	{
		mm_emu_machine_KeyboardRelease(&this->d_emu_machine, mm::mm_key::J);
		return false;
	}
	bool KO_dog_mailbox_game_playing::on_handle_l_s_button_D_UP(const CEGUI::EventArgs& args)
	{
		mm_emu_machine_KeyboardRelease(&this->d_emu_machine, mm::mm_key::K);
		return false;
	}
	bool KO_dog_mailbox_game_playing::on_handle_l_s_button_select_UP(const CEGUI::EventArgs& args)
	{
		mm_emu_machine_KeyboardRelease(&this->d_emu_machine, mm::mm_key::V);
		return false;
	}
	bool KO_dog_mailbox_game_playing::on_handle_l_s_button_start_UP(const CEGUI::EventArgs& args)
	{
		mm_emu_machine_KeyboardRelease(&this->d_emu_machine, mm::mm_key::B);
		return false;
	}
	bool KO_dog_mailbox_game_playing::on_handle_l_s_button_A_DOWN(const CEGUI::EventArgs& args)
	{
		mm_emu_machine_KeyboardPressed(&this->d_emu_machine, mm::mm_key::U);
		return false;
	}
	bool KO_dog_mailbox_game_playing::on_handle_l_s_button_B_DOWN(const CEGUI::EventArgs& args)
	{
		mm_emu_machine_KeyboardPressed(&this->d_emu_machine, mm::mm_key::I);
		return false;
	}
	bool KO_dog_mailbox_game_playing::on_handle_l_s_button_C_DOWN(const CEGUI::EventArgs& args)
	{
		mm_emu_machine_KeyboardPressed(&this->d_emu_machine, mm::mm_key::J);
		return false;
	}
	bool KO_dog_mailbox_game_playing::on_handle_l_s_button_D_DOWN(const CEGUI::EventArgs& args)
	{
		mm_emu_machine_KeyboardPressed(&this->d_emu_machine, mm::mm_key::K);
		return false;
	}
	bool KO_dog_mailbox_game_playing::on_handle_l_s_button_select_DOWN(const CEGUI::EventArgs& args)
	{
		mm_emu_machine_KeyboardPressed(&this->d_emu_machine, mm::mm_key::V);
		return false;
	}
	bool KO_dog_mailbox_game_playing::on_handle_l_s_button_start_DOWN(const CEGUI::EventArgs& args)
	{
		mm_emu_machine_KeyboardPressed(&this->d_emu_machine, mm::mm_key::B);
		return false;
	}

	bool KO_dog_mailbox_game_playing::on_handle_l_s_button_camera(const CEGUI::EventArgs& args)
	{
		return false;
	}

	bool KO_dog_mailbox_game_playing::on_StaticImage_table_EventUpdated(const CEGUI::EventArgs& args)
	{
		const CEGUI::UpdateEventArgs& evt = (const CEGUI::UpdateEventArgs&)(args);

		mm_emu_machine_UpdateFrameBitmap(&this->d_emu_machine);
		return true;
	}


	void KO_dog_mailbox_game_playing::update_anchor_quaternion(double abs_x, double abs_y)
	{
		if (true == this->d_is_anchor_touch_began)
		{
			double dx = abs_x - this->d_anchor_center.x;
			double dy = abs_y - this->d_anchor_center.y;

			this->d_rotation = atan2(dy, dx) - MM_PI_2;
			mm_fix32 k_yaogan_hudu = fmod(5 * MM_PI_2 - (atan2(dy, dx)), MM_PI_2 * 4);
			// the original quaternion is -pi / 2.
			CEGUI::Quaternion ce_quaternion = CEGUI::Quaternion::axisAngleRadians(CEGUI::Vector3f(0, 0, 1), (float)(this->d_rotation));
			this->StaticImage_yaogan->setRotation(ce_quaternion);
			this->StaticImage_yaogan->setVisible(true);

			// input rocker
			mm_fix32 rocker = this->rocker_key.input_rotation(this->d_rotation);
			this->StaticText_test->setText(rocker.to_string() + " du");
		}
	}
}

