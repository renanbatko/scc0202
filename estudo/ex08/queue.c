#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct fila {
	int values[MAX];
	int first;
	int last;
	int size;
};

queue *create() {
	queue *new;
	new = (queue *) malloc(sizeof(queue));
	
	new->first = 0;
	new->last = 0;
	new->size = 0;
	
	return new;
}

int add(queue *q, int elem) {
	if (!full(q)) {
		q->values[q->last] = elem;
		q->last = (q->last + 1) % MAX;
		q->size++;
		
		return 1;
	}
	
	return 0;
}

int removeq(queue *q) {
	if (!empty(q)) {
		q->first = (q->first + 1) % MAX;
		q->size--;
		
		return 1;
	}
	
	return 0;
}

void destroy(queue *q) {
	free(q->values);
}

int full(queue *q) {
	return (q->size == MAX);
}

int empty(queue *q) {
	return (q->size == 0);
}

void print(queue *q) {
	int i;
	for (i = q->first; i < q->first + q->size; i++) {
		printf("%d ", q->values[i]);
	}
	printf("\n");
}

