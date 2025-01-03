#include "test/Unity/unity.h"
#include "include/arvore_2_3.h"
#include <stdlib.h>

Arvore_2_3 *arvore;

void setUp(void)
{
  arvore = NULL;
}

void tearDown(void)
{
  free_arvore_2_3(arvore);
}

void compare_info(Informacao info, int inicio, int final, STATUS status)
{
  TEST_ASSERT_EQUAL_INT(inicio, info.inicio);
  TEST_ASSERT_EQUAL_INT(final, info.final);
  TEST_ASSERT_EQUAL_INT(status, info.status);
}

void prencher_arvore(int *valores_adicionar, int tamanho, STATUS status_inicial)
{
  int inicio = 0;
  STATUS status = status_inicial;
  for (int i = 0; i < tamanho; i++)
  {
    Informacao info;
    set_info(&info, inicio, valores_adicionar[i], status);
    set_inserir_arvore_2_3(&arvore, info);
    inicio = valores_adicionar[i] + 1;
    status = status == LIVRE ? OCUPADA : LIVRE;
  }
}

void test_set_info();
void test_criar_arvore_2_3();
void test_adicionar_informacao_caso_1();
void test_adicionar_informacao_caso_2();
void test_eh_folha_caso_1();
void test_eh_folha_caso_2();
void test_inserct_arvore_2_3_caso_1();
void test_inserct_arvore_2_3_caso_2();
void test_inserct_arvore_2_3_caso_3();
void test_inserct_arvore_2_3_caso_4();
void test_aloca_desaloca_no_caso_1();
void test_aloca_desaloca_no_caso_2();
void test_aloca_desaloca_no_caso_3();
void test_aloca_desaloca_no_caso_4();
void test_aloca_desaloca_no_caso_5();
void test_aloca_desaloca_no_caso_6();
void test_aloca_desaloca_no_caso_7();

int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_set_info);
  RUN_TEST(test_criar_arvore_2_3);
  RUN_TEST(test_adicionar_informacao_caso_1);
  RUN_TEST(test_adicionar_informacao_caso_2);
  RUN_TEST(test_eh_folha_caso_1);
  RUN_TEST(test_eh_folha_caso_2);
  RUN_TEST(test_inserct_arvore_2_3_caso_1);
  RUN_TEST(test_inserct_arvore_2_3_caso_2);
  RUN_TEST(test_inserct_arvore_2_3_caso_3);
  RUN_TEST(test_inserct_arvore_2_3_caso_4);
  RUN_TEST(test_aloca_desaloca_no_caso_1);
  RUN_TEST(test_aloca_desaloca_no_caso_2);  
  RUN_TEST(test_aloca_desaloca_no_caso_3);
  RUN_TEST(test_aloca_desaloca_no_caso_4);
  RUN_TEST(test_aloca_desaloca_no_caso_5);
  RUN_TEST(test_aloca_desaloca_no_caso_6);
  RUN_TEST(test_aloca_desaloca_no_caso_7);
  return UNITY_END();
}

void test_set_info()
{
  Informacao info;
  set_info(&info, 10, 20, OCUPADA);
  compare_info(info, 10, 20, OCUPADA);
}

void test_criar_arvore_2_3()
{
  Informacao info;
  set_info(&info, 10, 20, OCUPADA);

  TEST_ASSERT_EQUAL(1, criar_arvore_2_3(&arvore, info, NULL, NULL));
  compare_info(arvore->info1, 10, 20, OCUPADA);
}

void test_adicionar_informacao_caso_1()
{
  Informacao info1, info2;
  set_info(&info1, 10, 20, OCUPADA);
  set_info(&info2, 21, 40, OCUPADA);

  criar_arvore_2_3(&arvore, info1, NULL, NULL);
  adicionar_informacao(arvore, info2, NULL);

  compare_info(arvore->info1, 10, 20, OCUPADA);
  compare_info(arvore->info2, 21, 40, OCUPADA);
}

void test_adicionar_informacao_caso_2()
{
  Informacao info1, info2;
  set_info(&info1, 21, 40, OCUPADA);
  set_info(&info2, 10, 20, OCUPADA);

  criar_arvore_2_3(&arvore, info1, NULL, NULL);
  adicionar_informacao(arvore, info2, NULL);

  compare_info(arvore->info1, 10, 20, OCUPADA);
  compare_info(arvore->info2, 21, 40, OCUPADA);
}

void test_eh_folha_caso_1()
{
  Informacao info1;
  set_info(&info1, 21, 40, OCUPADA);

  criar_arvore_2_3(&arvore, info1, NULL, NULL);
  TEST_ASSERT_EQUAL(1, eh_folha(arvore));
}

