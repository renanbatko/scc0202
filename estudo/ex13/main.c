#include "pilhaest.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	pilha *pi;
	pi = criar();
	
	empilhar(pi, 5);
	imprimir(pi);
	empilhar(pi, 1);
	imprimir(pi);
	empilhar(pi, 3);
	imprimir(pi);
	empilhar(pi, 6);
	imprimir(pi);
	empilhar(pi, 9);
	imprimir(pi);
	empilhar(pi, 0);
	imprimir(pi);
	
	desempilhar(pi);
	imprimir(pi);
	desempilhar(pi);
	imprimir(pi);
	desempilhar(pi);
	imprimir(pi);
	desempilhar(pi);
	imprimir(pi);
	desempilhar(pi);
	imprimir(pi);
	
	apagar(pi);
	
	return 0;
}
