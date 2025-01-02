#include "include/arvore_2_3.h"
#include <stdlib.h>
#include <stdio.h>

int criar_arvore_2_3(Arvore_2_3 **arvore, Informacao info, Arvore_2_3 *esquerda, Arvore_2_3 *meio)
{
  int confirm = 1;

  *arvore = (Arvore_2_3 *)malloc(sizeof(Arvore_2_3));
  if (*arvore)
  {
    (*arvore)->info1 = info;
    (*arvore)->esquerda = esquerda;
    (*arvore)->meio = meio;
    (*arvore)->qtd_info = 1;
  }
  else
  {
    printf("Impossível alocar memória para a árvore 2-3, abortando...\n");
    exit(1);
  }

  return confirm;
}

void free_arvore_2_3(Arvore_2_3 *arvore)
{
  if (arvore)
  {
    free_arvore_2_3(arvore->esquerda);
    free_arvore_2_3(arvore->meio);
    if (arvore->qtd_info == 2)
      free_arvore_2_3(arvore->direita);
    free(arvore);
  }
}

void show_arvore_2_3(Arvore_2_3 *raiz)
{
  if (raiz)
  {
    show_arvore_2_3(raiz->esquerda);
    printf("Info1: %d - %d - %c\n", raiz->info1.inicio, raiz->info1.final, raiz->info1.status);
    show_arvore_2_3(raiz->meio);
    if (raiz->qtd_info == 2)
    {
      printf("Info2: %d - %d - %c\n", raiz->info2.inicio, raiz->info2.final, raiz->info2.status);
      show_arvore_2_3(raiz->direita);
    }
  }
}

int adicionar_informacao(Arvore_2_3 *raiz, Informacao info, Arvore_2_3 *filho)
{
  if (info.inicio > raiz->info1.inicio)
  {
    raiz->info2 = info;
    raiz->direita = filho;
  }
  else
  {
    raiz->info2 = raiz->info1;
    raiz->info1 = info;
    raiz->direita = raiz->meio;
    raiz->meio = filho;
  }
  raiz->qtd_info = 2;
}

int eh_folha(Arvore_2_3 *raiz)
{
  return !raiz->esquerda;
}

int eh_info1(Arvore_2_3 raiz, int info)
{
  return raiz.info1.inicio == info;
}

int eh_info2(Arvore_2_3 raiz, int info)
{
  return raiz.qtd_info == 2 && raiz.info2.inicio == info;
}

Arvore_2_3 *arvore_2_3_buscar_menor_pai(Arvore_2_3 *raiz, int info)
{
  Arvore_2_3 *pai;
  pai = NULL;

  if (raiz != NULL)
  {
    if (!eh_info1(*raiz, info) && !eh_info2(*raiz, info))
    {
      if (info < raiz->info1.inicio)
        pai = arvore_2_3_buscar_menor_pai(raiz->esquerda, info);
      else if (raiz->qtd_info == 1 || info < raiz->info2.inicio)
        pai = arvore_2_3_buscar_menor_pai(raiz->meio, info);
      else
        pai = arvore_2_3_buscar_menor_pai(raiz->direita, info);

      if (pai == NULL && raiz->info1.inicio < info)
        pai = raiz;
    }
  }

  return pai;
}

Informacao *no23_maior_info(Arvore_2_3 *raiz)
{
  return raiz->qtd_info == 2 ? &raiz->info2 : &raiz->info1;
}

Arvore_2_3 *arvore_2_3_buscar_menor_filho(Arvore_2_3 *raiz, Arvore_2_3 **pai)
{
  Arvore_2_3 *filho;
  filho = raiz;

  while (!eh_folha(filho))
  {
    *pai = filho;
    filho = filho->esquerda;
  }

  return filho;
}

Arvore_2_3 *arvore_2_3_buscar_maior_filho(Arvore_2_3 *raiz, Arvore_2_3 **pai, Informacao **maior_valor)
{
  Arvore_2_3 *filho;
  filho = raiz;

  while (!eh_folha(filho))
  {
    *pai = filho;
    if (filho->qtd_info == 1)
      filho = filho->meio;
    else
      filho = filho->direita;
  }

  if (filho != NULL)
    *maior_valor = no23_maior_info(filho);

  return filho;
}

