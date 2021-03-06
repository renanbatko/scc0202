#include "ponto.h"
#include <stdlib.h>
#include <math.h>

struct cord{
	float x;
	float y;
};

ponto *criar(float x, float y){
	ponto *p;
	p = (ponto *) malloc(sizeof(ponto));
	
	p->x = x;
	p->y = y;
	
	return p;
}

void inserir(ponto *p, float x, float y){
	p->x = x;
	p->y = y;
}

float calculo(ponto *a, ponto *b){
	return sqrt(pow(b->x-a->x, 2) + pow(b->y-a->y, 2));	
}

