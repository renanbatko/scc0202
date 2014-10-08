#include "proj.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	list *li;
	li = create();
	
	cell *c;
	c->code = 0006;
	strcpy(c->name, "mariao");
	c->relevance = 500;
	strcpy(c->url, "www.mariao.com.br");
	c->n_kw = 1;
	strcpy(c->keyword[c->n_kw], "bar"); 
	
	int k = sorted_insertion(li, c);
	
	printf("k = %d\n", k);
	
	return 0;
}
