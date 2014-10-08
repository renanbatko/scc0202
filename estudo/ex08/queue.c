#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct fila {
	int *values
	int first;
	int last;
	int size;
};

queue *create(int size) {
	queue *new;
	new = (queue *) malloc(size * sizeof(queue));
	
	new->first = 0;
	new->last = 0;
	new->size = 0;
	
	return new;
}

void add(queue *q, int elem) {
	if (!full(q)) {
		if (q->first == q->last) {
			
		}
		q->values[q->last] = elem;
		q->last++;
		q-
	}
}

void remove();

void destroy(queue *);

int full(queue *);

int empty(queue *);

void print(queue *);
