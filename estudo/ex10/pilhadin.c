#include "pilhadin.h"
#include <stdlib.h>
#include <stdio.h>

struct celula {
	int info;
	struct celula *under;
};

struct pilha {
	int size;
	struct celula *top;
};

stack *create() {
	stack *new;
	new = (stack *) malloc(sizeof(stack));
	
	if (new != NULL) {
		new->size = 0;
		new->top = NULL;
		
		return new;
	}
	
	return NULL;
}

void destroy(stack *s) {
	cell *p;
	cell *q;
	
	p = s->top;
	
	while (p != NULL) {
		q = p;
		p = p->under;
		free(q);
	}
	
	free(s);
}

int stacking(stack *s, int info) {
	cell *new;
	new = (cell *) malloc(sizeof(cell));
	
	if (new != NULL) {
		new->info = info;
		new->under = s->top;
		s->top = new;
		s->size++;
		
		return 1;
	}
	
	return 0;
}

int unstacking(stack *s) {
	int info;
	info = s->top->info;
	
	cell *p;
	p = s->top;
	s->top = s->top->under;
	s->size--;
	free(p);
	
	return info;
}

int empty(stack *s) {
	return (s->size == 0);
}

int size(stack *s) {
	return s->size;
}

void print(stack *s) {
	cell *p;
	p = s->top;
	
	while (p != NULL) {
		printf("%d ", p->info);
		p = p->under;
	}
	printf("\n");
}

