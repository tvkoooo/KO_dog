#include "mm_error_code_business_relation.h"
#include "core/mm_string.h"

//////////////////////////////////////////////////////////////////////////
void mm_error_desc_assign_business_relation(struct mm_error_desc* p)
{
	mm_error_core_assign_code_desc(p, err_business_relation_signed_in_relation_does_not_exist, "No login relation exists.");
	mm_error_core_assign_code_desc(p, err_business_relation_signed_in_relation_does_not_match_password, "relation does not match password.");
	mm_error_core_assign_code_desc(p, err_business_relation_register_relation_already_exists, "Registered relation already exists.");
	mm_error_core_assign_code_desc(p, err_business_relation_register_illegal_relation_or_password, "Illegal registration relation or password.");
}
//////////////////////////////////////////////////////////////////////////
