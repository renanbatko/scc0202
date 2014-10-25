#include "filadim.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	fila *fi;
	fi = create();
	
	entra(fi, 5);
	print(fi);
	entra(fi, 1);
	print(fi);
	entra(fi, 6);
	print(fi);
	entra(fi, 0);
	print(fi);
	entra(fi, 2);
	print(fi);
	entra(fi, 3);
	print(fi);
	entra(fi, 7);
	print(fi);
	entra(fi, 9);
	print(fi);
	
	sai(fi);
	print(fi);
	sai(fi);
	print(fi);
	sai(fi);
	print(fi);
	sai(fi);
	print(fi);
	sai(fi);
	print(fi);
	sai(fi);
	print(fi);
	sai(fi);
	print(fi);
	sai(fi);
	print(fi);
	
	destroy(fi);
	
	return 0;
}