void test_eh_folha_caso_2()
{
  Informacao info1, info2, info3;
  set_info(&info1, 21, 40, OCUPADA);
  set_info(&info2, 10, 20, OCUPADA);
  set_info(&info3, 41, 50, OCUPADA);

  criar_arvore_2_3(&arvore, info1, NULL, NULL);
  criar_arvore_2_3(&arvore->esquerda, info2, NULL, NULL);
  criar_arvore_2_3(&arvore->meio, info3, NULL, NULL);

  TEST_ASSERT_EQUAL(0, eh_folha(arvore));
}

void test_inserct_arvore_2_3_caso_1()
{
  prencher_arvore((int[]){10, 20, 40}, 3, OCUPADA);

  FILE *fp = freopen("output/test_inserct_arvore_2_3_caso_1.txt", "w", stdout);
  show_arvore_2_3(arvore);
  fclose(fp);
  freopen("/dev/tty", "w", stdout);

  char *expected_[] = {
      "Info1: 0 - 10 - O\n",
      "Info1: 11 - 20 - L\n",
      "Info1: 21 - 40 - O\n",
  };

  FILE *file = fopen("output/test_inserct_arvore_2_3_caso_1.txt", "r");
  char buffer[1024];
  for (int i = 0; i < 3; i++)
  {
    fgets(buffer, 1024, file);
    TEST_ASSERT_EQUAL_STRING(expected_[i], buffer);
  }
  fclose(file);
}

void test_inserct_arvore_2_3_caso_2()
{
  prencher_arvore((int[]){10, 20, 40, 50, 60, 70}, 6, LIVRE);

  FILE *fp = freopen("output/test_inserct_arvore_2_3_caso_2.txt", "w", stdout);
  show_arvore_2_3(arvore);
  fclose(fp);
  freopen("/dev/tty", "w", stdout);

  char *expected_[] = {
      "Info1: 0 - 10 - L\n",
      "Info1: 11 - 20 - O\n",
      "Info1: 21 - 40 - L\n",
      "Info2: 41 - 50 - O\n",
      "Info1: 51 - 60 - L\n",
      "Info2: 61 - 70 - O\n",
  };

  FILE *file = fopen("output/test_inserct_arvore_2_3_caso_2.txt", "r");
  char buffer[1024];
  for (int i = 0; i < 6; i++)
  {
    fgets(buffer, 1024, file);
    TEST_ASSERT_EQUAL_STRING(expected_[i], buffer);
  }
  fclose(file);
}

void test_inserct_arvore_2_3_caso_3()
{
  prencher_arvore((int[]){10, 20, 40, 50, 60, 70}, 6, OCUPADA);

  FILE *file = freopen("output/test_inserct_arvore_2_3_caso_3.txt", "w", stdout);
  show_arvore_2_3(arvore);
  fclose(file);
  freopen("/dev/tty", "w", stdout);

  char *expected_[] = {
      "Info1: 0 - 10 - O\n",
      "Info1: 11 - 20 - L\n",
      "Info1: 21 - 40 - O\n",
      "Info2: 41 - 50 - L\n",
      "Info1: 51 - 60 - O\n",
      "Info2: 61 - 70 - L\n",
  };

  file = fopen("output/test_inserct_arvore_2_3_caso_3.txt", "r");
  char buffer[255];
  for (int i = 0; i < 6; i++)
  {
    fgets(buffer, 255, file);
    TEST_ASSERT_EQUAL_STRING(expected_[i], buffer);
  }
  fclose(file);
}

void test_inserct_arvore_2_3_caso_4()
{
  prencher_arvore((int[]){10, 20, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130}, 12, LIVRE);

  FILE *file = freopen("output/test_inserct_arvore_2_3_caso_4.txt", "w", stdout);
  show_arvore_2_3(arvore);
  fclose(file);
  freopen("/dev/tty", "w", stdout);

  char *expected_[] = {
      "Info1: 0 - 10 - L\n",
      "Info1: 11 - 20 - O\n",
      "Info1: 21 - 40 - L\n",
      "Info1: 41 - 50 - O\n",
      "Info1: 51 - 60 - L\n",
      "Info1: 61 - 70 - O\n",
      "Info1: 71 - 80 - L\n",
      "Info2: 81 - 90 - O\n",
      "Info1: 91 - 100 - L\n",
      "Info1: 101 - 110 - O\n",
      "Info1: 111 - 120 - L\n",
      "Info2: 121 - 130 - O\n",
  };

  file = fopen("output/test_inserct_arvore_2_3_caso_4.txt", "r");
  char buffer[255];
  for (int i = 0; i < 12; i++)
  {
    fgets(buffer, 255, file);
    TEST_ASSERT_EQUAL_STRING(expected_[i], buffer);
  }
  fclose(file);
}

