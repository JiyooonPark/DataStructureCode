#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}DequeType;

void error(char* message) {
	printf(message);
	exit(1);
}

void init_queue(DequeType* q) {
	q->front = 0;
	q->rear = 0;

}
void queue_print(DequeType* q) {
	printf("(DEQUE(front : %d rear : %d) )  ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear) break;
		} while (i != q->front);
	}
	printf("\n");
}
int is_full(DequeType* q) {
	return (q->rear+1) % MAX_QUEUE_SIZE == q->front;
}
int is_empty(DequeType* q) {
	return q->rear == q->front;
}
void enqueue_front(DequeType* q, element item) {
	if (is_full(q)) {
		error("full");
	}
	else {
		
		q->data[q->front] = item;
		q->front = (q->front - 1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	}
}
void enqueue_rear(DequeType* q, element item) {
	if (is_full(q)) {
		error("full");
	}
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}
int deque_front(DequeType* q) {
	if (is_empty(q)) {
		error("empty");
		return -1;
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}
int deque_rear(DequeType* q) {
	int pev = q->rear;
	if (is_empty(q)) {
		error("empty");
		return -1;
	}
	else {
		q->rear = (q->rear -1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		return q->data[pev];
	}
}
int main() {
	int item = 0;
	DequeType q;
	init_queue(&q);

	enqueue_front(&q, 10); queue_print(&q);
	enqueue_rear(&q, 20); queue_print(&q);
	enqueue_front(&q, 30); queue_print(&q);
	enqueue_rear(&q, 40); queue_print(&q);


	item = deque_front(&q); printf("%d\n", item); queue_print(&q);
	item = deque_rear(&q); printf("%d\n", item); queue_print(&q);
	item = deque_front(&q); printf("%d\n", item); queue_print(&q);
	item = deque_rear(&q); printf("%d\n", item); queue_print(&q);
}