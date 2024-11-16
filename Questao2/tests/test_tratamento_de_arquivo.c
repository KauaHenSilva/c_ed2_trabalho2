#include "Unity/unity.h"
#include "include/tratamento_de_arquivo.h"
#include "include/arvore_vermelho_preto.h"
#include <stdio.h>
#include <stdlib.h>

ArvoreVermelhoPreto *raiz;

void setUp()
{
  raiz = NULL;
}
void tearDown()
{
  free_arvore_vermelho_preto(&raiz);
}

void test_ler_indentificar_linha_nome_unidade();
void test_ler_indentificar_linha_palavra_ingles_portugues();
void test_prencher_arvore_por_linha();
void test_ler_blocos();

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_ler_indentificar_linha_nome_unidade);
  RUN_TEST(test_ler_indentificar_linha_palavra_ingles_portugues);
  RUN_TEST(test_prencher_arvore_por_linha);
  RUN_TEST(test_ler_blocos);
  return UNITY_END();
}

void test_ler_indentificar_linha_nome_unidade()
{
  char linha[] = "% Unidade 1";
  TipoEntrada tipo = ler_indentificar_linha(linha);
  TEST_ASSERT_EQUAL_INT(NOME_UNIDADE, tipo);
}

void test_ler_indentificar_linha_palavra_ingles_portugues()
{
  char linha[] = "home: casa";
  TipoEntrada tipo = ler_indentificar_linha(linha);
  TEST_ASSERT_EQUAL_INT(PALAVRA_INGLES_PORTUGUES, tipo);
}

void test_prencher_arvore_por_linha()
{
  char linha[] = "Bus: onibus, barramento;";

  int resultado = prencher_arvore_por_linha(&raiz, linha, "Unidade 1");
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Unidade 1", raiz->info.arv_binaria_palavra_ingles->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("Bus", raiz->info.arv_binaria_palavra_ingles->palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("onibus", raiz->info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("barramento", raiz->esq->info.palavra_portugues);
  TEST_ASSERT_NOT_NULL(raiz->esq);
  TEST_ASSERT_NULL(raiz->dir);
}

void test_ler_blocos()
{
  int resultado = ler_blocos(&raiz);
  show_arvore_vermelho_preto(raiz);
  TEST_ASSERT_EQUAL_INT(1, resultado);
}
