#include "include/remocao_valores.h"
#include "include/arvore_vermelho_preto.h"
#include "include/lista_encadeada.h"
#include <stdio.h>
#include <string.h>

int _remove_palavra_ingles_unidade(ArvoreVermelhoPreto **raiz, const char *palavra_ingles, const char *unidade)
{
  int confirm = 1;
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
      remocao_arvore_binaria(&(*raiz)->info.arv_binaria_palavra_ingles, palavra_ingles);

    if (*raiz && !(*raiz)->info.arv_binaria_palavra_ingles)
      remover_NO_vermelho_preto(raiz, (*raiz)->info.palavra_portugues);
  }
}

int remove_palavra_ingles_unidade(ArvoreVermelhoPreto **raiz, const char *palavras_ingles, const char *unidade)
{
  _remove_palavra_ingles_unidade(raiz, palavras_ingles, unidade);
  if (*raiz)
    (*raiz)->cor = PRETO;
  return 1;
}
