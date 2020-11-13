#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element; 
element stack[MAX_STACK_SIZE];
int top = -1;

void printStack4() {
	for (int i = 0; i < top; i++) {
		printf("%d |", stack[i]);
	}
	printf("\n");
}
int is_empty() {
	return top == -1;
}

int is_full() {
	return top == MAX_STACK_SIZE - 1;
}

void push(element item) {
	if (is_full()) {
		printf("포화상태\n");
		exit(1);
	}
	else stack[++top] = item;
	printStack4();
}

element pop() {
	if (is_empty()) {
		printf("스택이 비었음\n");
		exit(1);
	}
	else {
		return stack[top--];
	}
	
}


int main() {
	for (int i = 0; i < 10; i++) {
		push(i + 12);
		//pop();
		push(i);
		
	}
}
