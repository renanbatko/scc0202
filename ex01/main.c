#include <stdio.h>
#include "complexo.h"

int main(void){
	Complexo *p;
	p = criar(2, 3);
	//print_complexo(p);
	atribuir(p, 1, 1);
	//print_complexo(p);
	atribuir(p, 5, 6);
	//print_complexo(p);
	atribuir_real(p, 1);
	//print_complexo(p);
	atribuir_imag(p, 1);
	//print_complexo(p);
	liberar(p);
	
	return 0;
}