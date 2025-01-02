#pragma once

typedef enum en_STATUS{
    LIVRE = 'L',
    OCUPADA = 'O',
} STATUS;

typedef struct st_Informacao
{
    int inicio;
    int final;
    STATUS status;
} Informacao;

void set_info(Informacao *informacao, int incio, int final, STATUS status);
void pegar_status_da_memoria(STATUS *status);
void trocar_status_da_memoria(STATUS *status);
int quantidade_blocos_disponiveis(Informacao info);