#ifndef __KO_dog_network_h__
#define __KO_dog_network_h__

#include "net/mm_client_tcp.h"
#include "net/mm_client_udp.h"

struct KO_dog_network
{
	struct mm_client_tcp tcp;
	struct mm_client_udp udp;
};

//////////////////////////////////////////////////////////////////////////
extern void KO_dog_network_init(struct KO_dog_network* p);
extern void KO_dog_network_destroy(struct KO_dog_network* p);
//////////////////////////////////////////////////////////////////////////
extern void KO_dog_network_assign_context(struct KO_dog_network* p, void* u);
extern void KO_dog_network_client_udp_assign_remote_target(struct KO_dog_network* p, const char* node, mm_ushort_t port);
extern void KO_dog_network_client_tcp_assign_remote_target(struct KO_dog_network* p, const char* node, mm_ushort_t port);

//////////////////////////////////////////////////////////////////////////
//主线程（渲染线程）update 需要调用          ----------功能：把网络数据（网络线程）弹回主线程
extern void KO_dog_network_thread_handle_recv(struct KO_dog_network* p);
//////////////////////////////////////////////////////////////////////////
// start wait thread.
extern void KO_dog_network_start(struct KO_dog_network* p);
// interrupt wait thread.
extern void KO_dog_network_interrupt(struct KO_dog_network* p);
// shutdown wait thread.
extern void KO_dog_network_shutdown(struct KO_dog_network* p);
// join wait thread.
extern void KO_dog_network_join(struct KO_dog_network* p);
//////////////////////////////////////////////////////////////////////////



#endif//__KO_dog_network_h__