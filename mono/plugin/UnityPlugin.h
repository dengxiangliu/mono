#pragma once
#include<stdint.h>
#define MAX_FUNC_COUNT 0x7
typedef enum
{
	MONO_GET_ASSEMBLY_CSHARP = 100,
	MONO_GET_METHOD,
	MONO_GET_STRING_HEAP,
	MONO_GET_OPCODE,
	MONO_METADATA_ENCRYPT,
	MONO_METHOD_TO_IR_CB,
	MONO_INTERNAL_HASH_TABLE_INSERT_CB,
	IL2CPP_GET_GLOBAL_METADATA,
	IL2CPP_GET_STRING
} callback_func_type;

typedef const void * (* def_query_call_back)(callback_func_type uID);
typedef void(* def_mono_get_assembly_csharp) (char ** data, int * data_len, const char * name, void* callback_func_info);
typedef void(* def_mono_get_method) (char * code, int code_size);
typedef void(* def_mono_get_string_heap) (char * string, int string_size);
typedef int(* def_mono_get_opcode)(int opcode);
typedef int(* def_mono_metadata_encrypt)();

/*callback func*/
typedef int(*def_mono_method_to_ir_callback)(
    void* cfg, void* method, void* start_bblock, void* end_bblock,
    void* return_var, void** inline_args,
    uint32_t inline_offset, uint32_t is_virtual_call);
typedef void(*def_mono_internal_hash_table_insert_callback)(void* table, void* key, void* value);

def_mono_get_assembly_csharp g_get_assembly_csharp;
def_mono_get_method g_get_method;
def_mono_get_string_heap g_get_string;
def_mono_get_opcode g_get_opcode;
def_mono_metadata_encrypt g_metadata_encrypt;
def_mono_method_to_ir_callback g_mono_method_to_ir_cb;
def_mono_internal_hash_table_insert_callback g_mono_internal_hash_table_insert_cb;

typedef struct CallBackFuncInfo
{ 
    uint32_t func_type; 
    void* stub_addr;
} CallBackFuncInfo;

static CallBackFuncInfo g_callback_func_info[MAX_FUNC_COUNT + 1] =
{
	{MONO_GET_ASSEMBLY_CSHARP, (void*)&g_get_assembly_csharp},
	{MONO_GET_METHOD, (void*)&g_get_method},
	{MONO_GET_STRING_HEAP, (void*)&g_get_string},
	{MONO_GET_OPCODE, (void*)&g_get_opcode},
	{MONO_METADATA_ENCRYPT, (void*)&g_metadata_encrypt},
	{MONO_METHOD_TO_IR_CB, (void*)&g_mono_method_to_ir_cb},
	{MONO_INTERNAL_HASH_TABLE_INSERT_CB, (void*)&g_mono_internal_hash_table_insert_cb},
	{0 ,0}
};