#include "filac.h"
#include <stdlib.h>
#include <stdio.h>

struct queue {
	int valores[MAX];
	int primeiro;
	int ultimo;
	int tamanho;
};

fila *cria() {
	fila *nova;
	nova = (fila *) malloc(sizeof(fila));
	
	if (nova != NULL) {
		nova->primeiro = 0;
		nova->ultimo = 0;
		nova->tamanho = 0;
		
		return nova;
	}
	
	return NULL;
}

int entra(fila *fi, int valor) {
	if (!cheia(fi)) {
		fi->valores[fi->ultimo] = valor;
		fi->ultimo = (fi->ultimo + 1) % MAX;
		fi->tamanho++;
		
		return 1;
	}
	
	return 0;
}

int sai(fila *fi) {
	if (!vazia(fi)) {
		int ret = fi->valores[fi->primeiro];
		fi->primeiro = (fi->primeiro + 1) % MAX;
		fi->tamanho--;
		
		return ret;
	}
	
	return -1;
}

void libera(fila *fi) {
	free(fi);
}

int cheia(fila *fi) {
	return (fi->tamanho == MAX-1);
}

int vazia(fila *fi) {
	return (fi->tamanho == 0);
}

void imprime(fila *fi) {
	int tam, nop = 0;
	tam = (fi->ultimo > fi->primeiro) ? (fi->ultimo - fi->primeiro) : (fi->primeiro - fi->ultimo);
	
	int i = fi->primeiro;
	while (nop != tam) {
		printf("%d ", fi->valores[i]);
		i++;
		nop++;
		if (i == MAX) i = 0;
	}
	printf("\n");
}

