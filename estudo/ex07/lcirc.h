#ifndef LCIRC_H
#define LCIRC_H

typedef struct lista list;

typedef struct celula cell;

list *create_list();

int append(list *, int);

void destroy(list *);

int seek_n_destroy(list *, int);

void sort(list *);

void print(list *);

#endif
