#include "include/arvore_vermelho_preto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void aloca_arvore_vermelho_preto(ArvoreVermelhoPreto **raiz, InfoMain *info)
{
  *raiz = (ArvoreVermelhoPreto *)malloc(sizeof(ArvoreVermelhoPreto));
  (*raiz)->info = *info;
  (*raiz)->cor = VERMELHO;
  (*raiz)->esq = NULL;
  (*raiz)->dir = NULL;
}

static void rotacao_esquerda(ArvoreVermelhoPreto **raiz)
{
  ArvoreVermelhoPreto *aux = (*raiz)->dir;
  (*raiz)->dir = aux->esq;
  aux->esq = *raiz;
  aux->cor = (*raiz)->cor;
  *raiz = aux;
  (*raiz)->cor = PRETO;
}

static void rotacao_direita(ArvoreVermelhoPreto **raiz)
{
  ArvoreVermelhoPreto *aux = (*raiz)->esq;
  (*raiz)->esq = aux->dir;
  aux->dir = *raiz;
  aux->cor = (*raiz)->cor;
  *raiz = aux;
  (*raiz)->cor = PRETO;
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
    ver = 0;

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