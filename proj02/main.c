#include "arvorebb.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define ENTER 10

char *readline() {
	//fflush(stdin);
	char *command = NULL;
	char ch;
	int counter = 0;
	
	do {
		ch = fgetc(stdin);
		command = (char *) realloc(command, (counter+1) * sizeof(char));
		command[counter++] = ch;
	} while (ch != ENTER);
	command[counter-1] = '\0';
	
	return command;
}

void inserir_pc(ARVORE_BINARIA *ab, char *pc) {

	LOCAL *local = (LOCAL *) malloc(sizeof(LOCAL));
	local->pagina = -1;
	local->linha = -1;
	local->prox = NULL;
	
	//ponteiro para o arquivo do texto
	FILE *texto;
	texto = fopen("texto.txt", "r");
	
	char ch, *palavra_texto = NULL;
	int counter = 0;
	int linha = 0;
	int pagina = 0;
	while ((ch = fgetc(texto)) != EOF) {
		if (ch == ' ' || ch == ',' || ch == '.' || ch == '\r' || ch == '\t' || ch == ':' || ch == ';' || ch == '?' || ch == '!' || ch == '\n') {
			if (ch == '\n') linha++;
			if (linha > 40) pagina++;
			
			palavra_texto = (char *) realloc(palavra_texto, (counter + 1) * sizeof(char));
			palavra_texto[counter] = '\0';
			printf("%s == %s ?\n", pc, palavra_texto);
			if (!strcmp(pc, palavra_texto)) {
				//printf("%s == %s\n", pc, palavra_texto);
				//printf("tem alguma coisa igual aqui...\n");
				//printf("l %d p %d\n", linha, pagina);
				local->linha = linha;
				local->pagina = pagina;
				local->prox = NULL;
				
				ITEM *it = busca(ab, palavra_texto[0]);
				//printf("ITEM->palavra = %s\n", it->palavra);
				if (it != NULL) {
					LOCAL *p, *q;
					p = it->local;
					while (p != NULL) {
						q = p;
						p = p->prox;
					}
					q->prox = local;
					
				}
				else {
					ITEM *item = item_criar(pc, local);//busca
					inserir(ab, item);
				}
				
			}
			counter = 0;
			free(palavra_texto);
			palavra_texto = NULL;
		}
		else {
			palavra_texto = (char *) realloc(palavra_texto, (counter + 1) * sizeof(char));
			palavra_texto[counter] = ch;
			counter++;
		}
	}

	rewind(texto);
	free(local);
	fclose(texto);
}

void leitura_arq_palavras(ARVORE_BINARIA *ab) {
	char *palavra = NULL;
	char ch;
	FILE *pf = fopen ("palavras.txt", "r");
	
	int counter = 0;
	do {
		while ((ch = fgetc(pf)) != ',' && ch != '\n') {
			palavra = (char *) realloc(palavra, (counter + 1) * sizeof(char));
			palavra[counter] = ch;
			counter++;
		}
		palavra[counter] = '\0';
		printf("PALAVRA: %s\n", palavra);
		inserir_pc(ab, palavra);
		free(palavra);
		palavra = NULL;
		counter = 0;
	} while (ch != '\n');
	
	int inutil;
	scanf(" %d", &inutil);
	
	fclose(pf);
}

int main(int argc, char *argv[]) {
	int op;
	char *palavra_chave = (char *) malloc(20 * sizeof(char));
	
	ARVORE_BINARIA *ab = criar_arvore();
	
	leitura_arq_palavras(ab);
	em_ordem(ab);
	int inutil;
	scanf(" %d", &inutil);
	
	do {
		system("clear");
		printf("Entre com a opcao desejada:\n----------------------------------\n");
		printf("1 - Inserir palavra-chave\n");
		printf("2 - Mostrar indice remissivo\n");
		printf("3 - Buscar por palavra\n");
		printf("4 - Sair\n");
		printf("Opcao: "); scanf(" %d", &op);
		fflush(stdin);
		switch (op) {
			case 1:
				printf("Nova palavra: "); scanf(" %s", palavra_chave);
			break;
			case 2:
			
			break;
			case 3:
			
			break;
		}
	} while (op >= 0 && op < 4);
		
	free(palavra_chave);
	return 0;
}
