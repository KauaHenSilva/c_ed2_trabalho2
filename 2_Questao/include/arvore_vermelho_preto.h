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

typedef struct st_ArvoreVermelhoPreto
{
  InfoMain info;

  Cor cor;
  struct st_ArvoreVermelhoPreto *esq;
  struct st_ArvoreVermelhoPreto *dir;
} ArvoreVermelhoPreto;

void aloca_arvore_vermelho_preto(ArvoreVermelhoPreto **raiz);
void free_arvore_vermelho_preto(ArvoreVermelhoPreto **raiz);
void def_arvore_vermelho_preto(ArvoreVermelhoPreto *raiz, char *plv_ingles, char *plv_portugues, char *nome_unidade);
void show_arvore_vermelho_preto(const ArvoreVermelhoPreto *raiz);
int inserir_arvore_vermelho_preto(ArvoreVermelhoPreto **raiz, ArvoreVermelhoPreto *new);
int remover_NO_vermelho_preto(ArvoreVermelhoPreto **raiz, const char *plv_portugues);
int remover_arvore_vermelho_preto(ArvoreVermelhoPreto **raiz, const char *plv_portugues);
