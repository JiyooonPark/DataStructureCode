#include <stdio.h>
#include <stdlib.h>

// 1876166박지윤 컴퓨터알고리즘 과제 1

// 구조체들
typedef struct ListNode{
    int data;
    struct ListNode* link;
}ListNode;

typedef struct {
    ListNode* head;
}LinkedListType;

// 초기화 함수
void init(LinkedListType * L){
    L->head=NULL;
}

// 출력함수
void printList(LinkedListType * L){
    for (ListNode* p = L->head; p != NULL; p= p->link){
        printf("[%d] -> ", p->data);
    }
    printf("NULL\n");
}

// 요소 추가 함
void addFirst(LinkedListType* L, int item){
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    node->data = item;
    node->link = L->head;
    L->head = node;
}
void add(LinkedListType * L , int pos, int item){
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    ListNode* before = L->head;
    for( int i=0; i<pos-1; i++){
        before = before->link;
    }
    node->data = item;
    node->link = before->link;
    before->link = node;
}
void addLast(LinkedListType * L, int item){
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    ListNode* before = L->head;
    while(before->link!=NULL){
        before = before->link;
    }
    node->data = item;
    node->link = before->link;
    before->link = node;

}

// 요소 가져오기, 값 바꾸기 관련 함수
int get(LinkedListType* L, int pos){
    ListNode* p = L->head;
    for(int i=1; i<pos; i++){
        p = p->link;
    }
    return  p->data;
}
void set(LinkedListType* L, int pos, int item){
    ListNode* p = L->head;
    for(int i=1; i<pos; i++){
        p = p->link;
    }
    p->data = item;
}

// 요소 제거 관련 함수
int removePose(LinkedListType* L, int pos){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* before = L->head;
    for (int i=1; i<pos -1 ; i++){
        before = before->link;
    }
    node = before;
    before->link = before->link->link;
    return node->data;
}
int removeFirst(LinkedListType* L){
    ListNode* node = L->head;
    L->head = L->head->link;
    return node->data;
}
int removeLast(LinkedListType* L){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* before = L->head;
    while(before->link->link!=NULL){
        before = before->link;
    }
    node = before;
    before->link=before->link->link;
    return node->data;
}

int main() {

    LinkedListType list;
    init(&list);

    addFirst(&list, 10); printList(&list);
    addFirst(&list, 20); printList(&list);
    addFirst(&list, 30); printList(&list);
    addFirst(&list, 40); printList(&list);
//    getchar();
    add(&list, 1, 100); printList(&list);
    add(&list, 4, 1000); printList(&list);
    addLast(&list, 500); printList(&list);

//    int pos;
//    printf("몇번 노드 값반환할까요?");
//    scanf("%d", &pos);
//    printf("%d 의 값은 %d", pos,get(&list, pos) );
    removePose(&list, 1); printList(&list);
    removeFirst(&list); printList(&list);
    removeLast(&list); printList(&list);

}
