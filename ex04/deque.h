#ifndef DEQUE_H
#define DEQUE_H

#include "item.h"

#define TRUE 1 /*define valor booleano � n�o existe na linguagem C*/
#define FALSE 0
#define boolean int //define um tipo booleano

typedef struct node
{
    TIPO_ITEM item;
    struct node *proximo;
    struct node *anterior;
} NO;

typedef struct deque
{
    struct node *inicio ;
    struct node *fim ;
} DEQUE_DINAMICO;

void inicializar_deque(DEQUE_DINAMICO *d);

void apagar_deque(DEQUE_DINAMICO *d);

boolean inserir_inicio(DEQUE_DINAMICO *d, TIPO_ITEM *item);

boolean inserir_fim(DEQUE_DINAMICO *d, TIPO_ITEM *item);

boolean remover_inicio(DEQUE_DINAMICO *d);

boolean remover_fim(DEQUE_DINAMICO *d);

TIPO_ITEM *primeiro(DEQUE_DINAMICO *d);

TIPO_ITEM *ultimo(DEQUE_DINAMICO *d);

int contar(DEQUE_DINAMICO *d);

void imprimir(DEQUE_DINAMICO *d);

boolean vazio(DEQUE_DINAMICO *d);

#endif

