#include <stdlib.h>

struct deq{
	int *p;
	int inicio;
	int fim;
	int tamanho;
};

deque *cria() {
	fila *a;
	a->p = (int *) malloc(100 * sizeof(int));
	a->inicio = 0;
	a->fim = 0;
	a->tamanho = 0;
	
	return a;
}

void remover_fim(deque *fi) {
	fi->inicio--;
	fi->tamanho--;
}

void inserir_inicio(deque *fi, item elem) {
	fi->fim++;
	fi->tamanho++;
	int i;
	for (i = fi->inicio; i < fi->fim; i++){
		fi->p[i+1] = fi->p[i];
	}
	fi->p[fi->inicio] = elem;
}
