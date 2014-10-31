#include "matrizesp.h"
#include <stdlib.h>
#include <stdio.h>

struct cel {
	int linha;
	int coluna;
	int dado;
	struct cel *direita;
	struct cel *abaixo;
};

struct matrix {
	int nlinhas;
	int ncolunas;
	celula **linhas;
	celula **colunas;
};

matriz *criar(int nlinhas, int ncolunas) {
	matriz *new;
	new = (matriz *) malloc(sizeof(matriz));
	
	if (new != NULL) {
		int i;
		new->nlinhas = nlinhas;
		new->ncolunas = ncolunas;
		new->linhas = (celula **) malloc(nlinhas * sizeof(celula *));
		new->colunas = (celula **) malloc(ncolunas * sizeof(celula *));
		for (i = 0; i < nlinhas; i++) {
			new->linhas[i] = NULL;
		}
		for (i = 0; i < ncolunas; i++) {
			new->colunas[i] = NULL;
		}
		
		return new;
	}
	
	return NULL;
}

void liberar(matriz *mat) {
	int i;
	for (i = 0; i < mat->nlinhas; i++) {
		if (mat->linhas[i] != NULL) {
			celula *p;
			p = mat->linhas[i]->direita;
			
			while (p != NULL) {
				celula *q;
				q = p;
				p = p->direita;
				free(q);
			}
		}
		free(mat->linhas[i]);
	}
	free(mat->linhas);
	free(mat->colunas);
	free(mat);
}

int set(matriz *mat, int linha, int coluna, int dado) {
	celula *p, *q, *qa;
	
	p = (celula *) malloc(sizeof(celula));
	if (p == NULL || linha > mat->nlinhas || coluna > mat->ncolunas) return 0;
	
	p->linha = linha;
	p->coluna = coluna;
	p->dado = dado;
	
	q = mat->colunas[coluna];
	qa = NULL;
	while (q != NULL) {
		if (q->linha < linha) {
			qa = q;
			q = q->abaixo;
		}
		else {
			if (qa == NULL) 
				mat->colunas[coluna] = p;
			else
				qa->abaixo = p;
			p->abaixo = q;
			break;
		}
	}
	
	if (q == NULL) {
		if (qa == NULL)
			mat->colunas[coluna] = p;
		else
			qa->abaixo = p;
	}
	
	return 1;
}

int get(matriz *, int, int);

void remover(matriz *, int, int);








