#include "include/utils.h"
#include <stdlib.h>

int tamanho_string(const char *string)
{
  int tamanho = 0;
  while (string[tamanho] != '\0')
    tamanho++;
  return tamanho;
}

int aloca_string(char **string, const int tamanho)
{
  *string = (char *)realloc(NULL, (size_t)tamanho * sizeof(char));
  return *string ? 1 : 0;
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
