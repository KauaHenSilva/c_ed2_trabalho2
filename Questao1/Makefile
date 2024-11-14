all: output main test  

output:
	mkdir -p output

main: test
	gcc -g -I. -o output/main -Wextra -Werror -Wconversion -Wpointer-arith -Wpedantic -Werror=deprecated-declarations -Wformat -Wnull-dereference main.c $(shell find ./src -name '*.c')
	# ./output/main

test: test_arvore_binaria test_arvore_vermelho_preto test_tratamento_de_arquivo test_utils
	clear
	./output/test_arvore_binaria
	./output/test_arvore_vermelho_preto
	./output/test_tratamento_de_arquivo
	./output/test_utils

test_arvore_binaria: 
	gcc -g -I . -o output/test_arvore_binaria tests/test_arvore_binaria.c $(shell find ./src -name '*.c') Unity/unity.c 

test_arvore_vermelho_preto: 
	gcc -g -I . -o output/test_arvore_vermelho_preto tests/test_arvore_vermelho_preto.c $(shell find ./src -name '*.c')  Unity/unity.c

test_tratamento_de_arquivo:
	gcc -g -I . -o output/test_tratamento_de_arquivo tests/test_tratamento_de_arquivo.c $(shell find ./src -name '*.c') Unity/unity.c

test_utils:
	gcc -g -I . -o output/test_utils tests/test_utils.c $(shell find ./src -name '*.c') Unity/unity.c

clean:
	rm -f output/*
