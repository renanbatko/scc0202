#ifndef _FILAC_H_
#define _FILAC_H_
#define MAX 10

typedef struct queue fila;

fila *cria();

int entra(fila *, int);

int sai(fila *);

void libera(fila *);

int cheia(fila *);

int vazia(fila *);

void imprime(fila *);

#endif

