#include "lcirc.h"
#include <stdio.h>
#include <stdlib.h>

struct lista {
	int size;
	cell *first;
	cell *last;
};

struct celula {
	int info;
	struct celula *next;
};

list *create_list() {
	list *li;
	li = (list *) malloc(sizeof(list));
	
	if (li != NULL) {
		li->size = 0;
		li->first = NULL;
		li->last = NULL;
		
		return li;
	}
	
	return NULL;
}

int append(list *li, int value) {
	cell *new;
	new = (cell *) malloc(sizeof(cell));
	
	if (new != NULL) {
		new->info = value;
		if (li->first == NULL) {
			li->last = new;
			li->first = new;
			new->next = li->first;
			
			printf("primeiro elemento [%d] inserido...\n", new->info);
			return 1;
		}
		
		cell *p; //para percorrer a lista
		cell *q; //aponta para o elemento anterior
		p = li->first;
		do {
			q = p;
			p = p->next;
		} while (p != li->first);
		if (q == NULL) printf("fuck!\n");
		new->next = li->first;
		q->next = new;
		li->last->next = li->first;
		
		printf("outro elemento [%d]->[%d]adicionado...\n", q->info, new->info);
		return 1;
	}
	
	return 0;
}

void destroy(list *li) {
	cell *p;
	cell *q;
	
	p = li->first;
	do {
		q = p;
		free(q);
		p = p->next;
	} while (p != li->first);
	
	free(li);
}

int seek_n_destroy(list *li, int key) {
	cell *p;
	cell *q;
	
	if (li->first->info == key) {
		q = li->first;
		li->first = li->first->next;
		li->last->next = li->first;
		
		free(q);
		
		return 1;
	}
	
	p = li->first;
	q = p;
	do {
		q = p;
		p = p->next;
	} while (p != li->first && p->info == key);
	
	if (p != li->first) {
		q->next = p->next;
		free(p);
		
		return 1;
	}
	
	return 0;
}

void sort(list *li){
	
}

void print(list *li){
	cell *p;
	p = li->first;
	
	printf("%d ", p->info);
	p = p->next;

	while (p != li->first) {
		printf("%d ", p->info);
		p = p->next;
	}

	printf("\n");
}











