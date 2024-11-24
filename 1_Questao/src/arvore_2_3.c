#include "include/arvore_2_3.h"
#include "include/lista_encadeada.h"
#include "include/arvore_binaria.h"
#include "include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void def_info_arvore_2_3(InfoMain *info, char *plv_ingles, char *plv_portugues, char *nome_unidade)
{
  aloca_arvore_binaria(&info->arv_binaria_palavra_ingles);
  aloca_string(&info->palavra_portugues, tamanho_string(plv_portugues));
  def_arvore_binaria(info->arv_binaria_palavra_ingles, plv_ingles, nome_unidade);
  strcpy(info->palavra_portugues, plv_portugues);
}

void free_info_arvore_2_3(InfoMain *info)
{
  free_arvore_binaria(info->arv_binaria_palavra_ingles);
  free(info->palavra_portugues);
}

void copia_info_arvore_2_3(InfoMain *info_recebe, InfoMain *info_envia)
{
  copia_arvore_binaria(info_recebe->arv_binaria_palavra_ingles, info_envia->arv_binaria_palavra_ingles);
  aloca_string(&info_recebe->palavra_portugues, tamanho_string(info_envia->palavra_portugues));
  strcpy(info_recebe->palavra_portugues, info_envia->palavra_portugues);
}

void aloca_arvore_2_3(Arvore_2_3 **raiz)
{
  *raiz = (Arvore_2_3 *)malloc(sizeof(Arvore_2_3));
  (*raiz)->direita = NULL;
  (*raiz)->info1.arv_binaria_palavra_ingles = NULL;
  (*raiz)->info1.palavra_portugues = NULL;
  (*raiz)->info2.arv_binaria_palavra_ingles = NULL;
  (*raiz)->info2.palavra_portugues = NULL;
}

void free_arvore_2_3(Arvore_2_3 *raiz)
{
  if (raiz)
  {
    free_arvore_2_3(raiz->esquerda);
    free_arvore_2_3(raiz->centro);
    if (raiz->n_info == 2)
      free_arvore_2_3(raiz->direita);

    if (raiz->n_info == 2)
      free_info_arvore_2_3(&raiz->info2);
    free_info_arvore_2_3(&raiz->info1);

    free(raiz);
  }
}

void cria_no(Arvore_2_3 **new, InfoMain info, Arvore_2_3 *esquerda, Arvore_2_3 *centro)
{
  aloca_arvore_2_3(new);
  (*new)->info1 = info;
  (*new)->esquerda = esquerda;
  (*new)->centro = centro;
  (*new)->n_info = 1;
}

int eh_folha_arvore_2_3(Arvore_2_3 *raiz)
{
  int is_folha = 1;
  if (raiz->esquerda)
    is_folha = 0;
  return is_folha;
}

int adicionando_valor_em_arvore_2_3(Arvore_2_3 *raiz, InfoMain *info, Arvore_2_3 *filho)
{
  int is_add = 1;
  int comp = strcmp(raiz->info1.palavra_portugues, info->palavra_portugues);

  if (comp != 0)
  {
    if (comp < 0)
    {
      raiz->info2 = *info;
      raiz->direita = filho;
    }
    else
    {
      raiz->info2 = raiz->info1;
      raiz->info1 = *info;
      raiz->centro = filho;
    }

    raiz->n_info = 2;
  }
  else
    is_add = 0;

  return is_add;
}

void quebra_no(Arvore_2_3 **raiz, Arvore_2_3 **new_node, InfoMain info, InfoMain *info_up, Arvore_2_3 **filho)
{

  if (strcmp(info.palavra_portugues, (*raiz)->info2.palavra_portugues) > 0)
  {
    *info_up = (*raiz)->info2;
    if (filho)
      cria_no(new_node, info, (*raiz)->direita, *filho);
    else
      cria_no(new_node, info, (*raiz)->direita, NULL);
  }
  else if (strcmp(info.palavra_portugues, (*raiz)->info1.palavra_portugues) > 0)
  {
    *info_up = info;
    if (filho)
      cria_no(new_node, (*raiz)->info2, *filho, (*raiz)->direita);
    else
      cria_no(new_node, (*raiz)->info2, NULL, (*raiz)->direita);
  }
  else
  {
    *info_up = (*raiz)->info1;
    cria_no(new_node, (*raiz)->info2, (*raiz)->centro, (*raiz)->direita);
    (*raiz)->info1 = info;

    if (filho)
      (*raiz)->centro = *filho;
  }

  (*raiz)->n_info = 1;
}

