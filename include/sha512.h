#pragma once
#ifndef SHA512_H__
#define SHA512_H__

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

typedef struct {
	union {
		uint64_t w64[16];
		uint8_t w8[128];
	};
	// Length in bytes
	ssize_t length;
} sha512_message_block_t;
typedef sha512_message_block_t sha384_message_block_t;

typedef struct {
	uint64_t words[80];
} sha512_message_schedule_t;
typedef sha512_message_schedule_t sha384_message_schedule_t;

typedef sha512_message_schedule_t sha512_constant_t;
typedef sha384_message_schedule_t sha384_constant_t;

typedef struct {
	sha512_message_block_t prev_block;
	sha512_message_block_t current_block;
	sha512_message_schedule_t message_schedule;
	__uint128_t bitlength;
} sha512_context_t;
typedef sha512_context_t sha384_context_t;

int32_t sha512_ctx_init(sha512_context_t *const ctx);
int32_t sha384_ctx_init(sha384_context_t *const ctx);
int32_t sha512_ctx_update(sha512_context_t *const ctx, const void *data, ssize_t byte_len);
#define sha384_ctx_update(ctx, data, byte_len) sha512_ctx_update(ctx, data, byte_len)
int32_t sha512_ctx_final(sha512_context_t *const ctx, void *res, ssize_t byte_len);
#define sha384_ctx_final(ctx, res, byte_len) sha512_ctx_final(ctx, res, byte_len)
int32_t sha512_message_block_printf(const sha512_message_block_t *const block, bool big_endian);
#define sha384_message_block_printf(block, big_endian) sha512_message_block_printf(block, big_endian)
int32_t sha512_message_schedule_printf(const sha512_message_schedule_t *const schedule);
#define sha384_message_schedule_printf(schedule) sha512_message_schedule_printf(schedule)
int32_t sha512_ctx_printf(const sha512_context_t *const ctx);
#define sha384_ctx_printf(ctx) sha512_ctx_printf(ctx);

#endif // SHA512_H__