Arvore_2_3 *buscar_menor_bloco(Arvore_2_3 **raiz, Arvore_2_3 *no, Informacao *info, Informacao **valor_menor)
{
  Arvore_2_3 *menor, *pai;
  *valor_menor = NULL;

  if (eh_folha(no))
  {
    if (no->info1.inicio != info->inicio)
      menor = no;
    else
      menor = arvore_2_3_buscar_menor_pai(*raiz, info->inicio);
    
    if (menor != NULL)
      if (menor->qtd_info == 2 && menor->info2.inicio < info->inicio)
        *valor_menor = &(menor->info2);
      else
        *valor_menor = &(menor->info1);
  }
  else if (no->info1.inicio == info->inicio)
    menor = arvore_2_3_buscar_maior_filho(no->esquerda, &pai, valor_menor);
  else
    menor = arvore_2_3_buscar_maior_filho(no->meio, &pai, valor_menor);

  return menor;
}

Arvore_2_3 *buscar_maior_bloco(Arvore_2_3 **raiz, Arvore_2_3 *no, Informacao *info, Informacao **valor_maior)
{
  Arvore_2_3 *maior;
  Arvore_2_3 *pai;
  *valor_maior = NULL;

  if (eh_folha(no))
  {
    maior = Arvore_2_3_buscar_maior_pai(*raiz, info->inicio);
    if (maior != NULL)
      *valor_maior = no23_maior_info(maior);
  }
  else
  {
    if (no->info1.inicio == info->inicio)
      maior = arvore_2_3_buscar_menor_filho(no->meio, &pai);
    else
      maior = arvore_2_3_buscar_menor_filho(no->direita, &pai);

    if (maior != NULL)
      *valor_maior = &(maior->info1);
  }

  return maior;
}

void no_2_3_desalocar(Arvore_2_3 **no)
{
  free(*no);
  *no = NULL;
}

Arvore_2_3 *arvore_2_3_buscar_pai(Arvore_2_3 *raiz, int info)
{
  Arvore_2_3 *pai;
  pai = NULL;

  if (raiz != NULL)
  {
    if (!eh_info1(*raiz, info) && !eh_info2(*raiz, info))
    {
      if (info < raiz->info1.inicio)
        pai = arvore_2_3_buscar_pai(raiz->esquerda, info);
      else if (raiz->qtd_info == 1 || info < raiz->info2.inicio)
        pai = arvore_2_3_buscar_pai(raiz->meio, info);
      else
        pai = arvore_2_3_buscar_pai(raiz->direita, info);

      if (pai == NULL)
        pai = raiz;
    }
  }

  return pai;
}

Arvore_2_3 *Arvore_2_3_buscar_maior_pai(Arvore_2_3 *raiz, int info)
{
  Arvore_2_3 *pai;
  pai = NULL;

  if (raiz != NULL)
  {
    if (!eh_info1(*raiz, info) && !eh_info2(*raiz, info))
    {
      if (info < raiz->info1.inicio)
        pai = Arvore_2_3_buscar_maior_pai(raiz->esquerda, info);
      else if (raiz->qtd_info == 1 || info < raiz->info2.inicio)
        pai = Arvore_2_3_buscar_maior_pai(raiz->meio, info);
      else
        pai = Arvore_2_3_buscar_maior_pai(raiz->direita, info);

      if (pai == NULL && ((raiz->qtd_info == 1 && raiz->info1.inicio > info) || (raiz->qtd_info == 2 && raiz->info2.inicio > info)))
        pai = raiz;
    }
  }

  return pai;
}

static int movimento_onda(Informacao saindo, Informacao *entrada, Arvore_2_3 *pai, Arvore_2_3 **origem, Arvore_2_3 **raiz, Arvore_2_3 **maior, int (*funcao_remover)(Arvore_2_3 **, int, Arvore_2_3 *, Arvore_2_3 **, Arvore_2_3 **))
{
  int removeu = funcao_remover(raiz, saindo.inicio, pai, origem, maior);
  *entrada = saindo;
  return removeu;
}

