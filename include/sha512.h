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

static const sha512_message_block_t __SHA384_INITIAL_HASH = (sha512_message_block_t){
	.w64 = {
		0xCBBB9D5DC1059ED8ULL,
		0x629A292A367CD507ULL,
		0x9159015A3070DD17ULL,
		0x152FECD8F70E5939ULL,
		0x67332667FFC00B31ULL,
		0x8EB44A8768581511ULL,
		0xDB0C2E0D64F98FA7ULL,
		0x47B5481DBEFA4FA4ULL
	},
	.length = 64
};
static const sha512_message_block_t *const SHA384_INITIAL_HASH = &__SHA384_INITIAL_HASH;

static const sha512_message_block_t __SHA512_INITIAL_HASH = (sha512_message_block_t){
	.w64 = {
		0x6A09E667F3BCC908ULL,
		0xBB67AE8584CAA73BULL,
		0x3C6EF372FE94F82BULL,
		0xA54FF53A5F1D36F1ULL,
		0x510E527FADE682D1ULL,
		0x9B05688C2B3E6C1FULL,
		0x1F83D9ABFB41BD6BULL,
		0x5BE0CD19137E2179ULL,
	},
	.length = 64
};
static const sha512_message_block_t *const SHA512_INITIAL_HASH = &__SHA512_INITIAL_HASH;

static const sha512_constant_t __K512 = (sha512_constant_t){
	.words = {
		0x428A2F98D728AE22ULL, 0x7137449123EF65CDULL, 0xB5C0FBCFEC4D3B2FULL, 0xE9B5DBA58189DBBCULL,
		0x3956C25BF348B538ULL, 0x59F111F1B605D019ULL, 0x923F82A4AF194F9BULL, 0xAB1C5ED5DA6D8118ULL,
		0xD807AA98A3030242ULL, 0x12835B0145706FBEULL, 0x243185BE4EE4B28CULL, 0x550C7DC3D5FFB4E2ULL,
		0x72BE5D74F27B896FULL, 0x80DEB1FE3B1696B1ULL, 0x9BDC06A725C71235ULL, 0xC19BF174CF692694ULL,
		0xE49B69C19EF14AD2ULL, 0xEFBE4786384F25E3ULL, 0x0FC19DC68B8CD5B5ULL, 0x240CA1CC77AC9C65ULL,
		0x2DE92C6F592B0275ULL, 0x4A7484AA6EA6E483ULL, 0x5CB0A9DCBD41FBD4ULL, 0x76F988DA831153B5ULL,
		0x983E5152EE66DFABULL, 0xA831C66D2DB43210ULL, 0xB00327C898FB213FULL, 0xBF597FC7BEEF0EE4ULL,
		0xC6E00BF33DA88FC2ULL, 0xD5A79147930AA725ULL, 0x06CA6351E003826FULL, 0x142929670A0E6E70ULL,
		0x27B70A8546D22FFCULL, 0x2E1B21385C26C926ULL, 0x4D2C6DFC5AC42AEDULL, 0x53380D139D95B3DFULL,
		0x650A73548BAF63DEULL, 0x766A0ABB3C77B2A8ULL, 0x81C2C92E47EDAEE6ULL, 0x92722C851482353BULL,
		0xA2BFE8A14CF10364ULL, 0xA81A664BBC423001ULL, 0xC24B8B70D0F89791ULL, 0xC76C51A30654BE30ULL,
		0xD192E819D6EF5218ULL, 0xD69906245565A910ULL, 0xF40E35855771202AULL, 0x106AA07032BBD1B8ULL,
		0x19A4C116B8D2D0C8ULL, 0x1E376C085141AB53ULL, 0x2748774CDF8EEB99ULL, 0x34B0BCB5E19B48A8ULL,
		0x391C0CB3C5C95A63ULL, 0x4ED8AA4AE3418ACBULL, 0x5B9CCA4F7763E373ULL, 0x682E6FF3D6B2B8A3ULL,
		0x748F82EE5DEFB2FCULL, 0x78A5636F43172F60ULL, 0x84C87814A1F0AB72ULL, 0x8CC702081A6439ECULL,
		0x90BEFFFA23631E28ULL, 0xA4506CEBDE82BDE9ULL, 0xBEF9A3F7B2C67915ULL, 0xC67178F2E372532BULL,
		0xCA273ECEEA26619CULL, 0xD186B8C721C0C207ULL, 0xEADA7DD6CDE0EB1EULL, 0xF57D4F7FEE6ED178ULL,
		0x06F067AA72176FBAULL, 0x0A637DC5A2C898A6ULL, 0x113F9804BEF90DAEULL, 0x1B710B35131C471BULL,
		0x28DB77F523047D84ULL, 0x32CAAB7B40C72493ULL, 0x3C9EBE0A15C9BEBCULL, 0x431D67C49C100D4CULL,
		0x4CC5D4BECB3E42B6ULL, 0x597F299CFC657E2AULL, 0x5FCB6FAB3AD6FAECULL, 0x6C44198C4A475817ULL,
	}
};

static const sha512_constant_t *const K512 = &__K512;
static const sha384_constant_t *const K384 = &__K512;

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