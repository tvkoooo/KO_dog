#include "lj_KO_dog_zhujiemian.h"


#include "CEGUI/System.h"
#include "CEGUI/GUIContext.h"
#include "CEGUI/SchemeManager.h"
#include "CEGUI/WindowManager.h"
#include "CEGUI/RenderingWindow.h"

#include "KO_dog.h"
#include "network/network_handle.h"
#include "protodef/cxx/protodef/c_business_account.pb.h"

#include "lua/mm_lua.h"

namespace mm
{
	lj_KO_dog_zhujiemian::lj_KO_dog_zhujiemian()
		: d_flake_context(NULL)
		, d_surface(NULL)
		, d_window_login(NULL)
		, l_home_lj_login(NULL)
		, MenuWindow(NULL)
		, l_edit_text_id(NULL)
		, l_s_button_login(NULL)
		, l_s_button_out(NULL)
		, l_edit_text_pwd(NULL)
		, l_s_button_register(NULL)
		, l_text_id(NULL)
		, l_text_pwd(NULL)
		, l_text_notice(NULL)
		, StaticImage(NULL)
		, l_image_gold1(NULL)
		, l_image_gold2(NULL)
		, l_image_gold3(NULL)
		, l_image_gold4(NULL)
		, l_image_gold5(NULL)
		, l_image_gold_y1(NULL)
		, l_image_gold_y2(NULL)
		, l_image_gold_mov(NULL)

		, d_scene_manager(NULL)
		, d_root_node(NULL)
		, d_node_camera(NULL)
		, d_camera(NULL)
		, d_viewport(NULL)
		, d_light_node(NULL)
		, d_dir_light(NULL)

		, d_coin_node(NULL)
		, d_coin_mesh(NULL)
		, d_coin_rotation(0)

		, image_gold_gif_n(0)
		, d_rotation(0)


	{
		mm_windows_target_init(&this->d_windows_target);
	}

	lj_KO_dog_zhujiemian::~lj_KO_dog_zhujiemian()
	{
		mm_windows_target_destroy(&this->d_windows_target);
	}

	void lj_KO_dog_zhujiemian::set_data(mm_flake_context* d_flake_context, mm_flake_surface* d_surface)
	{
		this->d_flake_context = d_flake_context;
		this->d_surface = d_surface;
	}

