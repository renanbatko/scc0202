#include <stdlib.h>
#include <stdio.h>
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
	//printf("void libera(Lista *p)\n");
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

int insere_inicio(Lista *p, struct aluno al){
	if (p == NULL){
		return -1;
	}
	
	if (vazia(p)){
		p->dados[p->qtd] = al;
		p->qtd++;
	} else{
		int i;
		p->qtd++;
		for (i = p->qtd-1; i >= 0; i--){
			p->dados[i+1] = p->dados[i];
		}
		p->dados[0] = al;
	}
	
	return 1;
}

int insere_meio(Lista *p, struct aluno al, int pos){
	if (p == NULL){
		return -1;
	}
	
	int i;
	for (i = p->qtd-1; i >= pos; i--){
		p->dados[i+1] = p->dados[i];
	}
	p->dados[pos] = al;
	p->qtd++;
	
	return 1;
}

int insere_final(Lista *p, struct aluno al){
	if (p == NULL){
		return -1;
	}
	
	p->dados[p->qtd] = al;
	p->qtd++;
	
	return 1;
}


int remove_inicio(Lista *p){
	if (p == NULL){
		return -1;
	}
	
	int i;
	for (i = 0; i < p->qtd; i++){
		p->dados[i] = p->dados[i+1];
	}
	p->qtd--;
	
	return 1;
}

int remove_meio(Lista *p, int pos){
	if (p == NULL){
		return -1;
	}
	
	int i;
	for (i = pos; i < p->qtd; i++){
		p->dados[i] = p->dados[i+1];
	}
	p->qtd--;
	
	return 1;
}

int remove_final(Lista *p){
	if (p == NULL){
		return -1;
	}
	
	p->qtd--;
	
	return 1;
}

void print(Lista *p){
	int i;
	printf("\n");
	for (i = 0; i < p->qtd; i++){
		printf("(%d, %s)\n", p->dados[i].nusp, p->dados[i].nome);
	}
	printf("\n");
}
