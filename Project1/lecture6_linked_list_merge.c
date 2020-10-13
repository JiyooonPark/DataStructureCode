//#include "lecture6_linked_list_word.c"
//
//ListNode* merge(ListNode* head1, ListNode* head2) {
//	if (head1 == NULL) return head2;
//	else if (head2 == NULL) return head1;
//	else {
//		ListNode* p = head1;
//		while (p->link != NULL) {
//			p = p->link;
//		}
//		p->link = head2;
//		return head1;
//	}
//}
////int main() {
////	ListNode* head1 = NULL;
////	ListNode* head2 = NULL;
////	ListNode* head3 = NULL;
////
////	element e[6] = { "Apple", "b", "c", "d", "E", "f" };
////	element f[6] = { "1", "2", "3", "4", "5", "6" };
////
////	for (int i = 0; i < 6; i++) {
////		head1 = insert_first(head1, e[i]);
////
////	}print_list(head1);
////
////	for (int i = 0; i < 6; i++) {
////		head2 = insert_first(head2, f[i]);
////
////	}print_list(head2);
////
////	head3 = merge(head1, head2);
////	print_list(head3);
////
////	return 0;
////}