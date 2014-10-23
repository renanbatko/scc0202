#include "sparse_matrix.h"
#include <stdlib.h>
#include <stdio.h>

struct cel {
	int l;
	int c;
	float value;
	struct cel *under;
	struct cel *right;
};

struct ms {
	cell **l;
	cell **c;
	int nl;
	int nc;
};

sparse_matrix *create(int nl, int nc) {
	sparse_matrix *new_matrix;
	new_matrix = (sparse_matrix *) malloc(sizeof(sparse_matrix));
	
	if (new_matrix != NULL) {
		new_matrix->nl = nl;
		new_matrix->nc = nc;
		
		new_matrix->l = (cell **) malloc(nl * sizeof(cell *));
		new_matrix->c = (cell **) malloc(nc * sizeof(cell *));
		
		if (new_matrix->l != NULL && new_matrix->c != NULL) {
			int i;
			for (i = 0; i < nl; i++) {
				new_matrix->l[i] = NULL;
			}
			for (i = 0; i < nc; i++) {
				new_matrix->c[i] = NULL;
			}
		}
	}
	
	return new_matrix;
}

void destroy(sparse_matrix *mat) {
//	cell *pi;
//	cell *pj;
//	
//	if (mat != NULL) {
//		
//	}
}

int set(sparse_matrix *, int, int, int);

int get(sparse_matrix *, int, int);

void print(sparse_matrix *);

