#pragma once

#include "include/lista_encadeada.h"

typedef struct st_info_ArvoreBinaria
{
  char *palavra_ingles;
  ListaEncadeadaUnidade *unidades;
} InfoArvoreBinaria;

typedef struct st_ArvoreBinaria
{
  InfoArvoreBinaria info;
  struct st_ArvoreBinaria *esquerda;
  struct st_ArvoreBinaria *direita;
} ArvoreBinaria;

void aloca_arvore_binaria(ArvoreBinaria **raiz);
void def_arvore_binaria(ArvoreBinaria *raiz, char *palavra_ingles, char *nome_unidade);
void copia_arvore_binaria(ArvoreBinaria *recebe, ArvoreBinaria *envia);
void show_arvore_binaria(ArvoreBinaria *raiz);
void free_arvore_binaria(ArvoreBinaria **raiz);
int insercao_arvore_binaria(ArvoreBinaria **raiz, ArvoreBinaria *new);
ArvoreBinaria *so_um_filho(ArvoreBinaria **raiz);
ArvoreBinaria *menor_filho(ArvoreBinaria **raiz);
int remocao_arvore_binaria(ArvoreBinaria **raiz, const char *palavra_ingles);