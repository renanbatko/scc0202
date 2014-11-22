#ifndef ITEM_H
#define ITEM_H

typedef struct l{
	int pagina;
	int linha;
	struct l *prox;
} LOCAL;

typedef struct i{
	char palavra[20];
	int chave;
	LOCAL *local;
} ITEM;

ITEM *item_criar(char *, LOCAL *);

void imprimir_item(ITEM *);

void libera_item(ITEM *);

#endif
