#include "Unity/unity.h"
#include "include/arvore_vermelho_preto.h"

void setUp(void) {}
void tearDown(void) {}

void test_aloca_arvore_vermelha_preta();
void test_insercao_arvore_vermelha_preta_inserindo();
void test_insercao_arvore_vermelha_preta_valor_unico();
void test_insercao_arvore_vermelha_preta_caso_1();
void test_insercao_arvore_vermelha_preta_caso_2();
void test_insercao_arvore_vermelha_preta_caso_3();

int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_aloca_arvore_vermelha_preta);
  RUN_TEST(test_insercao_arvore_vermelha_preta_inserindo);
  RUN_TEST(test_insercao_arvore_vermelha_preta_valor_unico);
  RUN_TEST(test_insercao_arvore_vermelha_preta_caso_1);
  RUN_TEST(test_insercao_arvore_vermelha_preta_caso_2);
  RUN_TEST(test_insercao_arvore_vermelha_preta_caso_3);
  return UNITY_END();
}

void test_aloca_arvore_vermelha_preta()
{
  ArvoreVermelhoPreto *raiz = NULL;
  InfoMain info;
  alocar_info_main(&info, "Bus", "Onibus", "Unidade");
  aloca_arvore_vermelho_preto(&raiz, &info);

  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Bus", raiz->info.palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("Onibus", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("Unidade", raiz->info.nome_unidade);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->cor);
  TEST_ASSERT_NULL(raiz->esq);
  TEST_ASSERT_NULL(raiz->dir);
}

void test_insercao_arvore_vermelha_preta_inserindo()
{
  ArvoreVermelhoPreto *raiz;
  raiz = NULL;

  ArvoreVermelhoPreto *newTree;
  InfoMain newInfo;
  alocar_info_main(&newInfo, "Bus", "Onibus", "Unidade");
  aloca_arvore_vermelho_preto(&newTree, &newInfo);

  int resultado = inserir_arvore_vermelho_preto(&raiz, newTree);
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Bus", raiz->info.palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("Onibus", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("Unidade", raiz->info.nome_unidade);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_NULL(raiz->esq);
  TEST_ASSERT_NULL(raiz->dir);
}

void test_insercao_arvore_vermelha_preta_valor_unico()
{
  ArvoreVermelhoPreto *raiz = NULL;
  ArvoreVermelhoPreto *newTree;

  InfoMain newInfo;
  alocar_info_main(&newInfo, "Bus", "Onibus", "Unidade");
  aloca_arvore_vermelho_preto(&newTree, &newInfo);

  int resultado = inserir_arvore_vermelho_preto(&raiz, newTree);
  TEST_ASSERT_EQUAL_INT(1, resultado);

  resultado = inserir_arvore_vermelho_preto(&raiz, newTree);
  TEST_ASSERT_EQUAL_INT(0, resultado);
}

void test_insercao_arvore_vermelha_preta_caso_1()
{
  ArvoreVermelhoPreto *raiz = NULL;

  // Passo 1
  ArvoreVermelhoPreto *newTree1;
  InfoMain newInfo1;

  alocar_info_main(&newInfo1, "1", "1", "Unidade");
  aloca_arvore_vermelho_preto(&newTree1, &newInfo1);
  inserir_arvore_vermelho_preto(&raiz, newTree1);

  // Passo 2
  ArvoreVermelhoPreto *newTree2;
  InfoMain newInfo2;

  alocar_info_main(&newInfo2, "2", "2", "Unidade");
  aloca_arvore_vermelho_preto(&newTree2, &newInfo2);

  int resultado = inserir_arvore_vermelho_preto(&raiz, newTree2);
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_NOT_NULL(raiz->esq);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);

  // Passo 3
  ArvoreVermelhoPreto *newTree3;
  InfoMain newInfo3;

  alocar_info_main(&newInfo3, "3", "3", "Unidade");
  aloca_arvore_vermelho_preto(&newTree3, &newInfo3);

  resultado = inserir_arvore_vermelho_preto(&raiz, newTree3);
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_NULL(raiz->dir);
  TEST_ASSERT_EQUAL_STRING("3", raiz->info.palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", raiz->esq->info.palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->esq->info.palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
}

void test_insercao_arvore_vermelha_preta_caso_2()
{
  ArvoreVermelhoPreto *raiz = NULL;

  // Passo 1
  ArvoreVermelhoPreto *newTree1;
  InfoMain newInfo1;

  alocar_info_main(&newInfo1, "3", "3", "Unidade");
  aloca_arvore_vermelho_preto(&newTree1, &newInfo1);
  inserir_arvore_vermelho_preto(&raiz, newTree1);

  // Passo 2
  ArvoreVermelhoPreto *newTree2;
  InfoMain newInfo2;

  alocar_info_main(&newInfo2, "2", "2", "Unidade");
  aloca_arvore_vermelho_preto(&newTree2, &newInfo2);
  int resultado = inserir_arvore_vermelho_preto(&raiz, newTree2);

  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_EQUAL_STRING("3", raiz->info.palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", raiz->esq->info.palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);

  // Passo 3
  ArvoreVermelhoPreto *newTree3;
  InfoMain newInfo3;

  alocar_info_main(&newInfo3, "1", "1", "Unidade");
  aloca_arvore_vermelho_preto(&newTree3, &newInfo3);
  resultado = inserir_arvore_vermelho_preto(&raiz, newTree3);

  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
}

void test_insercao_arvore_vermelha_preta_caso_3()
{
  ArvoreVermelhoPreto *raiz = NULL;

  // Passo 1, inserindo o 2.
  ArvoreVermelhoPreto *newTree1;
  InfoMain newInfo1;

  alocar_info_main(&newInfo1, "2", "2", "Unidade");
  aloca_arvore_vermelho_preto(&newTree1, &newInfo1);
  inserir_arvore_vermelho_preto(&raiz, newTree1);

  // Passo 2, inserindo o 1.
  ArvoreVermelhoPreto *newTree2;
  InfoMain newInfo2;

  alocar_info_main(&newInfo2, "1", "1", "Unidade");
  aloca_arvore_vermelho_preto(&newTree2, &newInfo2);
  int confirmacao = inserir_arvore_vermelho_preto(&raiz, newTree2);

  TEST_ASSERT_EQUAL_INT(1, confirmacao);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);

  // Passo 3, inserindo o 3.
  ArvoreVermelhoPreto *newTree3;
  InfoMain newInfo3;

  alocar_info_main(&newInfo3, "3", "3", "Unidade");
  aloca_arvore_vermelho_preto(&newTree3, &newInfo3);
  confirmacao = inserir_arvore_vermelho_preto(&raiz, newTree3);

  TEST_ASSERT_EQUAL_INT(1, confirmacao);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
}
