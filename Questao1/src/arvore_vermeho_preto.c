#include "include/arvore_vermelho_preto.h"
#include "include/arvore_binaria.h"
#include "include/utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void aloca_arvore_vermelho_preto(ArvoreVermelhoPreto **raiz)
{
  *raiz = (ArvoreVermelhoPreto *)malloc(sizeof(ArvoreVermelhoPreto));
  (*raiz)->cor = VERMELHO;
  (*raiz)->esq = NULL;
  (*raiz)->dir = NULL;
}

void def_arvore_vermelho_preto(ArvoreVermelhoPreto *raiz, char *plv_ingles, char *plv_portugues, char *nome_unidade)
{
  aloca_arvore_binaria(&raiz->info.arv_binaria_palavra_ingles);
  def_arvore_binaria(raiz->info.arv_binaria_palavra_ingles, plv_ingles, nome_unidade);
  aloca_string(&raiz->info.palavra_portugues, tamanho_string(plv_portugues));
  strcpy(raiz->info.palavra_portugues, plv_portugues);
}

void free_arvore_vermelho_preto(ArvoreVermelhoPreto **raiz)
{
  if (*raiz)
  {
    free_arvore_vermelho_preto(&(*raiz)->esq);
    free_arvore_vermelho_preto(&(*raiz)->dir);
    free_arvore_binaria(&(*raiz)->info.arv_binaria_palavra_ingles);
    if ((*raiz)->info.palavra_portugues)
      free((*raiz)->info.palavra_portugues);
    free(*raiz);
  }
}

static void rotacao_esquerda(ArvoreVermelhoPreto **raiz)
{
  ArvoreVermelhoPreto *aux = (*raiz)->dir;
  (*raiz)->dir = aux->esq;
  aux->esq = *raiz;
  aux->cor = (*raiz)->cor;
  (*raiz)->cor = VERMELHO;
  *raiz = aux;
}

static void rotacao_direita(ArvoreVermelhoPreto **raiz)
{
  ArvoreVermelhoPreto *aux = (*raiz)->esq;
  (*raiz)->esq = aux->dir;
  aux->dir = *raiz;
  aux->cor = (*raiz)->cor;
  (*raiz)->cor = VERMELHO;
  *raiz = aux;
}

static void troca_cor(ArvoreVermelhoPreto **raiz)
{
  (*raiz)->cor = !(*raiz)->cor;
  if ((*raiz)->esq)
    (*raiz)->esq->cor = !(*raiz)->esq->cor;
  if ((*raiz)->dir)
    (*raiz)->dir->cor = !(*raiz)->dir->cor;
}

static Cor pegarCor(ArvoreVermelhoPreto *raiz)
{
  Cor reposta;
  if (raiz)
    reposta = raiz->cor;
  else
    reposta = PRETO;
  return reposta;
}

static int inserir_NO_vermelha_preta(ArvoreVermelhoPreto **raiz, ArvoreVermelhoPreto *new)
{
  int ver = 1;

  if (!*raiz)
    *raiz = new;
  else if (strcmp((*raiz)->info.palavra_portugues, new->info.palavra_portugues) > 0)
    ver = inserir_NO_vermelha_preta(&(*raiz)->esq, new);
  else if (strcmp((*raiz)->info.palavra_portugues, new->info.palavra_portugues) < 0)
    ver = inserir_NO_vermelha_preta(&(*raiz)->dir, new);
  else
    ver = insercao_arvore_binaria(&(*raiz)->info.arv_binaria_palavra_ingles, new->info.arv_binaria_palavra_ingles);

  if (pegarCor((*raiz)->dir) == VERMELHO && pegarCor((*raiz)->esq) == PRETO)
    rotacao_esquerda(raiz);

  if (pegarCor((*raiz)->esq) == VERMELHO && pegarCor((*raiz)->esq->esq) == VERMELHO)
    rotacao_direita(raiz);

  if (pegarCor((*raiz)->esq) == VERMELHO && pegarCor((*raiz)->dir) == VERMELHO)
    troca_cor(raiz);

  return ver;
}

int inserir_arvore_vermelho_preto(ArvoreVermelhoPreto **raiz, ArvoreVermelhoPreto *new)
{
  int ver = inserir_NO_vermelha_preta(raiz, new);
  (*raiz)->cor = PRETO;
  return ver;
}

int show_arvore_vermelho_preto(ArvoreVermelhoPreto *raiz)
{
  if (raiz)
  {
    show_arvore_vermelho_preto(raiz->esq);
    printf("Cor: %d\n", raiz->cor);
    printf("Palavra em portugues: %s\n", raiz->info.palavra_portugues);
    show_arvore_binaria(raiz->info.arv_binaria_palavra_ingles);
    show_arvore_vermelho_preto(raiz->dir);
  }
}