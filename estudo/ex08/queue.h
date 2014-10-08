#ifndef QUEUE_H
#define QUEUE_H

typedef struct fila queue;

queue *create(int);

void add(queue *, int);

void remove(queue *);

void destroy(queue *);

int full(queue *);

int empty(queue *);

void print(queue *);

#endif

