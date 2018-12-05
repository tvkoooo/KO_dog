#ifndef __network_entry_h__
#define __network_entry_h__

#include "net/mm_client_udp.h"

struct KO_dog_network;

extern void network_entry_callback_function_registration(struct KO_dog_network* p);

//udp/////////////////////////////////////////////////////////////////////////////////
extern void mm_client_udp_flush_send_knock_rq(struct mm_client_udp* p);
extern void hd_n_c_basic_frame_entry_knock_rs(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote);



#endif//__network_entry_h__