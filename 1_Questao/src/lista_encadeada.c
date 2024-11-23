#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/lista_encadeada.h"
#include "include/utils.h"

void aloca_lista_encadeada_unidade(ListaEncadeadaUnidade **lista)
{
  *lista = (ListaEncadeadaUnidade *)malloc(sizeof(ListaEncadeadaUnidade));
  (*lista)->nome_unidade = NULL;
  (*lista)->prox = NULL;
}

void def_lista_encadeada_unidade(ListaEncadeadaUnidade *lista, const char *nome_unidade)
{
  aloca_string(&lista->nome_unidade, tamanho_string(nome_unidade));
  strcpy(lista->nome_unidade, nome_unidade);
}

void copia_lista_encadeada_unidade(ListaEncadeadaUnidade *recebe, ListaEncadeadaUnidade *envia)
{
  if (envia)
  {
    def_lista_encadeada_unidade(recebe, envia->nome_unidade);
    copia_lista_encadeada_unidade(recebe->prox, envia->prox);
  }
}

void show_lista_encadeada_unidade(const ListaEncadeadaUnidade *lista)
{
  if (lista)
  {
    if (lista->prox)
      printf("%s, ", lista->nome_unidade);
    else
      printf("%s", lista->nome_unidade);
    show_lista_encadeada_unidade(lista->prox);
  }
  else
    printf("\n");
}

int buscar_lista_encadeada_unidade(const ListaEncadeadaUnidade *lista, const char *nome_unidade)
{
  int confirmacao = 0;
  if (lista)
  {
    if (strcmp(lista->nome_unidade, nome_unidade) == 0)
      confirmacao = 1;
    else
      confirmacao = buscar_lista_encadeada_unidade(lista->prox, nome_unidade);
  }
  return confirmacao;
}

void free_lista_encadeada_unidade(ListaEncadeadaUnidade **lista)
{
  if (*lista)
  {
    free_lista_encadeada_unidade(&(*lista)->prox);
    free((*lista)->nome_unidade);
    free(*lista);
    *lista = NULL;
  }
}

int inserir_lista_encadeada_unidade(ListaEncadeadaUnidade **lista, char *nome)
{
  int confirmacao = 1;
  if (!buscar_lista_encadeada_unidade(*lista, nome))
  {
    ListaEncadeadaUnidade *new;
    aloca_lista_encadeada_unidade(&new);
    def_lista_encadeada_unidade(new, nome);
    new->prox = *lista;
    *lista = new;
  }
  else
    confirmacao = 0;

  return confirmacao;
}

int remover_lista_encadeada_unidade(ListaEncadeadaUnidade **lista, const char *nome)
{
  int confirmacao = 0;
  if (*lista)
  {
    if (strcmp((*lista)->nome_unidade, nome) == 0)
    {
      ListaEncadeadaUnidade *aux = *lista;
      *lista = (*lista)->prox;
      free(aux->nome_unidade);
      free(aux);
      confirmacao = 1;
    }
    else
      confirmacao = remover_lista_encadeada_unidade(&(*lista)->prox, nome);
  }
  return confirmacao;
}