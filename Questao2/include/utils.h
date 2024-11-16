#pragma once

int tamanho_string(char *string);
int aloca_string(char **string, int tamanho);
int nome_presente(const char *nome_procurar,const char *nomes);
void juntar_nome_por_virgula(char *nome_antigo, char *nome_novo, char **juncao);
void remover_virgula(char *palavra);