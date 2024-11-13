#pragma once

#include "include/arvore_binaria.h"

typedef struct st_InfoMain
{
  ArvoreBinaria *palavra_ingles;
  char *palavra_portugues;
  char *nome_unidade;
} InfoMain;

void alocar_info_main(InfoMain *info, char *palavra_ingles, char *palavra_portugues, char *nome_unidade);