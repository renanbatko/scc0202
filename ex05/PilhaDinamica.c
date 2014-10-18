#include "PilhaDinamica.h"
#include <stdlib.h>
#include <stdio.h>

PILHA_DINAMICA *PilhaDinamica_CriarPilha() {
	PILHA_DINAMICA *new;
	new = (PILHA_DINAMICA *) malloc(sizeof(PILHA_DINAMICA));
	
	if (new != NULL) {
		new->iTamanho = 0;
		new->pTopo = NULL;
		
		return new;
	}
	
	return NULL;
}

void PilhaDinamica_ApagarPilha(PILHA_DINAMICA **pPilha) {
	NO *p;
	NO *q;
	p = (*pPilha)->pTopo;
	q = NULL;
	
	while (p != NULL) {
		q = p;
		free(q);
		p = p->pAnterior;
	}
	
	free(*pPilha);
}

void PilhaDinamica_ApagarNo(NO *pNo) {
	
}

BOOLEAN PilhaDinamica_Empilhar(PILHA_DINAMICA *pPilha, ITEM *pItem) {
	NO *new;
	new = (NO *) malloc(sizeof(NO));
	
	if (new != NULL) {
		new->pItem = pItem;
		//Item_Imprimir(new->pItem);
		new->pAnterior = pPilha->pTopo;
		pPilha->pTopo = new;
		pPilha->iTamanho++;
		
		return TRUE;
	}
	
	return FALSE;
}

ITEM *PilhaDinamica_Desempilhar(PILHA_DINAMICA *pPilha) {
	if (PilhaDinamica_Vazia(pPilha)) {
		return NULL;
	}
	
	ITEM *item;
	item = (ITEM *) malloc(sizeof(ITEM));
	
	item = pPilha->pTopo->pItem;
	
	NO *morta;
	morta = pPilha->pTopo;
	//pPilha->pTopo->pAnterior = ;
	pPilha->iTamanho--;
	free(morta);
	
	return item;
}

ITEM *PilhaDinamica_Topo(PILHA_DINAMICA *pPilha) {
	if (PilhaDinamica_Vazia(pPilha)) {
		return NULL;
	}
	
	return pPilha->pTopo->pItem;
}

BOOLEAN PilhaDinamica_Vazia(PILHA_DINAMICA *pPilha) {
	return (pPilha->iTamanho == 0);
}

int PilhaDinamica_Tamanho(PILHA_DINAMICA *pPilha) {
	return pPilha->iTamanho;
}

void PilhaDinamica_ImprimirPilha(PILHA_DINAMICA *pPilha) {
	NO *p;
	p = pPilha->pTopo;
	
	while (p != NULL) {
		Item_Imprimir(p->pItem);
		p = p->pAnterior;
	}
}

