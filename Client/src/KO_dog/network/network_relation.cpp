#include "network_relation.h"
#include "KO_dog_network.h"
#include "core/mm_logger.h"
#include "application/KO_dog.h"
#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"

#include "protodef/cxx/protodef/c_business_relation.pb.h"
#include "protodef/cxx/protodef/c_business_account.pb.h"
#include "script/KO_dog_script_error_code.h"
#include "network_lobby.h"

#include "model_data/KO_dog_data_relation.h"

static void __static_event_data_relation_server_error_fire(mm::KO_dog* impl, b_error::info* error_info);

extern void hd_q_c_business_relation_add_friend_rs(void* obj, void* u, struct mm_packet* pack);
extern void hd_q_c_business_relation_delete_friend_rs(void* obj, void* u, struct mm_packet* pack);
extern void hd_q_c_business_relation_allow_friend_rs(void* obj, void* u, struct mm_packet* pack);
extern void hd_q_c_business_relation_query_friends_rs(void* obj, void* u, struct mm_packet* pack);
extern void hd_q_c_business_relation_rename_friend_remark_rs(void* obj, void* u, struct mm_packet* pack);
extern void hd_q_c_business_relation_add_friend_group_rs(void* obj, void* u, struct mm_packet* pack);
extern void hd_q_c_business_relation_delete_friend_group_rs(void* obj, void* u, struct mm_packet* pack);
extern void hd_q_c_business_relation_rename_friend_group_rs(void* obj, void* u, struct mm_packet* pack);
extern void hd_q_c_business_relation_change_friend_group_rs(void* obj, void* u, struct mm_packet* pack);
extern void hd_q_c_business_relation_talk_friend_rs(void* obj, void* u, struct mm_packet* pack);
extern void hd_q_c_business_relation_query_friends_apply_rs(void* obj, void* u, struct mm_packet* pack);

extern void hd_q_c_business_relation_add_friend_nt(void* obj, void* u, struct mm_packet* pack);
extern void hd_q_c_business_relation_delete_friend_nt(void* obj, void* u, struct mm_packet* pack);
extern void hd_q_c_business_relation_allow_friend_nt(void* obj, void* u, struct mm_packet* pack);
extern void hd_q_c_business_relation_talk_friend_nt(void* obj, void* u, struct mm_packet* pack);


void network_relation_callback_function_registration(struct KO_dog_network* p)
{
	mm_client_tcp_assign_n_callback(&p->tcp, c_business_relation::add_friend_rs_msg_id, &hd_q_c_business_relation_add_friend_rs);
	mm_client_tcp_assign_n_callback(&p->tcp, c_business_relation::delete_friend_rs_msg_id, &hd_q_c_business_relation_delete_friend_rs);
	mm_client_tcp_assign_q_callback(&p->tcp, c_business_relation::allow_friend_rs_msg_id, &hd_q_c_business_relation_allow_friend_rs);
	mm_client_tcp_assign_q_callback(&p->tcp, c_business_relation::query_friends_rs_msg_id, &hd_q_c_business_relation_query_friends_rs);
	mm_client_tcp_assign_q_callback(&p->tcp, c_business_relation::rename_friend_remark_rs_msg_id, &hd_q_c_business_relation_rename_friend_remark_rs);
	mm_client_tcp_assign_q_callback(&p->tcp, c_business_relation::add_friend_group_rs_msg_id, &hd_q_c_business_relation_add_friend_group_rs);
	mm_client_tcp_assign_q_callback(&p->tcp, c_business_relation::delete_friend_group_rs_msg_id, &hd_q_c_business_relation_delete_friend_group_rs);
	mm_client_tcp_assign_q_callback(&p->tcp, c_business_relation::rename_friend_group_rs_msg_id, &hd_q_c_business_relation_rename_friend_group_rs);
	mm_client_tcp_assign_q_callback(&p->tcp, c_business_relation::change_friend_group_rs_msg_id, &hd_q_c_business_relation_change_friend_group_rs);
	mm_client_tcp_assign_q_callback(&p->tcp, c_business_relation::talk_friend_rs_msg_id, &hd_q_c_business_relation_talk_friend_rs);
	mm_client_tcp_assign_q_callback(&p->tcp, c_business_relation::query_friends_apply_rs_msg_id, &hd_q_c_business_relation_query_friends_apply_rs);

	mm_client_tcp_assign_q_callback(&p->tcp, c_business_relation::add_friend_nt_msg_id, &hd_q_c_business_relation_add_friend_nt);
	mm_client_tcp_assign_q_callback(&p->tcp, c_business_relation::delete_friend_nt_msg_id, &hd_q_c_business_relation_delete_friend_nt);
	mm_client_tcp_assign_q_callback(&p->tcp, c_business_relation::allow_friend_nt_msg_id, &hd_q_c_business_relation_allow_friend_nt);
	mm_client_tcp_assign_q_callback(&p->tcp, c_business_relation::talk_friend_nt_msg_id, &hd_q_c_business_relation_talk_friend_nt);
}


