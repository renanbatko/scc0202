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

int remove_site(list *li, int keycode) { //ok
	cell *p;
	cell *q;
	q = li->first;
	p = q->next;
	
	if (li->first->code == keycode) {
		cell *temp = li->first;
		li->first = li->first->next;
		free(temp);
	}
	
	while (p != NULL && p->code != keycode) {
		q = p;
		p = p->next;
	}
	
	if (p != NULL) {
		q->next = p->next;
		free(p);
		
		return 1;
	}
	
	return 0;
}

void update_relevance(list *li, int keycode, int new_relevance) { //ok
	cell *p; //ponteiro para pecorrer a lista
	p = li->first;
	
	while (p != NULL && p->code != keycode) {
		p = p->next;
	}
	
	p->relevance = new_relevance;
}

void print_structure(list *li) { //ok
	cell *p; //ponteiro para percorrer a lista
	p = li->first;
	
	while (p != NULL) {
		printf("\n----------------------------------\n");
		printf("Codigo: %d\n", p->code);
		printf("Nome: %s\n", p->name);
		printf("Relevancia: %d\n", p->relevance);
		printf("URL: %s\n", p->url);
		int i;
		for (i = 0; i < p->n_kw; i++) {
			printf("Palavra chave [%d]: %s\n", i, p->keyword[i].word);
		}
		//printf("%d\n", p->n_kw);
		p = p->next;
		printf("\n----------------------------------\n");
	}
}

typedef struct tmp {
	char url[100];
	int relevance;
} results;

void sort_by_relevance(results *r, int size) {
	int i, j;
	results temp;
	for (j = 1; j < size; j++) {
		temp = r[j];
		i = j - 1;
		while (i >= 0 && r[i].relevance < temp.relevance) {
			r[i+1].relevance = r[i].relevance;
			strcpy(r[i+1].url, r[i].url);
			i--;
		}
		r[i+1].relevance = temp.relevance;
		strcpy(r[i+1].url, temp.url);
	}
}


void search_by_kw(list *li, char *kw) {
	results *r;
	r = NULL;
	
	cell *p; //ponteiro para pecorrer a lista
	p = li->first;
	
	int i, counter = 0;
	while (p != NULL) {
		for (i = 0; i < p->n_kw; i++) {
			if (!strcmp(p->keyword[i].word, kw)) {
				r = (results *) realloc(r, (counter + 1) * sizeof(results));
				strcpy(r[counter].url, p->url);
				r[counter].relevance = p->relevance;
				counter++;
			}
		}
		p = p->next;
	}
	
	//funcao que ordena os resultados por relevancia
	sort_by_relevance(r, counter);
	
	for (i = 0; i < counter; i++) {
		printf("%s %d\n", r[i].url, r[i].relevance);
	}
	
	free(r);
}

void suggest_site(list *li, char *kw) {
	cell *p;
	p = li->first;
	struct palavraschave *kword;
	kword = NULL;
	
	int i, counter  = 0;
	while (p != NULL) {
		for (i = 0; i < p->n_kw; i++) {
			if (!strcmp(p->keyword[i].word, kw)) {
				int j;
				for (j = 0; j < p->n_kw; j++) {
					if (strcmp(p->keyword[j].word, kw) != 0) {
						kword = (struct palavraschave *) realloc(kword, (counter + 1) * sizeof(struct palavraschave));
						strcpy(kword[counter].word, p->keyword[j].word);
						counter++;
					}
				}
			}
		}
		p = p->next;
	}
	
	for (i = 0; i < counter; i++) {
		search_by_kw(li, kword[i].word);
	}
	
	free(kword);
}



void destroy(list *li) {
	cell *p;
	cell *q;
	
	p = li->first;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	
	free(li);
}



