static int calcular_altura(Arvore_2_3 *no)
{
  int altura = -1;

  if (no != NULL)
    altura = 1 + calcular_altura(no->esquerda);

  return altura;
}

static Arvore_2_3 *arvore_2_3_buscar_menor_pai_2_infos(Arvore_2_3 *raiz, int info)
{
  Arvore_2_3 *pai;
  pai = NULL;

  if (raiz != NULL)
  {
    if (!eh_info1(*raiz, info) && !eh_info2(*raiz, info))
    {
      if (info < raiz->info1.inicio)
        pai = arvore_2_3_buscar_menor_pai_2_infos(raiz->esquerda, info);
      else if (raiz->qtd_info == 1 || info < raiz->info2.inicio)
        pai = arvore_2_3_buscar_menor_pai_2_infos(raiz->meio, info);
      else
        pai = arvore_2_3_buscar_menor_pai_2_infos(raiz->direita, info);

      if (pai == NULL && raiz->qtd_info == 2 && raiz->info2.inicio < info)
        pai = raiz;
    }
  }

  return pai;
}

static int arvore_2_3_remover_no_interno1(Arvore_2_3 **origem, Arvore_2_3 *raiz, Informacao *info, Arvore_2_3 *filho1, Arvore_2_3 *filho2, Arvore_2_3 **maior)
{
  int removeu;
  Arvore_2_3 *filho, *pai;
  Informacao *info_filho;

  pai = raiz;

  filho = arvore_2_3_buscar_maior_filho(filho1, &pai, &info_filho);

  if (filho->qtd_info == 2)
  {
    *info = *info_filho;
    filho->qtd_info = 1;
  }
  else
  {
    filho = arvore_2_3_buscar_menor_filho(filho2, &pai);
    removeu = movimento_onda(filho->info1, info, pai, origem, &filho, maior, arvore_2_3_remover1);
  }

  return removeu;
}

static int arvore_2_3_remover_no_interno2(Arvore_2_3 **origem, Arvore_2_3 *raiz, Informacao *info, Arvore_2_3 *filho1, Arvore_2_3 *filho2, Arvore_2_3 **maior)
{
  int removeu;
  Arvore_2_3 *filho, *pai;
  Informacao *info_filho;

  pai = raiz;

  filho = arvore_2_3_buscar_menor_filho(filho1, &pai);

  if (filho->qtd_info == 2)
  {
    *info = filho->info1;
    filho->info1 = filho->info2;
    filho->qtd_info = 1;
  }
  else
  {
    filho = arvore_2_3_buscar_maior_filho(filho2, &pai, &info_filho);
    removeu = movimento_onda(*info_filho, info, pai, origem, &filho, maior, arvore_2_3_remover2);
  }

  return removeu;
}

