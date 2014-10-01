#include "listadinamica.h"
#include <stdlib.h>
#include <stdio.h>

LISTA_DINAMICA *criar_lista(void){ //ok
	LISTA_DINAMICA *ini;
	ini = (LISTA_DINAMICA *) malloc(sizeof(LISTA_DINAMICA));
	
	ini->inicio = NULL;
	ini->fim = NULL;
	ini->tamanho = 0;
	
	return ini;
}

void apagar_lista(LISTA_DINAMICA *lista){ //ok
	NO *celula, *temp;
	celula = lista->inicio;
	
	while (celula != NULL){
		temp = celula;
		celula = celula->proximo;
		apagar_no(temp);
	}
	
	free(lista);
}

void apagar_no(NO *no){ //ok
	apagar_item(&no->item);
	//free(no); era aqui <<<<<<<--------------
}

boolean inserir_ordenado(LISTA_DINAMICA *lista, TIPO_ITEM *item){ //ok
	NO *novo; //novo elemento
	NO *p; //ponteiro para percorrer a lista
	NO *q = NULL; //elemento anterior
	novo = (NO *) malloc(sizeof(NO));
	
	p = lista->inicio;
	if (novo != NULL) {
		novo->item = *item;
		novo->proximo = NULL;
		
		while (p != NULL && p->item.chave < item->chave) {
			q = p;
			p = p->proximo;
		}
		if (q == NULL) {
			novo->proximo = lista->inicio;
			lista->inicio = novo;
			lista->tamanho++;
			return TRUE;
		}
		else {
			novo->proximo = q->proximo;
			q->proximo = novo;
			lista->tamanho++;
			return TRUE;
		}
		/*
		novo->item = *item;
		novo->proximo = NULL;
		
		if (lista->inicio == NULL){
			lista->inicio = novo;
		}
		else {
			while (p != NULL && p->item.chave < item->chave) {
				q = p;
				p = p->proximo;
			}
			q->proximo = novo;
			novo->proximo = p->proximo;
			//lista->fim->proximo = novo;
		}
		
		lista->fim = novo;
		lista->tamanho++;*/
		
		//return TRUE;
	}
	
	return FALSE;
}

boolean remover_item(LISTA_DINAMICA *lista, int chave){ //ok
	NO *celula, *aux;
	celula = lista->inicio;
	aux = NULL;
	
	while (celula != NULL && celula->item.chave != chave){
		aux = celula;
		celula = celula->proximo;
	}
	
	if (celula != NULL){
		if (celula == lista->inicio){
			lista->inicio = celula->proximo;
		} else {
			aux->proximo = celula->proximo;
		}
		
		if (celula == lista->fim){
			lista->fim = aux;
		}
		
		lista->tamanho--;
		free(celula);
		
		return TRUE;
	}
	
	return FALSE;
}

void swap(NO *p, NO *q){ //parte do ordenar_lista
	TIPO_CHAVE aux;
	TIPO_INFO temp;
	
	aux = p->item.chave;
	p->item.chave = q->item.chave;
	q->item.chave = aux;
	
	temp = p->item.info;
	p->item.info = q->item.info;
	q->item.info = temp;
}

LISTA_DINAMICA *ordenar_lista(LISTA_DINAMICA *lista){ //ok
	NO *p, *q, *elem, *temp;
	p = lista->inicio;
	
	while (p != NULL) {
		elem = p;
		q = elem;
		while (q != NULL) {
			temp = q;
			if (temp->item.chave < elem->item.chave) {
				swap(elem, temp);
			}
			q = q->proximo;
		}
		p = p->proximo;
	}
	
	return lista;
}

LISTA_DINAMICA *uniao_sem_repeticao(LISTA_DINAMICA *L1, LISTA_DINAMICA *L2, LISTA_DINAMICA *L3){ //ok
	NO *p, *q;
	p = L1->inicio;
	q = L2->inicio;
	
	while (p != NULL && q != NULL) {
		if (p->item.chave == q->item.chave && p->item.info.valor == q->item.info.valor) {
			inserir_ordenado(L3, &p->item);
		}
		else {
			inserir_ordenado(L3, &p->item);
			inserir_ordenado(L3, &q->item);		
		}

		p = p->proximo;
		q = q->proximo;
	}
	
	while (p == NULL && q != NULL) {
		inserir_ordenado(L3, &q->item);
		q = q->proximo;
	}
	
	while (p != NULL && q == NULL) {
		inserir_ordenado(L3, &p->item);
		p = p->proximo;
	}
	
	L3 = ordenar_lista(L3);
	
	return L3;
}

LISTA_DINAMICA *uniao_com_repeticao(LISTA_DINAMICA *L1, LISTA_DINAMICA *L2, LISTA_DINAMICA *L3){ //ok
	NO *p, *q;
	p = L1->inicio;
	q = L2->inicio;
	
	while (p != NULL && q != NULL) {
		inserir_ordenado(L3, &p->item);
		inserir_ordenado(L3, &q->item);
		p = p->proximo;
		q = q->proximo;
	}
	
	while (p == NULL && q != NULL) {
		inserir_ordenado(L3, &q->item);
		q = q->proximo;
	}
	
	while (p != NULL && q == NULL) {
		inserir_ordenado(L3, &p->item);
		p = p->proximo;
	}
	
	L3 = ordenar_lista(L3);
	
	return L3;
}

int tamanho(LISTA_DINAMICA *lista){ //ok
	return lista->tamanho;
}

boolean vazia(LISTA_DINAMICA *lista){ //ok
	return (lista->tamanho == 0);
}

boolean cheia(LISTA_DINAMICA *lista){ //ok
	return FALSE;
}

void imprimir_lista(LISTA_DINAMICA *lista){ //ok
	NO *p;
	p = lista->inicio;
	
	while (p != NULL){
		printf("[%d, %d]-> ", p->item.chave, p->item.info.valor);
		p = p->proximo;
	}
}

void imprimir_invertida(LISTA_DINAMICA *lista){
	
}

TIPO_ITEM *recuperar_item(LISTA_DINAMICA *lista, int chave){ //ok
	NO *p, *q;
	p = lista->inicio;
	q = p->proximo;
	
	while (p != NULL && p->item.chave != chave){
		p = q;
		q = q->proximo;
	}
	
	if (p != NULL){
		return &p->item;
	}
	
	return NULL;
}












