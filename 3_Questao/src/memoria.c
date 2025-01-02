#include <stdio.h>
#include "include/memoria.h"
#include "include/utils.h"

void pegar_status_da_memoria(STATUS *status)
{
  int confirm = 0;
  char status_aux;
  while (!confirm)
  {
    printf("Digite o status do nó (L - Livre, O - Ocupado): ");
    scanf("%c", &status_aux);
    limpar_buffer();

    if (status_aux == LIVRE || status_aux == OCUPADA)
      confirm = 1;
    else
      printf("Status inválido, digite L para livre ou O para ocupado\n");
  }

  *status = (STATUS)status_aux;
}

void trocar_status_da_memoria(STATUS *status)
{
  if (*status == LIVRE)
    *status = OCUPADA;
  else
    *status = LIVRE;
}

int quantidade_blocos_disponiveis(Informacao info)
{
  return info.final - info.inicio + 1;
}

void set_info(Informacao *informacao, int incio, int final, STATUS status)
{
  informacao->inicio = incio;
  informacao->final = final;
  informacao->status = status;
}
