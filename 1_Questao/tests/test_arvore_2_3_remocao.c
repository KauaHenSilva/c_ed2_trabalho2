#include "Unity/unity.h"
#include "include/arvore_2_3.h"

Arvore_2_3 *raiz;

void func_test_inserindo_valores_automatico(int *valores, int qtd)
{
  for (int i = 0; i < qtd; i++)
  {
    InfoMain newInfo;
    char nome_unidade[20];
    char palavra_portugues[20];
    char unidade[20];

    sprintf(nome_unidade, "%d", valores[i]);
    sprintf(palavra_portugues, "%d", valores[i]);
    sprintf(unidade, "%d", valores[i]);

    def_info_arvore_2_3(&newInfo, palavra_portugues, palavra_portugues, nome_unidade);
    inserir_arvore_2_3(&raiz, newInfo);
  }
}

void comp_info(InfoMain info, char *palavra_portugues, char *palavra_ingles, char *nome_unidade)
{
  TEST_ASSERT_EQUAL_STRING(palavra_portugues, info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING(palavra_ingles, info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING(nome_unidade, info.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
}

void comp_filho(Arvore_2_3 *raiz_atual, int tem_a_esquerda, int tem_o_centro, int tem_a_direita)
{
  if (tem_a_esquerda)
    TEST_ASSERT_NOT_NULL(raiz_atual->esquerda);
  else
    TEST_ASSERT_NULL(raiz_atual->esquerda);

  if (tem_o_centro)
    TEST_ASSERT_NOT_NULL(raiz_atual->centro);
  else
    TEST_ASSERT_NULL(raiz_atual->centro);

  if (tem_a_direita)
    TEST_ASSERT_NOT_NULL(raiz_atual->direita);
  else
    TEST_ASSERT_NULL(raiz_atual->direita);
}

void setUp(void)
{
  raiz = NULL;
}

void tearDown(void)
{
  free_arvore_2_3(raiz);
}

void test_remocao_2_3_caso_1(); // inc: 1 -> rem: 1
void test_remocao_2_3_caso_2(); // inc: 1, 2 -> rem: 1
void test_remocao_2_3_caso_3(); // inc: 1, 2 -> rem: 2
void test_remocao_2_3_caso_4(); // inc: 1, 2, 3 -> rem: 1
void test_remocao_2_3_caso_5(); // inc: 1, 3, 2, 5, 4 -> rem: 1
void test_remocao_2_3_caso_6(); // inc: 1, 3, 2, 5, 4 -> rem: 3
void test_remocao_2_3_caso_7(); // inc: 1, 3, 2, 5, 4 -> rem: 2
void test_remocao_2_3_caso_8(); // inc: 1, 3, 2, 5, 4 -> rem: 5

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_remocao_2_3_caso_1);
  RUN_TEST(test_remocao_2_3_caso_2);
  RUN_TEST(test_remocao_2_3_caso_3);
  RUN_TEST(test_remocao_2_3_caso_4);
  RUN_TEST(test_remocao_2_3_caso_5);
  RUN_TEST(test_remocao_2_3_caso_6);
  RUN_TEST(test_remocao_2_3_caso_7);
  RUN_TEST(test_remocao_2_3_caso_8);
  return UNITY_END();
}

void test_remocao_2_3_caso_1()
{
  int valores_adicinar[] = {1};
  func_test_inserindo_valores_automatico(valores_adicinar, 1);

  int resposta = arvore_2_3_remover(&raiz, "1");

  TEST_ASSERT_EQUAL_INT(1, resposta);
  TEST_ASSERT_NULL(raiz);
}

void test_remocao_2_3_caso_2()
{
  int valores_adicinar[] = {1, 2};
  func_test_inserindo_valores_automatico(valores_adicinar, 2);

  int resposta = arvore_2_3_remover(&raiz, "1");

  TEST_ASSERT_EQUAL_INT(1, resposta);
  TEST_ASSERT_EQUAL_INT(1, raiz->n_info);
  comp_info(raiz->info1, "2", "2", "2");
  comp_filho(raiz, 0, 0, 0);
}

void test_remocao_2_3_caso_3()
{
  int valores_adicinar[] = {1, 2};
  func_test_inserindo_valores_automatico(valores_adicinar, 2);

  int resposta = arvore_2_3_remover(&raiz, "2");

  TEST_ASSERT_EQUAL_INT(1, resposta);
  TEST_ASSERT_EQUAL_INT(1, raiz->n_info);
  comp_info(raiz->info1, "1", "1", "1");
  comp_filho(raiz, 0, 0, 0);
}

void test_remocao_2_3_caso_4()
{
  int valores_adicinar[] = {1, 2, 3};
  func_test_inserindo_valores_automatico(valores_adicinar, 3);
  int resposta = arvore_2_3_remover(&raiz, "1");

  TEST_ASSERT_EQUAL_INT(1, resposta);
  TEST_ASSERT_EQUAL_INT(2, raiz->n_info);
  comp_info(raiz->info1, "2", "2", "2");
  comp_info(raiz->info2, "3", "3", "3");
  comp_filho(raiz, 0, 0, 0);
}

void test_remocao_2_3_caso_5()
{
  int valores_adicionar[] = {1, 3, 2, 5, 4};
  func_test_inserindo_valores_automatico(valores_adicionar, 5);
  int resposta = arvore_2_3_remover(&raiz, "3");

  comp_info(raiz->info1, "2", "2", "2");
  TEST_ASSERT_EQUAL_INT(1, raiz->n_info);

  comp_info(raiz->esquerda->info1, "1", "1", "1");
  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->n_info);

  comp_info(raiz->centro->info1, "4", "4", "4");
  comp_info(raiz->centro->info2, "5", "5", "5");
  TEST_ASSERT_EQUAL_INT(2, raiz->centro->n_info);
}

