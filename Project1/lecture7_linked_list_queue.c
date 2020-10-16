//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef int element;
//
//typedef struct QueueNode {
//	element data;
//	struct QueueNode* link;
//}QueueNode;
//typedef struct {
//	QueueNode* front, * rear;
//}LinkedQueueType;
//
//void init(LinkedQueueType* q) {
//	q->rear = 0;
//	q->front = 0;
//}
//int is_empty(LinkedQueueType* q) {
//	return NULL == q->front;
//}
//int is_full(LinkedQueueType* s) {
//	return 0;
//}
//void enque(LinkedQueueType* s, element item) {
//	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
//	temp->data = item;
//	temp->link = NULL;
//
//	if (is_empty(s)) {
//		s->front = temp;
//		s->rear = temp;
//	}
//	else {
//		s->rear->link = temp;
//		s->rear = temp;
//	}
//}
//
//element deque(LinkedQueueType* q) {
//	QueueNode* temp = q->front;
//	element data;
//	if (is_empty(q)) {
//		printf("비어있음\n");
//		exit(1);
//	}
//	else {
//		data = temp->data;
//		q->front = q->front->link;
//		if (q->front == NULL) q->rear = NULL;
//		free(temp);
//		return data;
//	}
//}
//
//void print_list(LinkedQueueType* q) {
//	QueueNode* p = q->front;
//
//	for (p; p != NULL; p = p->link) {
//		printf("%d -> ", p->data);
//	}
//	printf("NULL\n");
//}
//
//
//int main() {
//
//	LinkedQueueType* q = (LinkedQueueType*)malloc(sizeof(LinkedQueueType));
//	init(q);
//
//	for (int i = 0; i < 10; i++) {
//		enque(q, i);
//		print_list(q);
//	}
//
//	for (int i = 0; i < 10; i++) {
//		deque(q);
//		print_list(q);
//	}
//}