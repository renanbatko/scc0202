#include "arvorebb.h"
#include "item.h"
#include <stdlib.h>
#include <stdio.h>

ARVORE_BINARIA *AB_CriarArvore() {
    ARVORE_BINARIA *ab = (ARVORE_BINARIA *) malloc(sizeof(ARVORE_BINARIA));

    if (ab != NULL) {
        ab->raiz = NULL;
	}

	return ab;
}

NO *criar_raiz(ARVORE_BINARIA *arvore, ITEM *item) {
    arvore->raiz = (NO *) malloc(sizeof (NO));
    
    if (arvore->raiz != NULL) {
		arvore->raiz->filhodir = NULL;
		arvore->raiz->filhoesq = NULL;
		arvore->raiz->item = item;
	}
	
	return arvore->raiz;
}

int inserir(ARVORE_BINARIA *arvore, ITEM item) {
	if (vazia(arvore)) {
		return (criar_raiz(arvore, &item) != NULL);
 	}
	else {
 		return inserir_aux(arvore->raiz, item);
 	}
}

NO *inserir_filho(int filho, NO *no, ITEM item) {
	NO *pnovo = (NO *) malloc(sizeof (NO));

	if (pnovo != NULL) {
		pnovo->filhodir = NULL;
		pnovo->filhoesq = NULL;
		pnovo->item = &item;
		if (filho == FILHO_ESQ) {
			no->filhoesq = pnovo;
		}
		else {
			no->filhodir = pnovo;
		}
	}
	return pnovo;
}

int inserir_aux(NO *raiz, ITEM item) {
	if (raiz->item->chave > item.chave) {
		if (raiz->filhoesq != NULL) {
 			return inserir_aux(raiz->filhoesq, item);
 		}
		else {
 			return (inserir_filho(FILHO_ESQ, raiz, item) != NULL);
 		}
 	}
	else if (raiz->item->chave < item.chave) {
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
 
ITEM *busca_aux(NO *raiz, int chave) {
	if (raiz == NULL) {
		return NULL;
 	}
	else {
		if (raiz->item->chave > chave) {
			return busca_aux(raiz->filhoesq, chave);
 		}
		else if (raiz->item->chave < chave) {
			return busca_aux(raiz->filhodir, chave);
 		}
		else {
			return raiz->item;
 		}
 	}
}

ITEM *busca(ARVORE_BINARIA *arvore, int chave) {
	return busca_aux(arvore->raiz, chave);
}

int vazia(ARVORE_BINARIA *ab) {
	return (ab->raiz == NULL || ab == NULL);
}

void emordem(ARVORE_BINARIA *arvore) {
	emordem_aux(arvore->raiz);
}

void emordem_aux(NO *raiz) {
	if (raiz != NULL) {
		emordem_aux(raiz->filhoesq);
		imprimir_item(raiz->item);
		emordem_aux(raiz->filhodir);
	}
}
