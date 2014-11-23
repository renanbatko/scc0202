#include "arvorebb.h"
#include <stdlib.h>
#include <stdio.h>
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
	
	
	ITEM *item = item_criar(pc, local);
	inserir(ab, item);
	
	free(local);
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
	//char *palavra_chave;
	
	ARVORE_BINARIA *ab = criar_arvore();
	
	leitura_arq_palavras(ab);
	
	do {
		system("clear");
		printf("Entre com a opcao desejada:\n----------------------------------\n");
		printf("1 - Inserir palavra-chave\n");
		printf("2 - Mostrar indice remissivo\n");
		printf("3 - Buscar por palavra\n");
		printf("4 - Sair\n");
		printf("Opcao: "); scanf(" %d", &op);
		
		switch (op) {
			case 1:
			
			break;
			case 2:
			
			break;
			case 3:
			
			break;
		}	
	} while (op > 0 && op < 4);
		
	
	return 0;
}
