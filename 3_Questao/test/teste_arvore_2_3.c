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

void compare_arvore(Arvore_2_3 *raiz, Informacao info1, Informacao info2, Arvore_2_3 *esq, Arvore_2_3 *meio, Arvore_2_3 *dir, int qtd_info)
{
  compare_info(raiz->info1, info1.inicio, info1.final, info1.status);

  TEST_ASSERT_EQUAL_PTR(esq, raiz->esquerda);
  TEST_ASSERT_EQUAL_PTR(meio, raiz->meio);
  TEST_ASSERT_EQUAL_INT(qtd_info, raiz->qtd_info);

  if (qtd_info == 2)
  {
    compare_info(raiz->info2, info2.inicio, info2.final, info2.status);
    TEST_ASSERT_EQUAL_PTR(dir, raiz->direita);
  }
}

void test_set_info();
void test_criar_arvore_2_3();
void test_adicionar_informacao_caso_1();
void test_adicionar_informacao_caso_2();
void test_eh_folha_caso_1();
void test_eh_folha_caso_2();
void test_inserct_arvore_2_3();

int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_set_info);
  RUN_TEST(test_criar_arvore_2_3);
  RUN_TEST(test_adicionar_informacao_caso_1);
  RUN_TEST(test_adicionar_informacao_caso_2);
  RUN_TEST(test_eh_folha_caso_1);
  RUN_TEST(test_eh_folha_caso_2);
  RUN_TEST(test_inserct_arvore_2_3);
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
  compare_arvore(arvore, info, info, NULL, NULL, NULL, 1);
}

void test_adicionar_informacao_caso_1()
{
  Informacao info1, info2;
  set_info(&info1, 10, 20, OCUPADA);
  set_info(&info2, 21, 40, OCUPADA);

  criar_arvore_2_3(&arvore, info1, NULL, NULL);
  adicionar_informacao(arvore, info2, NULL);

  compare_arvore(arvore, info1, info2, NULL, NULL, NULL, 2);
}

void test_adicionar_informacao_caso_2()
{
  Informacao info1, info2;
  set_info(&info1, 21, 40, OCUPADA);
  set_info(&info2, 10, 20, OCUPADA);

  criar_arvore_2_3(&arvore, info1, NULL, NULL);
  adicionar_informacao(arvore, info2, NULL);

  compare_arvore(arvore, info2, info1, NULL, NULL, NULL, 2);
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

void test_inserct_arvore_2_3()
{
  Informacao info1, info2, info3, info4, info5;
  set_info(&info1, 21, 40, OCUPADA);

  set_inserir_arvore_2_3(&arvore, info1);

  compare_arvore(arvore, info1, info1, NULL, NULL, NULL, 1);
}