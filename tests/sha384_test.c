#include "../include/sha512.h"
#include <assert.h>

const char *const fmt = "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X";

int32_t main(void) {
	const char *hash = "0D400188315E28D3A759DFEFB4EC9B4193BAB78722CA756C75E5FCC1CF85EC452D6A99F3FEE289B6FA931CEDA2A6C2DC";
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

	hash = "06D7CF783E8BC7CEE8C917639606772C1BA8328F5437149D35642CA73E29FEA19DAAFB088F56951B9D38150F50C638AF";
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

	hash = "1D37718F1AF28904A469C56052E3D2E1DF50963788517E1C3F89FBF0EA762BD141AB5EB562CF1BE31D638BB42EB87A4E";
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

	hash = "A8E4210DEC39C0E6542FC5D3FC7A0EFCD70DC09AAD90E9B366F4B31946540DD8B6DAC3E1C290016E9212897D6B0A9CAA";
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

	hash = "E86AC3BE1264416623B86D29A8E91C0DB4395A9AC4E31B5D870417F1713A29AEA204C51C432D5448AE11B9D3CA0C093B";
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

	hash = "C29EFF4FDCC09F2C17308C6038A3F28E0E7F4D89619FCB51D90ABB9E899945C7E85631293CE7477C3B679BF55E81A57F";
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

	hash = "34E5EEDA562798208491E6D6FE95D276369F9587265F742A1FA6DDB88212DD6F6A3A9AF0976D8A92A82F85E77DFDE895";
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

	hash = "D5AE3E9BAA60E9A3006FE54B876B8B21E495984170F8A5C2B7674268ADCB6E6D64A3E8E88CF9347C401C624867D5DD52";
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

	hash = "55F6DB5C5FC5B40A7A3DD368F4C0D352474371D2AE7E396F7C1160AFA2B08D781036C3DEBC82F677021511E024AA5D04";
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

	hash = "15CD5447B5BBE1B8C39F3B9ACAAD2EDA6802CEC077B2FCFD13D7367181AFF0B9BE90E32C50C48F10E8272A8A0B04300B";
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