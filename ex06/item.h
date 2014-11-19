#ifndef ITEM_H
#define	ITEM_H

typedef struct  {
  int iChave;
  int iValor;
} ITEM;

ITEM *Item_Criar(int iChave, int iValor);

void Item_Apagar(ITEM **pItem);

void Item_Imprimir(ITEM *pItem);

#endif

