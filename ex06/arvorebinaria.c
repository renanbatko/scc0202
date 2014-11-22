#include "arvorebinaria.h"
#include <stdlib.h>
#include <stdio.h>

ARVORE_BINARIA *AB_CriarArvore() {
	ARVORE_BINARIA *new;
	new = (ARVORE_BINARIA *) malloc(sizeof(ARVORE_BINARIA));
	
	if (new != NULL) {
		new->pRaiz = NULL;
		
		return new;
	}
	
	return NULL;
}

NO *AB_CriarRaiz(ARVORE_BINARIA *pArvore, ITEM *pItem) {
	pArvore->pRaiz = (NO *) malloc(sizeof(NO));
	
	if (pArvore->pRaiz != NULL) {
		pArvore->pRaiz->pFilhoEsq = NULL;
		pArvore->pRaiz->pFilhoDir = NULL;
		pArvore->pRaiz->pItem = pItem;
		
		return pArvore->pRaiz;
	}
	
	return NULL;
}

void AB_ApagarArvore_aux(NO *raiz) {
	if (raiz != NULL) {
		AB_ApagarArvore_aux(raiz->pFilhoEsq);
		AB_ApagarArvore_aux(raiz->pFilhoDir);
		Item_Apagar(&(raiz->pItem));
		free(raiz);
	}
}

void AB_ApagarArvore(ARVORE_BINARIA **pArvore) {
	AB_ApagarArvore_aux((*pArvore)->pRaiz);
	free(*pArvore);
	*pArvore = NULL;
}

NO *AB_InserirFilho(int iFilho, NO *pNo, ITEM *pItem) {
	NO *new;
	new = (NO *) malloc(sizeof(NO));
	
	if (new != NULL) {
		new->pFilhoEsq = NULL;
		new->pFilhoDir = NULL;
		new->pItem = pItem;
		
		if (iFilho == FILHO_ESQ) {
			pNo->pFilhoEsq = new;
		}
		else {
			pNo->pFilhoDir = new;
		}
	}
	
	return new;
}

int AB_Vazia(ARVORE_BINARIA *pArvore) {
	return (pArvore == NULL || pArvore->pRaiz == NULL);
}

void AB_ImprimirEmOrdem_aux(NO *raiz) {
	if (raiz != NULL) {
		AB_ImprimirEmOrdem_aux(raiz->pFilhoEsq);
		Item_Imprimir(raiz->pItem);
		AB_ImprimirEmOrdem_aux(raiz->pFilhoDir);
	}
}

void AB_ImprimirEmOrdem(ARVORE_BINARIA *pArvore) {
	AB_ImprimirEmOrdem_aux(pArvore->pRaiz);
}

void AB_ImprimirPreOrdem_aux(NO *raiz) {
	if (raiz != NULL) {
		Item_Imprimir(raiz->pItem);
		AB_ImprimirPreOrdem_aux(raiz->pFilhoEsq);
		AB_ImprimirPreOrdem_aux(raiz->pFilhoDir);
	}
}

void AB_ImprimirPreOrdem(ARVORE_BINARIA *pArvore) {
	AB_ImprimirPreOrdem_aux(pArvore->pRaiz);
}

void AB_ImprimirPosOrdem_aux(NO *raiz) {
	if (raiz != NULL) {
		AB_ImprimirPosOrdem_aux(raiz->pFilhoEsq);
		AB_ImprimirPosOrdem_aux(raiz->pFilhoDir);
		Item_Imprimir(raiz->pItem);
	}
}

void AB_ImprimirPosOrdem(ARVORE_BINARIA *pArvore) {
	AB_ImprimirPosOrdem_aux(pArvore->pRaiz);
}

int AB_AlturaArvore_aux(NO *no) {
	if (no == NULL) return -1;
	int esq = AB_AlturaArvore_aux(no->pFilhoEsq);
	int dir = AB_AlturaArvore_aux(no->pFilhoDir);
	
	return ((esq > dir) ? esq : dir) + 1;
}

int AB_AlturaArvore(ARVORE_BINARIA *pArvore) {
	return AB_AlturaArvore_aux(pArvore->pRaiz);
}

int AB_AlturaNo(NO *pNo) {
	return AB_AlturaArvore_aux(pNo);
}

int AB_ProfundidadeNo(NO *pRaiz, NO *pNo);

void AB_CaminhoNos(NO *pRaiz, NO *pNoInicial, NO *pNoFinal);

int AB_ContarFolhas(NO *pRaiz) {
	if (pRaiz == NULL)
		return 0;
	if (pRaiz->pFilhoEsq == NULL && pRaiz->pFilhoDir == NULL)
		return 1;
	return AB_ContarFolhas(pRaiz->pFilhoEsq) + AB_ContarFolhas(pRaiz->pFilhoDir);
}

int AB_ContarNos(NO *pRaiz) {
	if (pRaiz == NULL)
		return 0;
	else
		return 1 + AB_ContarNos(pRaiz->pFilhoEsq) + AB_ContarNos(pRaiz->pFilhoDir);
}

int AB_MaiorElementoArvore(NO *pRaiz);

int AB_MenorElementoArvore(NO *pRaiz);

int AB_SomaElementosArvore_aux(NO *pRaiz) {
	if (pRaiz != NULL)
		return pRaiz->pItem->iValor + AB_SomaElementosArvore_aux(pRaiz->pFilhoEsq) + AB_SomaElementosArvore_aux(pRaiz->pFilhoDir);
	return 0;
}

int AB_SomaElementosArvore(NO *pRaiz) {
	if (pRaiz != NULL) {
		return AB_SomaElementosArvore_aux(pRaiz);
	}
	return 0;
}