void test_remocao_2_3_caso_6()
{
  int valores_adicionar[] = {1, 3, 2, 5, 4};
  func_test_inserindo_valores_automatico(valores_adicionar, 5);
  int resposta = arvore_2_3_remover(&raiz, "3");

  comp_info(raiz->info1, "2", "2", "2");
  TEST_ASSERT_EQUAL_INT(1, raiz->n_info);

  comp_info(raiz->esquerda->info1, "1", "1", "1");
  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->n_info);

  comp_info(raiz->centro->info1, "4", "4", "4");
  comp_info(raiz->centro->info2, "5", "5", "5");
  TEST_ASSERT_EQUAL_INT(2, raiz->centro->n_info);
}

void test_remocao_2_3_caso_7()
{
  int valores_adicionar[] = {1, 3, 2, 5, 4};
  func_test_inserindo_valores_automatico(valores_adicionar, 5);
  int resposta = arvore_2_3_remover(&raiz, "2");

  comp_info(raiz->info1, "3", "3", "3");
  TEST_ASSERT_EQUAL_INT(1, raiz->n_info);

  comp_info(raiz->esquerda->info1, "1", "1", "1");
  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->n_info);

  comp_info(raiz->centro->info1, "4", "4", "4");
  comp_info(raiz->centro->info2, "5", "5", "5");
  TEST_ASSERT_EQUAL_INT(2, raiz->centro->n_info);
}

void test_remocao_2_3_caso_8()
{
  int valores_adicionar[] = {1, 3, 2, 5, 4};
  func_test_inserindo_valores_automatico(valores_adicionar, 5);
  int resposta = arvore_2_3_remover(&raiz, "5");

  comp_info(raiz->info1, "2", "2", "2");
  TEST_ASSERT_EQUAL_INT(1, raiz->n_info);

  comp_info(raiz->esquerda->info1, "1", "1", "1");
  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->n_info);

  comp_info(raiz->centro->info1, "3", "3", "3");
  comp_info(raiz->centro->info2, "4", "4", "4");
  TEST_ASSERT_EQUAL_INT(2, raiz->centro->n_info);
}