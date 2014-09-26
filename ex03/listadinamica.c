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
	NO *novo/*, *temp, *aux*/;
	novo = (NO *) malloc(sizeof(NO));
	
	//TIPO_ITEM *it;
	//it = criar_item(item->chave, item->info.valor);
	 /*
	novo->item = *item;
	novo->proximo = NULL;
	
	temp = lista->inicio;
	while (temp != NULL){
		aux = temp;
		temp = temp->proximo;
	}
	if (temp == NULL){
		aux->proximo = novo;
		printf("eh NULL\n");}
	else
		printf("nao eh null\n");
	*/
	
	//novo->item
	//novo->item = (TIPO_ITEM *) malloc(sizeof(TIPO_ITEM));
	
	if (novo != NULL){
		novo->item = *item;
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

void swap(NO *p, NO *q){
	NO *aux;
	aux = p->proximo;
	p->proximo = q->proximo;
	q->proximo = aux;
}

LISTA_DINAMICA *ordenar_lista(LISTA_DINAMICA *lista){
	NO *ini, *elem, *p, *q, *temp;
	ini = lista->inicio;
	p = ini->proximo;
	
	while (p != NULL){
		elem = p;
		q = elem;
		while (q != NULL){
			temp = q;
			if (temp->item.chave > elem->item.chave){
				swap(temp, elem);
			}
			q = q->proximo;
		}
		p = p->proximo;
	}
	
	return lista;
}

LISTA_DINAMICA *uniao_sem_repeticao(LISTA_DINAMICA *L1, LISTA_DINAMICA *L2, LISTA_DINAMICA *L3){
	return NULL;
}

LISTA_DINAMICA *uniao_com_repeticao(LISTA_DINAMICA *L1, LISTA_DINAMICA *L2, LISTA_DINAMICA *L3){
	return NULL;
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












