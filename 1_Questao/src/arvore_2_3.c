#include "include/arvore_2_3.h"
#include "include/lista_encadeada.h"
#include "include/arvore_binaria.h"
#include "include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void def_info_arvore_2_3(InfoMain *info, char *plv_ingles, char *plv_portugues, char *nome_unidade)
{
  aloca_arvore_binaria(&info->arv_binaria_palavra_ingles);
  aloca_string(&info->palavra_portugues, tamanho_string(plv_portugues));
  def_arvore_binaria(info->arv_binaria_palavra_ingles, plv_ingles, nome_unidade);
  strcpy(info->palavra_portugues, plv_portugues);
}

void free_info_arvore_2_3(InfoMain *info)
{
  free_arvore_binaria(info->arv_binaria_palavra_ingles);
  free(info->palavra_portugues);
}

void copia_info_arvore_2_3(InfoMain *info_recebe, InfoMain *info_envia)
{
  copia_arvore_binaria(info_recebe->arv_binaria_palavra_ingles, info_envia->arv_binaria_palavra_ingles);
  aloca_string(&info_recebe->palavra_portugues, tamanho_string(info_envia->palavra_portugues));
  strcpy(info_recebe->palavra_portugues, info_envia->palavra_portugues);
}

void aloca_arvore_2_3(Arvore_2_3 **raiz)
{
  *raiz = (Arvore_2_3 *)malloc(sizeof(Arvore_2_3));
  (*raiz)->direita = NULL;
  (*raiz)->info1.arv_binaria_palavra_ingles = NULL;
  (*raiz)->info1.palavra_portugues = NULL;
  (*raiz)->info2.arv_binaria_palavra_ingles = NULL;
  (*raiz)->info2.palavra_portugues = NULL;
}

void no23_desalocar(Arvore_2_3 **no)
{
    free(*no);
    *no = NULL;
}


void free_arvore_2_3(Arvore_2_3 *raiz)
{
  if (raiz)
  {
    free_arvore_2_3(raiz->esquerda);
    free_arvore_2_3(raiz->centro);
    if (raiz->n_info == 2)
      free_arvore_2_3(raiz->direita);

    if (raiz->n_info == 2)
      free_info_arvore_2_3(&raiz->info2);
    free_info_arvore_2_3(&raiz->info1);

    free(raiz);
  }
}

void cria_no(Arvore_2_3 **new, InfoMain info, Arvore_2_3 *esquerda, Arvore_2_3 *centro)
{
  aloca_arvore_2_3(new);
  (*new)->info1 = info;
  (*new)->esquerda = esquerda;
  (*new)->centro = centro;
  (*new)->n_info = 1;
}

int eh_folha_arvore_2_3(Arvore_2_3 *raiz)
{
  int is_folha = 1;
  if (raiz->esquerda)
    is_folha = 0;
  return is_folha;
}

static int eh_info1(Arvore_2_3 no, char *info)
{
    return strcmp(info, no.info1.palavra_portugues) == 0;
}

static int eh_info2(Arvore_2_3 no, char *info)
{
    return no.n_info == 2 && strcmp(info, no.info2.palavra_portugues) == 0;
}

int adicionando_valor_em_arvore_2_3(Arvore_2_3 *raiz, InfoMain *info, Arvore_2_3 *filho)
{
  int is_add = 1;
  int comp = strcmp(raiz->info1.palavra_portugues, info->palavra_portugues);

  if (comp != 0)
  {
    if (comp < 0)
    {
      raiz->info2 = *info;
      raiz->direita = filho;
    }
    else
    {
      raiz->info2 = raiz->info1;
      raiz->info1 = *info;
      raiz->centro = filho;
    }

    raiz->n_info = 2;
  }
  else
    is_add = 0;

  return is_add;
}

void quebra_no(Arvore_2_3 **raiz, Arvore_2_3 **new_node, InfoMain info, InfoMain *info_up, Arvore_2_3 **filho)
{

  if (strcmp(info.palavra_portugues, (*raiz)->info2.palavra_portugues) > 0)
  {
    *info_up = (*raiz)->info2;
    if (*filho)
      cria_no(new_node, info, (*raiz)->direita, *filho);
    else
      cria_no(new_node, info, (*raiz)->direita, NULL);
  }
  else if (strcmp(info.palavra_portugues, (*raiz)->info1.palavra_portugues) > 0)
  {
    *info_up = info;
    if (*filho)
      cria_no(new_node, (*raiz)->info2, *filho, (*raiz)->direita);
    else
      cria_no(new_node, (*raiz)->info2, NULL, (*raiz)->direita);
  }
  else
  {
    *info_up = (*raiz)->info1;
    cria_no(new_node, (*raiz)->info2, (*raiz)->centro, (*raiz)->direita);
    (*raiz)->info1 = info;

    if (*filho)
      (*raiz)->centro = *filho;
  }

  (*raiz)->n_info = 1;
}

