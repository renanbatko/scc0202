#ifndef PILHAEST_H
#define PILHAEST_H
#define MAX 10

typedef struct stack pilha;

pilha *criar();

void apagar(pilha *);

int empilhar(pilha *, int);

int desempilhar(pilha *);

int topo(pilha *);

int tamanho(pilha *);

int vazia(pilha *);

int cheia(pilha *);

void imprimir(pilha *);

#endif

