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

/* 删除第i个元素，元素从0开始计数 */
int dellist(sequenlist* L, int i) {
	if ((i < 0) || (i > L->last)) {
		printf("error, please input the right i");

		return 0;
	}
	else {
		for (; i < L->last; i++)
			L->data[i] = L->data[i + 1];
		L->last = L->last - 1;

		return (1);
	}
}

/* 建立顺序表，其元素为单个字符 */
void creatlist(sequenlist* L) {
	int n, i;
	char tmp;

	printf("请输入数据的个数：\n");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		printf("data[%d] = ", i);
		fflush(stdin);
		scanf_s("%c", &tmp);
		L->data[i] = tmp;
	}
	L->last = n - 1;
	printf("\n");
}

/* 打印顺序表 */
void printout(sequenlist* L) {
	int i;

	for (i = 0; i <= L->last; i++) {
		printf("data[%d] = ", i);
		printf("%c\n", L->data[i]);
	}
}