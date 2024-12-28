#include "include/arvore_2_3.h"
#include <stdlib.h>
#include <stdio.h>

int criar_arvore_2_3(Arvore_2_3 **arvore, Informacao info, Arvore_2_3 *esquerda, Arvore_2_3 *meio)
{
  int confirm = 1;

  *arvore = (Arvore_2_3 *)malloc(sizeof(Arvore_2_3));
  if (*arvore)
  {
    (*arvore)->info1 = info;
    (*arvore)->esquerda = esquerda;
    (*arvore)->meio = meio;
    (*arvore)->qtd_info = 1;
  }
  else
  {
    printf("Impossível alocar memória para a árvore 2-3, abortando...\n");
    exit(1);
  }

  return confirm;
}

void free_arvore_2_3(Arvore_2_3 *arvore)
{
  if (arvore)
  {
    free_arvore_2_3(arvore->esquerda);
    free_arvore_2_3(arvore->meio);
    if (arvore->qtd_info == 2)
      free_arvore_2_3(arvore->direita);
    free(arvore);
  }
}

void show_arvore_2_3(Arvore_2_3 *raiz)
{
  if (raiz)
  {
    show_arvore_2_3(raiz->esquerda);
    printf("Info1: %d - %d - %c\n", raiz->info1.inicio, raiz->info1.final, raiz->info1.status);
    show_arvore_2_3(raiz->meio);
    if (raiz->qtd_info == 2)
    {
      printf("Info2: %d - %d - %c\n", raiz->info2.inicio, raiz->info2.final, raiz->info2.status);
      show_arvore_2_3(raiz->direita);
    }
  }
}

int adicionar_informacao(Arvore_2_3 *raiz, Informacao info, Arvore_2_3 *filho)
{
  if (raiz->qtd_info == 1)
  {
    if (info.inicio > raiz->info1.inicio)
    {
      raiz->info2 = info;
      raiz->direita = filho;
    }
    else
    {
      raiz->info2 = raiz->info1;
      raiz->info1 = info;
      raiz->direita = raiz->meio;
      raiz->meio = filho;
    }
    raiz->qtd_info = 2;
  }
}

int eh_folha(Arvore_2_3 *raiz)
{
  return !raiz->esquerda;
}

void no_com_tamanho_livre(Arvore_2_3 **no_adequado, int *info_correspodente, Arvore_2_3 *arvore, int tamanho)
{
  if (arvore)
  {
    if ((arvore->info1.status == LIVRE) && ((arvore->info1.final - arvore->info1.inicio) > tamanho))
    {
      *no_adequado = arvore;
      *info_correspodente = 1;
    }
    else if ((arvore->qtd_info == 2) && (arvore->info2.status == LIVRE) && (arvore->info2.final - arvore->info2.inicio) > tamanho)
    {
      *no_adequado = arvore;
      *info_correspodente = 2;
    }
    else
    {
      no_com_tamanho_livre(no_adequado, info_correspodente, arvore->esquerda, tamanho);
      no_com_tamanho_livre(no_adequado, info_correspodente, arvore->meio, tamanho);
      if (arvore->qtd_info == 2)
        no_com_tamanho_livre(no_adequado, info_correspodente, arvore->direita, tamanho);

      if (!*no_adequado)
      {
        if ((arvore->info1.status == LIVRE) && ((arvore->info1.final - arvore->info1.inicio) == tamanho))
        {
          *no_adequado = arvore;
          *info_correspodente = 1;
        }
        else if ((arvore->qtd_info == 2) && (arvore->info2.status == LIVRE) && ((arvore->info2.final - arvore->info2.inicio) == tamanho))
        {
          *no_adequado = arvore;
          *info_correspodente = 2;
        }
      }
    }
  }
}

