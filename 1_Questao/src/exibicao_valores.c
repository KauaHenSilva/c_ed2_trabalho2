#include "include/exibicao_valores.h"
#include "include/utils.h"
#include "include/arvore_binaria.h"
#include <string.h>
#include <stdio.h>

static int exibir_arvore_binaria_por_unidade(const ArvoreBinaria *raiz, const char *unidade, const char *plv_ptbr)
{
  int exibir = 0;

  if (raiz)
  {

    exibir = exibir_arvore_binaria_por_unidade(raiz->esquerda, unidade, plv_ptbr);

    if (buscar_lista_encadeada_unidade(raiz->info.unidades, unidade))
    {
      if (!exibir)
        printf("Palavra em portugues: %s\n", plv_ptbr);
      printf("Possivel traducao em ingles: %s\n", raiz->info.palavra_ingles);
      // printf("Unidade: %s\n", raiz->nome_unidade); // Verificar se a unidade esta correta
      exibir = 1;
    }

    exibir = exibir_arvore_binaria_por_unidade(raiz->direita, unidade, plv_ptbr) || exibir;
  }

  return exibir;
}

void exibir_arvore_2_3_por_unidade(const Arvore_2_3 *raiz, const char *unidade)
{
  if (raiz)
  {
    exibir_arvore_2_3_por_unidade(raiz->esquerda, unidade);

    exibir_arvore_binaria_por_unidade(raiz->info1.arv_binaria_palavra_ingles, unidade, raiz->info1.palavra_portugues);
    exibir_arvore_2_3_por_unidade(raiz->centro, unidade);
    if (raiz->n_info == 2)
    {
      exibir_arvore_binaria_por_unidade(raiz->info2.arv_binaria_palavra_ingles, unidade, raiz->info2.palavra_portugues);
      exibir_arvore_2_3_por_unidade(raiz->direita, unidade);
    }
  }
}

void exibir_arvore_binaria_por_palavra_portugues(const ArvoreBinaria *raiz)
{
  if (raiz)
  {
    printf("Possivel traducao em ingles: %s\n", raiz->info.palavra_ingles);
    exibir_arvore_binaria_por_palavra_portugues(raiz->esquerda);
    exibir_arvore_binaria_por_palavra_portugues(raiz->direita);
  }
}

void exibir_arvore_2_3_por_palavra_portugues(const Arvore_2_3 *raiz, const char *palavra)
{
  if (raiz)
  {
    if (strcmp(raiz->info1.palavra_portugues, palavra) == 0)
      exibir_arvore_binaria_por_palavra_portugues(raiz->info1.arv_binaria_palavra_ingles);

    if (raiz->n_info == 2 && strcmp(raiz->info2.palavra_portugues, palavra) == 0)
      exibir_arvore_binaria_por_palavra_portugues(raiz->info2.arv_binaria_palavra_ingles);

    exibir_arvore_2_3_por_unidade(raiz->esquerda, palavra);
    exibir_arvore_2_3_por_unidade(raiz->centro, palavra);
    if (raiz->n_info == 2)
      exibir_arvore_2_3_por_unidade(raiz->direita, palavra);
  }
}