int value_equals(const Arvore_2_3 *raiz, const InfoMain *info)
{
  int equal = 0;
  if (strcmp(raiz->info1.palavra_portugues, info->palavra_portugues) == 0)
    equal = 1;
  else if ((raiz->n_info == 2) && strcmp(raiz->info2.palavra_portugues, info->palavra_portugues) == 0)
    equal = 2;
  return equal;
}

int inserir_valor_arvore_binaria(Arvore_2_3 **raiz, InfoMain info, int value_equals)
{
  int confirm = 1;

  ArvoreBinaria *new = NULL;
  aloca_arvore_binaria(&new);
  copia_arvore_binaria(new, info.arv_binaria_palavra_ingles);

  if (value_equals == 1)
    confirm = insercao_arvore_binaria(&(*raiz)->info1.arv_binaria_palavra_ingles, new);
  else if (value_equals == 2)
    confirm = insercao_arvore_binaria(&(*raiz)->info2.arv_binaria_palavra_ingles, new);
  else
    confirm = 0;

  return confirm;
}

static int _inserir_arvore_2_3(Arvore_2_3 **raiz, InfoMain info, InfoMain *promove, Arvore_2_3 **pai, Arvore_2_3 **new_node)
{
  InfoMain promove_rec;
  int confirm = 1, value_equal;

  if (!*raiz)
    cria_no(raiz, info, NULL, NULL);
  else if (value_equal = value_equals(*raiz, &info))
    confirm = inserir_valor_arvore_binaria(raiz, info, value_equal);
  else
  {
    if (eh_folha_arvore_2_3(*raiz))
    {
      if ((*raiz)->n_info == 1)
        confirm = adicionando_valor_em_arvore_2_3(*raiz, &info, NULL);
      else
      {
        Arvore_2_3 *filho = NULL;
        quebra_no(raiz, new_node, info, promove, &filho);
        if (!(*pai))
        {
          cria_no(raiz, *promove, *raiz, *new_node);
          new_node = NULL;
        }
      }
    }
    else
    {
      if (strcmp(info.palavra_portugues, (*raiz)->info1.palavra_portugues) < 0)
        confirm = _inserir_arvore_2_3(&(*raiz)->esquerda, info, promove, raiz, new_node);
      else if ((*raiz)->n_info == 1 || strcmp(info.palavra_portugues, (*raiz)->info2.palavra_portugues) < 0)
        confirm = _inserir_arvore_2_3(&(*raiz)->centro, info, promove, raiz, new_node);
      else
        confirm = _inserir_arvore_2_3(&(*raiz)->direita, info, promove, raiz, new_node);

      if (*new_node)
      {
        if ((*raiz)->n_info == 1)
        {
          adicionando_valor_em_arvore_2_3(*raiz, promove, *new_node);
          new_node = NULL;
        }
        else
        {
          quebra_no(raiz, new_node, *promove, &promove_rec, new_node);
          *promove = promove_rec;

          if (!(*pai))
          {
            cria_no(raiz, promove_rec, *raiz, *new_node);
            new_node = NULL;
          }
        }
      }
    }
  }

  return confirm;
}

int inserir_arvore_2_3(Arvore_2_3 **raiz, InfoMain info)
{
  Arvore_2_3 *pai;
  pai = NULL;
  Arvore_2_3 *new_node;
  new_node = NULL;
  InfoMain promove;
  return _inserir_arvore_2_3(raiz, info, &promove, &pai, &new_node);
}

static void show_info(const InfoMain *info)
{
  printf("Palavra em portugues: %s\n", info->palavra_portugues);
  show_arvore_binaria(info->arv_binaria_palavra_ingles);
}

/* Isso é em ordem, Utilize para deploymet */
void show_arvore_2_3(const Arvore_2_3 *raiz)
{
  if (raiz)
  {
    show_arvore_2_3(raiz->esquerda);
    show_info(&raiz->info1);

    show_arvore_2_3(raiz->centro);
    if (raiz->n_info == 2)
    {
      show_info(&raiz->info2);
      show_arvore_2_3(raiz->direita);
    }
  }
}


