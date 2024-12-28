#pragma once

#include "include/arvore_binaria.h"

typedef enum en_COR
{
  VERMELHO = 0,
  PRETO = 1
} Cor;

typedef struct st_InfoMain
{
  ArvoreBinaria *arv_binaria_palavra_ingles;
  char *palavra_portugues;
} InfoMain;

typedef struct st_Arvore_2_3
{
  InfoMain info1;
  InfoMain info2;

  int n_info;
  struct st_Arvore_2_3 *esquerda;
  struct st_Arvore_2_3 *centro;
  struct st_Arvore_2_3 *direita;
} Arvore_2_3;

// Funções de alocação e liberação
void def_info_arvore_2_3(InfoMain *info, char *plv_ingles, char *plv_portugues, char *nome_unidade);
void free_info_arvore_2_3(InfoMain *info);
void copia_info_arvore_2_3(InfoMain *info, InfoMain *info2);
void aloca_arvore_2_3(Arvore_2_3 **raiz);
void show_arvore_2_3(const Arvore_2_3 *raiz);
void free_arvore_2_3(Arvore_2_3 *raiz);

int eh_folha_arvore_2_3(Arvore_2_3 *raiz);
void cria_no(Arvore_2_3 **new, InfoMain info, Arvore_2_3 *esquerda, Arvore_2_3 *centro);
int adicionando_valor_em_arvore_2_3(Arvore_2_3 *raiz, InfoMain info, Arvore_2_3 *filho);
void quebra_no(Arvore_2_3 **raiz, Arvore_2_3 **new_node, InfoMain info, InfoMain *info_up, Arvore_2_3 *filho);
int inserir_arvore_2_3(Arvore_2_3 **raiz, InfoMain info);

int arvore23_remover_nao_folha1(Arvore_2_3 **origem, Arvore_2_3* raiz, InfoMain *info, Arvore_2_3 *filho1, Arvore_2_3 *filho2, Arvore_2_3 **maior);
int arvore23_remover_nao_folha2(Arvore_2_3 **origem, Arvore_2_3* raiz, InfoMain *info, Arvore_2_3 *filho1, Arvore_2_3 *filho2, Arvore_2_3 **maior);
int arvore23_remover1(Arvore_2_3 **raiz, char *info, Arvore_2_3 *pai, Arvore_2_3 **origem, Arvore_2_3 **maior);
int arvore23_remover2(Arvore_2_3 **raiz, char *info, Arvore_2_3 *pai, Arvore_2_3 **origem, Arvore_2_3 **maior);
int arvore_2_3_remover(Arvore_2_3 **raiz, char *info);