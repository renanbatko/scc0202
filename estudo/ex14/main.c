#include "matrizesp.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	matriz *mat;
	mat = criar(3, 3);
	
	liberar(mat);
	
	return 0;
}
