#ifndef PILHA_DINAMICA_H
#define PILHA_DINAMICA_H

#include "BiblioErro.h"
#include "Item.h"

#define TRUE 1 /*define valor booleano – não existe na linguagem C*/
#define FALSE 0
#define BOOLEAN int //define um tipo booleano

typedef struct NO {
  ITEM *pItem;
  struct NO *pAnterior;
} NO;

typedef struct pilha_dinamica {
  NO *pTopo;
  int iTamanho;
} PILHA_DINAMICA;

PILHA_DINAMICA *PilhaDinamica_CriarPilha();

void PilhaDinamica_ApagarPilha(PILHA_DINAMICA **pPilha);

void PilhaDinamica_ApagarNo(NO *pNo);

BOOLEAN PilhaDinamica_Empilhar(PILHA_DINAMICA *pPilha, ITEM *pItem);

ITEM *PilhaDinamica_Desempilhar(PILHA_DINAMICA *pPilha);

ITEM *PilhaDinamica_Topo(PILHA_DINAMICA *pPilha);

BOOLEAN PilhaDinamica_Vazia(PILHA_DINAMICA *pPilha);

int PilhaDinamica_Tamanho(PILHA_DINAMICA *pPilha);

void PilhaDinamica_ImprimirPilha(PILHA_DINAMICA *pPilha);

#endif
