#ifndef PROJ_H
#define PROJ_H

typedef struct palavraschave kw;

typedef struct celula cell;

typedef struct lista list;

void sorted_insertion(list *, cell);

void insert_kw(list *, char *);

void remove(list *, char *);

void update_relevance(list *, char *, char *);

void print_structure(list *);

void search_by_kw(list *, char *);

#endif

