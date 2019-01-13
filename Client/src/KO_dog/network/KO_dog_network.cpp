#include "KO_dog_network.h"
#include "net/mm_default_handle.h"
#include "network_entry.h"
#include "network_account.h"
#include "network_lobby.h"
#include "network_state.h"
#include "network_relation.h"

#include "application/KO_dog.h"

//////////////////////////////////////////////////////////////////////////
static void __static_KO_dog_network_msec_send_udp_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry);
//struct tcps_connect ///////////////////////////////////////////////////////////////////////////////////

void lobby_user_token_init(struct lobby_user_token* p)
{
	p->uid = 0;
	p->token = "";
	mm_spinlock_init(&p->locker, NULL);
	p->state = lobby_user_token::user_token_closed;
}
void lobby_user_token_destroy(struct lobby_user_token* p)
{
	p->uid = 0;
	p->token = "";
	mm_spinlock_destroy(&p->locker);
	p->state = lobby_user_token::user_token_closed;
}

void lobby_user_token_lock(struct lobby_user_token* p)
{
	mm_spinlock_lock(&p->locker);
}
void lobby_user_token_unlock(struct lobby_user_token* p)
{
	mm_spinlock_unlock(&p->locker);
}

void tcps_connect_init(struct tcps_connect *p)
{
	p->public_key = "";
	mm_openssl_rsa_init(&p->openssl_rsa_client);
	mm_openssl_rsa_init(&p->openssl_rsa_server);
	mm_openssl_rc4_init(&p->openssl_rc4);
	mm_openssl_tcp_context_init(&p->openssl_tcp_context);
	p->state = tcps_connect::tcps_state_closed;
	mm_openssl_rc4_srand(&p->openssl_rc4, (mm_uint64_t)time(NULL));
}

void tcps_connect_destroy(struct tcps_connect *p)
{
	p->public_key = "";
	mm_openssl_rsa_destroy(&p->openssl_rsa_client);
	mm_openssl_rsa_destroy(&p->openssl_rsa_server);
	mm_openssl_rc4_destroy(&p->openssl_rc4);
	mm_openssl_tcp_context_destroy(&p->openssl_tcp_context);
	p->state = tcps_connect::tcps_state_closed;
}

//////////////////////////////////////////////////////////////////////////


static void __static_net_tcp_handle_tcp_encrypt(void* p, void* e, mm_uint8_t* buffer_i, size_t offset_i, mm_uint8_t* buffer_o, size_t offset_o, size_t length);
static void __static_net_tcp_handle_tcp_decrypt(void* p, void* e, mm_uint8_t* buffer_i, size_t offset_i, mm_uint8_t* buffer_o, size_t offset_o, size_t length);

static void __static_net_udp_event_entry_socket_change_publishing(void* obj, void* u);

