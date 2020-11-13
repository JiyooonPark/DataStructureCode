#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}StackNode;
typedef struct {
	StackNode* top;
}LinkedStackType;

void init(LinkedStackType* s) {
	s->top = NULL;
}
int is_empty(LinkedStackType* s) {
	return s->top == NULL;
}
int is_full(LinkedStackType* s) {
	return 0;
}
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}
element pop(LinkedStackType* s) {
	
	if (is_empty(s)) {
		printf("비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		return data;
	}
}

void print_list(LinkedStackType* s) {
	StackNode* p = s->top;
	//do {
	//	printf("%d | ", p->data);
	//	p = p->link;
	//} while (p != NULL);
	for (p; p != NULL; p = p->link) {
		printf("%d -> ", p->data);
	}
	printf("NULL\n");
}


int main() {

	LinkedStackType* s = (LinkedStackType*) malloc(sizeof(LinkedStackType));
	init(s);

	for (int i = 0; i < 10; i++) {
		push(s, i);
		print_list(s);
	}

	for (int i = 0; i < 10; i++) {
		pop(s);
		print_list(s);
	}
}