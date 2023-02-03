/* Copyright 2021 NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */
/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.4 at Thu Mar 11 17:03:44 2021. */

#ifndef PB_NXP_IOT_RPC_PB_H_INCLUDED
#define PB_NXP_IOT_RPC_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef PB_BYTES_ARRAY_T(1024) nxp_iot_ArgumentPayload_bytes_arg_t;
typedef struct _nxp_iot_ArgumentPayload {
    pb_size_t which_data;
    union {
        uint32_t uint32_arg;
        int32_t int32_arg;
        nxp_iot_ArgumentPayload_bytes_arg_t bytes_arg;
        char string_arg[1024];
    } data;
/* @@protoc_insertion_point(struct:nxp_iot_ArgumentPayload) */
} nxp_iot_ArgumentPayload;

typedef struct _nxp_iot_Argument {
    bool has_pos;
    int32_t pos;
    bool has_payload;
    nxp_iot_ArgumentPayload payload;
/* @@protoc_insertion_point(struct:nxp_iot_Argument) */
} nxp_iot_Argument;

typedef struct _nxp_iot_RpcRequest {
    bool has_id;
    int32_t id;
    pb_size_t arg_count;
    nxp_iot_Argument arg[6];
/* @@protoc_insertion_point(struct:nxp_iot_RpcRequest) */
} nxp_iot_RpcRequest;

typedef struct _nxp_iot_RpcResponse {
    bool has_id;
    int32_t id;
    pb_size_t arg_count;
    nxp_iot_Argument arg[6];
/* @@protoc_insertion_point(struct:nxp_iot_RpcResponse) */
} nxp_iot_RpcResponse;

/* Default values for struct fields */

/* Initializer values for message structs */
#define nxp_iot_ArgumentPayload_init_default     {0, {0}}
#define nxp_iot_Argument_init_default            {false, 0, false, nxp_iot_ArgumentPayload_init_default}
#define nxp_iot_RpcRequest_init_default          {false, 0, 0, {nxp_iot_Argument_init_default, nxp_iot_Argument_init_default, nxp_iot_Argument_init_default, nxp_iot_Argument_init_default, nxp_iot_Argument_init_default, nxp_iot_Argument_init_default}}
#define nxp_iot_RpcResponse_init_default         {false, 0, 0, {nxp_iot_Argument_init_default, nxp_iot_Argument_init_default, nxp_iot_Argument_init_default, nxp_iot_Argument_init_default, nxp_iot_Argument_init_default, nxp_iot_Argument_init_default}}
#define nxp_iot_ArgumentPayload_init_zero        {0, {0}}
#define nxp_iot_Argument_init_zero               {false, 0, false, nxp_iot_ArgumentPayload_init_zero}
#define nxp_iot_RpcRequest_init_zero             {false, 0, 0, {nxp_iot_Argument_init_zero, nxp_iot_Argument_init_zero, nxp_iot_Argument_init_zero, nxp_iot_Argument_init_zero, nxp_iot_Argument_init_zero, nxp_iot_Argument_init_zero}}
#define nxp_iot_RpcResponse_init_zero            {false, 0, 0, {nxp_iot_Argument_init_zero, nxp_iot_Argument_init_zero, nxp_iot_Argument_init_zero, nxp_iot_Argument_init_zero, nxp_iot_Argument_init_zero, nxp_iot_Argument_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define nxp_iot_ArgumentPayload_uint32_arg_tag   2
#define nxp_iot_ArgumentPayload_int32_arg_tag    3
#define nxp_iot_ArgumentPayload_bytes_arg_tag    4
#define nxp_iot_ArgumentPayload_string_arg_tag   5
#define nxp_iot_Argument_pos_tag                 1
#define nxp_iot_Argument_payload_tag             10
#define nxp_iot_RpcRequest_id_tag                1
#define nxp_iot_RpcRequest_arg_tag               10
#define nxp_iot_RpcResponse_id_tag               1
#define nxp_iot_RpcResponse_arg_tag              10

/* Struct field encoding specification for nanopb */
extern const pb_field_t nxp_iot_ArgumentPayload_fields[5];
extern const pb_field_t nxp_iot_Argument_fields[3];
extern const pb_field_t nxp_iot_RpcRequest_fields[3];
extern const pb_field_t nxp_iot_RpcResponse_fields[3];

/* Maximum encoded size of messages (where known) */
#define nxp_iot_ArgumentPayload_size             1027
#define nxp_iot_Argument_size                    1041
#define nxp_iot_RpcRequest_size                  6275
#define nxp_iot_RpcResponse_size                 6275

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define RPC_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
