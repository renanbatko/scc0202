#include "proj.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fill_structure(list *li) { //ok
	FILE *fp;
	fp = fopen("googlebot.txt", "r+");
	
	if (fp == NULL) {
		return -1;
	}
	
	char ch, *temp = NULL;
	cell *p = (cell *) malloc(sizeof(cell));
	int counter = 0;
	int argc = 0;
	int i = 0;
	while ((ch = fgetc(fp)) != EOF) {
		temp = (char *) realloc(temp, (counter + 1) * sizeof(char));
		if (ch != ',' && ch != '\n') {
			//printf("aqui ok...\n");
			temp[counter] = ch;
			counter++;
		}
		else {
			temp[counter] = '\0';
			counter = 0;
			
			//printf("temp: %s\n", temp);
			//printf("argc: %d\n", argc);
			
			if (argc == 0) {
				p->code = atoi(temp);
			}
			if (argc == 1) {
				strcpy(p->name, temp);
			}
			if (argc == 2) {
				p->relevance = atoi(temp);
			}
			if (argc == 3) {
				strcpy(p->url, temp);
			}
			if (argc >= 4) {
				//printf("%s\n", temp);
				strcpy(p->keyword[i].word, temp);
				//printf("%d\n", p->n_kw);
				i++;
				p->n_kw = i + 1;
			}
			
			if (ch != '\n') {
				argc++;	
			}
			else {
				argc = 0;
				i = 0;
				//insercao dos dados da linha lida
				sorted_insertion(li, p);
			}
		}
	}
	
	fclose(fp);
	free(temp);
	return 1;
}

int main(void) {
	list *li;
	li = create();
	
	/*cell *c;
	c = (cell *) malloc(sizeof(cell));
	
	c->code = 0006;
	strcpy(c->name, "mariao");
	c->relevance = 500;
	strcpy(c->url, "www.mariao.com.br");
	c->n_kw = 1;
	strcpy(c->keyword[c->n_kw-1].word, "bar");
	printf("na main: %s\n", c->keyword[c->n_kw-1].word); 
	
	sorted_insertion(li, c);
	*/
	
	fill_structure(li);
	print_structure(li);
	
	//insert_kw(li, "batata", 3);
	//print_structure(li);
	
	//remove_site(li, 1);
	//print_structure(li);
	
	//update_relevance(li, 2, 12);
	//print_structure(li);
	
	search_by_kw(li, "Sao Carlos");
	
	return 0;
}

