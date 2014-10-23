#include "lde.h"
#include <stdio.h>

int main(void){
	celula *listad;
	listad = cria();

	insere(listad, 4);
	imprime(listad);
	
	insere(listad, 8);
	imprime(listad);
	
	insere(listad, 14);
	imprime(listad);
	
	insere(listad, 12);
	imprime(listad);
	
	insere(listad, 9);
	imprime(listad);
	
	insere(listad, 5);
	imprime(listad);
	
	insere(listad, 6);
	imprime(listad);

	//printf("maior: %d\n", maior(listad, -1));
	return 0;
}
