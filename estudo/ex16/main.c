#include "arvoro.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	binary_tree *bt;
	bt = create();
	create_root(bt, 22);
	
	insert(bt->root, 0, 5);
	insert(bt->root, 1, 4);
	insert(bt->root->left, 0, 2);
	insert(bt->root->right, 1, 8);
	insert(bt->root->left->left, 1, 1);
	
	print(bt);
	
	destroy(bt);
	return 0;
}
