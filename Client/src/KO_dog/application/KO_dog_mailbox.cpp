#include "KO_dog_mailbox.h"


#include "CEGUI/System.h"
#include "CEGUI/GUIContext.h"
#include "CEGUI/SchemeManager.h"
#include "CEGUI/WindowManager.h"
#include "CEGUI/RenderingWindow.h"


#include "CEGUI/widgets/Tree.h"
#include "CEGUI/ImageManager.h"



#include "KO_dog.h"
#include "network/network_handle.h"
#include "protodef/cxx/protodef/c_business_account.pb.h"

namespace mm
{
	const std::string KO_dog_mailbox::event_quit("event_quit");
	const std::string KO_dog_mailbox::event_game("event_game");

	KO_dog_mailbox::KO_dog_mailbox()
		: d_flake_context(NULL)
		, d_surface(NULL)

		, l_home_lj_mailbox(NULL)

		//, l_layer_dog_a1(NULL)
		, l_home_lj_mailbox_search(NULL)

		, StaticImage_basic(NULL)
		, DefaultWindow_left(NULL)
		, Button_search(NULL)
		, StaticImage_Tree_image(NULL)
		, Tree_friend(NULL)
		, Button_game(NULL)
		, StaticText_nt(NULL)
		, Listbox_nt(NULL)
		, Button_quit(NULL)
		, DefaultWindow_right(NULL)

		, p_apply_friend_info(NULL)
	{

	}

	KO_dog_mailbox::~KO_dog_mailbox()
	{

	}

