#ifndef PILHADIN_H
#define PILHADIN_H

typedef struct celula cell;

typedef struct pilha stack;

stack *create();

void destroy(stack *);

int stacking(stack *, int);

int unstacking(stack *);

int empty(stack *);

int size(stack *);

void print(stack *);

#endif
