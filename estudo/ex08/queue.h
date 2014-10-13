#ifndef QUEUE_H
#define QUEUE_H
#define MAX 100

typedef struct fila queue;

queue *create();

int add(queue *, int);

int removeq(queue *);

void destroy(queue *);

int full(queue *);

int empty(queue *);

void print(queue *);

#endif

