#include "Unity/unity.h"
#include "include/arvore_vermelho_preto.h"
#include "include/exibicao_valores.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

ArvoreVermelhoPreto *raiz;
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
  char info_str[100];
  for (int x = 0; x < QUANTIDADE_PALAVRAS_TOTAL; x++)
  {
    sprintf(info_str, "%d", x);
    ArvoreVermelhoPreto *new;
    aloca_arvore_vermelho_preto(&new);
    def_arvore_vermelho_preto(new, info_str, info_str, info_str);
    inserir_arvore_vermelho_preto(&raiz, new);
  }
}

int compare(const void *a, const void *b)
{
  clock_t va = *(const clock_t *)a;
  clock_t vb = *(const clock_t *)b;

  if (va < vb)
    return -1;
  else if (va > vb)
    return 1;
  else
    return 0;
}

void test_tempo_busca_30_palavras_portugues()
{
  char info_str[100];

  clock_t start, end;
  double tempo, media = 0;

  FILE *fp = freopen("output/tempo.txt", "w", stdout);

  for (int x = 0; x < QUANTIDADE_PALAVRAS_BUSCAR; x++)
  {
    sprintf(info_str, "%d", QUANTIDADE_PALAVRAS_TOTAL / QUANTIDADE_PALAVRAS_BUSCAR * x);

    InfoMain buscar;
    start = clock();
    buscar_arvore_vermelho_preto_por_palavra_portugues(raiz, info_str, &buscar);
    end = clock();

    TEST_ASSERT_EQUAL_STRING(info_str, buscar.palavra_portugues);

    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    media += tempo;
    printf("Tempo de busca por %s: %f\n", info_str, tempo);
  }
  printf("Tempo medio total: %.8f\n", media / QUANTIDADE_PALAVRAS_BUSCAR);
  fclose(fp);
  freopen("/dev/tty", "w", stdout);
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
    caminho_arvore_vermelho_preto_por_palavra_portugues(raiz, info_str);
    printf("\n\n");
  }
  fclose(fp);
  freopen("/dev/tty", "w", stdout);
}

int main()
{
  UNITY_BEGIN();
  inserir_dados();
  RUN_TEST(test_tempo_busca_30_palavras_portugues);
  RUN_TEST(test_caminho_busca_30_palavras_portugues);
  free_arvore_vermelho_preto(&raiz);
  return UNITY_END();
}