static InfoMain no23_maior_info(Arvore_2_3 *raiz)
{
    return raiz->n_info == 2 ? raiz->info2 : raiz->info1;
}


static Arvore_2_3 *arvore23_buscar_maior_filho(Arvore_2_3 *raiz, Arvore_2_3 **pai, InfoMain *maior_valor)
{
    Arvore_2_3 *filho;
    filho = raiz;

    while(!eh_folha_arvore_2_3(filho))
    {
        *pai = filho;
        if(filho->n_info == 1)
            filho = filho->centro;
        else
            filho = filho->direita;
    }

    if(filho != NULL)
        *maior_valor = no23_maior_info(filho);

    return filho;
}

static Arvore_2_3 *arvore23_buscar_menor_filho(Arvore_2_3 *raiz, Arvore_2_3 **pai)
{
    Arvore_2_3 *filho;
    filho = raiz;

    while(!eh_folha_arvore_2_3(filho))
    {
        *pai = filho;
        filho = filho->esquerda;
    }

    return filho;
}

static int movimento_onda(InfoMain saindo, InfoMain *entrada, Arvore_2_3 *pai, Arvore_2_3 **origem, Arvore_2_3 **raiz, Arvore_2_3 **maior, int (*funcao_remover)(Arvore_2_3 **, char *, Arvore_2_3 *, Arvore_2_3 **, Arvore_2_3 **))
{
    int removeu = funcao_remover(raiz, saindo.palavra_portugues, pai, origem, maior);
    *entrada = saindo;
    return removeu;
}

static Arvore_2_3 *arvore23_buscar_pai(Arvore_2_3 *raiz, char *info)
{
    Arvore_2_3 *pai;
    pai = NULL;

    if(raiz != NULL)
    {
        if(!eh_info1(*raiz, info) && !eh_info2(*raiz, info))
        {
            if (strcmp(info, raiz->info1.palavra_portugues) < 0)
                pai = arvore23_buscar_pai(raiz->esquerda, info);
            else if(raiz->n_info== 1 || (strcmp (info, raiz->info2.palavra_portugues) < 0))
                pai = arvore23_buscar_pai(raiz->centro, info);
            else
                pai = arvore23_buscar_pai(raiz->direita, info);

            if(pai == NULL)
                pai = raiz;
        }
    }

    return pai;
}

static Arvore_2_3 *arvore23_buscar_maior_pai(Arvore_2_3 *raiz, char *info)
{
    Arvore_2_3*  pai = NULL;

    if(raiz != NULL)
    {
        if(!eh_info1(*raiz, info) && !eh_info2(*raiz, info))
        {
            if (strcmp(info, raiz->info1.palavra_portugues) < 0)
                pai = arvore23_buscar_maior_pai(raiz->esquerda, info);
            else if(raiz->n_info == 1 || (strcmp(info, raiz->info2.palavra_portugues) < 0))
                pai = arvore23_buscar_maior_pai(raiz->centro, info);
            else
                pai = arvore23_buscar_maior_pai(raiz->direita, info);

            if(pai == NULL &&
             ((raiz->n_info == 1 && strcmp(raiz->info1.palavra_portugues, info) > 0 ||
              (raiz->n_info == 2 &&strcmp(raiz->info2.palavra_portugues, info) > 0))))
                pai = raiz;
        }
    }

    return pai;
}

static Arvore_2_3 *arvore23_buscar_menor_pai_2_infos(Arvore_2_3 *raiz, char *info)
{
    Arvore_2_3 *pai;
    pai = NULL;

    if(raiz != NULL)
    {
        if(!eh_info1(*raiz, info) && !eh_info2(*raiz, info))
        {
            if (strcmp(info, raiz->info1.palavra_portugues) < 0 )
                pai = arvore23_buscar_menor_pai_2_infos(raiz->esquerda, info);
            else if(raiz->n_info == 1 || (strcmp(info, raiz->info2.palavra_portugues) < 0))
                pai = arvore23_buscar_menor_pai_2_infos(raiz->centro, info);
            else
                pai = arvore23_buscar_menor_pai_2_infos(raiz->direita, info);

            if(pai == NULL && raiz->n_info == 2 && strcmp(raiz->info2.palavra_portugues, info) < 0)
                pai = raiz;
        }
    }

    return pai;
}

