#include "Unity/unity.h"
#include "include/arvore_2_3.h"
#include "include/exibicao_valores.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

Arvore_2_3 *raiz;
#define QUANTIDADE_PALAVRAS_BUSCAR 30
#define QUANTIDADE_PALAVRAS_TOTAL 10000000

void setUp()
{
  // raiz = NULL;
}

void tearDown()
{
  // free_arvore_vermelho_preto(&raiz);
}

void inserir_dados()
{
  char info_str[10];
  for (int x = 0; x < QUANTIDADE_PALAVRAS_TOTAL; x++)
  {
    sprintf(info_str, "%d", x);
    InfoMain new;
    def_info_arvore_2_3(&new, info_str, info_str, info_str);
    inserir_arvore_2_3(&raiz, new);
  }
}

void test_tempo_busca_30_palavras_portugues()
{
  char info_str[10];

  clock_t start, end;
  clock_t media;
  clock_t media_total = 0;

  FILE *fp = freopen("output/tempo.txt", "w", stdout);

  for (int x = 0; x < QUANTIDADE_PALAVRAS_BUSCAR; x++)
  {
    sprintf(info_str, "%d", QUANTIDADE_PALAVRAS_TOTAL / QUANTIDADE_PALAVRAS_BUSCAR * x);
    media = 0;
    for (int i = 0; i < 10; i++)
    {
      Arvore_2_3 *busca;
      start = clock();
      buscar_arvore_2_3_por_palavra_portugues(raiz, info_str, &busca);
      end = clock();

      if (strcmp(busca->info1.palavra_portugues, info_str) != 0)
        if (busca->n_info == 2 && strcmp(busca->info2.palavra_portugues, info_str) != 0)
            printf("Erro ao buscar %s\n", info_str);

      media += end - start;
      media_total += media;
    }
    printf("Tempo medio de busca por %s: %.9f\n", info_str, (double)media / 10 / CLOCKS_PER_SEC);
  }
  printf("Tempo medio total: %.9f\n", (double)media_total / 10 / QUANTIDADE_PALAVRAS_BUSCAR / CLOCKS_PER_SEC);

  fclose(fp);
}

void test_caminho_busca_30_palavras_portugues()
{
  char info_str[10];
  
  FILE *fp = freopen("output/caminho.txt", "w", stdout);
  for (int x = 0; x < QUANTIDADE_PALAVRAS_BUSCAR; x++)
  {
    sprintf(info_str, "%d", QUANTIDADE_PALAVRAS_TOTAL / QUANTIDADE_PALAVRAS_BUSCAR * x);
    printf("Iniciando busca por %s\n", info_str);
    printf("Raiz -> ");
    caminho_exibir_arvore_2_3_por_palavra_portugues(raiz, info_str);
    printf("\n\n");
  } 
  fclose(fp);
}

int main()
{
  UNITY_BEGIN();
  inserir_dados();
  RUN_TEST(test_tempo_busca_30_palavras_portugues);
  RUN_TEST(test_caminho_busca_30_palavras_portugues);
  free_arvore_2_3(raiz);
  return UNITY_END();
}
