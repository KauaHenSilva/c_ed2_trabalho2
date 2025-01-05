#pragma once

#include "arvore_2_3.h"

void set_info(Informacao *informacao, int incio, int final, STATUS status, int endereco_inicial, int endereco_final);
void pegar_status_da_memoria(STATUS *status);
void trocar_status_da_memoria(STATUS *status);
int quantidade_blocos_disponiveis(Informacao info);