#include "lista.h"
#include <stdio.h>
#define N 5

int main(void){	
	int i;
	struct aluno bixo;
	
	Lista *li;
	li = cria();
	
	for (i = 0; i < N; i++){
		scanf(" %d %s", &bixo.nusp, bixo.nome);
		insere_final(li, bixo);
	}
	print(li);
	
	scanf(" %d %s", &bixo.nusp, bixo.nome);
	insere_inicio(li, bixo);
	print(li);
	
	scanf(" %d %s", &bixo.nusp, bixo.nome);
	insere_meio(li, bixo, 2);
	print(li);
	
	remove_final(li);
	print(li);
	
	remove_meio(li, 1);
	print(li);
	
	remove_inicio(li);
	print(li);
	
	printf("%d\n", tamanho(li));
	
	libera(li);

	return 0;
}
