#pragma once

#include "include/info_main.h"

typedef struct st_Arvore2_3
{
  InfoMain info1;
  InfoMain info2;

  int qtd_infos;
  struct st_arvore_2_3 *esquerda;
  struct st_arvore_2_3 *centro;
  struct st_arvore_2_3 *direita;
} Arvore2_3;