#include "KO_dog_network.h"
#include "net/mm_default_handle.h"
#include "network_entry.h"

//////////////////////////////////////////////////////////////////////////
static void __static_net_udp_handle_udp_mid_broken_n(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote);
static void __static_net_udp_handle_udp_mid_nready_n(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote);
static void __static_net_udp_handle_udp_mid_finish_n(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote);

static void __static_net_udp_handle_udp_mid_broken_q(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote);
static void __static_net_udp_handle_udp_mid_nready_q(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote);
static void __static_net_udp_handle_udp_mid_finish_q(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote);


void KO_dog_network_init(struct KO_dog_network* p)
{
	mm_client_tcp_init(&p->tcp);
	mm_client_udp_init(&p->udp);
	struct mm_packet_queue_callback packet_queue_callback;
	struct mm_client_udp_callback client_udp_callback;
	packet_queue_callback.handle = &mm_packet_queue_handle_default;
	packet_queue_callback.obj = p;
	client_udp_callback.handle = &mm_client_udp_handle_default;
	client_udp_callback.obj = p;
	mm_client_udp_assign_q_default_callback(&p->udp, &packet_queue_callback);
	mm_client_udp_assign_n_default_callback(&p->udp, &client_udp_callback);


	mm_client_udp_assign_n_callback(&p->udp, udp_mid_broken, &__static_net_udp_handle_udp_mid_broken_n);
	mm_client_udp_assign_n_callback(&p->udp, udp_mid_nready, &__static_net_udp_handle_udp_mid_nready_n);
	mm_client_udp_assign_n_callback(&p->udp, udp_mid_finish, &__static_net_udp_handle_udp_mid_finish_n);

	mm_client_udp_assign_q_callback(&p->udp, udp_mid_broken, &__static_net_udp_handle_udp_mid_broken_q);
	mm_client_udp_assign_q_callback(&p->udp, udp_mid_nready, &__static_net_udp_handle_udp_mid_nready_q);
	mm_client_udp_assign_q_callback(&p->udp, udp_mid_finish, &__static_net_udp_handle_udp_mid_finish_q);

	network_entry_callback_function_registration(p);

}
void KO_dog_network_destroy(struct KO_dog_network* p)
{
	mm_client_tcp_destroy(&p->tcp);
	mm_client_udp_destroy(&p->udp);
}
//////////////////////////////////////////////////////////////////////////
void KO_dog_network_assign_context(struct KO_dog_network* p, void* u)
{
	//传入上下文
	mm_client_udp_assign_context(&p->udp, u);
	mm_client_tcp_assign_context(&p->tcp, u);
}

void KO_dog_network_client_udp_assign_remote_target(struct KO_dog_network* p, const char* node, mm_ushort_t port)
{
	mm_client_udp_assign_remote_target(&p->udp, node, port);
	//状态监测线程 设置udp 标签处于就绪状态
	mm_client_udp_assign_state_check_flag(&p->udp, client_udp_check_activate);
	//让网络线程立刻激活，并且做一次检测
	mm_client_udp_state_signal(&p->udp);
}
void KO_dog_network_client_tcp_assign_remote_target(struct KO_dog_network* p, const char* node, mm_ushort_t port)
{
	mm_client_tcp_assign_remote_target(&p->tcp, node, port);
	//状态监测线程 设置tcp 标签处于就绪状态
	mm_client_tcp_assign_state_check_flag(&p->tcp, client_tcp_check_activate);
	//让网络线程立刻激活，并且做一次检测
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
//static
static void __static_net_udp_handle_udp_mid_broken_n(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp 网络线程触发
}
static void __static_net_udp_handle_udp_mid_nready_n(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp 网络线程触发
}
static void __static_net_udp_handle_udp_mid_finish_n(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp 网络线程触发
	struct mm_udp* udp = (struct mm_udp*)(obj);
	struct mm_net_udp* net_udp = (struct mm_net_udp*)(udp->callback.obj);
	struct mm_client_udp* client_udp = (struct mm_client_udp*)(net_udp->callback.obj);

	mm_client_udp_flush_send_knock_rq_msg_id(client_udp);
}

static void __static_net_udp_handle_udp_mid_broken_q(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp 队列线程触发
}
static void __static_net_udp_handle_udp_mid_nready_q(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp 队列线程触发
}
static void __static_net_udp_handle_udp_mid_finish_q(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp 队列线程触发
}
