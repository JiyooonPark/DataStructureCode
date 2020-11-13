#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void print_list(ListNode* head) {
	ListNode* p = head;
	 do{
		printf("<- %s ->", p->data);
		p = p->link;
	}while (p != head);
	printf("\n");
}

ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	strcpy_s(node->data,100, data);
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	//print_list(head);
	return head;
}
ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	strcpy_s(node->data, 100, data);
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	print_list(head);
	return head;
}

int main() {
	ListNode* head = NULL;
	//head = insert_first(head, "hello");
	//head = insert_first(head, "my");
	//head = insert_first(head, "name");
	//head = insert_first(head, "is");
	//head = insert_first(head, "jypark");

	//head = insert_last(head, "20");
	//head = insert_last(head, "30");
	//head = insert_last(head, "40");
	//head = insert_last(head, "50");
	//head = insert_last(head, "10");

	head = insert_first(head, "KIM");
	head = insert_first(head, "PARK");
	head = insert_first(head, "SHIN");

	for (int i = 0; i < 10; i++) {
		printf("now : %s\n", head->data);
		head = head->link;
	}
}