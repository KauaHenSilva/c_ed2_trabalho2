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

void compare_info(InfoMain info, char *palavra_ingles, char *palavra_portugues, char *nome_unidade)
{
  TEST_ASSERT_EQUAL_STRING(palavra_ingles, info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING(palavra_portugues, info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING(nome_unidade, info.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
}

void compare_filiais_NULL(Arvore_2_3 *raiz_atual, Arvore_2_3 *esquerda, Arvore_2_3 *centro, Arvore_2_3 *direita)
{
  if (!esquerda)
    TEST_ASSERT_NULL(raiz_atual->esquerda);
  else
    TEST_ASSERT_NOT_NULL(raiz_atual->esquerda);

  if (!centro)
    TEST_ASSERT_NULL(raiz_atual->centro);
  else
    TEST_ASSERT_NOT_NULL(raiz_atual->centro);

  if (!raiz_atual->n_info == 2)
    if (!direita)
      TEST_ASSERT_NULL(raiz_atual->direita);
    else
      TEST_ASSERT_NOT_NULL(raiz_atual->direita);
}

void compare_qtd_info(Arvore_2_3 *raiz_atual, int qtd)
{
  TEST_ASSERT_EQUAL_INT(qtd, raiz_atual->n_info);
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
void test_insercao_arvore_2_3_inserindo_caso_8(); // inc: 3, 6, 1, 2, 4, 5, 7, 8

// destrichando esse caso: 
void test_insercao_arvore_2_3_inserindo_caso_9(); // {3000, 900, 1800, 500, 100, 250, 600, 1250, 1000, 1700, 1750, 2400, 2100, 2500, 7000, 4200, 5800, 3500, 4300, 6500, 8000, 10000, 7500, 9000, 9500, 15000};


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
  RUN_TEST(test_insercao_arvore_2_3_inserindo_caso_8);
  RUN_TEST(test_insercao_arvore_2_3_inserindo_caso_9);
  return UNITY_END();
}

void test_insercao_arvore_2_3_inserindo()
{
  InfoMain newInfo;
  def_info_arvore_2_3(&newInfo, "Bus", "Onibus", "Unidade 1");

  inserir_arvore_2_3(&raiz, newInfo);

  compare_info(raiz->info1, "Bus", "Onibus", "Unidade 1");
  compare_filiais_NULL(raiz, NULL, NULL, NULL);
  compare_qtd_info(raiz, 1);
}

void test_insercao_arvore_2_3_inserindo_valor_unico()
{
  InfoMain newInfo;
  def_info_arvore_2_3(&newInfo, "Bus", "Onibus", "Unidade 1");

  inserir_arvore_2_3(&raiz, newInfo);
  int resposta = inserir_arvore_2_3(&raiz, newInfo);

  compare_info(raiz->info1, "Bus", "Onibus", "Unidade 1");
  compare_filiais_NULL(raiz, NULL, NULL, NULL);
  compare_qtd_info(raiz, 1);
}

void test_insercao_arvore_2_3_inserindo_caso_1()
{
  int valores_adicinar[] = {1, 2};
  func_test_inserindo_valores_automatico(valores_adicinar, 2);

  compare_info(raiz->info1, "1", "1", "1");
  compare_info(raiz->info2, "2", "2", "2");
  compare_filiais_NULL(raiz, NULL, NULL, NULL);
  compare_qtd_info(raiz, 2);
}

void test_insercao_arvore_2_3_inserindo_caso_2()
{
  int valores_adicinar[] = {2, 1};
  func_test_inserindo_valores_automatico(valores_adicinar, 2);

  compare_info(raiz->info1, "1", "1", "1");
  compare_info(raiz->info2, "2", "2", "2");
  compare_filiais_NULL(raiz, NULL, NULL, NULL);
  compare_qtd_info(raiz, 2);
}

void test_insercao_arvore_2_3_inserindo_caso_3()
{
  int valores_adicinar[] = {1, 2, 3};
  func_test_inserindo_valores_automatico(valores_adicinar, 3);

  compare_info(raiz->info1, "2", "2", "2");
  compare_info(raiz->esquerda->info1, "1", "1", "1");
  compare_info(raiz->centro->info1, "3", "3", "3");

  compare_filiais_NULL(raiz, raiz, raiz, NULL);
  compare_filiais_NULL(raiz->esquerda, NULL, NULL, NULL);
  compare_filiais_NULL(raiz->centro, NULL, NULL, NULL);

  compare_qtd_info(raiz, 1);
  compare_qtd_info(raiz->esquerda, 1);
  compare_qtd_info(raiz->centro, 1);
}

void test_insercao_arvore_2_3_inserindo_caso_4()
{
  int valores_adicinar[] = {2, 3, 4, 1};
  func_test_inserindo_valores_automatico(valores_adicinar, 4);

  compare_info(raiz->info1, "3", "3", "3");
  compare_info(raiz->esquerda->info1, "1", "1", "1");
  compare_info(raiz->esquerda->info2, "2", "2", "2");
  compare_info(raiz->centro->info1, "4", "4", "4");

  compare_qtd_info(raiz, 1);
  compare_qtd_info(raiz->esquerda, 2);
  compare_qtd_info(raiz->centro, 1);

  compare_filiais_NULL(raiz, raiz, raiz, NULL);
  compare_filiais_NULL(raiz->esquerda, NULL, NULL, NULL);
  compare_filiais_NULL(raiz->centro, NULL, NULL, NULL);
}

void test_insercao_arvore_2_3_inserindo_caso_5()
{
  int valores_adicinar[] = {1, 2, 3, 4};
  func_test_inserindo_valores_automatico(valores_adicinar, 4);

  compare_info(raiz->info1, "2", "2", "2");
  compare_info(raiz->esquerda->info1, "1", "1", "1");
  compare_info(raiz->centro->info1, "3", "3", "3");
  compare_info(raiz->centro->info2, "4", "4", "4");

  compare_qtd_info(raiz, 1);
  compare_qtd_info(raiz->esquerda, 1);
  compare_qtd_info(raiz->centro, 2);

  compare_filiais_NULL(raiz, raiz, raiz, NULL);
  compare_filiais_NULL(raiz->esquerda, NULL, NULL, NULL);
  compare_filiais_NULL(raiz->centro, NULL, NULL, NULL);
}

void test_insercao_arvore_2_3_inserindo_caso_6()
{
  int valores_adicinar[] = {1, 2, 3, 4, 5};
  func_test_inserindo_valores_automatico(valores_adicinar, 5);

  compare_info(raiz->info1, "2", "2", "2");
  compare_info(raiz->info2, "4", "4", "4");
  compare_info(raiz->esquerda->info1, "1", "1", "1");
  compare_info(raiz->centro->info1, "3", "3", "3");
  compare_info(raiz->direita->info1, "5", "5", "5");

  compare_qtd_info(raiz, 2);
  compare_qtd_info(raiz->esquerda, 1);
  compare_qtd_info(raiz->centro, 1);
  compare_qtd_info(raiz->direita, 1);

  compare_filiais_NULL(raiz, raiz, raiz, raiz);
  compare_filiais_NULL(raiz->esquerda, NULL, NULL, NULL);
  compare_filiais_NULL(raiz->centro, NULL, NULL, NULL);
  compare_filiais_NULL(raiz->direita, NULL, NULL, NULL);
}

void test_insercao_arvore_2_3_inserindo_caso_7()
{
  int valores_adicinar[] = {1, 2, 3, 4, 5, 6, 7};
  func_test_inserindo_valores_automatico(valores_adicinar, 7);

  compare_info(raiz->info1, "4", "4", "4");
  compare_info(raiz->esquerda->info1, "2", "2", "2");
  compare_info(raiz->centro->info1, "6", "6", "6");
  compare_info(raiz->esquerda->esquerda->info1, "1", "1", "1");
  compare_info(raiz->esquerda->centro->info1, "3", "3", "3");
  compare_info(raiz->centro->esquerda->info1, "5", "5", "5");
  compare_info(raiz->centro->centro->info1, "7", "7", "7");

  compare_qtd_info(raiz, 1);
  compare_qtd_info(raiz->esquerda, 1);
  compare_qtd_info(raiz->centro, 1);
  compare_qtd_info(raiz->esquerda->esquerda, 1);
  compare_qtd_info(raiz->esquerda->centro, 1);
  compare_qtd_info(raiz->centro->esquerda, 1);
  compare_qtd_info(raiz->centro->centro, 1);

  compare_filiais_NULL(raiz, raiz, raiz, NULL);
  compare_filiais_NULL(raiz->esquerda, raiz, raiz, NULL);
  compare_filiais_NULL(raiz->centro, raiz, raiz, NULL);
  compare_filiais_NULL(raiz->esquerda->esquerda, NULL, NULL, NULL);
  compare_filiais_NULL(raiz->esquerda->centro, NULL, NULL, NULL);
  compare_filiais_NULL(raiz->centro->esquerda, NULL, NULL, NULL);
  compare_filiais_NULL(raiz->centro->centro, NULL, NULL, NULL);
}

void test_insercao_arvore_2_3_inserindo_caso_8()
{
  int valores_adicinar[] = {3, 6, 1, 2, 4, 5, 7, 8};
  func_test_inserindo_valores_automatico(valores_adicinar, 8);

  compare_info(raiz->info1, "5", "5", "5");
  compare_info(raiz->esquerda->info1, "3", "3", "3");
  compare_info(raiz->centro->info1, "7", "7", "7");
  compare_info(raiz->esquerda->esquerda->info1, "1", "1", "1");
  compare_info(raiz->esquerda->esquerda->info2, "2", "2", "2");
  compare_info(raiz->esquerda->centro->info1, "4", "4", "4");
  compare_info(raiz->centro->esquerda->info1, "6", "6", "6");
  compare_info(raiz->centro->centro->info1, "8", "8", "8");

  compare_qtd_info(raiz, 1);
  compare_qtd_info(raiz->esquerda, 1);
  compare_qtd_info(raiz->centro, 1);
  compare_qtd_info(raiz->esquerda->esquerda, 2);
  compare_qtd_info(raiz->esquerda->centro, 1);
  compare_qtd_info(raiz->centro->esquerda, 1);
  compare_qtd_info(raiz->centro->centro, 1);

  compare_filiais_NULL(raiz, raiz, raiz, NULL);
  compare_filiais_NULL(raiz->esquerda, raiz, raiz, NULL);
  compare_filiais_NULL(raiz->centro, raiz, raiz, NULL);
  compare_filiais_NULL(raiz->esquerda->esquerda, NULL, NULL, NULL);
  compare_filiais_NULL(raiz->esquerda->centro, NULL, NULL, NULL);
  compare_filiais_NULL(raiz->centro->esquerda, NULL, NULL, NULL);
  compare_filiais_NULL(raiz->centro->centro, NULL, NULL, NULL);
}

void test_insercao_arvore_2_3_inserindo_caso_9()
{
  int valores_adicionar[] = {3000, 900, 1800, 500, 100, 250, 600, 1250, 1000, 1700, 1750, 2400, 2100, 2500, 7000, 4200, 5800, 3500, 4300, 6500, 8000, 10000,
                             7500, 9000, 9500, 15000};
  func_test_inserindo_valores_automatico(valores_adicionar, 26);


  compare_info(raiz->info1, "3000", "3000", "3000");
  compare_info(raiz->esquerda->info1, "1700", "1700", "1700");
  compare_info(raiz->esquerda->info2, "3000", "3000", "3000");
  compare_info(raiz->centro->info1, "500", "500", "500");
  compare_info(raiz->centro->info2, "7000", "7000", "7000");
  compare_info(raiz->esquerda->esquerda->info1, "1000", "1000", "1000");
  compare_info(raiz->esquerda->esquerda->info2, "1250", "1250", "1250");
  compare_info(raiz->esquerda->centro->info1, "1800", "1800", "1800");
  compare_info(raiz->esquerda->centro->info2, "2400", "2400", "2400");
  compare_info(raiz->esquerda->direita->info1, "4200", "4200", "4200");
  compare_info(raiz->centro->esquerda->info1, "4200", "4200", "4200");
  compare_info(raiz->centro->centro->info1, "600", "600", "600");
  compare_info(raiz->centro->direita->info1, "8000", "8000", "8000");
  compare_info(raiz->centro->direita->info2, "9000", "9000", "9000");
  compare_info(raiz->esquerda->esquerda->esquerda->info1, "100", "100", "100");
  compare_info(raiz->esquerda->esquerda->centro->info1, "10000", "10000", "10000");
  compare_info(raiz->esquerda->esquerda->direita->info1, "15000", "15000", "15000");
  compare_info(raiz->esquerda->centro->esquerda->info1, "1750", "1750", "1750");
  compare_info(raiz->esquerda->centro->centro->info1, "2100", "2100", "2100");
  compare_info(raiz->esquerda->centro->direita->info1, "250", "250", "250");
  compare_info(raiz->esquerda->centro->direita->info2, "2500", "2500", "2500");
  compare_info(raiz->esquerda->direita->esquerda->info1, "3500", "3500", "3500");
  compare_info(raiz->esquerda->direita->centro->info1, "4300", "4300", "4300");

  // Pregruiça de fazer os testes de filiais e qtd de info. Não me julguem.
}