#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	element *data;
	int capacity;
	int top;
}StackType;

void printStack(StackType* s) {
	for (int i = 0; i < s->top; i++) {
		printf("%d | ", s->data[i]);
	}
	printf("\n");
}
void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

int is_empty(StackType* s) {
	return s->top == -1;
}
int is_full(StackType* s) {
	return s->capacity == s->top;
}
void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	else s->data[++s->top] = item;
	printStack(s);
}

element pop(StackType* s) {
	if (is_empty(s)) {
		printf("비었음");
	}
	else {
		return s->data[s->top--];
	}
}
element peek(StackType* s) {
	if (is_empty(s)) {
		printf("비었음");
	}
	else {
		return s->data[s->top];
	}
}

int main() {
	StackType *s;
	s = (StackType*)malloc(sizeof(StackType));
	init_stack(s);

	for (int i = 0; i < 10; i++) {
		push(s, i + 12);
		//pop();
		//push(s, i);

	}
	free(s);
}