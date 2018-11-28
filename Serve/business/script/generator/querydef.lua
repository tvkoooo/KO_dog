local string = string
local print = print
---copyright longer------------------------------------------
local modname="querydef"
local M={}
_G[modname]=M
package.loaded[modname]=M
if setfenv then
	setfenv(1, M) -- for 5.1
else
	_ENV = M -- for 5.2
end
----------------------------------------------------------------------------------
function type_i_i(v)
	return v.." = 0;"
end
function type_i_d(v)
	return v.." = 0;"
end
function type_i_a(v,u)
	return v.." = "..u..";";
end
function type_s_i(v)
	return "mm_string_init(&"..v..");"
end
function type_s_d(v)
	return "mm_string_destroy(&"..v..");"
end
function type_s_a(v,u)
	return "mm_string_assigns(&"..v..","..u..");"
end

typedef_mm =
{
	int8 	= "mm_sint8_t",
	uint8 	= "mm_uint8_t",
	int16 	= "mm_sint16_t",
	uint16 	= "mm_uint16_t",
	int32 	= "mm_sint32_t",
	uint32 	= "mm_uint32_t",
	int64 	= "mm_sint64_t",
	uint64 	= "mm_uint64_t",
	float 	= "mm_float32_t",
	double 	= "mm_float64_t",
	string 	= "struct mm_string",
}
calls =
{
	int8 	= {field_name = "sint8"  ,i = type_i_i,d = type_i_d,a = type_i_a,},
	uint8 	= {field_name = "uint8"  ,i = type_i_i,d = type_i_d,a = type_i_a,},
	int16 	= {field_name = "sint16" ,i = type_i_i,d = type_i_d,a = type_i_a,},
	uint16 	= {field_name = "uint16" ,i = type_i_i,d = type_i_d,a = type_i_a,},
	int32 	= {field_name = "sint32" ,i = type_i_i,d = type_i_d,a = type_i_a,},
	uint32 	= {field_name = "uint32" ,i = type_i_i,d = type_i_d,a = type_i_a,},
	int64 	= {field_name = "sint64" ,i = type_i_i,d = type_i_d,a = type_i_a,},
	uint64 	= {field_name = "uint64" ,i = type_i_i,d = type_i_d,a = type_i_a,},
	float 	= {field_name = "float32",i = type_i_i,d = type_i_d,a = type_i_a,},
	double 	= {field_name = "float64",i = type_i_i,d = type_i_d,a = type_i_a,},
	string 	= {field_name = "string" ,i = type_s_i,d = type_s_d,a = type_s_a,},
}

-- default
typedef = typedef_mm

function gsub_type(v)
	return string.gsub(v,"(%w+)",function(w) return types(w) end)
end

function gsub_type_array(v)
	return string.gsub(v,"<(.-)>",function(w) return "<"..gsub_type(w)..">" end)
end

function types(vtype)
	return typedef[vtype] or gsub_type_array(vtype)
end
function funcs(vtype)
	return funcdef[vtype]
end

vname = function(name)
	return name
end
----------------------------------------------------------------------------------
-- print(types("std::map<uint32,std::map<uint32,MSlot>>"))
----------------------------------------------------------------------------------
return M
