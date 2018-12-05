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
	//未绑定消息号的 缺省处理过程，需要有个错误提示。 （例如，不在下列绑定消息号里面的消息到达时，如果没有mm_client_tcp_handle_default 函数输出错误，回走默认函数，不会有任何错误提示，不利于错误发现）
	client_tcp_callback.handle = &mm_client_tcp_handle_default;
	client_tcp_callback.obj = p;
	//队列线程的缺省处理过程，（未绑定消息号的消息就会触发这个处理过程）
	mm_client_tcp_assign_q_default_callback(&p->tcp, &client_tcp_callback);
	//网络线程的缺省处理过程，（未绑定消息号的消息就会触发这个处理过程）
	mm_client_tcp_assign_n_default_callback(&p->tcp, &client_tcp_callback);
	mm_client_tcp_assign_n_callback(&p->tcp, tcp_mid_broken, &__static_net_tcp_handle_tcp_mid_broken_n);
	mm_client_tcp_assign_n_callback(&p->tcp, tcp_mid_nready, &__static_net_tcp_handle_tcp_mid_nready_n);
	mm_client_tcp_assign_n_callback(&p->tcp, tcp_mid_finish, &__static_net_tcp_handle_tcp_mid_finish_n);

	mm_client_tcp_assign_q_callback(&p->tcp, tcp_mid_broken, &__static_net_tcp_handle_tcp_mid_broken_q);
	mm_client_tcp_assign_q_callback(&p->tcp, tcp_mid_nready, &__static_net_tcp_handle_tcp_mid_nready_q);
	mm_client_tcp_assign_q_callback(&p->tcp, tcp_mid_finish, &__static_net_tcp_handle_tcp_mid_finish_q);

	//设置一个加解密函数回调处理过程
	struct mm_crypto_callback client_tcp_crypto_callback;
	client_tcp_crypto_callback.encrypt = &__static_net_tcp_handle_tcp_encrypt;
	client_tcp_crypto_callback.decrypt = &__static_net_tcp_handle_tcp_decrypt;
	client_tcp_crypto_callback.obj = p;
	mm_client_tcp_assign_crypto_callback(&p->tcp, &client_tcp_crypto_callback);

	//给tcp设置加解密上下文句柄
	mm_client_tcp_set_addr_context(&p->tcp, &p->openssl_tcp_context);

	//注册模块消息号和处理过程 
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

////////////////////////////////////////////////////////////////////////////
//static udp
static void __static_net_udp_event_entry_socket_change_publishing(void* obj, void* u)
{
	struct mm_udp* udp = (struct mm_udp*)(obj);
	struct mm_net_udp* net_udp = (struct mm_net_udp*)(udp->callback.obj);

	//数据更新以后的事件发布    发布内容  evt_ags
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

	//数据更新以后的事件发布    发布内容  evt_ags
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	mm::KO_dog_data_net* data_net = &impl->data.data_net;
	data_net->lobby.socket_state = net_tcp->tcp_state;

	mm_event_args evt_ags;
	data_net->d_event_set.fire_event(mm::KO_dog_data_net::event_lobby_socket_change, evt_ags);
}

static void __static_net_udp_handle_udp_mid_broken_n(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp 网络线程触发
	__static_net_udp_event_entry_socket_change_publishing(obj, u);
}
static void __static_net_udp_handle_udp_mid_nready_n(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp 网络线程触发
	__static_net_udp_event_entry_socket_change_publishing(obj, u);
}
static void __static_net_udp_handle_udp_mid_finish_n(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp 网络线程触发
	__static_net_udp_event_entry_socket_change_publishing(obj, u);	

	// udp 连接完成后发送一次udp业务：获取大厅IP信息  knock_rq 请求
	struct mm_udp* udp = (struct mm_udp*)(obj);
	struct mm_net_udp* net_udp = (struct mm_net_udp*)(udp->callback.obj);
	struct mm_client_udp* client_udp = (struct mm_client_udp*)(net_udp->callback.obj);
	mm_client_udp_flush_send_knock_rq(client_udp);
}