void KO_dog_network_init(struct KO_dog_network* p)
{
	mm_timer_init(&p->timer);
	mm_client_udp_init(&p->udp);
	mm_client_tcp_init(&p->tcp);
	tcps_connect_init(&p->tcps);
	lobby_user_token_init(&p->lobby_token);

	struct mm_client_udp_callback client_udp_callback;
	client_udp_callback.handle = &mm_client_udp_handle_default;
	client_udp_callback.obj = p;
	mm_client_udp_assign_q_default_callback(&p->udp, &client_udp_callback);
	mm_client_udp_assign_n_default_callback(&p->udp, &client_udp_callback);

	struct mm_client_tcp_callback client_tcp_callback;
	//δ����Ϣ�ŵ� ȱʡ������̣���Ҫ�и�������ʾ�� �����磬�������а���Ϣ���������Ϣ����ʱ�����û��mm_client_tcp_handle_default ����������󣬻���Ĭ�Ϻ������������κδ�����ʾ�������ڴ����֣�
	client_tcp_callback.handle = &mm_client_tcp_handle_default;
	client_tcp_callback.obj = p;
	//�����̵߳�ȱʡ������̣���δ����Ϣ�ŵ���Ϣ�ͻᴥ�����������̣�
	mm_client_tcp_assign_q_default_callback(&p->tcp, &client_tcp_callback);
	//�����̵߳�ȱʡ������̣���δ����Ϣ�ŵ���Ϣ�ͻᴥ�����������̣�
	mm_client_tcp_assign_n_default_callback(&p->tcp, &client_tcp_callback);


	//����һ���ӽ��ܺ����ص��������
	struct mm_crypto_callback client_tcp_crypto_callback;
	client_tcp_crypto_callback.encrypt = &__static_net_tcp_handle_tcp_encrypt;
	client_tcp_crypto_callback.decrypt = &__static_net_tcp_handle_tcp_decrypt;
	client_tcp_crypto_callback.obj = p;
	mm_client_tcp_assign_crypto_callback(&p->tcp, &client_tcp_crypto_callback);

	//��tcp���üӽ��������ľ��
	mm_client_tcp_set_addr_context(&p->tcp, &p->tcps.openssl_tcp_context);

	//ע��ģ����Ϣ�źʹ������ 
	network_state_callback_function_registration(p);
	network_entry_callback_function_registration(p);
	network_lobby_callback_function_registration(p);
	network_account_callback_function_registration(p);
	network_relation_callback_function_registration(p);
	//�ر�tcp udp �Զ������ظ�
	mm_client_udp_assign_state_check_flag(&p->udp, client_udp_check_inactive);
	mm_client_tcp_assign_state_check_flag(&p->tcp, client_tcp_check_inactive);

	//���ö�ʱ������tcp�Ͽ�״̬�£�1s ����һ�Σ�����ʱ����udp
	mm_timer_schedule(&p->timer, 5000, 5000, &__static_KO_dog_network_msec_send_udp_handle, p);
}
void KO_dog_network_destroy(struct KO_dog_network* p)
{
	lobby_user_token_destroy(&p->lobby_token);
	tcps_connect_destroy(&p->tcps);
	mm_client_tcp_destroy(&p->tcp);
	mm_client_udp_destroy(&p->udp);
	mm_timer_destroy(&p->timer);
}
//////////////////////////////////////////////////////////////////////////
void KO_dog_network_assign_context(struct KO_dog_network* p, void* u)
{
	//����������
	mm_client_udp_assign_context(&p->udp, u);
	mm_client_tcp_assign_context(&p->tcp, u);
}

void KO_dog_network_client_udp_assign_remote_target(struct KO_dog_network* p, const char* node, mm_ushort_t port)
{
	mm_client_udp_assign_remote(&p->udp, node, port);
	//״̬����߳� ����udp ��ǩ���ھ���״̬
	mm_client_udp_assign_state_check_flag(&p->udp, client_udp_check_activate);
	//�������߳����̼��������һ�μ��
	mm_client_udp_state_signal(&p->udp);
}
void KO_dog_network_client_tcp_assign_remote_target(struct KO_dog_network* p, const char* node, mm_ushort_t port)
{
	mm_client_tcp_assign_remote(&p->tcp, node, port);
	//״̬����߳� ����tcp ��ǩ���ھ���״̬
	mm_client_tcp_assign_state_check_flag(&p->tcp, client_tcp_check_activate);
	//�������߳����̼��������һ�μ��
	mm_client_tcp_state_signal(&p->tcp);
}

