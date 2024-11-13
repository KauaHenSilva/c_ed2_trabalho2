all: output main test  

output:
	mkdir -p output

main: test
	find ./src -name '*.c' | xargs gcc -g -I. -o output/main -Wextra -Werror -Wconversion -Wpointer-arith -Wpedantic -Werror=deprecated-declarations -Wformat -Wnull-dereference main.c
	# ./output/main

test: test_arvore_binaria test_arvore_vermelho_preto
	./output/test_arvore_binaria
	./output/test_arvore_vermelho_preto

test_arvore_binaria: 
	find ./src -name '*.c' | xargs gcc -g -I . -o output/test_arvore_binaria tests/test_arvore_binaria.c Unity/unity.c

test_arvore_vermelho_preto: 
	find ./src -name '*.c' | xargs gcc -g -I . -o output/test_arvore_vermelho_preto tests/test_arvore_vermelho_preto.c Unity/unity.c

clean:
	rm -f output/*
