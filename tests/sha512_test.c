#include "../include/sha512.h"
#include <assert.h>

const char *const fmt = "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X";

int32_t main(void) {
	const char *hash = "F3FAA517467A39A65DEBC010DAB99E899859B0DDFCF32A44D7BCBFF850B9A73DB3D76520B2231E2594866E2411A026CAF823380F43EAEEE45746953CF17ED943";
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

	hash = "0A6515353DEA2478D563900771F87207C3F76E29070E61E61DC2007ECBF070164A595333A6543617D350150065EFA1F3D3F09ED717A771F3D9D4475CC92EF49A";
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

	hash = "39770702429D7F691FC99132503BBCF4ABC9805DBFA9D012FEFD2F0077EE61C25780642380C0CC86F595D67D33C7D50CAC46D88A69596D08AB11CC937140DCF8";
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

	hash = "57B18782D13FA9E142D9C6C4E316A414CC3BDBAE82066FAE551BDB0D75CE5A8F6C38D01343C7ACDF6637651775E129A12FC73E82B5014F0331CE333F029D37EB";
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

	hash = "776D81C64AC293D30E94856A8064AFEB015B3015801B56C0B5B26358F6DE05676F3E67B022C60B8D6ED67BF1F30F7A6B3ABFDDC035D89D5ED7BACEF93F857EEB";
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

	hash = "A02CB3B4CC8439ED3B15E9CFBF784BB2C4E831EDA1AD73DF0087124C7100BE4A8C1A77BDCA7F6E229D54D51B1558BE568C07B7B14E5CC53C23057700C8FC7383";
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

	hash = "2127612A4537B4A3D0F21B341C33DC84C90B0B5F46DE6E196A957C4BCBDA59B4C5324353E161CAE9A176FFCC58D8053B15D207A72A121D9CF7C1998D75E5AF0B";
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

	hash = "1AEDB59C9E0937927CAC57E5ADD1093EC57448A8A4FD353218CB9DFC813B0A19921D57D29E5CD27ACFDCA40446AAAC7681D3CF089A55F93C959F95AACCB06BAE";
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

	hash = "64E77C84B2EC3D54D7FDFF3131766504040FE28F0F8A11B1EC1909C6EFE03F4A24E5F96A9CC3E6ADE34E6791799B20AD4DE10E3896BDB2051CFB9CBC374D50B7";
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

	hash = "FE2B283299ABCAD9E7249BBAEB3F7A17A32BEF84F8CB2042856F63DAB646714AE3C9E1464E67B6619531163D15C7D458BDBD0CF0BF28CD9F9650787DCAD2E4D2";
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