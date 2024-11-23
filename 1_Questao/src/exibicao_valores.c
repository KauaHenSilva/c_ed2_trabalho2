#include "include/exibicao_valores.h"
#include "include/utils.h"
#include "include/arvore_binaria.h"
// #include <string.h>
// #include <stdio.h>

// static int exibir_arvore_binaria_por_unidade(const ArvoreBinaria *raiz, const char *unidade, const char *plv_ptbr)
// {
//   int exibir = 0;

//   if (raiz)
//   {
//     exibir = exibir_arvore_binaria_por_unidade(raiz->esquerda, unidade, plv_ptbr);

//     if (buscar_lista_encadeada_unidade(raiz->info.unidades, unidade))
//     {
//       if (!exibir)
//         printf("Palavra em portugues: %s\n", plv_ptbr);
//       printf("Possivel traducao em ingles: %s\n", raiz->info.palavra_ingles);
//       // printf("Unidade: %s\n", raiz->nome_unidade); // Verificar se a unidade esta correta
//       exibir = 1;
//     }

//     exibir = exibir_arvore_binaria_por_unidade(raiz->direita, unidade, plv_ptbr) || exibir;
//   }

//   return exibir;
// }

// void exibir_arvore_vermelho_preto_por_unidade(const ArvoreVermelhoPreto *raiz, const char *unidade)
// {
//   if (raiz)
//   {
//     exibir_arvore_vermelho_preto_por_unidade(raiz->esq, unidade);
//     if (exibir_arvore_binaria_por_unidade(raiz->info.arv_binaria_palavra_ingles, unidade, raiz->info.palavra_portugues))
//       printf("\n");
//     exibir_arvore_vermelho_preto_por_unidade(raiz->dir, unidade);
//   }
// }

// void exibir_arvore_binaria_por_palavra_portugues(const ArvoreBinaria *raiz)
// {
//   if (raiz)
//   {
//     exibir_arvore_binaria_por_palavra_portugues(raiz->esquerda);
//     printf("Possivel traducao em ingles: %s\n", raiz->info.palavra_ingles);
//     exibir_arvore_binaria_por_palavra_portugues(raiz->direita);
//   }
// }

// void exibir_arvore_vermelho_preto_por_palavra_portugues(const ArvoreVermelhoPreto *raiz, const char *palavra)
// {
//   if (raiz)
//   {
//     exibir_arvore_vermelho_preto_por_palavra_portugues(raiz->esq, palavra);

//     if (strcmp(raiz->info.palavra_portugues, palavra) == 0)
//       exibir_arvore_binaria_por_palavra_portugues(raiz->info.arv_binaria_palavra_ingles);

//     exibir_arvore_vermelho_preto_por_palavra_portugues(raiz->dir, palavra);
//   }
// }