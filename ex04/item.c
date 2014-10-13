#include "item.h"
#include <stdio.h>
#include <stdlib.h>

TIPO_ITEM *criar_item(int chave, int valor) {
	TIPO_ITEM *new;
	new = (TIPO_ITEM *) malloc(sizeof(TIPO_ITEM));
	
	new->chave = chave;
	new->valor = valor;
	
	return new;
}

void imprimir_item(TIPO_ITEM *item) {
	printf("[%d, %d]", item->chave, item->valor);
}

