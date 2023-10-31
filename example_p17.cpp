#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1024
typedef char datatype;
typedef struct {
	datatype data[MAXSIZE];
	int last;
}sequenlist;

int insert(sequenlist* L, datatype x, int i) {
	int j;
	if (L->last == MAXSIZE - 1) {
		printf("overflow");

		return 0;
	}
	else if ((i < 0) || (i > L->last)) {
		printf("error, please input the right 'i'");
		
		return 0;
	}
	else {
		for (j = L->last; j >= i; j--)
			L->data[j + 1] = L->data[j];
		L->data[i] = x;
		L->data = L->last + 1;
	}
	return (1);
}