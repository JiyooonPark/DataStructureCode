#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

//8253-9*+7-*
//423*+2/3+

typedef char element;
typedef struct stack{
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}
int is_empty(StackType* s) {
	return (s->top == -1);
}
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택공백에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
void show(StackType* s) {
	for (int i = 0; i < s->top; i++) {
		printf("%d ", peek(s));
	}
	printf("\n");
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);

	}
	else return s->data[(s->top)--];
}


int eval(char exp[]) {
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;
	int pushed = 0;
	StackType s;

	init_stack(&s);
	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '/' && ch != '*') {
			value = ch - '0';
			push(&s, value);
			pushed++;
		}
		else {
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) {
			case '+': push(&s, op1 + op2); pushed++; break;
			case '-': push(&s, op1 - op2); pushed++; break;
			case '*': push(&s, op1 * op2); pushed++; break;
			case '/': push(&s, op1 / op2); pushed++; break;
			}
		}
		//printf("ch : %c\n", ch);
		//show(&s);
	}
	printf("pushed : %d\n", pushed);
	return pop(&s);
}
int main() {
	int result;
	char expression[100];

	printf("후위표기식을 입력하세요\n");
	scanf("%s", expression);

	result = eval(expression);
	printf("결과는 : %d.", result);
	return 0;

}