void ocupar_no(Arvore_2_3 *arvore, int tamanho)
{
  Arvore_2_3 *no_valido = NULL;
  int info_corespondente = 0;

  no_com_tamanho_livre(&no_valido, &info_corespondente, arvore, tamanho);
  if (no_valido)
  {
    if (info_corespondente == 1)
    {
      if (no_valido->info1.final - no_valido->info1.inicio == tamanho)
      {
        set_info(&no_valido->info1, no_valido->info1.inicio, no_valido->info1.final, OCUPADA);
        // balancear
      }
      else
      {
        printf("Situação não tratada\n");
      }
    }
    else
    {
      if (no_valido->info2.final - no_valido->info2.inicio == tamanho)
      {
        set_info(&no_valido->info2, no_valido->info2.inicio, no_valido->info2.final, OCUPADA);
        // balancear
      }
      else
      {
        printf("Situação não tratada\n");
      }
    }
  }
  else
  {
    printf("Não foi possível encontrar um nó com tamanho livre suficiente\n");
  }
}

void quebra_no(Arvore_2_3 **raiz, Informacao info, Arvore_2_3 **novo_no, Informacao *info_para_cima, Arvore_2_3 *filho)
{
  if (info.inicio > (*raiz)->info1.inicio)
  {
    *info_para_cima = (*raiz)->info2;
    criar_arvore_2_3(novo_no, info, (*raiz)->direita, filho);
  }
  else if (info.inicio > (*raiz)->info2.inicio)
  {
    *info_para_cima = info;
    criar_arvore_2_3(novo_no, (*raiz)->info2, filho, (*raiz)->direita);
  }
  else
  {
    *info_para_cima = (*raiz)->info1;
    criar_arvore_2_3(novo_no, (*raiz)->info2, (*raiz)->meio, (*raiz)->direita);
    (*raiz)->info1 = info;
    (*raiz)->meio = filho;
  }
  (*raiz)->qtd_info = 1;
}

static int inserir_arvore_2_3(Arvore_2_3 **raiz, Informacao info, Informacao *promove, Arvore_2_3 **pai, Arvore_2_3 **new_node)
{
  Informacao promove_rec;
  int confirm = 0;

  if (!*raiz)
    criar_arvore_2_3(raiz, info, NULL, NULL);
  else
  {
    if (eh_folha(*raiz))
    {
      if ((*raiz)->qtd_info == 1)
        confirm = adicionar_informacao(*raiz, info, NULL);
      else
      {
        quebra_no(raiz, info, new_node, promove, NULL);
        if (!(*pai))
        {
          criar_arvore_2_3(raiz, *promove, *raiz, *new_node);
          *new_node = NULL;
        }
      }
    }
    else
    {
      if (info.inicio < (*raiz)->info1.inicio)
        confirm = inserir_arvore_2_3(&(*raiz)->esquerda, info, promove, raiz, new_node);
      else if ((*raiz)->qtd_info == 1 || info.inicio < (*raiz)->info2.inicio)
        confirm = inserir_arvore_2_3(&(*raiz)->meio, info, promove, raiz, new_node);
      else
        confirm = inserir_arvore_2_3(&(*raiz)->direita, info, promove, raiz, new_node);

      if (*new_node)
      {
        if ((*raiz)->qtd_info == 1)
        {
          adicionar_informacao(*raiz, *promove, *new_node);
          *new_node = NULL;
        }
        else  
        {
          quebra_no(raiz, info, new_node, &promove_rec, *new_node);
          *promove = promove_rec;

          if (!(*pai))
          {
            criar_arvore_2_3(raiz, promove_rec, *raiz, *new_node);
            *new_node = NULL;
          }
        }
      }
    }
  }

  return confirm;
}

int set_inserir_arvore_2_3(Arvore_2_3 **raiz, Informacao info)
{
  Informacao promove;
  Arvore_2_3 *pai = NULL, *new_node = NULL;
  return inserir_arvore_2_3(raiz, info, &promove, &pai, &new_node);
}