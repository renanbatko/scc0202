#include "filac.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argtc, char *argv[]) {
	fila *fi;
	fi = cria();
	
	entra(fi, 5);
	imprime(fi);
	entra(fi, 7);
	imprime(fi);
	entra(fi, 2);
	imprime(fi);
	entra(fi, 0);
	imprime(fi);
	entra(fi, 9);
	imprime(fi);
	entra(fi, 1);
	imprime(fi);
	entra(fi, 4);
	imprime(fi);
	entra(fi, 4);
	imprime(fi);
	entra(fi, 3);
	imprime(fi);
	
	sai(fi);
	imprime(fi);
	sai(fi);
	imprime(fi);
	sai(fi);
	imprime(fi);
	sai(fi);
	imprime(fi);
	sai(fi);
	imprime(fi);
	sai(fi);
	imprime(fi);
	sai(fi);
	imprime(fi);
	sai(fi);
	imprime(fi);
	
	libera(fi);
	
	return 0;
}
