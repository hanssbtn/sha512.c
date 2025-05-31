#include "../include/sha512.h"
#include <assert.h>

const char *const fmt = "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X";

int32_t main(void) {
	const char *hash = "69774FA3D5F7E7FC91857C41AFCA8EA3AED952ADE07065626A382C530F45C611F5A703DBB3634511084C55D0371050320258C0DA6CCFA6A2A8813893CDFCDFCF";
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

	hash = "111BD93125D78EE8FBEF93433FB3D29DF085954B23AC794CB6DC7004D06C0A8E88F56662BCAC201ED0F5D0454973EC6C2071144B6321ED58A13E68DCC6BDC352";
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

	hash = "24B2A7659AEF667B821CB0ED5E1B43E9D3EBB43012A3BFD8B312BB6AEF98192780F1B4D3947EF7AFA2BDB46C09949EFA1DB5202214D97EB53C91495182C540A2";
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

	hash = "A6DE9285AACDE03CB71414CC68FEAABA226DA9E8B79B1055AA669052E70A090198339F17CC4ACF63135ABFAF619EDB686424B70E9A34CF586A4FC692620DEE7F";
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

	hash = "A59A582317EEA86B094C3931BED3B61AEF6F2C6C0AD37E1B393E328B708DE1FB6E4A6A588F4D024C7D1B054C1C8EA6FF6D51655B439BDFC1848678DC5A12CE57";
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

	hash = "46C13A2A228D4F1C836A0DF61CFF49408CC0A11CDFF7FD9F275672015590AB5EE60259BD8E51B542DC9B6D88A75DF5D0E41A244953B59C1AEF3DFD386067DA26";
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

	hash = "EC8E474331D0C4DB68924A27153D558D65494A06296DAAC0F189FEBCA0AF31569ED701D3CC51F2670418B664701D40A858EA625B35557DFD6B59FC68CF835F58";
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

	hash = "B8623A7E3726AF5F9222E1E8D5C68E90E9C024C868ADCA427639483F080AF64980DA2D869F9601BC574C8B1AE9C1FE5652F48B1AC53E81AD5A623E76C6A8A50B";
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

	hash = "16DA59AB04EA35F2525BB2E9A46CBC3F5F909DA4B5FC360A179FAC18E1AAD5AF5377F76D6B39B9E7AE487D41114F50650DD8E1307DDBD247AEB881F3E4E9FBE3";
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

	hash = "94F385A16E0B12DB3643D6CA1FF97E4A892D94C82309D85CA4516B4507AF5EB4C28158077954806FCAA8487B38331276917A3F56037B4810018B3BDA5993B627";
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