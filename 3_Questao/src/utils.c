#include "include/utils.h"
#include <stdio.h>
#include <stdlib.h>

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int esta_no_intervalo(int inicio, int final, int valor)
{
    return valor >= inicio && valor <= final;
}

void pegar_inteiro_em_intervalo(int *numero, int inicio, int final, char *mensagem)
{
    int confirm = 0;
    while (!confirm)
    {
        printf("Intervalo [%d, %d] : %s", inicio, final, mensagem);
        scanf("%d", numero);
        limpar_buffer();

        if (esta_no_intervalo(inicio, final, *numero))
            confirm = 1;
        else
        {
            printf("Valor fora do intervalo [%d, %d]\n", inicio, final);
            printf("Digite um valor dentro do intervalo\n");
        }
    }
}