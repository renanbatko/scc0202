#include "Item.h"
#include "PilhaDinamica.h"
#include "Calculadora.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	ITEM *item;
	item = Item_Criar(1, 10);
	//Item_Imprimir(item);
	Item_Apagar(&item);
	
	PILHA_DINAMICA *pd;
	pd = PilhaDinamica_CriarPilha();
	
	item = Item_Criar(1, 10);
	PilhaDinamica_Empilhar(pd, item);
	//Item_Apagar(&item);
	item = Item_Criar(1, 5);
	PilhaDinamica_Empilhar(pd, item);
	//Item_Apagar(&item);
	item = Item_Criar(1, 3);
	PilhaDinamica_Empilhar(pd, item);
	//Item_Apagar(&item);
	item = Item_Criar(0, '*');
	PilhaDinamica_Empilhar(pd, item);
	//Item_Apagar(&item);
	item = Item_Criar(1, 2);
	PilhaDinamica_Empilhar(pd, item);
	//Item_Apagar(&item);
	item = Item_Criar(1, 1);
	PilhaDinamica_Empilhar(pd, item);
	//Item_Apagar(&item);
	item = Item_Criar(0, '+');
	PilhaDinamica_Empilhar(pd, item);
	//Item_Apagar(&item);
	item = Item_Criar(1, 9);
	PilhaDinamica_Empilhar(pd, item);
	//Item_Apagar(&item);
	
	PilhaDinamica_ImprimirPilha(pd);
	
	printf("\n\n");
	
	PilhaDinamica_Desempilhar(pd);
	PilhaDinamica_Desempilhar(pd);
	PilhaDinamica_Desempilhar(pd);
	PilhaDinamica_Desempilhar(pd);
	
	PilhaDinamica_ImprimirPilha(pd);
	
	PilhaDinamica_ApagarPilha(&pd);

	printf("calculadora_avalia: %d\n", Calculadora_AvaliaInfixa("1+2+3*4^5"));
	
	return 0;
}
