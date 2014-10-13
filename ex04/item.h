#ifndef ITEM_H
#define ITEM_H

typedef struct{ 
        int chave;
        int valor;
} TIPO_ITEM;

TIPO_ITEM *criar_item(int chave, int valor);
void imprimir_item(TIPO_ITEM *item);

#endif
