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
	
	if (filho == FILHO_ESQ) {
		no->filhoesq = pnovo;
	}
	else {
		no->filhodir = pnovo;
	}
	
	return pnovo;
}

int inserir_aux(NO *raiz, ITEM *item) {
	if (raiz->item->chave > item->chave) {
		if (raiz->filhoesq != NULL) {
			return inserir_aux(raiz->filhoesq, item);
		}
		else {
			return (inserir_filho(FILHO_ESQ, raiz, item) != NULL);
		}
	}
	else if (raiz->item->chave < item->chave){
		if (raiz->filhodir != NULL) {
			return inserir_aux(raiz->filhodir, item);
		}
		else {
			return (inserir_filho(FILHO_DIR, raiz, item) != NULL);
		}
	}
	else {
		return 0;
	}
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

void em_ordem_aux(NO *raiz) {
	if (raiz != NULL) {
		em_ordem_aux(raiz->filhoesq);
		imprimir_item(raiz->item);
		em_ordem_aux(raiz->filhodir);
	}
}

void em_ordem(ARVORE_BINARIA *arvore) {
	em_ordem_aux(arvore->raiz);
}


