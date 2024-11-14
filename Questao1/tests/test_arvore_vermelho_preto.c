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
void test_insercao_arvore_vermelha_preta_inserindo();
void test_insercao_arvore_vermelha_preta_valor_unico();
void test_insercao_arvore_vermelha_preta_inserindo_caso_1(); // 1 -> 2 -> 3
void test_insercao_arvore_vermelha_preta_inserindo_caso_2(); // 3 -> 2 -> 1
void test_insercao_arvore_vermelha_preta_inserindo_caso_3(); // 2 -> 1 -> 3
void test_insercao_arvore_vermelha_preta_inserindo_caso_4(); // 3 -> 1 -> 2
void test_insercao_arvore_vermelha_preta_atualizando_caso_1();

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_aloca_arvore_vermelha_preta);
  RUN_TEST(test_insercao_arvore_vermelha_preta_inserindo);
  // RUN_TEST(test_insercao_arvore_vermelha_preta_valor_unico);
  RUN_TEST(test_insercao_arvore_vermelha_preta_inserindo_caso_1);
  RUN_TEST(test_insercao_arvore_vermelha_preta_inserindo_caso_2);
  RUN_TEST(test_insercao_arvore_vermelha_preta_inserindo_caso_3);
  RUN_TEST(test_insercao_arvore_vermelha_preta_inserindo_caso_4);
  RUN_TEST(test_insercao_arvore_vermelha_preta_atualizando_caso_1);
  return UNITY_END();
}

void test_aloca_arvore_vermelha_preta()
{
  aloca_arvore_vermelho_preto(&raiz);
  def_arvore_vermelho_preto(raiz, "Bus", "Onibus", "Unidade 1");

  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Bus", raiz->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("Onibus", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->cor);
  TEST_ASSERT_NULL(raiz->esq);
  TEST_ASSERT_NULL(raiz->dir);
}

void test_insercao_arvore_vermelha_preta_inserindo()
{
  ArvoreVermelhoPreto *newTree;
  aloca_arvore_vermelho_preto(&newTree);
  def_arvore_vermelho_preto(newTree, "Bus", "Onibus", "Unidade 1");

  int resultado = inserir_arvore_vermelho_preto(&raiz, newTree);
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Bus", raiz->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("Onibus", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_NULL(raiz->esq);
  TEST_ASSERT_NULL(raiz->dir);
}

void test_insercao_arvore_vermelha_preta_valor_unico()
{
  ArvoreVermelhoPreto *newTree;
  aloca_arvore_vermelho_preto(&newTree);
  def_arvore_vermelho_preto(newTree, "Bus", "Onibus", "Unidade 1");

  int resultado = inserir_arvore_vermelho_preto(&raiz, newTree);
  TEST_ASSERT_EQUAL_INT(1, resultado);

  resultado = inserir_arvore_vermelho_preto(&raiz, newTree);
  TEST_ASSERT_EQUAL_INT(0, resultado);
}

void test_insercao_arvore_vermelha_preta_inserindo_caso_1()
{
  // Passo 1
  ArvoreVermelhoPreto *newTree1;
  aloca_arvore_vermelho_preto(&newTree1);
  def_arvore_vermelho_preto(newTree1, "1", "1", "Unidade");

  int resultado = inserir_arvore_vermelho_preto(&raiz, newTree1);
  TEST_ASSERT_EQUAL_INT(1, resultado);

  // Passo 2
  ArvoreVermelhoPreto *newTree2;
  aloca_arvore_vermelho_preto(&newTree2);
  def_arvore_vermelho_preto(newTree2, "2", "2", "Unidade");

  resultado = inserir_arvore_vermelho_preto(&raiz, newTree2);
  TEST_ASSERT_EQUAL_INT(1, resultado);

  TEST_ASSERT_NOT_NULL(raiz->esq);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);

  // Passo 3
  ArvoreVermelhoPreto *newTree3;
  aloca_arvore_vermelho_preto(&newTree3);
  def_arvore_vermelho_preto(newTree3, "3", "3", "Unidade");

  resultado = inserir_arvore_vermelho_preto(&raiz, newTree3);
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
}

