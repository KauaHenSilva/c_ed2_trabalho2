#include "include/arvore_binaria.h"
#include "include/utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void aloca_arvore_binaria(ArvoreBinaria **raiz)
{
  *raiz = (ArvoreBinaria *)malloc(sizeof(ArvoreBinaria));
  (*raiz)->esquerda = NULL;
  (*raiz)->direita = NULL;
}

void def_arvore_binaria(ArvoreBinaria *raiz, char *palavra_ingles, char *nome_unidade)
{
  aloca_string(&raiz->palavra_ingles, tamanho_string(palavra_ingles));
  aloca_string(&raiz->nome_unidade, tamanho_string(nome_unidade));
  strcpy(raiz->palavra_ingles, palavra_ingles);
  strcpy(raiz->nome_unidade, nome_unidade);
}

void free_arvore_binaria(ArvoreBinaria **raiz)
{
  if (*raiz)
  {
    free_arvore_binaria(&(*raiz)->esquerda);
    free_arvore_binaria(&(*raiz)->direita);
    free((*raiz)->palavra_ingles);
    free((*raiz)->nome_unidade);
    free(*raiz);
  }
}

int atualizar_nome_unidade(ArvoreBinaria *raiz, char *nome_unidade)
{
  int confirm = 1;

  if (raiz)
    if (!nome_presente(nome_unidade, raiz->nome_unidade))
      juntar_nome_por_virgula(raiz->nome_unidade, nome_unidade, &raiz->nome_unidade);
    else
      confirm = 0;

  return confirm;
}

int insercao_arvore_binaria(ArvoreBinaria **raiz, ArvoreBinaria *new)
{
  int ver = 1;

  if (!*raiz)
    *raiz = new;
  else if (strcmp((*raiz)->palavra_ingles, new->palavra_ingles) > 0)
    ver = insercao_arvore_binaria(&(*raiz)->esquerda, new);
  else if (strcmp((*raiz)->palavra_ingles, new->palavra_ingles) < 0)
    ver = insercao_arvore_binaria(&(*raiz)->direita, new);
  else
    // Se a palavra já estiver presente no dicinário, somente atualiza a unidades que ela apareceu.
    ver = atualizar_nome_unidade(*raiz, new->nome_unidade);

  return ver;
}

int show_arvore_binaria(ArvoreBinaria *raiz)
{
  if (raiz)
  {
    show_arvore_binaria(raiz->esquerda);
    printf("Ingles: %s\n", raiz->palavra_ingles);
    printf("Apareceu em: %s\n", raiz->nome_unidade);
    show_arvore_binaria(raiz->direita);
  }
}