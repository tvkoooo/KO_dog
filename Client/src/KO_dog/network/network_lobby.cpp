#include "network_lobby.h"
#include "application/KO_dog.h"
#include "KO_dog_network.h"
#include "core/mm_logger.h"
#include "application/KO_dog.h"
#include "protobuf/mm_protobuff_cxx.h"
#include "protobuf/mm_protobuff_cxx_net.h"

#include "protodef/cxx/protodef/c_shuttle_lobby.pb.h"

#include "model_data/KO_dog_data_log_view.h"
#include "network_handle.h"


void network_lobby_callback_function_registration(struct KO_dog_network* p)
{
	mm_client_tcp_assign_n_callback(&p->tcp, c_shuttle_lobby::exchange_key_rs_msg_id, &hd_n_c_shuttle_lobby_exchange_key_rs);
	mm_client_tcp_assign_q_callback(&p->tcp, c_shuttle_lobby::exchange_key_rs_msg_id, &hd_q_c_shuttle_lobby_exchange_key_rs);
}
static void static_test_rc4_i()
{
	const char* key = "jfw9ejfoj#@%";

	char a64[64] = "123456789";
	char b64[64] = { 0 };
	char c64[64] = { 0 };

	RC4_KEY i;
	RC4_KEY o;
	RC4_set_key(&i, strlen(key), (const unsigned char *)key);
	RC4_set_key(&o, strlen(key), (const unsigned char *)key);

	//RC4(&i, 64, (const unsigned char *)a64, (unsigned char *)b64);
	//RC4(&o, 64, (const unsigned char *)b64, (unsigned char *)c64);

	RC4(&i, 64, (const unsigned char *)a64, (unsigned char *)a64);
	RC4(&o, 64, (const unsigned char *)a64, (unsigned char *)a64);
	
	//int aa;
}

//udp/////////////////////////////////////////////////////////////////////////////////
void mm_client_tcp_flush_send_exchange_key_rq(struct mm_client_tcp* p)
{
	//static_test_rc4_i();
	struct mm_logger* g_logger = mm_logger_instance();

	c_shuttle_lobby::exchange_key_rq msg_rq;
	mm::KO_dog* impl = (mm::KO_dog*)p->u;
	struct KO_dog_network* network = &impl->network;
	struct tcps_connect* p_tcps = &network->tcps;
	struct mm_openssl_rsa* p_openssl_rsa_client = &p_tcps->openssl_rsa_client;
	struct mm_openssl_rsa* p_openssl_rsa_server = &p_tcps->openssl_rsa_server;
	struct mm_openssl_rc4* p_openssl_rc4 = &p_tcps->openssl_rc4;
	struct mm_openssl_rc4_key* p_openssl_rc4_key = &p_tcps->openssl_rc4_key;
	int pub_encrypt_len = 0;

	//���� client rc4 L���ֲ��ұ��浽 mm_openssl_rc4_key ��R�������ɷ�����rs�ذ������ģ�
	mm_openssl_rc4_lock(p_openssl_rc4);
	mm_openssl_rc4_random_buffer(p_openssl_rc4, &p_openssl_rc4_key->key_l, KO_DOG_DATA_NET_RC4_LENGTH);
	mm_openssl_rc4_unlock(p_openssl_rc4);
	//ȡ�� msg_rq �� ��Ա encrypt_key_l��rc4��L����key�Ż�server���Ĺ�Կ�������棺ʹ�ù�Կ����rc4��L���� ��ַ���Թ��޸�ʹ��
	std::string* p_encrypt_key_l = msg_rq.mutable_encrypt_key_l();
	//����һ����ʱ�����������н� ��Կ����rc4��L�� �����ݣ���Ϊ������C��API�����ܽ�������ƥ�䣩
	struct mm_string output;
	mm_string_init(&output);
	// ��server rsa ��Կ���� rc4 L��
	mm_openssl_rsa_lock(p_openssl_rsa_server);
	mm_openssl_rc4_key_lock(p_openssl_rc4_key);
	pub_encrypt_len = mm_openssl_rsa_pub_encrypt(p_openssl_rsa_server, &p_openssl_rc4_key->key_l, &output);
	mm_openssl_rc4_key_unlock(p_openssl_rc4_key);
	mm_openssl_rsa_unlock(p_openssl_rsa_server);
	if (0 > pub_encrypt_len)
	{
		mm_logger_log_E(g_logger, "%s %d can not encrypt, server public key invalid.", __FUNCTION__, __LINE__);
	}
	else
	{
		mm_openssl_rsa_lock(p_openssl_rsa_client);
		//���� client rsa �������ɵ�ctx���У���û�н���Կ����˽Կ��ȡ�� p_openssl_rsa_client�����С�
		mm_openssl_rsa_generate(p_openssl_rsa_client, KO_DOG_DATA_NET_RSA_LENGTH, RSA_3);
		//���ɵ� rsa ��Կ ���� mm_openssl_rsa����
		mm_openssl_rsa_ctx_to_pub_mem(p_openssl_rsa_client);
		//��� client rsa ��Կ
		size_t openssl_rsa_pub_mem_size = mm_openssl_rsa_pub_mem_size(p_openssl_rsa_client);
		//ȡ�� msg_rq �� ��Ա public_key ��ַ���Թ��޸�ʹ��
		std::string* openssl_rsa_pub_mem = msg_rq.mutable_public_key();
		//���ַ���Ԥ����һ�� openssl_rsa_pub_mem_size ���ȵĻ�����
		openssl_rsa_pub_mem->resize(openssl_rsa_pub_mem_size);
		//�� client rsa �Ĺ�Կ �Կ��� Ԥ����Ļ�����
		mm_openssl_rsa_pub_mem_get(p_openssl_rsa_client, (mm_uint8_t*)openssl_rsa_pub_mem->data(), 0, openssl_rsa_pub_mem_size);
		mm_openssl_rsa_unlock(p_openssl_rsa_client);

		// Ԥ����нӶ���
		p_encrypt_key_l->resize(output.l);
		//�� output ���� �Կ����� Ԥ����Ļ�������rq���ڲ� p_encrypt_key_l��
		mm_memcpy((char*)p_encrypt_key_l->data(), output.s, output.l);
		mm_string_destroy(&output);
		msg_rq.set_version(0);

		//send api �̰߳�ȫ
		mm_client_tcp_flush_send_message(p, 0, c_shuttle_lobby::exchange_key_rq_msg_id, &msg_rq);
	}
}

