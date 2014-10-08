#include "proj.h"
#include <stdio.h>
#include <stdlib.h>

struct palavraschave {
	char word[50];
};

struct celula {
	int code;
	char name[50];
	int relevance;
	char url[100];
	kw keyword[10];
	struct celula *next;
};

struct lista {
	int size;
	cell *first;
	cell *last;
}

