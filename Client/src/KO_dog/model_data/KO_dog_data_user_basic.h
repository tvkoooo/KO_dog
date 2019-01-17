#ifndef __KO_dog_data_user_basic_h__
#define __KO_dog_data_user_basic_h__

#include <string>
#include <vector>
#include "core/mm_core.h"
#include "dish/mm_event.h"
#include "toolkit/mm_elem_map.h"

namespace mm
{
	struct data_user_basic
	{
		enum data_user_basic_state
		{
			user_basic_closed = 0,// user is closed,Not logged in.
			user_basic_motion = 1,// user is landing,Not logged in.
			user_basic_finish = 2,// user already logged.
		};
		std::string name;// 用户名.
		mm_uint64_t id;// 用户id.
		int state;
	};
	void data_user_basic_init(struct data_user_basic* p);
	void data_user_basic_destroy(struct data_user_basic* p);

	struct data_user_token
	{
		enum data_user_token_state
		{
			user_token_closed = 0,// user token is closed
			user_token_motion = 1,// user token is implementing
			user_token_finish = 2,// user token has already completed.
		};
		//std::string token;// token.
		int state;
	};

	void data_user_token_init(struct data_user_token* p);
	void data_user_token_destroy(struct data_user_token* p);


	//struct data_search_friend_basic
	//{
	//	mm_uint64_t id;// 用户id.
	//	std::string name;// 用户名.
	//	std::string nick;// 用户昵称.
	//	mm_uint32_t create_time;//创建时间
	//};
	//void data_search_friend_basic_init(struct data_search_friend_basic* p);
	//void data_search_friend_basic_destroy(struct data_search_friend_basic* p);
	//void data_search_friend_basic_clear(struct data_search_friend_basic* p);

	//class data_apply_friend_basic
	//{
	//public:
	//	struct data_search_friend_basic friend_basic;
	//	std::string apply_description;
	//public:
	//	data_apply_friend_basic();
	//	~data_apply_friend_basic();
	//	void clear();
	//};


	class data_basic_friend_info
	{
	public:
		mm_uint64_t id;// 用户id.
		std::string name;// 用户名.
		std::string nick;// 用户昵称.
		mm_uint32_t create_time;//创建时间
		std::string apply_description;//申请理由，（备注这个默认是 "" ,如果在好友申请时，会携带申请理由）
	public:
		static const std::string event_update;
		static const std::string event_update_description;
	public:
		// this member is event drive.
		mm::mm_event_set d_event_set;

	public:
		data_basic_friend_info();
		void update(mm_uint64_t id, const std::string& name, const std::string& nick, mm_uint32_t create_time, const std::string& apply_description);
		void update_description(const std::string& apply_description);
	};



	class KO_dog_data_user_basic
	{
	//public:
	//	class mm_event_args_data :public mm_event_args
	//	{
	//	public:
	//		data_apply_friend_basic apply_friend;
	//	};


	//public:
	//	typedef std::vector<struct data_search_friend_basic> v_friend_basic;
	//	typedef std::vector<data_apply_friend_basic> v_friend_apply;

	public:
		struct data_user_basic basic;
		struct data_user_token token;

		mm::elem_event_map<mm_uint64_t, data_basic_friend_info> m_friend_search;
		mm::elem_event_map<mm_uint64_t, data_basic_friend_info> m_friend_apply;

		//v_friend_basic friend_search;
		//v_friend_apply friend_apply;

	public:
		static const std::string event_userdata_user_basic_update;
		static const std::string event_userdata_user_token_update;
		static const std::string event_data_search_friend_basic_update;
		static const std::string event_data_friend_apply_update;
		//static const std::string event_data_add_friend_nt;
		//static const std::string event_data_rmv_friend_nt;
		// this member is event drive.
		mm::mm_event_set d_event_set;

	public:
		KO_dog_data_user_basic();
		~KO_dog_data_user_basic();

	};







	//class elem_0
	//{
	//public:
	//	int id;
	//	std::string name;
	//	std::string nick;
	//public:
	//	static const std::string event_update;
	//public:
	//	// this member is event drive.
	//	mm::mm_event_set d_event_set;
	//public:
	//	elem_0();
	//	void updat(const std::string& name, const std::string& nick)
	//	{
	//		this->name = name;
	//		this->nick = nick;
	//		mm_event_obj_ags ags;
	//		ags.e = this;
	//		this->d_event_set.fire_event(event_update, ags);
	//	}
	//};

}






#endif//__KO_dog_data_user_basic_h__