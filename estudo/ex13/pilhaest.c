#include "pilhaest.h"
#include <stdlib.h>
#include <stdio.h>

struct stack {
	int vet[MAX];
	int topo;
};

pilha *criar() {
	pilha *new;
	new = (pilha *) malloc(sizeof(pilha));
	
	if (new != NULL) {
		new->topo = -1;
		
		return new;
	}
	
	return NULL;
}

void apagar(pilha *pi) {
	free(pi);
}

int empilhar(pilha *pi, int elem) {
	if (!cheia(pi)) {
		pi->topo++;
		pi->vet[pi->topo] = elem;
		
		return 1;
	}
	
	return 0;
}

int desempilhar(pilha *pi) {
	if (!vazia(pi)) {
		pi->topo--;
		
		return 1;
	}
	
	return 0;
}

int topo(pilha *pi) {
	return pi->vet[pi->topo];
}

int tamanho(pilha *pi) {
	return pi->topo;
}

int vazia(pilha *pi) {
	return (pi->topo == -1);
}

int cheia(pilha *pi) {
	return (pi->topo == MAX);
}

void imprimir(pilha *pi) {
	int i;
	for (i = 0; i <= pi->topo; i++) {
		printf("%d ", pi->vet[i]);
	}
	printf("\n");
}

