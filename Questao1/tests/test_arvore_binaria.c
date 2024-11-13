#include "Unity/unity.h"
#include "include/arvore_binaria.h"

void setUp(void){}
void tearDown(void){}

void test_insercao_arvore_binaria();
void test_aloca_arvore_binaria();

int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_aloca_arvore_binaria);
  RUN_TEST(test_insercao_arvore_binaria);
  return UNITY_END();
}

void test_insercao_arvore_binaria()
{
  ArvoreBinaria *raiz = NULL;

  ArvoreBinaria *new;
  aloca_arvore_binaria(&new, "Palavra2");

  // Inserção na raiz
  int resultado = insercao_arvore_binaria(&raiz, new);
  TEST_ASSERT_EQUAL_INT(0, resultado);
  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Palavra2", raiz->palavra_ingles);
  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->direita);

  // Inserção à esquerda
  ArvoreBinaria *new2;
  aloca_arvore_binaria(&new2, "Palavra1");

  resultado = insercao_arvore_binaria(&raiz, new2);
  TEST_ASSERT_EQUAL_INT(0, resultado);
  TEST_ASSERT_NOT_NULL(raiz->esquerda);
  TEST_ASSERT_EQUAL_STRING("Palavra1", raiz->esquerda->palavra_ingles);
  TEST_ASSERT_NULL(raiz->esquerda->esquerda);
  TEST_ASSERT_NULL(raiz->esquerda->direita);

  // Inserção à direita
  ArvoreBinaria *new3;
  aloca_arvore_binaria(&new3, "Palavra3");

  resultado = insercao_arvore_binaria(&raiz, new3);
  TEST_ASSERT_EQUAL_INT(0, resultado);
  TEST_ASSERT_NOT_NULL(raiz->direita);
  TEST_ASSERT_EQUAL_STRING("Palavra3", raiz->direita->palavra_ingles);
  TEST_ASSERT_NULL(raiz->direita->esquerda);
  TEST_ASSERT_NULL(raiz->direita->direita);

}

void test_aloca_arvore_binaria()
{
  ArvoreBinaria *raiz = NULL;
  aloca_arvore_binaria(&raiz, "Palavra");

  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->direita);
}

