#include "KO_dog_network.h"
#include "net/mm_default_handle.h"
#include "network_entry.h"
#include "network_account.h"
#include "network_lobby.h"
#include "application/KO_dog.h"

//////////////////////////////////////////////////////////////////////////
static void __static_net_udp_handle_udp_mid_broken_n(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote);
static void __static_net_udp_handle_udp_mid_nready_n(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote);
static void __static_net_udp_handle_udp_mid_finish_n(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote);

static void __static_net_udp_handle_udp_mid_broken_q(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote);
static void __static_net_udp_handle_udp_mid_nready_q(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote);
static void __static_net_udp_handle_udp_mid_finish_q(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote);

static void __static_net_tcp_handle_tcp_mid_broken_n(void* obj, void* u, struct mm_packet* pack);
static void __static_net_tcp_handle_tcp_mid_nready_n(void* obj, void* u, struct mm_packet* pack);
static void __static_net_tcp_handle_tcp_mid_finish_n(void* obj, void* u, struct mm_packet* pack);

static void __static_net_tcp_handle_tcp_mid_broken_q(void* obj, void* u, struct mm_packet* pack);
static void __static_net_tcp_handle_tcp_mid_nready_q(void* obj, void* u, struct mm_packet* pack);
static void __static_net_tcp_handle_tcp_mid_finish_q(void* obj, void* u, struct mm_packet* pack);

static void __static_net_tcp_handle_tcp_encrypt(void* p, void* e, mm_uint8_t* buffer_i, size_t offset_i, mm_uint8_t* buffer_o, size_t offset_o, size_t length);
static void __static_net_tcp_handle_tcp_decrypt(void* p, void* e, mm_uint8_t* buffer_i, size_t offset_i, mm_uint8_t* buffer_o, size_t offset_o, size_t length);

static void __static_net_udp_event_entry_socket_change_publishing(void* obj, void* u);

