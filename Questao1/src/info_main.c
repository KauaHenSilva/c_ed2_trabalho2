#include "include/info_main.h"
#include "include/arvore_binaria.h"
#include <stdlib.h>
#include <string.h>

void alocar_info_main(InfoMain *info, char *palavra_ingles, char *palavra_portugues, char *nome_unidade)
{
  aloca_arvore_binaria(&info->palavra_ingles, palavra_ingles);
  info->palavra_portugues = palavra_portugues;
  info->nome_unidade = nome_unidade;
}

