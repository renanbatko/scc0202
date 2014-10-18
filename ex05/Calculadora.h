#ifndef CALCULADORA_H
#define	CALCULADORA_H

#include "BiblioErro.h"
#include "PilhaDinamica.h"

int Calculadora_AvaliaInfixa(char *infix_expr);

char *Calculadora_InfixaParaPosfixa(char *infix_expr);

int Calculadora_AvaliaPosfixa(char *posfix_expr);

int Calculadora_Prioridade(char operador);

#endif

