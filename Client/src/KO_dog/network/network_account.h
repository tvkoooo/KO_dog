#ifndef __network_account_h__
#define __network_account_h__

#include "net/mm_packet.h"

struct KO_dog_network;

extern void network_account_callback_function_registration(struct KO_dog_network* p);

//tcp/////////////////////////////////////////////////////////////////////////////////

extern void hd_n_c_business_account_signed_in_rs(void* obj, void* u, struct mm_packet* pack);
extern void hd_n_c_business_account_register_rs(void* obj, void* u, struct mm_packet* pack);
extern void hd_q_c_business_account_signed_in_rs(void* obj, void* u, struct mm_packet* pack);
extern void hd_q_c_business_account_register_rs(void* obj, void* u, struct mm_packet* pack);


#endif//__network_account_h__