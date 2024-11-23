#include "Unity/unity.h"
#include "include/arvore_2_3.h"

Arvore_2_3 *raiz;

void setUp(void)
{
  raiz = NULL;
}
void tearDown(void)
{
  free_arvore_2_3(raiz);
}

void test_aloca_arvore_2_3();
void test_def_info_arvore_2_3();
void test_cria_no_arvore_2_3();
void test_adicionando_valor_em_arvore_2_3_caso_1();
void test_adicionando_valor_em_arvore_2_3_caso_2();
void test_quebra_no_caso_1(); // inc: 1, 2, 3
void test_quebra_no_caso_2(); // inc: 3, 1, 2
void test_quebra_no_caso_3(); // inc: 2, 3, 1
// void test_quebra_no_caso_3(); // inc: 2, 1, 3
// void test_show_arvore_2_3_caso_1();
// void test_show_arvore_2_3_caso_2();

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_aloca_arvore_2_3);
  RUN_TEST(test_def_info_arvore_2_3);
  RUN_TEST(test_cria_no_arvore_2_3);
  RUN_TEST(test_adicionando_valor_em_arvore_2_3_caso_1);
  RUN_TEST(test_adicionando_valor_em_arvore_2_3_caso_2);
  RUN_TEST(test_quebra_no_caso_1);
  RUN_TEST(test_quebra_no_caso_2);
  RUN_TEST(test_quebra_no_caso_3);
  // RUN_TEST(test_show_arvore_2_3_caso_1);
  // RUN_TEST(test_show_arvore_2_3_caso_2);
  return UNITY_END();
}

void test_aloca_arvore_2_3()
{
  aloca_arvore_2_3(&raiz);

  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_NULL(raiz->centro);
  TEST_ASSERT_NULL(raiz->direita);
  TEST_ASSERT_NULL(raiz->esquerda);
  TEST_ASSERT_NULL(raiz->info1.arv_binaria_palavra_ingles);
  TEST_ASSERT_NULL(raiz->info1.palavra_portugues);
  TEST_ASSERT_NULL(raiz->info2.arv_binaria_palavra_ingles);
  TEST_ASSERT_NULL(raiz->info2.palavra_portugues);
  TEST_ASSERT_EQUAL_INT(0, raiz->n_info);
}

