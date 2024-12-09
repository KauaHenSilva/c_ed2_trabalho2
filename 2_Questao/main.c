#include "include/tratamento_de_arquivo.h"
#include "include/exibicao_valores.h"
#include "include/remocao_valores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu()
{
  printf("\n------------------------------------------------------------------------------------------------- \n");
  printf("\nMenu de opções:\n");
  printf("1 - Informar uma unidade e imprimir todas as palavras em português e as equivalentes em inglês.\n");
  printf("2 - Informar uma palavra em português e imprimir todas as palavras em inglês equivalentes.\n");
  printf("3 - Informar uma palavra em inglês e a unidade, removê-la da árvore binária e da árvore 2-3.\n");
  printf("4 - Informar uma palavra em português e a unidade, removê-la da árvore binária e da árvore 2-3.\n");
  printf("0 - Sair\n");
  printf("Escolha uma opção: \n");
  printf("\n------------------------------------------------------------------------------------------------- \n");
}

void flush_in()
{
  int ch;
  while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    ;
}

void get_int(int *num)
{
  int result = -1;
  while (result != 1)
  {
    result = scanf("%d", num);
    if (result != 1)
    {
      printf("Entrada inválida, tente novamente: ");
      result = -1;
    }
    flush_in();
  }
}

void get_string(char *str)
{
  int result = -1;
  while (result != 1)
  {
    result = scanf("%[^\n]", str);
    if (result != 1)
    {
      printf("Entrada inválida, tente novamente: ");
      result = -1;
    }

    flush_in();
  }
}

int main()
{
  ArvoreVermelhoPreto *raiz;
  raiz = NULL;
  ler_blocos(&raiz);

  int opcao = -1;
  while (opcao != 0)
  {
    menu();
    get_int(&opcao);
    if (opcao == 1)
    {
      char unidade[255];
      printf("Informe a unidade: ");
      get_string(unidade);
      printf("\nExibindo palavras da unidade %s:\n", unidade);
      printf("----------------------------------------\n");
      printf("ALERT: Caso não exiba nada, não há palavras cadastradas para essa unidade.\n");
      printf("----------------------------------------\n");
      exibir_arvore_vermelho_preto_por_unidade(raiz, unidade);
      printf("----------------------------------------\n");
    }
    else if (opcao == 2)
    {
      char palavra[255];
      printf("Informe a palavra em português: ");
      get_string(palavra);
      printf("\nExibindo palavras em inglês equivalentes a %s:\n", palavra);
      printf("----------------------------------------\n");
      printf("ALERT: Caso não exiba nada, não há palavras cadastradas para essa palavra em português.\n");
      printf("----------------------------------------\n");
      exibir_arvore_vermelho_preto_por_palavra_portugues(raiz, palavra);
      printf("----------------------------------------\n");
    }
    else if (opcao == 3)
    {
      char palavra[255];
      char unidade[255];
      printf("Informe a palavra em inglês: ");
      get_string(palavra);
      printf("Informe a unidade: ");
      get_string(unidade);
      printf("----------------------------------------\n");
      printf("\nRemovendo palavra %s da unidade %s...\n", palavra, unidade);
      remove_palavra_ingles_unidade(&raiz, palavra, unidade);
      printf("Operação concluída!\n");
      printf("----------------------------------------\n");
    }
    else if (opcao == 4)
    {
      char palavra[255];
      char unidade[255];
      printf("Informe a palavra em português: ");
      get_string(palavra);
      printf("Informe a unidade: ");
      get_string(unidade);
      printf("----------------------------------------\n");
      printf("\nRemovendo palavra %s da unidade %s...\n", palavra, unidade);
      remove_palavra_portugues_unidade(&raiz, palavra, unidade);
      printf("Operação concluída!\n");
      printf("----------------------------------------\n");
    }
    else if (opcao == 0)
    {
      printf("Saindo...\n");
      break;
    }
    else
      printf("Opção inválida!\n");
  }
}
