#include "KO_dog_error_code.h"
#include "core/mm_string.h"

//////////////////////////////////////////////////////////////////////////
void KO_dog_error_code(struct mm_error_desc* p)
{
	mm_error_core_assign_code_desc(p, KO_dog_error_code_network_anomaly, "Network anomaly.");
	mm_error_core_assign_code_desc(p, KO_dog_error_code_unencrypted_network, "Unencrypted network.");

	mm_error_core_assign_code_desc(p, KO_dog_error_code_does_remote_login, "User remote login.");

}
//////////////////////////////////////////////////////////////////////////
