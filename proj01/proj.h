#ifndef PROJ_H
#define PROJ_H

typedef struct palavraschave kw;
struct palavraschave {
	char word[50];
};


typedef struct celula cell;
struct celula {
	int code;
	char name[50];
	int relevance;
	char url[100];
	kw keyword[10];
	int n_kw;
	cell *next;
};

typedef struct lista list;

list *create();

int sorted_insertion(list *, cell *);

void insert_kw(list *, char *);

void remove_site(list *, char *);

void update_relevance(list *, char *, char *);

void print_structure(list *);

void search_by_kw(list *, char *);

#endif

