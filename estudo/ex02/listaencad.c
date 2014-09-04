#include "listaencad.h"
#include <stdlib.h>
#include <stdio.h>

struct cel{
	int dado;
	struct cel *prox;
};


celula *cria(){
	celula *c;
	c = (celula *) malloc(sizeof(celula));
	c->prox = NULL;
	
	return c;
}

void insere(celula *c, int val){
	celula *nova;
	nova = (celula *) malloc(sizeof(celula));
	nova->dado = val;
	nova->prox = c->prox;
	c->prox = nova;
}

void remover(celula *c){
	celula *morta;
	morta = c->prox;
	c->prox = morta->prox;
	free(morta);
}

void busca_remove(celula *ini, int elem){
	celula *p, *q;
	p = ini;
	q = ini->prox;
	while (q != NULL && q->dado != elem){
		p = q;
		q = q->prox;
	}
	if (q != NULL){
		p->prox = q->prox;
		free(q);
	}
}

void busca_insere(celula *ini, int elem, int novo){
	celula *p, *q, *nova;
	nova = (celula *) malloc(sizeof(celula));
	nova->dado = novo;
	p = ini;
	q = ini->prox;
	while (q != NULL && q->dado != elem){
		p = q;
		q = q->prox;
	}
	nova->prox = q;
	p->prox = nova;
}

int seek(celula *ini, int n){
	celula *p;
	p = ini;
	while (p != NULL){
		if (p->dado == n){
			return 1;
		}
		p = p->prox;
	}
	return 0;
}

void imprime(celula *ini){
	celula *p = ini->prox;
	while (p != NULL){
		printf("%d ", p->dado);
		p = p->prox;
	}
}