	void lj_KO_dog_zhujiemian::on_finish_launching()
	{
		this->scene_layer_launching();
	}
	void lj_KO_dog_zhujiemian::on_before_terminate()
	{
		this->scene_layer_terminate();
		struct mm_logger* g_logger = mm_logger_instance();
		mm_logger_log_I(g_logger, "lj_KO_dog_zhujiemian::%s %d success.", __FUNCTION__, __LINE__);

	}
	void lj_KO_dog_zhujiemian::scene_layer_launching()
	{
		struct mm_logger* g_logger = mm_logger_instance();
		//////////////////////////////////////////////////////////////////////////
		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();

		this->d_window_login = (CEGUI::Window*)_window_manager->createWindow("DefaultWindow", "root_window_0");
		this->l_home_lj_login = _window_manager->loadLayoutFromFile("l_home_lj_login.layout");

		this->MenuWindow = this->l_home_lj_login->getChild("MenuWindow");
		this->l_edit_text_id = this->MenuWindow->getChild("l_edit_text_id");
		this->l_s_button_login = this->MenuWindow->getChild("l_s_button_login");
		this->l_s_button_out = this->MenuWindow->getChild("l_s_button_out");
		this->l_edit_text_pwd = this->MenuWindow->getChild("l_edit_text_pwd");
		this->l_s_button_register = this->MenuWindow->getChild("l_s_button_register");
		this->l_text_id = this->MenuWindow->getChild("l_text_id");
		this->l_text_pwd = this->MenuWindow->getChild("l_text_pwd");
		this->l_text_notice = this->MenuWindow->getChild("l_text_notice");
		this->l_image_gold1 = this->MenuWindow->getChild("l_image_gold1");
		this->l_image_gold2 = this->MenuWindow->getChild("l_image_gold2");
		this->l_image_gold3 = this->MenuWindow->getChild("l_image_gold3");
		this->l_image_gold4 = this->MenuWindow->getChild("l_image_gold4");
		this->l_image_gold5 = this->MenuWindow->getChild("l_image_gold5");
		this->l_image_gold_y1 = this->MenuWindow->getChild("l_image_gold_y1");
		this->l_image_gold_y2 = this->MenuWindow->getChild("l_image_gold_y2");
		this->l_image_gold_mov = this->MenuWindow->getChild("l_image_gold_mov");

		this->StaticImage = this->l_home_lj_login->getChild("StaticImage");


		this->l_text_id->setText("Your ID");
		this->l_text_pwd->setText("Your password");
		//this->l_ensure->setVisible(false);
		CEGUI::GUIContext* _gui_context = this->d_surface->d_gui_context;
		this->d_window_login->addChild(this->l_home_lj_login);

		_gui_context->setRootWindow(this->d_window_login);
		_gui_context->getMouseCursor().setVisible(false);

		this->l_s_button_login->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&lj_KO_dog_zhujiemian::on_handle_l_s_button_login, this));
		this->l_s_button_out->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&lj_KO_dog_zhujiemian::on_handle_l_s_button_out, this));
		this->l_s_button_register->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&lj_KO_dog_zhujiemian::on_handle_l_s_button_register, this));

		this->MenuWindow->subscribeEvent(CEGUI::Window::EventUpdated, CEGUI::Event::Subscriber(&lj_KO_dog_zhujiemian::on_handle_MenuWindow_updated, this));


		this->d_event_l_animation_closed_conn = this->test_animation.d_event_set.subscribe_event(KO_dog_test_animation::event_close, &lj_KO_dog_zhujiemian::on_handle_l_animation_closed, this);

		
		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		//订阅KO_dog_data_user_basic 的 event_userdata_update 事件
		this->d_event_userdata_update_conn = p_dog->data.data_user_basic.d_event_set.subscribe_event(KO_dog_data_user_basic::event_userdata_update, &lj_KO_dog_zhujiemian::on_handle_event_userdata_update, this);

		//订阅KO_dog_data_log_view 的 event_log_view 事件
		this->d_event_log_view_conn = p_dog->data.data_log_view.d_event_set.subscribe_event(KO_dog_data_log_view::event_log_view, &lj_KO_dog_zhujiemian::on_handle_event_log_view, this);

		//////////////////////////////////////////////////////////////////////
		this->l_image_gold_mov->setVisible(true);
		this->d_windows_target.d_name = "gold_mov";
		this->d_windows_target.d_image_window = this->l_image_gold_mov;
		this->d_windows_target.d_cegui_system = &this->d_flake_context->d_cegui_system;
		mm_windows_target_launching(&this->d_windows_target);
		//////////////////////////////////////////////////////////////////////
		Ogre::RenderTarget* _render_target = this->d_windows_target.d_render_target;
		//////////////////////////////////////////////////////////////////////
		Ogre::Root* _ogre_root = this->d_flake_context->d_ogre_system.get_ogre_root();

		// Create the scene manager
		this->d_scene_manager = _ogre_root->createSceneManager();
		Ogre::RTShader::ShaderGenerator::getSingletonPtr()->addSceneManager(this->d_scene_manager);
		// Create and initialise the camera
		this->d_root_node = this->d_scene_manager->getRootSceneNode();
		/////////////////////////////////////////////////////////////////////
		this->d_camera = this->d_scene_manager->createCamera("main_camera");
		//this->d_camera->setPosition(Ogre::Vector3(0, 0, 0));
		//this->d_camera->lookAt(Ogre::Vector3(0, 0, 0));
		this->d_camera->setNearClipDistance(1.0f);
		this->d_camera->setFarClipDistance(100000.0f);
		this->d_camera->setAutoAspectRatio(true);

		this->d_node_camera = this->d_root_node->createChildSceneNode();
		this->d_node_camera->attachObject(this->d_camera);

		this->d_viewport = _render_target->addViewport(this->d_camera);
		this->d_camera->setAspectRatio(Ogre::Real(this->d_viewport->getActualWidth()) / Ogre::Real(this->d_viewport->getActualHeight()));

		Ogre::Vector3 lightdir(0.55f, -0.3f, -0.75f);
		lightdir.normalise();
		this->d_light_node = this->d_root_node->createChildSceneNode();
		this->d_dir_light = this->d_scene_manager->createLight();
		this->d_dir_light->setType(Ogre::Light::LT_DIRECTIONAL);
		this->d_dir_light->setDirection(lightdir);
		this->d_dir_light->setDiffuseColour(Ogre::ColourValue::White);
		this->d_dir_light->setSpecularColour(Ogre::ColourValue(0.4f, 0.4f, 0.4f));
		this->d_light_node->attachObject(this->d_dir_light);

		this->d_scene_manager->setAmbientLight(Ogre::ColourValue(1.0f, 1.0f, 1.0f));
		//////////////////////////////////////////////////////////////////////
		Ogre::ResourceGroupManager* _resource_group_manager = Ogre::ResourceGroupManager::getSingletonPtr();

		_resource_group_manager->addResourceLocation("media/models/coin", "mm_file_system", "media/models/coin");

		_resource_group_manager->initialiseResourceGroup(Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

		_resource_group_manager->initialiseResourceGroup("media/models/coin");

		this->d_coin_mesh = this->d_scene_manager->createEntity("coin", "coin.mesh", "media/models/coin");
		this->d_coin_node = this->d_root_node->createChildSceneNode();
		this->d_coin_node->attachObject(this->d_coin_mesh);

		this->d_node_camera->setPosition(Ogre::Vector3(0, 4, 0));
		this->d_node_camera->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);

		Ogre::ColourValue _viewport_colour(0, 0, 0, 0);
		this->d_viewport->setBackgroundColour(_viewport_colour);
		this->d_viewport->setClearEveryFrame(true);
		//////////////////////////////////////////////////////////////////////
		this->d_event_enter_background = this->d_surface->d_event_set.subscribe_event(mm_flake_surface::event_enter_background, &lj_KO_dog_zhujiemian::on_event_enter_background, this);
		this->d_event_enter_foreground = this->d_surface->d_event_set.subscribe_event(mm_flake_surface::event_enter_foreground, &lj_KO_dog_zhujiemian::on_event_enter_foreground, this);
		//////////////////////////////////////////////////////////////////////
		//do
		//{
		//	std::ifstream user_info_map;
		//	mm_logger_log_I(g_logger, "lj_KO_dog_zhujiemian::%s %d success.", __FUNCTION__, __LINE__);
		//	user_info_map.open("user_info.daSB");
		//	if (user_info_map.fail())
		//	{
		//		break;
		//	}
		//	while (!user_info_map.eof())
		//	{
		//		std::string key;
		//		std::string value;
		//		user_info_map >> key >> value;
		//		if (key != "")
		//		{
		//			this->user_info.insert(lj_type_map_string_string::value_type(key, value));
		//		}

		//	}
		//	user_info_map.close();
		//} while (0);
		////////////////////////////////////////////////////////////////////////
	}
	void lj_KO_dog_zhujiemian::scene_layer_terminate()
	{
		Ogre::Root* _ogre_root = this->d_flake_context->d_ogre_system.get_ogre_root();
		////////////////////////////////////////////////////////////////////////
		this->d_coin_node->detachObject(this->d_coin_mesh);
		this->d_scene_manager->destroySceneNode(this->d_coin_node);
		this->d_scene_manager->destroyEntity(this->d_coin_mesh);

		Ogre::ResourceGroupManager* _resource_group_manager = Ogre::ResourceGroupManager::getSingletonPtr();

		_resource_group_manager->removeResourceLocation("media/models/coin", "media/models/coin");
		////////////////////////////////////////////////////////////////////////
		Ogre::RenderTarget* _render_target = this->d_windows_target.d_render_target;
		//
		this->d_scene_manager->destroyLight(this->d_dir_light);
		this->d_scene_manager->destroySceneNode(this->d_light_node);
		_render_target->removeViewport(this->d_viewport->getZOrder());
		this->d_scene_manager->destroyCamera(this->d_camera);
		this->d_scene_manager->destroySceneNode(this->d_node_camera);
		//////////////////////////////////////////////////////////////////////////
		Ogre::RTShader::ShaderGenerator::getSingletonPtr()->removeSceneManager(this->d_scene_manager);
		_ogre_root->destroySceneManager(this->d_scene_manager);
		////////////////////////////////////////////////////////////////////////
		this->d_surface->d_event_set.unsubscribe_event(mm_flake_surface::event_enter_background, this->d_event_enter_background);
		this->d_surface->d_event_set.unsubscribe_event(mm_flake_surface::event_enter_foreground, this->d_event_enter_foreground);

		mm_windows_target_terminate(&this->d_windows_target);

		this->test_animation.d_event_set.unsubscribe_event(KO_dog_test_animation::event_close, this->d_event_l_animation_closed_conn);

		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		//解除 注册 KO_dog_data_user_basic 的 event_userdata_update 事件
		p_dog->data.data_user_basic.d_event_set.unsubscribe_event(KO_dog_data_user_basic::event_userdata_update, this->d_event_userdata_update_conn);

		// 解除 注册 KO_dog_data_log_view 的 event_log_view 事件
		p_dog->data.data_log_view.d_event_set.unsubscribe_event(KO_dog_data_log_view::event_log_view, this->d_event_log_view_conn);

		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();
		_window_manager->destroyWindow(this->l_home_lj_login);
		_window_manager->destroyWindow(this->d_window_login);
	}

	bool lj_KO_dog_zhujiemian::on_handle_l_s_button_login(const CEGUI::EventArgs& args)
	{
		//lj_type_map_string_string::iterator it;
		//it = this->user_info.find(user_name);
		//if (it == this->user_info.end())
		//{
		//	//没有找到
		//	this->l_text_notice->setText("You haven't applied this yet");
		//}
		//else
		//{
		//	//找到
		//	if (it->second != pass_word)
		//	{
		//		this->l_text_notice->setText("The password error");
		//	}
		//	else
		//	{
		//		this->l_text_notice->setText("Good luck");
		//		//mm_msleep(1000);
		//		this->test_animation.assign_flake_context(this->d_flake_context);
		//		this->test_animation.on_finish_launching(this->d_surface);
		//	}

		//}

		mm::KO_dog* p = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());

		if (0 != p->data.data_net.lobby_port)
		{	
			const CEGUI::String &user_name = this->l_edit_text_id->getText();
			const CEGUI::String &pass_word = this->l_edit_text_pwd->getText();

			md5_uint8 digest[16] = { 0 };
			mm_md5_starts(&this->md5_context);
			mm_md5_update(&this->md5_context, (md5_uint8 *)pass_word.c_str(), pass_word.length());
			mm_md5_finish(&this->md5_context, digest);

			char mima[33] = { 0 };
			for (size_t i = 0; i < 16; i++)
			{
				sprintf(&mima[2 * i], "%02x", digest[i]);
			}

			c_business_account::signed_in_rq rq;
			rq.set_user_name(user_name.c_str());
			rq.set_password((const char*)mima);
			mm_client_tcp_flush_send_message(&p->network.tcp,0, c_business_account::signed_in_rq_msg_id, &rq);
			this->l_text_notice->setText("Please wait.....");
		}
		else
		{
			this->l_text_notice->setText("Network unstable, retry later!");
		}

		return false;
	}
	bool lj_KO_dog_zhujiemian::on_handle_l_s_button_out(const CEGUI::EventArgs& args)
	{		
		this->d_flake_context->shutdown();
		return false;
	}
	bool lj_KO_dog_zhujiemian::on_handle_l_s_button_register(const CEGUI::EventArgs& args)
	{
		//std::string user_name = this->l_edit_text_id->getText().c_str();
		//std::string pass_word = this->l_edit_text_pwd->getText().c_str();
		
		//lj_type_map_string_string::iterator it;
		//it = this->user_info.find(user_name);
		//if (it == this->user_info.end())
		//{
		//	//没有找到
		//	this->user_info.insert(lj_type_map_string_string::value_type(user_name, pass_word));
		//	std::ofstream user_info_map;
		//	user_info_map.open("user_info.daSB", std::ofstream::app);
		//	user_info_map << user_name << "\t" << pass_word << std::endl;
		//	user_info_map.close();
		//}
		//else
		//{
		//	//找到
		//	this->l_text_notice->setText("you have register !");
		//}

		mm::KO_dog* p = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());

		if (0 != p->data.data_net.lobby_port)
		{
			const CEGUI::String &user_name = this->l_edit_text_id->getText();
			const CEGUI::String &pass_word = this->l_edit_text_pwd->getText();

			md5_uint8 digest[16] = { 0 };
			mm_md5_starts(&this->md5_context);
			mm_md5_update(&this->md5_context, (md5_uint8 *)pass_word.c_str(), pass_word.length());
			mm_md5_finish(&this->md5_context, digest);

			char mima[33] = { 0 };
			for (size_t i = 0; i < 16; i++)
			{
				sprintf(&mima[2*i],"%02x", digest[i]);
			}



			c_business_account::register_rq rq;
			rq.set_user_name(user_name.c_str());
			rq.set_password((const char*)mima);
			mm_client_tcp_flush_send_message(&p->network.tcp, 0, c_business_account::register_rq_msg_id, &rq);
			this->l_text_notice->setText("Please wait.....");
		}
		else
		{
			this->l_text_notice->setText("Network unstable, retry later!");
		}
		return false;
	}

	bool lj_KO_dog_zhujiemian::on_handle_MenuWindow_updated(const CEGUI::EventArgs& args)
	{
		const CEGUI::UpdateEventArgs& evt = (const CEGUI::UpdateEventArgs&)(args);

		this->d_coin_rotation += 30.0f * evt.d_timeSinceLastFrame;
		this->d_coin_rotation = fmod(this->d_coin_rotation, 360);

		Ogre::Quaternion _coin_quaternion;
		_coin_quaternion.FromAngleAxis(Ogre::Radian(Ogre::Degree(this->d_coin_rotation)), Ogre::Vector3::UNIT_Z);

		this->d_coin_node->setOrientation(_coin_quaternion);
		//重绘界面
		this->d_windows_target.d_image_window->invalidate();

		this->image_gold_gif_n++;	

		{
			this->d_rotation = fmod(this->d_rotation + 1,360);
			CEGUI::Quaternion ce_quaternion1 = CEGUI::Quaternion::axisAngleDegrees(CEGUI::Vector3f(0, 1, 0), this->d_rotation);
			CEGUI::Quaternion ce_quaternion2 = CEGUI::Quaternion::axisAngleDegrees(CEGUI::Vector3f(0, 1, 0), fmod(this->d_rotation +180,360));
			if (this->d_rotation ==104 )
			{
				this->l_image_gold_y2->setVisible(true);
				this->l_image_gold_y1->setVisible(false);
			}
			if (this->d_rotation == 284)
			{
				this->l_image_gold_y1->setVisible(true);
				this->l_image_gold_y2->setVisible(false);
			}
			
			this->l_image_gold_y1->setRotation(ce_quaternion1);
			this->l_image_gold_y2->setRotation(ce_quaternion2);
			//this->l_text_notice->setText(std::to_string(this->d_rotation));
		}
		if ( 0 == this->image_gold_gif_n % 10 )
		{

			switch ((this->image_gold_gif_n/10) % 8)
			{
			case 1:
			{
				this->l_image_gold2->setVisible(false);
				this->l_image_gold1->setVisible(true);
				break;
			}
			case 2:
			{
				this->l_image_gold1->setVisible(false);
				this->l_image_gold2->setVisible(true);
				break;
			}
			case 3:
			{
				this->l_image_gold2->setVisible(false);
				this->l_image_gold3->setVisible(true);
				break;
			}
			case 4:
			{
				this->l_image_gold3->setVisible(false);
				this->l_image_gold4->setVisible(true);
				break;
			}
			case 5:
			{
				this->l_image_gold4->setVisible(false);
				this->l_image_gold5->setVisible(true);
				break;
			}
			case 6:
			{
				this->l_image_gold5->setVisible(false);
				this->l_image_gold4->setVisible(true);
				break;
			}
			case 7:
			{
				this->l_image_gold4->setVisible(false);
				this->l_image_gold3->setVisible(true);
				break;
			}
			case 0:
			{
				this->l_image_gold3->setVisible(false);
				this->l_image_gold2->setVisible(true);
				break;
			}
			default:
				break;
			}

		}
		return false;
	}

	bool lj_KO_dog_zhujiemian::on_handle_l_animation_closed(const mm_event_args& args)
	{
		this->test_animation.on_before_terminate(this->d_surface);
		CEGUI::GUIContext* _gui_context = this->d_surface->d_gui_context;
		_gui_context->setRootWindow(this->d_window_login);
		return false;
	}
	bool lj_KO_dog_zhujiemian::on_handle_event_userdata_update(const mm_event_args& args)
	{
		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		mm::KO_dog_data_user_basic* data_user_basic = &p_dog->data.data_user_basic;
		if (data_user_basic->token.empty())
		{
			this->l_text_notice->setText("Error in account or password!");
		}
		else
		{
			this->l_text_notice->setText("Good luck.");
			this->test_animation.assign_flake_context(this->d_flake_context);
			this->test_animation.on_finish_launching(this->d_surface);
		}
		return false;
	}
	bool lj_KO_dog_zhujiemian::on_handle_event_log_view(const mm_event_args& args)
	{
		const mm_event_data_log_view& evt = (const mm_event_data_log_view&)args;
		// 中文展示：需要使用utf8无bom格式保存文本 后再经过 CEGUI::String 转化才能正常输出中文
		//String(const utf8* utf8_str, size_type chars_len)
		//CEGUI::String text((const CEGUI::utf8*)evt.view.c_str(), evt.view.size());

		mm::KO_dog* p = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		struct lua_State* L = p->lua_context.state;
		std::string view;
		mm::mm_lua _lua(L);
		_lua.push(evt.code);
		_lua.call("model_error", "err_code_view", 1, 1);
		_lua.pop(view);


		CEGUI::String text1((const CEGUI::utf8*)view.c_str(), view.size());
		this->l_text_notice->setText(text1);
		return false;
	}
	bool lj_KO_dog_zhujiemian::on_event_enter_background(const mm_event_args& args)
	{
		//mm_windows_target_set_active(&this->d_windows_target, false);
		return false;
	}
	bool lj_KO_dog_zhujiemian::on_event_enter_foreground(const mm_event_args& args)
	{
		//mm_windows_target_set_active(&this->d_windows_target, true);
		return false;
	}
}