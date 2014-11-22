#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int i;
	
	for (i = 0; i < 256; i++) {
		printf("%d[%c]\n", i, i);
	}
	
	return 0;
}
