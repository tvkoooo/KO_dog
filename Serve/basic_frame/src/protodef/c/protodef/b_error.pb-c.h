/* Generated by the protocol buffer compiler.  DO NOT EDIT! */

#ifndef PROTOBUF_C_b_5ferror_2eproto_INCLUDED
#define PROTOBUF_C_b_5ferror_2eproto_INCLUDED

#include <google/protobuf-c/protobuf-c.h>

PROTOBUF_C_BEGIN_DECLS


typedef struct _b_error_info b_error_info;


/* --- enums --- */


/* --- messages --- */

struct  _b_error_info
{
  ProtobufCMessage base;
  unsigned int code;
  char *desc;
};
extern char b_error_info_desc_default_value[];
#define b_error_info_Init \
 { PROTOBUF_C_MESSAGE_INIT (&b_error_info_descriptor) \
    , 0, b_error_info_desc_default_value }


/* b_error_info methods */
void   b_error_info_init
                     (b_error_info         *message);
size_t b_error_info_get_packed_size
                     (const b_error_info   *message);
size_t b_error_info_pack
                     (const b_error_info   *message,
                      unsigned char             *out);
size_t b_error_info_pack_to_buffer
                     (const b_error_info   *message,
                      ProtobufCBuffer     *buffer);
b_error_info *
       b_error_info_unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const unsigned char       *data);
void   b_error_info_free_unpacked
                     (b_error_info *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*b_error_info_Closure)
                 (const b_error_info *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor b_error_info_descriptor;

PROTOBUF_C_END_DECLS


#endif  /* PROTOBUF_b_5ferror_2eproto_INCLUDED */