void hd_n_c_shuttle_lobby_exchange_key_rs(void* obj, void* u, struct mm_packet* pack)
{
	c_shuttle_lobby::exchange_key_rs msg_rs;
	struct mm_string proto_desc;
	b_error::info* error_info = msg_rs.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);

	////////////////////////////////
	mm_string_init(&proto_desc);	
	do
	{
		// �������
		if (0 != mm_protobuf_cxx_decode_message(pack, &msg_rs))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &msg_rs);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		// �ذ��߼�����
		if (0 != error_info->code())
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());			
		}
		else
		{	
			//���ݸ���
			struct KO_dog_network* network = &impl->network;
			struct mm_tcp* p_tcp = &network->tcp.net_tcp.tcp;
			struct tcps_connect* tcps = &network->tcps;
			struct mm_openssl_tcp_context* p_openssl_tcp_context = &tcps->openssl_tcp_context;
			struct mm_openssl_rsa* p_openssl_rsa_client = &tcps->openssl_rsa_client;
			struct mm_openssl_rsa* p_openssl_rsa_server = &tcps->openssl_rsa_server;
			struct mm_openssl_rc4* p_openssl_rc4 = &tcps->openssl_rc4;
			struct mm_openssl_rc4_key* p_openssl_rc4_key = &tcps->openssl_rc4_key;
			int pri_decrypt_len = 0;

			//ȡ��msg_rs rc4 R�� ����
			const std::string& rc4_R_miwen = msg_rs.encrypt_key_r();
			struct mm_string i_rc4_R_miwen;
			mm_string_init(&i_rc4_R_miwen);
			mm_string_resize(&i_rc4_R_miwen, rc4_R_miwen.size());
			mm_memcpy(i_rc4_R_miwen.s, (char*)rc4_R_miwen.data(), rc4_R_miwen.size());	
			//��client rsa ˽Կ����rs���ص����ģ���� rs4 ��R��
			mm_openssl_rsa_lock(p_openssl_rsa_client);
			mm_openssl_rc4_key_lock(p_openssl_rc4_key);
			pri_decrypt_len = mm_openssl_rsa_pri_decrypt(p_openssl_rsa_client, &i_rc4_R_miwen, &p_openssl_rc4_key->key_r);
			mm_openssl_rc4_key_unlock(p_openssl_rc4_key);
			mm_openssl_rsa_unlock(p_openssl_rsa_client);
			mm_string_destroy(&i_rc4_R_miwen);
			// can not decrypt, client private key invalid.
			if (0 > pri_decrypt_len)
			{
				mm_logger_log_E(g_logger, "%s %d can not decrypt, client private key invalid.", __FUNCTION__, __LINE__);
				break;
			}
			//��tcp ����Ϊp_openssl_tcp_context ����tcp �������ģ� ��סtcp�����൱����ס p_openssl_tcp_context
			mm_tcp_lock(p_tcp);
			//��װrc4 L����R�� ���һ�������� rc4 key			
			mm_openssl_rc4_key_lock(p_openssl_rc4_key);
			mm_openssl_rc4_key_assembly(p_openssl_rc4_key);
			//������������rc4 key ���õ�tcp���ӵ���
			mm_openssl_tcp_context_assign_key(p_openssl_tcp_context, (mm_uint8_t*)p_openssl_rc4_key->key.s, 0, p_openssl_rc4_key->key.l);
			mm_openssl_rc4_key_unlock(p_openssl_rc4_key);
			//tcp���� ����rc4�ӽ��� ��ǩ
			mm_openssl_tcp_context_assign_state(p_openssl_tcp_context, CRYPTO_CONTEXT_ACTIVATE);
			mm_tcp_unlock(p_tcp);

			//����������tcps ����״̬
			tcps->state = tcps_connect::tcps_state_finish;
			//////////////////////////////////////////////////////////////////////////
		}
	} while (0);
}

