#include "complexo.h"
#include <stdlib.h>
//#include <stdio.h>

struct complexo{
	double real;
	double imag;
};

Complexo *criar(double real, double imag){
	Complexo *p = (Complexo *) malloc(sizeof(Complexo));
	p->real = real;
	p->imag = imag;
	
	return p;
}

void liberar(Complexo *p){
	free(p);
}

void copiar(Complexo *p, Complexo *q){
	q->real = p->real;
	q->imag = p->imag;
}

void adicao(Complexo *p, Complexo *q, Complexo *r){
	r->real = p->real + q->real;
	r->imag = p->imag + q->imag;
}

void subtracao(Complexo *p, Complexo *q, Complexo *r){
	r->real = p->real - q->real;
	r->imag = p->imag - q->imag;
}

int e_real(Complexo *p){
	if (p->imag == 0)
		return 1;
	return 0;
}

double real(Complexo *p){
	return p->real;
}

double imag(Complexo *p){
	return p->imag;
}

void atribuir(Complexo *p, double real, double imag){
	p->real = real;
	p->imag = imag;
}

void atribuir_real(Complexo *p, double real){
	p->real = real;
}

void atribuir_imag(Complexo *p, double imag){
	p->imag = imag;
}

/*void print_complexo(Complexo *p){
	printf("COMPLEXO: %.1lf + i%.1lf\n", p->real, p->imag);
}*/