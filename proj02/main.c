#include "arvorebb.h"
#include <stdlib.h>
#include <stdio.h>

void leitura (ARVORE_BINARIA *ab) {
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
		free(palavra);
		palavra = NULL;
		counter = 0;
	} while (ch != '\n');
	
	
	int inutil;
	scanf(" %d", &inutil);
	
	fclose(pf);
}

void inserir_pc(ARVORE_BINARIA *ab, char *pc) {

	LOCAL *local = (LOCAL *) malloc(sizeof(LOCAL));
	local->pagina = -1;
	local->linha = -1;
	local->prox = NULL;
	
	
	ITEM *item = item_criar(pc, local);
	inserir(ab, *item);
	
	free(local);
}


int main(int argc, char *argv[]) {
	int Op;
	char pc[20];
	
	ARVORE_BINARIA *ab = AB_CriarArvore();
	
	leitura(ab);
	
	do {
		system("clear");
		printf("\n Entre com a opcao desejada :\n\n");
		printf(" 1 - Inserir palavra-chave\n");
		printf(" 2 - Mostrar indice remissivo\n");
		printf(" 3 - Buscar por palavra\n");
		printf(" 4 - Sair\n\n");
		scanf("%d", &Op);
		
		switch(Op) {
			case 1:
				/* Inserir palavra-chave */
				//scanf(" %s", pc);
				//inserir_pc(ab, pc);
			break;
			case 2:
				/* Mostrar indice remissivo */
				emordem(ab);
				int inutil;
				scanf(" %d", &inutil);
			break;
			case 3:
				/* Buscar por palavra */
			break;
			case 4: break;
		}
	} while (Op != 4);
	
	return 0;
}
