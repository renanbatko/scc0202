#include "Item.h"
#include <stdlib.h>
#include <stdio.h>

ITEM *Item_Criar(int iTipoUnion, int valor) {
	ITEM *new;
	new = (ITEM *) malloc(sizeof(ITEM));
	
	if (new != NULL) {
		new->iTipoUnion = iTipoUnion;
		new->iInt = valor;
		
		return new;
	}
	
	return NULL;
}

void Item_Apagar(ITEM **pItem) {
	free(*pItem);
}

void Item_Imprimir(ITEM *pItem) {
	if (pItem->iTipoUnion == TIPO_CHAR) {
		printf("[%c]\n", pItem->cChar);
	}
	else {
		printf("[%d]\n", pItem->iInt);
	}
}
