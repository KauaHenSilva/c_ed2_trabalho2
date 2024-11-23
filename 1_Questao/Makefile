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
	# ./output/main

test: test_arvore_binaria test_arvore_2_3 test_arvore_2_3_insercao test_arvore_2_3_remocao test_tratamento_de_arquivo test_utils test_exibicao_valores test_remocao_valores
	clear
	./output/test_arvore_binaria
	./output/test_arvore_2_3
	./output/test_arvore_2_3_insercao
	./output/test_arvore_2_3_remocao
	./output/test_tratamento_de_arquivo
	./output/test_utils
	./output/test_exibicao_valores
	./output/test_remocao_valores

test_debug: output test_arvore_binaria test_arvore_2_3 test_arvore_2_3_insercao test_arvore_2_3_remocao test_tratamento_de_arquivo test_utils test_exibicao_valores test_remocao_valores
	
test_arvore_binaria: 
	gcc -g -I . -o output/test_arvore_binaria ${C_FLAGS} tests/test_arvore_binaria.c $(shell find ./src -name '*.c') Unity/unity.c 

test_arvore_2_3: 
	gcc -g -I . -o output/test_arvore_2_3 ${C_FLAGS} tests/test_arvore_2_3.c $(shell find ./src -name '*.c')  Unity/unity.c

test_arvore_2_3_insercao:
	gcc -g -I . -o output/test_arvore_2_3_insercao ${C_FLAGS} tests/test_arvore_2_3_insercao.c $(shell find ./src -name '*.c') Unity/unity.c

test_arvore_2_3_remocao:
	gcc -g -I . -o output/test_arvore_2_3_remocao ${C_FLAGS} tests/test_arvore_2_3_remocao.c $(shell find ./src -name '*.c') Unity/unity.c

test_tratamento_de_arquivo:
	gcc -g -I . -o output/test_tratamento_de_arquivo ${C_FLAGS} tests/test_tratamento_de_arquivo.c $(shell find ./src -name '*.c') Unity/unity.c

test_exibicao_valores:
	gcc -g -I . -o output/test_exibicao_valores ${C_FLAGS} tests/test_exibicao_valores.c $(shell find ./src -name '*.c') Unity/unity.c

test_utils:
	gcc -g -I . -o output/test_utils ${C_FLAGS} tests/test_utils.c $(shell find ./src -name '*.c') Unity/unity.c

test_remocao_valores:
	gcc -g -I . -o output/test_remocao_valores ${C_FLAGS} tests/test_remocao_valores.c $(shell find ./src -name '*.c') Unity/unity.c

clean:
	rm -r output