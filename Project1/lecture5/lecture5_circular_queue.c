#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

void error(char* message) {
	printf(message);
	exit(1);
}

void init_queue(QueueType* q) {
	q->front = 0;
	q->rear = 0;

}
void queue_print(QueueType* q) {
	printf("(QUEUE(front : %d rear : %d) )  ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear) break;
		} while (i != q->front);
	}
	printf("\n");
	//for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
	//	if (i <= q->front || i > q->rear) {
	//		printf("   |");
	//	}
	//	else printf("%d |", q->data[i]);
	//}
	//printf("\n");
}
int is_full(QueueType* q) {
	return (q->rear+1 % MAX_QUEUE_SIZE == q->front);
}
int is_empty(QueueType* q) {
	return q->rear == q->front;
}
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("full");
	}
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}
int deque(QueueType* q) {
	if (is_empty(q)) {
		error("empty");
		return -1;
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}
int main() {
	int item = 0;
	QueueType q;
	init_queue(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 40); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 40); queue_print(&q);
	enqueue(&q, 40); queue_print(&q);
	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 10); queue_print(&q);

	item = deque(&q); printf("%d\n", item); queue_print(&q);
	item = deque(&q); printf("%d\n", item); queue_print(&q);
	item = deque(&q); printf("%d\n", item); queue_print(&q);
	item = deque(&q); printf("%d\n", item); queue_print(&q);
}