void test_aloca_desaloca_no_caso_1()
{
  prencher_arvore((int[]){10, 20, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130}, 12, LIVRE);

  int qtd_alocar = 10;

  FILE *file = freopen("output/test_aloca_desaloca_no_caso_1.txt", "w", stdout);
  printf("Antes: \n");
  show_arvore_2_3(arvore);
  alocar_desalocar_no(&arvore, qtd_alocar, LIVRE);
  printf("\nDepois: \n");
  show_arvore_2_3(arvore);
  fclose(file);
  freopen("/dev/tty", "w", stdout);

  char *expected_[] = {
    "Antes: \n",
    "Info1: 0 - 10 - L\n",
    "Info1: 11 - 20 - O\n",
    "Info1: 21 - 40 - L\n",
    "Info1: 41 - 50 - O\n",
    "Info1: 51 - 60 - L\n",
    "Info1: 61 - 70 - O\n",
    "Info1: 71 - 80 - L\n",
    "Info2: 81 - 90 - O\n",
    "Info1: 91 - 100 - L\n",
    "Info1: 101 - 110 - O\n",
    "Info1: 111 - 120 - L\n",
    "Info2: 121 - 130 - O\n",
    "\nDepois: \n",
    "Info1: 0 - 9 - O\n",
    "Info2: 10 - 10 - L\n",
    "Info1: 11 - 20 - O\n",
    "Info1: 21 - 40 - L\n",
    "Info1: 41 - 50 - O\n",
    "Info1: 51 - 60 - L\n",
    "Info1: 61 - 70 - O\n",
    "Info1: 71 - 80 - L\n",
    "Info2: 81 - 90 - O\n",
    "Info1: 91 - 100 - L\n",
    "Info1: 101 - 110 - O\n",
    "Info1: 111 - 120 - L\n",
    "Info2: 121 - 130 - O\n",
  };

  file = fopen("output/test_aloca_desaloca_no_caso_1.txt", "r");
  char buffer[255];

  for (int i = 0; i < 12; i++)
  {
    fgets(buffer, 255, file);
    TEST_ASSERT_EQUAL_STRING(expected_[i], buffer);
  }

  fclose(file);
}

void test_aloca_desaloca_no_caso_2()
{
  prencher_arvore((int[]){10, 20, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130}, 12, OCUPADA);

  int qtd_alocar = 10;

  FILE *file = freopen("output/test_aloca_desaloca_no_caso_2.txt", "w", stdout);
  printf("Antes: \n");
  show_arvore_2_3(arvore);
  alocar_desalocar_no(&arvore, qtd_alocar, LIVRE);
  printf("\nDepois: \n");
  show_arvore_2_3(arvore);
  fclose(file);
  freopen("/dev/tty", "w", stdout);

  char *expected[] = {
    "Antes: \n",
    "Info1: 0 - 10 - O\n",
    "Info1: 11 - 20 - L\n",
    "Info1: 21 - 40 - O\n",
    "Info1: 41 - 50 - L\n",
    "Info1: 51 - 60 - O\n",
    "Info1: 61 - 70 - L\n",
    "Info1: 71 - 80 - O\n",
    "Info2: 81 - 90 - L\n",
    "Info1: 91 - 100 - O\n",
    "Info1: 101 - 110 - L\n",
    "Info1: 111 - 120 - O\n",
    "Info2: 121 - 130 - L\n",
    "\n",
    "Depois: \n",
    "Info1: 0 - 40 - O\n",
    "Info1: 41 - 50 - L\n",
    "Info1: 51 - 60 - O\n",
    "Info1: 61 - 70 - L\n",
    "Info1: 71 - 80 - O\n",
    "Info1: 81 - 90 - L\n",
    "Info1: 91 - 100 - O\n",
    "Info2: 101 - 110 - L\n",
    "Info1: 111 - 120 - O\n",
    "Info2: 121 - 130 - L\n",
  };

  file = fopen("output/test_aloca_desaloca_no_caso_2.txt", "r");
  char buffer[255];

  for (int i = 0; i < 24; i++)
  {
    fgets(buffer, 255, file);
    TEST_ASSERT_EQUAL_STRING(expected[i], buffer);
  }

  fclose(file);
}

