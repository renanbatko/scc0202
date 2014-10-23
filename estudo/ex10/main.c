#include "pilhadin.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	stack *s;
	s = create();
	
	stacking(s, 1);
	print(s);
	stacking(s, 4);
	print(s);
	stacking(s, 2);
	print(s);
	stacking(s, 0);
	print(s);
	stacking(s, 9);
	print(s);
	stacking(s, 7);
	print(s);
	stacking(s, 3);
	print(s);
	stacking(s, 8);
	print(s);
	
	unstacking(s);
	print(s);
	unstacking(s);
	print(s);
	unstacking(s);
	print(s);
	unstacking(s);
	print(s);
	unstacking(s);
	print(s);
	unstacking(s);
	print(s);
	
	destroy(s);
	
	return 0;
}
