#include "sortedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct celula{
	int info;
	struct celula *next;
};

struct lista{
	cell *first;
	int size;
};

list *create_list(){
	list *li;
	li = (list *) malloc(sizeof(list));
	
	li->first = NULL;
	li->size = 0;
	
	return li;
}

int insert(list *li, int value) {
	cell *new; //novo elemento
	cell *p; //ponteiro para percorrer a lista
	cell *q = NULL; //elemento anterior
	new = (cell *) malloc(sizeof(cell));
	new->info = value;
	
	p = li->first;
	while (p != NULL && p->info < value) {
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

void print(list *li){
	cell *p;
	p = li->first;
	
	while (p != NULL){
		printf("%d ", p->info);
		p = p->next;
	}
	printf("\n");
}

void destroy(list *li){
	cell *p, *q;
	p = li->first;
	
	while (p != NULL){
		q = p;
		p = p->next;
		free(q);
	}
	
	free(li);
}

int seek_n_destroy(list *li, int key){
	cell *p, *q;
	p = li->first;
	q = p->next;
	
	if (li->first->info == key){
		cell *temp = li->first;
		li->first = li->first->next;
		free(temp);
	}
	
	while (q != NULL && q->info != key){
		p = q;
		q = q->next;
	}
	
	if (q != NULL){
		p->next = q->next;
		free(q);
		
		return 1;
	}
	
	return 0;
}







