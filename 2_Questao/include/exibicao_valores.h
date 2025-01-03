#pragma once

#include "arvore_vermelho_preto.h"

void exibir_arvore_vermelho_preto_por_unidade(const ArvoreVermelhoPreto *raiz, const char *unidade);
void exibir_arvore_vermelho_preto_por_palavra_portugues(const ArvoreVermelhoPreto *raiz, const char *palavra);
void caminho_arvore_vermelho_preto_por_palavra_portugues(const ArvoreVermelhoPreto *raiz, const char *palavra);
void buscar_arvore_vermelho_preto_por_palavra_portugues(ArvoreVermelhoPreto *raiz, const char *palavra, InfoMain *buscar);
