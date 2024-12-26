#include "Unity/unity.h"
#include "include/arvore_vermelho_preto.h"
#include "include/tratamento_de_arquivo.h"
#include "include/remocao_valores.h"
#include "string.h"

ArvoreVermelhoPreto *raiz;

void setUp()
{
  raiz = NULL;
  ler_blocos(&raiz);
}

void tearDown()
{
  free_arvore_vermelho_preto(&raiz);
}

void test_remove_palavra_ingles_unidade_caso_bus_unidade_1();
void test_remove_palavra_ingles_unidade_caso_bug_unidade_1();
void test_remove_palavra_ingles_unidade_caso_bug_unidade_2();
void test_remove_palavra_portugues_unidade_caso_inseto_unidade_1();
void test_remove_palavra_portugues_unidade_caso_problema_unidade_2();

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_remove_palavra_ingles_unidade_caso_bus_unidade_1);
  RUN_TEST(test_remove_palavra_ingles_unidade_caso_bug_unidade_1);
  RUN_TEST(test_remove_palavra_ingles_unidade_caso_bug_unidade_2);
  RUN_TEST(test_remove_palavra_portugues_unidade_caso_inseto_unidade_1);
  RUN_TEST(test_remove_palavra_portugues_unidade_caso_problema_unidade_2);
  return UNITY_END();
}

void test_remove_palavra_ingles_unidade_caso_bus_unidade_1()
{
  FILE *fp = freopen("output/test_remove_palavra_ingles_unidade_caso_bus_unidade_1.txt", "w", stdout);
  remove_palavra_ingles_unidade(&raiz, "Bus", "Unidade 1");
  show_arvore_vermelho_preto(raiz);
  fclose(fp);
  freopen("/dev/tty", "w", stdout);

  fp = fopen("output/test_remove_palavra_ingles_unidade_caso_bus_unidade_1.txt", "r");
  char buffer[1024];
  char *experado[] = {
      "Cor: VERMELHO\n",
      "Palavra em portugues: bicicleta\n",
      "Possivel traducao em ingles: Bicycle\n",
      "Apareceu em: Unidade 2\n",
      "Possivel traducao em ingles: Bike\n",
      "Apareceu em: Unidade 1\n",
      "Cor: PRETO\n",
      "Palavra em portugues: inseto\n",
      "Possivel traducao em ingles: Bug\n",
      "Apareceu em: Unidade 2, Unidade 1\n",
      "Cor: VERMELHO\n",
      "Palavra em portugues: problema\n",
      "Possivel traducao em ingles: Bug\n",
      "Apareceu em: Unidade 1\n",
      "Cor: VERMELHO\n",
      "Palavra em portugues: rede de computadores\n",
      "Possivel traducao em ingles: Network\n",
      "Apareceu em: Unidade 1\n",
      "Cor: PRETO\n",
      "Palavra em portugues: rede de relacionamento\n",
      "Possivel traducao em ingles: Network\n",
      "Apareceu em: Unidade 2\n",
      "Cor: PRETO\n",
      "Palavra em portugues: sistema\n",
      "Possivel traducao em ingles: System\n",
      "Apareceu em: Unidade 1\n",
      "Cor: PRETO\n",
      "Palavra em portugues: ventilador\n",
      "Possivel traducao em ingles: Coller\n",
      "Apareceu em: Unidade 1\n",
      "Possivel traducao em ingles: Fan\n",
      "Apareceu em: Unidade 2\n"};

  for (int i = 0; i < 32; i++)
  {
    fgets(buffer, 1024, fp);
    TEST_ASSERT_EQUAL_STRING(experado[i], buffer);
  }
  fclose(fp);
}

