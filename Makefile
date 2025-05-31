CC = gcc

TEST_FILES = tests/sha512_test.c $(wildcard tests/*.bin)

CFLAGS = -Wall -Wextra -Wpedantic -fPIC

LDFLAGS =

OBJDIR = objs

LIBDIR = lib

STATIC_LIB_NAME = libsha512.a
SHARED_LIB_NAME = libsha512.so
STATIC_LIB = $(addprefix $(LIBDIR)/, $(STATIC_LIB_NAME))
SHARED_LIB = $(addprefix $(LIBDIR)/, $(SHARED_LIB_NAME))

all: $(STATIC_LIB) $(SHARED_LIB)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBDIR):
	@mkdir -p $(LIBDIR)

$(OBJDIR)/sha512.o: src/sha512.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the static library
$(STATIC_LIB): $(OBJDIR)/sha512.o | $(LIBDIR)
	ar rcs $@ $^

$(SHARED_LIB): | $(LIBDIR)
	$(CC) $(CFLAGS) -shared -o $@ $^ $(LDFLAGS) src/sha512.c

test:
	python write_tests.py
	$(CC) $(CFLAGS) src/sha512.c tests/sha512_test.c -o test512
	$(CC) $(CFLAGS) src/sha512.c tests/sha384_test.c -o test384

clean_test:
	rm -f $(TEST_FILES) out.txt test*.exe objs/*

clean_all:
	rm -f $(TEST_FILES) out.txt test*.exe lib/* objs/*

.PHONY: test clean_all clean_test