void hd_q_c_business_relation_add_friend_rs(void* obj, void* u, struct mm_packet* pack)
{
	c_business_relation::add_friend_rs rs_msg;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);

	//
	mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
	do
	{
		// 解包错误
		if (0 != mm_protobuf_cxx_decode_message(pack, &rs_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &rs_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		// 回包逻辑错误
		if (0 != error_info->code())
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());
			__static_event_data_relation_server_error_fire(impl, error_info);
		}
		else
		{

		}
		//////////////////////////////////////////////////////////////////////////
	} while (0);
}

void hd_q_c_business_relation_delete_friend_rs(void* obj, void* u, struct mm_packet* pack)
{
	c_business_relation::delete_friend_rs rs_msg;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);

	//
	mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
	do
	{
		// 解包错误
		if (0 != mm_protobuf_cxx_decode_message(pack, &rs_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &rs_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		// 回包逻辑错误
		if (0 != error_info->code())
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());	
			__static_event_data_relation_server_error_fire(impl, error_info);
		}
		else
		{		
			//数据更新
			p_relation->friendId_friendInfo_map.rmv(rs_msg.user_delete_id());
		}
		//////////////////////////////////////////////////////////////////////////
	} while (0);
	
}
void hd_q_c_business_relation_allow_friend_rs(void* obj, void* u, struct mm_packet* pack)
{
	c_business_relation::allow_friend_rs rs_msg;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);
	do
	{
		// 解包错误
		if (0 != mm_protobuf_cxx_decode_message(pack, &rs_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &rs_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
		mm::KO_dog_data_user_basic* p_data_user_basic = &impl->data.data_user_basic;
		// 回包逻辑错误
		if (0 != error_info->code())
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());
			__static_event_data_relation_server_error_fire(impl, error_info);
		}
		else
		{
			//数据更新
			{
				if (1 == rs_msg.opcode())
				{
					{
						typedef ::google::protobuf::RepeatedPtrField< ::b_business_relation::user_relation > p_v;
						p_v* p_s = rs_msg.mutable_relation_s();
						int index = p_s->size();
						p_v::iterator it;
						for (it = p_s->begin(); it != p_s->end(); it++)
						{
							//增加好友 
							p_relation->friendId_friendInfo_map.add(it->friend_id(), it->friend_group_id(), it->friend_remark(), it->build_friend_time());
						}
					}
				}
				//去掉好友申请通知nt 
				p_data_user_basic->m_friend_apply.rmv(rs_msg.user_allow_id());
			}
		}
	} while (0);

}

void hd_q_c_business_relation_query_friends_rs(void* obj, void* u, struct mm_packet* pack)
{
	c_business_relation::query_friends_rs rs_msg;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);
	do
	{
		// 解包错误
		if (0 != mm_protobuf_cxx_decode_message(pack, &rs_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &rs_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
		// 回包逻辑错误
		if (0 != error_info->code())
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());
			__static_event_data_relation_server_error_fire(impl, error_info);
		}
		else
		{
			//数据更新
			mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
			{
				typedef ::google::protobuf::RepeatedPtrField< ::b_business_relation::user_relation_group > p_v;
				p_v* p_s = rs_msg.mutable_group_s();
				int index = p_s->size();
				//先清空现有map(组数据 和好友数据)，遍历传回数据并添加进map
				p_relation->groupId_groupName_map.clear();
				//添加客户端默认分组（视图界面不需要发布事件，视图有个默认分组）
				mm::data_relation_groupInfo* p_g = p_relation->groupId_groupName_map.add(0);
				//p_g->group_id = 0;
				//p_g->group_name = "friends";
				p_g->update(0, "friends");
				p_v::iterator it;
				for (it = p_s->begin(); it != p_s->end(); it++)
				{
					//备注： 使用的是内置发布事件的函数，因此不需要额外增加外表事件发布
					p_g = p_relation->groupId_groupName_map.add(it->id());
					//p_g->group_id = it->user_id();
					//p_g->group_name = it->friend_group();
					p_g->update(it->id(), it->friend_group());
				}
			}
			{
				typedef ::google::protobuf::RepeatedPtrField< ::b_business_relation::user_relation > p_v;
				p_v* p_s = rs_msg.mutable_relation_s();
				int index = p_s->size();
				//先清空现有map(组数据 和好友数据)，遍历传回数据并添加进map
				p_relation->friendId_friendInfo_map.clear();
				p_v::iterator it;
				for (it = p_s->begin(); it != p_s->end(); it++)
				{
					//备注： 使用的是内置发布事件的函数，因此不需要额外增加外表事件发布
					p_relation->friendId_friendInfo_map.add(it->friend_id(), it->friend_group_id(), it->friend_remark(), it->build_friend_time());
				}
			}
		}
	} while (0);

}

