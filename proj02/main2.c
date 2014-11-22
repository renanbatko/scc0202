#include "arvorebb.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	char palavra[] = "Saa";
	ITEM *item;
	LOCAL *local = (LOCAL *) malloc(sizeof(LOCAL));
	local->pagina = -1;
	local->linha = -1;
	local->prox = NULL;
	item = item_criar(palavra, local);
	
	printf("CHAVE: %d\n", item->chave);
	
	
	libera_item(item);
	
	return 0;
}
