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
	
	libera(li);

	return 0;
}