	void KO_dog_mailbox::set_data(mm_flake_context* d_flake_context, mm_flake_surface* d_surface)
	{
		this->d_flake_context = d_flake_context;
		this->d_surface = d_surface;		
	}
	void KO_dog_mailbox::set_l_layer(CEGUI::Window* l_layer)
	{
		this->l_home_lj_mailbox = l_layer;
	}
	void KO_dog_mailbox::on_finish_launching()
	{
		struct mm_logger* g_logger = mm_logger_instance();
		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();
		//////////////////////////////////////////////////////////////////////////
		//this->l_layer_dog_a1 = _window_manager->loadLayoutFromFile("l_layer_dog_a1.layout");
		this->l_home_lj_mailbox_search = _window_manager->loadLayoutFromFile("l_home_lj_mailbox_search.layout");
		this->l_home_lj_mailbox_friend_apply = _window_manager->loadLayoutFromFile("l_home_lj_mailbox_friend_apply.layout");
		//////////////////////////////////////////////////////////////////////////
		this->StaticImage_basic = this->l_home_lj_mailbox->getChild("StaticImage_basic");
		this->DefaultWindow_left = this->l_home_lj_mailbox->getChild("DefaultWindow_left");
		this->Button_search = this->DefaultWindow_left->getChild("Button_search");
		this->StaticImage_Tree_image = this->DefaultWindow_left->getChild("StaticImage_Tree_image");
		this->Tree_friend = this->StaticImage_Tree_image->getChild("Tree_friend");
		this->Button_game = this->DefaultWindow_left->getChild("Button_game");
		this->StaticText_nt = this->DefaultWindow_left->getChild("StaticText_nt");
		this->Listbox_nt = this->StaticText_nt->getChild("Listbox_nt");
		this->Button_quit = this->DefaultWindow_left->getChild("Button_quit");
		this->DefaultWindow_right = this->l_home_lj_mailbox->getChild("DefaultWindow_right");
		////////////////////////////////////////////////////////////////////////////////
		//Set up layers l_home_lj_mailbox_search
		this->mailbox_search.set_data(this->d_flake_context, this->d_surface);
		this->mailbox_search.set_l_layer(this->l_home_lj_mailbox_search);
		this->mailbox_search.on_finish_launching();
		//Set up layers l_home_lj_mailbox_friend_apply
		this->mailbox_friend_apply.set_data(this->d_flake_context, this->d_surface);
		this->mailbox_friend_apply.set_l_layer(this->l_home_lj_mailbox_friend_apply);
		this->mailbox_friend_apply.on_finish_launching();
		////////////////////////////////////////////////////////////////////////////////
		CEGUI::URect  ur = { {0, 0}, {0, 0}, {1, 0}, {1, 0} };
		this->DefaultWindow_right->addChild(this->l_home_lj_mailbox_search);
		this->l_home_lj_mailbox_search->setArea(ur);
		this->DefaultWindow_right->addChild(this->l_home_lj_mailbox_friend_apply);
		this->l_home_lj_mailbox_friend_apply->setArea(ur);
		////////////////////////////////////////////////////////////////////////////////
		this->l_home_lj_mailbox_search->setVisible(false);
		this->l_home_lj_mailbox_friend_apply->setVisible(false);
		////////////////////////////////////////////////////////////////////////////////

		this->Button_search->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Button_search, this));
		//Tree handle
		{
			CEGUI::Tree* theTree = (CEGUI::Tree*)this->Tree_friend;
			theTree->initialise();
			theTree->subscribeEvent(CEGUI::Tree::EventSelectionChanged, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Tree_friend_Select, this));
			theTree->subscribeEvent(CEGUI::Tree::EventBranchOpened, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Tree_friend_Open, this));
			theTree->subscribeEvent(CEGUI::Tree::EventBranchClosed, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Tree_friend_Close, this));

			//测试Tree 添加数据
			CEGUI::TreeItem *  newTreeCtrlEntryLvl1;
			CEGUI::TreeItem *  newTreeCtrlEntryLvl2;


			newTreeCtrlEntryLvl1 = new CEGUI::TreeItem("1c",1);
			newTreeCtrlEntryLvl1->setTextColours(CEGUI::Colour(0xff00ff00));
			newTreeCtrlEntryLvl1->setSelectionBrushImage("TaharezLook" "/TextSelectionBrush");
			theTree->addItem(newTreeCtrlEntryLvl1);
			newTreeCtrlEntryLvl2 = new CEGUI::TreeItem("2a (1a)",1);
			newTreeCtrlEntryLvl2->setSelectionBrushImage("TaharezLook" "/TextSelectionBrush");
			newTreeCtrlEntryLvl1->addItem(newTreeCtrlEntryLvl2);

			newTreeCtrlEntryLvl1 = new CEGUI::TreeItem("2c",2);
			newTreeCtrlEntryLvl1->setTextColours(CEGUI::Colour(0xff00ff00));
			newTreeCtrlEntryLvl1->setSelectionBrushImage("TaharezLook" "/TextSelectionBrush");
			theTree->addItem(newTreeCtrlEntryLvl1);
			newTreeCtrlEntryLvl1->setText("222222222");
			//theTree->removeItem(newTreeCtrlEntryLvl1);

		}
		this->Button_game->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Button_game, this));
		this->Button_quit->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Button_quit, this));
		this->Listbox_nt->subscribeEvent(CEGUI::Listbox::EventSelectionChanged, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Listbox_nt_select, this));




		//
		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		//订阅KO_dog_data_relation 的 event 事件
		this->d_event_data_add_friend_nt_conn = p_dog->data.data_user_basic.d_event_set.subscribe_event(KO_dog_data_user_basic::event_data_add_friend_nt, &KO_dog_mailbox::on_handle_event_data_add_friend_nt, this);
		this->d_event_data_respond_friend_nt_conn = p_dog->data.data_user_basic.d_event_set.subscribe_event(KO_dog_data_user_basic::event_data_respond_friend_nt, &KO_dog_mailbox::on_handle_event_data_respond_friend_nt, this);
	
		
		//初始化部分逻辑数据
		this->map_apply_friend_wp.clear();
	}
	void KO_dog_mailbox::on_before_terminate()
	{
		//清理部分逻辑数据
		this->map_apply_friend_wp.clear();

		//KO_dog_data_relation 的 event 事件 解绑
		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		p_dog->data.data_relation.d_event_set.unsubscribe_event(KO_dog_data_user_basic::event_data_add_friend_nt, this->d_event_data_add_friend_nt_conn);

		////////////////////////////////////////////////////////////////////////////////
		this->DefaultWindow_right->removeChild(this->l_home_lj_mailbox_search);
		this->DefaultWindow_right->removeChild(this->l_home_lj_mailbox_friend_apply);
		////////////////////////////////////////////////////////////////////////////////
		this->mailbox_friend_apply.on_before_terminate();
		this->mailbox_search.on_before_terminate();
		////////////////////////////////////////////////////////////////////////////////
		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();
		_window_manager->destroyWindow(this->l_home_lj_mailbox_search);
		_window_manager->destroyWindow(this->l_home_lj_mailbox_friend_apply);
		////////////////////////////////////////////////////////////////////////////////

		struct mm_logger* g_logger = mm_logger_instance();
		mm_logger_log_I(g_logger, "KO_dog_mailbox::%s %d success.", __FUNCTION__, __LINE__);
	}

	bool KO_dog_mailbox::on_handle_Button_search(const CEGUI::EventArgs& args)
	{
		this->l_home_lj_mailbox_search->setVisible(true);
		return false;
	}

	bool KO_dog_mailbox::on_handle_Tree_friend_Select(const CEGUI::EventArgs& args)
	{
		this->l_home_lj_mailbox_search->setVisible(false);
		return false;
	}
	bool KO_dog_mailbox::on_handle_Tree_friend_Open(const CEGUI::EventArgs& args)
	{
		this->l_home_lj_mailbox_search->setVisible(false);
		return false;
	}
	bool KO_dog_mailbox::on_handle_Tree_friend_Close(const CEGUI::EventArgs& args)
	{
		this->l_home_lj_mailbox_search->setVisible(false);
		return false;
	}
	bool KO_dog_mailbox::on_handle_Button_game(const CEGUI::EventArgs& args)
	{
		this->l_home_lj_mailbox_search->setVisible(false);
		mm_event_args evt_ags;
		this->d_event_set.fire_event(KO_dog_mailbox::event_game, evt_ags);
		return false;
	}
	bool KO_dog_mailbox::on_handle_Button_quit(const CEGUI::EventArgs& args)
	{
		this->l_home_lj_mailbox_search->setVisible(false);
		mm_event_args evt_ags;
		this->d_event_set.fire_event(KO_dog_mailbox::event_quit, evt_ags);
		return false;
	}
	bool KO_dog_mailbox::on_handle_Listbox_nt_select(const CEGUI::EventArgs& args)
	{
		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		mm::KO_dog_data_user_basic* p_data_user_basic = &p_dog->data.data_user_basic;
		CEGUI::Listbox* listb = (CEGUI::Listbox*)this->Listbox_nt;

		size_t choices_num = listb->getSelectedCount();
		if (choices_num > 0)
		{
			CEGUI::ListboxItem*	getFirst = listb->getFirstSelectedItem();
			this->p_apply_friend_info = (data_basic_friend_info*)getFirst->getUserData();
			this->mailbox_friend_apply.p_friend_apply = p_apply_friend_info;
			this->mailbox_friend_apply.setVisible(true);
			this->mailbox_friend_apply.setVisible_opcode(true);
		}
		else
		{
			this->mailbox_friend_apply.p_friend_apply = NULL;
			this->mailbox_friend_apply.setVisible(false);
			this->mailbox_friend_apply.setVisible_opcode(false);
			this->mailbox_friend_apply.setVisible_friend(false);

		}
		return false;
	}

	//bool KO_dog_mailbox::on_handle_event_data_friend_apply_update(const mm_event_args& args)
	//{
	//	mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
	//	mm::KO_dog_data_user_basic* p_data_user_basic = &p_dog->data.data_user_basic;
	//	CEGUI::Listbox* listb = (CEGUI::Listbox*)this->Listbox_nt;
	//	//更新新数据
	//	int i = 0;
	//	//typedef 做一个短名称
	//	typedef mm::KO_dog_data_user_basic::v_friend_apply user_apply_vec;
	//	user_apply_vec& vec = p_data_user_basic->friend_apply;

	//	//遍历容器
	//	for (user_apply_vec::iterator it = vec.begin();
	//		it != vec.end(); it++, i++)
	//	{
	//		//获取具体迭代器包含的元素引用
	//		mm::data_apply_friend_basic& e = *it;

	//		CEGUI::ListboxTextItem* item = new CEGUI::ListboxTextItem(e.friend_basic.name, e.friend_basic.id);
	//		item->setSelectionBrushImage("TaharezLook" "/TextSelectionBrush");
	//		listb->addItem(item);
	//	}
	//	return false;
	//}
	bool KO_dog_mailbox::on_handle_event_data_add_friend_nt(const mm_event_args& args)
	{
		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		mm::KO_dog_data_user_basic* p_data_user_basic = &p_dog->data.data_user_basic;
		CEGUI::Listbox* listb = (CEGUI::Listbox*)this->Listbox_nt;
		//更新新数据
		mm::mm_event_map_ags& ags = (mm::mm_event_map_ags&)args;
		mm::data_basic_friend_info* p_info = (mm::data_basic_friend_info*)ags.e;

		if (NULL != p_info)
		{
			CEGUI::ListboxTextItem* item = new CEGUI::ListboxTextItem(p_info->name, 0, p_info);
			item->setSelectionBrushImage("TaharezLook" "/TextSelectionBrush");
			listb->addItem(item);

			this->map_apply_friend_wp.add(p_info->id, item);
		}

		return false;
	}
	bool KO_dog_mailbox::on_handle_event_data_respond_friend_nt(const mm_event_args& args)
	{
		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		mm::KO_dog_data_user_basic* p_data_user_basic = &p_dog->data.data_user_basic;
		CEGUI::Listbox* listb = (CEGUI::Listbox*)this->Listbox_nt;
		//更新新数据
		mm::mm_event_map_ags& ags = (mm::mm_event_map_ags&)args;
		mm::data_basic_friend_info* p_info = (mm::data_basic_friend_info*)ags.e;

		if (NULL != p_info)
		{
			CEGUI::ListboxTextItem* item = this->map_apply_friend_wp.get(p_info->id);
			if (NULL != item)
			{
				listb->removeItem(item);
			}
			this->map_apply_friend_wp.rmv(p_info->id);
		}
		return false;
	}

}