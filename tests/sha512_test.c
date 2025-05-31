#include "../include/sha512.h"
#include <assert.h>

const char *const fmt = "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X";

int32_t main(void) {
	const char *hash = "BF3678EA9DD46BD590E51D2C7F7466D987A404128D8A196C44D041DF5B69BA8B82343392484DA4998600B6F4F4AE0114B73F91BF280E0CD86DB90BE2ECB0287E";
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

	hash = "67F87163755C2FDF8A47A54E6E73CFAF07073B16464DEC3259739675BFC6EFD3B033FDED9332265122A46BA494C7F879961AD95F76BE4A4253BBC7DBB17A0D5F";
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

	hash = "ABCFD4151D6DBC12B888B9E501C0956813C6E539C9BF4F5E37C7A82E5C0BEED045B4272B1A551ABE3F770A169C92BFFFAFCA1D4F725EA20A6DB9A30ACEDB87FA";
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

	hash = "C3F0664BEEABA6EBDB1B12C356D5822A56780A5E28C8BECAC43708C574A09A77CE284EBF0CAC46AB258F1A84535E0FE386C1637698E2AC0814F98E5D4169A4ED";
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

	hash = "615F5F198EA47381283144759F56854B27481F05C68B53EEF41AF428272D55D87193B8052EA71862635EAAFB95E7FD9D8B6FD24507B67844F3BF73579EEC837C";
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

	hash = "2459275DEC7DC16322D7059FF8A1EB5732E5479ACA30F63148129B90175DE0E0341E694961CB1B2D700CFF918E0349EFE4F14782A532C093B2254AE6130B25AA";
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

	hash = "580693747A5C92DB87B0F5096170DCC1BFA70A47CCB6757AC8BAE4EA1835337DA1A5E8C714ED25B7E02035F6C22A44454AECA6D476E0551E2CB72E43584993D3";
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

	hash = "0FC513EC84D0BF5AD810A0BEAB249FEE09FC16CBD878483EF627C2177E549C6A6CE8442321E157BBB11C9A2092DF537A47CF661367AD2E4B3CB76D1937D8621E";
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

	hash = "C6FBB9AEE2A3DFD41FC5D9801FFA38348630F336667D1231577D385EE5A7192F9F777AA721C28CD057118BCF8419836498B483F771B4A53114F6D98B43541E10";
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

	hash = "A2EA38F8AA66C76A44CFFA97155B29749E376BCEC8ECF6016DF356D7A054D219015429518EB2859227D42817B7E678E9B8B6B45AC5AF0F1ABAA7151F88DFFF70";
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