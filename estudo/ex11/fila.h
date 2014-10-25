#ifndef FILA_H
#define FILA_H
#define MAX 6

typedef struct queue fila;

fila *cria();

int add(fila *, int);

int remover(fila *);

void liberar(fila *);

int cheia(fila *);

int vazia(fila *);

void imprimir(fila *);

#endif

