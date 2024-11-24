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

    InfoMain promove;
    Arvore_2_3 *pai = NULL;
    Arvore_2_3 *new_node = NULL;

    def_info_arvore_2_3(&newInfo, palavra_portugues, palavra_portugues, nome_unidade);
    inserir_arvore_2_3(&raiz, newInfo, &promove, &pai, &new_node);
  }
}

void setUp(void)
{
  raiz = NULL;
}

void tearDown(void)
{
  free_arvore_2_3(raiz);
}

void test_insercao_arvore_2_3_inserindo();
void test_insercao_arvore_2_3_inserindo_valor_unico();
void test_insercao_arvore_2_3_inserindo_caso_1(); // inc: 1, 2
void test_insercao_arvore_2_3_inserindo_caso_2(); // inc: 2, 1
void test_insercao_arvore_2_3_inserindo_caso_3(); // inc: 1, 2, 3
void test_insercao_arvore_2_3_inserindo_caso_4(); // inc: 2, 3, 4, 1
void test_insercao_arvore_2_3_inserindo_caso_5(); // inc: 1, 2, 3, 4
void test_insercao_arvore_2_3_inserindo_caso_6(); // inc: 1, 2, 3, 4, 5
void test_insercao_arvore_2_3_inserindo_caso_7(); // inc: 1, 2, 3, 4, 5, 6, 7

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_insercao_arvore_2_3_inserindo);
  RUN_TEST(test_insercao_arvore_2_3_inserindo_valor_unico);
  RUN_TEST(test_insercao_arvore_2_3_inserindo_caso_1);
  RUN_TEST(test_insercao_arvore_2_3_inserindo_caso_2);
  RUN_TEST(test_insercao_arvore_2_3_inserindo_caso_3);
  RUN_TEST(test_insercao_arvore_2_3_inserindo_caso_4);
  RUN_TEST(test_insercao_arvore_2_3_inserindo_caso_5);
  RUN_TEST(test_insercao_arvore_2_3_inserindo_caso_6);
  RUN_TEST(test_insercao_arvore_2_3_inserindo_caso_7);
  return UNITY_END();
}

void test_insercao_arvore_2_3_inserindo()
{
  InfoMain newInfo;
  def_info_arvore_2_3(&newInfo, "Bus", "Onibus", "Unidade 1");

  Arvore_2_3 *new_node = NULL;
  Arvore_2_3 *pai = NULL;
  InfoMain promove;

  inserir_arvore_2_3(&raiz, newInfo, &promove, &pai, &new_node);

  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Bus", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("Onibus", raiz->info1.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(1, raiz->n_info);
  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->centro);
  TEST_ASSERT_NULL(raiz->direita);
}

void test_insercao_arvore_2_3_inserindo_valor_unico()
{
  InfoMain newInfo;
  def_info_arvore_2_3(&newInfo, "Bus", "Onibus", "Unidade 1");

  Arvore_2_3 *new_node = NULL;
  Arvore_2_3 *pai = NULL;
  InfoMain promove;

  inserir_arvore_2_3(&raiz, newInfo, &promove, &pai, &new_node);
  int resposta = inserir_arvore_2_3(&raiz, newInfo, &promove, &pai, &new_node);

  TEST_ASSERT_EQUAL_INT(0, resposta);
  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Bus", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("Onibus", raiz->info1.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("Unidade 1", raiz->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_INT(1, raiz->n_info);
  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->centro);
  TEST_ASSERT_NULL(raiz->direita);
}

void test_insercao_arvore_2_3_inserindo_caso_1()
{
  int valores_adicinar[] = {1, 2};
  func_test_inserindo_valores_automatico(valores_adicinar, 2);

  TEST_ASSERT_EQUAL_INT(2, raiz->n_info);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info2.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info2.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info2.palavra_portugues);

  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->centro);
  TEST_ASSERT_NULL(raiz->direita);
}

void test_insercao_arvore_2_3_inserindo_caso_2()
{
  int valores_adicinar[] = {2, 1};
  func_test_inserindo_valores_automatico(valores_adicinar, 2);

  TEST_ASSERT_EQUAL_INT(2, raiz->n_info);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info2.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info2.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info2.palavra_portugues);

  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->centro);
  TEST_ASSERT_NULL(raiz->direita);
}

