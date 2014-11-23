#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char to_lower(char ch) {
	//se for simplemente maiuscula
	if (ch >= 65 && ch <= 90) {
		ch = ch + 32;
		return ch;
	}
	//se for algum 'e' com acento
	if (ch == 130 || (ch >= 136 && ch <= 138) || ch == 144 || (ch >= 210 && ch <= 212)) {
		ch = 101;
		return ch;
	}
	//se for algum 'a' com acento
	if ((ch >= 131 && ch <= 134) || ch == 142 || ch == 143 || ch == 160 || (ch >= 181 && ch <= 183) || ch == -61) {
		ch = 97;
		return ch;
	}
	//se for algum 'i' com acento
	if ((ch >= 139 && ch <= 141) || ch == 173 || ch == 215 || ch == 216 || ch == 222) {
		ch = 105;
		return ch;
	}
	//se for algum 'o' com acento
	if ((ch >= 147 && ch <= 149) || ch == 153 || ch == 162 || (ch >= 224 && ch <= 229)) {
		ch = 111;
		return ch;
	}
	//se for algum 'u' com acento
	if (ch == 150 || ch == 151 || ch == 154 || ch == 161 || ch == 163 || (ch >= 233 && ch <= 235)) {
		ch = 117;
		return ch;
	}

	return ch;
}

ITEM *item_criar(char *palavra, LOCAL *local) {
	ITEM *novo;
	novo = (ITEM *) malloc(sizeof(ITEM));
	
	if (novo != NULL) {
		strcpy(novo->palavra, palavra);
		novo->local = local;
		novo->chave = to_lower(palavra[0]);
		novo->local->prox = NULL;
		
		return novo;
	}
	
	return NULL;
}

void imprimir_item(ITEM *item) {
	printf("%s\t", item->palavra);
	LOCAL *p = item->local;
	while (p != NULL) {
		printf("%d,%d ", item->local->pagina, item->local->linha);
		p = p->prox;
	}
	printf("\n");
}

void libera_item(ITEM *item) {
	LOCAL *p, *q;
	p = item->local;
	while (p != NULL) {
		q = p;
		p = p->prox;
		free(q);
	}
	free(item);
}

