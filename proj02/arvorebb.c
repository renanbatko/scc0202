#include "arvorebb.h"
#include <stdlib.h>
#include <stdio.h>

ARVORE_BINARIA *criar_arvore() {
	ARVORE_BINARIA *nova;
	nova = (ARVORE_BINARIA *) malloc(sizeof(ARVORE_BINARIA));
	
	if (nova != NULL) {
		nova->raiz = NULL;
	}
	
	return nova;
}

NO *criar_raiz(ARVORE_BINARIA *arvore, ITEM *item) {
	arvore->raiz = (NO *) malloc(sizeof(NO));
	
	if (arvore->raiz != NULL) {
		arvore->raiz->filhoesq = NULL;
		arvore->raiz->filhodir = NULL;
		arvore->raiz->item = item;
	}
	
	return arvore->raiz;
}

NO *inserir_filho(int filho, NO *no, ITEM *item) {
	NO *pnovo;
	pnovo = (NO *) malloc(sizeof(NO));
	
	if (pnovo != NULL) {
		pnovo->filhoesq = NULL;
		pnovo->filhodir = NULL;
		pnovo->item = item;
	}
	
	if (filho == FILHOESQ) {
		no->filhoesq = pnovo;
	}
	else {
		no->filhodir = pnovo;
	}
	
	return pnovo;
}

int inserir_aux(NO *raiz, ITEM *item) {
	
}

int inserir(ARVORE_BINARIA *arvore, ITEM *item) {
	if (vazia(arvore)) {
		return (criar_raiz(arvore, item) != NULL);
	}
	else {
		return inserir_aux(arvore->raiz, item);
	}
}

ITEM *busca(ARVORE_BINARIA *, int);

int vazia(ARVORE_BINARIA *arvore) {
	return (arvore->raiz == NULL);
}

