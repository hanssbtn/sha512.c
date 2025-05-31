#include "include/sha512.h"

int main(void) {
	sha384_context_t ctx;
	sha384_ctx_init(&ctx);
	sha384_ctx_printf(&ctx);
	printf("DONE\n");
	return 0;
}