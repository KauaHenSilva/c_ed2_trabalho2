#include "Unity/unity.h"
#include "include/arvore_vermelho_preto.h"

ArvoreVermelhoPreto *raiz;

void prencher_automatico(int *valores, int qtd)
{
  for (int i = 0; i < qtd; i++)
  {
    ArvoreVermelhoPreto *newTree = NULL;
    aloca_arvore_vermelho_preto(&newTree);
    char nome_unidade[20];
    char palavra_portugues[20];
    sprintf(nome_unidade, "Unidade %d", valores[i]);
    sprintf(palavra_portugues, "%d", valores[i]);
    def_arvore_vermelho_preto(newTree, palavra_portugues, palavra_portugues, nome_unidade);
    inserir_arvore_vermelho_preto(&raiz, newTree);
  }
}

void setUp(void)
{
  raiz = NULL;
}

void tearDown(void)
{
  free_arvore_vermelho_preto(&raiz);
}

void test_remocao_arvore_vermelha_preta_caso_1(); // inc: 4, 2, 5, 1, 3 -> rem: 3
void test_remocao_arvore_vermelho_preto_caso_2(); // inc: 4, 2, 5, 1, 3 -> rem: 2
void test_remocao_arvore_vermelho_preto_caso_3(); // inc: 4, 2, 5, 1, 3 -> rem: 4
void test_remocao_arvore_vermelho_preto_caso_4(); // inc: 4, 2, 5, 1, 3 -> rem: 5
void test_remocao_arvore_vermelho_preto_caso_5(); // inc: 4, 2, 5, 1, 3 -> rem: 1
void test_remocao_arvore_vermelho_preto_caso_6(); // inc: 3 -> rem: 2
void test_remocao_arvore_vermelho_preto_caso_7(); // inc: 3 -> rem: 3
void test_remocao_arvore_vermelho_preto_caso_8(); // inc: 3 -> rem: 4
void test_remocao_arvore_vermelho_preto_caso_9(); // inc: 1, 2, 3, 4, 5 -> 0

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_remocao_arvore_vermelha_preta_caso_1);
  RUN_TEST(test_remocao_arvore_vermelho_preto_caso_2);
  RUN_TEST(test_remocao_arvore_vermelho_preto_caso_3);
  RUN_TEST(test_remocao_arvore_vermelho_preto_caso_4);
  RUN_TEST(test_remocao_arvore_vermelho_preto_caso_5);
  RUN_TEST(test_remocao_arvore_vermelho_preto_caso_6);
  RUN_TEST(test_remocao_arvore_vermelho_preto_caso_7);
  RUN_TEST(test_remocao_arvore_vermelho_preto_caso_8);
  RUN_TEST(test_remocao_arvore_vermelho_preto_caso_9);
  return UNITY_END();
}

