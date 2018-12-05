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
		p->token = "";
		p->state = data_user_token::user_token_closed;
	}
	void data_user_token_destroy(struct data_user_token* p)
	{
		p->token = "";
		p->state = data_user_token::user_token_closed;
	}

	//class KO_dog_data_user_basic ///////////////////////////////////////////////////////////////////////////////////
	const std::string KO_dog_data_user_basic::event_userdata_update("event_userdata_update");
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