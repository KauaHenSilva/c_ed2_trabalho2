#include <stdio.h>
#include "include/memoria.h"

void pegar_status_da_memoria(char *status)
{
  int confirm = 0;
  while (!confirm)
  {
    printf("Digite o status do nó (L - Livre, O - Ocupado): ");
    scanf("%c", status);

    if (*status == LIVRE || *status == OCUPADA)
      confirm = 1;
    else
      printf("Status inválido, digite L para livre ou O para ocupado\n");
  }
  
}

void trocar_status_da_memoria(char *status)
{
  if (*status == LIVRE)
    *status = OCUPADA;
  else
    *status = LIVRE;
}


void set_info(Informacao *informacao, int incio, int final, STATUS status)
{
  informacao->inicio = incio;
  informacao->final = final;
  informacao->status = status;
}