int arvore_2_3_remover1(Arvore_2_3 **raiz, int info, Arvore_2_3 *pai, Arvore_2_3 **origem, Arvore_2_3 **maior)
{
  int removeu = 0;

  if (*raiz != NULL)
  {
    int info1 = eh_info1(**raiz, info);
    int info2 = eh_info2(**raiz, info);

    if (info1 || info2)
    {
      removeu = 1;
      if (eh_folha(*raiz))
      {
        if ((*raiz)->qtd_info == 2)
        {
          if (info1)
            (*raiz)->info1 = (*raiz)->info2;

          (*raiz)->qtd_info = 1;
        }
        else
        {
          if (pai == NULL)
            no_2_3_desalocar(raiz);
          else
          {
            Arvore_2_3 *pai_aux;
            Informacao info_pai;
            if (*raiz == pai->esquerda || (pai->qtd_info == 2 && *raiz == pai->meio))
            {
              pai_aux = arvore_2_3_buscar_pai(*origem, pai->info1.inicio);

              if (*raiz == pai->esquerda)
                info_pai = pai->info1;
              else
                info_pai = pai->info2;

              removeu = movimento_onda(info_pai, &((*raiz)->info1), pai_aux, origem, &pai, maior, arvore_2_3_remover1);
            }
            else // Filho do meio (com pai de 1 info) ou da direita
            {
              pai_aux = Arvore_2_3_buscar_maior_pai(*origem, (*raiz)->info1.inicio);

              Arvore_2_3 *menor_pai;
              menor_pai = arvore_2_3_buscar_menor_pai_2_infos(*origem, (*raiz)->info1.inicio);

              if (pai_aux != NULL)
              {
                if (pai_aux->info1.inicio > (*raiz)->info1.inicio)
                  info_pai = pai_aux->info1;
                else
                  info_pai = pai_aux->info2;
              }

              int altura_menor_pai = calcular_altura(menor_pai);
              int altura_pai_aux = calcular_altura(pai_aux);

              if (pai_aux == NULL || (pai_aux != pai && menor_pai != NULL && altura_menor_pai <= altura_pai_aux && info_pai.inicio > menor_pai->info2.inicio))
              {
                *maior = pai;
                (*raiz)->qtd_info = 0;
                removeu = -1;
              }
              else
              {
                Arvore_2_3 *avo;
                avo = arvore_2_3_buscar_pai(*origem, info_pai.inicio);
                removeu = movimento_onda(info_pai, &((*raiz)->info1), avo, origem, &pai_aux, maior, arvore_2_3_remover1);
              }
            }
          }
        }
      }
      else if (info2)
        removeu = arvore_2_3_remover_no_interno1(origem, *raiz, &((*raiz)->info2), (*raiz)->meio, (*raiz)->direita, maior);
      else if (info1)
        removeu = arvore_2_3_remover_no_interno1(origem, *raiz, &((*raiz)->info1), (*raiz)->esquerda, (*raiz)->meio, maior);
    }
    else
    {
      if (info < (*raiz)->info1.inicio)
        removeu = arvore_2_3_remover1(&(*raiz)->esquerda, info, *raiz, origem, maior);
      else if ((*raiz)->qtd_info == 1 || info < (*raiz)->info2.inicio)
        removeu = arvore_2_3_remover1(&(*raiz)->meio, info, *raiz, origem, maior);
      else
        removeu = arvore_2_3_remover1(&(*raiz)->direita, info, *raiz, origem, maior);
    }
  }
  return removeu;
}

int arvore_2_3_remover2(Arvore_2_3 **raiz, int info, Arvore_2_3 *pai, Arvore_2_3 **origem, Arvore_2_3 **maior)
{
  int removeu = 0;

  if (*raiz != NULL)
  {
    int info1 = eh_info1(**raiz, info);
    int info2 = eh_info2(**raiz, info);

    if (info1 || info2)
    {
      removeu = 1;
      if (eh_folha(*raiz))
      {
        if ((*raiz)->qtd_info == 2)
        {
          if (info1)
            (*raiz)->info1 = (*raiz)->info2;

          (*raiz)->qtd_info = 1;
        }
        else
        {
          if (pai == NULL)
            no_2_3_desalocar(raiz);
          else
          {
            Arvore_2_3 *pai_aux;
            Informacao info_pai;
            if (*raiz == pai->meio || (pai->qtd_info == 2 && *raiz == pai->direita))
            {
              pai_aux = arvore_2_3_buscar_pai(*origem, pai->info1.inicio);

              if (*raiz == pai->meio)
                info_pai = pai->info1;
              else
                info_pai = pai->info2;

              removeu = movimento_onda(info_pai, &((*raiz)->info1), pai_aux, origem, &pai, maior, arvore_2_3_remover2);
            }
            else // Filho da esquerda
            {
              pai_aux = arvore_2_3_buscar_menor_pai(*origem, (*raiz)->info1.inicio);

              Arvore_2_3 *menor_pai;
              menor_pai = arvore_2_3_buscar_menor_pai_2_infos(*origem, (*raiz)->info1.inicio);

              Arvore_2_3 *avo;
              if (pai_aux == NULL || (pai_aux != pai && menor_pai != NULL))
              {
                removeu = -1;
                *maior = pai;
              }
              else
              {
                if (pai_aux->qtd_info == 2 && pai_aux->info2.inicio < (*raiz)->info1.inicio)
                  info_pai = pai_aux->info2;
                else
                  info_pai = pai_aux->info1;

                avo = arvore_2_3_buscar_pai(*origem, info_pai.inicio);
                removeu = movimento_onda(info_pai, &((*raiz)->info1), avo, origem, &pai_aux, maior, arvore_2_3_remover2);
              }
            }
          }
        }
      }
      else if (info2)
        removeu = arvore_2_3_remover_no_interno2(origem, *raiz, &((*raiz)->info2), (*raiz)->direita, (*raiz)->meio, maior);
      else if (info1)
        removeu = arvore_2_3_remover_no_interno2(origem, *raiz, &((*raiz)->info1), (*raiz)->meio, (*raiz)->esquerda, maior);
    }
    else
    {
      if (info < (*raiz)->info1.inicio)
        removeu = arvore_2_3_remover2(&(*raiz)->esquerda, info, *raiz, origem, maior);
      else if ((*raiz)->qtd_info == 1 || info < (*raiz)->info2.inicio)
        removeu = arvore_2_3_remover2(&(*raiz)->meio, info, *raiz, origem, maior);
      else
        removeu = arvore_2_3_remover2(&(*raiz)->direita, info, *raiz, origem, maior);
    }
  }
  return removeu;
}

