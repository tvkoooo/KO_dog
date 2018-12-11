#ifndef __network_lobby_h__
#define __network_lobby_h__

#include "net/mm_client_tcp.h"

struct KO_dog_network;

extern void network_lobby_callback_function_registration(struct KO_dog_network* p);

//tcp/////////////////////////////////////////////////////////////////////////////////
extern void mm_client_tcp_flush_send_exchange_key_rq(struct mm_client_tcp* p);
extern void mm_client_tcp_flush_send_token_verify_rq(struct mm_client_tcp* p);



//extern void hd_n_c_shuttle_lobby_token_verify_rs(void* obj, void* u, struct mm_packet* pack);


#endif//__network_lobby_h__