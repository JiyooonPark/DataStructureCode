#include <stdio.h>
#include <stdlib.h>
#include "lecutre6_inked_list_word.c"

ListNode* search_list(ListNode* head, element x) {
	ListNode* p = head;

	while (p != NULL) {
		if (p -> data == x) return p;
		p = p->link;
	}
	return NULL;
}


int main() {
	ListNode* head = NULL;
	element e [6]= { "Apple", "b", "c", "d", "E", "f" };
	for (int i = 0; i < 6; i++) {
		head = insert_first(head, e[i]);
		print_list(head);
	}
	if (search_list(head, e[4]) != NULL) {
		printf("found %s \n", e[4]);
	}
	else {
		printf("cound not find it\n");
	}

	for (int i = 0; i < 5; i++) {
		head = delete_first(head, i);
		print_list(head);
	}
	return 0;
}