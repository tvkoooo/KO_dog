//#include "mm_business_nt_message_sql.h"
//
//#include "shuttle_common/mm_error_code_mysql.h"
//#include "shuttle_common/mm_error_code_common.h"
//#include "shuttle_common/mm_message_lpusher.h"
//
//#include "net/mm_packet.h"
//
//#include "querydef/mm_q_db_ko_dog_t_nt_message.h"
//#include "querydef/mm_m_db_ko_dog_t_nt_message.h"
////////////////////////////////////////////////////////////////////////////
//void mm_business_nt_message_sql_init(struct mm_business_nt_message_sql* p)
//{
//	mm_db_mysql_config_init(&p->db_sql_config);
//	mm_db_mysql_section_init(&p->db_sql_section);
//	//
//	mm_string_assigns(&p->db_sql_config.node, "127.0.0.1");
//	mm_string_assigns(&p->db_sql_config.username, "tvkoooo");
//	mm_string_assigns(&p->db_sql_config.password, "fsf4e%$c34fdt43BR_BDfdhjs8eu");
//	mm_string_assigns(&p->db_sql_config.basename, "db_ko_dog");
//	p->db_sql_config.port = 3306;
//	//
//	mm_db_mysql_section_set_config(&p->db_sql_section, &p->db_sql_config);
//}
//void mm_business_nt_message_sql_destroy(struct mm_business_nt_message_sql* p)
//{
//	mm_db_mysql_config_destroy(&p->db_sql_config);
//	mm_db_mysql_section_destroy(&p->db_sql_section);
//
//}
////////////////////////////////////////////////////////////////////////////
//void mm_business_nt_message_sql_assign(struct mm_business_nt_message_sql* p, struct mm_message_lpusher* message_lpusher, struct mm_error_desc* error_desc)
//{
//	p->message_lpusher = message_lpusher;
//	p->error_desc = error_desc;
//
//}
//
////////////////////////////////////////////////////////////////////////////
//mm_uint64_t mm_business_nt_message_sql_stored_procedure(struct mm_business_nt_message_sql* p,
//	mm_uint64_t user_id, mm_uint64_t to_user_id, mm_uint32_t message_mid, ::google::protobuf::Message* message,
//	struct mm_packet* nt_pack)
//{
//	struct mm_logger* g_logger = mm_logger_instance();
//	mm_uint64_t note_id = 0;
//	size_t push_size = 0;
//
//	mm::p_nt_message_add query;
//	query.user_id = user_id;
//	query.to_user_id = to_user_id;
//	query.message_mid = message_mid;
//
//	//对nt包放入回退队并列做流处理
//	struct mm_packet_head packet_head;
//	packet_head.mid = message_mid;
//	packet_head.pid = 0;
//	packet_head.sid = 0;
//	packet_head.uid = to_user_id;
//	//做push到回推队列序列化（push 流）
//	mm_message_lpusher_buffer_protobuf(p->message_lpusher, message, &packet_head, nt_pack);
//	push_size = mm_message_lpusher_buffer_size(p->message_lpusher);
//	query.nt_message.resize(push_size);
//	mm_message_lpusher_buffer_copy(p->message_lpusher, (mm_uint8_t*)query.nt_message.data(), 0, push_size);
//	//////////////////////////////////////////////////////////////////////////
//	//调用nt_message_sql(nt消息 push 流 进行sql存储)
//	do
//	{
//		struct mm_db_mysql* db_mysql = mm_db_mysql_section_thread_instance(&p->db_sql_section);
//		if (db_mysql_state_success != query.query(db_mysql, MM_LOG_INFO))
//		{
//			mm_logger_log_W(g_logger, "%s %d %d %s", __FUNCTION__, __LINE__, err_common_exec_procedure_failure, mm_error_desc_string(p->error_desc, err_common_exec_procedure_failure));
//			break;
//		}
//		if (0 != query.code)
//		{
//			mm_logger_log_W(g_logger, "%s %d %d %s", __FUNCTION__, __LINE__, query.code, mm_error_desc_string(p->error_desc, query.code));
//			break;
//		}
//		note_id = query.note_id;
//		mm_logger_log_I(g_logger, "%s %d nt_message_note_id:%d", __FUNCTION__, __LINE__, note_id);
//	} while (true);
//	//////////////////////////////////////////////////////////////////////////
//	//nt消息 push 流 推送到回推队列
//	mm_message_lpusher_lpush_buffer(p->message_lpusher, (mm_uint8_t*)query.nt_message.data(), 0, push_size);
//	return note_id;
//}
