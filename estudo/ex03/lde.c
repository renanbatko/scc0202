#include "lde.h"
#include <stdlib.h>
#include <stdio.h>

struct cel{
	int dado;
	struct cel *prev;
	struct cel *next;
};

celula *cria(){
	celula *p;
	p = (celula *) malloc(sizeof(celula));
	p->next = NULL;
	p->prev = NULL;
	
	return p;
}

void libera(celula *ini){
	celula *p, *q;
	p = ini;
	while (p != NULL){
		q = p;
		free(q);
		p = p->next;
	}
}

void insere(celula *ini, int n){
	celula *nova;
	nova = (celula *) malloc(sizeof(celula));
	nova->dado = n;
	nova->next = ini;
	nova->prev = NULL;
	if (ini->next == NULL){
		ini->next = nova;
	}
}

void imprime(celula *ini){
	celula *p;
	p = ini->next;
	while (p != NULL){
		printf("%d ", p->dado);
		p = p->next;
	}
	printf("\n");
}

int maior(celula *p, int mai) {
	if (p != NULL) {
		if (p->dado > mai) mai = p->dado;
		return maior(p->next, mai);
	}
	return mai;
}
