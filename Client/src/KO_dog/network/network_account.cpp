#include "network_account.h"
#include "KO_dog_network.h"
#include "core/mm_logger.h"
#include "application/KO_dog.h"
#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"

#include "protodef/cxx/protodef/c_business_account.pb.h"
#include "script/KO_dog_script_error_code.h"
#include "network_lobby.h"


extern void hd_n_c_business_account_signed_in_rs(void* obj, void* u, struct mm_packet* pack);
extern void hd_n_c_business_account_register_rs(void* obj, void* u, struct mm_packet* pack);
extern void hd_q_c_business_account_signed_in_rs(void* obj, void* u, struct mm_packet* pack);
extern void hd_q_c_business_account_register_rs(void* obj, void* u, struct mm_packet* pack);

void network_account_callback_function_registration(struct KO_dog_network* p)
{
	mm_client_tcp_assign_n_callback(&p->tcp, c_business_account::signed_in_rs_msg_id, &hd_n_c_business_account_signed_in_rs);
	mm_client_tcp_assign_n_callback(&p->tcp, c_business_account::register_rs_msg_id, &hd_n_c_business_account_register_rs);
	mm_client_tcp_assign_q_callback(&p->tcp, c_business_account::signed_in_rs_msg_id, &hd_q_c_business_account_signed_in_rs);
	mm_client_tcp_assign_q_callback(&p->tcp, c_business_account::register_rs_msg_id, &hd_q_c_business_account_register_rs);
}

void hd_n_c_business_account_signed_in_rs(void* obj, void* u, struct mm_packet* pack)
{
	c_business_account::signed_in_rs rs_msg;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);

	//
	mm::KO_dog_data_user_basic* p_data_user_basic = &impl->data.data_user_basic;
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
		}
		else
		{
			struct KO_dog_network* p_network = &impl->network;
			struct lobby_user_token* p_lobby_user_token = &p_network->lobby_token;
			//保存登录返回的 token ，并且把网络层的 token 设置为 motion
			lobby_user_token_lock(p_lobby_user_token);
			p_lobby_user_token->uid = rs_msg.user_id();
			p_lobby_user_token->token = rs_msg.token();
			p_lobby_user_token->state = lobby_user_token::user_token_motion;
			lobby_user_token_unlock(p_lobby_user_token);
			//发 token 到 lobby
			mm_client_tcp_flush_send_token_verify_rq(&p_network->tcp);
		}
		//////////////////////////////////////////////////////////////////////////
	} while (0);

}
void hd_n_c_business_account_register_rs(void* obj, void* u, struct mm_packet* pack)
{
	c_business_account::register_rs rs_msg;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);

	//
	mm::KO_dog_data_user_basic* p_data_user_basic = &impl->data.data_user_basic;
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
		}
		else
		{
			struct KO_dog_network* p_network = &impl->network;
			struct lobby_user_token* p_lobby_user_token = &p_network->lobby_token;
			//保存登录返回的 token ，并且把网络层的 token 设置为 motion
			lobby_user_token_lock(p_lobby_user_token);
			p_lobby_user_token->uid = rs_msg.user_id();
			p_lobby_user_token->token = rs_msg.token();
			p_lobby_user_token->state = lobby_user_token::user_token_motion;
			lobby_user_token_unlock(p_lobby_user_token);
			//发 token 到 lobby
			mm_client_tcp_flush_send_token_verify_rq(&p_network->tcp);
		}
		//////////////////////////////////////////////////////////////////////////
	} while (0);
}

//tcp/////////////////////////////////////////////////////////////////////////////////

void hd_q_c_business_account_signed_in_rs(void* obj, void* u, struct mm_packet* pack)
{
	c_business_account::signed_in_rs rs_msg;
	struct mm_string proto_desc;
	b_error::info* error_info = rs_msg.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	////////////////////////////////
	mm_string_init(&proto_desc);

	//
	mm::KO_dog_data_user_basic* p_data_user_basic = &impl->data.data_user_basic;	
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
			//发布到界面输出错误日志    发布内容  evt_ags
			mm::KO_dog_data_log_view* data_log_view = &impl->data.data_log_view;
			mm::mm_event_data_log_view evt_ags;
			evt_ags.code = error_info->code();
			evt_ags.desc = error_info->desc();
			KO_dog_script_error_code_get_view(impl->lua_context.state, evt_ags.code, evt_ags.view);
			data_log_view->d_event_set.fire_event(mm::KO_dog_data_log_view::event_log_view, evt_ags);
		}
		else
		{		
			//数据更新
			p_data_user_basic->basic.name = rs_msg.user_name();
			p_data_user_basic->basic.id = rs_msg.user_id();
			p_data_user_basic->basic.state = mm::data_user_basic::user_basic_motion;
			//////////////////////////////////////////////////////////////////////////

			//数据更新以后的事件发布    发布内容  evt_ags
			mm_event_args evt_ags;
			p_data_user_basic->d_event_set.fire_event(mm::KO_dog_data_user_basic::event_userdata_user_basic_update, evt_ags);
		}
		//////////////////////////////////////////////////////////////////////////
	} while (0);
	
}
void hd_q_c_business_account_register_rs(void* obj, void* u, struct mm_packet* pack)
{
	c_business_account::register_rs rs_msg;
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
		// 回包逻辑错误
		mm::KO_dog_data* data = &impl->data;
		mm::KO_dog_data_user_basic* p_data_user_basic = &impl->data.data_user_basic;
		if (0 != error_info->code())
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());

			//发布到界面输出错误日志    发布内容  evt_ags
			mm::KO_dog_data_log_view* data_log_view = &impl->data.data_log_view;
			mm::mm_event_data_log_view evt_ags;
			evt_ags.code = error_info->code();
			evt_ags.desc = error_info->desc();
			KO_dog_script_error_code_get_view(impl->lua_context.state, evt_ags.code, evt_ags.view);
			data_log_view->d_event_set.fire_event(mm::KO_dog_data_log_view::event_log_view, evt_ags);
		}
		else
		{
			//数据更新
			p_data_user_basic->basic.name = rs_msg.user_name();
			p_data_user_basic->basic.id = rs_msg.user_id();
			p_data_user_basic->basic.state = mm::data_user_basic::user_basic_motion;
			//////////////////////////////////////////////////////////////////////////

			//数据更新以后的事件发布    发布内容  evt_ags
			mm_event_args evt_ags;
			p_data_user_basic->d_event_set.fire_event(mm::KO_dog_data_user_basic::event_userdata_user_basic_update, evt_ags);
			//////////////////////////////////////////////////////////////////////////
		}
	} while (0);

}