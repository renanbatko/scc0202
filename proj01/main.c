#include "proj.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	list *li;
	li = create();
	
	cell *c;
	c = (cell *) malloc(sizeof(cell));
	
	c->code = 0006;
	strcpy(c->name, "mariao");
	c->relevance = 500;
	strcpy(c->url, "www.mariao.com.br");
	c->n_kw = 1;
	strcpy(c->keyword[c->n_kw-1].word, "bar");
	printf("na main: %s\n", c->keyword[c->n_kw-1].word); 
	
	sorted_insertion(li, c);
	print_structure(li);
	
	return 0;
}
