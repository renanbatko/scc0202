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

ARVORE_BINARIA *AB_CriarArvore();

NO *criar_raiz(ARVORE_BINARIA *pArvore, ITEM *pItem);

int inserir(ARVORE_BINARIA *arvore, ITEM item);

int inserir_aux(NO *raiz, ITEM item);

NO *inserir_filho(int filho, NO *no, ITEM item);

ITEM *busca_aux(NO *raiz, int chave);

ITEM *busca(ARVORE_BINARIA *arvore, int chave);

int vazia(ARVORE_BINARIA *ab);

void emordem(ARVORE_BINARIA *arvore);

void emordem_aux(NO *raiz);

#endif
