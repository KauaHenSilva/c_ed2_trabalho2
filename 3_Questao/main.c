#include <stdio.h>
#include "include/arvore_2_3.h"
#include "include/memoria.h"
#include "include/utils.h"
#include <stdlib.h>

void informar_primeiro_nos(Arvore_2_3 **arvore, int tamanho_maximo)
{
  // Setando o primeiro nó da árvore
  Informacao info_primeiro;
  int final;
  STATUS status;

  pega_inteiro(&tamanho_maximo, "Digite o endereço final do nó: ");
  pegar_status_da_memoria(&status);

  set_info(&info_primeiro, 0, final, status, 0, tamanho_maximo);
  set_inserir_arvore_2_3(arvore, info_primeiro);

  int inicio;

  // ------------------------------------------------

  // Setando os demais nós, Aqui o usuário informa apenas o endereço final, o status é contabilizado pelo sistema
  // caso o status seja livre, o sistema muda para ocupado, caso seja ocupado, o sistema muda para livre.
  // e o endereço inicial é o endereço final do utlimo nó + 1
  while (final != tamanho_maximo)
  {
    inicio = final + 1;
    Informacao info;

    pegar_inteiro_em_intervalo(&final, inicio, tamanho_maximo, "Digite o endereço final do nó: ");
    trocar_status_da_memoria(&status);

    set_info(&info, inicio, final, status, 0, tamanho_maximo);
    set_inserir_arvore_2_3(arvore, info);
  }
}

void menu()
{
  printf("\n");
  printf("Menu\n");
  printf("0 - Sair\n");
  printf("1 - Exibir árvore\n");
  printf("2 - Ocupar nó\n");
  printf("3 - Desocupar nó\n");
  printf("\n");
}

int main()
{
  Arvore_2_3 *arvore = NULL;

  int tamanho_maximo;
  pega_inteiro(&tamanho_maximo, "Digite o tamanho da memória: ");

  informar_primeiro_nos(&arvore, tamanho_maximo);

  int opcao = -1;
  while (opcao != 0)
  {
    menu();
    pegar_inteiro_em_intervalo(&opcao, 0, 2, "Digite a opção desejada: ");
    printf("\n");
    if (opcao == 1)
      show_arvore_2_3(arvore);
    else if (opcao == 2)
    {
      int tamanho;
      pegar_inteiro_em_intervalo(&tamanho, 0, tamanho_maximo, "Digite o tamanho do nó a ser ocupado: ");
      alocar_desalocar_no(&arvore, tamanho, OCUPADA);
    }
    else if (opcao == 3)
    {
      int tamanho;
      pegar_inteiro_em_intervalo(&tamanho, 0, tamanho_maximo, "Digite o tamanho do nó a ser desocupado: ");
      alocar_desalocar_no(&arvore, tamanho, LIVRE);
    }
  }

  free_arvore_2_3(arvore);
  return 0;
}