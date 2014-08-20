#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct complexo Complexo;

Complexo *criar(double, double);

void liberar(Complexo *);

void copiar(Complexo *, Complexo *);

void adicao(Complexo *, Complexo *, Complexo *);

void subtracao(Complexo *, Complexo *, Complexo *);

int e_real(Complexo *);

double real(Complexo *);

double imag(Complexo *);

void atribuir(Complexo *, double, double);

void atribuir_real(Complexo *, double);

void atribuir_imag(Complexo *, double);

#endif
