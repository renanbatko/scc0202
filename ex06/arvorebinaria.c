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

void AB_ApagarArvore(ARVORE_BINARIA **pArvore);

NO *AB_InserirFilho(int iFilho, NO *pNo, ITEM *pItem);

int AB_Vazia(ARVORE_BINARIA *pArvore);

void AB_ImprimirEmOrdem(ARVORE_BINARIA *pArvore);

void AB_ImprimirPreOrdem(ARVORE_BINARIA *pArvore);

void AB_ImprimirPosOrdem(ARVORE_BINARIA *pArvore);

int AB_AlturaArvore(ARVORE_BINARIA *pArvore);

int AB_AlturaNo(NO *pNo);

int AB_ProfundidadeNo(NO *pRaiz, NO *pNo);

void AB_CaminhoNos(NO *pRaiz, NO *pNoInicial, NO *pNoFinal);

int AB_ContarFolhas(NO *pRaiz);

int AB_ContarNos(NO *pRaiz);

int AB_MaiorElementoArvore(NO *pRaiz);

int AB_MenorElementoArvore(NO *pRaiz);

int AB_SomaElementosArvore(NO *pRaiz);

