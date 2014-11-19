#include "item.h"
#include <stdlib.h>
#include <stdio.h>

ITEM *Item_Criar(int iChave, int iValor) {
	ITEM *new;
	new = (ITEM *) malloc(sizeof(ITEM));
	
	if (new != NULL) {
		new->iChave = iChave;
		new->iValor = iValor;
		
		return new;
	}
	
	return NULL;
}

void Item_Apagar(ITEM **pItem) {
	free(*pItem);
	*pItem = NULL;
}

void Item_Imprimir(ITEM *pItem) {
	printf("[%d, %d]\n", pItem->iChave, pItem->iValor);
}