void hd_q_c_business_relation_rename_friend_remark_rs(void* obj, void* u, struct mm_packet* pack)
{
	c_business_relation::rename_friend_remark_rs rs_msg;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);

	//
	do
	{
		// 解包错误
		if (0 != mm_protobuf_cxx_decode_message(pack, &rs_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &rs_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
		// 回包逻辑错误
		if (0 != error_info->code())
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());
			__static_event_data_relation_server_error_fire(impl, error_info);
		}
		else
		{
			//数据更新
			mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
			mm::data_relation_friendInfo* p_friendInfo = p_relation->friendId_friendInfo_map.get(rs_msg.user_friend_id());
			if (NULL != p_friendInfo)
			{
				p_friendInfo->update_remark(rs_msg.user_friend_remark()); 
			}
			else
			{
				mm_logger_log_E(g_logger, "%s %d %s", __FUNCTION__, __LINE__, "mm::KO_dog_data_relation::data_relation_friendInfo return pointer is null !!");
			}
		}
		//////////////////////////////////////////////////////////////////////////
	} while (0);
}

void hd_q_c_business_relation_add_friend_group_rs(void* obj, void* u, struct mm_packet* pack)
{
	c_business_relation::add_friend_group_rs rs_msg;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);

	//
	do
	{
		// 解包错误
		if (0 != mm_protobuf_cxx_decode_message(pack, &rs_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &rs_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
		// 回包逻辑错误
		if (0 != error_info->code())
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());
			__static_event_data_relation_server_error_fire(impl, error_info);
		}
		else
		{
			//数据更新
			mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
			mm::data_relation_groupInfo* p_groupInfo = p_relation->groupId_groupName_map.add(rs_msg.user_friend_group_id());
			if (NULL != p_groupInfo)
			{
				p_groupInfo->update(rs_msg.user_friend_group_id(), rs_msg.user_friend_group());
			}
			else
			{
				mm_logger_log_E(g_logger, "%s %d %s", __FUNCTION__, __LINE__, "mm::KO_dog_data_relation::data_relation_groupInfo return pointer is null !!");
			}

			
		}
		//////////////////////////////////////////////////////////////////////////
	} while (0);

}
void hd_q_c_business_relation_delete_friend_group_rs(void* obj, void* u, struct mm_packet* pack)
{
	c_business_relation::delete_friend_group_rs rs_msg;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);

	//
	do
	{
		// 解包错误
		if (0 != mm_protobuf_cxx_decode_message(pack, &rs_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &rs_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
		// 回包逻辑错误
		if (0 != error_info->code())
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());
			__static_event_data_relation_server_error_fire(impl, error_info);
		}
		else
		{
			//数据更新
			mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
			if (0 == rs_msg.user_friend_id())
			{
				p_relation->rmv(rs_msg.user_friend_group_id());
			}
			else
			{
				mm::data_relation_friendInfo* p_friendInfo = p_relation->friendId_friendInfo_map.get(rs_msg.user_friend_id());
				if (NULL != p_friendInfo)
				{
					p_friendInfo->update_group(0);
				}
				else
				{
					mm_logger_log_E(g_logger, "%s %d %s", __FUNCTION__, __LINE__, "mm::KO_dog_data_relation::data_relation_friendInfo return pointer is null !!");
				}
			}			
		}
		//////////////////////////////////////////////////////////////////////////
	} while (0);

}

