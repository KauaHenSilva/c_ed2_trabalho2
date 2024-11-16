#include "Unity/unity.h"
#include "include/arvore_binaria.h"

ArvoreBinaria *raiz;

void setUp(void)
{
  raiz = NULL;
}
void tearDown(void)
{
  free_arvore_binaria(&raiz);
}

void test_aloca_arvore_binaria();
void test_insercao_arvore_binaria();
void test_atualizar_nome_unidade();

int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_aloca_arvore_binaria);
  RUN_TEST(test_atualizar_nome_unidade);
  RUN_TEST(test_insercao_arvore_binaria);
  return UNITY_END();
}

void test_insercao_arvore_binaria()
{
  ArvoreBinaria *new;
  aloca_arvore_binaria(&new);
  def_arvore_binaria(new, "Palavra2", "Unidade");

  // Inserção na raiz
  int resultado = insercao_arvore_binaria(&raiz, new);
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Palavra2", raiz->palavra_ingles);
  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->direita);

  // Inserção à esquerda
  ArvoreBinaria *new2;
  aloca_arvore_binaria(&new2);
  def_arvore_binaria(new2, "Palavra1", "Unidade");

  resultado = insercao_arvore_binaria(&raiz, new2);
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_NOT_NULL(raiz->esquerda);
  TEST_ASSERT_EQUAL_STRING("Palavra1", raiz->esquerda->palavra_ingles);
  TEST_ASSERT_NULL(raiz->esquerda->esquerda);
  TEST_ASSERT_NULL(raiz->esquerda->direita);

  // Inserção à direita
  ArvoreBinaria *new3;
  aloca_arvore_binaria(&new3);
  def_arvore_binaria(new3, "Palavra3", "Unidade");

  resultado = insercao_arvore_binaria(&raiz, new3);
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_NOT_NULL(raiz->direita);
  TEST_ASSERT_EQUAL_STRING("Palavra3", raiz->direita->palavra_ingles);
  TEST_ASSERT_NULL(raiz->direita->esquerda);
  TEST_ASSERT_NULL(raiz->direita->direita);
}

void test_atualizar_nome_unidade()
{
  ArvoreBinaria *new;
  aloca_arvore_binaria(&new);
  def_arvore_binaria(new, "Palavra2", "Unidade");

  // Inserção na raiz
  int resultado = insercao_arvore_binaria(&raiz, new);
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Palavra2", raiz->palavra_ingles);
  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->direita);

  // Atualização
  ArvoreBinaria *new2;
  aloca_arvore_binaria(&new2);
  def_arvore_binaria(new2, "Palavra1", "Unidade2");

  int resultado_atualizacao = atualizar_nome_unidade(raiz, new2->nome_unidade);
  TEST_ASSERT_EQUAL_INT(1, resultado_atualizacao);
  TEST_ASSERT_EQUAL_STRING("Unidade, Unidade2", raiz->nome_unidade);
  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->direita);
}

void test_aloca_arvore_binaria()
{
  aloca_arvore_binaria(&raiz);
  def_arvore_binaria(raiz, "Palavra", "Unidade");

  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Palavra", raiz->palavra_ingles);
  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->direita);
}
