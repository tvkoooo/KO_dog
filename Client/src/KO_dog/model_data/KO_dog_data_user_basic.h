#ifndef __KO_dog_data_user_basic_h__
#define __KO_dog_data_user_basic_h__

#include <string>
#include "core/mm_core.h"
#include "dish/mm_event.h"

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



	class KO_dog_data_user_basic
	{

	public:
		struct data_user_basic basic;
		struct data_user_token token;

	public:
		static const std::string event_userdata_user_basic_update;
		static const std::string event_userdata_user_token_update;
		// this member is event drive.
		mm::mm_event_set d_event_set;

	public:
		KO_dog_data_user_basic();
		~KO_dog_data_user_basic();

	};
}






#endif//__KO_dog_data_user_basic_h__