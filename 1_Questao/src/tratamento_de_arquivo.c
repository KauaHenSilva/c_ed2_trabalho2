#include "include/tratamento_de_arquivo.h"
#include "include/arvore_2_3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TipoEntrada ler_indentificar_linha(const char *linha)
{
  TipoEntrada tipo;
  if (linha[0] == '%')
    tipo = NOME_UNIDADE;
  else if (strchr(linha, ';') != NULL && strchr(linha, ':') != NULL)
    tipo = PALAVRA_INGLES_PORTUGUES;
  return tipo;
}

int prencher_arvore_por_linha(Arvore_2_3 **raiz, const char *linha, char *nome_unidade)
{
  char palavra_em_ingles[255];
  char palavras_em_portugues[255];
  char palavra_atual[255];

  sscanf(linha, "%[^:]: %[^;];", palavra_em_ingles, palavras_em_portugues);

  int posicao_palavras = 0;
  int posicao_palavra_atual = 0;
  while (posicao_palavras == 0 || palavras_em_portugues[posicao_palavras - 1] != '\0')
  {
    if (palavras_em_portugues[posicao_palavras] == ',' || palavras_em_portugues[posicao_palavras] == '\0')
    {
      palavra_atual[posicao_palavra_atual] = '\0';

      InfoMain new;
      def_info_arvore_2_3(&new, palavra_em_ingles, palavra_atual, nome_unidade);

      InfoMain promove;
      Arvore_2_3 *pai, *new_node;
      pai = new_node = NULL;
      if (!inserir_arvore_2_3(raiz, new, &promove, &pai, &new_node))
        printf("Erro ao inserir %s\n", palavra_atual);

      if (palavras_em_portugues[posicao_palavra_atual] == ',')
        posicao_palavras++;
      posicao_palavra_atual = 0;
    }
    else
    {
      palavra_atual[posicao_palavra_atual] = palavras_em_portugues[posicao_palavras];
      posicao_palavra_atual++;
    }

    posicao_palavras++;
  }

  return 1;
}

int ler_blocos(Arvore_2_3 **raiz)
{
  int confirm = 1;
  char buffer[255];
  char nome_unidade_atual[255];
  FILE *arquivo = fopen(PATH_ARQUIVO, "r");

  if (!arquivo)
    confirm = 0;
  else
  {
    int qtd_linhas = 0;
    while (fgets(buffer, 255, arquivo) != NULL)
    {
      TipoEntrada resultado = ler_indentificar_linha(buffer);
      qtd_linhas++;
      if (resultado == NOME_UNIDADE)
        sscanf(buffer, "%% %[^\n]", nome_unidade_atual);
      else if (resultado == PALAVRA_INGLES_PORTUGUES)
        prencher_arvore_por_linha(raiz, buffer, nome_unidade_atual);
      else
        printf("Erro ao identificar linha %d\n", qtd_linhas);
    }

    fclose(arquivo);
  }

  return confirm;
}