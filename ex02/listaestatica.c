#include "listaestatica.h"
#include <stdlib.h>
#include <stdio.h>

void criar_lista(lista_estatica *lista){
	//lista = (lista_estatica *) malloc(sizeof(lista_estatica));
	lista->primeiro = 0;
	lista->ultimo = 0;
}

int inserir_fim(lista_estatica *lista, livro *codigo){
	if (cheia(lista) == 0){
		lista->Item[lista->ultimo] = *codigo;
		lista->ultimo++;
		return 1;
	}
	return 0;
}

int inserir_ordenado(lista_estatica *lista, livro *codigo){
	if (cheia(lista) == 0){
		int i;
		for (i = lista->primeiro; i < lista->ultimo; i++){
			if (lista->Item[i].codigo > codigo->codigo){
				int j;
				for (j = lista->ultimo-1; j >= i ; j--){
					lista->Item[j+1] = lista->Item[j];
				}
				lista->Item[i] = *codigo;
				lista->ultimo++;
				return 1;
			}
		}
	}
	return 0;
}

boolean inserir_posicao(lista_estatica *lista, int pos, livro *codigo){
	if (cheia(lista) == 0){
		int i;
		for (i = lista->ultimo-1; i >= pos; i--){
			lista->Item[i+1] = lista->Item[i];
		}
		lista->Item[pos] = *codigo;
		lista->ultimo++;
		return TRUE;
	}
	return FALSE;
}

boolean remover_fim(lista_estatica *lista){
	if (vazia(lista) == 0){
		lista->ultimo--;
		return TRUE;
	}
	return FALSE;
}

boolean remover_posicao(lista_estatica *lista, int pos){
	if (vazia(lista) == 0){
		if (pos >= lista->primeiro && pos < lista->ultimo){
			int i;
			for (i = pos; i < lista->ultimo; i++){
				lista->Item[i] = lista->Item[i+1];
			}
			lista->ultimo--;
			return TRUE;
		}
		return FALSE;
	}
	return FALSE;
}

int busca_sequencial(tipo_chave x, lista_estatica *lista){
	if (vazia(lista) == 0){
		int i;
		for (i = lista->primeiro; i < lista->ultimo; i++){
			if (lista->Item[i].codigo == x){
				return i;
			}
		}
		return -1;
	}
	return -1;
}

int busca_ordenada(tipo_chave x, lista_estatica *lista){
	if (vazia(lista) == 0){
		int i;
		for (i = lista->primeiro; i < lista->ultimo; i++){
			if (lista->Item[i].codigo > x){
				break;
			}
			if (lista->Item[i].codigo == x){
				return i;
			}
		}
		return -1;
	}
	return -1;
}

int busca_binaria(tipo_chave x, lista_estatica *lista){
	//insertion sort
	int i, j;
	livro temp;
	for (j = 1; j < lista->ultimo; j++){
		temp = lista->Item[j];
		i = j - 1;
		while (i >= 0 && lista->Item[i].codigo > temp.codigo){
			lista->Item[i+1] = lista->Item[i];
			i--;
		}
		lista->Item[i+1] = temp;
	}
	//end insertion sort
	
	//inicio busca binaria
	int begin, end, mid;
	begin = lista->primeiro;
	end = lista->ultimo-1;
	while (end >= begin){
		mid = (begin + end)/2;
		if (x == lista->Item[mid].codigo){
			return mid;
		}
		if (x < lista->Item[mid].codigo){
			end = mid - 1;
		} else{
			begin = mid + 1;
		}
	}
	return -1;
}

int tamanho(lista_estatica *lista){
	return (lista->ultimo - lista->primeiro);
}

boolean vazia(lista_estatica *lista){
	if (lista->ultimo == 0){
		return TRUE;
	}
	return FALSE;
}

boolean cheia(lista_estatica *lista){
	if (lista->ultimo == TAM_MAX){
		return TRUE;
	}
	return FALSE;
}

void imprimir(lista_estatica *lista){
	int i;
	for (i = lista->primeiro; i < lista->ultimo; i++){
		printf("[%d] [%s] [%d]\n", lista->Item[i].codigo, lista->Item[i].nome, lista->Item[i].quantidade);
	}
}