void test_insercao_arvore_vermelha_preta_inserindo_caso_2()
{
  // Passo 1
  ArvoreVermelhoPreto *newTree1;
  aloca_arvore_vermelho_preto(&newTree1);
  def_arvore_vermelho_preto(newTree1, "3", "3", "Unidade");

  inserir_arvore_vermelho_preto(&raiz, newTree1);

  // Passo 2
  ArvoreVermelhoPreto *newTree2;
  aloca_arvore_vermelho_preto(&newTree2);
  def_arvore_vermelho_preto(newTree2, "2", "2", "Unidade");

  int resultado = inserir_arvore_vermelho_preto(&raiz, newTree2);

  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_EQUAL_STRING("3", raiz->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", raiz->esq->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->esq->cor);

  // Passo 3
  ArvoreVermelhoPreto *newTree3;
  aloca_arvore_vermelho_preto(&newTree3);
  def_arvore_vermelho_preto(newTree3, "1", "1", "Unidade");

  resultado = inserir_arvore_vermelho_preto(&raiz, newTree3);

  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
}

void test_insercao_arvore_vermelha_preta_inserindo_caso_3()
{
  // Passo 1, inserindo o 2.
  ArvoreVermelhoPreto *newTree1;
  aloca_arvore_vermelho_preto(&newTree1);
  def_arvore_vermelho_preto(newTree1, "2", "2", "Unidade");

  inserir_arvore_vermelho_preto(&raiz, newTree1);

  // Passo 2, inserindo o 1.
  ArvoreVermelhoPreto *newTree2;
  aloca_arvore_vermelho_preto(&newTree2);
  def_arvore_vermelho_preto(newTree2, "1", "1", "Unidade");

  int confirmacao = inserir_arvore_vermelho_preto(&raiz, newTree2);

  TEST_ASSERT_EQUAL_INT(1, confirmacao);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);

  // Passo 3, inserindo o 3.
  ArvoreVermelhoPreto *newTree3;
  aloca_arvore_vermelho_preto(&newTree3);
  def_arvore_vermelho_preto(newTree3, "3", "3", "Unidade");

  confirmacao = inserir_arvore_vermelho_preto(&raiz, newTree3);

  TEST_ASSERT_EQUAL_INT(1, confirmacao);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
}

void test_insercao_arvore_vermelha_preta_inserindo_caso_4()
{
  ArvoreVermelhoPreto *newTree1;
  aloca_arvore_vermelho_preto(&newTree1);
  def_arvore_vermelho_preto(newTree1, "3", "3", "Unidade");

  inserir_arvore_vermelho_preto(&raiz, newTree1);

  ArvoreVermelhoPreto *newTree2;
  aloca_arvore_vermelho_preto(&newTree2);
  def_arvore_vermelho_preto(newTree2, "1", "1", "Unidade");

  inserir_arvore_vermelho_preto(&raiz, newTree2);

  ArvoreVermelhoPreto *newTree3;
  aloca_arvore_vermelho_preto(&newTree3);
  def_arvore_vermelho_preto(newTree3, "2", "2", "Unidade");

  inserir_arvore_vermelho_preto(&raiz, newTree3);

  TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
}

void test_insercao_arvore_vermelha_preta_atualizando_caso_1()
{
  // Passo 1, inserindo a palavra ingles 2, portugues 2, unidade 1.
  ArvoreVermelhoPreto *newTree1;
  aloca_arvore_vermelho_preto(&newTree1);
  def_arvore_vermelho_preto(newTree1, "2", "2", "Unidade 1");

  inserir_arvore_vermelho_preto(&raiz, newTree1);

  // Passo 2, inserindo a palavra ingles 2, portugues 1, unidade 2.
  ArvoreVermelhoPreto *newTree2;
  InfoMain newInfo2;

  aloca_arvore_vermelho_preto(&newTree2);
  def_arvore_vermelho_preto(newTree2, "1", "2", "Unidade 2");

  int confirmacao = inserir_arvore_vermelho_preto(&raiz, newTree2);
  TEST_ASSERT_EQUAL_INT(1, confirmacao);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("Unidade 1", raiz->info.arv_binaria_palavra_ingles->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info.arv_binaria_palavra_ingles->esquerda->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("Unidade 2", raiz->info.arv_binaria_palavra_ingles->esquerda->nome_unidade);
}
