#ifndef LISTAENCAD_H
#define LISTAENCAD_H

typedef struct cel celula;

typedef struct list lista;

lista *create_list();

int append(lista *, int);

void print(lista *);

void destroy(lista *);

void sort(lista *);

int seek_n_destroy(lista *, int);

#endif
