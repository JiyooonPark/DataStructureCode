//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct ListNode {
//    int data;
//    struct ListNode* link;
//}ListNode;
//
//void print_list(ListNode* head) {
//    int first = head->data;
//    printf("first is :%d\n", first);
//    ListNode* p = head;
//    do{
//        printf("<- %d ->", p->data);
//        p = p->link;
//        printf("p->data is :%d\n", p->data);
//    }while (p->data != first);
//    printf("\ndone");
//}
//ListNode* insert_last(ListNode* head, int data) {
//    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
//    node->data = data;
//    if (head == NULL) {
//        head = node;
//        node->link = head;
//    }
//    else {
//        node->link = head->link;
//        head->link = node;
//        head = node;
//    }
////    print_list(head);
//    return head;
//}
//
//ListNode* buildList(int n){
//    ListNode* list= NULL;
//
//    ListNode* header = list;
//    for(int i=1; i<n; i++) {
//        list = insert_last(list, i);
//    }
//    print_list(list);
//    return header;
//}
//int removePose(ListNode * L, int pos){
//    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
//    ListNode* before = L;
//    for (int i=1; i<pos -1 ; i++){
//        before = before->link;
//    }
//    node = before;
//    before->link = before->link->link;
//    return node->data;
//}
//void putnode(ListNode *list, ListNode *pnext) {
////    removePose(list, )
//}
//int runSimulation(ListNode *list, int n, int k){
//    print_list(list);
//
//    ListNode* p = list;
//    ListNode* pnext;
//    while(p != p->link){
//        for(int i=1; i<k; i++){
//            p = p->link;
//        }
//        pnext = p->link;
//        p->link = (p->link)->link;
////        putnode(pnext);
//        p = p->link;
//    }
//    return p->data;
//}
//
//
//int candle( int n, int k){
//    ListNode* list = NULL;
//    list = buildList(n);
//    printf("here\n");
////    print_list(list);
////    return runSimulation(list, n, k);
//}
//
//
//int main() {
////    ListNode* head = NULL;
//    int n = 7;
//    int k = 3;
//////    print_list(head);
////    printf("ans :%d",candle(7,3));
//
//    ListNode* list = (ListNode*)malloc(sizeof(struct ListNode)*n);
//    list = buildList(n);
//
////    print_list(list);
//    int first = list->data;
//    printf("first is :%d\n", first);
//    ListNode* p = list;
//    do{
//        printf("<- %d ->", p->data);
//        p = p->link;
//        printf("p->data is :%d\n", p->data);
//    }while (p->data != first);
//    printf("\ndone");
////    ListNode* p = NULL;
////    p = list;
////    printf("%d\n", list->data);
////    ListNode* pnext;
////    while(p != p->link){
////        for(int i=1; i<k; i++){
////            p = p->link;
////        }
////        pnext = p->link;
////        p->link = (p->link)->link;
//////        putnode(pnext);
////        p = p->link;
////    }
//
//}