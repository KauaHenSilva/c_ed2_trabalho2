#pragma once

#include "include/arvore_vermelho_preto.h"

#define PATH_ARQUIVO "./files/exemplo1.txt"

typedef enum en_TipoEntrada
{
  NOME_UNIDADE,
  PALAVRA_INGLES_PORTUGUES,
} TipoEntrada;

TipoEntrada ler_indentificar_linha(char *linha);
int prencher_arvore_por_linha(ArvoreVermelhoPreto **raiz, char *linha, char *nome_unidade);
int ler_blocos(ArvoreVermelhoPreto **raiz);