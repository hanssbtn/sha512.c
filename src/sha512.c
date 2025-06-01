#include "../include/sha512.h"
#include "assert.h"

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

#ifdef __BYTE_ORDER__
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
		#define SWAP_64(x) (((x) << 56) | \
							(((x) << 40) & 0x00FF000000000000ULL) | \
							(((x) << 24) & 0x0000FF0000000000ULL) | \
							(((x) << 8)  & 0x000000FF00000000ULL) | \
							(((x) >> 8)  & 0x00000000FF000000ULL) | \
							(((x) >> 24) & 0x0000000000FF0000ULL) | \
							(((x) >> 40) & 0x000000000000FF00ULL) | \
							((x) >> 56))
	#else
		#define SWAP_64(x) (x) // No swap needed for big-endian
	#endif
#else
	#define SWAP_64(x) (((x) << 56) | \
                    (((x) << 40) & 0x00FF000000000000ULL) | \
                    (((x) << 24) & 0x0000FF0000000000ULL) | \
                    (((x) << 8)  & 0x000000FF00000000ULL) | \
                    (((x) >> 8)  & 0x00000000FF000000ULL) | \
                    (((x) >> 24) & 0x0000000000FF0000ULL) | \
                    (((x) >> 40) & 0x000000000000FF00ULL) | \
                    ((x) >> 56))
#endif

static inline uint64_t sha512_ch(uint64_t x, uint64_t y, uint64_t z) {
	return (x & y) ^ (~x & z);
}

static inline uint64_t sha512_maj(uint64_t x, uint64_t y, uint64_t z) {
	return (x & y) ^ (x & z) ^ (y & z);
}

#define SHR(x, s) ((x) >> (s))

#define ROTR(x, s) (((x) >> (s)) | ((x) << (64 - (s))))

static inline uint64_t sha512_sigma0(uint64_t x) {
	return ROTR(x, 28) ^ ROTR(x, 34) ^ ROTR(x, 39);
}

static inline uint64_t sha512_sigma1(uint64_t x) {
	return ROTR(x, 14) ^ ROTR(x, 18) ^ ROTR(x, 41);
}

static inline uint64_t sha512_varsigma0(uint64_t x) {
	return ROTR(x, 1) ^ ROTR(x, 8) ^ SHR(x, 7);
}

static inline uint64_t sha512_varsigma1(uint64_t x) {
	return ROTR(x, 19) ^ ROTR(x, 61) ^ SHR(x, 6);
}

int32_t sha512_ctx_init(sha512_context_t *const ctx) {
	if (!ctx) return -1;
	*ctx = (sha512_context_t){
		.prev_block = *SHA512_INITIAL_HASH
	};
	return 0;
}

int32_t sha384_ctx_init(sha384_context_t *const ctx) {
	if (!ctx) return -1;
	*ctx = (sha384_context_t){
		.prev_block = *SHA384_INITIAL_HASH
	};
	return 0;
}

int32_t sha512_ctx_hash(sha512_context_t *const ctx) {
	if (!ctx) return -1;
	if (ctx->current_block.length != 128) return -2;
	ssize_t t;
	uint64_t *const W = ctx->message_schedule.words;
	const uint64_t *const K = K512->words;
	uint64_t *const H = ctx->prev_block.w64;
	for (t = 0; t < 16; ++t) {
		W[t] = SWAP_64(ctx->current_block.w64[t]);
	}
	// 80 words
	for (t = 16; t < 80; ++t) {
		W[t] = sha512_varsigma1(W[t - 2]) + W[t - 7] + sha512_varsigma0(W[t - 15]) + W[t - 16];
	}
	
	uint64_t a = H[0], b = H[1], c = H[2], d = H[3], e = H[4], f = H[5], g = H[6], h = H[7];
	for (t = 0; t < 80; ++t) {
		uint64_t T1 = h + sha512_sigma1(e) + sha512_ch(e, f, g) + K[t] + W[t];
		uint64_t T2 = sha512_sigma0(a) + sha512_maj(a, b, c);
		h = g;
		g = f;
		f = e;
		e = d + T1;
		d = c;
		c = b;
		b = a;
		a = T1 + T2;
	} 
	
	H[0] += a;
	H[1] += b;
	H[2] += c;
	H[3] += d;
	H[4] += e;
	H[5] += f;
	H[6] += g;
	H[7] += h;

	for (t = 0; t < 16; ++t) {
		ctx->message_schedule.words[t] = 0;
		ctx->current_block.w64[t] = 0;
	}
	for (; t < 80; ++t) {
		ctx->message_schedule.words[t] = 0;
	}
	ctx->current_block.length = 0;
	
	return 0;
}