void test_remove_palavra_ingles_unidade_caso_bug_unidade_1()
{
  FILE *fp = freopen("output/test_remove_palavra_ingles_unicade_caso_bug_unidade_1.txt", "w", stdout);
  remove_palavra_ingles_unidade(&raiz, "Bug", "Unidade 1");
  show_arvore_vermelho_preto(raiz);
  fclose(fp);
    freopen("/dev/tty", "w", stdout);

    fp = fopen("output/test_remove_palavra_ingles_unicade_caso_bug_unidade_1.txt", "r");
    char buffer[1024];
    char *experado[] = {
        "Cor: VERMELHO\n",
        "Palavra em portugues: barramento\n",
        "Possivel traducao em ingles: Bus\n",
        "Apareceu em: Unidade 1\n",
        "Cor: PRETO\n",
        "Palavra em portugues: bicicleta\n",
        "Possivel traducao em ingles: Bicycle\n",
        "Apareceu em: Unidade 2\n",
        "Possivel traducao em ingles: Bike\n",
        "Apareceu em: Unidade 1\n",
        "Cor: PRETO\n",
        "Palavra em portugues: inseto\n",
        "Possivel traducao em ingles: Bug\n",
        "Apareceu em: Unidade 2\n",
        "Cor: PRETO\n",
        "Palavra em portugues: onibus\n",
        "Possivel traducao em ingles: Bus\n",
        "Apareceu em: Unidade 1\n",
        "Cor: PRETO\n",
        "Palavra em portugues: rede de computadores\n",
        "Possivel traducao em ingles: Network\n",
        "Apareceu em: Unidade 1\n",
        "Cor: PRETO\n",
        "Palavra em portugues: rede de relacionamento\n",
        "Possivel traducao em ingles: Network\n",
        "Apareceu em: Unidade 2\n",
        "Cor: PRETO\n",
        "Palavra em portugues: sistema\n",
        "Possivel traducao em ingles: System\n",
        "Apareceu em: Unidade 1\n",
        "Cor: PRETO\n",
        "Palavra em portugues: ventilador\n",
        "Possivel traducao em ingles: Coller\n",
        "Apareceu em: Unidade 1\n",
        "Possivel traducao em ingles: Fan\n",
        "Apareceu em: Unidade 2\n"};

    for (int i = 0; i < 36; i++)
    {
      fgets(buffer, 1024, fp);
      TEST_ASSERT_EQUAL_STRING(experado[i], buffer);
    }
    fclose(fp);
  }

void test_remove_palavra_ingles_unidade_caso_bug_unidade_2()
{
  FILE *fp = freopen("output/test_remove_palavra_ingles_unidade_caso_bug_unidade_2.txt", "w", stdout);
  remove_palavra_ingles_unidade(&raiz, "Bug", "Unidade 2");
  show_arvore_vermelho_preto(raiz);
  fclose(fp);
  freopen("/dev/tty", "w", stdout);

  fp = fopen("output/test_remove_palavra_ingles_unidade_caso_bug_unidade_2.txt", "r");
  char buffer[1024];
  char *experado[] = {
      "Cor: VERMELHO\n",
      "Palavra em portugues: barramento\n",
      "Possivel traducao em ingles: Bus\n",
      "Apareceu em: Unidade 1\n",
      "Cor: PRETO\n",
      "Palavra em portugues: bicicleta\n",
      "Possivel traducao em ingles: Bicycle\n",
      "Apareceu em: Unidade 2\n",
      "Possivel traducao em ingles: Bike\n",
      "Apareceu em: Unidade 1\n",
      "Cor: PRETO\n",
      "Palavra em portugues: inseto\n",
      "Possivel traducao em ingles: Bug\n",
      "Apareceu em: Unidade 1\n",
      "Cor: PRETO\n",
      "Palavra em portugues: onibus\n",
      "Possivel traducao em ingles: Bus\n",
      "Apareceu em: Unidade 1\n",
      "Cor: PRETO\n",
      "Palavra em portugues: problema\n",
      "Possivel traducao em ingles: Bug\n",
      "Apareceu em: Unidade 1\n",
      "Cor: VERMELHO\n",
      "Palavra em portugues: rede de computadores\n",
      "Possivel traducao em ingles: Network\n",
      "Apareceu em: Unidade 1\n",
      "Cor: PRETO\n",
      "Palavra em portugues: rede de relacionamento\n",
      "Possivel traducao em ingles: Network\n",
      "Apareceu em: Unidade 2\n",
      "Cor: PRETO\n",
      "Palavra em portugues: sistema\n",
      "Possivel traducao em ingles: System\n",
      "Apareceu em: Unidade 1\n",
      "Cor: PRETO\n",
      "Palavra em portugues: ventilador\n",
      "Possivel traducao em ingles: Coller\n",
      "Apareceu em: Unidade 1\n",
      "Possivel traducao em ingles: Fan\n",
      "Apareceu em: Unidade 2\n"};

  for (int i = 0; i < 40; i++)
  {
    fgets(buffer, 1024, fp);
    TEST_ASSERT_EQUAL_STRING(experado[i], buffer);
  }
  fclose(fp);
}