void KO_dog_network_init(struct KO_dog_network* p)
{
	mm_client_tcp_init(&p->tcp);
	mm_client_udp_init(&p->udp);
	struct mm_client_udp_callback client_udp_callback;
	client_udp_callback.handle = &mm_client_udp_handle_default;
	client_udp_callback.obj = p;
	mm_client_udp_assign_q_default_callback(&p->udp, &client_udp_callback);
	mm_client_udp_assign_n_default_callback(&p->udp, &client_udp_callback);


	mm_client_udp_assign_n_callback(&p->udp, udp_mid_broken, &__static_net_udp_handle_udp_mid_broken_n);
	mm_client_udp_assign_n_callback(&p->udp, udp_mid_nready, &__static_net_udp_handle_udp_mid_nready_n);
	mm_client_udp_assign_n_callback(&p->udp, udp_mid_finish, &__static_net_udp_handle_udp_mid_finish_n);

	mm_client_udp_assign_q_callback(&p->udp, udp_mid_broken, &__static_net_udp_handle_udp_mid_broken_q);
	mm_client_udp_assign_q_callback(&p->udp, udp_mid_nready, &__static_net_udp_handle_udp_mid_nready_q);
	mm_client_udp_assign_q_callback(&p->udp, udp_mid_finish, &__static_net_udp_handle_udp_mid_finish_q);


	struct mm_client_tcp_callback client_tcp_callback;
	//δ����Ϣ�ŵ� ȱʡ������̣���Ҫ�и�������ʾ�� �����磬�������а���Ϣ���������Ϣ����ʱ�����û��mm_client_tcp_handle_default ����������󣬻���Ĭ�Ϻ������������κδ�����ʾ�������ڴ����֣�
	client_tcp_callback.handle = &mm_client_tcp_handle_default;
	client_tcp_callback.obj = p;
	//�����̵߳�ȱʡ������̣���δ����Ϣ�ŵ���Ϣ�ͻᴥ�����������̣�
	mm_client_tcp_assign_q_default_callback(&p->tcp, &client_tcp_callback);
	//�����̵߳�ȱʡ������̣���δ����Ϣ�ŵ���Ϣ�ͻᴥ�����������̣�
	mm_client_tcp_assign_n_default_callback(&p->tcp, &client_tcp_callback);
	mm_client_tcp_assign_n_callback(&p->tcp, tcp_mid_broken, &__static_net_tcp_handle_tcp_mid_broken_n);
	mm_client_tcp_assign_n_callback(&p->tcp, tcp_mid_nready, &__static_net_tcp_handle_tcp_mid_nready_n);
	mm_client_tcp_assign_n_callback(&p->tcp, tcp_mid_finish, &__static_net_tcp_handle_tcp_mid_finish_n);

	mm_client_tcp_assign_q_callback(&p->tcp, tcp_mid_broken, &__static_net_tcp_handle_tcp_mid_broken_q);
	mm_client_tcp_assign_q_callback(&p->tcp, tcp_mid_nready, &__static_net_tcp_handle_tcp_mid_nready_q);
	mm_client_tcp_assign_q_callback(&p->tcp, tcp_mid_finish, &__static_net_tcp_handle_tcp_mid_finish_q);

	//����һ���ӽ��ܺ����ص��������
	struct mm_crypto_callback client_tcp_crypto_callback;
	client_tcp_crypto_callback.encrypt = &__static_net_tcp_handle_tcp_encrypt;
	client_tcp_crypto_callback.decrypt = &__static_net_tcp_handle_tcp_decrypt;
	client_tcp_crypto_callback.obj = p;
	mm_client_tcp_assign_crypto_callback(&p->tcp, &client_tcp_crypto_callback);

	//��tcp���üӽ��������ľ��
	mm_client_tcp_set_addr_context(&p->tcp, &p->openssl_tcp_context);

	//ע��ģ����Ϣ�źʹ������ 
	network_entry_callback_function_registration(p);
	network_lobby_callback_function_registration(p);
	network_account_callback_function_registration(p);
	//
	mm_openssl_tcp_context_init(&p->openssl_tcp_context);
}
void KO_dog_network_destroy(struct KO_dog_network* p)
{
	mm_openssl_tcp_context_destroy(&p->openssl_tcp_context);
	mm_client_tcp_destroy(&p->tcp);
	mm_client_udp_destroy(&p->udp);
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
	mm_client_udp_assign_remote_target(&p->udp, node, port);
	//״̬����߳� ����udp ��ǩ���ھ���״̬
	mm_client_udp_assign_state_check_flag(&p->udp, client_udp_check_activate);
	//�������߳����̼��������һ�μ��
	mm_client_udp_state_signal(&p->udp);
}
void KO_dog_network_client_tcp_assign_remote_target(struct KO_dog_network* p, const char* node, mm_ushort_t port)
{
	mm_client_tcp_assign_remote_target(&p->tcp, node, port);
	//״̬����߳� ����tcp ��ǩ���ھ���״̬
	mm_client_tcp_assign_state_check_flag(&p->tcp, client_tcp_check_activate);
	//�������߳����̼��������һ�μ��
	mm_client_tcp_state_signal(&p->tcp);
}

void KO_dog_network_thread_handle_recv(struct KO_dog_network* p)
{
	mm_client_tcp_thread_handle_recv(&p->tcp);
	mm_client_udp_thread_handle_recv(&p->udp);
}
//////////////////////////////////////////////////////////////////////////
// start wait thread.
void KO_dog_network_start(struct KO_dog_network* p)
{
	mm_client_tcp_start(&p->tcp);
	mm_client_udp_start(&p->udp);
}
// interrupt wait thread.
void KO_dog_network_interrupt(struct KO_dog_network* p)
{
	mm_client_tcp_interrupt(&p->tcp);
	mm_client_udp_interrupt(&p->udp);
}
// shutdown wait thread.
void KO_dog_network_shutdown(struct KO_dog_network* p)
{
	mm_client_tcp_shutdown(&p->tcp);
	mm_client_udp_shutdown(&p->udp);
}
// join wait thread.
void KO_dog_network_join(struct KO_dog_network* p)
{
	mm_client_tcp_join(&p->tcp);
	mm_client_udp_join(&p->udp);
}
//////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
//static udp
static void __static_net_udp_event_entry_socket_change_publishing(void* obj, void* u)
{
	struct mm_udp* udp = (struct mm_udp*)(obj);
	struct mm_net_udp* net_udp = (struct mm_net_udp*)(udp->callback.obj);

	//���ݸ����Ժ���¼�����    ��������  evt_ags
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	mm::KO_dog_data_net* data_net = &impl->data.data_net;
	data_net->entry.socket_state = net_udp->udp_state;

	mm_event_args evt_ags;
	data_net->d_event_set.fire_event(mm::KO_dog_data_net::event_entry_socket_change, evt_ags);
}
static void __static_net_tcp_event_lobby_socket_change_publishing(void* obj, void* u)
{
	struct mm_udp* tcp = (struct mm_udp*)(obj);
	struct mm_net_tcp* net_tcp = (struct mm_net_tcp*)(tcp->callback.obj);

	//���ݸ����Ժ���¼�����    ��������  evt_ags
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	mm::KO_dog_data_net* data_net = &impl->data.data_net;
	data_net->lobby.socket_state = net_tcp->tcp_state;

	mm_event_args evt_ags;
	data_net->d_event_set.fire_event(mm::KO_dog_data_net::event_lobby_socket_change, evt_ags);
}

