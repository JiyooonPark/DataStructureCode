#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101

typedef struct {
	float coef;
	int expon;
}polynomial;
polynomial terms[MAX_TERMS] = { {8,3},{7,1},{1,0},{10,3},{3,2},{1,0} };
int avail = 6;
char compare(int a, int b) {
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}
void attach(float coef, int expon) {
	if (avail > MAX_TERMS) {
		fprintf(stderr, "���� ������ �ʹ� ����\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}

void poly_Add2(int As, int Ae, int Bs, int* Cs, int *Ce) {

}