static void __static_net_udp_handle_udp_mid_broken_q(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp 网络线程触发
	__static_net_udp_event_entry_socket_change_publishing(obj, u);
}
static void __static_net_udp_handle_udp_mid_nready_q(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp 队列线程触发

	__static_net_udp_event_entry_socket_change_publishing(obj, u);
}
static void __static_net_udp_handle_udp_mid_finish_q(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote)
{
	// udp 队列线程触发
	__static_net_udp_event_entry_socket_change_publishing(obj, u);

}
//////////////////////////////////////////////////////////////////////////
//static tcp
static void __static_net_tcp_handle_tcp_mid_broken_n(void* obj, void* u, struct mm_packet* pack)
{
	// tcp 网络线程触发
	__static_net_tcp_event_lobby_socket_change_publishing(obj,u);

	// tcp连接断开后 再做一次 udp业务请求： 获取大厅IP信息  knock_rq 请求
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	mm_client_udp_flush_send_knock_rq(&impl->network.udp);
}
static void __static_net_tcp_handle_tcp_mid_nready_n(void* obj, void* u, struct mm_packet* pack)
{
	// tcp 网络线程触发

	__static_net_tcp_event_lobby_socket_change_publishing(obj, u);
}
static void __static_net_tcp_handle_tcp_mid_finish_n(void* obj, void* u, struct mm_packet* pack)
{
	// tcp 网络线程触发
	__static_net_tcp_event_lobby_socket_change_publishing(obj, u);
	// tcp 连接完成后；立即请求交换 秘钥
	mm::KO_dog* impl = (mm::KO_dog*)(u);
	mm_client_tcp_flush_send_exchange_key_rq(&impl->network.tcp);
}

static void __static_net_tcp_handle_tcp_mid_broken_q(void* obj, void* u, struct mm_packet* pack)
{
	// tcp 队列线程触发
	__static_net_tcp_event_lobby_socket_change_publishing(obj, u);
}
static void __static_net_tcp_handle_tcp_mid_nready_q(void* obj, void* u, struct mm_packet* pack)
{
	// tcp 队列线程触发

	__static_net_tcp_event_lobby_socket_change_publishing(obj, u);
}
static void __static_net_tcp_handle_tcp_mid_finish_q(void* obj, void* u, struct mm_packet* pack)
{
	// tcp 队列线程触发
	__static_net_tcp_event_lobby_socket_change_publishing(obj, u);
}

//static tcp 加解密过程
//buffer_i 输入缓冲区的起始位置，不是实际流的起始位置 ,offset_i 实际流的起始位置距离输入缓冲区起始位置的偏移量
//buffer_o 输出缓冲区的起始位置，不是实际流的起始位置 ,offset_o 实际流的起始位置距离输出缓冲区起始位置的偏移量
//length 输入缓冲区和输出缓冲区的有效长度，不分输入和输出，因为是必须一样，对称加密符合输入输出严格相等
static void __static_net_tcp_handle_tcp_encrypt(void* p, void* e, mm_uint8_t* buffer_i, size_t offset_i, mm_uint8_t* buffer_o, size_t offset_o, size_t length)
{
	// tcp 加密过程
	struct mm_tcp* tcp = (struct mm_tcp*)e;
	struct mm_openssl_tcp_context* tcp_context = (struct mm_openssl_tcp_context*) mm_tcp_get_context(tcp);
	if (CRYPTO_CONTEXT_ACTIVATE == tcp_context->state)
	{
		RC4(&tcp_context->context_send, length,(const unsigned char *)(buffer_i+ offset_i),(unsigned char *)(buffer_o+ offset_o));
	}
}
//static tcp 加解密过程
//buffer_i 输入缓冲区的起始位置，不是实际流的起始位置 ,offset_i 实际流的起始位置距离输入缓冲区起始位置的偏移量
//buffer_o 输出缓冲区的起始位置，不是实际流的起始位置 ,offset_o 实际流的起始位置距离输出缓冲区起始位置的偏移量
//length 输入缓冲区和输出缓冲区的有效长度，不分输入和输出，因为是必须一样，对称加密符合输入输出严格相等
static void __static_net_tcp_handle_tcp_decrypt(void* p, void* e, mm_uint8_t* buffer_i, size_t offset_i, mm_uint8_t* buffer_o, size_t offset_o, size_t length)
{
	// tcp 解密过程
	struct mm_tcp* tcp = (struct mm_tcp*)e;
	struct mm_openssl_tcp_context* tcp_context = (struct mm_openssl_tcp_context*) mm_tcp_get_context(tcp);
	if (CRYPTO_CONTEXT_ACTIVATE == tcp_context->state)
	{
		RC4(&tcp_context->context_recv, length, (const unsigned char *)(buffer_i + offset_i), (unsigned char *)(buffer_o + offset_o));
	}

}


