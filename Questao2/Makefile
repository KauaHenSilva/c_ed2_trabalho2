# Variáveis de Configuração
C_FLAGS = -Wextra -Werror -Wconversion -Wpointer-arith -Wpedantic \
          -Werror=deprecated-declarations -Wformat -Wnull-dereference \
          -Wshadow -Wimplicit-fallthrough \
          -Wunreachable-code -Wduplicated-cond -Wduplicated-branches \
					-Wrestrict -Wnull-dereference -Wdouble-promotion \
					-Wformat-y2k \ -Wunused-result


OUTPUT_DIR = output
TEST_DIR = tests
TEST_FILES = $(shell find $(TEST_DIR) -name '*.c')
TEST_OUTPUTS = $(patsubst $(TEST_DIR)/%.c, $(OUTPUT_DIR)/%, $(TEST_FILES))

all: $(OUTPUT_DIR) test clean

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

main:
	gcc -g -I. -o $(OUTPUT_DIR)/main $(C_FLAGS) main.c $(shell find ./src -name '*.c')
	./$(OUTPUT_DIR)/main

test: $(TEST_OUTPUTS)
	clear
	@for test_binary in $(TEST_OUTPUTS); do \
	    ./$$test_binary; \
	done

test_debug: $(TEST_OUTPUTS)
	echo $(TEST_OUTPUTS)

$(OUTPUT_DIR)/%: $(TEST_DIR)/%.c
	gcc -g -I. -o $@ $(C_FLAGS) $< $(shell find ./src -name '*.c') Unity/unity.c

# Limpeza
clean:
	rm -r $(OUTPUT_DIR)
