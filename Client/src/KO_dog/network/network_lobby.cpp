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
	//mm_client_tcp_assign_n_callback(&p->tcp, c_shuttle_lobby::token_verify_rs_msg_id, &hd_n_c_shuttle_lobby_token_verify_rs);
}

//udp/////////////////////////////////////////////////////////////////////////////////
void mm_client_tcp_flush_send_exchange_key_rq(struct mm_client_tcp* p)
{
	struct mm_logger* g_logger = mm_logger_instance();

	c_shuttle_lobby::exchange_key_rq msg_rq;
	mm::KO_dog* impl = (mm::KO_dog*)p->u;
	mm::KO_dog_data_net* p_data_net = &impl->data.data_net;
	mm::tcps_connect* p_tcps_connect = &p_data_net->lobby_tcps;
	struct mm_openssl_rsa* p_openssl_rsa_client = &p_tcps_connect->openssl_rsa_client;
	struct mm_openssl_rsa* p_openssl_rsa_server = &p_tcps_connect->openssl_rsa_server;
	struct mm_openssl_rc4* p_openssl_rc4 = &p_tcps_connect->openssl_rc4;
	struct mm_openssl_rc4_key* p_openssl_rc4_key = &p_tcps_connect->openssl_rc4_key;
	int pub_encrypt_len = 0;

	//产生 client rc4 L部分并且保存到 mm_openssl_rc4_key （R部分是由服务器rs回包过来的）
	mm_openssl_rc4_random_buffer(p_openssl_rc4, &p_openssl_rc4_key->key_l, KO_DOG_DATA_NET_RC4_LENGTH);
	//取出 msg_rq 的 成员 encrypt_key_l（rc4的L部的key放回server给的公钥箱子里面：使用公钥加密rc4的L部） 地址。以供修改使用
	std::string* p_encrypt_key_l = msg_rq.mutable_encrypt_key_l();
	//创建一个临时缓冲区用来承接 公钥加密rc4的L部 的内容（因为出参是C的API，不能进行类型匹配）
	struct mm_string output;
	mm_string_init(&output);
	// 用server rsa 公钥加密 rc4 L部
	pub_encrypt_len = mm_openssl_rsa_pub_encrypt(p_openssl_rsa_server, &p_openssl_rc4_key->key_l, &output);
	if (0 > pub_encrypt_len)
	{
		mm_logger_log_E(g_logger, "%s %d can not encrypt, server public key invalid.", __FUNCTION__, __LINE__);
	}
	else
	{
		//产生 client rsa 仅仅生成到ctx当中，并没有将公钥或者私钥提取到 p_openssl_rsa_client对象当中。
		mm_openssl_rsa_generate(p_openssl_rsa_client, KO_DOG_DATA_NET_RSA_LENGTH, RSA_3);
		//生成的 rsa 公钥 放入 mm_openssl_rsa当中
		mm_openssl_rsa_ctx_to_pub_mem(p_openssl_rsa_client);

		//获得 client rsa 公钥
		size_t openssl_rsa_pub_mem_size = mm_openssl_rsa_pub_mem_size(p_openssl_rsa_client);
		//取出 msg_rq 的 成员 public_key 地址。以供修改使用
		std::string* openssl_rsa_pub_mem = msg_rq.mutable_public_key();
		//给字符串预分配一个 openssl_rsa_pub_mem_size 长度的缓冲区
		openssl_rsa_pub_mem->resize(openssl_rsa_pub_mem_size);
		//把 client rsa 的公钥 对拷贝 预分配的缓冲区
		mm_openssl_rsa_pub_mem_get(p_openssl_rsa_client, (mm_uint8_t*)openssl_rsa_pub_mem->data(), 0, openssl_rsa_pub_mem_size);

		// 预分配承接对象
		p_encrypt_key_l->resize(output.l);
		//把 output 密文 对拷贝到 预分配的缓冲区（rq包内部 p_encrypt_key_l）
		mm_memcpy((char*)p_encrypt_key_l->data(), output.s, output.l);
		mm_string_destroy(&output);
		msg_rq.set_version(0);

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
		// 解包错误
		if (0 != mm_protobuf_cxx_decode_message(pack, &msg_rs))
		{
			mm_logger_log_E(g_logger, "%s %d mid:0x%08X message decode failure.", __FUNCTION__, __LINE__, pack->phead.mid);
			break;
		}
		// logger rq.
		mm_protobuf_cxx_logger_append_packet_message(&proto_desc, pack, &msg_rs);
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
			evt_ags.view = data_log_view->code_map.get(evt_ags.code);
			data_log_view->d_event_set.fire_event(mm::KO_dog_data_log_view::event_log_view, evt_ags);
		}
		else
		{	
			//数据更新
			mm::KO_dog_data_net* p_data_net = &impl->data.data_net;
			mm::tcps_connect* p_tcps_connect = &p_data_net->lobby_tcps;
			struct mm_openssl_rsa* p_openssl_rsa_client = &p_tcps_connect->openssl_rsa_client;
			struct mm_openssl_rsa* p_openssl_rsa_server = &p_tcps_connect->openssl_rsa_server;
			struct mm_openssl_rc4* p_openssl_rc4 = &p_tcps_connect->openssl_rc4;
			struct mm_openssl_rc4_key* p_openssl_rc4_key = &p_tcps_connect->openssl_rc4_key;
			int pri_decrypt_len = 0;

			//取出msg_rs rc4 R部 密文
			const std::string& rc4_R_miwen = msg_rs.encrypt_key_r();
			struct mm_string i_rc4_R_miwen;
			mm_string_init(&i_rc4_R_miwen);
			mm_string_resize(&i_rc4_R_miwen, rc4_R_miwen.size());
			mm_memcpy(i_rc4_R_miwen.s, (char*)rc4_R_miwen.data(), rc4_R_miwen.size());	
			//用client rsa 私钥解密rs返回的密文，输出 rs4 的R部
			pri_decrypt_len = mm_openssl_rsa_pri_decrypt(p_openssl_rsa_client, &i_rc4_R_miwen, &p_openssl_rc4_key->key_r);
			mm_string_destroy(&i_rc4_R_miwen);
			// can not decrypt, client private key invalid.
			if (0 > pri_decrypt_len)
			{
				mm_logger_log_E(g_logger, "%s %d can not decrypt, client private key invalid.", __FUNCTION__, __LINE__);
				break;
			}
			//组装rc4 L部和R部 变成一个完整的 rc4 key
			mm_openssl_rc4_key_assembly(p_openssl_rc4_key);
			struct KO_dog_network* p_dog_network = &impl->network;
			struct mm_openssl_tcp_context* p_openssl_tcp_context = &p_dog_network->openssl_tcp_context;
			//将生产的完整rc4 key 设置到tcp连接当中
			mm_openssl_tcp_context_assign_key(p_openssl_tcp_context, (mm_uint8_t*)p_openssl_rc4_key->key.s, 0, p_openssl_rc4_key->key.l);
			//tcp连接 激活rc4加解密 标签
			mm_openssl_tcp_context_assign_state(p_openssl_tcp_context, CRYPTO_CONTEXT_ACTIVATE);

			//数据更新以后的事件发布    发布内容  evt_ags
			p_tcps_connect->state = mm::tcps_connect::tcps_state_finish;
			mm_event_args evt_ags;
			p_data_net->d_event_set.fire_event(mm::KO_dog_data_net::event_tcps_state_change, evt_ags);
			//////////////////////////////////////////////////////////////////////////
		}

		//发布到界面视图log

	} while (0);
}

