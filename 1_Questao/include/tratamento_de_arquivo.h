#pragma once

#include "include/arvore_2_3.h"

#define PATH_ARQUIVO "./files/exemplo1.txt"

typedef enum en_TipoEntrada
{
  NOME_UNIDADE,
  PALAVRA_INGLES_PORTUGUES,
} TipoEntrada;

TipoEntrada ler_indentificar_linha(const char *linha);
int prencher_arvore_por_linha(Arvore_2_3 **raiz, const char *linha, char *nome_unidade);
int ler_blocos(Arvore_2_3 **raiz);