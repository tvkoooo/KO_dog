//
//	Generated by lua
//	copyright longer 2018
//  mm_m_db_ko_dog_t_user_basic.cpp

#include "mm_m_db_ko_dog_t_user_basic.h"

namespace mm
{
	//
	//	struct implementation for t_user_basic	//
	t_user_basic::~t_user_basic()
	{

	}
	t_user_basic::t_user_basic()
		:id(0)
		,name("")
		,nick("")
		,create_time(0)
	{

	}
	void t_user_basic::encode(mm_o_archive& archive) const
	{
		archive << id;
		archive << name;
		archive << nick;
		archive << create_time;
	}
	void t_user_basic::decode(const mm_i_archive& archive)
	{
		archive >> id;
		archive >> name;
		archive >> nick;
		archive >> create_time;
	}
}