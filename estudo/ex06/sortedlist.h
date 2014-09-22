#ifndef SORTEDLIST_H
#define SORTEDLIST_H

typedef struct celula cell;

typedef struct lista list;

list *create_list();

int insert(list *, int);

void print(list *);

void destroy(list *);

int seek_n_destroy(list *, int);

#endif