static Arvore_2_3 *arvore23_buscar_menor_pai(Arvore_2_3 *raiz, char *info)
{
    Arvore_2_3 *pai;
    pai = NULL;

    if(raiz != NULL)
    {
        if(!eh_info1(*raiz, info) && !eh_info2(*raiz, info))
        {
            if (strcmp(info, raiz->info1.palavra_portugues) < 0)
                pai = arvore23_buscar_menor_pai(raiz->esquerda, info);
            else if(raiz->n_info == 1 || strcmp(info, raiz->info2.palavra_portugues) < 0)
                pai = arvore23_buscar_menor_pai(raiz->centro, info);
            else
                pai = arvore23_buscar_menor_pai(raiz->direita, info);

            if(pai == NULL && strcmp(raiz->info1.palavra_portugues, info) < 0)
                pai = raiz;
        }
    }

    return pai;
}


int arvore23_remover_nao_folha1(Arvore_2_3 **origem, Arvore_2_3* raiz, InfoMain *info, Arvore_2_3 *filho1, Arvore_2_3 *filho2, Arvore_2_3 **maior)
{
    int removeu;
    Arvore_2_3 *filho, *pai;
    InfoMain info_filho;

    pai = raiz;

    filho = arvore23_buscar_maior_filho(filho1, &pai, &info_filho);

    if(filho->n_info == 2)
    {
        *info = info_filho;
        filho->n_info = 1;
        removeu = 1;
    }
    else
    {
        filho = arvore23_buscar_menor_filho(filho2, &pai);
        removeu = movimento_onda(filho->info1, info, pai, origem, &filho, maior, arvore23_remover1);
    }

    return removeu;
}

int arvore23_remover_nao_folha2(Arvore_2_3 **origem, Arvore_2_3* raiz, InfoMain *info, Arvore_2_3 *filho1, Arvore_2_3 *filho2, Arvore_2_3 **maior)
{
    int removeu;
    Arvore_2_3 *filho, *pai;
    InfoMain info_filho;

    pai = raiz;

    filho = arvore23_buscar_menor_filho(filho1, &pai);

    if(filho->n_info == 2)
    {
        *info = filho->info1;
        filho->info1 = filho->info2;
        filho->n_info = 1;
    }
    else
    {
        filho = arvore23_buscar_maior_filho(filho2, &pai, &info_filho);
        removeu = movimento_onda(info_filho, info, pai, origem, &filho, maior, arvore23_remover2);
    }

    return removeu;
}

int arvore23_remover1(Arvore_2_3 **raiz, char *info, Arvore_2_3 *pai, Arvore_2_3 **origem, Arvore_2_3 **maior)
{
  int removeu = 0;

  if (*raiz != NULL)
  {
    int info1 = eh_info1(**raiz, info);
    int info2 = eh_info2(**raiz, info);

    if (info1 || info2)
    {
      removeu = 1;
      if (eh_folha_arvore_2_3(*raiz))
      {
        if ((*raiz)->n_info == 2)
        {
          if (info1)
            (*raiz)->info1 = (*raiz)->info2;
          (*raiz)->n_info = 1;
        }
        else
        {
          if (pai == NULL)
            no23_desalocar(raiz);
          else
          {
            Arvore_2_3 *pai_aux;
            InfoMain info_pai;
            if (*raiz == pai->esquerda || (pai->n_info == 2 && *raiz == pai->centro))
            {
              pai_aux = arvore23_buscar_pai(*origem, pai->info1.palavra_portugues);

              if (*raiz == pai->esquerda)
                info_pai = pai->info1;
              else
                info_pai = pai->info2;

              removeu = movimento_onda(info_pai, &((*raiz)->info1), pai_aux, origem, &pai, maior, arvore23_remover1);
            }
            else
            {
              pai_aux = arvore23_buscar_maior_pai(*origem, (*raiz)->info1.palavra_portugues);

              Arvore_2_3 *menor_pai;
              menor_pai = arvore23_buscar_menor_pai_2_infos(*origem, (*raiz)->info1.palavra_portugues);

              if (pai_aux == NULL || (pai_aux != pai && menor_pai != NULL))
              {
                *maior = pai;
                (*raiz)->n_info = 0;
                removeu = -1;
              }
              else
              {
                if (strcmp(pai_aux->info1.palavra_portugues, (*raiz)->info1.palavra_portugues) > 0)
                  info_pai = pai_aux->info1;
                else
                  info_pai = pai_aux->info2;

                Arvore_2_3 *avo;
                avo = arvore23_buscar_pai(*origem, info_pai.palavra_portugues);
                removeu = movimento_onda(info_pai, &((*raiz)->info1), avo, origem, &pai_aux, maior, arvore23_remover1);
              }
            }
          }
        }
      }
      else if (info2)
        removeu = arvore23_remover_nao_folha1(origem, *raiz, &((*raiz)->info2), (*raiz)->centro, (*raiz)->direita, maior);
      else if (info1)
        removeu = arvore23_remover_nao_folha1(origem, *raiz, &((*raiz)->info1), (*raiz)->esquerda, (*raiz)->centro, maior);
    }
    else
    {
      if (strcmp(info, (*raiz)->info1.palavra_portugues) < 0)
        removeu = arvore23_remover1(&(*raiz)->esquerda, info, *raiz, origem, maior);
      else if ((*raiz)->n_info == 1 || (strcmp(info, (*raiz)->info2.palavra_portugues) < 0))
        removeu = arvore23_remover1(&(*raiz)->centro, info, *raiz, origem, maior);
      else
        removeu = arvore23_remover1(&(*raiz)->direita, info, *raiz, origem, maior);
    }
  }
  return removeu;
}

