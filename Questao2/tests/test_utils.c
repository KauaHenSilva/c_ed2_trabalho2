#include "Unity/unity.h"
#include "include/utils.h"
#include <stdlib.h>

void setUp()
{
}

void tearDown()
{
}

void test_tamanho_string();
void test_aloca_string();
void test_nome_presente();
void test_juntar_nome_por_virgula();
void test_remover_virgula();

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_tamanho_string);
  RUN_TEST(test_aloca_string);
  RUN_TEST(test_nome_presente);
  RUN_TEST(test_juntar_nome_por_virgula);
  RUN_TEST(test_remover_virgula);
  return UNITY_END();
}

void test_tamanho_string()
{
  TEST_ASSERT_EQUAL(5, tamanho_string("hello"));
  TEST_ASSERT_EQUAL(0, tamanho_string(""));
  TEST_ASSERT_EQUAL(4, tamanho_string("test"));
}

void test_aloca_string()
{
  char *str;
  TEST_ASSERT_EQUAL(1, aloca_string(&str, 10));
  TEST_ASSERT_NOT_NULL(str);
  free(str);
}

void test_nome_presente()
{
  TEST_ASSERT_EQUAL(1, nome_presente("john", "john, doe, jane"));
  TEST_ASSERT_EQUAL(0, nome_presente("mike", "john, doe, jane"));
  TEST_ASSERT_EQUAL(1, nome_presente("jane", "john, doe, jane"));
}

void test_juntar_nome_por_virgula()
{
  char *result;
  aloca_string(&result, 20);
  juntar_nome_por_virgula("john", "doe", &result);
  TEST_ASSERT_EQUAL_STRING("john, doe", result);
  free(result);
}

void test_remover_virgula()
{
  char palavra[] = "ventilador,";
  remover_virgula(palavra);
  TEST_ASSERT_EQUAL_STRING("ventilador", palavra);
}