#include "filadim.h"
#include <stdlib.h>
#include <stdio.h>

struct cel {
	int info;
	struct cel *next;
};

struct queue {
	no *first;
	no *last;
	int size;
};


fila *create() {
	fila *new;
	new = (fila *) malloc(sizeof(fila));
	
	if (new != NULL) {
		new->first = NULL;
		new->last = NULL;
		new->size = 0;
		
		return new;
	}
	
	return NULL;
}

int entra(fila *fi, int info) {
	no *new;
	new = (no *) malloc(sizeof(no));
	
	if (new != NULL) {
		new->info = info;
		new->next = NULL;
		
		if (fi->first == NULL) {
			fi->last = new;
			fi->first = new;
			fi->size++;
			return 1;
		}
		else {
			fi->last->next = new;
			fi->last = new;
			fi->size++;
			
			return 1;
		}
	}
	
	return 0;
}

int sai(fila *fi) {
	if (!empty(fi)) {
		int elem;
		no *morta;
	
		morta = fi->first;
		elem = fi->first->info;
		fi->first = fi->first->next;
		fi->size--;
		free(morta);
	
		return elem;
	}
	
	return -1;
}

void destroy(fila *fi) {
	no *p;
	no *q;
	
	q = NULL;
	p = fi->first;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	free(fi);
}

int empty(fila *fi) {
	return (fi->size == 0);
}

void print(fila *fi) {
	no *p;
	p = fi->first;
	
	while (p != NULL) {
		printf("%d ", p->info);
		p = p->next;
	}
	printf("\n");
}











