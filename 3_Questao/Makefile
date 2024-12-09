# Variáveis de Configuração
C_FLAGS = -Wextra -Werror -Wconversion -Wpointer-arith -Wpedantic \
          -Werror=deprecated-declarations -Wformat -Wnull-dereference \
          -Wshadow -Wimplicit-fallthrough \
          -Wunreachable-code -Wduplicated-cond -Wduplicated-branches \
					-Wrestrict -Wnull-dereference -Wdouble-promotion \
					-Wformat-y2k


OUTPUT_DIR = output
TEST_DIR = tests
TEST_FILES = $(shell find $(TEST_DIR) -name '*.c')
TEST_OUTPUTS = $(patsubst $(TEST_DIR)/%.c, $(OUTPUT_DIR)/%, $(TEST_FILES))

all: output test main 

output:
	mkdir -p output

main: test
	gcc -g -I. -o output/main ${C_FLAGS} main.c $(shell find ./src -name '*.c')
	./output/main

test:
	clear

clean:
	rm -r output