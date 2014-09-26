#include "lcirc.h"
#include <stdio.h>

int main(void) {
	list *li;
	li = create_list();
	
	append(li, 4);
	print(li);
	append(li, 2);
	print(li);
	append(li, 9);
	print(li);
	append(li, 1);
	print(li);
	append(li, 18);
	print(li);
	append(li, 3);
	print(li);
	
	destroy(li);
	
	return 0;	
}