int32_t sha512_ctx_update(sha512_context_t *const ctx, const void *data, ssize_t byte_len) {
	if (!ctx || !data) return -1;
	if (byte_len < 0) return -2;
	if (!byte_len) return 0;
	ctx->bitlength += byte_len * 8;
	ssize_t l = ctx->current_block.length;
	if (l + byte_len < 0) return -3;
	if (l + byte_len >= 128) {
		const char *ptr = (const char*)data;
		
		// calculate number of bytes required to fill current_block
		ssize_t remaining_bytes = 128 - l;
		// make length of current_block equal to 128 bytes (1024 bits)
		memcpy(ctx->current_block.w8 + l, ptr, remaining_bytes);
		assert(l + remaining_bytes == 128);
		ctx->current_block.length = 128;
		
		// process bytes and reset length of current_block to 0
		int32_t r = sha512_ctx_hash(ctx);
		assert(r == 0);
		assert(ctx->current_block.length == 0);

		byte_len -= remaining_bytes;
		// return if there is no more bytes to process
		if (!byte_len) return 0;
		
		// advance pointer by bytes taken
		ptr += remaining_bytes;
		ssize_t blocks = byte_len / 128;
		remaining_bytes = byte_len % 128;

		// process remaining blocks
		for (ssize_t i = 0; i < blocks; ++i) {
			memcpy(ctx->current_block.w8, ptr, 128);
			ctx->current_block.length = 128;
			assert(sha512_ctx_hash(ctx) == 0);
			ptr += 128;
		}
		ctx->current_block.length = remaining_bytes;
		memcpy(ctx->current_block.w8, ptr, remaining_bytes);
	} else {
		ctx->current_block.length += byte_len;
		memcpy(ctx->current_block.w8 + l, data, byte_len);
	}

	return 0;
}
#define sha384_ctx_update(ctx, data, byte_len) sha512_ctx_update(ctx, data, byte_len)

int32_t sha512_pad_data(sha512_context_t *const ctx) {
	if (!ctx) return -1;
	if (ctx->current_block.length == 128) return -2;
	ctx->current_block.w8[ctx->current_block.length++] = 0x80;
	if (ctx->current_block.length > (128 - 16)) {
        // Fill the rest of the current block with zeros
        while (ctx->current_block.length < 128) {
            ctx->current_block.w8[ctx->current_block.length++] = 0;
        }
        int32_t r = sha512_ctx_hash(ctx); // Process this filled block
        if (r) return r; // Propagate error from hash function
        // ctx->current_block.length is now 0 after sha512_ctx_hash
    }
	while (ctx->current_block.length < (128 - 16)) {
        ctx->current_block.w8[ctx->current_block.length++] = 0;
    }

    assert(ctx->current_block.length == (128 - 16));

    // Store total bit length in big-endian format
    // High 64 bits of length
    ctx->current_block.w64[14] = SWAP_64(ctx->bitlength >> 64);
    // Low 64 bits of length
    ctx->current_block.w64[15] = SWAP_64(ctx->bitlength & 0xFFFFFFFFFFFFFFFFULL);

    ctx->current_block.length = 128;
	return 0;
}

int32_t sha512_ctx_final(sha512_context_t *const ctx, void *res, ssize_t byte_len) {
	if (!ctx || (!res && byte_len > 0)) return -1;
	int32_t r = sha512_pad_data(ctx);
	if (r) return r;
	r = sha512_ctx_hash(ctx);
	if (r) return r;
	uint64_t tmp[8] = {};
	for (ssize_t i = 0; i < 8; ++i) {
		tmp[i] = SWAP_64(ctx->prev_block.w64[i]);
	}
	memcpy(res, tmp, byte_len);
	return 0;
}
#define sha384_ctx_final(ctx, res, byte_len) sha512_ctx_final(ctx, res, byte_len)

int32_t sha512_message_block_printf(const sha512_message_block_t *const block, bool big_endian) {
	if (!block) return -1;	
	if (big_endian){
		for (ssize_t i = 0; i < 7; ++i) {
			printf("%016llX-", SWAP_64(block->w64[i]));
		}
		printf("%016llX\n", SWAP_64(block->w64[7]));
		for (ssize_t i = 0; i < 7; ++i) {
			printf("%016llX-", SWAP_64(block->w64[i + 8]));
		}
		printf("%016llX\n", SWAP_64(block->w64[15]));
	} else {
		for (ssize_t i = 0; i < 7; ++i) {
			printf("%016llX-", (block->w64[i]));
		}
		printf("%016llX\n", (block->w64[7]));
		for (ssize_t i = 0; i < 7; ++i) {
			printf("%016llX-", (block->w64[i + 8]));
		}
		printf("%016llX\n", (block->w64[15]));
	}
	return 0;
}

int32_t sha512_message_schedule_printf(const sha512_message_schedule_t *const schedule) {
	if (!schedule) return -1;
	printf("%016llX", (schedule->words[0]));
	for (ssize_t i = 1; i < 80; ++i) {
		printf("%s%016llX", (i % 8) ? "-" : "\n", (schedule->words[i]));
	}
	printf("\n");
	return 0;
}

int32_t sha512_ctx_printf(const sha512_context_t *const ctx) {
	if (!ctx) return -1;
	printf("current block:\n");
	sha512_message_block_printf(&ctx->current_block, true);
	printf("previous block:\n");
	sha512_message_block_printf(&ctx->prev_block, false);
	printf("message schedule:\n");
	sha512_message_schedule_printf(&ctx->message_schedule);
	printf("bit length:\n%016llX\n%016llX bits\n", ((uint64_t)(ctx->bitlength >> 64)), ((uint64_t)ctx->bitlength));
	return 0;
}

