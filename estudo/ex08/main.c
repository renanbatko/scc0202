#include "queue.h"
#include <stdio.h>

int main(void) {
	queue *q;
	q = create();
	
	add(q, 5);
	add(q, 2);
	add(q, 3);
	add(q, 7);
	add(q, 9);
	add(q, 1);
	add(q, 0);
	add(q, 4);
	add(q, 11);
	add(q, 2);
	add(q, 1);
	add(q, 13);
	
	print(q);
	
	removeq(q);
	print(q);
	removeq(q);
	print(q);
	removeq(q);
	print(q);
	removeq(q);
	print(q);
	removeq(q);
	print(q);
	removeq(q);
	print(q);
	removeq(q);
	print(q);
	removeq(q);

	print(q);
	
	destroy(q);
	
	return 0;
}

