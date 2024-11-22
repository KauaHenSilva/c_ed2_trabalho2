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
void test_remover_virgula();

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_tamanho_string);
  RUN_TEST(test_aloca_string);
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
  char *str = NULL;
  TEST_ASSERT_EQUAL(1, aloca_string(&str, 10));
  TEST_ASSERT_NOT_NULL(str);
  free(str);
}

void test_realoca_string()
{
  char *str;
  TEST_ASSERT_EQUAL(1, aloca_string(&str, 10));
  TEST_ASSERT_NOT_NULL(str);

  TEST_ASSERT_EQUAL(1, aloca_string(&str, 20));
  TEST_ASSERT_NOT_NULL(str);
  free(str);
}


void test_remover_virgula()
{
  char palavra[] = "ventilador,";
  remover_virgula(palavra);
  TEST_ASSERT_EQUAL_STRING("ventilador", palavra);
}