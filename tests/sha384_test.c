#include "../include/sha512.h"
#include <assert.h>

const char *const fmt = "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X";

int32_t main(void) {
	const char *hash = "E124DEED1F58B530F3B1ABC7964DEB37567B3C1D7AF4B3B059AF7273F43E1A989C6222E0B311CA4B2A2C34067F4BCD72";
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

	hash = "D3D3483C1F5E9F0B8A9593AA945E4685CEE0B2A577B578EFAD1AD95C5BEEE8AFF968FEB3A1B54B120E7A941ED87A6481";
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

	hash = "DAAF50B3099CA12E26FAB8E69448CA9BD012134AAAA20703213728D08716B9A9F86B289D06AB6A48D1D10DA1687347CC";
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

	hash = "6C66FAB44F2BFFA25FB5F905B2BBCE90A59274C621A8430FB4A168415B309EE2B771EDA4148596AE75E006E15325C889";
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

	hash = "2588A38024708BE69EC4B1A4C86E01B28A381CE944B1EC4B98247F9848BACAD2E1A38BA63081B5275837D2F0B32246B1";
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

	hash = "2C9000FDB4BA753C6275ADDE2B72A11B372ACF61C5C1BEC6C3BD6CB1407ED3C7E9081017D161A072F045126B80D2718E";
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

	hash = "558DE3063A304178ADE5EA32FB0329EBDE0B25862966CF86F3BC4CF9CA907430D6A33EEA8E16D406F54BA9C2251A4E56";
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

	hash = "E70F8C349778929159981C50576BE28CEDB7CC4C7ECD490BECD9FD96E5C5683298796FE884640BFF26B7BF27AF94AE90";
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

	hash = "7108FCFC9288B0392D0959A45E296A016EFBD5324CA59E440DF47D23C373CC7B86417036E30257BC7578F1694F609CBD";
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

	hash = "A50765B0935BCAA2F07E740C4FB456DFBFC70EE29AA017A1C2D02FD578CBB8E9686779E82159AE300825153F7A5521D0";
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