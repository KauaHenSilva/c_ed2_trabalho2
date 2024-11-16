#include "include/utils.h"
#include <stdlib.h>

int tamanho_string(char *string)
{
  int tamanho = 0;
  while (string[tamanho] != '\0')
    tamanho++;
  return tamanho;
}

int aloca_string(char **string, int tamanho)
{
  *string = (char *)realloc(*string, (size_t)tamanho * sizeof(char));
  return *string ? 1 : 0;
}

int nome_presente(const char *nome_procurar, const char *nomes)
{
  int posicao_nome = 0;
  int posicao_nome_procurar = 0;
  int confirm = 0;

  while (nomes[posicao_nome] != '\0' && confirm == 0)
  {
    if (nomes[posicao_nome] == nome_procurar[posicao_nome_procurar])
    {
      posicao_nome_procurar++;
      if (nome_procurar[posicao_nome_procurar] == '\0' || nomes[posicao_nome] == ',')
        confirm = 1;
    }
    else
      posicao_nome_procurar = 0;
    posicao_nome++;
  }

  return confirm;
}

void juntar_nome_por_virgula(char *nome_antigo, char *nome_novo, char **juncao)
{
  aloca_string(juncao, tamanho_string(nome_antigo) + tamanho_string(nome_novo) + 2);

  int posicao_nome_antigo = 0, posicao_nome_novo = 0;

  for (posicao_nome_antigo = 0; nome_antigo[posicao_nome_antigo] != '\0'; posicao_nome_antigo++)
    (*juncao)[posicao_nome_antigo] = nome_antigo[posicao_nome_antigo];

  (*juncao)[posicao_nome_antigo++] = ',';
  (*juncao)[posicao_nome_antigo++] = ' ';

  for (posicao_nome_novo = 0; nome_novo[posicao_nome_novo] != '\0'; posicao_nome_novo++)
    (*juncao)[posicao_nome_antigo + posicao_nome_novo] = nome_novo[posicao_nome_novo];
  (*juncao)[posicao_nome_antigo + posicao_nome_novo] = '\0';
}

void remover_virgula(char *palavra)
{
  int posicao = 0;
  while (palavra[posicao] != '\0')
  {
    if (palavra[posicao] == ',')
      for (int i = posicao; palavra[i] != '\0'; i++)
        palavra[i] = palavra[i + 1];
    posicao++;
  }
}
