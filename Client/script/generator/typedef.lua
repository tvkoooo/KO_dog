local string = string
local print = print
---copyright longer------------------------------------------
local modname="typedef"
local M={}
_G[modname]=M
package.loaded[modname]=M
if setfenv then
	setfenv(1, M) -- for 5.1
else
	_ENV = M -- for 5.2
end
----------------------------------------------------------------------------------
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
	string 	= "std::string",
}

typedef_cpp =
{
	int8 	= "char",
	uint8 	= "unsigned char",
	int16 	= "short",
	uint16 	= "unsigned short",
	int32 	= "int",
	uint32 	= "unsigned int",
	int64 	= "int64",
	uint64 	= "uint64",
	float 	= "float",
	double 	= "double",
	string 	= "std::string",
}

typedef_java =
{
	int8 	= "byte",
	uint8 	= "byte",
	int16 	= "short",
	uint16 	= "short",
	int32 	= "int",
	uint32 	= "int",
	int64 	= "long",
	uint64 	= "long",
	double 	= "double",
	string 	= "String",
}
-- default
typedef = typedef_mm

function use_mm_types()
	typedef = typedef_mm
end

function use_cpp_types()
	typedef = typedef_cpp
end

function use_java_types()
	typedef = typedef_java
end

function gsub_type(v)
	return string.gsub(v,"(%w+)",function(w) return types(w) end)
end

function gsub_type_array(v)
	return string.gsub(v,"<(.-)>",function(w) return "<"..gsub_type(w)..">" end)
end

function types(vtype)
	return typedef[vtype] or gsub_type_array(vtype)
end

vname = function(name)
	return name
end
----------------------------------------------------------------------------------
-- print(types("std::map<uint32,std::map<uint32,MSlot>>"))
----------------------------------------------------------------------------------
return M
