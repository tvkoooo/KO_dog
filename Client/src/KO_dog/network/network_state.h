#ifndef __network_state_h__
#define __network_state_h__


struct KO_dog_network;

extern void network_state_callback_function_registration(struct KO_dog_network* p);

//
extern void network_state_entry_event_publish(struct KO_dog_network* p, const char* ip, unsigned short port);
extern void network_state_lobby_event_publish(struct KO_dog_network* p, const char* ip, unsigned short port);


#endif//__network_state_h__