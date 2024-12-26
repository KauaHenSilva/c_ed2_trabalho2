#include "include/lista_encadeada.h"
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
  aloca_string(&raiz->info.palavra_ingles, tamanho_string(palavra_ingles));
  strcpy(raiz->info.palavra_ingles, palavra_ingles);
  aloca_lista_encadeada_unidade(&raiz->info.unidades);
  def_lista_encadeada_unidade(raiz->info.unidades, nome_unidade);
}

void free_info_arvore_binaria(InfoArvoreBinaria *info)
{
  free_lista_encadeada_unidade(&info->unidades);
  free(info->palavra_ingles);
}

void copia_arvore_binaria(ArvoreBinaria *recebe, ArvoreBinaria *envia)
{
  aloca_string(&recebe->info.palavra_ingles, tamanho_string(envia->info.palavra_ingles));
  aloca_lista_encadeada_unidade(&recebe->info.unidades);
  strcpy(recebe->info.palavra_ingles, envia->info.palavra_ingles);
  copia_lista_encadeada_unidade(recebe->info.unidades, envia->info.unidades);
}

void free_arvore_binaria(ArvoreBinaria **raiz)
{
  if (*raiz)
  {
    free_arvore_binaria(&(*raiz)->esquerda);
    free_arvore_binaria(&(*raiz)->direita);
    free_info_arvore_binaria(&(*raiz)->info);
    free(*raiz);
  }
}

int insercao_arvore_binaria(ArvoreBinaria **raiz, ArvoreBinaria *new)
{
  int ver = 1;

  if (!*raiz)
    *raiz = new;
  else if (strcmp((*raiz)->info.palavra_ingles, new->info.palavra_ingles) > 0)
    ver = insercao_arvore_binaria(&(*raiz)->esquerda, new);
  else if (strcmp((*raiz)->info.palavra_ingles, new->info.palavra_ingles) < 0)
    ver = insercao_arvore_binaria(&(*raiz)->direita, new);
  else
  {
    ver = inserir_lista_encadeada_unidade(&(*raiz)->info.unidades, new->info.unidades->nome_unidade);
    if (ver)
    {
      free(new->info.palavra_ingles);
      free(new);
    }
  }

  return ver;
}

ArvoreBinaria *so_um_filho(ArvoreBinaria **raiz)
{
  ArvoreBinaria *aux = NULL;
  if ((*raiz)->esquerda == NULL && (*raiz)->direita != NULL)
    aux = (*raiz)->direita;
  else if ((*raiz)->esquerda != NULL && (*raiz)->direita == NULL)
    aux = (*raiz)->esquerda;
  return aux;
}

int eh_folha(ArvoreBinaria **raiz)
{
  int aux = 0;
  if ((*raiz)->esquerda == NULL && (*raiz)->direita == NULL)
    aux = 1;
  return aux;
}

ArvoreBinaria *menor_filho(ArvoreBinaria **raiz)
{
  ArvoreBinaria *aux = NULL;
  if ((*raiz)->esquerda)
    aux = menor_filho(&(*raiz)->esquerda);
  else
    aux = *raiz;

  return aux;
}

void free_value(ArvoreBinaria **raiz)
{
  free_info_arvore_binaria(&(*raiz)->info);
  free(*raiz);
}

int remocao_arvore_binaria(ArvoreBinaria **raiz, const char *palavra_ingles)
{
  int confirm = 1;
  ArvoreBinaria *aux = NULL;

  if (*raiz)
  {
    if (strcmp((*raiz)->info.palavra_ingles, palavra_ingles) == 0)
    {
      if (eh_folha(raiz))
      {
        free_value(raiz);
        *raiz = NULL;
      }
      else if ((aux = so_um_filho(raiz)))
      {
        free_value(raiz);
        *raiz = aux;
      }
      else
      {
        aux = menor_filho(&(*raiz)->direita);
        copia_arvore_binaria(*raiz, aux);
        remocao_arvore_binaria(&(*raiz)->direita, aux->info.palavra_ingles);
      }
    }
  }
  else
    confirm = 0;

  return confirm;
}

void show_arvore_binaria(ArvoreBinaria *raiz)
{
  if (raiz)
  {
    show_arvore_binaria(raiz->esquerda);
    printf("Possivel traducao em ingles: %s\n", raiz->info.palavra_ingles);
    printf("Apareceu em: ");
    show_lista_encadeada_unidade(raiz->info.unidades);
    show_arvore_binaria(raiz->direita);
  }
}