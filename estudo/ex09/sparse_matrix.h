#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

typedef struct cel cell;

typedef struct ms sparse_matrix;

sparse_matrix *create(int, int);

void destroy(sparse_matrix *);

int set(sparse_matrix *, int, int, float);

float get(sparse_matrix *, int, int);

void print(sparse_matrix *);

#endif

