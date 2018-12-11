#include "network_state.h"

#include "application/KO_dog.h"
#include "network_entry.h"
#include "network_lobby.h"

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


void network_state_callback_function_registration(struct KO_dog_network* p)
{
	//client_udp
	mm_client_udp_assign_n_callback(&p->udp, udp_mid_broken, &__static_net_udp_handle_udp_mid_broken_n);
	mm_client_udp_assign_n_callback(&p->udp, udp_mid_nready, &__static_net_udp_handle_udp_mid_nready_n);
	mm_client_udp_assign_n_callback(&p->udp, udp_mid_finish, &__static_net_udp_handle_udp_mid_finish_n);

	mm_client_udp_assign_q_callback(&p->udp, udp_mid_broken, &__static_net_udp_handle_udp_mid_broken_q);
	mm_client_udp_assign_q_callback(&p->udp, udp_mid_nready, &__static_net_udp_handle_udp_mid_nready_q);
	mm_client_udp_assign_q_callback(&p->udp, udp_mid_finish, &__static_net_udp_handle_udp_mid_finish_q);


	//client_tcp
	mm_client_tcp_assign_n_callback(&p->tcp, tcp_mid_broken, &__static_net_tcp_handle_tcp_mid_broken_n);
	mm_client_tcp_assign_n_callback(&p->tcp, tcp_mid_nready, &__static_net_tcp_handle_tcp_mid_nready_n);
	mm_client_tcp_assign_n_callback(&p->tcp, tcp_mid_finish, &__static_net_tcp_handle_tcp_mid_finish_n);

	mm_client_tcp_assign_q_callback(&p->tcp, tcp_mid_broken, &__static_net_tcp_handle_tcp_mid_broken_q);
	mm_client_tcp_assign_q_callback(&p->tcp, tcp_mid_nready, &__static_net_tcp_handle_tcp_mid_nready_q);
	mm_client_tcp_assign_q_callback(&p->tcp, tcp_mid_finish, &__static_net_tcp_handle_tcp_mid_finish_q);
}

void network_state_entry_event_publish(struct KO_dog_network* p, const char* ip, unsigned short port)
{

	mm::KO_dog* impl = (mm::KO_dog*)(p->udp.u);
	//���ݸ���
	mm::KO_dog_data_net* data_net = &impl->data.data_net;
	mm::ip_port_state* p_entry = &data_net->entry;
	p_entry->ip = ip;
	p_entry->port = port;
	//
	//���ݸ����Ժ���¼�����    ��������  evt_ags
	mm_event_args evt_ags;
	p_entry->d_event_set.fire_event(mm::ip_port_state::event_ip_port_update, evt_ags);
}
void network_state_lobby_event_publish(struct KO_dog_network* p, const char* ip, unsigned short port)
{
	mm::KO_dog* impl = (mm::KO_dog*)(p->tcp.u);
	//���ݸ���
	mm::KO_dog_data_net* data_net = &impl->data.data_net;
	mm::ip_port_state* p_lobby = &data_net->lobby;
	p_lobby->ip = ip;
	p_lobby->port = port;
	//
	//���ݸ����Ժ���¼�����    ��������  evt_ags
	mm_event_args evt_ags;
	p_lobby->d_event_set.fire_event(mm::ip_port_state::event_ip_port_update, evt_ags);

}




////////////////////////////////////////////////////////////////////////////
//static udp
static void __static_net_udp_event_entry_socket_change_publishing(void* obj, void* u)
{
	struct mm_udp* udp = (struct mm_udp*)(obj);
	struct mm_net_udp* net_udp = (struct mm_net_udp*)(udp->callback.obj);

	//���ݸ����Ժ���¼�����    ��������  evt_ags
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	mm::KO_dog_data_net* data_net = &impl->data.data_net;
	mm::ip_port_state* p_entry = &data_net->entry;
	p_entry->socket_state = net_udp->udp_state;
	mm_event_args evt_ags;
	p_entry->d_event_set.fire_event(mm::ip_port_state::event_socket_update, evt_ags);
}
static void __static_net_tcp_event_lobby_socket_change_publishing(void* obj, void* u)
{
	struct mm_udp* tcp = (struct mm_udp*)(obj);
	struct mm_net_tcp* net_tcp = (struct mm_net_tcp*)(tcp->callback.obj);

	//���ݸ����Ժ���¼�����    ��������  evt_ags
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	mm::KO_dog_data_net* data_net = &impl->data.data_net;
	mm::ip_port_state* p_lobby = &data_net->lobby;
	p_lobby->socket_state = net_tcp->tcp_state;
	mm_event_args evt_ags;
	p_lobby->d_event_set.fire_event(mm::ip_port_state::event_socket_update, evt_ags);
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
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	KO_dog_network* p_network = &impl->network;
	struct tcps_connect* p_tcps_connect = &p_network->tcps;
	struct mm_tcp* p_tcp = &p_network->tcp.net_tcp.tcp;
	struct tcps_connect* tcps = &p_network->tcps;
	struct mm_openssl_tcp_context* p_openssl_tcp_context = &tcps->openssl_tcp_context;

	//��� lobby��Կ
	p_tcps_connect->public_key.clear();
	//��� network tcps state , ���±�Ϊ�ر�
	p_tcps_connect->state = tcps_connect::tcps_state_closed;
	//�ԳƼ��� ״̬ȡ��
	mm_tcp_lock(p_tcp);
	mm_openssl_tcp_context_assign_state(p_openssl_tcp_context, CRYPTO_CONTEXT_INACTIVE);
	mm_tcp_unlock(p_tcp);

	//�ر�tcp �Զ�����
	mm_client_tcp_assign_state_check_flag(&p_network->tcp, client_tcp_check_inactive);
	// tcp���ӶϿ��� ����һ�� udpҵ������ ��ȡ����IP��Ϣ  knock_rq ����
	mm_client_udp_flush_send_knock_rq(&impl->network.udp);
}
static void __static_net_tcp_handle_tcp_mid_nready_n(void* obj, void* u, struct mm_packet* pack)
{
	// tcp �����̴߳���
}
static void __static_net_tcp_handle_tcp_mid_finish_n(void* obj, void* u, struct mm_packet* pack)
{
	// tcp �����̴߳���
	// tcp ������ɺ��������󽻻� ��Կ
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	mm_client_tcp_flush_send_exchange_key_rq(&impl->network.tcp);
}

static void __static_net_tcp_handle_tcp_mid_broken_q(void* obj, void* u, struct mm_packet* pack)
{
	// tcp �����̴߳���
	mm::KO_dog* impl = (mm::KO_dog*)(u);

	// ����״̬��� �¼��ַ�
	__static_net_tcp_event_lobby_socket_change_publishing(obj, u);

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
