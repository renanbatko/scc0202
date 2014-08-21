#include <stdlib.h>
#include "lista.h"

struct lista{
	int qtd;
	struct aluno dados[MAX];
};

Lista *cria(){
	Lista *p;
	p = (Lista *) malloc(sizeof(Lista));
	
	if (p != NULL){
		p->qtd = 0;
	}
	return p;
}

void libera(Lista *p){
	free(p);
}

int tamanho(Lista *p){
	if (p == NULL){
		return -1;
	} else{
		return p->qtd;
	}
}

int cheia(Lista *p){
	if (p == NULL){
		return -1;
	}
	return (p->qtd == MAX);
}

int vazia(Lista *p){
	if (p == NULL){
		return -1;
	}
	return (p->qtd == 0);
}











