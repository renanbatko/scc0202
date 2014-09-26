#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H

#include "item.h"

#define TRUE 1 /*define valor booleano não existe na linguagem C*/
#define FALSE 0
#define boolean int //define um tipo booleano


typedef struct node{
    TIPO_ITEM item;
    struct node *proximo;
}NO;

typedef struct { 
    NO *inicio;
    NO *fim;    
    int tamanho;  //tamanho da fila
}LISTA_DINAMICA;

LISTA_DINAMICA *criar_lista(void);

void apagar_lista(LISTA_DINAMICA *lista);

void apagar_no(NO *no);

boolean inserir_ordenado(LISTA_DINAMICA *lista, TIPO_ITEM *item);

boolean remover_item(LISTA_DINAMICA *lista, int chave);

LISTA_DINAMICA *uniao_sem_repeticao(LISTA_DINAMICA *L1, LISTA_DINAMICA *L2, LISTA_DINAMICA *L3);

LISTA_DINAMICA *uniao_com_repeticao(LISTA_DINAMICA *L1, LISTA_DINAMICA *L2, LISTA_DINAMICA *L3);

int tamanho(LISTA_DINAMICA *lista);

boolean vazia(LISTA_DINAMICA *lista);

boolean cheia(LISTA_DINAMICA *lista);

void imprimir_lista(LISTA_DINAMICA *lista);

void imprimir_invertida(LISTA_DINAMICA *lista);

TIPO_ITEM *recuperar_item(LISTA_DINAMICA *lista, int chave);

LISTA_DINAMICA *ordenar_lista(LISTA_DINAMICA *lista);
  
#endif
