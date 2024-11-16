#include "include/tratamento_de_arquivo.h"
#include "include/arvore_vermelho_preto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TipoEntrada ler_indentificar_linha(const char *linha)
{
  TipoEntrada tipo;
  if (linha[0] == '%')
    tipo = NOME_UNIDADE;
  else
    tipo = PALAVRA_INGLES_PORTUGUES;
  return tipo;
}

int prencher_arvore_por_linha(ArvoreVermelhoPreto **raiz, const char *linha, char *nome_unidade)
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

      ArvoreVermelhoPreto *new;
      aloca_arvore_vermelho_preto(&new);
      def_arvore_vermelho_preto(new, palavra_em_ingles, palavra_atual, nome_unidade);

      if (!inserir_arvore_vermelho_preto(raiz, new))
        perror("Erro ao inserir na arvore vermelho preto");

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

int ler_blocos(ArvoreVermelhoPreto **raiz)
{
  int confirm = 1;
  char buffer[255];
  char nome_unidade_atual[255];
  FILE *arquivo = fopen(PATH_ARQUIVO, "r");


  if (!arquivo)
    confirm = 0;
  else
  {
    while (fgets(buffer, 255, arquivo) != NULL)
      if (ler_indentificar_linha(buffer) == NOME_UNIDADE)
        sscanf(buffer, "%% %[^\n]", nome_unidade_atual);
      else
        prencher_arvore_por_linha(raiz, buffer, nome_unidade_atual);

    fclose(arquivo);
  }

  return confirm;
}