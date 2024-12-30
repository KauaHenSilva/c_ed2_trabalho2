#include "Unity/unity.h"
#include "include/arvore_2_3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  if (raiz_atual->n_info == 2)
  {
    if (tem_a_direita)
      TEST_ASSERT_NOT_NULL(raiz_atual->direita);
    else
      TEST_ASSERT_NULL(raiz_atual->direita);
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

// Testes de remoção Pt.1 (Caso base)
void test_remocao_2_3_caso_1(); // inc: 1 -> rem: 1
void test_remocao_2_3_caso_2(); // inc: 1, 2 -> rem: 1
void test_remocao_2_3_caso_3(); // inc: 1, 2 -> rem: 2
void test_remocao_2_3_caso_4(); // inc: 1, 2, 3 -> rem: 1
void test_remocao_2_3_caso_5(); // inc: 1, 3, 2, 5, 4 -> rem: 1
void test_remocao_2_3_caso_6(); // inc: 1, 3, 2, 5, 4 -> rem: 3
void test_remocao_2_3_caso_7(); // inc: 1, 3, 2, 5, 4 -> rem: 2
void test_remocao_2_3_caso_8(); // inc: 1, 3, 2, 5, 4 -> rem: 5
void test_remocao_2_3_caso_9(); // inc: 1, 3, 2, 5, 4 -> rem: 4

// Testes de remoção Pt.2 (Caso mais complexos e específicos)
void test_remocao_2_3_caso_10(); // inc: 3, 6, 1, 2, 4, 5, 7, 8 -> rem: 6
void test_remocao_2_3_caso_11(); // inc: 3, 6, 1, 2, 4, 5, 7 -> rem: 6
void test_remocao_2_3_caso_12(); // inc: 3, 6, 1, 2, 4, 7 -> rem: 6
void test_remocao_2_3_caso_13(); // inc: 3, 6, 1, 2, 4, 5, 7, 8 -> rem: 3
void test_remocao_2_3_caso_14(); // inc: 3, 6, 1, 4, 5, 7, 8 -> rem: 3
void test_remocao_2_3_caso_15(); // inc: 3, 6, 1, 4, 5, 7 -> rem: 3
void test_remocao_2_3_caso_16(); // inc: 3, 6, 1, 4, 5, 7 -> rem: 6
void test_remocao_2_3_caso_17(); // inc: 3, 6, 4, 2, 5, 7, 8 -> rem: 6
void test_remocao_2_3_caso_18(); // inc: 3, 6, 4, 2, 5, 7, 8 -> rem: 2
void test_remocao_2_3_caso_19(); // inc: 3, 6, 4, 2, 5, 7, 8 -> rem: 5

// Testes de remoção Pt.3 (Grandes remoções)
void test_remocao_2_3_caso_20(); // inc: varios -> rem: varios
void test_remocao_2_3_caso_21(); // inc: varios -> rem: varios
void test_remocao_2_3_caso_22(); // inc: varios -> rem: varios
void test_remocao_2_3_caso_23(); // inc: varios -> rem: varios

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
  RUN_TEST(test_remocao_2_3_caso_9);
  RUN_TEST(test_remocao_2_3_caso_10);
  RUN_TEST(test_remocao_2_3_caso_11);
  RUN_TEST(test_remocao_2_3_caso_12);
  RUN_TEST(test_remocao_2_3_caso_13);
  RUN_TEST(test_remocao_2_3_caso_14);
  RUN_TEST(test_remocao_2_3_caso_15);
  RUN_TEST(test_remocao_2_3_caso_16);
  RUN_TEST(test_remocao_2_3_caso_17);
  RUN_TEST(test_remocao_2_3_caso_18);
  RUN_TEST(test_remocao_2_3_caso_19);
  RUN_TEST(test_remocao_2_3_caso_20);
  RUN_TEST(test_remocao_2_3_caso_21);
  RUN_TEST(test_remocao_2_3_caso_22);
  RUN_TEST(test_remocao_2_3_caso_23);
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

void test_remocao_2_3_caso_9()
{
  int valores_adicionar[] = {1, 3, 2, 5, 4};
  func_test_inserindo_valores_automatico(valores_adicionar, 5);
  int resposta = arvore_2_3_remover(&raiz, "4");

  comp_info(raiz->info1, "2", "2", "2");
  TEST_ASSERT_EQUAL_INT(1, raiz->n_info);

  comp_info(raiz->esquerda->info1, "1", "1", "1");
  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->n_info);

  comp_info(raiz->centro->info1, "3", "3", "3");
  comp_info(raiz->centro->info2, "5", "5", "5");
  TEST_ASSERT_EQUAL_INT(2, raiz->centro->n_info);
}

