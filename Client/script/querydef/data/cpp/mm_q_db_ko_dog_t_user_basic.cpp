//
//	Generated by lua
//	copyright longer 2018
//  mm_q_db_ko_dog_t_user_basic.cpp

#include "mm_q_db_ko_dog_t_user_basic.h"

namespace mm
{
	//
	//	struct definition for p_userinfo_add	//
	p_userinfo_add::~p_userinfo_add()
	{

	}
	p_userinfo_add::p_userinfo_add()
		:code(0)
		,name("")
		,password("")
		,nick("")
		,id(0)
	{

	}
	void p_userinfo_add::encode(mm_o_archive& archive) const
	{
		archive << code;
		archive << name;
		archive << password;
		archive << nick;
		archive << id;
	}
	void p_userinfo_add::decode(const mm_i_archive& archive)
	{
		archive >> code;
		archive >> name;
		archive >> password;
		archive >> nick;
		archive >> id;
	}
	int p_userinfo_add::query(struct mm_db_mysql* _sql, mm_uint32_t logger_level)
	{
		int error_code = db_mysql_state_unknown;
		struct mm_logger* g_logger = mm_logger_instance();
		assert(NULL != _sql && "p_userinfo_add input struct mm_db_mysql is a null.");
		mm_db_mysql_query db(_sql);
		mm_db_mysql_stream oss( mm_db_mysql_get_context( _sql ) );
		mm_db_mysql_lock(_sql);
		oss
			<< "call db_ko_dog.p_userinfo_add("
			<< " " << "@code"
			<< ",'" << name << "'"
			<< ",'" << password << "'"
			<< ",'" << nick << "'" << " );"
			<< "select "
			<< " " << "@code" << "  ;";
		const std::string& sql_str = oss.get_string();
		mm_logger_message(g_logger,logger_level,"dump sql:%s",sql_str.c_str());
		if ( 0 == mm_db_mysql_real_query( _sql, sql_str.c_str() ) )
		{
			// result 1.
			mm_db_mysql_store_next_result(_sql);
			{
				assert( 1 == mm_db_mysql_get_field_count(_sql) && "field count is not match.");
				if ( 0 != mm_db_mysql_get_has_row(_sql) )
				{
					db.get_field( 0, id );
				}
			}
			mm_db_mysql_free_current_result(_sql);
			// result 2.
			mm_db_mysql_store_next_result(_sql);
			{
				assert( 1 == mm_db_mysql_get_field_count(_sql) && "field count is not match.");
				if ( 0 != mm_db_mysql_get_has_row(_sql) )
				{
					db.get_field( 0, code );
				}
			}
			mm_db_mysql_free_current_result(_sql);
			// free unused result.
			mm_db_mysql_free_unused_result(_sql);
			//
			error_code = db_mysql_state_success;
		}
		else
		{
			error_code = db_mysql_state_failure;
		}
		mm_db_mysql_unlock(_sql);
		return error_code;
	}
	//
	//	struct definition for p_userinfo_check	//
	p_userinfo_check::~p_userinfo_check()
	{

	}
	p_userinfo_check::p_userinfo_check()
		:code(0)
		,name("")
		,password("")
		,id(0)
	{

	}
	void p_userinfo_check::encode(mm_o_archive& archive) const
	{
		archive << code;
		archive << name;
		archive << password;
		archive << id;
	}
	void p_userinfo_check::decode(const mm_i_archive& archive)
	{
		archive >> code;
		archive >> name;
		archive >> password;
		archive >> id;
	}
	int p_userinfo_check::query(struct mm_db_mysql* _sql, mm_uint32_t logger_level)
	{
		int error_code = db_mysql_state_unknown;
		struct mm_logger* g_logger = mm_logger_instance();
		assert(NULL != _sql && "p_userinfo_check input struct mm_db_mysql is a null.");
		mm_db_mysql_query db(_sql);
		mm_db_mysql_stream oss( mm_db_mysql_get_context( _sql ) );
		mm_db_mysql_lock(_sql);
		oss
			<< "call db_ko_dog.p_userinfo_check("
			<< " " << "@code"
			<< ",'" << name << "'"
			<< ",'" << password << "'" << " );"
			<< "select "
			<< " " << "@code" << "  ;";
		const std::string& sql_str = oss.get_string();
		mm_logger_message(g_logger,logger_level,"dump sql:%s",sql_str.c_str());
		if ( 0 == mm_db_mysql_real_query( _sql, sql_str.c_str() ) )
		{
			// result 1.
			mm_db_mysql_store_next_result(_sql);
			{
				assert( 1 == mm_db_mysql_get_field_count(_sql) && "field count is not match.");
				if ( 0 != mm_db_mysql_get_has_row(_sql) )
				{
					db.get_field( 0, id );
				}
			}
			mm_db_mysql_free_current_result(_sql);
			// result 2.
			mm_db_mysql_store_next_result(_sql);
			{
				assert( 1 == mm_db_mysql_get_field_count(_sql) && "field count is not match.");
				if ( 0 != mm_db_mysql_get_has_row(_sql) )
				{
					db.get_field( 0, code );
				}
			}
			mm_db_mysql_free_current_result(_sql);
			// free unused result.
			mm_db_mysql_free_unused_result(_sql);
			//
			error_code = db_mysql_state_success;
		}
		else
		{
			error_code = db_mysql_state_failure;
		}
		mm_db_mysql_unlock(_sql);
		return error_code;
	}
}