int arvore23_remover2(Arvore_2_3 **raiz, char *info, Arvore_2_3 *pai, Arvore_2_3 **origem, Arvore_2_3 **maior)
{
  int removeu = 0;

  if (*raiz != NULL)
  {
    int info1 = eh_info1(**raiz, info);
    int info2 = eh_info2(**raiz, info);

    if (info1 || info2)
    {
      removeu = 1;
      if (eh_folha_arvore_2_3(*raiz))
      {
        if ((*raiz)->n_info == 2)
        {
          if (info1)
            (*raiz)->info1 = (*raiz)->info2;

          (*raiz)->n_info = 1;
        }
        else
        {
          if (pai == NULL)
            no23_desalocar(raiz);
          else
          {
            Arvore_2_3 *pai_aux;
            InfoMain info_pai;
            if (*raiz == pai->centro || (pai->n_info == 2 && *raiz == pai->direita))
            {
              pai_aux = arvore23_buscar_pai(*origem, pai->info1.palavra_portugues);

              if (*raiz == pai->centro)
                info_pai = pai->info1;
              else
                info_pai = pai->info2;

              removeu = movimento_onda(info_pai, &((*raiz)->info1), pai_aux, origem, &pai, maior, arvore23_remover2);
            }
            else
            {
              pai_aux = arvore23_buscar_menor_pai(*origem, (*raiz)->info1.palavra_portugues);

              Arvore_2_3 *menor_pai;
              menor_pai = arvore23_buscar_menor_pai_2_infos(*origem, (*raiz)->info1.palavra_portugues);

              Arvore_2_3 *avo;
              if (pai_aux == NULL || (pai_aux != pai && menor_pai != NULL))
              {
                removeu = -1;
                *maior = pai;
              }
              else
              {
                if (pai_aux->n_info == 2 && pai_aux->info2.palavra_portugues < (*raiz)->info1.palavra_portugues)
                  info_pai = pai_aux->info2;
                else
                  info_pai = pai_aux->info1;

                avo = arvore23_buscar_pai(*origem, info_pai.palavra_portugues);
                removeu = movimento_onda(info_pai, &((*raiz)->info1), avo, origem, &pai_aux, maior, arvore23_remover2);
              }
            }
          }
        }
      }
      else if (info2)
        removeu = arvore23_remover_nao_folha2(origem, *raiz, &((*raiz)->info2), (*raiz)->direita, (*raiz)->centro, maior);
      else if (info1)
        removeu = arvore23_remover_nao_folha2(origem, *raiz, &((*raiz)->info1), (*raiz)->centro, (*raiz)->esquerda, maior);
    }
    else
    {
      if (strcmp(info, (*raiz)->info1.palavra_portugues) < 0)
        removeu = arvore23_remover2(&(*raiz)->esquerda, info, *raiz, origem, maior);
      else if ((*raiz)->n_info == 1 || (strcmp(info, (*raiz)->info2.palavra_portugues) < 0))
        removeu = arvore23_remover2(&(*raiz)->centro, info, *raiz, origem, maior);
      else
        removeu = arvore23_remover2(&(*raiz)->direita, info, *raiz, origem, maior);
    }
  }
  return removeu;
}

