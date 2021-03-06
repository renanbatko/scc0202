#include "listaencad.h"
#include <stdlib.h>
#include <stdio.h>

struct cel{
	int info;
	struct cel *next;
};

struct list{
	int size;
	celula *first;
	celula *last;
};

lista *create_list(){
	lista *li;
	li = (lista *) malloc(sizeof(lista));
	
	li->size = 0;
	li->first = NULL;
	li->last = NULL;
	
	return li;
}

int append(lista *li, int info){
	celula *c;
	c = (celula *) malloc(sizeof(celula));
	
	if (c != NULL){
		c->info = info;
		c->next = NULL;
	
		if (li->first == NULL){
			li->first = c;
		}
		else {
			li->last->next = c;
		}
		li->last = c;
		
		return 1;
	}
	
	return 0;
}

int seek_n_destroy(lista *li, int key){
	celula *p, *q;
	p = li->first;
	q = p->next;
	
	//if para verificar se key eh igual ao primeiro elemento
	if (p->info == key){
		li->first = q;
		free(p);
		
		return 1;
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

void destroy(lista *li){
	celula *p, *q;
	p = li->first;
	
	while (p != NULL){
		//printf("node destroyed...\n");
		q = p;
		p = p->next;
		free(q);
	}
	
	free(li);
	//printf("everything destroyed!!!\n");
}

void swap(celula *p, celula *q){
	//printf("swapping...\n");
	int aux;
	aux = p->info;
	p->info = q->info;
	q->info = aux;
}

void sort(lista *li){
	celula *p, *q, *elem, *temp;
	p = li->first;
	//p = ini->next;
	
	while (p != NULL){
		elem = p;
		q = elem;
		
		while (q != NULL){
			temp = q;
			//printf("temp->info < elem->info		%d < %d?\n", temp->info, elem->info);
			if (temp->info < elem->info){
				swap(elem, temp);
			}
			q = q->next;
		}
		p = p->next;
	}
}

void print(lista *li){
	celula *c;
	c = li->first;
	
	while (c != NULL){
		printf("%d ", c->info);
		c = c->next;
	}
	printf("\n");
}
















