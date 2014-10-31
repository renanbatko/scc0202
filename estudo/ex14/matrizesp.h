#ifndef MATRIZESP_H
#define MATRIZESP_H

typedef struct cel celula;

typedef struct matrix matriz;

matriz *criar(int, int);

void liberar(matriz *);

int set(matriz *, int, int, int);

int get(matriz *, int, int);

void remover(matriz *, int, int);

#endif
