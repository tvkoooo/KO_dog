//
//	Generated by lua
//	copyright longer 2018
//  mm_m_db_ko_dog_t_user_basic.h

#ifndef __mm_m_db_ko_dog_t_user_basic_h__
#define __mm_m_db_ko_dog_t_user_basic_h__

#include "dish/mm_package.h"
#include <string>

namespace mm
{
	//
	//	struct definition for t_user_basic	//
	struct t_user_basic : public mm_package
	{
	public:
		mm_uint64_t id;// 用户id.
		std::string name;// 用户名.
		std::string password;// 用户密码.
		std::string nick;// 昵称.
		mm_uint32_t create_time;// 创建时间.
	public:
		virtual ~t_user_basic();
	public:
		t_user_basic();
		virtual void encode(mm_o_archive& archive) const;
		virtual void decode(const mm_i_archive& archive);
	};
}
#endif//__dish_m_db_ko_dog_t_user_basic_h__