#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	fila *fi;
	fi = cria();
	
	add(fi, 5);
	imprimir(fi);
	add(fi, 7);
	imprimir(fi);
	add(fi, 1);
	imprimir(fi);
	add(fi, 9);
	imprimir(fi);
	add(fi, 4);
	imprimir(fi);
		
	remover(fi);
	imprimir(fi);
	remover(fi);
	imprimir(fi);
	remover(fi);
	imprimir(fi);
	remover(fi);
	imprimir(fi);
	
	liberar(fi);
	
	
	return 0;
}
