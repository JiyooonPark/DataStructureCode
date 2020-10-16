//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef int element;
//typedef struct DlistNode {
//	element data;
//	struct DlistNode* rlink, * llink;
//}DlistNode;
//
//void dinsert(DlistNode* before, element data) {
//	DlistNode* newnode = (DlistNode*)malloc(sizeof(DlistNode));
//	newnode->data = data;
//
//
//	newnode->llink = before;
//	newnode->rlink = before->rlink;
//	
//	before->rlink->llink = newnode;
//	before->rlink = newnode;
//}
//void ddelete(DlistNode* head, DlistNode* removed) {
//	if (removed == head) return;
//	removed->llink->rlink = removed->rlink;
//	removed->rlink->llink = removed->llink;
//	free(removed);
//}
//void init(DlistNode* phead) {
//	phead->llink = phead;
//	phead->rlink = phead;
//}
//void print_dlist(DlistNode* phead) {
//	DlistNode* p;
//	for (p = phead->rlink; p != phead; p = p->rlink) {
//		printf("<- |%d| ->", p->data);
//	}
//	printf("\n");
//}
//int main() {
//	DlistNode* head = (DlistNode*)malloc(sizeof(DlistNode));
//	init(head);
//	printf("추가 단계\n");
//	for (int i = 0; i < 5; i++) {
//		dinsert(head, i);
//		print_dlist(head);
//	}
//	printf("삭제 단계\n");
//	for (int i = 0; i < 5; i++) {
//		print_dlist(head);
//		ddelete(head, head->rlink);
//	}
//	free(head);
//	return 0;
//}