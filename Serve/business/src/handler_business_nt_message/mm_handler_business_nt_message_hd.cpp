#include "mm_handler_business_nt_message_hd.h"

#include "core/mm_logger.h"

#include "net/mm_packet.h"

#include "rabbitmq/mm_amqp_consume_array.h"

#include "cxx/protodef/s_shuttle_lobby.pb.h"

#include "mm_handler_business_nt_message.h"

void mm_handler_lobby_hd_register(struct mm_handler_business_nt_message* impl)
{
	struct mm_amqp_consume_array* consume_array = &impl->consume_array;

	mm_amqp_consume_array_assign_callback(consume_array, s_shuttle_lobby::token_verify_ev_msg_id, &hd_s_shuttle_lobby_token_verify_ev);
}
