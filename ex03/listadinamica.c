#include "listadinamica.h"
#include <stdlib.h>
#include <stdio.h>

LISTA_DINAMICA *criar_lista(void){
	LISTA_DINAMICA *ini;
	ini = (LISTA_DINAMICA *) malloc(sizeof(LISTA_DINAMICA));
	
	ini->inicio = NULL;
	ini->fim = NULL;
	ini->tamanho = 0;
	
	return ini;
}

void apagar_lista(LISTA_DINAMICA *lista){
	NO *celula, *temp;
	celula = lista->inicio;
	
	while (celula != NULL){
		temp = celula;
		apagar_no(temp);
		celula = celula->proximo;
	}
	
	free(lista);
}

void apagar_no(NO *no){
	apagar_item(no->item);
	free(no);
}

boolean inserir_ordenado(LISTA_DINAMICA *lista, TIPO_ITEM *item){
	NO *novo;
	novo = (NO *) malloc(sizeof(NO));
	
	if (novo != NULL){
		novo->item = item;
		novo->proximo = NULL;
	
		if (lista->inicio == NULL){
			lista->inicio = novo;
		}
		else {
			lista->fim->proximo = novo;
		}
	
		lista->fim = novo;
		lista->tamanho++;
	
		return TRUE;
	}
	
	return FALSE;
}

boolean remover_item(LISTA_DINAMICA *lista, int chave){
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

LISTA_DINAMICA *uniao_sem_repeticao(LISTA_DINAMICA *L1, LISTA_DINAMICA *L2, LISTA_DINAMICA *L3){

}

LISTA_DINAMICA *uniao_com_repeticao(LISTA_DINAMICA *L1, LISTA_DINAMICA *L2, LISTA_DINAMICA *L3){

}

int tamanho(LISTA_DINAMICA *lista){

}

boolean vazia(LISTA_DINAMICA *lista){

}

boolean cheia(LISTA_DINAMICA *lista){

}

void imprimir_lista(LISTA_DINAMICA *lista){

}

void imprimir_invertida(LISTA_DINAMICA *lista){

}

TIPO_ITEM *recuperar_item(LISTA_DINAMICA *lista, int chave){
	NO *p, *q;
	p = lista->inicio;
	q = p->proximo;
	
	while (p != NULL && p->item.chave != chave){
		p = q;
		q = q->proximo;
	}
	
	if (p != NULL){
		return p->item;
	}
	
	return NULL;
}












