#ifndef LISTAENCAD_H
#define LISTAENCAD_H

typedef struct cel celula;

celula *cria();

void insere(celula *, int);

void remover(celula *);

void busca_remove(celula *, int);

void busca_insere(celula *, int, int);

void imprime(celula *);

int seek(celula *, int);

#endif

