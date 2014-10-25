#ifndef FILADIM_H
#define FILADIM_H

typedef struct cel no;

typedef struct queue fila;

fila *create();

int entra(fila *, int);

int sai(fila *);

void destroy(fila *);

int empty(fila *);

void print(fila *);

#endif

