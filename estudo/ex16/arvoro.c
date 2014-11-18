#include "arvoro.h"
#include <stdlib.h>
#include <stdio.h>

binary_tree *create() {
	binary_tree *new;
	new = (binary_tree *) malloc(sizeof(binary_tree));
	
	if (new != NULL) {
		new->root = NULL;
		
		return new;
	}
	
	return NULL;
}

no *create_root(binary_tree *bt, int info) {
	bt->root = (no *) malloc(sizeof(no));
	if (bt->root != NULL) {
		bt->root->left = NULL;
		bt->root->right = NULL;
		bt->root->info = info;
		
		return bt->root;
	}
	
	return NULL;
}

void destroy_aux(no *node) {
	if (node != NULL) {
		destroy_aux(node->left);
		destroy_aux(node->right);
		free(node);
	}
}

void destroy(binary_tree *bt) {
	destroy_aux(bt->root);
	free(bt);
}

//0: left 1: right
int insert(no *node, int son, int info) {
	no *new;
	new = (no *) malloc(sizeof(no));
	
	if (new != NULL) {
		new->left = NULL;
		new->right = NULL;
		new->info = info;
		
		if (son == 0) {
			node->left = new;
		}
		else {
			node->right = new;
		}
		
		return 1;
	}
	
	return 0;
}

int empty(no *node) {
	return (node == NULL);
}

void print_aux(no *node) {
	if (node != NULL) {
		printf("%d\n", node->info);
		print_aux(node->left);
		print_aux(node->right);
	}
}

void print(binary_tree *bt) {
	print_aux(bt->root);
}
