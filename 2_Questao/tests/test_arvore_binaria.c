#include "Unity/unity.h"
#include "include/arvore_binaria.h"

ArvoreBinaria *raiz;

void setUp()
{
  raiz = NULL;
}
void tearDown()
{
  free_arvore_binaria(&raiz);
}

void test_aloca_arvore_binaria();
void test_insercao_arvore_binaria();
void test_atualizar_nome_unidade();
void test_so_um_filho_caso_1(); // Sem filho
void test_so_um_filho_caso_2(); // Filho a direita
void test_so_um_filho_caso_3(); // Filho a esquerda
void test_menor_filho_caso_1(); // O Menor filho é a raiz
void test_menor_filho_caso_2(); // O Menor filho é a raiz->esquerda
void test_menor_filho_caso_3(); // O Menor filho é a raiz->esquerda->esquerda
void test_remocao_arvore_binaria_caso_1(); // Folha
void test_remocao_arvore_binaria_caso_2(); // 1 filho a direita
void test_remocao_arvore_binaria_caso_3(); // 1 filho a esquerda
void test_remocao_arvore_binaria_caso_4(); // 2 filhos


int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_aloca_arvore_binaria);
  RUN_TEST(test_atualizar_nome_unidade);
  RUN_TEST(test_insercao_arvore_binaria);
  RUN_TEST(test_so_um_filho_caso_1);
  RUN_TEST(test_so_um_filho_caso_2);
  RUN_TEST(test_so_um_filho_caso_3);
  RUN_TEST(test_menor_filho_caso_1);
  RUN_TEST(test_menor_filho_caso_2);
  RUN_TEST(test_menor_filho_caso_3);
  RUN_TEST(test_remocao_arvore_binaria_caso_1);
  RUN_TEST(test_remocao_arvore_binaria_caso_2);
  RUN_TEST(test_remocao_arvore_binaria_caso_3);
  RUN_TEST(test_remocao_arvore_binaria_caso_4);
  return UNITY_END();
}

void test_insercao_arvore_binaria()
{
  ArvoreBinaria *new;
  aloca_arvore_binaria(&new);
  def_arvore_binaria(new, "Palavra2", "Unidade");

  // Inserção na raiz
  int resultado = insercao_arvore_binaria(&raiz, new);
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Palavra2", raiz->info.palavra_ingles);
  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->direita);

  // Inserção à esquerda
  ArvoreBinaria *new2;
  aloca_arvore_binaria(&new2);
  def_arvore_binaria(new2, "Palavra1", "Unidade");

  resultado = insercao_arvore_binaria(&raiz, new2);
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_NOT_NULL(raiz->esquerda);
  TEST_ASSERT_EQUAL_STRING("Palavra1", raiz->esquerda->info.palavra_ingles);
  TEST_ASSERT_NULL(raiz->esquerda->esquerda);
  TEST_ASSERT_NULL(raiz->esquerda->direita);

  // Inserção à direita
  ArvoreBinaria *new3;
  aloca_arvore_binaria(&new3);
  def_arvore_binaria(new3, "Palavra3", "Unidade");

  resultado = insercao_arvore_binaria(&raiz, new3);
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_NOT_NULL(raiz->direita);
  TEST_ASSERT_EQUAL_STRING("Palavra3", raiz->direita->info.palavra_ingles);
  TEST_ASSERT_NULL(raiz->direita->esquerda);
  TEST_ASSERT_NULL(raiz->direita->direita);
}

