#include "sortedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
	list *li;
	li = create_list();
	
	insert(li, 5);
	print(li);
	insert(li, 0);
	print(li);
	insert(li, 22);
	print(li);
	insert(li, 1);
	print(li);
	insert(li, 9);
	print(li);
	insert(li, 14);
	print(li);
	insert(li, 4);
	print(li);
	insert(li, 5);
	print(li);
	
	seek_n_destroy(li, 22);
	print(li);
	seek_n_destroy(li, 4);
	print(li);
	seek_n_destroy(li, 0);
	print(li);
	seek_n_destroy(li, 5);
	print(li);
	
	destroy(li);
	
	return 0;
}
