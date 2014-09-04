#include "listaestatica.h"
#include <stdio.h>
#include <stdlib.h>

/*typedef struct{ 
	tipo_chave codigo;
	char nome[50];
	int quantidade;
} livro;*/

int main(void){
	livro *a = (livro *) malloc(sizeof(livro));
	
	lista_estatica *li = (lista_estatica *) malloc(sizeof(lista_estatica));;
	criar_lista(li);
	
	int i;
	for (i = 0; i < 3; i++){
		scanf(" %d %s %d", &a->codigo, a->nome, &a->quantidade);
		inserir_fim(li, a);
	}
	printf("TAMANHO: %d\n", tamanho(li));
	imprimir(li);
	
	printf("BUSCA SEQ: %d\n", busca_sequencial(123, li));
	printf("BUSCA ORD: %d\n", busca_ordenada(7, li));
	printf("BUSCA BIN: %d\n", busca_binaria(123, li));
	
	remover_posicao(li, 1);
	imprimir(li);
	printf("\n\n");
	remover_fim(li);
	imprimir(li);
		
	return 0;
}