void test_remove_palavra_portugues_unidade_caso_inseto_unidade_1()
{
  FILE *fp = freopen("output/test_remove_palavra_portugues_unidade_caso_inseto_unidade_1.txt", "w", stdout);
  remove_palavra_portugues_unidade(&raiz, "inseto", "Unidade 1");
  show_arvore_vermelho_preto(raiz);
  fclose(fp);
  freopen("/dev/tty", "w", stdout);

  fp = fopen("output/test_remove_palavra_portugues_unidade_caso_inseto_unidade_1.txt", "r");
  char buffer[1024];
  char *experado[] = {
    "Cor: VERMELHO\n",
    "Palavra em portugues: barramento\n",
    "Possivel traducao em ingles: Bus\n",
    "Apareceu em: Unidade 1\n",
    "Cor: PRETO\n",
    "Palavra em portugues: bicicleta\n",
    "Possivel traducao em ingles: Bicycle\n",
    "Apareceu em: Unidade 2\n",
    "Possivel traducao em ingles: Bike\n",
    "Apareceu em: Unidade 1\n",
    "Cor: PRETO\n",
    "Palavra em portugues: inseto\n",
    "Possivel traducao em ingles: Bug\n",
    "Apareceu em: Unidade 2\n",
    "Cor: PRETO\n",
    "Palavra em portugues: onibus\n",
    "Possivel traducao em ingles: Bus\n",
    "Apareceu em: Unidade 1\n",
    "Cor: PRETO\n",
    "Palavra em portugues: problema\n",
    "Possivel traducao em ingles: Bug\n",
    "Apareceu em: Unidade 1\n",
    "Cor: VERMELHO\n",
    "Palavra em portugues: rede de computadores\n",
    "Possivel traducao em ingles: Network\n",
    "Apareceu em: Unidade 1\n",
    "Cor: PRETO\n",
    "Palavra em portugues: rede de relacionamento\n",
    "Possivel traducao em ingles: Network\n",
    "Apareceu em: Unidade 2\n",
    "Cor: PRETO\n",
    "Palavra em portugues: sistema\n",
    "Possivel traducao em ingles: System\n",
    "Apareceu em: Unidade 1\n",
    "Cor: PRETO\n",
    "Palavra em portugues: ventilador\n",
    "Possivel traducao em ingles: Coller\n",
    "Apareceu em: Unidade 1\n",
    "Possivel traducao em ingles: Fan\n",
    "Apareceu em: Unidade 2\n"
  };

  for (int i = 0; i < 40; i++)
  {
    fgets(buffer, 1024, fp);
    TEST_ASSERT_EQUAL_STRING(experado[i], buffer);
  }
}

void test_remove_palavra_portugues_unidade_caso_problema_unidade_2()
{
  FILE *fp = freopen("output/test_remove_palavra_portugues_unidade_caso_problema_unidade_2.txt", "w", stdout);
  remove_palavra_portugues_unidade(&raiz, "problema", "Unidade 1");
  show_arvore_vermelho_preto(raiz);
fclose(fp);
  freopen("/dev/tty", "w", stdout);

  fp = fopen("output/test_remove_palavra_portugues_unidade_caso_problema_unidade_2.txt", "r");
  char buffer[1024];
  char *experado[] = {
    "Cor: VERMELHO\n",
    "Palavra em portugues: barramento\n",
    "Possivel traducao em ingles: Bus\n",
    "Apareceu em: Unidade 1\n",
    "Cor: PRETO\n",
    "Palavra em portugues: bicicleta\n",
    "Possivel traducao em ingles: Bicycle\n",
    "Apareceu em: Unidade 2\n",
    "Possivel traducao em ingles: Bike\n",
    "Apareceu em: Unidade 1\n",
    "Cor: PRETO\n",
    "Palavra em portugues: inseto\n",
    "Possivel traducao em ingles: Bug\n",
    "Apareceu em: Unidade 2, Unidade 1\n",
    "Cor: PRETO\n",
    "Palavra em portugues: onibus\n",
    "Possivel traducao em ingles: Bus\n",
    "Apareceu em: Unidade 1\n",
    "Cor: PRETO\n",
    "Palavra em portugues: rede de computadores\n",
    "Possivel traducao em ingles: Network\n",
    "Apareceu em: Unidade 1\n",
    "Cor: PRETO\n",
    "Palavra em portugues: rede de relacionamento\n",
    "Possivel traducao em ingles: Network\n",
    "Apareceu em: Unidade 2\n",
    "Cor: PRETO\n",
    "Palavra em portugues: sistema\n",
    "Possivel traducao em ingles: System\n",
    "Apareceu em: Unidade 1\n",
    "Cor: PRETO\n",
    "Palavra em portugues: ventilador\n",
    "Possivel traducao em ingles: Coller\n",
    "Apareceu em: Unidade 1\n",
    "Possivel traducao em ingles: Fan\n",
    "Apareceu em: Unidade 2\n"
  };

  for (int i = 0; i < 36; i++)
  {
    fgets(buffer, 1024, fp);
    TEST_ASSERT_EQUAL_STRING(experado[i], buffer);
  }
  fclose(fp);
}
