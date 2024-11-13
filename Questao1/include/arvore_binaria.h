#pragma once

typedef struct st_ArvoreBinaria
{
  char *palavra_ingles;

  struct st_ArvoreBinaria *esquerda;
  struct st_ArvoreBinaria *direita;
} ArvoreBinaria;

void aloca_arvore_binaria(ArvoreBinaria **raiz, char *palavra_ingles);
int insercao_arvore_binaria(ArvoreBinaria **raiz, ArvoreBinaria *new);