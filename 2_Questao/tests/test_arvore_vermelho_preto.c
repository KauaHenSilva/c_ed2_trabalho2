#include "Unity/unity.h"
#include "include/arvore_vermelho_preto.h"

ArvoreVermelhoPreto *raiz;

void setUp(void)
{
  raiz = NULL;
}
void tearDown(void)
{
  free_arvore_vermelho_preto(&raiz);
}

void test_aloca_arvore_vermelha_preta();

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_aloca_arvore_vermelha_preta);
  return UNITY_END();
}

void test_aloca_arvore_vermelha_preta()
{
  aloca_arvore_vermelho_preto(&raiz);
  def_arvore_vermelho_preto(raiz, "Bus", "Onibus", "Unidade 1");

  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Bus", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("Onibus", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->cor);
  TEST_ASSERT_NULL(raiz->esq);
  TEST_ASSERT_NULL(raiz->dir);
}
