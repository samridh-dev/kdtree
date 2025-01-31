CC = gcc
CFLAGS = -std=c89 -pedantic -Wall -Wextra -Wshadow -Wstrict-prototypes        \
         -Wmissing-prototypes -Wfloat-equal -Wpointer-arith      \
         -Wcast-align -Wwrite-strings -Wredundant-decls -Wnested-externs      \
         -Winline -Wmissing-declarations -Wmissing-format-attribute           \
         -Wformat=2 -Wswitch-default -Wswitch-enum -Wunreachable-code         \
         -Wstrict-aliasing=2 -Wundef                                          \
         -pg -fsanitize=address -fanalyzer                                     
LDFLAGS = -fsanitize=address

BIN_DIR = bin
TEST_DIR = $(BIN_DIR)/tests

.PHONY: all test run-tests clean

all: $(BIN_DIR)/main

$(BIN_DIR)/main: main.c kdtree.h | $(BIN_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $< -O3

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR)

test: $(TEST_DIR) $(patsubst tests/%.c,$(TEST_DIR)/%,$(wildcard tests/*.c))
	@$(MAKE) run-tests

$(TEST_DIR):
	mkdir -p $(TEST_DIR)

$(TEST_DIR)/%: tests/%.c kdtree.h | $(TEST_DIR)
	$(CC) $(LDFLAGS) -o $@ $< -DUSE_STDIO

run-tests:
	@echo "Running all test binaries..."
	@for test_bin in $(TEST_DIR)/*; do \
		$$test_bin; \
	  done
    
    
    