void KO_dog_network_thread_handle_recv(struct KO_dog_network* p)
{
	mm_client_udp_thread_handle_recv(&p->udp);
	mm_client_tcp_thread_handle_recv(&p->tcp);
}
//////////////////////////////////////////////////////////////////////////
// start wait thread.
void KO_dog_network_start(struct KO_dog_network* p)
{
	mm_timer_start(&p->timer);
	mm_client_udp_start(&p->udp);
	mm_client_tcp_start(&p->tcp);
}
// interrupt wait thread.
void KO_dog_network_interrupt(struct KO_dog_network* p)
{
	mm_timer_interrupt(&p->timer);
	mm_client_udp_interrupt(&p->udp);
	mm_client_tcp_interrupt(&p->tcp);
}
// shutdown wait thread.
void KO_dog_network_shutdown(struct KO_dog_network* p)
{
	mm_timer_shutdown(&p->timer);
	mm_client_udp_shutdown(&p->udp);
	mm_client_tcp_shutdown(&p->tcp);
}
// join wait thread.
void KO_dog_network_join(struct KO_dog_network* p)
{
	mm_timer_join(&p->timer);
	mm_client_udp_join(&p->udp);
	mm_client_tcp_join(&p->tcp);
}
//////////////////////////////////////////////////////////////////////////


//static tcp �ӽ��ܹ���
//buffer_i ���뻺��������ʼλ�ã�����ʵ��������ʼλ�� ,offset_i ʵ��������ʼλ�þ������뻺������ʼλ�õ�ƫ����
//buffer_o �������������ʼλ�ã�����ʵ��������ʼλ�� ,offset_o ʵ��������ʼλ�þ��������������ʼλ�õ�ƫ����
//length ���뻺�������������������Ч���ȣ�����������������Ϊ�Ǳ���һ�����ԳƼ��ܷ�����������ϸ����
static void __static_net_tcp_handle_tcp_encrypt(void* p, void* e, mm_uint8_t* buffer_i, size_t offset_i, mm_uint8_t* buffer_o, size_t offset_o, size_t length)
{
	// tcp ���ܹ���
	struct mm_tcp* tcp = (struct mm_tcp*)e;
	struct mm_openssl_tcp_context* tcp_context = (struct mm_openssl_tcp_context*) mm_tcp_get_context(tcp);
	if (CRYPTO_CONTEXT_ACTIVATE == tcp_context->state)
	{
		RC4(&tcp_context->context_send, length,(const unsigned char *)(buffer_i+ offset_i),(unsigned char *)(buffer_o+ offset_o));
	}
}
//static tcp �ӽ��ܹ���
//buffer_i ���뻺��������ʼλ�ã�����ʵ��������ʼλ�� ,offset_i ʵ��������ʼλ�þ������뻺������ʼλ�õ�ƫ����
//buffer_o �������������ʼλ�ã�����ʵ��������ʼλ�� ,offset_o ʵ��������ʼλ�þ��������������ʼλ�õ�ƫ����
//length ���뻺�������������������Ч���ȣ�����������������Ϊ�Ǳ���һ�����ԳƼ��ܷ�����������ϸ����
static void __static_net_tcp_handle_tcp_decrypt(void* p, void* e, mm_uint8_t* buffer_i, size_t offset_i, mm_uint8_t* buffer_o, size_t offset_o, size_t length)
{
	// tcp ���ܹ���
	struct mm_tcp* tcp = (struct mm_tcp*)e;
	struct mm_openssl_tcp_context* tcp_context = (struct mm_openssl_tcp_context*) mm_tcp_get_context(tcp);
	if (CRYPTO_CONTEXT_ACTIVATE == tcp_context->state)
	{
		RC4(&tcp_context->context_recv, length, (const unsigned char *)(buffer_i + offset_i), (unsigned char *)(buffer_o + offset_o));
	}

}

static void __static_KO_dog_network_msec_send_udp_handle(struct mm_timer_heap* timer_heap, struct mm_timer_entry* entry)
{
	struct KO_dog_network* p = (struct KO_dog_network*)(entry->callback.obj);
	int tcp_state = mm_client_tcp_finally_state(&p->tcp);
	int udp_state = mm_client_udp_finally_state(&p->udp);
	if (0 != tcp_state && 0 == udp_state)
	{
		struct mm_logger* g_logger = mm_logger_instance();
		mm_client_udp_flush_send_knock_rq(&p->udp);
		mm_logger_log_T(g_logger, "%s %d", __FUNCTION__, __LINE__);
	}
}