static Arvore_2_3 *no_2_3_juntar(Arvore_2_3 *filho1, Informacao info, Arvore_2_3 *maior, Arvore_2_3 **raiz)
{
  adicionar_informacao(filho1, info, maior);

  (*raiz)->qtd_info--;

  if ((*raiz)->qtd_info == 0)
    no_2_3_desalocar(raiz);

  return filho1;
}

static int balanceamento(Arvore_2_3 **raiz, Arvore_2_3 *filho1, Arvore_2_3 **filho2, Informacao info, Arvore_2_3 **maior)
{
  int balanceou = 0;
  if (*filho2 == NULL || (*filho2)->qtd_info == 0)
  {
    if (*filho2 != NULL)
      no_2_3_desalocar(filho2);

    *maior = no_2_3_juntar(filho1, info, *maior, raiz);
    balanceou = 1;
  }
  return balanceou;
}

static int possivel_remover(Arvore_2_3 *raiz)
{
  int possivel = 0;

  if (raiz != NULL)
  {
    possivel = raiz->qtd_info == 2;

    if (!possivel)
    {
      possivel = possivel_remover(raiz->meio);

      if (!possivel)
        possivel = possivel_remover(raiz->esquerda);
    }
  }

  return possivel;
}

int arvore_2_3_rebalancear(Arvore_2_3 **raiz, int info, Arvore_2_3 **maior)
{
  int balanceou = 0;
  if (*raiz != NULL)
  {
    if (!eh_folha(*raiz))
    {
      if (info < (*raiz)->info1.inicio)
        balanceou = arvore_2_3_rebalancear(&((*raiz)->esquerda), info, maior);
      else if ((*raiz)->qtd_info == 1 || info < (*raiz)->info2.inicio)
      {
        if ((*raiz)->esquerda->qtd_info == 2 && !possivel_remover((*raiz)->meio))
          balanceou = -1;
        else
          balanceou = arvore_2_3_rebalancear(&((*raiz)->meio), info, maior);
      }
      else
      {
        if ((*raiz)->meio->qtd_info == 2 && !possivel_remover((*raiz)->direita))
          balanceou = -1;
        else
          balanceou = arvore_2_3_rebalancear(&((*raiz)->direita), info, maior);
      }

      if (balanceou != -1)
      {
        if ((*raiz)->qtd_info == 1)
          balanceou = balanceamento(raiz, (*raiz)->esquerda, &((*raiz)->meio), (*raiz)->info1, maior);
        else if ((*raiz)->qtd_info == 2)
          balanceou = balanceamento(raiz, (*raiz)->meio, &((*raiz)->direita), (*raiz)->info2, maior);
      }
    }
  }

  return balanceou;
}

