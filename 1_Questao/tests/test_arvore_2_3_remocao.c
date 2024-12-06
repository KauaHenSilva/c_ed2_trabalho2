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

// void test_remocao_2_3_caso_1(); // inc: 1 -> rem: 1
// void test_remocao_2_3_caso_2(); // inc: 1, 2 -> rem: 1
// void test_remocao_2_3_caso_3(); // inc: 1, 2 -> rem: 2
// void test_remocao_2_3_caso_4(); // inc: 1, 2, 3 -> rem: 1
// void test_remocao_2_3_caso_5(); // inc: 1, 3, 2, 5, 4 -> rem: 1

int main()
{
  UNITY_BEGIN();
  // RUN_TEST(test_remocao_2_3_caso_1);
  // RUN_TEST(test_remocao_2_3_caso_2);
  // RUN_TEST(test_remocao_2_3_caso_3);
  // RUN_TEST(test_remocao_2_3_caso_4);
  // RUN_TEST(test_remocao_2_3_caso_5);
  return UNITY_END();
}

// void test_remocao_2_3_caso_1()
// {
//   int valores_adicinar[] = {1};
//   func_test_inserindo_valores_automatico(valores_adicinar, 1);

//   Arvore_2_3 *maior;
//   int resposta = remover_arvore_2_3(&raiz, "1", NULL, &raiz, &maior);

//   TEST_ASSERT_EQUAL_INT(1, resposta);
//   TEST_ASSERT_NULL(raiz);
// }

// void test_remocao_2_3_caso_2()
// {
//   int valores_adicinar[] = {1, 2};
//   func_test_inserindo_valores_automatico(valores_adicinar, 2);

//   Arvore_2_3 *maior;
//   int resposta = remover_arvore_2_3(&raiz, "1", NULL, &raiz, &maior);

//   TEST_ASSERT_EQUAL_INT(1, resposta);
//   TEST_ASSERT_EQUAL_INT(1, raiz->n_info);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->info1.palavra_portugues);
// }

// void test_remocao_2_3_caso_3()
// {
//   int valores_adicinar[] = {1, 2};
//   func_test_inserindo_valores_automatico(valores_adicinar, 2);

//   Arvore_2_3 *maior;
//   int resposta = remover_arvore_2_3(&raiz, "2", NULL, &raiz, &maior);

//   TEST_ASSERT_EQUAL_INT(1, resposta);
//   TEST_ASSERT_EQUAL_INT(1, raiz->n_info);
//   TEST_ASSERT_EQUAL_STRING("1", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("1", raiz->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
//   TEST_ASSERT_EQUAL_STRING("1", raiz->info1.palavra_portugues);
// }

// void test_remocao_2_3_caso_4()
// {
//   int valores_adicinar[] = {1, 2, 3};
//   func_test_inserindo_valores_automatico(valores_adicinar, 3);
//   int resposta = main_remover_arvore_2_3(&raiz, "1");

//   TEST_ASSERT_EQUAL_INT(1, resposta);
//   TEST_ASSERT_EQUAL_INT(2, raiz->n_info);

//   TEST_ASSERT_EQUAL_STRING("2", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("3", raiz->info2.arv_binaria_palavra_ingles->info.palavra_ingles);
// }

// void test_remocao_2_3_caso_5()
// {
//   int valores_adicionar[] = {1, 3, 2, 5, 4};
//   func_test_inserindo_valores_automatico(valores_adicionar, 5);
//   int resposta = main_remover_arvore_2_3(&raiz, "3");

//   TEST_ASSERT_EQUAL_STRING("2", raiz->info1.palavra_portugues);
//   TEST_ASSERT_EQUAL_INT(1, raiz->n_info);

//   TEST_ASSERT_EQUAL_STRING("1", raiz->esquerda->info1.palavra_portugues);
//   TEST_ASSERT_EQUAL_INT(1, raiz->n_info);

//   TEST_ASSERT_EQUAL_STRING("4", raiz->direita->info1.palavra_portugues);
//   TEST_ASSERT_EQUAL_STRING("5", raiz->direita->info2.palavra_portugues);
//   TEST_ASSERT_EQUAL_INT(2, raiz->n_info);
// }