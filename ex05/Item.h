#ifndef ITEM_H
#define	ITEM_H

#include "BiblioErro.h"

#define TIPO_CHAR 0
#define TIPO_INT 1

typedef struct {
  int iTipoUnion;
  union {
    int iInt;
    char cChar;
  };
} ITEM;

ITEM *Item_Criar(int iTipoUnion, int valor);

void Item_Apagar(ITEM **pItem);

void Item_Imprimir(ITEM *pItem);

#endif	

