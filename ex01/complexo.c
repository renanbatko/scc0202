#include "complexo.h"
#include <stdlib.h>
#include <stdio.h>

struct complexo{
	double real;
	double imag;
};

Complexo *criar(double real, double imag){
	printf("Complexo *criar(double real, double imag)\n");	
	
	Complexo *p = (Complexo *) malloc(sizeof(Complexo));
	p->real = real;
	p->imag = imag;
	
	return p;
}

void liberar(Complexo *p){
	printf("void liberar(Complexo *p)\n");
	
	free(p);
}

void copiar(Complexo *p, Complexo *q){
	printf("void copiar(Complexo *p, Complexo *q)\n");

	q->real = p->real;
	q->imag = p->imag;
}

void adicao(Complexo *p, Complexo *q, Complexo *r){
	printf("void adicao(Complexo *p, Complexo *q, Complexo *r)\n");

	r->real = p->real + q->real;
	r->imag = p->imag + q->imag;
}

void subtracao(Complexo *p, Complexo *q, Complexo *r){
	printf("void subtracao(Complexo *p, Complexo *q, Complexo *r)\n");

	r->real = p->real - q->real;
	r->imag = p->imag - q->imag;
}

int e_real(Complexo *p){
	printf("int e_real(Complexo *p)\n");	
	
	if (p->imag == 0)
		return 1;
	return 0;
}

double real(Complexo *p){
	printf("double real(Complexo *p)\n");
	
	return p->real;
}

double imag(Complexo *p){
	printf("double imag(Complexo *p)\n");

	return p->imag;
}

void atribuir(Complexo *p, double real, double imag){
	printf("void atribuir(Complexo *p, double real, double imag)\n");

	p->real = real;
	p->imag = imag;
}

void atribuir_real(Complexo *p, double real){
	printf("void atribuir_real(Complexo *p, double real)\n");

	p->real = real;
}

void atribuir_imag(Complexo *p, double imag){
	printf("void atribuir_imag(Complexo *p, double imag)\n");

	p->imag = imag;
}

void print(Complexo *p){
	printf("%.1lf + i%.1lf\n", p->real, p->imag);
}