int value_equals(const Arvore_2_3 *raiz, const InfoMain *info)
{
  int equal = 0;
  if (raiz->n_info == 2)
  {
    if (strcmp(raiz->info1.palavra_portugues, info->palavra_portugues) == 0)
      equal = 1;
    else if (strcmp(raiz->info2.palavra_portugues, info->palavra_portugues) == 0)
      equal = 2;
  }
  else if (strcmp(raiz->info1.palavra_portugues, info->palavra_portugues) == 0)
    equal = 1;

  return equal;
}

int inserir_valor_arvore_binaria(Arvore_2_3 **raiz, InfoMain info, int value_equals)
{
  int confirm = 1;

  ArvoreBinaria *new = NULL;
  aloca_arvore_binaria(&new);
  copia_arvore_binaria(new, info.arv_binaria_palavra_ingles);

  if (value_equals == 1)
    insercao_arvore_binaria(&(*raiz)->info1.arv_binaria_palavra_ingles, new);
  else if (value_equals == 2)
    insercao_arvore_binaria(&(*raiz)->info2.arv_binaria_palavra_ingles, new);
  else
    confirm = 0;

  return confirm;
}

int inserir_arvore_2_3(Arvore_2_3 **raiz, InfoMain info, InfoMain *promove, Arvore_2_3 **pai, Arvore_2_3 **new_node)
{
  InfoMain promove_rec;
  int confirm = 1, value_equal;

  if (!*raiz)
    cria_no(raiz, info, NULL, NULL);
  else if (value_equal = value_equals(*raiz, &info))
    confirm = inserir_valor_arvore_binaria(raiz, info, value_equal);
  else
  {
    if (eh_folha_arvore_2_3(*raiz))
    {
      if ((*raiz)->n_info == 1)
        confirm = adicionando_valor_em_arvore_2_3(*raiz, &info, NULL);
      else
      {
        quebra_no(raiz, new_node, info, promove, NULL);
        if (!(*pai))
        {
          cria_no(raiz, *promove, *raiz, *new_node);
          new_node = NULL;
        }
      }
    }
    else
    {
      if (strcmp(info.palavra_portugues, (*raiz)->info1.palavra_portugues) < 0)
        confirm = inserir_arvore_2_3(&(*raiz)->esquerda, info, promove, raiz, new_node) || confirm;
      else if ((*raiz)->n_info == 1 || strcmp(info.palavra_portugues, (*raiz)->info2.palavra_portugues) < 0)
        confirm = inserir_arvore_2_3(&(*raiz)->centro, info, promove, raiz, new_node) || confirm;
      else
        confirm = inserir_arvore_2_3(&(*raiz)->direita, info, promove, raiz, new_node) || confirm;

      if (*new_node)
      {
        if ((*raiz)->n_info == 1)
        {
          adicionando_valor_em_arvore_2_3(*raiz, promove, *new_node);
          new_node = NULL;
        }
        else
        {
          quebra_no(raiz, new_node, *promove, &promove_rec, new_node);
          *promove = promove_rec;

          if (!(*pai))
          {
            cria_no(raiz, promove_rec, *raiz, *new_node);
            new_node = NULL;
          }
        }
      }
    }
  }

  return confirm;
}

static void show_info(const InfoMain *info)
{
  printf("Palavra em portugues: %s\n", info->palavra_portugues);
  show_arvore_binaria(info->arv_binaria_palavra_ingles);
}

/* Isso é em ordem, Utilize para testar */
void show_arvore_2_3(const Arvore_2_3 *raiz)
{
  if (raiz)
  {

    printf("Nó: 1\n");
    show_info(&raiz->info1);
    if (raiz->n_info == 2)
    {
      printf("Nó: 2\n");
      show_info(&raiz->info2);
    }

    printf("\n");

    show_arvore_2_3(raiz->esquerda);
    show_arvore_2_3(raiz->centro);
    if (raiz->n_info == 2)
      show_arvore_2_3(raiz->direita);
  }
}

/* Isso é em ordem, Utilize para deploymet */
// void show_arvore_2_3(const Arvore_2_3 *raiz)
// {
//   if (raiz)
//   {
//     show_arvore_2_3(raiz->esquerda);
//     printf("Nó: 1\n");
//     show_info(&raiz->info1);

//     show_arvore_2_3(raiz->centro);
//     if (raiz->n_info == 2)
//     {
//       printf("Nó: 2\n");
//       show_info(&raiz->info2);
//       show_arvore_2_3(raiz->direita);
//     }

//     printf("\n");
//   }
// }