int arvore_2_3_remover(Arvore_2_3 **raiz, int info)
{
  Arvore_2_3 *maior, *posicao_juncao;
  int removeu = arvore_2_3_remover1(raiz, info, NULL, raiz, &posicao_juncao);

  if (removeu == -1)
  {
    removeu = 1;
    Informacao valor_juncao = *(no23_maior_info(posicao_juncao));
    maior = NULL;
    int removeu_aux = arvore_2_3_rebalancear(raiz, valor_juncao.inicio, &maior);

    if (removeu_aux == -1)
    {
      Arvore_2_3 *pai, *posicao_juncao2;
      Informacao *entrada;
      pai = arvore_2_3_buscar_pai(*raiz, valor_juncao.inicio);

      if (eh_info1(*posicao_juncao, valor_juncao.inicio))
        entrada = &(posicao_juncao->meio->info1);
      else
        entrada = &(posicao_juncao->direita->info1);

      removeu_aux = movimento_onda(valor_juncao, entrada, pai, raiz, &posicao_juncao, &posicao_juncao2, arvore_2_3_remover2);

      if (removeu_aux == -1)
      {
        valor_juncao = posicao_juncao2->info1;
        pai = arvore_2_3_buscar_pai(*raiz, valor_juncao.inicio);
        removeu_aux = movimento_onda(valor_juncao, &(posicao_juncao2->esquerda->info1), pai, raiz, &posicao_juncao2, &posicao_juncao, arvore_2_3_remover1);

        valor_juncao = *(no23_maior_info(posicao_juncao));
        maior = NULL;
        removeu_aux = arvore_2_3_rebalancear(raiz, valor_juncao.inicio, &maior);
      }
    }

    if (*raiz == NULL)
      *raiz = maior;
  }

  return removeu;
}

void concatenar_no(Arvore_2_3 **raiz, int *numero_final, int limite, int valor_remover)
{
  *numero_final = limite;
  arvore_2_3_remover(raiz, valor_remover);
}

// Em desenvolvimento, não está funcionando corretamente
void modificar_no(Arvore_2_3 **raiz, Arvore_2_3 *no, Informacao *info, int quant)
{
  Arvore_2_3 *menor;
  Informacao *valor_menor;

  menor = buscar_menor_bloco(raiz, no, info, &valor_menor);

  if (quant < quantidade_blocos_disponiveis(*info))
  {
    if (menor == NULL)
    {
      Informacao data;
      data.inicio = info->inicio;
      data.final = info->inicio + quant - 1;
      data.status = info->status == LIVRE ? OCUPADA : LIVRE;

      info->inicio += quant;
      set_inserir_arvore_2_3(raiz, data);
    }
    else
    {
      valor_menor->final += quant;
      info->inicio += quant;
    }
  }
  else
  {
    Arvore_2_3 *maior;
    Informacao *valor_maior;

    maior = buscar_maior_bloco(raiz, no, info, &valor_maior);

    if (menor == NULL && maior == NULL)
      trocar_status_da_memoria(&info->status);
    else
    {
      if (menor == NULL)
      {
        concatenar_no(raiz, &(info->final), valor_maior->final, valor_maior->inicio);
        info->status = !(info->status);
      }
      else if (maior == NULL)
        concatenar_no(raiz, &(valor_menor->final), info->final, info->inicio);
      else
      {
        int numero = valor_maior->inicio;
        concatenar_no(raiz, &(valor_menor->final), valor_maior->final, info->inicio);
        arvore_2_3_remover(raiz, numero);
      }
    }
  }
}

Arvore_2_3 *buscar_no_memoria(Arvore_2_3 **arvore, int quant, STATUS status, Informacao **info_escolhido)
{
  Arvore_2_3 *no;
  if (*arvore != NULL)
  {
    no = buscar_no_memoria(&((*arvore)->esquerda), quant, status, info_escolhido);

    if (*info_escolhido == NULL)
    {
      if ((*arvore)->info1.status == status && quantidade_blocos_disponiveis((*arvore)->info1) >= quant)
      {
        *info_escolhido = &((*arvore)->info1);
        no = *arvore;
      }
      else
      {
        no = buscar_no_memoria(&((*arvore)->meio), quant, status, info_escolhido);
        if ((*arvore)->qtd_info == 2)
        {
          if ((*arvore)->info2.status == status && quantidade_blocos_disponiveis((*arvore)->info2) >= quant)
          {
            *info_escolhido = &((*arvore)->info2);
            no = *arvore;
          }
          else if (*info_escolhido == NULL)
            no = buscar_no_memoria(&((*arvore)->direita), quant, status, info_escolhido);
        }
      }
    }
  }
  else
    *info_escolhido = NULL;

  return no;
}

