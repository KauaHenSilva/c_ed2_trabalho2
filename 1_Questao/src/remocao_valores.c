#include "include/remocao_valores.h"
#include "include/arvore_2_3.h"
#include "include/lista_encadeada.h"
#include <stdio.h>
#include <string.h>

int __remove_palavra_ingles_unidade(ArvoreBinaria **raiz, const char *palavra_ingles, const char *unidade)
{
  int confirm = 1;

  if (*raiz)
  {
    if (strcmp((*raiz)->info.palavra_ingles, palavra_ingles) == 0)
    {
      confirm = remover_lista_encadeada_unidade(&(*raiz)->info.unidades, unidade);
      if (!(*raiz)->info.unidades)
        confirm = remocao_arvore_binaria(raiz, palavra_ingles);
    }
    else if (strcmp((*raiz)->info.palavra_ingles, palavra_ingles) > 0)
      confirm = __remove_palavra_ingles_unidade(&(*raiz)->esquerda, palavra_ingles, unidade);
    else
      confirm = __remove_palavra_ingles_unidade(&(*raiz)->direita, palavra_ingles, unidade);
  }

  return confirm;
}

int _remove_palavra_ingles_unidade(Arvore_2_3 *raiz, const char *palavra_ingles, const char *unidade, Arvore_2_3 **top)
{
  int confirm = 0;

  if (raiz)
  {
    confirm = _remove_palavra_ingles_unidade((raiz)->esquerda, palavra_ingles, unidade, top);
    confirm = _remove_palavra_ingles_unidade((raiz)->centro, palavra_ingles, unidade, top) || confirm;

    if ((raiz)->n_info == 2)
    {
      confirm = _remove_palavra_ingles_unidade((raiz)->direita, palavra_ingles, unidade, top) || confirm;
      confirm = __remove_palavra_ingles_unidade(&(raiz)->info2.arv_binaria_palavra_ingles, palavra_ingles, unidade);
    }

    confirm = __remove_palavra_ingles_unidade(&(raiz)->info1.arv_binaria_palavra_ingles, palavra_ingles, unidade);


    if (!(raiz)->info1.arv_binaria_palavra_ingles)
      confirm = arvore_2_3_remover(top, raiz->info1.palavra_portugues);

    if ((raiz)->n_info == 2 && !(raiz)->info2.arv_binaria_palavra_ingles)
      confirm = arvore_2_3_remover(top, raiz->info2.palavra_portugues);
  }

  return confirm;
}

int remove_palavra_ingles_unidade(Arvore_2_3 **raiz, const char *palavras_ingles, const char *unidade)
{
  int confirm = 1;
  confirm = _remove_palavra_ingles_unidade(*raiz, palavras_ingles, unidade, raiz);
  return confirm;
}

int __remove_palavra_portugues_unidade(ArvoreBinaria **raiz, const char *palavra_portugues, const char *unidade)
{
  int confirm = 0;
  if (*raiz)
  {
    confirm = __remove_palavra_portugues_unidade(&(*raiz)->esquerda, palavra_portugues, unidade);
    confirm = __remove_palavra_portugues_unidade(&(*raiz)->direita, palavra_portugues, unidade) || confirm;
    confirm = remover_lista_encadeada_unidade(&(*raiz)->info.unidades, unidade);

    if (!(*raiz)->info.unidades)
      confirm = remocao_arvore_binaria(raiz, (*raiz)->info.palavra_ingles);
  }

  return confirm;
}

int _remove_palavra_portugues_unidade(Arvore_2_3 *raiz, char *palavra_portugues, const char *unidade, Arvore_2_3 **top)
{
  int confirm = 1;

  if (raiz)
  {
    if (strcmp((raiz)->info1.palavra_portugues, palavra_portugues) == 0)
    {
      confirm = __remove_palavra_portugues_unidade(&(raiz)->info1.arv_binaria_palavra_ingles, palavra_portugues, unidade);
      if (!(raiz)->info1.arv_binaria_palavra_ingles)
        confirm = arvore_2_3_remover(top, palavra_portugues);
    }
    else if ((raiz)->n_info == 2 && strcmp((raiz)->info2.palavra_portugues, palavra_portugues) == 0)
    {
      confirm = __remove_palavra_portugues_unidade(&(raiz)->info2.arv_binaria_palavra_ingles, palavra_portugues, unidade);
      if (!(raiz)->info2.arv_binaria_palavra_ingles)
        confirm = arvore_2_3_remover(top, palavra_portugues);
    }
    else if (strcmp(palavra_portugues, (raiz)->info1.palavra_portugues) < 0)
      confirm = _remove_palavra_portugues_unidade((raiz)->esquerda, palavra_portugues, unidade, top);
    else if ((raiz)->n_info == 1 || strcmp(palavra_portugues, (raiz)->info2.palavra_portugues) < 0)
      confirm = _remove_palavra_portugues_unidade((raiz)->centro, palavra_portugues, unidade, top);
    else
      confirm = _remove_palavra_portugues_unidade((raiz)->direita, palavra_portugues, unidade, top);
  }

  return confirm;
}

int remove_palavra_portugues_unidade(Arvore_2_3 **raiz, char *palavra_portugues, const char *unidade)
{
  int confirm = 1;
  confirm = _remove_palavra_portugues_unidade(*raiz, palavra_portugues, unidade, raiz);
  return confirm;
}