#include <stdio.h>
#include "complexo.h"

int main(void){
	Complexo *p, *q, *r;
	p = criar(2, 3);
	print(p);
	q = criar(0, 0);
	print(q);
	
	//teste da funcao copiar
	copiar(p, q);
	print(p);
	print(q);
	
	//teste da funcao de adicao
	r = criar(0, 0);
	adicao(p, q, r);
	print(r);
	
	//teste da funcao de subtracao
	subtracao(p, q, r);
	print(r);
	
	//teste da funcao e_real
	int x;
	x = e_real(p);
	printf("%d\n", x);
	x = e_real(q);
	printf("%d\n", x);
	x = e_real(r);
	printf("%d\n", x);
	
	//teste das funcoes real e imag
	double vimag, vreal;
	vreal = real(p);
	vimag = imag(p);

	printf("%.1lf %.1lf\n", vreal, vimag);
	
	//teste da funcao atribuir
	atribuir(q, 12, 13);
	print(q);
	
	//teste da funcao atribuir_real
	atribuir_real(q, -5);
	print(q);
	
	//teste da funcao atribuir_imag
	atribuir_imag(q, -9);
	print(q);
	
	liberar(p);
	liberar(q);
	liberar(r);
	
	return 0;
}
