#include "include/arvore_binaria.h"
#include <string.h>
#include <stdlib.h>

void aloca_arvore_binaria(ArvoreBinaria **raiz, char *palavra_ingles)
{
  *raiz = (ArvoreBinaria *)malloc(sizeof(ArvoreBinaria));
  (*raiz)->palavra_ingles = palavra_ingles;
  (*raiz)->esquerda = NULL;
  (*raiz)->direita = NULL;
}

int insercao_arvore_binaria(ArvoreBinaria **raiz, ArvoreBinaria *new)
{
  int confirm = 0;

  if (!*raiz)
    *raiz = new;
  else if (strcmp((*raiz)->palavra_ingles, new->palavra_ingles) > 0)
    insercao_arvore_binaria(&(*raiz)->esquerda, new);
  else if (strcmp((*raiz)->palavra_ingles, new->palavra_ingles) < 0)
    insercao_arvore_binaria(&(*raiz)->direita, new);
  else
    confirm = 1;

  return confirm;
}