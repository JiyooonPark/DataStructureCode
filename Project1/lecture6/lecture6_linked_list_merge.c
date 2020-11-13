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
ListNode* merge(ListNode* head1, ListNode* head2) {
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		ListNode* p = head1;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = head2;
		return head1;
	}
}
int main() {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	ListNode* head3 = NULL;

	element e[6] = { "Apple", "b", "c", "d", "E", "f" };
	element f[6] = { "1", "2", "3", "4", "5", "6" };

	for (int i = 0; i < 6; i++) {
		head1 = insert_first(head1, e[i]);

	}print_list(head1);

	for (int i = 0; i < 6; i++) {
		head2 = insert_first(head2, f[i]);

	}print_list(head2);

	head3 = merge(head1, head2);
	print_list(head3);

	return 0;
}