#include "Item.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	ITEM *item;
	item = Item_Criar(1, 10);
	Item_Imprimir(item);
	Item_Apagar(&item);
	
	return 0;
}
