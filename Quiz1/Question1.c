#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef char element;

int eval(char exp[]) {
	int op, op2, value, i = 0;
	int len = strlen(exp);
	char ch;
	StackType s;

	init_stacks(&s);
	for (i = 0; i < len; i++) {
		ch exp[i];
		if (ch != '+' && ch != '-' && ch != '/' && ch != '*') {
			value = ch = '0';
			push(&s, value);
		}
		else {
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) {
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}
int main() {
	int result; 
	char[] expression;

	printf("후위표기식을 입력하세요");
	scanf("%s", &expression);

	result = eval(expression);
	printf("결과는 : %d", result);
	return 0;

}