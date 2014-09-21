#ifndef PONTO_H
#define PONTO_H

typedef struct cord ponto;

ponto *criar(float, float);

void inserir(ponto *, float, float);

float calculo(ponto *, ponto *);
#endif
