#ifndef __network_entry_h__
#define __network_entry_h__

#include "net/mm_client_udp.h"
#include "protodef/cxx/protodef/c_basic_frame_entry.pb.h"

extern void network_entry_callback_function_registration(struct KO_dog_network* p);

extern void mm_client_udp_send_message(struct mm_client_udp* p, struct mm_packet_head* packet_head, mm_uint32_t hlength, ::google::protobuf::Message* message, struct mm_sockaddr* remote);

extern void mm_client_udp_flush_send_knock_rq_msg_id(struct mm_client_udp* p);

extern void hd_n_c_basic_frame_entry_knock_rs(void* obj, void* u, struct mm_packet* pack, struct mm_sockaddr* remote);


#endif//__network_entry_h__