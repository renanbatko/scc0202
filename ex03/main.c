#include "item.h"
#include "listadinamica.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
	LISTA_DINAMICA *li;
	li = criar_lista();
	
	TIPO_ITEM *item;
		
	//item = criar_item(2, 3);
	//imprimir_item(item);
	
	//inserir_ordenado(li, item);
	//apagar_item(item);
	int i, a, b;
	for (i = 0; i < 4; i++){
		scanf(" %d %d", &a, &b);
		//a = i + 2;
		//b = i + 9;
		item = criar_item(a, b);
		inserir_ordenado(li, item);
		apagar_item(item);
	}
	
	imprimir_lista(li);
	
	apagar_lista(li);
	
	return 0;
}