void test_remocao_2_3_caso_10()
{
  int valores_adicionar[] = {3, 6, 1, 2, 4, 5, 7, 8};
  func_test_inserindo_valores_automatico(valores_adicionar, 8);
  int resposta = arvore_2_3_remover(&raiz, "6");

  TEST_ASSERT_EQUAL_INT(1, resposta);
  comp_info(raiz->info1, "3", "3", "3");
  comp_info(raiz->info2, "5", "5", "5");
  comp_filho(raiz, 1, 1, 1);
  TEST_ASSERT_EQUAL_INT(2, raiz->n_info);

  comp_info(raiz->esquerda->info1, "1", "1", "1");
  comp_info(raiz->esquerda->info2, "2", "2", "2");
  comp_filho(raiz->esquerda, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(2, raiz->esquerda->n_info);

  comp_info(raiz->centro->info1, "4", "4", "4");
  comp_filho(raiz->centro, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(1, raiz->centro->n_info);

  comp_info(raiz->direita->info1, "7", "7", "7");
  comp_info(raiz->direita->info2, "8", "8", "8");
  comp_filho(raiz->direita, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(2, raiz->direita->n_info);
}

void test_remocao_2_3_caso_11()
{
  int valores_adicionar[] = {3, 6, 1, 2, 4, 5, 7};
  func_test_inserindo_valores_automatico(valores_adicionar, 7);
  int resposta = arvore_2_3_remover(&raiz, "6");

  TEST_ASSERT_EQUAL_INT(1, resposta);
  comp_info(raiz->info1, "3", "3", "3");
  comp_info(raiz->info2, "5", "5", "5");
  comp_filho(raiz, 1, 1, 1);
  TEST_ASSERT_EQUAL_INT(2, raiz->n_info);

  comp_info(raiz->esquerda->info1, "1", "1", "1");
  comp_info(raiz->esquerda->info2, "2", "2", "2");
  comp_filho(raiz->esquerda, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(2, raiz->esquerda->n_info);

  comp_info(raiz->centro->info1, "4", "4", "4");
  comp_filho(raiz->centro, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(1, raiz->centro->n_info);

  comp_info(raiz->direita->info1, "7", "7", "7");
  comp_filho(raiz->direita, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(1, raiz->direita->n_info);
}

void test_remocao_2_3_caso_12()
{
  int valores_adicionar[] = {3, 6, 1, 2, 4, 7};
  func_test_inserindo_valores_automatico(valores_adicionar, 6);
  int resposta = arvore_2_3_remover(&raiz, "6");

  TEST_ASSERT_EQUAL_INT(1, resposta);
  comp_info(raiz->info1, "3", "3", "3");
  comp_filho(raiz, 1, 1, 0);
  TEST_ASSERT_EQUAL_INT(1, raiz->n_info);

  comp_info(raiz->esquerda->info1, "1", "1", "1");
  comp_info(raiz->esquerda->info2, "2", "2", "2");
  comp_filho(raiz->esquerda, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(2, raiz->esquerda->n_info);

  comp_info(raiz->centro->info1, "4", "4", "4");
  comp_info(raiz->centro->info2, "7", "7", "7");
  comp_filho(raiz->centro, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(2, raiz->centro->n_info);
}

void  test_remocao_2_3_caso_13()
{
  int valores_adicionar[] = {3, 6, 1, 2, 4, 5, 7, 8};
  func_test_inserindo_valores_automatico(valores_adicionar, 8);
  int resposta = arvore_2_3_remover(&raiz, "3");

  TEST_ASSERT_EQUAL_INT(1, resposta);
  comp_info(raiz->info1, "5", "5", "5");
  comp_filho(raiz, 1, 1, -1);
  TEST_ASSERT_EQUAL_INT(1, raiz->n_info);

  comp_info(raiz->esquerda->info1, "2", "2", "2");
  comp_filho(raiz->esquerda, 1, 1, -1);
  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->n_info);

  comp_info(raiz->esquerda->esquerda->info1, "1", "1", "1");
  comp_filho(raiz->esquerda->esquerda, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->esquerda->n_info);

  comp_info(raiz->esquerda->centro->info1, "4", "4", "4");
  comp_filho(raiz->esquerda->centro, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->centro->n_info);


  comp_info(raiz->centro->info1, "7", "7", "7");
  comp_filho(raiz->centro, 1, 1, -1);
  TEST_ASSERT_EQUAL_INT(1, raiz->centro->n_info);

  comp_info(raiz->centro->esquerda->info1, "6", "6", "6");
  comp_filho(raiz->centro->esquerda, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(1, raiz->centro->esquerda->n_info);

  comp_info(raiz->centro->centro->info1, "8", "8", "8");
  comp_filho(raiz->centro->centro, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(1, raiz->centro->centro->n_info);
}

void test_remocao_2_3_caso_14()
{
  int valores_adicionar[] = {3, 6, 1, 4, 5, 7, 8};
  func_test_inserindo_valores_automatico(valores_adicionar, 7);
  int resposta = arvore_2_3_remover(&raiz, "3");

  TEST_ASSERT_EQUAL_INT(1, resposta);
  comp_info(raiz->info1, "4", "4", "4");
  comp_info(raiz->info2, "6", "6", "6");
  comp_filho(raiz, 1, 1, 1);
  TEST_ASSERT_EQUAL_INT(2, raiz->n_info);

  comp_info(raiz->esquerda->info1, "1", "1", "1");
  comp_filho(raiz->esquerda, 0, 0, -1);
  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->n_info);

  comp_info(raiz->centro->info1, "5", "5", "5");
  comp_filho(raiz->centro, 0, 0, -1);
  TEST_ASSERT_EQUAL_INT(1, raiz->centro->n_info);

  comp_info(raiz->direita->info1, "7", "7", "7");
  comp_info(raiz->direita->info2, "8", "8", "8");
  comp_filho(raiz->direita, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(2, raiz->direita->n_info);
}

void test_remocao_2_3_caso_15()
{
  int valores_adicionar[] = {3, 6, 1, 4, 5, 7};
  func_test_inserindo_valores_automatico(valores_adicionar, 6);
  int resposta = arvore_2_3_remover(&raiz, "3");

  TEST_ASSERT_EQUAL_INT(1, resposta);
  comp_info(raiz->info1, "4", "4", "4");
  comp_info(raiz->info2, "6", "6", "6");
  comp_filho(raiz, 1, 1, 1);
  TEST_ASSERT_EQUAL_INT(2, raiz->n_info);

  comp_info(raiz->esquerda->info1, "1", "1", "1");
  comp_filho(raiz->esquerda, 0, 0, -1);
  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->n_info);

  comp_info(raiz->centro->info1, "5", "5", "5");
  comp_filho(raiz->centro, 0, 0, -1);
  TEST_ASSERT_EQUAL_INT(1, raiz->centro->n_info);

  comp_info(raiz->direita->info1, "7", "7", "7");
  comp_filho(raiz->direita, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(1, raiz->direita->n_info);
}

void test_remocao_2_3_caso_16()
{
  int valores_adicionar[] = {3, 6, 1, 4, 5, 7};
  func_test_inserindo_valores_automatico(valores_adicionar, 6);
  int resposta = arvore_2_3_remover(&raiz, "6");

  TEST_ASSERT_EQUAL_INT(1, resposta);
  comp_info(raiz->info1, "3", "3", "3");
  comp_info(raiz->info2, "5", "5", "5");
  comp_filho(raiz, 1, 1, 1);
  TEST_ASSERT_EQUAL_INT(2, raiz->n_info);

  comp_info(raiz->esquerda->info1, "1", "1", "1");
  comp_filho(raiz->esquerda, 0, 0, -1);
  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->n_info);

  comp_info(raiz->centro->info1, "4", "4", "4");
  comp_filho(raiz->centro, 0, 0, -1);
  TEST_ASSERT_EQUAL_INT(1, raiz->centro->n_info);

  comp_info(raiz->direita->info1, "7", "7", "7");
  comp_filho(raiz->direita, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(1, raiz->direita->n_info);
}

void test_remocao_2_3_caso_17()
{
  int valores_adicionar[] = {3, 6, 4, 2, 5, 7, 8};
  func_test_inserindo_valores_automatico(valores_adicionar, 7);
  int resposta = arvore_2_3_remover(&raiz, "6");

  TEST_ASSERT_EQUAL_INT(1, resposta);
  comp_info(raiz->info1, "4", "4", "4");
  comp_info(raiz->info2, "7", "7", "7");
  comp_filho(raiz, 1, 1, 1);
  TEST_ASSERT_EQUAL_INT(2, raiz->n_info);

  comp_info(raiz->esquerda->info1, "2", "2", "2");
  comp_info(raiz->esquerda->info2, "3", "3", "3");
  comp_filho(raiz->esquerda, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(2, raiz->esquerda->n_info);

  comp_info(raiz->centro->info1, "5", "5", "5");
  comp_filho(raiz->centro, 0, 0, -1);
  TEST_ASSERT_EQUAL_INT(1, raiz->centro->n_info);

  comp_info(raiz->direita->info1, "8", "8", "8");
  comp_filho(raiz->direita, 0, 0, -1);
  TEST_ASSERT_EQUAL_INT(1, raiz->direita->n_info);


}

void test_remocao_2_3_caso_18()
{
  int valores_adicionar[] = {3, 6, 4, 2, 5, 7, 8};
  func_test_inserindo_valores_automatico(valores_adicionar, 7);
  int resposta = arvore_2_3_remover(&raiz, "2");

  TEST_ASSERT_EQUAL_INT(1, resposta);
  comp_info(raiz->info1, "4", "4", "4");
  comp_info(raiz->info2, "6", "6", "6");
  comp_filho(raiz, 1, 1, 1);
  TEST_ASSERT_EQUAL_INT(2, raiz->n_info);

  comp_info(raiz->esquerda->info1, "3", "3", "3");
  comp_filho(raiz->esquerda, 0, 0, -1);
  TEST_ASSERT_EQUAL_INT(1, raiz->esquerda->n_info);

  comp_info(raiz->centro->info1, "5", "5", "5");
  comp_filho(raiz->centro, 0, 0, -1);
  TEST_ASSERT_EQUAL_INT(1, raiz->centro->n_info);

  comp_info(raiz->direita->info1, "7", "7", "7");
  comp_info(raiz->direita->info2, "8", "8", "8");
  comp_filho(raiz->direita, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(2, raiz->direita->n_info);
}

void test_remocao_2_3_caso_19()
{
  int valores_adicionar[] = {3, 6, 4, 2, 5, 7, 8};
  func_test_inserindo_valores_automatico(valores_adicionar, 7);
  int resposta = arvore_2_3_remover(&raiz, "5");

  TEST_ASSERT_EQUAL_INT(1, resposta);
  comp_info(raiz->info1, "4", "4", "4");
  comp_info(raiz->info2, "7", "7", "7");
  comp_filho(raiz, 1, 1, 1);
  TEST_ASSERT_EQUAL_INT(2, raiz->n_info);

  comp_info(raiz->esquerda->info1, "2", "2", "2");
  comp_info(raiz->esquerda->info2, "3", "3", "3");
  comp_filho(raiz->esquerda, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(2, raiz->esquerda->n_info);

  comp_info(raiz->centro->info1, "6", "6", "6");
  comp_filho(raiz->centro, 0, 0, 0);
  TEST_ASSERT_EQUAL_INT(1, raiz->centro->n_info);

  comp_info(raiz->direita->info1, "8", "8", "8");
  comp_filho(raiz->direita, 0, 0, -1);
  TEST_ASSERT_EQUAL_INT(1, raiz->direita->n_info);
}

void arvore23_exibir_pre(Arvore_2_3 *raiz_atual)
{
    if(raiz_atual != NULL)
    {
        printf("[1º] %s -> ", raiz_atual->info1.palavra_portugues);
        if(raiz_atual->n_info == 2)
            printf("[2º] %s -> ", raiz_atual->info2.palavra_portugues);

        arvore23_exibir_pre(raiz_atual->esquerda);
        arvore23_exibir_pre(raiz_atual->centro);
        if(raiz_atual->n_info == 2)
            arvore23_exibir_pre(raiz_atual->direita);
    }
}

void test_remocao_2_3_caso_20()
{
  int valores_adicionar[] = {3000, 900, 1800, 500, 100, 250, 600, 1250, 1000, 1700, 1750, 2400, 2100, 2500, 7000, 4200, 5800, 3500, 4300, 6500, 8000, 10000, 7500, 9000, 9500};
  func_test_inserindo_valores_automatico(valores_adicionar, 25);

  FILE *fp = freopen("output/test_remocao_caso_20_crecente.txt", "w", stdout);
  for (int i = 0; i < 25; i++)
  {
    char valor[20];
    sprintf(valor, "%d", valores_adicionar[i]);
    int resposta = arvore_2_3_remover(&raiz, valor);
    printf("Removendo %s\n", valor);
    arvore23_exibir_pre(raiz);
    printf("\n\n");
  }
  fclose(fp);
  freopen("/dev/tty", "w", stdout);

  func_test_inserindo_valores_automatico(valores_adicionar, 25);

  FILE *fp1 = freopen("output/test_remocao_caso_20_decrescente.txt", "w", stdout);
  for (int i = 24; i >= 0; i--)
  {
    char valor[20];
    sprintf(valor, "%d", valores_adicionar[i]);
    printf("Removendo %s\n", valor);
    int resposta = arvore_2_3_remover(&raiz, valor);
    arvore23_exibir_pre(raiz);
    printf("\n\n");
  }
  fclose(fp1);
  freopen("/dev/tty", "w", stdout);
}


void test_remocao_2_3_caso_21()
{
  int valores_adicionar[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  func_test_inserindo_valores_automatico(valores_adicionar, 26);

  FILE *fp = freopen("output/test_remocao_caso_21.txt", "w", stdout);
  for (int i = 25; i >= 0; i--)
  {
    char valor[20];
    sprintf(valor, "%d", valores_adicionar[i]);
    int resposta = arvore_2_3_remover(&raiz, valor);
    printf("Removendo %s\n", valor);
    arvore23_exibir_pre(raiz);
    printf("\n\n");
  }
  fclose(fp);
  freopen("/dev/tty", "w", stdout);
}

void test_remocao_2_3_caso_22()
{
  char *valores_adicionar[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

  for (int i = 0; i < 26; i++)
  {
    InfoMain info;
    def_info_arvore_2_3(&info, valores_adicionar[i], valores_adicionar[i], valores_adicionar[i]);
    inserir_arvore_2_3(&raiz, info);
  }

  FILE *fp = freopen("output/test_remocao_caso_22.txt", "w", stdout);
  for (int i = 25; i >= 0; i--)
  {
    int resposta = arvore_2_3_remover(&raiz, valores_adicionar[i]);
    printf("Removendo %s\n", valores_adicionar[i]);
    arvore23_exibir_pre(raiz);
    printf("\n\n");
  }
  fclose(fp);
  freopen("/dev/tty", "w", stdout);
}


void test_remocao_2_3_caso_23()
{
  char *valores_adicionar[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

  for (int i = 0; i < 26; i++)
  {
    InfoMain info;
    def_info_arvore_2_3(&info, valores_adicionar[i], valores_adicionar[i], valores_adicionar[i]);
    inserir_arvore_2_3(&raiz, info);
  }

  FILE *fp = freopen("output/test_remocao_caso_23.txt", "w", stdout);
  for (int i = 0; i < 26; i++)
  {
    int resposta = arvore_2_3_remover(&raiz, valores_adicionar[i]);
    printf("Removendo %s\n", valores_adicionar[i]);
    arvore23_exibir_pre(raiz);
    printf("\n\n");
  }
  fclose(fp);
  freopen("/dev/tty", "w", stdout);
}