void test_atualizar_nome_unidade()
{
  ArvoreBinaria *new;
  aloca_arvore_binaria(&new);
  def_arvore_binaria(new, "Palavra2", "Unidade1");

  // Inserção na raiz
  int resultado = insercao_arvore_binaria(&raiz, new);
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Palavra2", raiz->info.palavra_ingles);
  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->direita);

  // Atualização
  ArvoreBinaria *new2;
  aloca_arvore_binaria(&new2);
  def_arvore_binaria(new2, "Palavra2", "Unidade2");

  int resultado_atualizacao = insercao_arvore_binaria(&raiz, new2);
  TEST_ASSERT_EQUAL_INT(1, resultado_atualizacao);
  TEST_ASSERT_EQUAL_STRING("Unidade2", raiz->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("Unidade1", raiz->info.unidades->prox->nome_unidade);
  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->direita);

  // Atualização
  ArvoreBinaria *new3;
  aloca_arvore_binaria(&new3);
  def_arvore_binaria(new3, "Palavra2", "Unidade3");

  resultado_atualizacao = insercao_arvore_binaria(&raiz, new3);
  TEST_ASSERT_EQUAL_INT(1, resultado_atualizacao);
  TEST_ASSERT_EQUAL_STRING("Unidade3", raiz->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("Unidade2", raiz->info.unidades->prox->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("Unidade1", raiz->info.unidades->prox->prox->nome_unidade);
  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->direita);
  
}

void test_aloca_arvore_binaria()
{
  aloca_arvore_binaria(&raiz);
  def_arvore_binaria(raiz, "Palavra", "Unidade");

  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Palavra", raiz->info.palavra_ingles);
  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->direita);
}

void test_remocao_arvore_binaria_caso_1() // Folha
{
  ArvoreBinaria *new;
  aloca_arvore_binaria(&new);
  def_arvore_binaria(new, "Palavra2", "Unidade");
  insercao_arvore_binaria(&raiz, new);

  int resultado = remocao_arvore_binaria(&raiz, "Palavra2");
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_NULL(raiz);
}

void test_remocao_arvore_binaria_caso_2() // 1 filho a direita
{
  ArvoreBinaria *new;
  aloca_arvore_binaria(&new);
  def_arvore_binaria(new, "Palavra2", "Unidade");
  insercao_arvore_binaria(&raiz, new);

  ArvoreBinaria *new2;
  aloca_arvore_binaria(&new2);
  def_arvore_binaria(new2, "Palavra1", "Unidade");
  insercao_arvore_binaria(&raiz, new2);

  int resultado = remocao_arvore_binaria(&raiz, "Palavra2");
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Palavra1", raiz->info.palavra_ingles);
  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->direita);
}

void test_remocao_arvore_binaria_caso_3() // 1 filho a esquerda
{
  ArvoreBinaria *new;
  aloca_arvore_binaria(&new);
  def_arvore_binaria(new, "Palavra2", "Unidade");
  insercao_arvore_binaria(&raiz, new);

  ArvoreBinaria *new2;
  aloca_arvore_binaria(&new2);
  def_arvore_binaria(new2, "Palavra3", "Unidade");
  insercao_arvore_binaria(&raiz, new2);

  int resultado = remocao_arvore_binaria(&raiz, "Palavra2");
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Palavra3", raiz->info.palavra_ingles);
  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->direita);
}

void test_remocao_arvore_binaria_caso_4() // 2 filhos
{
  ArvoreBinaria *new;
  aloca_arvore_binaria(&new);
  def_arvore_binaria(new, "Palavra2", "Unidade");
  insercao_arvore_binaria(&raiz, new);

  ArvoreBinaria *new2;
  aloca_arvore_binaria(&new2);
  def_arvore_binaria(new2, "Palavra1", "Unidade");
  insercao_arvore_binaria(&raiz, new2);

  ArvoreBinaria *new3;
  aloca_arvore_binaria(&new3);
  def_arvore_binaria(new3, "Palavra3", "Unidade");
  insercao_arvore_binaria(&raiz, new3);

  int resultado = remocao_arvore_binaria(&raiz, "Palavra2");
  TEST_ASSERT_EQUAL_INT(1, resultado);
  TEST_ASSERT_EQUAL_STRING("Palavra3", raiz->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("Palavra1", raiz->esquerda->info.palavra_ingles);
  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_NOT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->direita);
}

