#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[100];
}element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* p = pre->link->link;
	pre->link = p;
	return head;
}
void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%s -> ", p->data);
	}
	printf("NULL \n");
}

//int main() {
//	ListNode* head = NULL;
//	element e = { "Apple" };
//	for (int i = 0; i < 5; i++) {
//		head = insert_first(head, e);
//		print_list(head);
//	}
//	for (int i = 0; i < 5; i++) {
//		head = delete_first(head, i);
//		print_list(head);
//	}
//	return 0;
//}
ListNode* reverse(ListNode* head) {
	ListNode* p, * r, * q;
	p = head;
	q = NULL;
	while (p != NULL) {

		r = q;
		printf("r: ");
		print_list(r);
		printf("\n");
		q = p;
		printf("q: ");
		print_list(q);
		printf("\n");
		printf("p: ");
		print_list(p);
		printf("\n");
		p = p->link;
		printf("p: ");
		print_list(p);
		printf("\n");
		printf("q: ");
		print_list(q);
		printf("\n");
		q->link = r;
		printf("q: ");
		print_list(q);
		printf("\n");
	}
	return q;
}
int main() {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	element e[6] = { "Apple", "b", "c", "d", "E", "f" };
	for (int i = 0; i < 6; i++) {
		head1 = insert_first(head1, e[i]);

	}print_list(head1);
	head2 = reverse(head1);
	print_list(head2);
}
