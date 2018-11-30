#include "network_account.h"
#include "KO_dog_network.h"
#include "core/mm_logger.h"
#include "application/KO_dog.h"
#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"

#include "protodef/cxx/protodef/c_business_account.pb.h"

void network_account_callback_function_registration(struct KO_dog_network* p)
{
	mm_client_udp_assign_n_callback(&p->udp, c_business_account::signed_in_rs_msg_id, &hd_n_c_business_account_signed_in_rs);
	mm_client_udp_assign_n_callback(&p->udp, c_business_account::register_rs_msg_id, &hd_n_c_business_account_register_rs);
}


//tcp/////////////////////////////////////////////////////////////////////////////////

void hd_n_c_business_account_signed_in_rs(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
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
	mm::KO_dog_data_user_basic* data_user_basic = &impl->data.data_user_basic;
	data_user_basic->token = "";
	do
	{
		// �������
		if (0 != mm_protobuf_cxx_decode_message(pack, &rs_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &rs_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		// �ذ��߼�����
		if (0 != error_info->code())
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());
			break;
		}

		//////////////////////////////////////////////////////////////////////////

		//���ݸ���
		data_user_basic->name = rs_msg.user_name();
		data_user_basic->id = rs_msg.user_id();
		data_user_basic->token = rs_msg.token();

		//���ݸ����Ժ���¼�����    ��������  evt_ags
		mm_event_args evt_ags;
		data_user_basic->d_event_userdata.fire_event(mm::KO_dog_data_user_basic::d_event_userdata_update, evt_ags);
		//////////////////////////////////////////////////////////////////////////
	} while (0);

}
void hd_n_c_business_account_register_rs(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
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
		// �������
		if (0 != mm_protobuf_cxx_decode_message(pack, &rs_msg))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &rs_msg);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		// �ذ��߼�����
		if (0 != error_info->code())
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());
			break;
		}
		//////////////////////////////////////////////////////////////////////////
		//
		mm::KO_dog_data* data = &impl->data;
		mm::KO_dog_data_user_basic* data_user_basic = &impl->data.data_user_basic;

		//���ݸ���
		data_user_basic->name = rs_msg.user_name();
		data_user_basic->id = rs_msg.user_id();
		data_user_basic->token = rs_msg.token();

		//���ݸ����Ժ���¼�����    ��������  evt_ags
		mm_event_args evt_ags;
		data_user_basic->d_event_userdata.fire_event(mm::KO_dog_data_user_basic::d_event_userdata_update, evt_ags);
		//////////////////////////////////////////////////////////////////////////
	} while (0);

}