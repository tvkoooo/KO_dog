#include "KO_dog_mailbox.h"


#include "CEGUI/System.h"
#include "CEGUI/GUIContext.h"
#include "CEGUI/SchemeManager.h"
#include "CEGUI/WindowManager.h"
#include "CEGUI/RenderingWindow.h"



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
		, l_home_lj_mailbox_friend_apply(NULL)
		, l_home_lj_mailbox_friend(NULL)

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

		, p_friend_friend(NULL)
		, p_friend_group(NULL)

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
	void KO_dog_mailbox::set_friend_apply_model(mm::elem_event_map<mm_uint64_t, data_basic_friend_info>* md)
	{
		////1 ����¼�
		//if (NULL != this->p_md)
		//{
		//	this->p_ip_port_state->d_event_set.unsubscribe_event(ip_port_state::event_ip_port_update, this->d_event_ip_port_update_conn);
		//	this->p_ip_port_state->d_event_set.unsubscribe_event(ip_port_state::event_socket_update, this->d_event_socket_update_conn);
		//	this->p_ip_port_state->d_event_set.unsubscribe_event(ip_port_state::event_crypto_update, this->d_event_crypto_update_conn);
		//}
		////2 ���µ�ģ������
		//this->p_ip_port_state = d;
		////3 ���¼�
		//if (NULL != this->p_ip_port_state)
		//{
		//	this->d_event_ip_port_update_conn = this->p_ip_port_state->d_event_set.subscribe_event(ip_port_state::event_ip_port_update, &KO_dog_window_ip::on_handle_event_ip_port_update, this);
		//	this->d_event_socket_update_conn = this->p_ip_port_state->d_event_set.subscribe_event(ip_port_state::event_socket_update, &KO_dog_window_ip::on_handle_event_socket_update, this);
		//	this->d_event_crypto_update_conn = this->p_ip_port_state->d_event_set.subscribe_event(ip_port_state::event_crypto_update, &KO_dog_window_ip::on_handle_event_crypto_update, this);

		//	//default Initialization
		//	mm_event_args args;
		//	this->on_handle_event_ip_port_update(args);
		//	this->on_handle_event_socket_update(args);
		//	this->on_handle_event_crypto_update(args);
		//}
	}

	void KO_dog_mailbox::on_finish_launching()
	{
		struct mm_logger* g_logger = mm_logger_instance();
		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();
		//////////////////////////////////////////////////////////////////////////
		//this->l_layer_dog_a1 = _window_manager->loadLayoutFromFile("l_layer_dog_a1.layout");
		this->l_home_lj_mailbox_search = _window_manager->loadLayoutFromFile("l_home_lj_mailbox_search.layout");
		this->l_home_lj_mailbox_friend_apply = _window_manager->loadLayoutFromFile("l_home_lj_mailbox_friend_apply.layout");
		this->l_home_lj_mailbox_friend = _window_manager->loadLayoutFromFile("l_home_lj_mailbox_friend.layout");
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
		//Set up layers l_home_lj_mailbox_friend
		this->mailbox_friend_talk.set_context(this->d_flake_context, this->d_surface);
		this->mailbox_friend_talk.set_layer(this->l_home_lj_mailbox_friend);
		this->mailbox_friend_talk.on_finish_launching();


		//{
		//	mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		//	this->d_mfa.set_model(&p_dog->data.data_relation.groupId_groupName_map);
		//}
		//this->d_mfa.set_data(this->d_flake_context, this->d_surface);
		//this->d_mfa.set_l_layer(this->l_home_lj_mailbox_friend_apply);
		//this->d_mfa.on_finish_launching();
		//{
		//	mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		//	this->d_bfi.set_model(&p_dog->data.data_user_basic.m_friend_apply);
		//}
		//this->d_bfi.set_layer(this->Listbox_nt);
		////////////////////////////////////////////////////////////////////////////////
		CEGUI::URect  ur = { {0, 0}, {0, 0}, {1, 0}, {1, 0} };
		this->DefaultWindow_right->addChild(this->l_home_lj_mailbox_search);
		this->l_home_lj_mailbox_search->setArea(ur);
		this->DefaultWindow_right->addChild(this->l_home_lj_mailbox_friend_apply);
		this->l_home_lj_mailbox_friend_apply->setArea(ur);
		this->DefaultWindow_right->addChild(this->l_home_lj_mailbox_friend);
		this->l_home_lj_mailbox_friend->setArea(ur);
		////////////////////////////////////////////////////////////////////////////////
		//this->l_home_lj_mailbox_search->setVisible(false);
		//this->l_home_lj_mailbox_friend_apply->setVisible(false);
		////////////////////////////////////////////////////////////////////////////////

		this->Button_search->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Button_search, this));
		////Tree handle
		//{
		//	CEGUI::Tree* theTree = (CEGUI::Tree*)this->Tree_friend;
		//	theTree->initialise();
		//	theTree->subscribeEvent(CEGUI::Tree::EventSelectionChanged, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Tree_friend_Select, this));
		//	theTree->subscribeEvent(CEGUI::Tree::EventBranchOpened, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Tree_friend_Open, this));
		//	theTree->subscribeEvent(CEGUI::Tree::EventBranchClosed, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Tree_friend_Close, this));

		//	//����Tree �������
		//	CEGUI::TreeItem *  newTreeCtrlEntryLvl1;
		//	CEGUI::TreeItem *  newTreeCtrlEntryLvl2;


		//	newTreeCtrlEntryLvl1 = new CEGUI::TreeItem("1c",1);
		//	newTreeCtrlEntryLvl1->setTextColours(CEGUI::Colour(0xff00ff00));
		//	newTreeCtrlEntryLvl1->setSelectionBrushImage("TaharezLook" "/TextSelectionBrush");
		//	theTree->addItem(newTreeCtrlEntryLvl1);
		//	newTreeCtrlEntryLvl2 = new CEGUI::TreeItem("2a (1a)",1);
		//	newTreeCtrlEntryLvl2->setSelectionBrushImage("TaharezLook" "/TextSelectionBrush");
		//	newTreeCtrlEntryLvl1->addItem(newTreeCtrlEntryLvl2);

		//	newTreeCtrlEntryLvl1 = new CEGUI::TreeItem("2c",2);
		//	newTreeCtrlEntryLvl1->setTextColours(CEGUI::Colour(0xff00ff00));
		//	newTreeCtrlEntryLvl1->setSelectionBrushImage("TaharezLook" "/TextSelectionBrush");
		//	theTree->addItem(newTreeCtrlEntryLvl1);
		//	newTreeCtrlEntryLvl1->setText("222222222");
		//	//theTree->removeItem(newTreeCtrlEntryLvl1);

		//}
		this->Button_game->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Button_game, this));
		this->Button_quit->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Button_quit, this));
		this->Listbox_nt->subscribeEvent(CEGUI::Listbox::EventSelectionChanged, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Listbox_nt_select, this));
		//
		this->Tree_friend->subscribeEvent(CEGUI::Tree::EventSelectionChanged, CEGUI::Event::Subscriber(&KO_dog_mailbox::on_handle_Tree_friend_Select, this));




		//
		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		//����KO_dog_data_relation �� event �¼�
		this->d_event_data_add_friend_nt_conn = p_dog->data.data_user_basic.m_friend_apply.d_event_set.subscribe_event(mm::elem_event_map<mm_uint64_t, data_basic_friend_info>::event_add, &KO_dog_mailbox::on_handle_event_data_add_friend_nt, this);
		this->d_event_data_rmv_friend_nt_conn = p_dog->data.data_user_basic.m_friend_apply.d_event_set.subscribe_event(mm::elem_event_map<mm_uint64_t, data_basic_friend_info>::event_rmv, &KO_dog_mailbox::on_handle_event_data_rmv_friend_nt, this);
		this->d_event_data_update_friend_nt_conn = p_dog->data.data_user_basic.m_friend_apply.d_event_set.subscribe_event(mm::data_basic_friend_info::event_update, &KO_dog_mailbox::on_handle_event_data_update_friend_nt, this);
		//this->d_event_data_update_description_friend_nt_conn = p_dog->data.data_user_basic.d_event_set.subscribe_event(KO_dog_data_user_basic::event_data_add_friend_nt, &KO_dog_mailbox::on_handle_event_data_add_friend_nt, this);
	
		//��1
		this->d_event_data_relation_add_friend_group_conn = p_dog->data.data_relation.groupId_groupName_map.d_event_set.subscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_add, &KO_dog_mailbox::on_handle_event_data_relation_add_friend_group, this);
		this->d_event_data_relation_rmv_friend_group_conn = p_dog->data.data_relation.groupId_groupName_map.d_event_set.subscribe_event(mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::event_rmv, &KO_dog_mailbox::on_handle_event_data_relation_rmv_friend_group, this);
		//����2
		this->d_event_data_relation_add_friend_conn = p_dog->data.data_relation.friendId_friendInfo_map.d_event_set.subscribe_event(mm::data_relation_friendId_friendInfo_map::event_add, &KO_dog_mailbox::on_handle_event_data_relation_add_friend, this);
		this->d_event_data_relation_rmv_friend_conn = p_dog->data.data_relation.friendId_friendInfo_map.d_event_set.subscribe_event(mm::data_relation_friendId_friendInfo_map::event_rmv, &KO_dog_mailbox::on_handle_event_data_relation_rmv_friend, this);


		//��ʼ�������߼�����
		this->map_apply_friend_wp.clear();

		//���������map
		this->m_single_view.add("l_home_lj_mailbox_search", this->l_home_lj_mailbox_search);
		this->m_single_view.add("l_home_lj_mailbox_friend_apply", this->l_home_lj_mailbox_friend_apply);
		this->m_single_view.add("l_home_lj_mailbox_friend", this->l_home_lj_mailbox_friend);
		this->m_single_view.blank();
	}

	void KO_dog_mailbox::clear_data_before_terminate()
	{
		//this->d_mfa.clear_item();
		//this->d_bfi.clear_item();

		//�������߼�����
		this->map_friendId_data.clear();
		this->map_apply_friend_wp.clear();
		this->map_apply_friend_event_handle.clear();
		this->map_groupId_data.clear();		
		//
		CEGUI::Tree* theTree = (CEGUI::Tree*)this->Tree_friend;
		theTree->resetList();

	}

	void KO_dog_mailbox::on_before_terminate()
	{
		this->clear_data_before_terminate();

		this->m_single_view.clear();

		//KO_dog_data_relation �� event �¼� ���
		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		//p_dog->data.data_relation.d_event_set.unsubscribe_event(KO_dog_data_user_basic::event_data_add_friend_nt, this->d_event_data_add_friend_nt_conn);

		////////////////////////////////////////////////////////////////////////////////
		this->DefaultWindow_right->removeChild(this->l_home_lj_mailbox_search);
		this->DefaultWindow_right->removeChild(this->l_home_lj_mailbox_friend_apply);
		this->DefaultWindow_right->removeChild(this->l_home_lj_mailbox_friend);
		////////////////////////////////////////////////////////////////////////////////
		this->mailbox_friend_talk.on_before_terminate();
		this->mailbox_friend_apply.on_before_terminate();
		//this->d_mfa.on_before_terminate();
		this->mailbox_search.on_before_terminate();
		////////////////////////////////////////////////////////////////////////////////
		CEGUI::WindowManager* _window_manager = CEGUI::WindowManager::getSingletonPtr();
		_window_manager->destroyWindow(this->l_home_lj_mailbox_search);
		_window_manager->destroyWindow(this->l_home_lj_mailbox_friend_apply);
		_window_manager->destroyWindow(this->l_home_lj_mailbox_friend);
		////////////////////////////////////////////////////////////////////////////////

		struct mm_logger* g_logger = mm_logger_instance();
		mm_logger_log_I(g_logger, "KO_dog_mailbox::%s %d success.", __FUNCTION__, __LINE__);
	}

	bool KO_dog_mailbox::on_handle_Button_search(const CEGUI::EventArgs& args)
	{
		this->m_single_view.view("l_home_lj_mailbox_search");
		return false;
	}

	bool KO_dog_mailbox::on_handle_Tree_friend_Select(const CEGUI::EventArgs& args)
	{
		CEGUI::Tree* theTree = (CEGUI::Tree*)this->Tree_friend;
		CEGUI::TreeItem* item = theTree->getFirstSelectedItem();
		if ( NULL != item)
		{
			this->m_single_view.view("l_home_lj_mailbox_friend");
			int itemId = item->getID();
			if (2 == itemId)
			{
				this->p_friend_friend = (mm::data_relation_friendInfo*)item->getUserData();
				this->mailbox_friend_talk.set_data_model(this->p_friend_friend);
			}
			if (1 == itemId)
			{
				this->p_friend_group = (mm::data_relation_groupInfo*)item->getUserData();
			}
		}
		else
		{
			this->m_single_view.blank();
		}

		return false;
	}
	bool KO_dog_mailbox::on_handle_Tree_friend_Open(const CEGUI::EventArgs& args)
	{
		this->m_single_view.blank();
		return false;
	}
	bool KO_dog_mailbox::on_handle_Tree_friend_Close(const CEGUI::EventArgs& args)
	{
		this->m_single_view.blank();
		return false;
	}
	bool KO_dog_mailbox::on_handle_Button_game(const CEGUI::EventArgs& args)
	{
		//this->l_home_lj_mailbox_search->setVisible(false);
		this->m_single_view.blank();
		mm_event_args evt_ags;
		this->d_event_set.fire_event(KO_dog_mailbox::event_game, evt_ags);
		return false;
	}
	bool KO_dog_mailbox::on_handle_Button_quit(const CEGUI::EventArgs& args)
	{
		this->clear_data_before_terminate();
		//this->l_home_lj_mailbox_search->setVisible(false);
		this->m_single_view.blank();
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

			this->p_apply_friend_info = (mm::data_basic_friend_info*)getFirst->getUserData();
			this->mailbox_friend_apply.set_friend_apply(p_apply_friend_info);
			this->mailbox_friend_apply.setVisible(true);
			this->mailbox_friend_apply.setVisible_opcode(true);

			//CEGUI::ListboxItem* getFirst = listb->getFirstSelectedItem();
			//mm_bfi_list_item* item = (mm_bfi_list_item*)getFirst;
			//this->p_apply_friend_info = (data_basic_friend_info*)item->d_m;
			//this->d_mfa.p_friend_apply = p_apply_friend_info;
			//this->d_mfa.setVisible(true);
			//this->d_mfa.setVisible_opcode(true);
		}
		else
		{
			this->mailbox_friend_apply.p_friend_apply = NULL;
			this->mailbox_friend_apply.setVisible(false);
			this->mailbox_friend_apply.setVisible_opcode(false);
			this->mailbox_friend_apply.setVisible_friend(false);

			//this->d_mfa.p_friend_apply = NULL;
			//this->d_mfa.setVisible(false);
			//this->d_mfa.setVisible_opcode(false);
			//this->d_mfa.setVisible_friend(false);

		}
		return false;
	}

	//bool KO_dog_mailbox::on_handle_event_data_friend_apply_update(const mm_event_args& args)
	//{
	//	mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
	//	mm::KO_dog_data_user_basic* p_data_user_basic = &p_dog->data.data_user_basic;
	//	CEGUI::Listbox* listb = (CEGUI::Listbox*)this->Listbox_nt;
	//	//����������
	//	int i = 0;
	//	//typedef ��һ��������
	//	typedef mm::KO_dog_data_user_basic::v_friend_apply user_apply_vec;
	//	user_apply_vec& vec = p_data_user_basic->friend_apply;

	//	//��������
	//	for (user_apply_vec::iterator it = vec.begin();
	//		it != vec.end(); it++, i++)
	//	{
	//		//��ȡ���������������Ԫ������
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
		//����������
		mm::elem_event_map<mm_uint64_t, data_relation_friendInfo*>::mm_event_map_ags& ags = (mm::elem_event_map<mm_uint64_t, data_relation_friendInfo*>::mm_event_map_ags&)args;
		mm::data_basic_friend_info* p_info = (mm::data_basic_friend_info*)ags.e;
		mm_uint64_t add_friend_id = ags.id;

		if (NULL != p_info)
		{
			CEGUI::ListboxTextItem* item = new CEGUI::ListboxTextItem(p_info->name, 0, p_info);
			item->setSelectionBrushImage("TaharezLook" "/TextSelectionBrush");
			listb->addItem(item);

			mm_event_handler handle = p_info->d_event_set.subscribe_event(mm::data_basic_friend_info::event_update, &KO_dog_mailbox::on_handle_event_data_update_friend_nt, this);
			this->map_apply_friend_wp.add(add_friend_id, item);
			this->map_apply_friend_event_handle.add(add_friend_id, handle);
		}
		else
		{
			CEGUI::ListboxTextItem* item = this->map_apply_friend_wp.get(p_info->id);
			if (NULL != item)
			{
				item->setText(p_info->name);
				item->setUserData(p_info);
			}
		}

		return false;
	}
	bool KO_dog_mailbox::on_handle_event_data_rmv_friend_nt(const mm_event_args& args)
	{
		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		mm::KO_dog_data_user_basic* p_data_user_basic = &p_dog->data.data_user_basic;
		CEGUI::Listbox* listb = (CEGUI::Listbox*)this->Listbox_nt;
		//����������
		mm::elem_event_map<mm_uint64_t, data_relation_friendInfo*>::mm_event_map_ags& ags = (mm::elem_event_map<mm_uint64_t, data_relation_friendInfo*>::mm_event_map_ags&)args;
		mm::data_basic_friend_info* p_info = (mm::data_basic_friend_info*)ags.e;
		mm_uint64_t friend_id = ags.id;
		
		if (0 != friend_id)
		{
			CEGUI::ListboxTextItem* item = this->map_apply_friend_wp.get(friend_id);
			if (NULL != item)
			{
				mm_event_handler handle = this->map_apply_friend_event_handle.get(friend_id);
				p_info->d_event_set.unsubscribe_event(mm::data_basic_friend_info::event_update, handle);
				listb->removeItem(item);
				this->map_apply_friend_wp.rmv(friend_id);
				this->map_apply_friend_event_handle.rmv(friend_id);
				this->mailbox_friend_apply.setVisible(false);
			}
		}

		return false;
	}

	
	bool KO_dog_mailbox::on_handle_event_data_update_friend_nt(const mm_event_args& args)
	{
		mm::KO_dog* p_dog = (mm::KO_dog*)(this->d_flake_context->get_flake_activity());
		mm::KO_dog_data_user_basic* p_data_user_basic = &p_dog->data.data_user_basic;
		CEGUI::Listbox* listb = (CEGUI::Listbox*)this->Listbox_nt;
		//����������
		mm::mm_event_obj_ags& ags = (mm::mm_event_obj_ags&)args;
		mm::data_basic_friend_info* p_info = (mm::data_basic_friend_info*)ags.e;
		if (NULL != p_info)
		{
			CEGUI::ListboxTextItem* item = this->map_apply_friend_wp.get(p_info->id);
			if (NULL != item)
			{
				item->setText(p_info->name);
			}
		}
		return false;
	}

	bool KO_dog_mailbox::on_handle_event_data_relation_add_friend_group(const mm_event_args& args)
	{
		bool flag = false;
		mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags& evt_ags = (mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags&)args;
		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
		assert(NULL != p_groupInfo && "mm::data_relation_groupInfo mm_event_args Return null value.");
		mm_uint64_t group_id = evt_ags.id;
		mm::KO_dog_mailbox::data_group* p_data = this->map_groupId_data.get(group_id);
		if (NULL == p_data)
		{
			//����һ���µĺ�����
			p_data = this->map_groupId_data.add(group_id);
			//theTree ����һ������
			CEGUI::Tree* theTree = (CEGUI::Tree*)this->Tree_friend;
			//CEGUI::Combobox* cbbo = (CEGUI::Combobox*)this->Combobox;
			p_data->p_TextItem = new CEGUI::TreeItem(p_groupInfo->group_name, 1, p_groupInfo , false, true);
			p_data->p_TextItem->setSelectionBrushImage("TaharezLook" "/TextSelectionBrush");
			theTree->addItem(p_data->p_TextItem);
			//
			p_data->d_event_group_update = p_groupInfo->d_event_set.subscribe_event(mm::data_relation_groupInfo::event_update, &KO_dog_mailbox::on_handle_event_data_friend_group_update, this);
			p_data->d_event_group_update_name = p_groupInfo->d_event_set.subscribe_event(mm::data_relation_groupInfo::event_update_name, &KO_dog_mailbox::on_handle_event_data_friend_group_update_name, this);
			flag = true;
		}
		else
		{
			//�޸���������
			if (NULL != p_data->p_TextItem)
			{
				p_data->p_TextItem->setText(p_groupInfo->group_name);
				p_data->p_TextItem->setUserData(p_groupInfo);
			}
			flag = true;
		}
		return flag;
	}
	bool KO_dog_mailbox::on_handle_event_data_relation_rmv_friend_group(const mm_event_args& args)
	{
		bool flag = false;
		mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags& evt_ags = (mm::elem_event_map<mm_uint64_t, data_relation_groupInfo>::mm_event_map_ags&)args;
		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
		assert(NULL != p_groupInfo && "mm::data_relation_groupInfo mm_event_args Return null value.");
		mm_uint64_t group_id = evt_ags.id;
		mm::KO_dog_mailbox::data_group* p_data = this->map_groupId_data.get(group_id);
		if (NULL != p_data)
		{
			//Combobox �Ƚ��������¼�İ󶨣���ɾ��
			p_groupInfo->d_event_set.unsubscribe_event(mm::data_relation_groupInfo::event_update, p_data->d_event_group_update);
			p_groupInfo->d_event_set.unsubscribe_event(mm::data_relation_groupInfo::event_update_name, p_data->d_event_group_update_name);
			//
			CEGUI::Tree* theTree = (CEGUI::Tree*)this->Tree_friend;
			theTree->removeItem(p_data->p_TextItem);
			//
			this->map_groupId_data.rmv(group_id);
			flag = true;
		}
		return flag;
	}
	bool KO_dog_mailbox::on_handle_event_data_friend_group_update(const mm_event_args& args)
	{
		mm::mm_event_obj_ags& evt_ags = (mm::mm_event_obj_ags&)args;
		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
		mm::KO_dog_mailbox::data_group* p_data = this->map_groupId_data.get(p_groupInfo->group_id);
		if (NULL != p_data)
		{
			p_data->p_TextItem->setText(p_groupInfo->group_name);
		}
		return false;
	}
	bool KO_dog_mailbox::on_handle_event_data_friend_group_update_name(const mm_event_args& args)
	{
		mm::mm_event_obj_ags& evt_ags = (mm::mm_event_obj_ags&)args;
		mm::data_relation_groupInfo* p_groupInfo = (mm::data_relation_groupInfo*)evt_ags.e;
		mm::KO_dog_mailbox::data_group* p_data = this->map_groupId_data.get(p_groupInfo->group_id);
		if (NULL != p_data)
		{
			p_data->p_TextItem->setText(p_groupInfo->group_name);
		}
		return false;
	}

	bool KO_dog_mailbox::on_handle_event_data_relation_add_friend(const mm_event_args& args)
	{
		bool flag = false;
		mm::elem_event_map<mm_uint64_t, data_relation_friendInfo*>::mm_event_map_ags& evt_ags = (mm::elem_event_map<mm_uint64_t, data_relation_friendInfo*>::mm_event_map_ags&)args;
		mm::data_relation_friendInfo* p_friendInfo = (mm::data_relation_friendInfo*)evt_ags.e;
		assert(NULL != p_friendInfo && "mm::data_relation_friendInfo mm_event_args Return null value.");
		mm_uint64_t friend_id = evt_ags.id;
		mm::KO_dog_mailbox::data_friend* p_data_friend = this->map_friendId_data.get(friend_id);
		if (NULL == p_data_friend)
		{
			//����һ���µĺ�����
			p_data_friend = this->map_friendId_data.add(friend_id);
			//theTree ����һ�����ݣ�������¼�ǲ��뵽��Ӧ �����棬������ҵ���Ӧ��data_group�� ������ص� handle��
			mm_uint64_t group_id = p_friendInfo->friend_group_id;
			mm::KO_dog_mailbox::data_group* p_data_group = this->map_groupId_data.get(group_id);
			//���Ѽ�¼���ص���Ӧ�����¼����
			p_data_friend->p_TextItem = new CEGUI::TreeItem(p_friendInfo->friend_remark, 2, p_friendInfo , false , true);
			p_data_friend->p_TextItem->setSelectionBrushImage("TaharezLook" "/TextSelectionBrush");
			p_data_group->p_TextItem->addItem(p_data_friend->p_TextItem);
			//���Ѽ�¼���Լ����¼�
			p_data_friend->group_id = group_id;
			p_data_friend->d_event_friend_update = p_friendInfo->d_event_set.subscribe_event(mm::data_relation_friendInfo::event_update, &KO_dog_mailbox::on_handle_event_data_friend_update, this);
			p_data_friend->d_event_friend_update_remark = p_friendInfo->d_event_set.subscribe_event(mm::data_relation_friendInfo::event_update_remark, &KO_dog_mailbox::on_handle_event_data_friend_update_remark, this);
			p_data_friend->d_event_friend_update_group = p_friendInfo->d_event_set.subscribe_event(mm::data_relation_friendInfo::event_update_group, &KO_dog_mailbox::on_handle_event_data_friend_update_group, this);
			flag = true;
		}
		else
		{
			////�޸���������
			//if (NULL != p_data_friend->p_TextItem)
			//{
			//	//����text
			//	p_data_friend->p_TextItem->setText(p_friendInfo->friend_remark);

			//	//��ǰ����������id �ͺ���id
			//	mm_uint64_t group_id_now = p_friendInfo->friend_group_id;
			//	mm_uint64_t friend_id_now = evt_ags.id;
			//	//���ô������ĺ���id��ѯ֮ǰ��¼���еľɵĹ�����Ϣ �� ����id
			//	mm::KO_dog_mailbox::data_friend* p_data_friend_old = this->map_friendId_data.get(friend_id_now);
			//	mm_uint64_t group_id_old = p_data_friend->group_id;
			//	//�������ȣ���Ҫ���м�¼���飬ԭ��������ļ�¼�õ��µ�������
			//	if (group_id_old != group_id_now)
			//	{
			//		mm::KO_dog_mailbox::data_group* p_data_group_old = this->map_groupId_data.get(group_id_old);
			//		mm::KO_dog_mailbox::data_group* p_data_group_now = this->map_groupId_data.get(group_id_old);
			//		if (NULL != p_data_group_now)
			//		{
			//			//�����Ƴ����������
			//			p_data_group_old->p_TextItem->removeItem(p_data_friend_old->p_TextItem);
			//			p_data_group_now->p_TextItem->addItem(p_data_friend_old->p_TextItem);
			//		}
			//		else
			//		{
			//			assert(0==1 && "KO_dog_mailbox::on_handle_event_data_relation_add_friend group_now_id Not mounted yet.");
			//		}					
			//	}				
			//}
			assert(0 == 1 && "KO_dog_mailbox::on_handle_event_data_relation_add_friend,,, Abnormal");
			flag = true;
		}
		return flag;
	}
	bool KO_dog_mailbox::on_handle_event_data_relation_rmv_friend(const mm_event_args& args)
	{
		bool flag = false;
		mm::elem_event_map<mm_uint64_t, data_relation_friendInfo>::mm_event_map_ags& evt_ags = (mm::elem_event_map<mm_uint64_t, data_relation_friendInfo>::mm_event_map_ags&)args;
		mm::data_relation_friendInfo* p_friendInfo = (mm::data_relation_friendInfo*)evt_ags.e;
		assert(NULL != p_friendInfo && "mm::data_relation_friendInfo mm_event_args Return null value.");
		mm_uint64_t friend_id = evt_ags.id;
		mm::KO_dog_mailbox::data_friend* p_data_friend = this->map_friendId_data.get(friend_id);
		if (NULL != p_data_friend)
		{
			//TheTree �Ƚ��������¼�İ󶨣���ɾ��
			p_friendInfo->d_event_set.unsubscribe_event(mm::data_relation_friendInfo::event_update, p_data_friend->d_event_friend_update);
			p_friendInfo->d_event_set.unsubscribe_event(mm::data_relation_friendInfo::event_update_remark, p_data_friend->d_event_friend_update_remark);
			p_friendInfo->d_event_set.unsubscribe_event(mm::data_relation_friendInfo::event_update_group, p_data_friend->d_event_friend_update_group);
			//�ҵ��Լ�id��Ӧ���item ,����Լ���item
			mm_uint64_t group_id = p_data_friend->group_id;
			mm_uint64_t friend_id = evt_ags.id;
			mm::KO_dog_mailbox::data_group* p_data_group = this->map_groupId_data.get(group_id);
			mm::KO_dog_mailbox::data_friend* p_data_friend = this->map_friendId_data.get(friend_id);
			p_data_group->p_TextItem->removeItem(p_data_friend->p_TextItem);
			//
			this->map_friendId_data.rmv(friend_id);
			flag = true;
		}
		return flag;
	}
	bool KO_dog_mailbox::on_handle_event_data_friend_update(const mm_event_args& args)
	{
		//mm::mm_event_obj_ags& evt_ags = (mm::mm_event_obj_ags&)args;
		//mm::data_relation_friendInfo* p_friendInfo = (mm::data_relation_friendInfo*)evt_ags.e;
		//mm::KO_dog_mailbox::data_friend* p_data = this->map_friendId_data.get(p_friendInfo->friend_id);
		//if (NULL != p_data)
		//{
		//	p_data->p_TextItem->setText(p_groupInfo->group_name);
		//}
		return false;
	}
	bool KO_dog_mailbox::on_handle_event_data_friend_update_remark(const mm_event_args& args)
	{
		mm::mm_event_obj_ags& evt_ags = (mm::mm_event_obj_ags&)args;
		mm::data_relation_friendInfo* p_friendInfo = (mm::data_relation_friendInfo*)evt_ags.e;
		mm::KO_dog_mailbox::data_friend* p_data = this->map_friendId_data.get(p_friendInfo->friend_id);
		if (NULL != p_data)
		{
			p_data->p_TextItem->setText(p_friendInfo->friend_remark);
			this->Tree_friend->invalidate();
		}
		return false;
	}

	bool KO_dog_mailbox::on_handle_event_data_friend_update_group(const mm_event_args& args)
	{
		mm::mm_event_obj_ags& evt_ags = (mm::mm_event_obj_ags&)args;
		mm::data_relation_friendInfo* p_friendInfo = (mm::data_relation_friendInfo*)evt_ags.e;
		mm::KO_dog_mailbox::data_friend* p_data_friend_old = this->map_friendId_data.get(p_friendInfo->friend_id);
		mm_uint64_t group_id_old = p_data_friend_old->group_id;
		//��ǰ����������id �ͺ���id
		mm_uint64_t group_id_now = p_friendInfo->friend_group_id;
		mm_uint64_t friend_id_now = p_friendInfo->friend_id;
		//�������ȣ���Ҫ���м�¼���飬��������ļ�¼�õ��µ�������
		if (group_id_old != group_id_now)
		{
			assert(NULL != p_data_friend_old && "KO_dog_mailbox::on_handle_event_data_friend_update_group,,, Null pointer");

			mm::KO_dog_mailbox::data_group* p_data_group_old = this->map_groupId_data.get(group_id_old);
			mm::KO_dog_mailbox::data_group* p_data_group_now = this->map_groupId_data.get(group_id_now);

			assert(NULL != p_data_group_old && NULL != p_data_group_now && "KO_dog_mailbox::on_handle_event_data_friend_update_group,,, Null pointer");
			//�����Ƴ����������
			p_data_group_old->p_TextItem->removeItem(p_data_friend_old->p_TextItem);
			p_data_group_now->p_TextItem->addItem(p_data_friend_old->p_TextItem);
			this->Tree_friend->invalidate();
			//����������ѵ����ݣ��ı��飺 group_id_old -> group_id_now ��
			p_data_friend_old->group_id = group_id_now;
			this->mailbox_friend_talk.set_data_model(p_friendInfo);
		}
		return false;
	}



}