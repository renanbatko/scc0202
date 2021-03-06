#include "item.h"
#include <stdlib.h>
#include <stdio.h>

TIPO_ITEM *criar_item(TIPO_CHAVE chave, int valor){
	TIPO_ITEM *item;
	item = (TIPO_ITEM *) malloc(sizeof(TIPO_ITEM));
	
	item->chave = chave;
	item->info.valor = valor;
	
	return item;
}

void apagar_item(TIPO_ITEM *item){
	//printf("item freed...\n");
	free(item);
}

void imprimir_item(TIPO_ITEM *item){
	printf("[%d, %d]\n", item->chave, item->info.valor);
}