void test_aloca_desaloca_no_caso_3()
{
  prencher_arvore((int[]){1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 23}, 12, OCUPADA);

  int qtd_alocar = 10;

  FILE *file = freopen("output/test_aloca_desaloca_no_caso_3.txt", "w", stdout);
  printf("Antes: \n");
  show_arvore_2_3(arvore);
  alocar_desalocar_no(&arvore, qtd_alocar, LIVRE);
  printf("\nDepois: \n");
  show_arvore_2_3(arvore);
  fclose(file);
  freopen("/dev/tty", "w", stdout);

  char *expected[] = {
    "Antes: \n",
    "Info1: 0 - 1 - O\n",
    "Info1: 2 - 2 - L\n",
    "Info1: 3 - 4 - O\n",
    "Info1: 5 - 5 - L\n",
    "Info1: 6 - 6 - O\n",
    "Info1: 7 - 7 - L\n",
    "Info1: 8 - 8 - O\n",
    "Info2: 9 - 9 - L\n",
    "Info1: 10 - 10 - O\n",
    "Info1: 11 - 11 - L\n",
    "Info1: 12 - 12 - O\n",
    "Info2: 13 - 23 - L\n",
    "\n",
    "Depois: \n",
    "Info1: 0 - 1 - O\n",
    "Info1: 2 - 2 - L\n",
    "Info1: 3 - 4 - O\n",
    "Info1: 5 - 5 - L\n",
    "Info1: 6 - 6 - O\n",
    "Info1: 7 - 7 - L\n",
    "Info1: 8 - 8 - O\n",
    "Info2: 9 - 9 - L\n",
    "Info1: 10 - 10 - O\n",
    "Info1: 11 - 11 - L\n",
    "Info1: 12 - 22 - O\n",
    "Info2: 23 - 23 - L\n",
  };

  file = fopen("output/test_aloca_desaloca_no_caso_3.txt", "r");
  char buffer[255];

  for (int i = 0; i < 24; i++)
  {
    fgets(buffer, 255, file);
    TEST_ASSERT_EQUAL_STRING(expected[i], buffer);
  }

  fclose(file);

}

void test_aloca_desaloca_no_caso_4()
{
  prencher_arvore((int[]){1, 2, 4, 5, 6, 7, 90, 100, 110, 120}, 10, OCUPADA);

  int qtd_alocar = 10;

  FILE *file = freopen("output/test_aloca_desaloca_no_caso_4.txt", "w", stdout);
  printf("Antes: \n");
  show_arvore_2_3(arvore);
  alocar_desalocar_no(&arvore, qtd_alocar, LIVRE);
  printf("\nDepois: \n");
  show_arvore_2_3(arvore);
  fclose(file);
  freopen("/dev/tty", "w", stdout);
}


void test_aloca_desaloca_no_caso_5()
{
  prencher_arvore((int[]){10, 20, 30, 40, 50, 60, 70, 80, 90, 100}, 10, OCUPADA);

  int qtd_alocar = 10;

  FILE *file = freopen("output/test_aloca_desaloca_no_caso_5.txt", "w", stdout);
  printf("Antes: \n");
  show_arvore_2_3(arvore);
  alocar_desalocar_no(&arvore, qtd_alocar, LIVRE);
  printf("\nDepois: \n");
  show_arvore_2_3(arvore);
  fclose(file);
  freopen("/dev/tty", "w", stdout);

}

void test_aloca_desaloca_no_caso_6()
{
  prencher_arvore((int[]){19, 40, 60, 80, 100}, 5, OCUPADA);

  int qtd_alocar = 21;

  FILE *file = freopen("output/test_aloca_desaloca_no_caso_6.txt", "w", stdout);
  printf("Antes: \n");
  show_arvore_2_3(arvore);
  alocar_desalocar_no(&arvore, qtd_alocar, LIVRE);
  printf("\nDepois: \n");
  show_arvore_2_3(arvore);
  fclose(file);
  freopen("/dev/tty", "w", stdout);
}

void test_aloca_desaloca_no_caso_7()
{
  prencher_arvore((int[]){19, 40, 60, 80, 100}, 5, OCUPADA);

  int qtd_alocar = 20;

  FILE *file = freopen("output/test_aloca_desaloca_no_caso_7.txt", "w", stdout);
  printf("Antes: \n");
  show_arvore_2_3(arvore);
  alocar_desalocar_no(&arvore, qtd_alocar, OCUPADA);
  printf("\nDepois: \n");
  show_arvore_2_3(arvore);
  fclose(file);
  freopen("/dev/tty", "w", stdout);
}