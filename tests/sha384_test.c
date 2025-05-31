#include "../include/sha512.h"
#include <assert.h>

const char *const fmt = "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X";

int32_t main(void) {
	const char *hash = "D2A2BF4ADDF58F20BFCAFA01E3D4B07FD9D41EBB661AE9DACFEC027F1DBFFA895BEE3E3334B485BD4819009AF9EFFAD8";
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

	hash = "C0B7D8F761094C7BB01BC44A89B0D2EFB4AC0521A8DD7178E1D2B05EC62F17BF8EC4D827FAA66C8826BA7F6A81F4BAF1";
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

	hash = "EB6426C0D8E9ED56B76F255BDB58A474B8F68D7CB80472A7264B41C022F2EAE057453596E1E6374A91CD1EEC69CF470C";
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

	hash = "E406DE90A798F3893BD8B15B532DEEA8AC69E76E6880582E7EF60EC80A1C0905D1C6AE0498F4E8CB527C6B8262F56E0F";
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

	hash = "8FE2CF7BC6C3B4920FA6E3185E54ACC9C995C95F42E9E8836CF557BCC72525C380D82FD41125DB8B598C9BE53F931CB7";
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

	hash = "C978B7EE7AF28449F96D073FEF9C9620419C0E4742D26C7B3FF64F4DD5B4104C5E9640D01BF9539C35E0F4BC66830C53";
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

	hash = "7E86CBD334BB737ED8AB19A2B1F554A82ABEE3B4CB3654405971CA978A7E41A0CCCCE5706019C31727ADE8C278CAB305";
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

	hash = "A7BB17AD1FD6921232F6B8A7FB4FF12EB2CCE1CBA188C9411E4CF6552457684D87863144DE517E383CEA1BE78436D0E5";
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

	hash = "2264320F6AE31ABD8F8B9EDCCCC8C9A5050D94E439BE2D66880E260D65192931904ABC57EF31EDF854691C866A2144BC";
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

	hash = "079B702FC44286A2CCF4E3E1060A4791037C03F88665B23E53E542CC3C249B9B518E3E736319E3A01B2EA0F5A50F5066";
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