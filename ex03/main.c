#include "item.h"
#include "listadinamica.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
	LISTA_DINAMICA *li, *l2, *l3;
	li = criar_lista();
	
	TIPO_ITEM *item;
		
	//item = criar_item(2, 3);
	//imprimir_item(item);
	
	//inserir_ordenado(li, item);
	//apagar_item(item);
	//int i, a, b;
	//for (i = 0; i < 4; i++){
		//scanf(" %d %d", &a, &b);
		//a = i + 2;
		//b = i + 9;
		//item = criar_item(a, b);
		//inserir_ordenado(li, item);
		//apagar_item(item);
	//}
	
	item = criar_item(99, 2);
	inserir_ordenado(li, item);
	apagar_item(item);
	item = criar_item(9, 50);
	inserir_ordenado(li, item);
	apagar_item(item);
	item = criar_item(2, 69);
	inserir_ordenado(li, item);
	apagar_item(item);
	item = criar_item(19, 3);
	inserir_ordenado(li, item);
	apagar_item(item);
	item = criar_item(78, 901);
	inserir_ordenado(li, item);
	apagar_item(item);
	item = criar_item(18, 12);
	inserir_ordenado(li, item);
	apagar_item(item);
	
	l2 = criar_lista();
	
	item = criar_item(-1, 0);
	inserir_ordenado(l2, item);
	apagar_item(item);
	item = criar_item(-1, 0);
	inserir_ordenado(l2, item);
	apagar_item(item);
	item = criar_item(-1, 0);
	inserir_ordenado(l2, item);
	apagar_item(item);
	item = criar_item(19, 3);
	inserir_ordenado(l2, item);
	apagar_item(item);
	item = criar_item(-1, 0);
	inserir_ordenado(l2, item);
	apagar_item(item);
	
	
	imprimir_lista(li);
	//li = ordenar_lista(li);
	printf("\n");
	imprimir_lista(l2);
	//imprimir_lista(li);
	
	/*printf("\n");
	item = recuperar_item(li, 4);
	imprimir_item(item);
	
	printf("\n");
	imprimir_lista(li);
	
	printf("tamanho: %d\n", tamanho(li));
	
	remover_item(li, 2);
	printf("\n");
	imprimir_lista(li);
	
	remover_item(li, 5);
	printf("\n");
	imprimir_lista(li);
	
	printf("tamanho: %d\n", tamanho(li));

	*/
	l3 = criar_lista();
	
	//l3 = uniao_com_repeticao(li, l2, l3);
	l3 = uniao_sem_repeticao(li, l2, l3);
	printf("\n");
	imprimir_lista(l3);

	apagar_lista(li);
	apagar_lista(l2);
	apagar_lista(l3);
	
	printf("\n");
	
	return 0;
}
