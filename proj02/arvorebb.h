#ifndef _ARVOREBB_H_
#define	_ARVOREBB_H_

#include <stdlib.h>
#include <stdio.h>
#include "item.h"

#define FILHO_ESQ 0
#define FILHO_DIR 1

typedef struct arvore_binaria ARVORE_BINARIA;
typedef struct no NO;

struct no {
	ITEM *item;
	NO *filhoesq;
	NO *filhodir;
};

struct arvore_binaria {
	NO *raiz;
};

ARVORE_BINARIA *criar_arvore();

NO *criar_raiz(ARVORE_BINARIA *, ITEM *);

NO *inserir_filho(int, NO *, ITEM *);

int inserir(ARVORE_BINARIA *, ITEM *);

ITEM *busca(ARVORE_BINARIA *, int);

int vazia(ARVORE_BINARIA *);

#endif