void test_def_info_arvore_2_3()
{
  InfoMain info;
  def_info_arvore_2_3(&info, "Bus", "Onibus", "Unidade 1");

  TEST_ASSERT_EQUAL_STRING("Bus", info.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("Onibus", info.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("Unidade 1", info.arv_binaria_palavra_ingles->info.unidades->nome_unidade);

  free_info_arvore_2_3(&info);
}

void test_cria_no_arvore_2_3()
{
  InfoMain info;
  def_info_arvore_2_3(&info, "Bus", "Onibus", "Unidade 1");
  cria_no(&raiz, info, NULL, NULL);

  TEST_ASSERT_NOT_NULL(raiz);
  TEST_ASSERT_EQUAL_STRING("Bus", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("Onibus", raiz->info1.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("Unidade 1", raiz->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);

  TEST_ASSERT_NULL(raiz->centro);
  TEST_ASSERT_NULL(raiz->direita);
  TEST_ASSERT_NULL(raiz->esquerda);
}

void test_adicionando_valor_em_arvore_2_3_caso_1()
{
  InfoMain info1;
  InfoMain info2;
  def_info_arvore_2_3(&info1, "1", "1", "1");
  def_info_arvore_2_3(&info2, "2", "2", "2");

  cria_no(&raiz, info1, NULL, NULL);
  int resp = adicionando_valor_em_arvore_2_3(raiz, &info2, NULL);

  TEST_ASSERT_EQUAL_INT(1, resp);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info2.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info2.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info2.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
}

void test_adicionando_valor_em_arvore_2_3_caso_2()
{
  InfoMain info1;
  InfoMain info2;
  def_info_arvore_2_3(&info1, "2", "2", "2");
  def_info_arvore_2_3(&info2, "1", "1", "1");

  cria_no(&raiz, info1, NULL, NULL);
  int resp = adicionando_valor_em_arvore_2_3(raiz, &info2, NULL);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info2.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info2.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", raiz->info2.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
}

void test_quebra_no_caso_1()
{
  InfoMain info1;
  InfoMain info2;
  InfoMain info3;

  def_info_arvore_2_3(&info1, "1", "1", "1");
  def_info_arvore_2_3(&info2, "2", "2", "2");
  def_info_arvore_2_3(&info3, "3", "3", "3");

  cria_no(&raiz, info1, NULL, NULL);
  adicionando_valor_em_arvore_2_3(raiz, &info2, NULL);

  Arvore_2_3 *new_node = NULL;
  InfoMain info_up;
  quebra_no(&raiz, &new_node, info3, &info_up, NULL);

  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);

  TEST_ASSERT_EQUAL_STRING("3", new_node->info1.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", new_node->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", new_node->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);

  TEST_ASSERT_EQUAL_STRING("2", info_up.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", info_up.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", info_up.arv_binaria_palavra_ingles->info.unidades->nome_unidade);

  free_arvore_2_3(new_node);
}

void test_quebra_no_caso_2()
{
  InfoMain info1;
  InfoMain info2;
  InfoMain info3;

  def_info_arvore_2_3(&info1, "3", "3", "3");
  def_info_arvore_2_3(&info2, "1", "1", "1");
  def_info_arvore_2_3(&info3, "2", "2", "2");

  cria_no(&raiz, info1, NULL, NULL);
  adicionando_valor_em_arvore_2_3(raiz, &info2, NULL);

  Arvore_2_3 *new_node = NULL;
  InfoMain info_up;
  quebra_no(&raiz, &new_node, info3, &info_up, NULL);

  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);

  TEST_ASSERT_EQUAL_STRING("3", new_node->info1.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", new_node->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", new_node->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);

  TEST_ASSERT_EQUAL_STRING("2", info_up.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", info_up.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", info_up.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
}

void test_quebra_no_caso_3()
{
  InfoMain info1;
  InfoMain info2;
  InfoMain info3;

  def_info_arvore_2_3(&info1, "2", "2", "2");
  def_info_arvore_2_3(&info2, "3", "3", "3");
  def_info_arvore_2_3(&info3, "1", "1", "1");

  cria_no(&raiz, info1, NULL, NULL);
  adicionando_valor_em_arvore_2_3(raiz, &info2, NULL);

  Arvore_2_3 *new_node = NULL;
  InfoMain info_up;
  quebra_no(&raiz, &new_node, info3, &info_up, NULL);

  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("1", raiz->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);

  TEST_ASSERT_EQUAL_STRING("3", new_node->info1.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("3", new_node->info1.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("3", new_node->info1.arv_binaria_palavra_ingles->info.unidades->nome_unidade);

  TEST_ASSERT_EQUAL_STRING("2", info_up.palavra_portugues);
  TEST_ASSERT_EQUAL_STRING("2", info_up.arv_binaria_palavra_ingles->info.palavra_ingles);
  TEST_ASSERT_EQUAL_STRING("2", info_up.arv_binaria_palavra_ingles->info.unidades->nome_unidade);
}

// void test_show_arvore_2_3_caso_1()
// {
//   aloca_arvore_2_3(&raiz);
//   def(raiz, "Bus", "Onibus", "Unidade 1");

//   FILE *fp = freopen("output/test_show_arvore_2_3_caso_1.txt", "w", stdout);
//   show_arvore_2_3(raiz);
//   fclose(fp);
//   freopen("/dev/tty", "w", stdout);

//   FILE *f1 = fopen("output/test_show_arvore_2_3_caso_1.txt", "r");
//   char buffer[255];

//   char *expected[] = {
//       "Palavra em portugues: Onibus\n",
//       "Ingles: Bus\n",
//       "Apareceu em: Unidade 1\n"};

//   for (int i = 0; fgets(buffer, 255, f1) != NULL; i++)
//     TEST_ASSERT_EQUAL_STRING(expected[i], buffer);
// }

// void test_show_arvore_2_3_caso_2()
// {
//   aloca_arvore_2_3(&raiz);
//   def_arvore_2_3(raiz, "Bus", "Onibus", "Unidade 1");
//   def_arvore_2_3(raiz, "Car", "Carro", "Unidade 2");

//   FILE *fp = freopen("output/test_show_arvore_2_3_caso_2.txt", "w", stdout);
//   show_arvore_2_3(raiz);
//   fclose(fp);
//   freopen("/dev/tty", "w", stdout);

//   FILE *f1 = fopen("output/test_show_arvore_2_3_caso_2.txt", "r");
//   char buffer[255];

//   char *expected[] = {
//       "Palavra em portugues: Onibus\n",
//       "Ingles: Bus\n",
//       "Apareceu em: Unidade 1\n",
//       "Palavra em portugues: Carro\n",
//       "Ingles: Car\n",
//       "Apareceu em: Unidade 2\n"};

//   for (int i = 0; fgets(buffer, 255, f1) != NULL; i++)
//     TEST_ASSERT_EQUAL_STRING(expected[i], buffer);
// }