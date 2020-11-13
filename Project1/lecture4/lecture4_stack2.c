#include <stdio.h>
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}
void printStack(StackType* s) {
	for (int i = 0; i < s->top; i++) {
		printf("%d | ", s->data[i]);
	}
	printf("\n");
}
int is_empty(StackType *s){
	return s->top == -1;
}
int is_full(StackType* s) {
	return s->top == MAX_STACK_SIZE - 1;
}
void push(StackType* s, element item) {
	if (is_full(s)) {
		printf("포화상태");
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
	StackType s;
	init_stack(&s);

	for (int i = 0; i < 10; i++) {
		push(&s, i + 12);
		//pop();
		push(&s, i);

	}
}