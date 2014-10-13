#include "proj.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**************************************************************/
/* NOME: int fill_structure(list *li)                         */
/* DESCRICAO: pega as informacoes do arquivo CVS e preenche a */
/*            lista                                           */
/* PARAMETROS: list *li - ponteiro para a lista               */
/* RETORNO: 1 - funcao executada com sucesso                  */
/*          -1 - falha na abertura do arquivo                 */
/***************************************************************/
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

void form_insertion(list *li) {
	cell *c;
	c = (cell *) malloc(sizeof(cell));
	
	printf("\n-----Inserir novo site-----\n");
	printf("Codigo: "); scanf(" %d", &c->code);
	printf("Nome: "); scanf(" %s", c->name);
	printf("Relevancia: "); scanf(" %d", &c->relevance);
	printf("URL: "); scanf(" %s", c->url);
	printf("Numero de palavras chave: "); scanf(" %d", &c->n_kw);
	int i;
	for (i = 0; i < c->n_kw; i++) {
		printf("Palavra chave [%d]: ", i); scanf(" %s", c->keyword[i].word);
	}
	
	sorted_insertion(li, c);
	
	printf("\nSite inserido!\n");
	
	free(c);
}

void form_insert_kw(list *li) {
	int code;
	char new_kw[50];
	
	printf("\n-----Inserir nova palavra chave-----\n");
	printf("Codigo: "); scanf(" %d", &code);
	printf("Nova palavra chave: "); scanf(" %s", new_kw);
	
	insert_kw(li, new_kw, code);
	
	printf("\nSite inserido!\n");
}

void form_remove_site(list *li) {
	int code;
	
	printf("\n-----Remover site-----\n");
	printf("Codigo: "); scanf(" %d", &code);
	
	remove_site(li, code);
	
	printf("\nSite removido!\n");
}

void form_update_relevance(list *li) {
	int code;
	int new_relevance;
	
	printf("\n-----Atualizar relevancia-----\n");
	printf("Codigo: "); scanf(" %d", &code);
	printf("Nova relevancia: "); scanf(" %d", &new_relevance);
	
	update_relevance(li, code, new_relevance);
	
	printf("\nRelevancia atualizada!\n");
}

void form_search(list *li) {
	char kw[50];
	
	printf("\n-----Pesquisa por palavra chave-----\n");
	printf("Palavra chave: "); scanf(" %s", kw);
	
	search_by_kw(li, kw);
	
	printf("\nPesquisa finalizada!\n");
}

void form_suggest(list *li) {
	char kw[50];
	
	printf("\n-----Sugestoes-----\n");
	printf("Palavra chave: "); scanf(" %s", kw);
	
	suggest_site(li, kw);
	
	printf("\nPesquisa finalizada!\n");
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
	//print_structure(li);
	
	//insert_kw(li, "batata", 3);
	//print_structure(li);
	
	//remove_site(li, 1);
	//print_structure(li);
	
	//update_relevance(li, 2, 12);
	//print_structure(li);
	
	//search_by_kw(li, "Sao Carlos");
	
	while (1) {
		char unuseful;
		system("clear");
		printf("MINI GOOGLE\n\n");
		printf("1 - Inserir novo site\n");
		printf("2 - Inserir palavra chave\n");
		printf("3 - Remover site\n");
		printf("4 - Atualizar relevancia\n");
		printf("5 - Mostrar estrutura de dados\n");
		printf("6 - Buscar por palavra chave\n");
		printf("7 - Sugerir sites\n");
		printf("8 - Sair\n");
		int op;
		printf("Opcao: "); scanf(" %d", &op);
		
		if (op < 1 || op > 8) {
			continue;
		}
		if (op == 1) {
			form_insertion(li);
			printf("Digite 'q'+ Enter para continuar...\n");
			scanf(" %c", &unuseful);
		}
		if (op == 2) {
			form_insert_kw(li);
			printf("Digite 'q'+ Enter para continuar...\n");
			scanf(" %c", &unuseful);
		}
		if (op == 3) {
			form_remove_site(li);
			printf("Digite 'q'+ Enter para continuar...\n");
			scanf(" %c", &unuseful);
		}
		if (op == 4) {
			form_update_relevance(li);
			printf("Digite 'q'+ Enter para continuar...\n");
			scanf(" %c", &unuseful);
		}
		if (op == 5) {
			print_structure(li);
			printf("Digite 'q'+ Enter para continuar...\n");
			scanf(" %c", &unuseful);
		}
		if (op == 6) {
			form_search(li);
			printf("Digite 'q'+ Enter para continuar...\n");
			scanf(" %c", &unuseful);
		}
		if (op == 7) {
			form_suggest(li);
			printf("Digite 'q'+ Enter para continuar...\n");
			scanf(" %c", &unuseful);
		}
		if (op == 8) {
			break;
		}
	}
	
	destroy(li);
	
	return 0;
}

