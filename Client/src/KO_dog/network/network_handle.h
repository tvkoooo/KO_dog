#ifndef __network_handle_h__
#define __network_handle_h__

#include <google/protobuf/message.h>
#include "core/mm_core.h"

extern void mm_client_tcp_flush_send_message(struct mm_client_tcp* p, mm_uint64_t uid, mm_uint32_t mid, ::google::protobuf::Message *message);

#endif//__network_handle_h__