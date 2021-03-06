#ifndef LISTA_H
#define LISTA_H
#define MAX 100

struct aluno{
	int nusp;
	char nome[30];
};
typedef struct lista Lista;

Lista *cria();

void libera(Lista *);

int tamanho(Lista *);

int cheia(Lista *);

int vazia(Lista *);

int insere_inicio(Lista *, struct aluno);

int insere_meio(Lista *, struct aluno, int);

int insere_final(Lista *, struct aluno);

int remove_inicio(Lista *);

int remove_meio(Lista *, int);

int remove_final(Lista *);

void print(Lista *);

#endif
