#ifndef _ARVORO_H_
#define _ARVORO_H_

struct nod {
	int info;
	struct nod *left;
	struct nod *right;
};
typedef struct nod no;

struct arvore {
	struct nod *root;
};
typedef struct arvore binary_tree;

binary_tree *create();

no *create_root(binary_tree *, int);

void destroy(binary_tree *);

int insert(no *, int, int);

int empty(no *);

void print(binary_tree *);

#endif