static void __static_net_udp_handle_udp_mid_broken_n(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp �����̴߳���
	__static_net_udp_event_entry_socket_change_publishing(obj, u);
}
static void __static_net_udp_handle_udp_mid_nready_n(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp �����̴߳���
	__static_net_udp_event_entry_socket_change_publishing(obj, u);
}
static void __static_net_udp_handle_udp_mid_finish_n(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp �����̴߳���
	__static_net_udp_event_entry_socket_change_publishing(obj, u);	

	// udp ������ɺ���һ��udpҵ�񣺻�ȡ����IP��Ϣ  knock_rq ����
	struct mm_udp* udp = (struct mm_udp*)(obj);
	struct mm_net_udp* net_udp = (struct mm_net_udp*)(udp->callback.obj);
	struct mm_client_udp* client_udp = (struct mm_client_udp*)(net_udp->callback.obj);
	mm_client_udp_flush_send_knock_rq(client_udp);
}

static void __static_net_udp_handle_udp_mid_broken_q(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp �����̴߳���
	__static_net_udp_event_entry_socket_change_publishing(obj, u);
}
static void __static_net_udp_handle_udp_mid_nready_q(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp �����̴߳���

	__static_net_udp_event_entry_socket_change_publishing(obj, u);
}
static void __static_net_udp_handle_udp_mid_finish_q(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp �����̴߳���
	__static_net_udp_event_entry_socket_change_publishing(obj, u);

}
//////////////////////////////////////////////////////////////////////////
//static tcp
static void __static_net_tcp_handle_tcp_mid_broken_n(void* obj, void* u, struct mm_packet* pack)
{
	// tcp �����̴߳���
	__static_net_tcp_event_lobby_socket_change_publishing(obj,u);

	// tcp���ӶϿ��� ����һ�� udpҵ������ ��ȡ����IP��Ϣ  knock_rq ����
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	mm_client_udp_flush_send_knock_rq(&impl->network.udp);
}
static void __static_net_tcp_handle_tcp_mid_nready_n(void* obj, void* u, struct mm_packet* pack)
{
	// tcp �����̴߳���

	__static_net_tcp_event_lobby_socket_change_publishing(obj, u);
}
static void __static_net_tcp_handle_tcp_mid_finish_n(void* obj, void* u, struct mm_packet* pack)
{
	// tcp �����̴߳���
	__static_net_tcp_event_lobby_socket_change_publishing(obj, u);
	// tcp ������ɺ��������󽻻� ��Կ
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	mm_client_tcp_flush_send_exchange_key_rq(&impl->network.tcp);
}

static void __static_net_tcp_handle_tcp_mid_broken_q(void* obj, void* u, struct mm_packet* pack)
{
	// tcp �����̴߳���
	__static_net_tcp_event_lobby_socket_change_publishing(obj, u);
}
static void __static_net_tcp_handle_tcp_mid_nready_q(void* obj, void* u, struct mm_packet* pack)
{
	// tcp �����̴߳���

	__static_net_tcp_event_lobby_socket_change_publishing(obj, u);
}
static void __static_net_tcp_handle_tcp_mid_finish_q(void* obj, void* u, struct mm_packet* pack)
{
	// tcp �����̴߳���
	__static_net_tcp_event_lobby_socket_change_publishing(obj, u);
}

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


