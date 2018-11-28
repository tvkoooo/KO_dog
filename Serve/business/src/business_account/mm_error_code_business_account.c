#include "mm_error_code_business_account.h"
#include "core/mm_string.h"

//////////////////////////////////////////////////////////////////////////
void mm_error_desc_assign_business_account(struct mm_error_desc* p)
{
	mm_error_core_assign_code_desc(p, err_business_account_signed_in_account_does_not_exist, "No login account exists.");
	mm_error_core_assign_code_desc(p, err_business_account_signed_in_account_does_not_match_password, "Account does not match password.");
	mm_error_core_assign_code_desc(p, err_business_account_register_account_already_exists, "Registered account already exists.");
	mm_error_core_assign_code_desc(p, err_business_account_register_illegal_account_or_password, "Illegal registration account or password.");
}
//////////////////////////////////////////////////////////////////////////
