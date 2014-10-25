#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

struct queue {
	int valores[MAX];
	int primeiro;
	int ultimo;
	int tamanho;
};

fila *cria() {
	fila *new;
	new = (fila *) malloc(sizeof(fila));
	
	if (new != NULL) {
		new->primeiro = 0;
		new->ultimo = 0;
		new->tamanho = 0;
		
		return new;
	}
	
	return NULL;
}

int add(fila *fi, int elem) {
	if (!cheia(fi)) {
		fi->valores[fi->ultimo] = elem;
		fi->ultimo = (fi->ultimo + 1) % MAX;
		fi->tamanho++;
		
		return 1;
	}
	
	return 0;
}

int remover(fila *fi) {
	if (!vazia(fi)) {
		fi->primeiro = (fi->primeiro + 1) % MAX;
		fi->tamanho--;
		
		return 1;
	}
	
	return 0;
}

void liberar(fila *fi) {
	free(fi);
}

int cheia(fila *fi) {
	return (fi->tamanho == MAX);
}

int vazia(fila *fi) {
	return (fi->tamanho == 0);
}

void imprimir(fila *fi) {
	int tam, nop = 0;
	tam = (fi->ultimo > fi->primeiro) ? (fi->ultimo - fi->primeiro) : (fi->primeiro - fi->ultimo);
	
	int i = fi->primeiro;
	while (nop != tam) {
		printf("%d ", fi->valores[i]);
		nop++;
		i++;
		if (i == MAX) i = 0;
	}
	printf("\n");
}



