void no23_exibir(Informacao info)
{
  printf("Inicio: %d\n", info.inicio);
  printf("Final: %d\n", info.final);
  printf("Status: %c\n", info.status);
}

int alocar_desalocar_no(Arvore_2_3 **arvore, int quant_nos, STATUS status)
{
  Informacao *info_escolhido;
  info_escolhido = NULL;
  Arvore_2_3 *no_escolhido;
  no_escolhido = buscar_no_memoria(arvore, quant_nos, status, &info_escolhido);

  if (info_escolhido != NULL)
    modificar_no(arvore, no_escolhido, info_escolhido, quant_nos);
  else
    printf("\nNão há nó disponível\n");
}

void quebra_no(Arvore_2_3 **raiz, Informacao info, Arvore_2_3 **novo_no, Informacao *info_para_cima, Arvore_2_3 *filho)
{
  if (info.inicio > (*raiz)->info2.inicio)
  {
    *info_para_cima = (*raiz)->info2;
    criar_arvore_2_3(novo_no, info, (*raiz)->direita, filho);
  }
  else if (info.inicio > (*raiz)->info1.inicio)
  {
    *info_para_cima = info;
    criar_arvore_2_3(novo_no, (*raiz)->info2, filho, (*raiz)->direita);
  }
  else
  {
    *info_para_cima = (*raiz)->info1;
    criar_arvore_2_3(novo_no, (*raiz)->info2, (*raiz)->meio, (*raiz)->direita);
    (*raiz)->info1 = info;
    (*raiz)->meio = filho;
  }
  (*raiz)->qtd_info = 1;
}

static int inserir_arvore_2_3(Arvore_2_3 **raiz, Informacao info, Informacao *promove, Arvore_2_3 **pai, Arvore_2_3 **new_node)
{
  int confirm = 0;
  *new_node = NULL;

  if (!*raiz)
    criar_arvore_2_3(raiz, info, NULL, NULL);
  else
  {
    if (eh_folha(*raiz))
    {
      if ((*raiz)->qtd_info == 1)
        confirm = adicionar_informacao(*raiz, info, NULL);
      else
      {
        quebra_no(raiz, info, new_node, promove, NULL);
        if (!(*pai))
        {
          criar_arvore_2_3(raiz, *promove, *raiz, *new_node);
          *new_node = NULL;
        }
      }
    }
    else
    {
      if (info.inicio < (*raiz)->info1.inicio)
        confirm = inserir_arvore_2_3(&(*raiz)->esquerda, info, promove, raiz, new_node);
      else if ((*raiz)->qtd_info == 1 || info.inicio < (*raiz)->info2.inicio)
        confirm = inserir_arvore_2_3(&(*raiz)->meio, info, promove, raiz, new_node);
      else
        confirm = inserir_arvore_2_3(&(*raiz)->direita, info, promove, raiz, new_node);

      if (*new_node)
      {
        if ((*raiz)->qtd_info == 1)
        {
          adicionar_informacao(*raiz, *promove, *new_node);
          *new_node = NULL;
        }
        else
        {
          Informacao promove_rec;
          quebra_no(raiz, *promove, new_node, &promove_rec, *new_node);
          *promove = promove_rec;

          if (!(*pai))
          {
            criar_arvore_2_3(raiz, promove_rec, *raiz, *new_node);
            *new_node = NULL;
          }
        }
      }
    }
  }

  return confirm;
}

int set_inserir_arvore_2_3(Arvore_2_3 **raiz, Informacao info)
{
  Informacao promove;
  Arvore_2_3 *pai = NULL, *new_node = NULL;
  return inserir_arvore_2_3(raiz, info, &promove, &pai, &new_node);
}
