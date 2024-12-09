#include "include/remocao_valores.h"
#include "include/arvore_vermelho_preto.h"
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

int _remove_palavra_ingles_unidade(ArvoreVermelhoPreto *raiz, const char *palavra_ingles, const char *unidade, ArvoreVermelhoPreto **top)
{
  int confirm = 1;

  if (raiz)
  {
    confirm = _remove_palavra_ingles_unidade((raiz)->esq, palavra_ingles, unidade, top);
    confirm = _remove_palavra_ingles_unidade((raiz)->dir, palavra_ingles, unidade, top);
    confirm = __remove_palavra_ingles_unidade(&(raiz)->info.arv_binaria_palavra_ingles, palavra_ingles, unidade);

    if (!(raiz)->info.arv_binaria_palavra_ingles)
      confirm = remover_arvore_vermelho_preto(top, raiz->info.palavra_portugues);
  }

  return confirm;
}

int remove_palavra_ingles_unidade(ArvoreVermelhoPreto **raiz, const char *palavras_ingles, const char *unidade)
{
  int confirm = 1;
  confirm = _remove_palavra_ingles_unidade(*raiz, palavras_ingles, unidade, raiz);
  return confirm;
}

int __remove_palavra_portugues_unidade(ArvoreBinaria **raiz, const char *palavra_portugues, const char *unidade)
{
  int confirm = 1;
  if (*raiz)
  {
    confirm = __remove_palavra_portugues_unidade(&(*raiz)->esquerda, palavra_portugues, unidade);
    confirm = __remove_palavra_portugues_unidade(&(*raiz)->direita, palavra_portugues, unidade) || confirm;
    confirm = remover_lista_encadeada_unidade(&(*raiz)->info.unidades, unidade);

    if (!(*raiz)->info.unidades)
      remocao_arvore_binaria(raiz, (*raiz)->info.palavra_ingles);
  }

  return confirm;
}

int _remove_palavra_portugues_unidade(ArvoreVermelhoPreto *raiz, const char *palavra_portugues, const char *unidade, ArvoreVermelhoPreto **top)
{
  int confirm = 1;

  if (raiz)
  {
    if (strcmp((raiz)->info.palavra_portugues, palavra_portugues) == 0)
    {
      confirm = __remove_palavra_portugues_unidade(&(raiz)->info.arv_binaria_palavra_ingles, palavra_portugues, unidade);
      if (!(raiz)->info.arv_binaria_palavra_ingles)
        confirm = remover_arvore_vermelho_preto(top, palavra_portugues);
    }
    else if (strcmp((raiz)->info.palavra_portugues, palavra_portugues) > 0)
      confirm = _remove_palavra_portugues_unidade((raiz)->esq, palavra_portugues, unidade, top);
    else
      confirm = _remove_palavra_portugues_unidade((raiz)->dir, palavra_portugues, unidade, top);
  }

  return confirm;
}

int remove_palavra_portugues_unidade(ArvoreVermelhoPreto **raiz, const char *palavra_portugues, const char *unidade)
{
  int confirm = 1;
  confirm = _remove_palavra_portugues_unidade(*raiz, palavra_portugues, unidade, raiz);
  return confirm;
}