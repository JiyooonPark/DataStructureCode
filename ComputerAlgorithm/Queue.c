////
//// Created by jypark on 3/21/21.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct QueueNode{
//    int data;
//    struct QueueNode* link;
//}QueueNode;
//
//typedef struct {
//    QueueNode* front;
//    QueueNode* rear;
//}LinkedQueue;
//
//void init(LinkedQueue* queue){
//    queue->front = queue->rear = NULL;
//}
//int is_empty(LinkedQueue* queue){
//    return queue->front == NULL;
//}
//void enqueue(LinkedQueue* queue, int data){
//    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
//    temp->data = data;
//    temp->link = NULL;
//    if( is_empty(queue)){
//        queue->front = temp;
//        queue->rear = temp;
//    }
//    else{
//        queue->rear->link = temp;
//        queue->rear = temp;
//    }
//}
//void printQueue(LinkedQueue* queue){
//    QueueNode * p;
//    for(p = queue->front; p!=NULL; p = p->link){
//        printf("[%d] -> ", p->data);
//    }
//    printf("[NULL]\n");
//}
//int dequeue(LinkedQueue* queue){
//    QueueNode* temp;
//    // 4-3마지막에 있다..
//}
//void main(){
//    LinkedQueue queue;
//    init(&queue);
//}