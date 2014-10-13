#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void inicializar_deque(DEQUE_DINAMICO *d) {
	d = (DEQUE_DINAMICO *) malloc(sizeof(DEQUE_DINAMICO));
	d->inicio = NULL;
	d->fim = NULL;
}

void apagar_deque(DEQUE_DINAMICO *d) {
	NO *p;
	NO *q = NULL;
	
	p = d->inicio;
	while (p != NULL) {
		q = p;
		p = p->proximo;
		
		free(q);
	}
	free(d);
}

boolean inserir_inicio(DEQUE_DINAMICO *d, TIPO_ITEM *item) {
	NO *new;
	new = (NO *) malloc(sizeof(NO));
	
	if (new != NULL) {
		new->item = *item;
	
		new->anterior = NULL;
		new->proximo = d->inicio;
		d->inicio = new;
	
		return TRUE;
	}
	
	return FALSE;
}

boolean inserir_fim(DEQUE_DINAMICO *d, TIPO_ITEM *item) {
	NO *new;
	new = (NO *) malloc(sizeof(NO));
	
	if (new != NULL) {
		new->item = *item;
		
		new->anterior = d->fim;
		new->proximo = NULL;
		d->fim = new;
	
		return TRUE;
	}
	
	return FALSE;
}

boolean remover_inicio(DEQUE_DINAMICO *d) {
	if (vazio(d)) return FALSE;
	
	NO *morta;
	
	morta = d->inicio;
	d->inicio = morta->proximo;
	d->inicio->anterior = NULL;
	
	free(morta);
	
	return TRUE;
}

boolean remover_fim(DEQUE_DINAMICO *d) {
	if (vazio(d)) return FALSE;
	
	NO *morta;
	
	morta = d->fim;
	d->fim = morta->anterior;
	d->fim->proximo = NULL;
	
	free(morta);
	
	return TRUE;
}

TIPO_ITEM *primeiro(DEQUE_DINAMICO *d) {
	if (vazio(d)) return NULL;
	
	return &d->inicio->item;
}

TIPO_ITEM *ultimo(DEQUE_DINAMICO *d) {
	if (vazio(d)) return NULL;
	
	return &d->fim->item;
}

int contar(DEQUE_DINAMICO *d) {
	NO *p;
	p = d->inicio;
	
	int counter = 1;
	while (p != NULL) {
		counter++;
		p = p->proximo;
	}
	
	return counter;
}

void imprimir(DEQUE_DINAMICO *d) {
	NO *p;
	p = d->inicio;
	
	while (p != NULL) {
		printf("[%d, %d] ", p->item.chave, p->item.valor);
		p = p->proximo;
	}
}

boolean vazio(DEQUE_DINAMICO *d) {
	return ((d->inicio == NULL) && (d->fim == NULL));
}

