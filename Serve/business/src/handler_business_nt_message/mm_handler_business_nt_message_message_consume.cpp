#include "mm_handler_business_nt_message_message_consume.h"

#include "net/mm_sockaddr.h"

#include "dish/mm_xoshiro_string.h"

#include "rabbitmq/mm_amqp_consume_array.h"

#include "mm_handler_business_nt_message.h"
#include "mm_handler_business_nt_message_launch.h"

void mm_handler_business_nt_message_message_consume_config(struct mm_handler_business_nt_message* impl)
{
	struct mm_amqp_consume_array* consume_array = &impl->consume_array;
	struct mm_handler_business_nt_message_launch* lobby_launch = &impl->launch_info;

	struct mm_string rabbitmq_password;
	struct mm_amqp_exchange exchange;
	struct mm_amqp_queue queue;

	mm_string_init(&rabbitmq_password);
	mm_amqp_exchange_init(&exchange);
	mm_amqp_queue_init(&queue);

	mm_xoshiro256starstar_srand(&impl->rabbitmq_password_random, lobby_launch->rabbitmq_password_seed);
	mm_xoshiro256starstar_random_string(&impl->rabbitmq_password_random, &rabbitmq_password, MM_HANDLER_LOBBY_RABBITMQ_SECRET_LENGTH);
	
	mm_string_assigns(&exchange.exchange_name, "mm.exchange.shuttle_lobby");
	mm_string_assigns(&exchange.exchange_type, "topic");
	exchange.exchange_passive = 0;
	exchange.exchange_durable = 1;
	exchange.exchange_auto_delete = 0;
	exchange.exchange_internal = 0;

	mm_string_assigns(&queue.queue_name, "mm.handler_business_nt_message");
	queue.queue_passive = 0;
	queue.queue_durable = 1;
	queue.queue_exclusive = 0;
	queue.queue_auto_delete = 0;

	mm_amqp_consume_array_assign_context(consume_array, impl);
	mm_amqp_consume_array_assign_pop_timeout(consume_array, MM_AMQP_CONSUME_ERROR_POP_TIMEOUT);
	mm_amqp_consume_array_assign_sleep_timeout(consume_array, MM_AMQP_CONSUME_EMPTY_KEY_SLEEP_TIME, MM_AMQP_CONSUME_EMPTY_VAL_SLEEP_TIME, MM_AMQP_CONSUME_ERROR_CTX_SLEEP_TIME);
	mm_amqp_consume_array_assign_consume_attr(consume_array, 0, 0, 0);
	mm_amqp_consume_array_assign_exchange(consume_array, &exchange);
	mm_amqp_consume_array_assign_queue(consume_array, &queue);
	mm_amqp_consume_array_assign_routing_key(consume_array, "mm.shuttle_lobby");
	mm_amqp_consume_array_assign_index_key(consume_array, "*");

	mm_amqp_consume_array_assign_parameters(consume_array, lobby_launch->event_queue_rabbitmq_parameters.s);
	mm_amqp_consume_array_assign_vhost(consume_array, "mm.shuttle");
	mm_amqp_consume_array_assign_account(consume_array, "mm_shuttle_lobby", rabbitmq_password.s);
	mm_amqp_consume_array_assign_conn_attr(consume_array, 0, 131072, 0, 1);
	mm_amqp_consume_array_assign_conn_timeout(consume_array, MM_AMQP_CONN_CONN_TIMEOUT, MM_AMQP_CONN_TRYTIMES);

	mm_string_destroy(&rabbitmq_password);
	mm_amqp_exchange_destroy(&exchange);
	mm_amqp_queue_destroy(&queue);
}