#ifndef LDE_H
#define LDE_H

typedef struct cel celula;

celula *cria();

void libera(celula *);

void insere(celula *, int);

void imprime(celula *);

int maior(celula *, int);

#endif
