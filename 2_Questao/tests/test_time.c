#include "Unity/unity.h"
#include "include/arvore_vermelho_preto.h"
#include "include/exibicao_valores.h"
#include <stdlib.h>
#include <time.h>

ArvoreVermelhoPreto *raiz;
#define QUANTIDADE 30

void setUp()
{
  raiz = NULL;
}

void tearDown()
{
  free_arvore_vermelho_preto(&raiz);
}

void inserir_dados()
{
  char info_str[10];
  for (int x = 0; x < QUANTIDADE; x++)
  {
    sprintf(info_str, "%d", x);
    ArvoreVermelhoPreto *new;
    aloca_arvore_vermelho_preto(&new);
    def_arvore_vermelho_preto(new, info_str, info_str, info_str);
    inserir_arvore_vermelho_preto(&raiz, new);
  }
}

void test_tempo_busca_30_palavras_portugues()
{
  inserir_dados();
  char info_str[10];

  clock_t resultados[30];

  for (int qtd_test = 0; qtd_test < 30; qtd_test++)
  {
    clock_t inicio, resultado = 0;
    for (int x = 0; x < QUANTIDADE; x++)
    {
      sprintf(info_str, "%d", x);
      inicio = clock();
      buscar_arvore_vermelho_preto_por_palavra_portugues(raiz, info_str);
      resultado += clock() - inicio;
    } 

    resultados[qtd_test] = resultado;
  }

  clock_t media = 0;
  for (int x = 0; x < 30; x++)
    media += resultados[x];
  media /= 30;

  FILE *fp = freopen("output/time.txt", "a", stdout);
  printf("[Media 30] Tempo de busca de %d palavras em português: %f\n", QUANTIDADE, (double)(media) / CLOCKS_PER_SEC);
  fclose(fp);
}

void test_caminho_busca_30_palavras_portugues()
{
  inserir_dados();
  char info_str[10];
  
  FILE *fp = freopen("output/caminho.txt", "w", stdout);
  for (int x = 0; x < QUANTIDADE; x++)
  {
    sprintf(info_str, "%d", x);
    printf("Iniciando busca por %s\n", info_str);
    printf("Raiz -> ");
    caminho_arvore_vermelho_preto_por_palavra_portugues(raiz, info_str);
    printf("\n\n");
  } 
  fclose(fp);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_tempo_busca_30_palavras_portugues);
  RUN_TEST(test_caminho_busca_30_palavras_portugues);
  return UNITY_END();
}
