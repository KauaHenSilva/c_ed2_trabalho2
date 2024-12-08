#include "include/remocao_valores.h"
#include "include/arvore_vermelho_preto.h"
#include "include/lista_encadeada.h"
#include <stdio.h>
#include <string.h>

int _remove_palavra_ingles_unidade(ArvoreVermelhoPreto **raiz, const char *palavra_ingles, const char *unidade)
{
  int confirm = 1;
  int removel_vermelho_preto = 0;

  if (*raiz)
  {
    confirm = remove_palavra_ingles_unidade(&(*raiz)->esq, palavra_ingles, unidade);
    confirm = remove_palavra_ingles_unidade(&(*raiz)->dir, palavra_ingles, unidade);

    ArvoreBinaria *aux = (*raiz)->info.arv_binaria_palavra_ingles;
    int achou = 0;
    while (aux && !achou)
    {
      if (strcmp(aux->info.palavra_ingles, palavra_ingles) == 0)
      {
        confirm = remover_lista_encadeada_unidade(&aux->info.unidades, unidade);
        achou = 1;
      }
      else if (strcmp(aux->info.palavra_ingles, palavra_ingles) > 0)
        aux = aux->esquerda;
      else
        aux = aux->direita;
    }

    if (aux && !aux->info.unidades)
      confirm = remocao_arvore_binaria(&(*raiz)->info.arv_binaria_palavra_ingles, palavra_ingles);

    if (*raiz && !(*raiz)->info.arv_binaria_palavra_ingles)
      confirm = removel_vermelho_preto = remover_NO_vermelho_preto(raiz, (*raiz)->info.palavra_portugues);
  }

  if (*raiz && removel_vermelho_preto)
    balancear(raiz);

  return confirm;
}

int remove_palavra_ingles_unidade(ArvoreVermelhoPreto **raiz, const char *palavras_ingles, const char *unidade)
{
  _remove_palavra_ingles_unidade(raiz, palavras_ingles, unidade);
  if (*raiz)
    (*raiz)->cor = PRETO;
  return 1;
}

int _remove_palavra_portugues_unidade(ArvoreBinaria **raiz, const char *palavra_portugues, const char *unidade)
{
  int confirm = 1;
  if (*raiz)
  {
    confirm = _remove_palavra_portugues_unidade(&(*raiz)->esquerda, palavra_portugues, unidade);
    confirm = _remove_palavra_portugues_unidade(&(*raiz)->direita, palavra_portugues, unidade);

    ListaEncadeadaUnidade *aux_unidades = (*raiz)->info.unidades;
    int achou = 0;
    while (aux_unidades && !achou)
    {
      if (strcmp(aux_unidades->nome_unidade, unidade) == 0)
      {
        confirm = remover_lista_encadeada_unidade(&(*raiz)->info.unidades, unidade);
        achou = 1;
      }
      aux_unidades = aux_unidades->prox;
    }

    if (*raiz && !(*raiz)->info.unidades)
      remocao_arvore_binaria(raiz, (*raiz)->info.palavra_ingles);
  }
}

int remove_palavra_portugues_unidade(ArvoreVermelhoPreto **raiz, const char *palavra_portugues, const char *unidade)
{
  int confirm = 1;
  int removel_vermelho_preto = 0;

  if (*raiz)
  {
    if (strcmp((*raiz)->info.palavra_portugues, palavra_portugues) == 0)
    {
      confirm = _remove_palavra_portugues_unidade(&(*raiz)->info.arv_binaria_palavra_ingles, palavra_portugues, unidade);
      if (!(*raiz)->info.arv_binaria_palavra_ingles)
        confirm = removel_vermelho_preto = remover_NO_vermelho_preto(raiz, palavra_portugues);
    }
    else if (strcmp((*raiz)->info.palavra_portugues, palavra_portugues) > 0)
      confirm = remove_palavra_portugues_unidade(&(*raiz)->esq, palavra_portugues, unidade);
    else
      confirm = remove_palavra_portugues_unidade(&(*raiz)->dir, palavra_portugues, unidade);
  }

  if (*raiz && removel_vermelho_preto)
    balancear(raiz);

  return 0;
}