void test_remocao_arvore_vermelha_preta_caso_1()
{
  int valores_adicinar[] = {4, 2, 5, 1, 3};
  prencher_automatico(valores_adicinar, 5);

  int confirmacao = remover_arvore_vermelho_preto(&raiz, "3");

  TEST_ASSERT_EQUAL_INT(1, confirmacao);
  TEST_ASSERT_EQUAL_STRING("4", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("5", raiz->dir->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->esq->info.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->esq->esq->cor);

  TEST_ASSERT_NULL(raiz->dir->esq);
  TEST_ASSERT_NULL(raiz->dir->dir);
  TEST_ASSERT_NULL(raiz->esq->dir);
  TEST_ASSERT_NULL(raiz->esq->esq->esq);
  TEST_ASSERT_NULL(raiz->esq->esq->dir);
}

void test_remocao_arvore_vermelho_preto_caso_2()
{
  int valores_adicinar[] = {4, 2, 5, 1, 3};
  prencher_automatico(valores_adicinar, 5);

  int confirmacao = remover_arvore_vermelho_preto(&raiz, "2");

  TEST_ASSERT_EQUAL_INT(1, confirmacao);
  TEST_ASSERT_EQUAL_STRING("4", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("5", raiz->dir->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->esq->info.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->esq->esq->cor);

  TEST_ASSERT_NULL(raiz->dir->esq);
  TEST_ASSERT_NULL(raiz->dir->dir);
  TEST_ASSERT_NULL(raiz->esq->dir);
  TEST_ASSERT_NULL(raiz->esq->esq->esq);
  TEST_ASSERT_NULL(raiz->esq->esq->dir);
}

void test_remocao_arvore_vermelho_preto_caso_3()
{
  int valores_adicinar[] = {4, 2, 5, 1, 3};
  prencher_automatico(valores_adicinar, 5);

  int confirmacao = remover_arvore_vermelho_preto(&raiz, "4");

  TEST_ASSERT_EQUAL_INT(1, confirmacao);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("5", raiz->dir->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->esq->info.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->dir->esq->cor);

  TEST_ASSERT_NULL(raiz->dir->dir);
  TEST_ASSERT_NULL(raiz->dir->esq->dir);
  TEST_ASSERT_NULL(raiz->dir->esq->esq);
  TEST_ASSERT_NULL(raiz->esq->dir);
  TEST_ASSERT_NULL(raiz->esq->esq);
}

void test_remocao_arvore_vermelho_preto_caso_4()
{
  int valores_adicinar[] = {4, 2, 5, 1, 3};
  prencher_automatico(valores_adicinar, 5);

  int confirmacao = remover_arvore_vermelho_preto(&raiz, "5");

  TEST_ASSERT_EQUAL_INT(1, confirmacao);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("4", raiz->dir->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->esq->info.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->dir->esq->cor);

  TEST_ASSERT_NULL(raiz->dir->dir);
  TEST_ASSERT_NULL(raiz->dir->esq->dir);
  TEST_ASSERT_NULL(raiz->dir->esq->esq);
  TEST_ASSERT_NULL(raiz->esq->dir);
  TEST_ASSERT_NULL(raiz->esq->esq);
}

void test_remocao_arvore_vermelho_preto_caso_5()
{
  int valores_adicinar[] = {4, 2, 5, 1, 3};
  prencher_automatico(valores_adicinar, 5);

  int confirmacao = remover_arvore_vermelho_preto(&raiz, "1");

  TEST_ASSERT_EQUAL_INT(1, confirmacao);
  TEST_ASSERT_EQUAL_STRING("4", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("5", raiz->dir->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", raiz->esq->esq->info.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->esq->esq->cor);

  TEST_ASSERT_NULL(raiz->dir->esq);
  TEST_ASSERT_NULL(raiz->dir->dir);
  TEST_ASSERT_NULL(raiz->esq->dir);
  TEST_ASSERT_NULL(raiz->esq->esq->esq);
  TEST_ASSERT_NULL(raiz->esq->esq->dir);
}

void test_remocao_arvore_vermelho_preto_caso_6()
{
  int valores_adicinar[] = {3};
  prencher_automatico(valores_adicinar, 1);

  int confirmacao = remover_arvore_vermelho_preto(&raiz, "2");

  TEST_ASSERT_EQUAL_INT(0, confirmacao);
  TEST_ASSERT_EQUAL_STRING("3", raiz->info.palavra_portugues);
  TEST_ASSERT_NULL(raiz->esq);
  TEST_ASSERT_NULL(raiz->dir);

  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
}

void test_remocao_arvore_vermelho_preto_caso_7()
{
  int valores_adicinar[] = {3};
  prencher_automatico(valores_adicinar, 1);

  int confirmacao = remover_arvore_vermelho_preto(&raiz, "3");

  TEST_ASSERT_EQUAL_INT(1, confirmacao);
  TEST_ASSERT_NULL(raiz);
}

void test_remocao_arvore_vermelho_preto_caso_8()
{
  int valores_adicinar[] = {3};
  prencher_automatico(valores_adicinar, 1);

  int confirmacao = remover_arvore_vermelho_preto(&raiz, "4");

  TEST_ASSERT_EQUAL_INT(0, confirmacao);
  TEST_ASSERT_EQUAL_STRING("3", raiz->info.palavra_portugues);
  TEST_ASSERT_NULL(raiz->esq);
  TEST_ASSERT_NULL(raiz->dir);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
}

void test_remocao_arvore_vermelho_preto_caso_9()
{
  int valores_adicionar[] = {1, 2, 3, 4, 5};
  prencher_automatico(valores_adicionar, 5);

  int confirmacao = remover_arvore_vermelho_preto(&raiz, "0");
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->dir->cor);
}