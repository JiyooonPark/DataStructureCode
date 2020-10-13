//#include <stdio.h>
//#include <stdlib.h>
//#include "lecture6_linked_list_word.c"
//
//ListNode* reverse(ListNode* head) {
//	ListNode* p , *r, *q;
//	p = head;
//	q = NULL;
//	while (p != NULL) {
//
//		r = q;
//		printf("r: ");
//		print_list(r);
//		printf("\n");
//		q = p; 
//		printf("q: ");
//		print_list(q);
//		printf("\n");
//		printf("p: ");
//		print_list(p);
//		printf("\n");
//		p = p->link;
//		printf("p: ");
//		print_list(p);
//		printf("\n");
//		q->link = r;
//		printf("q: ");
//		print_list(q);
//		printf("\n");
//	}
//}
//int main() {
//	ListNode* head1 = NULL;
//	ListNode* head2 = NULL;
//	element e[6] = { "Apple", "b", "c", "d", "E", "f" };
//	for (int i = 0; i < 6; i++) {
//		head1 = insert_first(head1, e[i]);
//
//	}print_list(head1);
//	head2 = reverse(head1);
//}