void test_insercao_arvore_2_3_inserindo_caso_3()
{
  int valores_adicinar[] = {1, 2, 3};
  func_test_inserindo_valores_automatico(valores_adicinar, 3);

  TEST_ASSERT_EQUAL_INT(1, raiz->n_info);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info1.palavra_portugues);
  TEST_ASSERT_NOT_NULL(raiz->esquerda);
  TEST_ASSERT_NOT_NULL(raiz->centro);
  TEST_ASSERT_NULL(raiz->direita);

  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->n_info);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esquerda->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esquerda->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esquerda->info1.palavra_portugues);
  TEST_ASSERT_NULL(raiz->esquerda->esquerda);
  TEST_ASSERT_NULL(raiz->esquerda->centro);
  TEST_ASSERT_NULL(raiz->esquerda->direita);

  TEST_ASSERT_EQUAL_INT(1, raiz->centro->n_info);
  TEST_ASSERT_EQUAL_STRING("3", raiz->centro->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->centro->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("3", raiz->centro->info1.palavra_portugues);
  TEST_ASSERT_NULL(raiz->centro->esquerda);
  TEST_ASSERT_NULL(raiz->centro->centro);
  TEST_ASSERT_NULL(raiz->centro->direita);
}

void test_insercao_arvore_2_3_inserindo_caso_4()
{
  int valores_adicinar[] = {2, 3, 4, 1};
  func_test_inserindo_valores_automatico(valores_adicinar, 4);

  TEST_ASSERT_EQUAL_INT(1, raiz->n_info);
  TEST_ASSERT_EQUAL_STRING("3", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("3", raiz->info1.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(2, raiz->esquerda->n_info);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esquerda->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esquerda->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esquerda->info1.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", raiz->esquerda->info2.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->esquerda->info2.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("2", raiz->esquerda->info2.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(1, raiz->centro->n_info);
  TEST_ASSERT_EQUAL_STRING("4", raiz->centro->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("4", raiz->centro->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("4", raiz->centro->info1.palavra_portugues);
}

void test_insercao_arvore_2_3_inserindo_caso_5()
{
  int valores_adicinar[] = {1, 2, 3, 4};
  func_test_inserindo_valores_automatico(valores_adicinar, 4);

  TEST_ASSERT_EQUAL_INT(1, raiz->n_info);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info1.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->n_info);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esquerda->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esquerda->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esquerda->info1.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(2, raiz->centro->n_info);
  TEST_ASSERT_EQUAL_STRING("3", raiz->centro->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->centro->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("3", raiz->centro->info1.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("4", raiz->centro->info2.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("4", raiz->centro->info2.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("4", raiz->centro->info2.palavra_portugues);
}

void test_insercao_arvore_2_3_inserindo_caso_6()
{
  int valores_adicinar[] = {1, 2, 3, 4, 5};
  func_test_inserindo_valores_automatico(valores_adicinar, 5);

  TEST_ASSERT_EQUAL_INT(2, raiz->n_info);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info1.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("4", raiz->info2.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("4", raiz->info2.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("4", raiz->info2.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->n_info);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esquerda->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esquerda->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esquerda->info1.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(1, raiz->centro->n_info);
  TEST_ASSERT_EQUAL_STRING("3", raiz->centro->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", raiz->centro->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("3", raiz->centro->info1.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(1, raiz->direita->n_info);
  TEST_ASSERT_EQUAL_STRING("5", raiz->direita->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("5", raiz->direita->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("5", raiz->direita->info1.palavra_portugues);
}

void test_insercao_arvore_2_3_inserindo_caso_7()
{
  int valores_adicinar[] = {1, 2, 3, 4, 5, 6, 7};
  func_test_inserindo_valores_automatico(valores_adicinar, 7);

  TEST_ASSERT_EQUAL_INT(1, raiz->n_info);
  TEST_ASSERT_EQUAL_STRING("4", raiz->info1.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->n_info);
  TEST_ASSERT_EQUAL_STRING("2", raiz->esquerda->info1.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(1, raiz->centro->n_info);
  TEST_ASSERT_EQUAL_STRING("6", raiz->centro->info1.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->esquerda->n_info);
  TEST_ASSERT_EQUAL_STRING("1", raiz->esquerda->esquerda->info1.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->centro->n_info);
  TEST_ASSERT_EQUAL_STRING("3", raiz->esquerda->centro->info1.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(1, raiz->centro->esquerda->n_info);
  TEST_ASSERT_EQUAL_STRING("5", raiz->centro->esquerda->info1.palavra_portugues);

  TEST_ASSERT_EQUAL_INT(1, raiz->centro->centro->n_info);
  TEST_ASSERT_EQUAL_STRING("7", raiz->centro->centro->info1.palavra_portugues);
}
