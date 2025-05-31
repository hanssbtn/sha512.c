#include "../include/sha512.h"
#include "assert.h"

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
		// printf("l:        %lld byte(s)\nbyte_len: %lld byte(s)\ntotal:    %lld byte(s)\n", l, byte_len, l + byte_len);
		const char *ptr = (const char*)data;
		
		// calculate number of bytes required to fill current_block
		ssize_t remaining_bytes = 128 - l;
		// printf("remaining bytes: %lld byte(s)\n", remaining_bytes);
		// make length of current_block equal to 128 bytes (1024 bits)
		memcpy(ctx->current_block.w8 + l, ptr, remaining_bytes);
		assert(l + remaining_bytes == 128);
		ctx->current_block.length = 128;
		
		// process bytes and reset length of current_block to 0
		int32_t r = sha512_ctx_hash(ctx);
		assert(r == 0);
		assert(ctx->current_block.length == 0);

		byte_len -= remaining_bytes;
		// printf("byte_len: %lld byte(s)\n", byte_len);
		// return if there is no more bytes to process
		if (!byte_len) return 0;
		
		// advance pointer by bytes taken
		ptr += remaining_bytes;
		ssize_t blocks = byte_len / 128;
		remaining_bytes = byte_len % 128;
		// printf("blocks:          %lld block(s)\n", blocks);
		// printf("remaining_bytes: %lld byte(s)\n", remaining_bytes);

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
		// printf("Appending %lld byte(s) to current block\n", byte_len);
		ctx->current_block.length += byte_len;
		// printf("Total length: %llu byte(s)\n", ctx->current_block.length);
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