void hd_q_c_business_relation_rename_friend_group_rs(void* obj, void* u, struct mm_packet* pack)
{
	c_business_relation::rename_friend_group_rs rs_msg;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);

	//
	do
	{
		// 解包错误
		if (0 != mm_protobuf_cxx_decode_message(pack, &rs_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &rs_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
		// 回包逻辑错误
		if (0 != error_info->code())
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());
			//发布relation 服务器错误事件    发布内容  evt_ags
			__static_event_data_relation_server_error_fire(impl, error_info);
		}
		else
		{
			//数据更新
			mm::data_relation_groupInfo* p_groupInfo = p_relation->groupId_groupName_map.get(rs_msg.user_friend_group_id());
			if (NULL != p_groupInfo)
			{
				p_groupInfo->update_name(rs_msg.user_friend_group());
			}
			else
			{
				mm_logger_log_E(g_logger, "%s %d %s", __FUNCTION__, __LINE__, "mm::KO_dog_data_relation::data_relation_groupInfo return pointer is null !!");
			}
		}
		//////////////////////////////////////////////////////////////////////////
	} while (0);

}

void hd_q_c_business_relation_change_friend_group_rs(void* obj, void* u, struct mm_packet* pack)
{
	c_business_relation::change_friend_group_rs rs_msg;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);

	//
	do
	{
		// 解包错误
		if (0 != mm_protobuf_cxx_decode_message(pack, &rs_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &rs_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
		// 回包逻辑错误
		if (0 != error_info->code())
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());
			//发布relation 服务器错误事件    发布内容  evt_ags
			__static_event_data_relation_server_error_fire(impl, error_info);
		}
		else
		{
			//数据更新
			mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
			if (0 == rs_msg.user_friend_id())
			{
				p_relation->meg(rs_msg.user_friend_group_id_old(), rs_msg.user_friend_group_id_new());
			}
			else
			{
				mm::data_relation_friendInfo* p_friendInfo = p_relation->friendId_friendInfo_map.get(rs_msg.user_friend_id());
				if (NULL != p_friendInfo)
				{
					p_friendInfo->update_group(rs_msg.user_friend_group_id_new());
				}
				else
				{
					mm_logger_log_E(g_logger, "%s %d %s", __FUNCTION__, __LINE__, "mm::KO_dog_data_relation::data_relation_friendInfo return pointer is null !!");
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////
	} while (0);

}

void hd_q_c_business_relation_talk_friend_rs(void* obj, void* u, struct mm_packet* pack)
{
	c_business_relation::talk_friend_rs rs_msg;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);

	//
	do
	{
		// 解包错误
		if (0 != mm_protobuf_cxx_decode_message(pack, &rs_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &rs_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
		// 回包逻辑错误
		if (0 != error_info->code())
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());
			//发布relation 服务器错误事件    发布内容  evt_ags
			__static_event_data_relation_server_error_fire(impl, error_info);
		}
		else
		{
			//////////////////////////////////////////////////////////////////////////
			//数据更新
			//////////////////////////////////////////////////////////////////////////
			//数据更新以后的事件发布    发布内容  evt_ags
			mm_event_args evt_ags;
			p_relation->d_event_set.fire_event(mm::KO_dog_data_relation::event_data_relation_talk_friend_send, evt_ags);
		}
	} while (0);

}

void hd_q_c_business_relation_query_friends_apply_rs(void* obj, void* u, struct mm_packet* pack)
{
	c_business_relation::query_friends_apply_rs rs_msg;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);
	do
	{
		// 解包错误
		if (0 != mm_protobuf_cxx_decode_message(pack, &rs_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &rs_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
		// 回包逻辑错误
		if (0 != error_info->code())
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());
			//发布relation 服务器错误事件    发布内容  evt_ags
			__static_event_data_relation_server_error_fire(impl, error_info);
		}
		else
		{
			{
				mm::KO_dog_data_user_basic* p_data_user_basic = &impl->data.data_user_basic;
				typedef ::google::protobuf::RepeatedPtrField< ::b_business_relation::friend_apply > p_v;
				p_v* p_s = rs_msg.mutable_apply_s();
				int index = p_s->size();
				//先清空现有map(组数据 和好友数据)，遍历传回数据并添加进map
				p_data_user_basic->m_friend_apply.clear();
				p_v::iterator it;
				for (it = p_s->begin(); it != p_s->end(); it++)
				{
					//备注： 使用的是内置发布事件的函数，因此不需要额外增加外表事件发布					
					mm::data_basic_friend_info* p_user_basic = p_data_user_basic->m_friend_apply.add(it->user_apply_id());
					if (NULL != p_user_basic)
					{
						p_user_basic->update(it->user_apply_id(), it->user_apply_name(), it->user_apply_nick(), it->user_apply_create_time(), it->user_apply_description());
					}
					else
					{
						mm_logger_log_E(g_logger, "%s %d %s", __FUNCTION__, __LINE__, "mm::KO_dog_data_user_basic::data_basic_friend_info return pointer is null !!");
					}
				}
			}
		}
	} while (0);

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void hd_q_c_business_relation_add_friend_nt(void* obj, void* u, struct mm_packet* pack)
{
	c_business_relation::add_friend_nt nt_msg;
	struct mm_string proto_desc;

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);

	//
	mm::KO_dog_data* data = &impl->data;
	mm::KO_dog_data_user_basic* p_data_user_basic = &impl->data.data_user_basic;
	mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
	do
	{
		// 解包错误
		if (0 != mm_protobuf_cxx_decode_message(pack, &nt_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &nt_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		//数据更新
		b_business_account::user_info* user_info = nt_msg.mutable_apply_user_info();
		mm::data_basic_friend_info* p_user_basic = p_data_user_basic->m_friend_apply.get(user_info->user_id());
		if (NULL == p_user_basic)
		{
			p_user_basic = p_data_user_basic->m_friend_apply.add(user_info->user_id());
			p_user_basic->update(user_info->user_id(), user_info->user_name(), user_info->user_nick(), user_info->create_time(), nt_msg.description());
		}
		else
		{
			p_user_basic->update_description(nt_msg.description());
		}
	} while (0);
}

void hd_q_c_business_relation_delete_friend_nt(void* obj, void* u, struct mm_packet* pack)
{
	c_business_relation::delete_friend_nt nt_msg;
	struct mm_string proto_desc;

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);

	//
	do
	{
		// 解包错误
		if (0 != mm_protobuf_cxx_decode_message(pack, &nt_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &nt_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		//数据更新
		mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
		p_relation->friendId_friendInfo_map.rmv(nt_msg.apply_user_id());
	} while (0);

}
void hd_q_c_business_relation_allow_friend_nt(void* obj, void* u, struct mm_packet* pack)
{
	c_business_relation::allow_friend_nt nt_msg;
	struct mm_string proto_desc;

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);

	//
	do
	{
		// 解包错误
		if (0 != mm_protobuf_cxx_decode_message(pack, &nt_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &nt_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		//数据更新
		mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
		if (1 == nt_msg.opcode())
		{
			{
				typedef ::google::protobuf::RepeatedPtrField< ::b_business_relation::user_relation > p_v;
				p_v* p_s = nt_msg.mutable_relation_s();
				int index = p_s->size();
				p_v::iterator it;
				for (it = p_s->begin(); it != p_s->end(); it++)
				{
					p_relation->friendId_friendInfo_map.add(it->friend_id(), it->friend_group_id(), it->friend_remark(), it->build_friend_time());
				}
			}
		}
	} while (0);
}


void hd_q_c_business_relation_talk_friend_nt(void* obj, void* u, struct mm_packet* pack)
{
	c_business_relation::delete_friend_nt nt_msg;
	struct mm_string proto_desc;

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);

	//
	do
	{
		// 解包错误
		if (0 != mm_protobuf_cxx_decode_message(pack, &nt_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &nt_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		//数据更新
		mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
		//////////////////////////////////////////////////////////////////////////

		//数据更新以后的事件发布    发布内容  evt_ags
		mm_event_args evt_ags;
		p_relation->d_event_set.fire_event(mm::KO_dog_data_relation::event_data_relation_talk_friend_receive, evt_ags);
		//////////////////////////////////////////////////////////////////////////
	} while (0);

}


static void __static_event_data_relation_server_error_fire(mm::KO_dog* impl, b_error::info* error_info)
{
	//发布relation 服务器错误事件    发布内容  evt_ags
	mm::KO_dog_data_relation* p_relation = &impl->data.data_relation;
	mm::mm_event_data_log_view evt_ags;
	evt_ags.code = error_info->code();
	evt_ags.desc = error_info->desc();
	KO_dog_script_error_code_get_view(impl->lua_context.state, evt_ags.code, evt_ags.view);
	p_relation->d_event_set.fire_event(mm::KO_dog_data_relation::event_data_relation_server_error, evt_ags);
}

