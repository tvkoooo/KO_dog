#include "KO_dog_data_user_basic.h"


namespace mm
{
	//struct data_user_basic ///////////////////////////////////////////////////////////////////////////////////
	void data_user_basic_init(struct data_user_basic* p)
	{
		p->name = "";
		p->id = 0;
		p->state = data_user_basic::user_basic_closed;
	}
	void data_user_basic_destroy(struct data_user_basic* p)
	{
		p->name = "";
		p->id = 0;
		p->state = data_user_basic::user_basic_closed;
	}
	//struct data_user_token ///////////////////////////////////////////////////////////////////////////////////
	void data_user_token_init(struct data_user_token* p)
	{
		p->state = data_user_token::user_token_closed;
	}
	void data_user_token_destroy(struct data_user_token* p)
	{
		p->state = data_user_token::user_token_closed;
	}

	////struct data_search_friend_basic ///////////////////////////////////////////////////////////////////////////////////
	//void data_search_friend_basic_init(struct data_search_friend_basic* p)
	//{
	//	p->id = 0;
	//	p->name = "";
	//	p->nick = "";
	//	p->create_time = 0;
	//}
	//void data_search_friend_basic_destroy(struct data_search_friend_basic* p)
	//{
	//	p->id = 0;
	//	p->name = "";
	//	p->nick = "";
	//	p->create_time = 0;
	//}
	//void data_search_friend_basic_clear(struct data_search_friend_basic* p)
	//{
	//	p->id = 0;
	//	p->name = "";
	//	p->nick = "";
	//	p->create_time = 0;
	//}
	////class data_apply_friend_basic ///////////////////////////////////////////////////////////////////////////////////
	//data_apply_friend_basic::data_apply_friend_basic()
	//	: apply_description("")
	//{
	//	data_search_friend_basic_init(&this->friend_basic);
	//}
	//data_apply_friend_basic::~data_apply_friend_basic()
	//{
	//	data_search_friend_basic_destroy(&this->friend_basic);
	//}
	//void data_apply_friend_basic::clear()
	//{
	//	data_search_friend_basic_clear(&this->friend_basic);
	//	this->apply_description = "";
	//}

	//class data_basic_friend_info ///////////////////////////////////////////////////////////////////////////////////
	const std::string data_basic_friend_info::event_update("event_update");
	const std::string data_basic_friend_info::event_update_description("event_update_description");

	data_basic_friend_info::data_basic_friend_info()
		: id(0)
		, name("")
		, nick("")
		, create_time(0)
		, apply_description("")
	{

	}
	void data_basic_friend_info::update(mm_uint64_t id, const std::string& name, const std::string& nick, mm_uint32_t create_time, const std::string& apply_description)
	{
		this->id = id;
		this->name = name;
		this->nick = nick;
		this->create_time = create_time;
		this->apply_description = apply_description;
		//
		mm_event_obj_ags ags;
		ags.e = this;
		this->d_event_set.fire_event(event_update, ags);

	}
	void data_basic_friend_info::update_description(const std::string& apply_description)
	{
		this->apply_description = apply_description;
		//
		mm_event_obj_ags ags;
		ags.e = this;
		this->d_event_set.fire_event(event_update_description, ags);
	}




	//class KO_dog_data_user_basic ///////////////////////////////////////////////////////////////////////////////////
	const std::string KO_dog_data_user_basic::event_userdata_user_basic_update("event_userdata_user_basic_update");
	const std::string KO_dog_data_user_basic::event_userdata_user_token_update("event_userdata_user_token_update");
	const std::string KO_dog_data_user_basic::event_data_search_friend_basic_update("event_data_search_friend_basic_update");
	const std::string KO_dog_data_user_basic::event_data_friend_apply_update("event_data_friend_apply_update");
	const std::string KO_dog_data_user_basic::event_data_add_friend_nt("event_data_add_friend_nt");
	const std::string KO_dog_data_user_basic::event_data_respond_friend_nt("event_data_respond_friend_nt");

	KO_dog_data_user_basic::KO_dog_data_user_basic()
		: d_event_set()
	{
		data_user_basic_init(&this->basic);
		data_user_token_init(&this->token);
	}

	KO_dog_data_user_basic::~KO_dog_data_user_basic()
	{
		data_user_basic_destroy(&this->basic);
		data_user_token_destroy(&this->token);
	}




}