void test_so_um_filho_caso_1() // Sem filho
{
  ArvoreBinaria *new;
  aloca_arvore_binaria(&new);
  def_arvore_binaria(new, "Palavra2", "Unidade");

  insercao_arvore_binaria(&raiz, new);

  ArvoreBinaria *resultado = so_um_filho(&raiz);
  TEST_ASSERT_NULL(resultado);
}

void test_so_um_filho_caso_2() // Filho a direita
{
  ArvoreBinaria *new;
  aloca_arvore_binaria(&new);
  def_arvore_binaria(new, "Palavra2", "Unidade");

  insercao_arvore_binaria(&raiz, new);

  ArvoreBinaria *new2;
  aloca_arvore_binaria(&new2);
  def_arvore_binaria(new2, "Palavra1", "Unidade");

  insercao_arvore_binaria(&raiz, new2);

  ArvoreBinaria *resultado = so_um_filho(&raiz);
  TEST_ASSERT_NOT_NULL(resultado);
  TEST_ASSERT_EQUAL_STRING("Palavra1", resultado->info.palavra_ingles);
}

void test_so_um_filho_caso_3() // Filho a esquerda
{
  ArvoreBinaria *new;
  aloca_arvore_binaria(&new);
  def_arvore_binaria(new, "Palavra2", "Unidade");

  insercao_arvore_binaria(&raiz, new);

  ArvoreBinaria *new2;
  aloca_arvore_binaria(&new2);
  def_arvore_binaria(new2, "Palavra3", "Unidade");

  insercao_arvore_binaria(&raiz, new2);

  ArvoreBinaria *resultado = so_um_filho(&raiz);
  TEST_ASSERT_NOT_NULL(resultado);
  TEST_ASSERT_EQUAL_STRING("Palavra3", resultado->info.palavra_ingles);
}

void test_menor_filho_caso_1()
{
  ArvoreBinaria *new;
  aloca_arvore_binaria(&new);
  def_arvore_binaria(new, "Palavra2", "Unidade");

  insercao_arvore_binaria(&raiz, new);

  ArvoreBinaria *resultado = menor_filho(&raiz);
  TEST_ASSERT_NOT_NULL(resultado);
  TEST_ASSERT_EQUAL_STRING("Palavra2", resultado->info.palavra_ingles);
}

void test_menor_filho_caso_2()
{
  ArvoreBinaria *new;
  aloca_arvore_binaria(&new);
  def_arvore_binaria(new, "Palavra2", "Unidade");

  insercao_arvore_binaria(&raiz, new);

  ArvoreBinaria *new2;
  aloca_arvore_binaria(&new2);
  def_arvore_binaria(new2, "Palavra1", "Unidade");

  insercao_arvore_binaria(&raiz, new2);

  ArvoreBinaria *resultado = menor_filho(&raiz);
  TEST_ASSERT_NOT_NULL(resultado);
  TEST_ASSERT_EQUAL_STRING("Palavra1", resultado->info.palavra_ingles);
}

void test_menor_filho_caso_3()
{
  ArvoreBinaria *new;
  aloca_arvore_binaria(&new);
  def_arvore_binaria(new, "Palavra3", "Unidade");

  insercao_arvore_binaria(&raiz, new);

  ArvoreBinaria *new2;
  aloca_arvore_binaria(&new2);
  def_arvore_binaria(new2, "Palavra2", "Unidade");

  insercao_arvore_binaria(&raiz, new2);

  ArvoreBinaria *new3;
  aloca_arvore_binaria(&new3);
  def_arvore_binaria(new3, "Palavra1", "Unidade");

  insercao_arvore_binaria(&raiz, new3);

  ArvoreBinaria *resultado = menor_filho(&raiz);
  TEST_ASSERT_NOT_NULL(resultado);
  TEST_ASSERT_EQUAL_STRING("Palavra1", resultado->info.palavra_ingles);
}
