#include "Unity/unity.h"
#include "include/arvore_vermelho_preto.h"

ArvoreVermelhoPreto *raiz;

int prencher_automatico(int *valores, int qtd)
{
  int qtd_erros = 0;
  for (int i = 0; i < qtd; i++)
  {
    ArvoreVermelhoPreto *newTree = NULL;
    aloca_arvore_vermelho_preto(&newTree);
    char nome_unidade[20];
    char palavra_portugues[20];
    sprintf(nome_unidade, "Unidade %d", valores[i]);
    sprintf(palavra_portugues, "%d", valores[i]);
    def_arvore_vermelho_preto(newTree, palavra_portugues, palavra_portugues, nome_unidade);
    qtd_erros += !inserir_arvore_vermelho_preto(&raiz, newTree);
  }
  return qtd_erros;
}

void setUp(void)
{
  raiz = NULL;
}
void tearDown(void)
{
  free_arvore_vermelho_preto(&raiz);
}

void test_insercao_arvore_vermelha_preta_inserindo();
void test_insercao_arvore_vermelha_preta_inserindo_valor_unico();
void test_insercao_arvore_vermelha_preta_inserindo_caso_1(); // 1 -> 2 -> 3
void test_insercao_arvore_vermelha_preta_inserindo_caso_2(); // 3 -> 2 -> 1
void test_insercao_arvore_vermelha_preta_inserindo_caso_3(); // 2 -> 1 -> 3
void test_insercao_arvore_vermelha_preta_inserindo_caso_4(); // 3 -> 1 -> 2
void test_insercao_arvore_vermelha_preta_inserindo_caso_5(); // 1 -> 2 -> 3 -> 4 -> 5
void test_insercao_arvore_vermelha_preta_atualizando_caso_1();

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_insercao_arvore_vermelha_preta_inserindo);
  RUN_TEST(test_insercao_arvore_vermelha_preta_inserindo_valor_unico);
  RUN_TEST(test_insercao_arvore_vermelha_preta_inserindo_caso_1);
  RUN_TEST(test_insercao_arvore_vermelha_preta_inserindo_caso_2);
  RUN_TEST(test_insercao_arvore_vermelha_preta_inserindo_caso_3);
  RUN_TEST(test_insercao_arvore_vermelha_preta_inserindo_caso_4);
  RUN_TEST(test_insercao_arvore_vermelha_preta_atualizando_caso_1);
  return UNITY_END();
}

void test_insercao_arvore_vermelha_preta_inserindo()
{
  int valores_inserir[] = {1};
  prencher_automatico(valores_inserir, 1);

  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_NULL(raiz->esq);
  TEST_ASSERT_NULL(raiz->dir);
}

void test_insercao_arvore_vermelha_preta_inserindo_valor_unico()
{
  int valores_inserir[] = {1, 1};
  int qtd_erros = prencher_automatico(valores_inserir, 2);

  TEST_ASSERT_EQUAL_INT(1, qtd_erros);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("Unidade 1", raiz->info.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
}

void test_insercao_arvore_vermelha_preta_inserindo_caso_1()
{
  int valores_inserir_pt1[] = {1, 2};
  int qtd_erros = prencher_automatico(valores_inserir_pt1, 2);

  TEST_ASSERT_NOT_NULL(raiz->esq);
  TEST_ASSERT_EQUAL_INT(0, qtd_erros);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);

  int valores_inserir_pt2[] = {3};
  qtd_erros = prencher_automatico(valores_inserir_pt2, 1);

  TEST_ASSERT_EQUAL_INT(0, qtd_erros);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
}

void test_insercao_arvore_vermelha_preta_inserindo_caso_2()
{
  int valores_inserir_pt1[] = {3, 2};
  int qtd_erros = prencher_automatico(valores_inserir_pt1, 2);

  TEST_ASSERT_EQUAL_INT(0, qtd_erros);
  TEST_ASSERT_EQUAL_STRING("3", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", raiz->esq->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->esq->cor);

  int valores_inserir_pt2[] = {1};
  qtd_erros = prencher_automatico(valores_inserir_pt2, 1);

  TEST_ASSERT_EQUAL_INT(0, qtd_erros);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
}

void test_insercao_arvore_vermelha_preta_inserindo_caso_3()
{
  int valores_inserir_pt1[] = {2, 1};
  int qtd_erros = prencher_automatico(valores_inserir_pt1, 2);

  TEST_ASSERT_EQUAL_INT(0, qtd_erros);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);

  int valores_inserir_pt2[] = {3};
  qtd_erros = prencher_automatico(valores_inserir_pt2, 1);

  TEST_ASSERT_EQUAL_INT(0, qtd_erros);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
}

void test_insercao_arvore_vermelha_preta_inserindo_caso_4()
{
  int valores_inserir_pt1[] = {3, 1, 2};
  int qtd_erros = prencher_automatico(valores_inserir_pt1, 3);

  TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
}

void test_insercao_arvore_vermelha_preta_inserindo_caso_5()
{
  int valores_inserir_pt1[] = {1, 2, 3, 4, 5};
  int qtd_erros = prencher_automatico(valores_inserir_pt1, 5);

  TEST_ASSERT_EQUAL_STRING("4", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esq->esq->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", raiz->esq->dir->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("5", raiz->dir->info.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
  TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->esq->cor);
  TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->dir->cor);

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
  TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("Unidade 1", raiz->info.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info.arv_binaria_palavra_ingles->esquerda->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("Unidade 2", raiz->info.arv_binaria_palavra_ingles->esquerda->info.unidades->nome_unidade);
}
