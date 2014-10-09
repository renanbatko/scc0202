#include "proj.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
	int size;
	cell *first;
	cell *last;
};

list *create() { //ok
	list *new;
	new = (list *) malloc(sizeof(list));
	
	new->size = 0;
	new->first = NULL;
	new->last = NULL;
	
	return new;
}

int sorted_insertion(list *li, cell *c) { //ok
	cell *new; //novo elemento
	cell *p; //ponteiro para percorrer a lista
	cell *q = NULL; //elemento anterior
	
	//copiando os valores para a nova celula
	new = (cell *) malloc(sizeof(cell));
	new->code = c->code;
	strcpy(new->name, c->name);
	new->relevance = c->relevance;
	strcpy(new->url, c->url);
	int i;
	for (i = 0; i < c->n_kw; i++) {
		strcpy(new->keyword[i].word, c->keyword[i].word);
	}
	new->n_kw = c->n_kw;
	
	p = li->first;
	while (p != NULL && p->code < c->code) {
		q = p;
		p = p->next;
	}
	if (q == NULL) {
		new->next = li->first;
		li->first = new;
		
		return 1;
	}
	else {
		new->next = q->next;
		q->next = new;
		
		return 1;
	}
	
	return 0;
}

void insert_kw(list *li, char *new_kw, int keycode) { //ok
	cell *p; //ponteiro para percorrer a list
	p = li->first;
	
	while (p != NULL && p->code != keycode) {
		p = p->next;
	}
	
	strcpy(p->keyword[p->n_kw].word, new_kw);
	p->n_kw++;
}

void remove_site(list *li, char *key_code) {

}

void update_relevance(list *li, char *key_relevance, char *new_relevance) {

}

void print_structure(list *li) {
	cell *p; //ponteiro para percorrer a lista
	p = li->first;
	
	while (p != NULL) {
		printf("%d\n", p->code);
		printf("%s\n", p->name);
		printf("%d\n", p->relevance);
		printf("%s\n", p->url);
		int i;
		for (i = 0; i < p->n_kw; i++) {
			printf("%s\n", p->keyword[i].word);
		}
		//printf("%d\n", p->n_kw);
		p = p->next;
	}
	printf("\n");
}

void search_by_kw(list *li, char *kw) {

}








