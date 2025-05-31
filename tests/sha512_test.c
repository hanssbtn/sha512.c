#include "../include/sha512.h"
#include <assert.h>

const char *const fmt = "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X";

int32_t main(void) {
	const char *hash = "FF22ACAB56AD6F29CD41FDE0E24C02F50438845BD1D2A660C7E3118A674BEC967A684807E17CE77944053581791D0CE856FDE7015B84AB58323C6E2315EAFE75";
	sha512_context_t *ctx = malloc(sizeof(sha512_context_t));
	sha512_ctx_init(ctx);
	uint8_t buf[8192 + 1] = { };
	uint8_t res[64] = { };
	char string[130] = { };
	FILE *file = fopen("tests/sha512_test_0.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha512_test_0.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -1;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha512_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha512_ctx_final(ctx, res, 64) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47],res[48],res[49],res[50],res[51],res[52],res[53],res[54],res[55],res[56],res[57],res[58],res[59],res[60],res[61],res[62],res[63]);
	string[129] = '\0';
	printf("%s\n", string);
	int32_t result = memcmp(string, hash, 128ULL);
	if (result) {
		fprintf(stderr, "Test Case 0 FAILED (got %d)\n", result);
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -1;
	}
	fclose(file);

	hash = "70C686BF8E59F552FDC0FA3EAEEDF150B8DDE320926D2FF6647F620D669FFD62C59ECEE483E6FB35AC9C5FE42E8AA27FCE2C0C63E258B16B87083E5F524665A9";
	sha512_ctx_init(ctx);
	file = fopen("tests/sha512_test_1.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha512_test_1.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -2;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha512_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha512_ctx_final(ctx, res, 64) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47],res[48],res[49],res[50],res[51],res[52],res[53],res[54],res[55],res[56],res[57],res[58],res[59],res[60],res[61],res[62],res[63]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 128ULL);
	if (memcmp(string, hash, 128ULL)) {
		fprintf(stderr, "Test Case 1 FAILED (got %d)\n", result);	;
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -2;
	}
	fclose(file);

	hash = "C578FB97391370A32952FC6914814721B43004EDB0C2FF026ADBF43A9B7CAF5CF5329F0C55D9426C77B96DD07F25427B7AAB6E2170F240D3993BD068678C3CA4";
	sha512_ctx_init(ctx);
	file = fopen("tests/sha512_test_2.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha512_test_2.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -3;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha512_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha512_ctx_final(ctx, res, 64) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47],res[48],res[49],res[50],res[51],res[52],res[53],res[54],res[55],res[56],res[57],res[58],res[59],res[60],res[61],res[62],res[63]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 128ULL);
	if (memcmp(string, hash, 128ULL)) {
		fprintf(stderr, "Test Case 2 FAILED (got %d)\n", result);	;
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -3;
	}
	fclose(file);

	hash = "EED958DEFDBD2459CBFE0E94236BFDD5A7385FB70F918C34908E6A04CF5EDF9C3261D806C558E62A81FD2AADB98F58DE451829C8260F2B67B9D1B0A6881D9646";
	sha512_ctx_init(ctx);
	file = fopen("tests/sha512_test_3.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha512_test_3.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -4;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha512_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha512_ctx_final(ctx, res, 64) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47],res[48],res[49],res[50],res[51],res[52],res[53],res[54],res[55],res[56],res[57],res[58],res[59],res[60],res[61],res[62],res[63]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 128ULL);
	if (memcmp(string, hash, 128ULL)) {
		fprintf(stderr, "Test Case 3 FAILED (got %d)\n", result);	;
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -4;
	}
	fclose(file);

	hash = "4590C66416574ECC9292EE174111DA65AE118A1CB8150DB84456381994ABA5FA19B6C536BA37DF71AFC2FE511B3A8989B186C508668F89BBEC01DB460B6E37B1";
	sha512_ctx_init(ctx);
	file = fopen("tests/sha512_test_4.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha512_test_4.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -5;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha512_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha512_ctx_final(ctx, res, 64) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47],res[48],res[49],res[50],res[51],res[52],res[53],res[54],res[55],res[56],res[57],res[58],res[59],res[60],res[61],res[62],res[63]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 128ULL);
	if (memcmp(string, hash, 128ULL)) {
		fprintf(stderr, "Test Case 4 FAILED (got %d)\n", result);	;
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -5;
	}
	fclose(file);

	hash = "7EF4CD98DC6EF4DC561E069D5E32F14C98E92EC084B5F3C2AD78156ACA433EC0DDE405B6D5C17C9BFC667CE17F52E17AB3EBEDC9D175E8E405DA521044142882";
	sha512_ctx_init(ctx);
	file = fopen("tests/sha512_test_5.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha512_test_5.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -6;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha512_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha512_ctx_final(ctx, res, 64) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47],res[48],res[49],res[50],res[51],res[52],res[53],res[54],res[55],res[56],res[57],res[58],res[59],res[60],res[61],res[62],res[63]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 128ULL);
	if (memcmp(string, hash, 128ULL)) {
		fprintf(stderr, "Test Case 5 FAILED (got %d)\n", result);	;
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -6;
	}
	fclose(file);

	hash = "65E43D6D96918F98C837C7CD8585CE5AE40074C7949EE49225524F315841AEC8AE0F2A6A3DA37BC0E66027AE6C8536B0A9998E1B2F865C37803DD9AF81F72954";
	sha512_ctx_init(ctx);
	file = fopen("tests/sha512_test_6.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha512_test_6.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -7;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha512_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha512_ctx_final(ctx, res, 64) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47],res[48],res[49],res[50],res[51],res[52],res[53],res[54],res[55],res[56],res[57],res[58],res[59],res[60],res[61],res[62],res[63]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 128ULL);
	if (memcmp(string, hash, 128ULL)) {
		fprintf(stderr, "Test Case 6 FAILED (got %d)\n", result);	;
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -7;
	}
	fclose(file);

	hash = "94489E2588070729B266D9EC602CB7F103DDFF705B93BED8DE7DFCBFB86903ACF348C61FCF1891843E06ADCA68CD9F1FA387C58539028F681318A65A0A3845A7";
	sha512_ctx_init(ctx);
	file = fopen("tests/sha512_test_7.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha512_test_7.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -8;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha512_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha512_ctx_final(ctx, res, 64) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47],res[48],res[49],res[50],res[51],res[52],res[53],res[54],res[55],res[56],res[57],res[58],res[59],res[60],res[61],res[62],res[63]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 128ULL);
	if (memcmp(string, hash, 128ULL)) {
		fprintf(stderr, "Test Case 7 FAILED (got %d)\n", result);	;
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -8;
	}
	fclose(file);

	hash = "C821E7C9348EA69FD6911C0DF838C7E8BCAFE1B2AC49F2C19D1067EBC2DEA871F1F560A5B805504F8A63DBB4D726961301176809AA6C96FD0C32587E497BE6A1";
	sha512_ctx_init(ctx);
	file = fopen("tests/sha512_test_8.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha512_test_8.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -9;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha512_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha512_ctx_final(ctx, res, 64) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47],res[48],res[49],res[50],res[51],res[52],res[53],res[54],res[55],res[56],res[57],res[58],res[59],res[60],res[61],res[62],res[63]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 128ULL);
	if (memcmp(string, hash, 128ULL)) {
		fprintf(stderr, "Test Case 8 FAILED (got %d)\n", result);	;
		printf("hash: %s\n", hash);
		printf("string: %s\n", string);
		free(ctx);
		fclose(file);
		return -9;
	}
	fclose(file);

	hash = "C889DD3D1A1F8132B99C3CA74A0D8A6E806F371DA47BADE7792689BCB5EF32B27A380DD917C5BB1F1CDA72B534AD7438D8B951323300A1479257AA9D6F0A055B";
	sha512_ctx_init(ctx);
	file = fopen("tests/sha512_test_9.bin", "rb");
	if (!file) {
		fprintf(stderr, "Cannot open sha512_test_9.bin. Please run the test from the project root directory.\n");
		free(ctx);
		return -10;
	}
	for (;;) {
		ssize_t len = fread(buf, sizeof(uint8_t), 8192ULL, file);
		if (!len) break;
		assert(sha512_ctx_update(ctx, buf, len) == 0);
	}
	assert(sha512_ctx_final(ctx, res, 64) == 0);
	snprintf(string, 129ULL, fmt, res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26],res[27],res[28],res[29],res[30],res[31],res[32],res[33],res[34],res[35],res[36],res[37],res[38],res[39],res[40],res[41],res[42],res[43],res[44],res[45],res[46],res[47],res[48],res[49],res[50],res[51],res[52],res[53],res[54],res[55],res[56],res[57],res[58],res[59],res[60],res[61],res[62],res[63]);
	string[129] = '\0';
	printf("%s\n", string);
	result = memcmp(string, hash, 128ULL);
	if (memcmp(string, hash, 128ULL)) {
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