#include "include/exibicao_valores.h"
#include "include/utils.h"
#include "include/arvore_binaria.h"
#include <string.h>
#include <stdio.h>

static int exibir_arvore_binaria_por_unidade(const ArvoreBinaria *raiz, const char *unidade)
{
  int exibir = 0;

  if (raiz)
  {
    exibir = exibir_arvore_binaria_por_unidade(raiz->esquerda, unidade);

    if (nome_presente(unidade, raiz->nome_unidade))
    {
      printf("Palavra em ingles: %s\n", raiz->palavra_ingles);
      exibir = 1;
    }

    exibir = exibir_arvore_binaria_por_unidade(raiz->direita, unidade) || exibir;
  }

  return exibir;
}

void exibir_arvore_vermelho_preto_por_unidade(const ArvoreVermelhoPreto *raiz, const char *unidade)
{
  if (raiz)
  {
    exibir_arvore_vermelho_preto_por_unidade(raiz->esq, unidade);

    if (exibir_arvore_binaria_por_unidade(raiz->info.arv_binaria_palavra_ingles, unidade))
      printf("Palavra em portugues: %s\n", raiz->info.palavra_portugues);

    exibir_arvore_vermelho_preto_por_unidade(raiz->dir, unidade);
  }
}