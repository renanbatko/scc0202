#ifndef LISTA_H
#define LISTA_H
#define MAX 100

struct aluno{
	int nusp;
	char nome[30];
	float n1;
	float n2;
	float n3;
};
typedef struct lista Lista;

Lista *cria();

void libera(Lista *);

int tamanho(Lista *);

int cheia(Lista *);

int vazia(Lista *);

#endif
