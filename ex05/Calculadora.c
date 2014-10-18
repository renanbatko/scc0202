#include "Calculadora.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int is_operator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') ? 1 : 0;
}

int is_number(char ch) {
	return (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9') ? 1 : 0;
}

int is_bracket(char ch) {
	return (ch == '(' || ch == ')') ? 1 : 0;
}

int brackets_ok(char *expr, int size) {
	int i, flag = 0;
	for (i = 0; i < size; i++) {
		if (expr[i] == '(') flag = 1;
		if (expr[i] == ')' && flag == 0) return 0;
		if (expr[i] == ')' && flag == 1) flag = 0;
	}
	if (flag == 0) return 1;
	else return 0;
	
	return -1;
}

int rest_ok(char *expr, int size) {
	int i;
	for (i = 0; i < size-1; i++) {
		if (is_operator(expr[i]) && is_operator(expr[i+1])) return 0;
		if (is_operator(expr[i]) && expr[i+1] == ')') return 0;
		if (expr[i] == '(' && is_operator(expr[i+1])) return 0;
	}
	
	return 1;
}

int Calculadora_AvaliaInfixa(char *infix_expr) {
	int size, i;
	size = strlen(infix_expr);
	
	for (i = 0; i < size; i++) {
		if (is_operator(infix_expr[i]) || is_number(infix_expr[i]) || is_bracket(infix_expr[i])) {
			continue;
		}
		else {
			
			return ERRO_LEXICO;
		}
	}
	if (brackets_ok(infix_expr, size)) {
		if (rest_ok(infix_expr, size)) {
			return ERRO_SUCESSO;
		}
		else {
			return ERRO_SINTAXE;
		}
	}
	else {
		return ERRO_SINTAXE;
	}
	printf("retornei aqui...\n");
	return ERRO_SUCESSO;
}

char *Calculadora_InfixaParaPosfixa(char *infix_expr);

int Calculadora_AvaliaPosfixa(char *posfix_expr);

int Calculadora_Prioridade(char operador);
