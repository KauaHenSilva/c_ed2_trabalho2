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

void copia_arvore_vermelho_preto(ArvoreVermelhoPreto *recebe, ArvoreVermelhoPreto *envia)
{
  aloca_arvore_binaria(&recebe->info.arv_binaria_palavra_ingles);
  copia_arvore_binaria(recebe->info.arv_binaria_palavra_ingles, envia->info.arv_binaria_palavra_ingles);
  aloca_string(&recebe->info.palavra_portugues, tamanho_string(envia->info.palavra_portugues));
  strcpy(recebe->info.palavra_portugues, envia->info.palavra_portugues);
}

void free_NO_arvore_vermelho_preto(ArvoreVermelhoPreto **raiz)
{
  free_arvore_binaria(&(*raiz)->info.arv_binaria_palavra_ingles);
  if ((*raiz)->info.palavra_portugues)
    free((*raiz)->info.palavra_portugues);
  free(*raiz);
}

void free_arvore_vermelho_preto(ArvoreVermelhoPreto **raiz)
{
  if (*raiz)
  {
    free_arvore_vermelho_preto(&(*raiz)->esq);
    free_arvore_vermelho_preto(&(*raiz)->dir);
    free_NO_arvore_vermelho_preto(raiz);
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

static Cor pegarCor(const ArvoreVermelhoPreto *raiz)
{
  Cor reposta;
  if (raiz)
    reposta = raiz->cor;
  else
    reposta = PRETO;
  return reposta;
}

void balancear(ArvoreVermelhoPreto **raiz)
{
  if (pegarCor((*raiz)->dir) == VERMELHO && pegarCor((*raiz)->esq) == PRETO)
    rotacao_esquerda(raiz);
  if ((*raiz)->esq && pegarCor((*raiz)->esq) == VERMELHO && pegarCor((*raiz)->esq->esq) == VERMELHO)
    rotacao_direita(raiz);
  if (pegarCor((*raiz)->esq) == VERMELHO && pegarCor((*raiz)->dir) == VERMELHO)
    troca_cor(raiz);
}

static int inserir_NO_vermelha_preta(ArvoreVermelhoPreto **raiz, ArvoreVermelhoPreto *new)
{
  int ver = 1;

  if (!*raiz)
    *raiz = new;
  else if (strcmp(new->info.palavra_portugues, (*raiz)->info.palavra_portugues) < 0)
    ver = inserir_NO_vermelha_preta(&(*raiz)->esq, new);
  else if (strcmp(new->info.palavra_portugues, (*raiz)->info.palavra_portugues) > 0)
    ver = inserir_NO_vermelha_preta(&(*raiz)->dir, new);
  else
    ver = insercao_arvore_binaria(&(*raiz)->info.arv_binaria_palavra_ingles, new->info.arv_binaria_palavra_ingles);

  balancear(raiz);

  return ver;
}

int procurar_arvore_vermelho_preto(ArvoreVermelhoPreto *raiz, const char *plv_portugues, ArvoreVermelhoPreto **result)
{
  int ver = 0;

  if (raiz)
  {
    if (strcmp(plv_portugues, raiz->info.palavra_portugues) < 0)
      ver = procurar_arvore_vermelho_preto(raiz->esq, plv_portugues, result);
    else if (strcmp(plv_portugues, raiz->info.palavra_portugues) > 0)
      ver = procurar_arvore_vermelho_preto(raiz->dir, plv_portugues, result);
    else
    {
      *result = raiz;
      ver = 1;
    }
  }

  return ver;
}

int inserir_arvore_vermelho_preto(ArvoreVermelhoPreto **raiz, ArvoreVermelhoPreto *new)
{
  int ver = inserir_NO_vermelha_preta(raiz, new);
  (*raiz)->cor = PRETO;
  return ver;
}

static void mover_2_esq_RED(ArvoreVermelhoPreto **raiz)
{
  troca_cor(raiz);
  if ((*raiz)->dir && pegarCor((*raiz)->dir->esq) == VERMELHO)
  {
    rotacao_direita(&(*raiz)->dir);
    rotacao_esquerda(raiz);
    troca_cor(raiz);
  }
}

static void mover_2_dir_RED(ArvoreVermelhoPreto **raiz)
{
  troca_cor(raiz);
  if ((*raiz)->esq && pegarCor((*raiz)->esq->esq) == VERMELHO)
  {
    rotacao_direita(raiz);
    troca_cor(raiz);
  }
}

static ArvoreVermelhoPreto *procurar_menor(ArvoreVermelhoPreto *raiz)
{
  ArvoreVermelhoPreto *no1 = raiz;
  ArvoreVermelhoPreto *no2 = raiz->esq;
  while (no2)
  {
    no1 = no2;
    no2 = no2->esq;
  }
  return no1;
}

static int remover_menor(ArvoreVermelhoPreto **raiz)
{
  int ver = 0;

  if (!(*raiz)->esq)
  {
    free_arvore_vermelho_preto(raiz);
    *raiz = NULL;
    ver = 1;
  }
  else
  {
    if (pegarCor((*raiz)->esq) == PRETO && pegarCor((*raiz)->esq->esq) == PRETO)
      mover_2_esq_RED(raiz);
    ver = remover_menor(&(*raiz)->esq);
  }

  if (*raiz)
    balancear(raiz);

  return ver;
}

int remover_NO_vermelho_preto(ArvoreVermelhoPreto **raiz, const char *plv_portugues)
{
  int ver = 0;

  if (*raiz)
  {
    if (strcmp(plv_portugues, (*raiz)->info.palavra_portugues) < 0)
    {
      if ((*raiz)->esq && pegarCor((*raiz)->esq) == PRETO && pegarCor((*raiz)->esq->esq) == PRETO)
        mover_2_esq_RED(raiz);
      ver = remover_NO_vermelho_preto(&(*raiz)->esq, plv_portugues);
    }
    else
    {
      if (pegarCor((*raiz)->esq) == VERMELHO)
        rotacao_direita(raiz);

      if (strcmp((*raiz)->info.palavra_portugues, plv_portugues) == 0 && !(*raiz)->dir)
      {
        free_NO_arvore_vermelho_preto(raiz);
        *raiz = NULL;
        ver = 1;
      }
      else
      {
        if ((*raiz)->dir && pegarCor((*raiz)->dir) == PRETO && pegarCor((*raiz)->dir->esq) == PRETO)
          mover_2_dir_RED(raiz);

        if (strcmp((*raiz)->info.palavra_portugues, plv_portugues) == 0)
        {
          ArvoreVermelhoPreto *aux = procurar_menor((*raiz)->dir);
          copia_arvore_vermelho_preto(*raiz, aux);
          ver = remover_menor(&(*raiz)->dir);
        }
        else
          ver = remover_NO_vermelho_preto(&(*raiz)->dir, plv_portugues);
      }
    }
  }

  if (*raiz)
    balancear(raiz);

  return ver;
}

int remover_arvore_vermelho_preto(ArvoreVermelhoPreto **raiz, const char *plv_portugues)
{
  int ver = remover_NO_vermelho_preto(raiz, plv_portugues);
  if (ver && *raiz)
    (*raiz)->cor = PRETO;
  return ver;
}

void show_arvore_vermelho_preto(const ArvoreVermelhoPreto *raiz)
{
  if (raiz)
  {
    show_arvore_vermelho_preto(raiz->esq);

    (raiz->cor == VERMELHO) ? printf("Cor: VERMELHO\n") : printf("Cor: PRETO\n");
    printf("Palavra em portugues: %s\n", raiz->info.palavra_portugues);
    show_arvore_binaria(raiz->info.arv_binaria_palavra_ingles);

    show_arvore_vermelho_preto(raiz->dir);
  }
}