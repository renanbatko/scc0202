#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H

#define TAM_MAX 50 
#define TRUE 1 
#define FALSE 0
#define boolean int
#define inicio 0

typedef int tipo_chave;

typedef struct{ 
	tipo_chave codigo;
	char nome[50];
	int quantidade;
} livro;

typedef struct{ 
	livro Item[TAM_MAX];    
	int primeiro;
	int ultimo;
} lista_estatica;

void criar_lista(lista_estatica *lista);

int inserir_fim(lista_estatica *lista, livro *codigo);

int inserir_ordenado(lista_estatica *lista, livro *codigo);

boolean inserir_posicao(lista_estatica *lista, int pos, livro *codigo);

boolean remover_fim(lista_estatica *lista);

boolean remover_posicao(lista_estatica *lista, int pos);

int busca_sequencial(tipo_chave x, lista_estatica *lista);

int busca_ordenada(tipo_chave x, lista_estatica *lista);

int busca_binaria(tipo_chave x, lista_estatica *lista);

int tamanho(lista_estatica *lista);

boolean vazia(lista_estatica *lista);

boolean cheia(lista_estatica *lista);

void imprimir(lista_estatica *lista);
  
#endif
