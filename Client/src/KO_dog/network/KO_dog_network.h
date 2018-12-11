#ifndef __KO_dog_network_h__
#define __KO_dog_network_h__

#include <string>
#include "core/mm_timer.h"
#include "net/mm_client_tcp.h"
#include "net/mm_client_udp.h"
#include "openssl/mm_openssl_tcp_context.h"
#include "openssl/mm_openssl_rsa.h"
#include "openssl/mm_openssl_rc4.h"

struct tcps_connect
{
	enum enum_tcps_state
	{
		tcps_state_closed = 0,// tcps is closed,Unencrypted packages are not allowed to be sent.
		tcps_state_finish = 1,// tcps already completed,Unencrypted packages are allowed to be sent.
	};
	//服务端 openssl_rsa_server 的公钥
	std::string public_key;
	struct mm_openssl_rsa openssl_rsa_client;
	struct mm_openssl_rsa openssl_rsa_server;
	struct mm_openssl_rc4 openssl_rc4;
	struct mm_openssl_tcp_context openssl_tcp_context;
	int state;
};
void tcps_connect_init(struct tcps_connect *p);
void tcps_connect_destroy(struct tcps_connect *p);

struct lobby_user_token
{
	enum lobby_user_token_state
	{
		user_token_closed = 0,// user token is closed
		user_token_motion = 1,// user token is implementing
		user_token_finish = 2,// user token has already completed.
	};
	mm_uint64_t uid;
	std::string token;// token.
	mm_atomic_t locker;
	int state;
};

void lobby_user_token_init(struct lobby_user_token* p);
void lobby_user_token_destroy(struct lobby_user_token* p);
//
void lobby_user_token_lock(struct lobby_user_token* p);
void lobby_user_token_unlock(struct lobby_user_token* p);

struct KO_dog_network
{
	struct mm_timer timer;
	struct mm_client_udp udp;	
	struct mm_client_tcp tcp;
	struct tcps_connect tcps;
	struct lobby_user_token lobby_token;
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