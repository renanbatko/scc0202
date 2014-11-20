#include <stdio.h>
#include <stdlib.h>
//#include "item.h"
//#include "arvorebb.h"

int main () {
	int Op;

	printf("\n Entre com a opcao desejada :\n\n");

	printf(" 1 - Inserir palavra-chave\n");
	printf(" 2 - Mostrar indice remissivo\n");
	printf(" 3 - Buscar por palavra\n");
	printf(" 4 - Sair\n\n");
	scanf("%d", &Op);


	switch(Op) {
	case 1:
		/* Inserir palavra-chave */
		break;
	case 2:
		/* Mostrar indice remissivo */
		break;
	case 3:
		/* Buscar por palavra */
		break;
	case 4:
		return 0;
	}
	
	
	system("pause");
}