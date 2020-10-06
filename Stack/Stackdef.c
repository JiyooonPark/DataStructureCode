#include <stdio.h>
#define MAX_SIZE 100
typedef char* element;
typedef struct {
	element* data;
	int capacity;
	int top;
}StackType;
typedef struct {
	StackType s1;
	StackType s2;
}Queue;

void initStack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}
int isEmpty(StackType* s) {
	return s->top == -1;
}
int isFull(StackType* s) {
	return s->top == MAX_SIZE - 1;
}
void printStack(StackType* s) {
	for (int i = 0; i < s->top + 1; i++) {
		//printf("?\n");
		printf("%s | ", (s->data[i]));
	}
	printf("\n");
}
void push(StackType* s, element e) {
	if (isFull(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = e;
	//printStack(s);
}
element pop(StackType* s) {
	if (isEmpty(s)) {
		printf("스택이 비어있습니다. ");
		exit(1);
	}
	else return s->data[(s->top)--];
}
element peek(StackType* s) {
	return s->data[s->top];
}
