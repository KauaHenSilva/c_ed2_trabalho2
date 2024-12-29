#include "Unity/unity.h"
#include "include/arvore_2_3.h"
#include "include/exibicao_valores.h"
#include <stdlib.h>
#include <time.h>

Arvore_2_3 *raiz;

void setUp()
{
  raiz = NULL;
}

void tearDown()
{
  free_arvore_2_3(raiz);
}

void inserir_dados()
{
  char info_str[10];
  for (int x = 0; x < 30; x++)
  {
    InfoMain info;
    sprintf(info_str, "%d", x);
    def_info_arvore_2_3(&info, info_str, info_str, info_str);
    inserir_arvore_2_3(&raiz, info);
  }
}

void test_tempo_busca_30_palavras_portugues()
{
  inserir_dados();
  char info_str[10];

  InfoMain info;
  sprintf(info_str, "%d", 1000);
  def_info_arvore_2_3(&info, info_str, info_str, info_str);
  
  clock_t resultados[30];

  for (int qtd_test = 0; qtd_test < 30; qtd_test++)
  {
    clock_t inicio, resultado = 0;
    for (int x = 0; x < 30; x++)
    {
      sprintf(info_str, "%d", x);
      inicio = clock();
      exibir_arvore_2_3_por_palavra_portugues(raiz, info_str);
      resultado += clock() - inicio;
    } 

    double time_spent = (double)(resultado) / CLOCKS_PER_SEC;
    resultados[qtd_test] = resultado;
  }

  clock_t media = 0;
  for (int x = 0; x < 30; x++)
    media += resultados[x];
  media /= 30;

  FILE *fp = freopen("output/time.txt", "a", stdout);
  printf("[Media 30] Tempo de busca de 30 palavras em português: %f\n", (double)(media) / CLOCKS_PER_SEC);
  fclose(fp);
}

void test_caminho_busca_30_palavras_portugues()
{
  inserir_dados();
  char info_str[10];
  
  FILE *fp = freopen("output/caminho.txt", "w", stdout);
  for (int x = 0; x < 30; x++)
  {
    sprintf(info_str, "%d", x);
    char caminho[255] = "Raiz";
    printf("Inicinado busca por %s\n", info_str);
    caminho_exibir_arvore_2_3_por_palavra_portugues(raiz, info_str, caminho);
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
