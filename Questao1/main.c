#include "include/arvore_binaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  ArvoreBinaria *raiz = NULL;

  // Inserção na raiz
  ArvoreBinaria *new;
  aloca_arvore_binaria(&new, "Palavra2");
  printf("%d", insercao_arvore_binaria(&raiz, new));

  // Inserção à esquerda
  // ArvoreBinaria *new2;
  // aloca_arvore_binaria(&new2, "Palavra1");
  // insercao_arvore_binaria(&raiz, new2);

  // Inserção à direita
  // ArvoreBinaria *new3;
  // aloca_arvore_binaria(&new3, "Palavra3");
  // insercao_arvore_binaria(&raiz, new3);

  printf("Fim\n");
  scanf("%*c");
}