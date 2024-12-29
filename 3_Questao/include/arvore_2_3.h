#pragma once

#include "include/memoria.h"

typedef struct Arvore_2_3
{
    Informacao info1;
    Informacao info2;
    struct Arvore_2_3 *esquerda;
    struct Arvore_2_3 *meio;
    struct Arvore_2_3 *direita;
    int qtd_info;
} Arvore_2_3;

int criar_arvore_2_3(Arvore_2_3 **arvore, Informacao info, Arvore_2_3 *esquerda, Arvore_2_3 *meio);
int adicionar_informacao(Arvore_2_3 *raiz, Informacao info, Arvore_2_3 *filho);
int set_inserir_arvore_2_3(Arvore_2_3 **raiz, Informacao info);
void free_arvore_2_3(Arvore_2_3 *arvore);
void show_arvore_2_3(Arvore_2_3 *raiz);
int eh_folha(Arvore_2_3 *raiz);

void ocupar_no(Arvore_2_3 **arvore, int tamanho);
void no_com_tamanho_livre(Arvore_2_3 **no_adequado, int *info_correspodente, Arvore_2_3 *arvore, int tamanho);