void hd_q_c_shuttle_lobby_exchange_key_rs(void* obj, void* u, struct mm_packet* pack)
{
	c_shuttle_lobby::exchange_key_rs msg_rs;
	struct mm_string proto_desc;
	b_error::info* error_info = msg_rs.mutable_error();

	struct mm_logger* g_logger = mm_logger_instance();
	struct mm_tcp* tcp = (struct mm_tcp*)(obj);
	mm::KO_dog* impl = (mm::KO_dog*)(u);

	////////////////////////////////
	mm_string_init(&proto_desc);	
	do
	{
		// �������
		if (0 != mm_protobuf_cxx_decode_message(pack, &msg_rs))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &msg_rs);
		mm_logger_log_I(g_logger, "%s %d %s", __FUNCTION__, __LINE__, proto_desc.s);
		//////////////////////////////////////////////////////////////////////////
		// �ذ��߼�����
		if (0 != error_info->code())
		{
			mm_logger_log_E(g_logger, "%s %d (%d)%s", __FUNCTION__, __LINE__, error_info->code(), error_info->desc().c_str());	
			
			//�������������������־    ��������  evt_ags
			mm::KO_dog_data_log_view* data_log_view = &impl->data.data_log_view;
			mm::mm_event_data_log_view evt_ags;
			evt_ags.code = error_info->code();
			evt_ags.desc = error_info->desc();
			evt_ags.view = data_log_view->code_map.get(evt_ags.code);
			data_log_view->d_event_set.fire_event(mm::KO_dog_data_log_view::event_log_view, evt_ags);
		}
		else
		{	
			//���ݸ���
			mm::KO_dog_data_net* p_data_net = &impl->data.data_net;
			struct KO_dog_network* network = &impl->network;
			struct tcps_connect* tcps = &network->tcps;
			mm::ip_port_state* p_lobby = &p_data_net->lobby;
			//���и��������߳���ɵ� tcps ״̬
			p_lobby->crypto_state = tcps->state;
			//�������и��� tcps ״̬ �¼�
			mm_event_args evt_ags;
			p_lobby->d_event_set.fire_event(mm::ip_port_state::event_crypto_update, evt_ags);
			//////////////////////////////////////////////////////////////////////////
		}
	} while (0);
}

