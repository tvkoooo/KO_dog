//
//	Generated by lua
//	copyright longer 2019
//  mm_q_db_ko_dog_t_user_relation.cpp

#include "mm_q_db_ko_dog_t_user_relation.h"

namespace mm
{
	//
	//	struct definition for p_user_relation_add_friend	//
	p_user_relation_add_friend::~p_user_relation_add_friend()
	{

	}
	p_user_relation_add_friend::p_user_relation_add_friend()
		:code(0)
		,myself_id(0)
		,friend_id(0)
		,friend_remark("")
	{

	}
	void p_user_relation_add_friend::encode(mm_o_archive& archive) const
	{
		archive << code;
		archive << myself_id;
		archive << friend_id;
		archive << friend_remark;
		archive << user_relation_s;
	}
	void p_user_relation_add_friend::decode(const mm_i_archive& archive)
	{
		archive >> code;
		archive >> myself_id;
		archive >> friend_id;
		archive >> friend_remark;
		archive >> user_relation_s;
	}
	int p_user_relation_add_friend::query(struct mm_db_mysql* _sql, mm_uint32_t logger_level)
	{
		int error_code = db_mysql_state_unknown;
		struct mm_logger* g_logger = mm_logger_instance();
		assert(NULL != _sql && "p_user_relation_add_friend input struct mm_db_mysql is a null.");
		mm_db_mysql_query db(_sql);
		mm_db_mysql_stream oss( mm_db_mysql_get_context( _sql ) );
		mm_db_mysql_lock(_sql);
		oss
			<< "call db_ko_dog.p_user_relation_add_friend("
			<< " " << "@code"
			<< ",'" << myself_id << "'"
			<< ",'" << friend_id << "'"
			<< ",'" << friend_remark << "'" << " );"
			<< "select "
			<< " " << "@code" << "  ;";
		const std::string& sql_str = oss.get_string();
		mm_logger_message(g_logger,logger_level,"dump sql:%s",sql_str.c_str());
		if ( 0 == mm_db_mysql_real_query( _sql, sql_str.c_str() ) )
		{
			// result 1.
			mm_db_mysql_store_next_result(_sql);
			{
				assert( 5 == mm_db_mysql_get_field_count(_sql) && "field count is not match.");
				typedef user_relation_vec::iterator iterator; 
				mm_uint64_t _affected_rows = mm_db_mysql_get_affected_rows(_sql);
				// std list vector resize(size_t n, value_type()), value_type can not contain shared pointer.
				// here we can safe resize.
				user_relation_s.resize((size_t)_affected_rows);
				for (iterator it = user_relation_s.begin();
					it!=user_relation_s.end();++it)
				{
					if ( 0 != mm_db_mysql_get_has_row(_sql) )
					{
						t_user_relation& v = *it;
						db.get_field( 0, v.user_id );
						db.get_field( 1, v.friend_group_id );
						db.get_field( 2, v.friend_id );
						db.get_field( 3, v.friend_remark );
						db.get_field( 4, v.build_friend_time );
					}
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
	//	struct definition for p_user_relation_delete_friend	//
	p_user_relation_delete_friend::~p_user_relation_delete_friend()
	{

	}
	p_user_relation_delete_friend::p_user_relation_delete_friend()
		:code(0)
		,myself_id(0)
		,friend_id(0)
	{

	}
	void p_user_relation_delete_friend::encode(mm_o_archive& archive) const
	{
		archive << code;
		archive << myself_id;
		archive << friend_id;
	}
	void p_user_relation_delete_friend::decode(const mm_i_archive& archive)
	{
		archive >> code;
		archive >> myself_id;
		archive >> friend_id;
	}
	int p_user_relation_delete_friend::query(struct mm_db_mysql* _sql, mm_uint32_t logger_level)
	{
		int error_code = db_mysql_state_unknown;
		struct mm_logger* g_logger = mm_logger_instance();
		assert(NULL != _sql && "p_user_relation_delete_friend input struct mm_db_mysql is a null.");
		mm_db_mysql_query db(_sql);
		mm_db_mysql_stream oss( mm_db_mysql_get_context( _sql ) );
		mm_db_mysql_lock(_sql);
		oss
			<< "call db_ko_dog.p_user_relation_delete_friend("
			<< " " << "@code"
			<< ",'" << myself_id << "'"
			<< ",'" << friend_id << "'" << " );"
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
	//	struct definition for p_user_relation_query_friends	//
	p_user_relation_query_friends::~p_user_relation_query_friends()
	{

	}
	p_user_relation_query_friends::p_user_relation_query_friends()
		:code(0)
		,myself_id(0)
	{

	}
	void p_user_relation_query_friends::encode(mm_o_archive& archive) const
	{
		archive << code;
		archive << myself_id;
		archive << user_relation_assist_s;
		archive << user_relation_s;
	}
	void p_user_relation_query_friends::decode(const mm_i_archive& archive)
	{
		archive >> code;
		archive >> myself_id;
		archive >> user_relation_assist_s;
		archive >> user_relation_s;
	}
	int p_user_relation_query_friends::query(struct mm_db_mysql* _sql, mm_uint32_t logger_level)
	{
		int error_code = db_mysql_state_unknown;
		struct mm_logger* g_logger = mm_logger_instance();
		assert(NULL != _sql && "p_user_relation_query_friends input struct mm_db_mysql is a null.");
		mm_db_mysql_query db(_sql);
		mm_db_mysql_stream oss( mm_db_mysql_get_context( _sql ) );
		mm_db_mysql_lock(_sql);
		oss
			<< "call db_ko_dog.p_user_relation_query_friends("
			<< " " << "@code"
			<< ",'" << myself_id << "'" << " );"
			<< "select "
			<< " " << "@code" << "  ;";
		const std::string& sql_str = oss.get_string();
		mm_logger_message(g_logger,logger_level,"dump sql:%s",sql_str.c_str());
		if ( 0 == mm_db_mysql_real_query( _sql, sql_str.c_str() ) )
		{
			// result 1.
			mm_db_mysql_store_next_result(_sql);
			{
				assert( 3 == mm_db_mysql_get_field_count(_sql) && "field count is not match.");
				typedef user_relation_assist_vec::iterator iterator; 
				mm_uint64_t _affected_rows = mm_db_mysql_get_affected_rows(_sql);
				// std list vector resize(size_t n, value_type()), value_type can not contain shared pointer.
				// here we can safe resize.
				user_relation_assist_s.resize((size_t)_affected_rows);
				for (iterator it = user_relation_assist_s.begin();
					it!=user_relation_assist_s.end();++it)
				{
					if ( 0 != mm_db_mysql_get_has_row(_sql) )
					{
						t_user_relation_assist& v = *it;
						db.get_field( 0, v.id );
						db.get_field( 1, v.user_id );
						db.get_field( 2, v.friend_group );
					}
				}
			}
			mm_db_mysql_free_current_result(_sql);
			// result 2.
			mm_db_mysql_store_next_result(_sql);
			{
				assert( 5 == mm_db_mysql_get_field_count(_sql) && "field count is not match.");
				typedef user_relation_vec::iterator iterator; 
				mm_uint64_t _affected_rows = mm_db_mysql_get_affected_rows(_sql);
				// std list vector resize(size_t n, value_type()), value_type can not contain shared pointer.
				// here we can safe resize.
				user_relation_s.resize((size_t)_affected_rows);
				for (iterator it = user_relation_s.begin();
					it!=user_relation_s.end();++it)
				{
					if ( 0 != mm_db_mysql_get_has_row(_sql) )
					{
						t_user_relation& v = *it;
						db.get_field( 0, v.user_id );
						db.get_field( 1, v.friend_group_id );
						db.get_field( 2, v.friend_id );
						db.get_field( 3, v.friend_remark );
						db.get_field( 4, v.build_friend_time );
					}
				}
			}
			mm_db_mysql_free_current_result(_sql);
			// result 3.
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
	//	struct definition for p_user_relation_add_group	//
	p_user_relation_add_group::~p_user_relation_add_group()
	{

	}
	p_user_relation_add_group::p_user_relation_add_group()
		:code(0)
		,myself_id(0)
		,friend_group("")
		,id(0)
	{

	}
	void p_user_relation_add_group::encode(mm_o_archive& archive) const
	{
		archive << code;
		archive << myself_id;
		archive << friend_group;
		archive << id;
	}
	void p_user_relation_add_group::decode(const mm_i_archive& archive)
	{
		archive >> code;
		archive >> myself_id;
		archive >> friend_group;
		archive >> id;
	}
	int p_user_relation_add_group::query(struct mm_db_mysql* _sql, mm_uint32_t logger_level)
	{
		int error_code = db_mysql_state_unknown;
		struct mm_logger* g_logger = mm_logger_instance();
		assert(NULL != _sql && "p_user_relation_add_group input struct mm_db_mysql is a null.");
		mm_db_mysql_query db(_sql);
		mm_db_mysql_stream oss( mm_db_mysql_get_context( _sql ) );
		mm_db_mysql_lock(_sql);
		oss
			<< "call db_ko_dog.p_user_relation_add_group("
			<< " " << "@code"
			<< ",'" << myself_id << "'"
			<< ",'" << friend_group << "'" << " );"
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
	//	struct definition for p_user_relation_rename_group	//
	p_user_relation_rename_group::~p_user_relation_rename_group()
	{

	}
	p_user_relation_rename_group::p_user_relation_rename_group()
		:code(0)
		,user_id(0)
		,friend_group_id(0)
		,friend_group("")
	{

	}
	void p_user_relation_rename_group::encode(mm_o_archive& archive) const
	{
		archive << code;
		archive << user_id;
		archive << friend_group_id;
		archive << friend_group;
	}
	void p_user_relation_rename_group::decode(const mm_i_archive& archive)
	{
		archive >> code;
		archive >> user_id;
		archive >> friend_group_id;
		archive >> friend_group;
	}
	int p_user_relation_rename_group::query(struct mm_db_mysql* _sql, mm_uint32_t logger_level)
	{
		int error_code = db_mysql_state_unknown;
		struct mm_logger* g_logger = mm_logger_instance();
		assert(NULL != _sql && "p_user_relation_rename_group input struct mm_db_mysql is a null.");
		mm_db_mysql_query db(_sql);
		mm_db_mysql_stream oss( mm_db_mysql_get_context( _sql ) );
		mm_db_mysql_lock(_sql);
		oss
			<< "call db_ko_dog.p_user_relation_rename_group("
			<< " " << "@code"
			<< ",'" << user_id << "'"
			<< ",'" << friend_group_id << "'"
			<< ",'" << friend_group << "'" << " );"
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
	//	struct definition for p_user_relation_delete_group	//
	p_user_relation_delete_group::~p_user_relation_delete_group()
	{

	}
	p_user_relation_delete_group::p_user_relation_delete_group()
		:code(0)
		,myself_id(0)
		,friend_id(0)
		,friend_group_id(0)
	{

	}
	void p_user_relation_delete_group::encode(mm_o_archive& archive) const
	{
		archive << code;
		archive << myself_id;
		archive << friend_id;
		archive << friend_group_id;
	}
	void p_user_relation_delete_group::decode(const mm_i_archive& archive)
	{
		archive >> code;
		archive >> myself_id;
		archive >> friend_id;
		archive >> friend_group_id;
	}
	int p_user_relation_delete_group::query(struct mm_db_mysql* _sql, mm_uint32_t logger_level)
	{
		int error_code = db_mysql_state_unknown;
		struct mm_logger* g_logger = mm_logger_instance();
		assert(NULL != _sql && "p_user_relation_delete_group input struct mm_db_mysql is a null.");
		mm_db_mysql_query db(_sql);
		mm_db_mysql_stream oss( mm_db_mysql_get_context( _sql ) );
		mm_db_mysql_lock(_sql);
		oss
			<< "call db_ko_dog.p_user_relation_delete_group("
			<< " " << "@code"
			<< ",'" << myself_id << "'"
			<< ",'" << friend_id << "'"
			<< ",'" << friend_group_id << "'" << " );"
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
	//	struct definition for p_user_relation_change_group	//
	p_user_relation_change_group::~p_user_relation_change_group()
	{

	}
	p_user_relation_change_group::p_user_relation_change_group()
		:code(0)
		,myself_id(0)
		,friend_id(0)
		,friend_group_id_old(0)
		,friend_group_id_new(0)
	{

	}
	void p_user_relation_change_group::encode(mm_o_archive& archive) const
	{
		archive << code;
		archive << myself_id;
		archive << friend_id;
		archive << friend_group_id_old;
		archive << friend_group_id_new;
	}
	void p_user_relation_change_group::decode(const mm_i_archive& archive)
	{
		archive >> code;
		archive >> myself_id;
		archive >> friend_id;
		archive >> friend_group_id_old;
		archive >> friend_group_id_new;
	}
	int p_user_relation_change_group::query(struct mm_db_mysql* _sql, mm_uint32_t logger_level)
	{
		int error_code = db_mysql_state_unknown;
		struct mm_logger* g_logger = mm_logger_instance();
		assert(NULL != _sql && "p_user_relation_change_group input struct mm_db_mysql is a null.");
		mm_db_mysql_query db(_sql);
		mm_db_mysql_stream oss( mm_db_mysql_get_context( _sql ) );
		mm_db_mysql_lock(_sql);
		oss
			<< "call db_ko_dog.p_user_relation_change_group("
			<< " " << "@code"
			<< ",'" << myself_id << "'"
			<< ",'" << friend_id << "'"
			<< ",'" << friend_group_id_old << "'"
			<< ",'" << friend_group_id_new << "'" << " );"
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
	//	struct definition for p_user_relation_change_remark	//
	p_user_relation_change_remark::~p_user_relation_change_remark()
	{

	}
	p_user_relation_change_remark::p_user_relation_change_remark()
		:code(0)
		,myself_id(0)
		,friend_id(0)
		,friend_remark(0)
	{

	}
	void p_user_relation_change_remark::encode(mm_o_archive& archive) const
	{
		archive << code;
		archive << myself_id;
		archive << friend_id;
		archive << friend_remark;
	}
	void p_user_relation_change_remark::decode(const mm_i_archive& archive)
	{
		archive >> code;
		archive >> myself_id;
		archive >> friend_id;
		archive >> friend_remark;
	}
	int p_user_relation_change_remark::query(struct mm_db_mysql* _sql, mm_uint32_t logger_level)
	{
		int error_code = db_mysql_state_unknown;
		struct mm_logger* g_logger = mm_logger_instance();
		assert(NULL != _sql && "p_user_relation_change_remark input struct mm_db_mysql is a null.");
		mm_db_mysql_query db(_sql);
		mm_db_mysql_stream oss( mm_db_mysql_get_context( _sql ) );
		mm_db_mysql_lock(_sql);
		oss
			<< "call db_ko_dog.p_user_relation_change_remark("
			<< " " << "@code"
			<< ",'" << myself_id << "'"
			<< ",'" << friend_id << "'"
			<< ",'" << friend_remark << "'" << " );"
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
	//	struct definition for p_user_relation_add_apply	//
	p_user_relation_add_apply::~p_user_relation_add_apply()
	{

	}
	p_user_relation_add_apply::p_user_relation_add_apply()
		:code(0)
		,user_allow_id(0)
		,user_apply_id(0)
		,user_apply_description("")
	{

	}
	void p_user_relation_add_apply::encode(mm_o_archive& archive) const
	{
		archive << code;
		archive << user_allow_id;
		archive << user_apply_id;
		archive << user_apply_description;
	}
	void p_user_relation_add_apply::decode(const mm_i_archive& archive)
	{
		archive >> code;
		archive >> user_allow_id;
		archive >> user_apply_id;
		archive >> user_apply_description;
	}
	int p_user_relation_add_apply::query(struct mm_db_mysql* _sql, mm_uint32_t logger_level)
	{
		int error_code = db_mysql_state_unknown;
		struct mm_logger* g_logger = mm_logger_instance();
		assert(NULL != _sql && "p_user_relation_add_apply input struct mm_db_mysql is a null.");
		mm_db_mysql_query db(_sql);
		mm_db_mysql_stream oss( mm_db_mysql_get_context( _sql ) );
		mm_db_mysql_lock(_sql);
		oss
			<< "call db_ko_dog.p_user_relation_add_apply("
			<< " " << "@code"
			<< ",'" << user_allow_id << "'"
			<< ",'" << user_apply_id << "'"
			<< ",'" << user_apply_description << "'" << " );"
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
	//	struct definition for p_user_relation_respond_apply	//
	p_user_relation_respond_apply::~p_user_relation_respond_apply()
	{

	}
	p_user_relation_respond_apply::p_user_relation_respond_apply()
		:code(0)
		,user_allow_id(0)
		,user_apply_id(0)
	{

	}
	void p_user_relation_respond_apply::encode(mm_o_archive& archive) const
	{
		archive << code;
		archive << user_allow_id;
		archive << user_apply_id;
	}
	void p_user_relation_respond_apply::decode(const mm_i_archive& archive)
	{
		archive >> code;
		archive >> user_allow_id;
		archive >> user_apply_id;
	}
	int p_user_relation_respond_apply::query(struct mm_db_mysql* _sql, mm_uint32_t logger_level)
	{
		int error_code = db_mysql_state_unknown;
		struct mm_logger* g_logger = mm_logger_instance();
		assert(NULL != _sql && "p_user_relation_respond_apply input struct mm_db_mysql is a null.");
		mm_db_mysql_query db(_sql);
		mm_db_mysql_stream oss( mm_db_mysql_get_context( _sql ) );
		mm_db_mysql_lock(_sql);
		oss
			<< "call db_ko_dog.p_user_relation_respond_apply("
			<< " " << "@code"
			<< ",'" << user_allow_id << "'"
			<< ",'" << user_apply_id << "'" << " );"
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
	//	struct definition for p_user_relation_query_friends_apply	//
	p_user_relation_query_friends_apply::~p_user_relation_query_friends_apply()
	{

	}
	p_user_relation_query_friends_apply::p_user_relation_query_friends_apply()
		:code(0)
		,myself_id(0)
	{

	}
	void p_user_relation_query_friends_apply::encode(mm_o_archive& archive) const
	{
		archive << code;
		archive << myself_id;
		archive << user_relation_friend_apply_s;
	}
	void p_user_relation_query_friends_apply::decode(const mm_i_archive& archive)
	{
		archive >> code;
		archive >> myself_id;
		archive >> user_relation_friend_apply_s;
	}
	int p_user_relation_query_friends_apply::query(struct mm_db_mysql* _sql, mm_uint32_t logger_level)
	{
		int error_code = db_mysql_state_unknown;
		struct mm_logger* g_logger = mm_logger_instance();
		assert(NULL != _sql && "p_user_relation_query_friends_apply input struct mm_db_mysql is a null.");
		mm_db_mysql_query db(_sql);
		mm_db_mysql_stream oss( mm_db_mysql_get_context( _sql ) );
		mm_db_mysql_lock(_sql);
		oss
			<< "call db_ko_dog.p_user_relation_query_friends_apply("
			<< " " << "@code"
			<< ",'" << myself_id << "'" << " );"
			<< "select "
			<< " " << "@code" << "  ;";
		const std::string& sql_str = oss.get_string();
		mm_logger_message(g_logger,logger_level,"dump sql:%s",sql_str.c_str());
		if ( 0 == mm_db_mysql_real_query( _sql, sql_str.c_str() ) )
		{
			// result 1.
			mm_db_mysql_store_next_result(_sql);
			{
				assert( 5 == mm_db_mysql_get_field_count(_sql) && "field count is not match.");
				typedef user_relation_friend_apply_vec::iterator iterator; 
				mm_uint64_t _affected_rows = mm_db_mysql_get_affected_rows(_sql);
				// std list vector resize(size_t n, value_type()), value_type can not contain shared pointer.
				// here we can safe resize.
				user_relation_friend_apply_s.resize((size_t)_affected_rows);
				for (iterator it = user_relation_friend_apply_s.begin();
					it!=user_relation_friend_apply_s.end();++it)
				{
					if ( 0 != mm_db_mysql_get_has_row(_sql) )
					{
						t_user_relation_friend_apply& v = *it;
						db.get_field( 0, v.user_apply_id );
						db.get_field( 1, v.user_apply_name );
						db.get_field( 2, v.user_apply_nick );
						db.get_field( 3, v.user_apply_create_time );
						db.get_field( 4, v.user_apply_description );
					}
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