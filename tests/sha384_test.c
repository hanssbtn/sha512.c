#include "../include/sha512.h"
#include <assert.h>

const char *const fmt = "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X";

int32_t main(void) {
	const char *hash = "6C041C8C096E2EC8874F68C4BA9FE6955E346B8349BB8C012697A5156D3DA430ED9A6BFC777F9C70D0E5BC56F7B231B3";
	sha384_context_t *ctx = malloc(sizeof(sha512_context_t));
	sha384_ctx_init(ctx);
	uint8_t buf[8192 + 1] = { };
	uint8_t res[48] = { };
	char string[98] = { };
	FILE *file = fopen("tests/sha384_test_0.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha384_test_0.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -1;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha384_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha384_ctx_final(ctx, res, 48) == 0);
	snprintf(string, 97ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47]);
	string[97] = '\0';
	printf("%s\n", string);
	int32_t result = memcmp(string, hash, 96ULL);
	if (result) {
		fprintf(stderr, "Test Case 0 FAILED (got %d)\n", result);
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -1;
	}
	fclose(file);

	hash = "A9BF3D0FAD07926E4417FC5AFF70DB35432ADABDCD75B6C3DD9B42AC18384E81BE6623378880BCBAEC13C9C1076E91EA";
	sha384_ctx_init(ctx);
	file = fopen("tests/sha384_test_1.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha384_test_1.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -2;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha384_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha384_ctx_final(ctx, res, 48) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 96ULL);
	if (result) {
		fprintf(stderr, "Test Case 1 FAILED (got %d)\n", result);	;
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -2;
	}
	fclose(file);

	hash = "AB4424985AB6FB1A5B11FCBBF51222831D3536211032FE4B2111250B5F06D2669012EDFA8D8077A625478B61758A37E0";
	sha384_ctx_init(ctx);
	file = fopen("tests/sha384_test_2.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha384_test_2.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -3;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha384_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha384_ctx_final(ctx, res, 48) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 96ULL);
	if (result) {
		fprintf(stderr, "Test Case 2 FAILED (got %d)\n", result);	;
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -3;
	}
	fclose(file);

	hash = "54F16D82A1A5D72ACD986D877F748C863034969A470CF3945ADCE79BFAADF5B86DD29991F897C6D5CF1B6553431C6A01";
	sha384_ctx_init(ctx);
	file = fopen("tests/sha384_test_3.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha384_test_3.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -4;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha384_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha384_ctx_final(ctx, res, 48) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 96ULL);
	if (result) {
		fprintf(stderr, "Test Case 3 FAILED (got %d)\n", result);	;
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -4;
	}
	fclose(file);

	hash = "20880E542BF5AA0384EF4AE1E339651471F11FD5BCD1A61774BA1201A4604A0A13E7D2DBE3728E734A590E74A6DCB85D";
	sha384_ctx_init(ctx);
	file = fopen("tests/sha384_test_4.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha384_test_4.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -5;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha384_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha384_ctx_final(ctx, res, 48) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 96ULL);
	if (result) {
		fprintf(stderr, "Test Case 4 FAILED (got %d)\n", result);	;
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -5;
	}
	fclose(file);

	hash = "9BD0824B4A42622079B80285A31E61A717E54B499DE828068D7AC9FF7AC098C3D9AB3A366BF722E4884D73F989276226";
	sha384_ctx_init(ctx);
	file = fopen("tests/sha384_test_5.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha384_test_5.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -6;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha384_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha384_ctx_final(ctx, res, 48) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 96ULL);
	if (result) {
		fprintf(stderr, "Test Case 5 FAILED (got %d)\n", result);	;
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -6;
	}
	fclose(file);

	hash = "DB7B722DBA2AB72DDCE02DD0B12AF93E73B5CE758289C56A18B7E7D8C95053AF55672338D251B61F045710EF1DF0A6E8";
	sha384_ctx_init(ctx);
	file = fopen("tests/sha384_test_6.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha384_test_6.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -7;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha384_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha384_ctx_final(ctx, res, 48) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 96ULL);
	if (result) {
		fprintf(stderr, "Test Case 6 FAILED (got %d)\n", result);	;
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -7;
	}
	fclose(file);

	hash = "1901205EA5F9287A8026879A2FCD49D3A185CAB816AEF8379D872582BAD6277FCDB23532CCA4AAF80476074976BFD1D5";
	sha384_ctx_init(ctx);
	file = fopen("tests/sha384_test_7.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha384_test_7.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -8;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha384_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha384_ctx_final(ctx, res, 48) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 96ULL);
	if (result) {
		fprintf(stderr, "Test Case 7 FAILED (got %d)\n", result);	;
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -8;
	}
	fclose(file);

	hash = "A26E08676CCB117CD5250505114C58131A29844AB6B01507D51515418D47001E0F570D36E581967A2BFD02918CE972B7";
	sha384_ctx_init(ctx);
	file = fopen("tests/sha384_test_8.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha384_test_8.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -9;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha384_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha384_ctx_final(ctx, res, 48) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 96ULL);
	if (result) {
		fprintf(stderr, "Test Case 8 FAILED (got %d)\n", result);	;
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -9;
	}
	fclose(file);

	hash = "77629D49419A775404E599D45FC3CEA7A579FA0FCB3DFF267FFAFD4334D5B6BA002912C973289C221429C6113F634B98";
	sha384_ctx_init(ctx);
	file = fopen("tests/sha384_test_9.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha384_test_9.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -10;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha384_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha384_ctx_final(ctx, res, 48) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 96ULL);
	if (result) {
		fprintf(stderr, "Test Case 9 FAILED (got %d)\n", result);	;
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -10;
	}
	fclose(file);

	free(ctx);
	printf("DONE\n");
	return 0;
}