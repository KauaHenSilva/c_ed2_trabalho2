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

    def_info_arvore_2_3(&newInfo, palavra_portugues, palavra_portugues, nome_unidade);
    inserir_arvore_2_3(&raiz, newInfo, &promove, &pai);
  }
}

void setUp(void)
{
  raiz = NULL;
}

void tearDown(void)
{
  free_arvore_2_3(&raiz);
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
// void test_insercao_arvore_2_3_inserindo_caso_2(); // 3 -> 2 -> 1
// void test_insercao_arvore_2_3_inserindo_caso_3(); // 2 -> 1 -> 3
// void test_insercao_arvore_2_3_inserindo_caso_4(); // 3 -> 1 -> 2
// void test_insercao_arvore_2_3_atualizando_caso_1();

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
  // RUN_TEST(test_insercao_arvore_2_3_inserindo_caso_2);
  // RUN_TEST(test_insercao_arvore_2_3_inserindo_caso_3);
  // RUN_TEST(test_insercao_arvore_2_3_inserindo_caso_4);
  // RUN_TEST(test_insercao_arvore_2_3_atualizando_caso_1);
  return UNITY_END();
}

void test_insercao_arvore_2_3_inserindo()
{
  InfoMain newInfo;
  def_info_arvore_2_3(&newInfo, "Bus", "Onibus", "Unidade 1");

  Arvore_2_3 *new_node = NULL;
  Arvore_2_3 *pai = NULL;
  InfoMain promove;

  inserir_arvore_2_3(&raiz, newInfo, &promove, &pai);

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

  inserir_arvore_2_3(&raiz, newInfo, &promove, &pai);
  inserir_arvore_2_3(&raiz, newInfo, &promove, &pai);

  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Bus", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("Onibus", raiz->info1.palavra_portugues);
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

// void test_insercao_arvore_2_3_inserindo_caso_3()
// {
//   // Passo 1
//   ArvoreVermelhoPreto *newTree1;
//   aloca_arvore_vermelho_preto(&newTree1);
//   def_arvore_vermelho_preto(newTree1, "1", "1", "Unidade");

//   int resultado = inserir_arvore_vermelho_preto(&raiz, newTree1);
//   TEST_ASSERT_EQUAL_INT(1, resultado);

//   // Passo 2
//   ArvoreVermelhoPreto *newTree2;
//   aloca_arvore_vermelho_preto(&newTree2);
//   def_arvore_vermelho_preto(newTree2, "2", "2", "Unidade");

//   resultado = inserir_arvore_vermelho_preto(&raiz, newTree2);
//   TEST_ASSERT_EQUAL_INT(1, resultado);

//   TEST_ASSERT_NOT_NULL(raiz->esq);
//   TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->esq->cor);
//   TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);

//   // Passo 3
//   ArvoreVermelhoPreto *newTree3;
//   aloca_arvore_vermelho_preto(&newTree3);
//   def_arvore_vermelho_preto(newTree3, "3", "3", "Unidade");

//   resultado = inserir_arvore_vermelho_preto(&raiz, newTree3);
//   TEST_ASSERT_EQUAL_INT(1, resultado);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
//   TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
//   TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
// }

// void test_insercao_arvore_2_3_inserindo_caso_2()
// {
//   // Passo 1
//   ArvoreVermelhoPreto *newTree1;
//   aloca_arvore_vermelho_preto(&newTree1);
//   def_arvore_vermelho_preto(newTree1, "3", "3", "Unidade");

//   inserir_arvore_vermelho_preto(&raiz, newTree1);

//   // Passo 2
//   ArvoreVermelhoPreto *newTree2;
//   aloca_arvore_vermelho_preto(&newTree2);
//   def_arvore_vermelho_preto(newTree2, "2", "2", "Unidade");

//   int resultado = inserir_arvore_vermelho_preto(&raiz, newTree2);

//   TEST_ASSERT_EQUAL_INT(1, resultado);
//   TEST_ASSERT_EQUAL_STRING("3", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("3", raiz->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->esq->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->esq->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
//   TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->esq->cor);

//   // Passo 3
//   ArvoreVermelhoPreto *newTree3;
//   aloca_arvore_vermelho_preto(&newTree3);
//   def_arvore_vermelho_preto(newTree3, "1", "1", "Unidade");

//   resultado = inserir_arvore_vermelho_preto(&raiz, newTree3);

//   TEST_ASSERT_EQUAL_INT(1, resultado);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
//   TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
//   TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
// }

// void test_insercao_arvore_2_3_inserindo_caso_3()
// {
//   // Passo 1, inserindo o 2.
//   ArvoreVermelhoPreto *newTree1;
//   aloca_arvore_vermelho_preto(&newTree1);
//   def_arvore_vermelho_preto(newTree1, "2", "2", "Unidade");

//   inserir_arvore_vermelho_preto(&raiz, newTree1);

//   // Passo 2, inserindo o 1.
//   ArvoreVermelhoPreto *newTree2;
//   aloca_arvore_vermelho_preto(&newTree2);
//   def_arvore_vermelho_preto(newTree2, "1", "1", "Unidade");

//   int confirmacao = inserir_arvore_vermelho_preto(&raiz, newTree2);

//   TEST_ASSERT_EQUAL_INT(1, confirmacao);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_INT(VERMELHO, raiz->esq->cor);
//   TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);

//   // Passo 3, inserindo o 3.
//   ArvoreVermelhoPreto *newTree3;
//   aloca_arvore_vermelho_preto(&newTree3);
//   def_arvore_vermelho_preto(newTree3, "3", "3", "Unidade");

//   confirmacao = inserir_arvore_vermelho_preto(&raiz, newTree3);

//   TEST_ASSERT_EQUAL_INT(1, confirmacao);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
//   TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
//   TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
// }

// void test_insercao_arvore_2_3_inserindo_caso_4()
// {
//   ArvoreVermelhoPreto *newTree1;
//   aloca_arvore_vermelho_preto(&newTree1);
//   def_arvore_vermelho_preto(newTree1, "3", "3", "Unidade");

//   inserir_arvore_vermelho_preto(&raiz, newTree1);

//   ArvoreVermelhoPreto *newTree2;
//   aloca_arvore_vermelho_preto(&newTree2);
//   def_arvore_vermelho_preto(newTree2, "1", "1", "Unidade");

//   inserir_arvore_vermelho_preto(&raiz, newTree2);

//   ArvoreVermelhoPreto *newTree3;
//   aloca_arvore_vermelho_preto(&newTree3);
//   def_arvore_vermelho_preto(newTree3, "2", "2", "Unidade");

//   inserir_arvore_vermelho_preto(&raiz, newTree3);

//   TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("1", raiz->esq->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("3", raiz->dir->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_INT(PRETO, raiz->cor);
//   TEST_ASSERT_EQUAL_INT(PRETO, raiz->esq->cor);
//   TEST_ASSERT_EQUAL_INT(PRETO, raiz->dir->cor);
// }

// void test_insercao_arvore_2_3_atualizando_caso_1()
// {
//   // Passo 1, inserindo a palavra ingles 2, portugues 2, unidade 1.
//   ArvoreVermelhoPreto *newTree1;
//   aloca_arvore_vermelho_preto(&newTree1);
//   def_arvore_vermelho_preto(newTree1, "2", "2", "Unidade 1");

//   inserir_arvore_vermelho_preto(&raiz, newTree1);

//   // Passo 2, inserindo a palavra ingles 2, portugues 1, unidade 2.
//   ArvoreVermelhoPreto *newTree2;
//   InfoMain newInfo2;

//   aloca_arvore_vermelho_preto(&newTree2);
//   def_arvore_vermelho_preto(newTree2, "1", "2", "Unidade 2");

//   int confirmacao = inserir_arvore_vermelho_preto(&raiz, newTree2);
//   TEST_ASSERT_EQUAL_INT(1, confirmacao);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->info.palavra_portugues);
//   TEST_ASSERT_EQUAL_STRING("2", raiz->info.arv_binaria_palavra_ingles->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("Unidade 1", raiz->info.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
//   TEST_ASSERT_EQUAL_STRING("1", raiz->info.arv_binaria_palavra_ingles->esquerda->info.palavra_ingles);
//   TEST_ASSERT_EQUAL_STRING("Unidade 2", raiz->info.arv_binaria_palavra_ingles->esquerda->info.unidades->nome_unidade);
// }
