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

void prencher_arvore_caso_1()
{
  Informacao info1, info2, info3, info4, info5, info6;
  set_info(&info1, 0, 10, LIVRE);
  set_info(&info2, 11, 20, OCUPADA);
  set_info(&info3, 21, 40, LIVRE);
  set_info(&info4, 41, 50, OCUPADA);
  set_info(&info5, 51, 60, LIVRE);
  set_info(&info6, 61, 70, OCUPADA);


  set_inserir_arvore_2_3(&arvore, info1);
  set_inserir_arvore_2_3(&arvore, info2);
  set_inserir_arvore_2_3(&arvore, info3);
  set_inserir_arvore_2_3(&arvore, info4);
  set_inserir_arvore_2_3(&arvore, info5);
  set_inserir_arvore_2_3(&arvore, info6);
}

void test_set_info();
void test_criar_arvore_2_3();
void test_adicionar_informacao_caso_1();
void test_adicionar_informacao_caso_2();
void test_eh_folha_caso_1();
void test_eh_folha_caso_2();
void test_inserct_arvore_2_3_caso_1();
void test_no_com_tamanho_livre_caso_1();
void test_no_com_tamanho_livre_caso_2();
void test_ocupar_no_caso_1();

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
  RUN_TEST(test_no_com_tamanho_livre_caso_1);
  RUN_TEST(test_no_com_tamanho_livre_caso_2);
  RUN_TEST(test_ocupar_no_caso_1);
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
  // compare_arvore(arvore, info, info, 1);
}

void test_adicionar_informacao_caso_1()
{
  Informacao info1, info2;
  set_info(&info1, 10, 20, OCUPADA);
  set_info(&info2, 21, 40, OCUPADA);

  criar_arvore_2_3(&arvore, info1, NULL, NULL);
  adicionar_informacao(arvore, info2, NULL);

  // compare_arvore(arvore, info1, info2, 2);
}

void test_adicionar_informacao_caso_2()
{
  Informacao info1, info2;
  set_info(&info1, 21, 40, OCUPADA);
  set_info(&info2, 10, 20, OCUPADA);

  criar_arvore_2_3(&arvore, info1, NULL, NULL);
  adicionar_informacao(arvore, info2, NULL);

  // compare_arvore(arvore, info2, info1, 2);
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
  Informacao info1, info2, info3, info4, info5;
  set_info(&info1, 10, 20, OCUPADA);
  set_info(&info2, 21, 40, LIVRE);
  set_info(&info3, 41, 50, OCUPADA);
  set_info(&info4, 51, 60, LIVRE);
  set_info(&info5, 61, 70, OCUPADA);

  set_inserir_arvore_2_3(&arvore, info1);
  set_inserir_arvore_2_3(&arvore, info2);
  set_inserir_arvore_2_3(&arvore, info3);
  set_inserir_arvore_2_3(&arvore, info4);
  set_inserir_arvore_2_3(&arvore, info5);

  compare_info(arvore->info1, 21, 40, LIVRE);
  compare_info(arvore->info2, 51, 60, LIVRE);
  compare_info(arvore->esquerda->info1, 10, 20, OCUPADA);
  compare_info(arvore->meio->info1, 41, 50, OCUPADA);
  compare_info(arvore->direita->info1, 61, 70, OCUPADA);


}

void test_no_com_tamanho_livre_caso_1()
{ 
  prencher_arvore_caso_1();
  Arvore_2_3 *no_valido = NULL;

  int info_correspodente = 0;
  no_com_tamanho_livre(&no_valido, &info_correspodente, arvore, 10);

  TEST_ASSERT_NOT_NULL(no_valido);
  TEST_ASSERT_EQUAL(1, info_correspodente);
  TEST_ASSERT_EQUAL(21, no_valido->info1.inicio);
  TEST_ASSERT_EQUAL(40, no_valido->info1.final);
}

void test_no_com_tamanho_livre_caso_2()
{
  prencher_arvore_caso_1();
  Arvore_2_3 *no_valido = NULL;

  int info_correspodente = 0;
  no_com_tamanho_livre(&no_valido, &info_correspodente, arvore, 19);

  TEST_ASSERT_NOT_NULL(no_valido);
  TEST_ASSERT_EQUAL(1, info_correspodente);
  TEST_ASSERT_EQUAL(21, no_valido->info1.inicio);
  TEST_ASSERT_EQUAL(40, no_valido->info1.final);
}

void test_ocupar_no_caso_1()
{
  prencher_arvore_caso_1();
  // ocupar_no(&arvore, 10);

  show_arvore_2_3(arvore);
}