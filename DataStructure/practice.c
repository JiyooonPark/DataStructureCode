#include <stdio.h>
#include <stdbool.h>

// include header files
#include "header.h"

//final number
#define MAX_INT = 100;

//function headers should come first


//main() tells the compiler where to start compiling 
void main() {
	int price = 10000;
	int tax = taxCalculator(price);
	int i = POW(4);
	int a = 10, b = 90;
	printf("The total is %d\n", add(tax, price));
	printf("%d\n",i);
	printFunction();
	switchFunction(4);
	forFunction(1);
	whileFunction(101);
	swap(&a,&b);
	printf("%d %d", a, b);
}

//functions
int taxCalculator(int money) {
	return money * 0.1;
}

int add(int a, int b) {
	return a + b;
}

void printFunction() {
	printf("[%d], [%10d], %.2f, %c, %s", 10, 10, 0.5, 'A', "C practice\n");
	printf("[%d] [%5d] [%05d] [%-15d]\n", 3, 3, 3, 3);
	printf("[%f] [%.3f] [%10.3f] [%-10.3f] ", 0.5, 0.5, 0.5, 0.5);
}

bool ifFunction(int a) {
	if (a > 100) return false;
	else if (a > 50) return true;
	else return false;
}
void switchFunction(int a) {
	switch (a) {
	case 1:
		printf('1');
		break;
	case 2:
		printf('2');
		break;
	default:
		printf("3 or more");
		break;
	}
}
void forFunction(int i) {
	for (; i < 100; i = i + 4) {
		printf("# ");
	}
}
void whileFunction(int i) {
	while (i > 0) {
		printf("%d  ", i);
		i = i - 2;
		if (i == 7) break;
	}
}
void arrays() {
	int intList[30];
	for (int i = 0; i < sizeof(intList) / sizeof(int); i++) {
		intList[i] = i * 10;
	}
}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

struct Person {
	int age; 
	char* name;
};

typedef struct Person People;
