#pragma once

typedef struct st_ArvoreBinaria
{
  char *palavra_ingles;
  char *nome_unidade;

  struct st_ArvoreBinaria *esquerda;
  struct st_ArvoreBinaria *direita;
} ArvoreBinaria;

void aloca_arvore_binaria(ArvoreBinaria **raiz);
void def_arvore_binaria(ArvoreBinaria *raiz, char *palavra_ingles, char *nome_unidade);
void show_arvore_binaria(ArvoreBinaria *raiz);
void free_arvore_binaria(ArvoreBinaria **raiz);
int atualizar_nome_unidade(ArvoreBinaria *raiz, char *nome_unidade);
int insercao_arvore_binaria(ArvoreBinaria **raiz, ArvoreBinaria *new);
