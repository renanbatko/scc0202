#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ITEM *item_criar(char *palavra, LOCAL *local) {
	ITEM *novo;
	novo = (ITEM *) malloc(sizeof(ITEM));
	
	if (novo != NULL) {
		strcpy(novo->palavra, palavra);
		novo->local = local;
		novo->chave = palavra[0];
		novo->local->prox = NULL;
		
		return novo;
	}
	
	return NULL;
}

void imprimir_item(ITEM *item) {
	printf("%s\t%d,%d\n", item->palavra, item->local->pagina, item->local->linha);
}
