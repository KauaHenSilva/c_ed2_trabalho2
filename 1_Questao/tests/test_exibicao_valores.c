#include "Unity/unity.h"
#include "include/exibicao_valores.h"
#include "include/arvore_2_3.h"
#include "include/tratamento_de_arquivo.h"
#include "string.h"

Arvore_2_3 *raiz;

void setUp()
{
  raiz = NULL;
  ler_blocos(&raiz);
}

void tearDown()
{
  free_arvore_2_3(raiz);
}

void test_exibir_arvore_2_3_por_unidade_caso_1();
void test_exibir_arvore_2_3_por_unidade_caso_2();
void test_exibir_arvore_2_3_por_palavra_portugues_caso_1();
void test_exibir_arvore_2_3_por_palavra_portugues_caso_2();

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_exibir_arvore_2_3_por_unidade_caso_1);
  RUN_TEST(test_exibir_arvore_2_3_por_unidade_caso_2);
  RUN_TEST(test_exibir_arvore_2_3_por_palavra_portugues_caso_1);
  RUN_TEST(test_exibir_arvore_2_3_por_palavra_portugues_caso_2);
  return UNITY_END();
}

void test_exibir_arvore_2_3_por_unidade_caso_1()
{
  FILE *fp = freopen("output/test_exibir_arvore_2_3_por_unidade_caso_1.txt", "w", stdout);
  exibir_arvore_2_3_por_unidade(raiz, "Unidade 1");
  fclose(fp);
  freopen("/dev/tty", "w", stdout);

  fp = fopen("output/test_exibir_arvore_2_3_por_unidade_caso_1.txt", "r");
  char buffer[1024];

  char *experado[] = {
      "Palavra em portugues: barramento\n",
      "Possivel traducao em ingles: Bus\n",
      "Palavra em portugues: bicicleta\n",
      "Possivel traducao em ingles: Bike\n",
      "Palavra em portugues: inseto\n",
      "Possivel traducao em ingles: Bug\n",
      "Palavra em portugues: onibus\n",
      "Possivel traducao em ingles: Bus\n",
      "Palavra em portugues: problema\n",
      "Possivel traducao em ingles: Bug\n",
      "Palavra em portugues: rede de computadores\n",
      "Possivel traducao em ingles: Network\n",
      "Palavra em portugues: sistema\n",
      "Possivel traducao em ingles: System\n",
      "Palavra em portugues: ventilador\n",
      "Possivel traducao em ingles: Coller\n",
  };

  for (int i = 0; i < (int)(sizeof(experado) / sizeof(char *)); i++)
    TEST_ASSERT_EQUAL_STRING(experado[i], fgets(buffer, 1024, fp));
  TEST_ASSERT_EQUAL_STRING(NULL, fgets(buffer, 1024, fp));
}

void test_exibir_arvore_2_3_por_unidade_caso_2()
{
  FILE *fp = freopen("output/test_exibir_arvore_2_3_por_unidade_caso_2.txt", "w", stdout);
  exibir_arvore_2_3_por_unidade(raiz, "Unidade 2");
  fclose(fp);
  freopen("/dev/tty", "w", stdout);

  fp = fopen("output/test_exibir_arvore_2_3_por_unidade_caso_2.txt", "r");
  char buffer[1024];

  char *experado[] = {
    "Palavra em portugues: bicicleta\n",
    "Possivel traducao em ingles: Bicycle\n",
    "Palavra em portugues: inseto\n",
    "Possivel traducao em ingles: Bug\n",
    "Palavra em portugues: rede de relacionamento\n",
    "Possivel traducao em ingles: Network\n",
    "Palavra em portugues: ventilador\n",
    "Possivel traducao em ingles: Fan\n",
  };

  for (int i = 0; i < (int)(sizeof(experado) / sizeof(char *)); i++)
    TEST_ASSERT_EQUAL_STRING(experado[i], fgets(buffer, 1024, fp));
  TEST_ASSERT_EQUAL_STRING(NULL, fgets(buffer, 1024, fp));
}

void test_exibir_arvore_2_3_por_palavra_portugues_caso_1()
{
  FILE *fp = freopen("output/test_exibir_arvore_2_3_por_palavra_portugues_caso_1.txt", "w", stdout);
  exibir_arvore_2_3_por_palavra_portugues(raiz, "barramento");
  fclose(fp);
  freopen("/dev/tty", "w", stdout);

  fp = fopen("output/test_exibir_arvore_2_3_por_palavra_portugues_caso_1.txt", "r");
  char buffer[1024];

  char *experado[] = {
    "Possivel traducao em ingles: Bus\n",
  };

  for (int i = 0; i < (int)(sizeof(experado) / sizeof(char *)); i++)
    TEST_ASSERT_EQUAL_STRING(experado[i], fgets(buffer, 1024, fp));
  TEST_ASSERT_EQUAL_STRING(NULL, fgets(buffer, 1024, fp));
}

void test_exibir_arvore_2_3_por_palavra_portugues_caso_2()
{
  FILE *fp = freopen("output/test_exibir_arvore_2_3_por_palavra_portugues_caso_2.txt", "w", stdout);
  exibir_arvore_2_3_por_palavra_portugues(raiz, "bicicleta");
  fclose(fp);
  freopen("/dev/tty", "w", stdout);

  fp = fopen("output/test_exibir_arvore_2_3_por_palavra_portugues_caso_2.txt", "r");
  char buffer[1024];

  char *experado[] = {
    "Possivel traducao em ingles: Bicycle\n",
    "Possivel traducao em ingles: Bike\n"
  };

  for (int i = 0; i < (int)(sizeof(experado) / sizeof(char *)); i++)
    TEST_ASSERT_EQUAL_STRING(experado[i], fgets(buffer, 1024, fp));
  TEST_ASSERT_EQUAL_STRING(NULL, fgets(buffer, 1024, fp));
}