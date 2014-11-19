#ifndef ARVOREBINARIA_H
#define	ARVOREBINARIA_H

#include "item.h" 

#define FILHO_ESQ 0
#define FILHO_DIR 1

typedef struct arvore_binaria ARVORE_BINARIA;
typedef struct no NO;

struct no {
  ITEM *pItem;
  NO *pFilhoEsq;
  NO *pFilhoDir;
};

struct arvore_binaria {
  NO *pRaiz;
};

ARVORE_BINARIA *AB_CriarArvore();

NO *AB_CriarRaiz(ARVORE_BINARIA *pArvore, ITEM *pItem);

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

#endif

