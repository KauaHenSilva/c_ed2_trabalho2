#pragma once

#include "include/arvore_binaria.h"

typedef struct st_InfoMain
{
  ArvoreBinaria *arv_binaria_palavra_ingles;
  char *palavra_portugues;
} InfoMain;

int atualizar_info(InfoMain *info, InfoMain *new_info);
