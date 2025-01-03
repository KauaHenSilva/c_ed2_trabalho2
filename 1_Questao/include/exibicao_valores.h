#pragma once

#include "include/arvore_2_3.h"

void exibir_arvore_2_3_por_unidade(const Arvore_2_3 *raiz, const char *unidade);
void exibir_arvore_2_3_por_palavra_portugues(const Arvore_2_3 *raiz, const char *palavra);
void caminho_exibir_arvore_2_3_por_palavra_portugues(const Arvore_2_3 *raiz, const char *palavra);
void buscar_arvore_2_3_por_palavra_portugues(Arvore_2_3 *raiz, const char *palavra, InfoMain *busca);
