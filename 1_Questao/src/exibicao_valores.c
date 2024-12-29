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

static void exibir_arvore_binaria_por_palavra_portugues(const ArvoreBinaria *raiz)
{
  if (raiz)
  {
    exibir_arvore_binaria_por_palavra_portugues(raiz->esquerda);    
    printf("Possivel traducao em ingles: %s\n", raiz->info.palavra_ingles);
    exibir_arvore_binaria_por_palavra_portugues(raiz->direita);
  }
}

void exibir_arvore_2_3_por_palavra_portugues(const Arvore_2_3 *raiz, const char *palavra)
{
  if (raiz)
  {
    if (strcmp(raiz->info1.palavra_portugues, palavra) == 0)
      exibir_arvore_binaria_por_palavra_portugues(raiz->info1.arv_binaria_palavra_ingles);
    else if (raiz->n_info == 2 && strcmp(raiz->info2.palavra_portugues, palavra) == 0)
      exibir_arvore_binaria_por_palavra_portugues(raiz->info2.arv_binaria_palavra_ingles);
    else if (strcmp(raiz->info1.palavra_portugues, palavra) > 0)
      exibir_arvore_2_3_por_palavra_portugues(raiz->esquerda, palavra);
    else if (raiz->n_info == 1 || strcmp(raiz->info2.palavra_portugues, palavra) > 0)
      exibir_arvore_2_3_por_palavra_portugues(raiz->centro, palavra);
    else
      exibir_arvore_2_3_por_palavra_portugues(raiz->direita, palavra);
  }
}
void caminho_exibir_arvore_2_3_por_palavra_portugues(const Arvore_2_3 *raiz, const char *palavra, const char *caminho)
{
  if (raiz)
  {
    char novo_caminho_esq[100];
    char novo_caminho_centro[100];
    char novo_caminho_dir[100];
    sprintf(novo_caminho_esq, "%s -> esquerda", caminho);
    sprintf(novo_caminho_centro, "%s -> centro", caminho);
    sprintf(novo_caminho_dir, "%s -> direita", caminho);

    if (strcmp(raiz->info1.palavra_portugues, palavra) == 0)
    {
      char *info = "info1";
      printf("Caminho: %s, info: %s\n", caminho, info);
      exibir_arvore_binaria_por_palavra_portugues(raiz->info1.arv_binaria_palavra_ingles);
    }
    else if (raiz->n_info == 2 && strcmp(raiz->info2.palavra_portugues, palavra) == 0)
    {
      char *info = "info2";
      printf("Caminho: %s, info: %s\n", caminho, info);
      exibir_arvore_binaria_por_palavra_portugues(raiz->info2.arv_binaria_palavra_ingles);
    }
    else if (strcmp(raiz->info1.palavra_portugues, palavra) > 0)
      caminho_exibir_arvore_2_3_por_palavra_portugues(raiz->esquerda, palavra, novo_caminho_esq);
    else if (raiz->n_info == 1 || strcmp(raiz->info2.palavra_portugues, palavra) > 0)
      caminho_exibir_arvore_2_3_por_palavra_portugues(raiz->centro, palavra, novo_caminho_centro);
    else
      caminho_exibir_arvore_2_3_por_palavra_portugues(raiz->direita, palavra, novo_caminho_dir);
  }
}