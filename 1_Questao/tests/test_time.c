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
  double media = 0, tempo;

  FILE *fp = freopen("output/tempo.txt", "w", stdout);

  for (int x = 0; x < QUANTIDADE_PALAVRAS_BUSCAR; x++)
  {
    sprintf(info_str, "%d", QUANTIDADE_PALAVRAS_TOTAL / QUANTIDADE_PALAVRAS_BUSCAR * x);

    InfoMain busca;
    start = clock();
    buscar_arvore_2_3_por_palavra_portugues(raiz, info_str, &busca);
    end = clock();

    TEST_ASSERT_EQUAL_STRING(info_str, busca.palavra_portugues);

    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    media += tempo;

    printf("Busca por %s: %f\n", info_str, tempo);
  }

  printf("Tempo medio total: %.8f\n", media / QUANTIDADE_PALAVRAS_BUSCAR);
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
