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

Arvore_2_3 *buscar_no_memoria(Arvore_2_3 **arvore, int quant, STATUS status, Informacao **info_escolhido);
Informacao *no23_maior_info(Arvore_2_3 *raiz);
Arvore_2_3 *arvore_2_3_buscar_menor_filho(Arvore_2_3 *raiz, Arvore_2_3 **pai);
Arvore_2_3 *arvore_2_3_buscar_maior_filho(Arvore_2_3 *raiz, Arvore_2_3 **pai, Informacao **maior_valor);
Arvore_2_3 *arvore_2_3_buscar_pai(Arvore_2_3 *raiz, int info);
Arvore_2_3 *Arvore_2_3_buscar_maior_pai(Arvore_2_3 *raiz, int info);
Arvore_2_3 *arvore_2_3_buscar_menor_pai(Arvore_2_3 *raiz, int info);
Arvore_2_3 *buscar_menor_bloco(Arvore_2_3 **raiz, Arvore_2_3 *no, Informacao *info, Informacao **valor_menor);
Arvore_2_3 *buscar_maior_bloco(Arvore_2_3 **raiz, Arvore_2_3 *no, Informacao *info, Informacao **valor_maior);
void no_2_3_desalocar(Arvore_2_3 **no);

int arvore_2_3_remover2(Arvore_2_3 **raiz, int info, Arvore_2_3 *pai, Arvore_2_3 **origem, Arvore_2_3 **maior);
int arvore_2_3_remover1(Arvore_2_3 **raiz, int info, Arvore_2_3 *pai, Arvore_2_3 **origem, Arvore_2_3 **maior);
int arvore_2_3_remover(Arvore_2_3 **raiz, int info);

void modificar_no(Arvore_2_3 **raiz, Arvore_2_3 *no, Informacao *info, int quant);
// void no_com_tamanho_livre(Arvore_2_3 **no_adequado, int *info_correspodente, Arvore_2_3 *arvore, int tamanho);
int alocar_desalocar_no(Arvore_2_3 **arvore, int quant_nos, STATUS status);