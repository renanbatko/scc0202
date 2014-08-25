#include "listaencad.h"
#include <stdio.h>

int main(void){
	celula *lista;
	lista = cria();
	
	insere(lista, 5);
	imprime(lista);
	printf("\n");

	insere(lista, 12);
	imprime(lista);
	printf("\n");
	
	insere(lista, 8);
	imprime(lista);
	printf("\n");
	
	insere(lista, 0);
	imprime(lista);
	printf("\n");
	
	insere(lista, 78);
	imprime(lista);
	printf("\n");
	
	insere(lista, 90);
	imprime(lista);
	printf("\n");
	
	insere(lista, 2);
	imprime(lista);
	printf("\n");
	
	remover(lista);
	imprime(lista);
	printf("\n");
	
	remover(lista);
	imprime(lista);
	printf("\n");
	
	busca_remove(lista, 8);
	imprime(lista);
	printf("\n");
	
	busca_remove(lista, 5);
	imprime(lista);
	printf("\n");
	
	busca_insere(lista, 0, 66);
	imprime(lista);
	printf("\n");
	
	busca_insere(lista, 78, 1);
	imprime(lista);
	printf("\n");
	
	return 0;
}
