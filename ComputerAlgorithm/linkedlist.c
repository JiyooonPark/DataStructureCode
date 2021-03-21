//#include <stdio.h>
//#include <stdlib.h>
//
//// 1876166박지윤 컴퓨터알고리즘 과제 2 - 3 : Linked List
//
//// 구조체들
//typedef struct ListNode{
//    int data;
//    struct ListNode* link;
//}ListNode;
//
//typedef struct {
//    ListNode* head;
//}LinkedListType;
//
//// 초기화 함수
//void init(LinkedListType * L){
//    L->head=NULL;
//}
//
//// 출력함수
//void printList(LinkedListType * L){
//    for (ListNode* p = L->head; p != NULL; p= p->link){
//        printf("[%d] -> ", p->data);
//    }
////    ListNode* first = L->head;
////    ListNode* p = L->head;
////    do{
////        printf("[%d] -> ", p->data);
////        p = p->link;
////    } while (p != first);
//    printf("NULL\n");
//}
//void print_list(ListNode* head) {
//    ListNode* p = head;
//    do{
//        printf("<- %s ->", p->data);
//        p = p->link;
//    }while (p != head);
//    printf("\n");
//}
//
//
//void add(LinkedListType * L , int pos, int item){
//    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
//    ListNode* before = L->head;
//    for( int i=0; i<pos-1; i++){
//        before = before->link;
//    }
//    node->data = item;
//    node->link = before->link;
//    before->link = node;
//}
//
//
//ListNode* getNode(){
//    ListNode* temp;
//    temp->link = NULL;
//    temp->data = 0;
//    return temp;
//}
////LinkedListType* buildList1(int n){
////    LinkedListType *L = (LinkedListType*)malloc(sizeof(ListNode)*(n+10));
////    ListNode* p = L->head;
////    L->head=NULL;
////    p->data = 1;
////    for(int i=2; i<n; i++){
////        p->link = getNode();
////        p = p->link;
////        p->data = i;
////    }
////    p->link = L;
////    return L;
////}
//int runSimulation(LinkedListType *L, int n, int k){
//    ListNode* p = L->head;
//    ListNode* pnext;
//    while(p != p->link){
//        for(int i=1; i<k; i++){
//            p = p->link;
//        }
//        pnext = p->link;
//        p->link = (p->link)->link;
////        putnpde(pnext);
//        p = p->link;
//    }
//    return p->data;
//}
//LinkedListType* buildList(int n){
//    LinkedListType* list;
//    init(list);
//    ListNode* header = list->head;
//    header->data = 1;
//    for(int i=2; i<n; i++){
//        header->link = getNode();
//        header = header->link;
//        header->data = i;
//    }
//    header->link = list->head;
//    print_list(list->head);
//    return list;
//}
//
//int candle( int n, int k){
//    LinkedListType* list;
//    list = buildList(n);
//    printList(list);
//    return runSimulation(&list, n, k);
//}
//
//int main() {
//    printf("hello");
////    printf("%d",candle(7,3));
////    candle(7,3);
//    LinkedListType* list;
//    init(list);
////    ListNode* header = list->head;
////    header->data = 1;
////    printf("%d ",header->data);
////    for(int i=2; i<7; i++){
////        header->link = getNode();
////        header = header->link;
////        header->data = i;
////        printf("%d ",header->data);
////    }
////    header->link = list->head;
////    print_list(list->head);
////    return list;
//}