int possivel_remover(Arvore_2_3 *raiz)
{
    int possivel = 0;

    if(raiz != NULL)
    {
        possivel = raiz->n_info == 2;

        if(!possivel)
        {
            possivel = possivel_remover(raiz->centro);

            if(!possivel)
                possivel = possivel_remover(raiz->esquerda);
        }
    }

    return possivel;
}

Arvore_2_3 *no23_juntar(Arvore_2_3 *filho1, InfoMain info, Arvore_2_3 *maior, Arvore_2_3 **raiz)
{
    adicionando_valor_em_arvore_2_3(filho1, &info, maior);

    (*raiz)->n_info--;

    if((*raiz)->n_info == 0)
        no23_desalocar(raiz);

    return filho1;
}

static int balanceamento(Arvore_2_3 **raiz, Arvore_2_3 *filho1, Arvore_2_3 **filho2, InfoMain info, Arvore_2_3 **maior)
{
    int balanceou = 0;
    if(*filho2 == NULL || (*filho2)->n_info == 0)
    {
        if(*filho2 != NULL)
            no23_desalocar(filho2);

        *maior = no23_juntar(filho1, info, *maior, raiz);
        balanceou = 1;
    }
    return balanceou;
}

int arvore23_rebalancear(Arvore_2_3 **raiz, char *info, Arvore_2_3 **maior)
{
    int balanceou = 0;
    if(*raiz != NULL)
    {
        if(!eh_folha_arvore_2_3(*raiz))
        {
            if (strcmp(info, (*raiz)->info1.palavra_portugues) < 0)
                balanceou = arvore23_rebalancear(&((*raiz)->esquerda), info, maior);
            else if((*raiz)->n_info == 1 || (strcmp(info, (*raiz)->info2.palavra_portugues) < 0))
            {
                if((*raiz)->esquerda->n_info == 2 && !possivel_remover((*raiz)->centro))
                    balanceou = -1;
                else
                    balanceou = arvore23_rebalancear(&((*raiz)->centro), info, maior);
            }
            else
            {
                if((*raiz)->centro->n_info == 2 && !possivel_remover((*raiz)->direita))
                    balanceou = -1;
                else
                    balanceou = arvore23_rebalancear(&((*raiz)->direita), info, maior);
            }

            if(balanceou != -1)
            {
                if((*raiz)->n_info == 1)
                    balanceou = balanceamento(raiz, (*raiz)->esquerda, &((*raiz)->centro), (*raiz)->info1, maior);
                else if((*raiz)->n_info == 2)
                    balanceou = balanceamento(raiz, (*raiz)->centro, &((*raiz)->direita), (*raiz)->info2, maior);
            }
            
        }
    }

    return balanceou;
}


int arvore_2_3_remover(Arvore_2_3 **raiz, char *info)
{
  Arvore_2_3 *maior, *posicao_juncao;
  int removeu = arvore23_remover1(raiz, info, NULL, raiz, &posicao_juncao);

  if (removeu == -1)
  {
    InfoMain valor_juncao = no23_maior_info(posicao_juncao);
    maior = NULL;
    removeu = arvore23_rebalancear(raiz, valor_juncao.palavra_portugues, &maior);

    if (removeu == -1)
    {
      Arvore_2_3 *pai, *posicao_juncao2;
      InfoMain *entrada;
      pai = arvore23_buscar_pai(*raiz, valor_juncao.palavra_portugues);

      if (eh_info1(*posicao_juncao, valor_juncao.palavra_portugues))
        entrada = &(posicao_juncao->centro->info1);
      else
        entrada = &(posicao_juncao->direita->info1);

      removeu = movimento_onda(valor_juncao, entrada, pai, raiz, &posicao_juncao, &posicao_juncao2, arvore23_remover2);

      if (removeu == -1)
      {
        valor_juncao = posicao_juncao2->info1;
        pai = arvore23_buscar_pai(*raiz, valor_juncao.palavra_portugues);
        removeu = movimento_onda(valor_juncao, &(posicao_juncao2->esquerda->info1), pai, raiz, &posicao_juncao2, &posicao_juncao, arvore23_remover1);

        valor_juncao = no23_maior_info(posicao_juncao);
        maior = NULL;
        removeu = arvore23_rebalancear(raiz, valor_juncao.palavra_portugues, &maior);
      }
    }

    if (*raiz == NULL)
      *raiz = maior;
  }

  return removeu;
}