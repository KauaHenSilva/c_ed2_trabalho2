#include "Unity/unity.h"
#include "include/exibicao_valores.h"
#include "include/arvore_vermelho_preto.h"
#include "include/tratamento_de_arquivo.h"
#include "string.h"

ArvoreVermelhoPreto *raiz;

void setUp()
{
  raiz = NULL;
  ler_blocos(&raiz);
}

void tearDown()
{
  free_arvore_vermelho_preto(&raiz);
}

void test_exibir_arvore_vermelho_preto_por_unidade();

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_exibir_arvore_vermelho_preto_por_unidade);
  return UNITY_END();
}

void test_exibir_arvore_vermelho_preto_por_unidade()
{
  FILE *fp = freopen("output/test_exibir_arvore_vermelho_preto_por_unidade.txt", "w", stdout);
  exibir_arvore_vermelho_preto_por_unidade(raiz, "Unidade 1");
  fclose(fp);
  freopen("/dev/tty", "w", stdout);

  fp = fopen("output/test_exibir_arvore_vermelho_preto_por_unidade.txt", "r");
  char buffer[1024];

  char *experado[] = {
    "Palavra em ingles: Bus\n",
    "Palavra em portugues: barramento\n",
    "Palavra em ingles: Bike\n",
    "Palavra em portugues: bicicleta\n",
    "Palavra em ingles: Bug\n",
    "Palavra em portugues: inseto\n",
    "Palavra em ingles: Bus\n",
    "Palavra em portugues: onibus\n",
    "Palavra em ingles: Bug\n",
    "Palavra em portugues: problema\n",
    "Palavra em ingles: Network\n",
    "Palavra em portugues: rede de computadores\n",
    "Palavra em ingles: System\n",
    "Palavra em portugues: sistema\n",
    "Palavra em ingles: Coller\n",
    "Palavra em portugues: ventilador\n"
  };
  
  for (int i = 0; i < 16; i++)
    TEST_ASSERT_EQUAL_STRING(experado[i], fgets(buffer, 1024, fp));

}
