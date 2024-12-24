# Variáveis de Configuração
C_FLAGS = -Wextra -Werror -Wconversion -Wpointer-arith -Wpedantic \
          -Werror=deprecated-declarations -Wformat -Wnull-dereference \
          -Wshadow -Wimplicit-fallthrough \
          -Wunreachable-code -Wduplicated-cond -Wduplicated-branches \
          -Wrestrict -Wnull-dereference -Wdouble-promotion \
          -Wformat-y2k

GCC_FLAGS = -g -I. $(C_FLAGS)

PATH_OUTPUT_DIR = output
PATH_TEST_DIR = tests
PATH_SRC_DIR = src

PATH_UNITY_DIR = $(PATH_TEST_DIR)/Unity
PATH_TEST_FILES = $(shell find $(PATH_TEST_DIR) -name '*.c' -not -path '*/Unity/*')
PATH_SRC_FILES = $(shell find $(PATH_SRC_DIR) -name '*.c')
PATH_TEST_OUTPUTS = $(patsubst $(PATH_TEST_DIR)/%.c, $(PATH_OUTPUT_DIR)/%, $(PATH_TEST_FILES))

COMAND_SEPARATOR = echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"

all: output build_files exec_all_test main

output:
	@mkdir -p $(PATH_OUTPUT_DIR)

# Buildar um arquivo de teste
$(PATH_OUTPUT_DIR)/%: $(PATH_TEST_DIR)/%.c
	@gcc $(GCC_FLAGS) ${PATH_SRC_FILES} $< -o $@ ${PATH_UNITY_DIR}/unity.c >> /dev/null

build_files: $(PATH_TEST_FILES)
	@gcc $(GCC_FLAGS) ${PATH_SRC_FILES} main.c -o $(PATH_OUTPUT_DIR)/main >> /dev/null
	@for test_file in $^; do \
		output_file=$(PATH_OUTPUT_DIR)/$$(basename $$test_file .c); \
		gcc $(GCC_FLAGS) ${PATH_SRC_FILES} $$test_file -o $$output_file ${PATH_UNITY_DIR}/unity.c >> /dev/null; \
	done

main:
	@$(COMAND_SEPARATOR)
	@./$(PATH_OUTPUT_DIR)/main
	@$(COMAND_SEPARATOR)


exec_all_test: build_files
	@for test_file in $(PATH_TEST_OUTPUTS); do \
		${COMAND_SEPARATOR}; \
		./$$test_file; \
	done

clean:
	@rm -rf $(PATH_OUTPUT_DIR)
