//#include <stdio.h>
//#include <stdlib.h>
//
////1876166 ������ ����1 - ���� 2���� ť �����ϱ�
//
//#define MAX_STACK_SIZE 100
//
////��Ҹ� ���ڿ��� �����ϱ� 
//typedef char* element;
//
////����Ÿ���� �����Ѵ�
//typedef struct {
//	element data[MAX_STACK_SIZE];
//	int top;
//} StackType;
//
////����Ÿ�� 2���� ť�� �����Ѵ�
//typedef struct {
//	StackType s1;
//	StackType s2;
//}Queue;
//
////������ �ʱ�ȭ�ϴ� �Լ�
//void init_stack(StackType* s)
//{
//	s->top = -1;
//}
//
////������ ������� Ȯ���ϴ� �Լ�
//int is_empty(StackType* s)
//{
//	return (s->top == -1);
//}
//
////������ ��ȭ�������� Ȯ���ϴ� �Լ�
//int is_full(StackType* s)
//{
//	return (s->top == (MAX_STACK_SIZE - 1));
//}
//
////���ÿ� ��Ҹ� �߰��ϴ� �Լ�
//void push(StackType* s, element item)
//{
//	if (is_full(s)) {
//		fprintf(stderr, "���� ��ȭ ����\n");
//		return;
//	}
//	else s->data[++(s->top)] = item;
//}
//
////���ÿ� ��Ҹ� �����ϰ� ��ȯ�ϴ� �Լ�
//element pop(StackType* s)
//{
//	if (is_empty(s)) {
//		fprintf(stderr, "���� ���� ����\n");
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}
//
////������ ��Ҹ� ���ž��� ��ȯ�ϴ�/�����ִ� �Լ�
//element peek(StackType* s)
//{
//	if (is_empty(s)) {
//		fprintf(stderr, "���� ���� ����\n");
//		exit(1);
//	}
//	else return s->data[s->top];
//}
//
////������ ����ϴ� �Լ�
//void printStack(StackType* s) {
//	for (int i = 0; i < s->top + 1; i++) {
//		printf("%s | ", (s->data[i]));
//	}
//	printf("\n");
//}
//
////ť�� ���� ���¸� ����ϴ� �Լ�
//void printCurrent(Queue* q) {
//	printf("s1 >>>");
//	printStack(&(q->s1));
//	printf("s2 >>>");
//	printStack(&(q->s2));
//	printf("\n");
//}
//
////ť�� ��Ҹ� �߰��ϴ� �Լ� => ť ���� s1���ÿ� ��Ҹ� �߰��ϴ� �Լ�
//void queuePush(Queue* q, element e) {
//	printf("[%s]�� �Է��մϴ�. \n", e);
//	push(&(q->s1), e);
//	printCurrent(q);
//}
//
////ť ���� s1 ������ ��� ��Ҹ� s2�������� �ű�� �Լ�
//void pushAll(Queue* q, StackType* s1, StackType* s2) {
//	while (!(s1->top == -1)) {
//		push(s2, pop(s1));
//	}
//	//printCurrent(q);
//}
//
////ť���� ��Ҹ� �����ϰ� ��ȯ�ϴ� �Լ�
//void queuePop(Queue* q) {
//	if (is_empty(&(q->s2))) {
//		pushAll(q, &(q->s1), &(q->s2));
//	}
//	printf("[%s] �� ��ȯ�Ǿ����ϴ�. \n", pop(&(q->s2)));
//	printCurrent(q);
//}
//
////ť�� �ʱ�ȭ�ϴ� �Լ�
//void initQueue(Queue* q) {
//	init_stack(&(q->s1));
//	init_stack(&(q->s2));
//}
//
//
//int main(void)
//{
//	Queue q;
//	initQueue(&q);
//	Queue q2;
//	initQueue(&q2);
//
//	element capitals[20] = { "����", "����", "��Ÿ��","������ ��","�����ϰ�","������","��ũ��","����" ,"�ϳ���"," ����",
//		"��ũ��", "����Ÿ��", "�ڳ�ũ��","����","�߷�","�ֹ�","������","�˷���", "����", "����" };
//
//
//	//10���̻��� �Է°� 10���� ��� �ڵ� 
//	queuePush(&q2, capitals[rand() % 20]);
//	queuePush(&q2, capitals[rand() % 20]);
//	queuePush(&q2, capitals[rand() % 20]);
//	queuePop(&q2);
//	queuePush(&q2, capitals[rand() % 20]);
//	queuePush(&q2, capitals[rand() % 20]);
//	queuePop(&q2); queuePop(&q2); queuePop(&q2);
//	queuePush(&q2, capitals[rand() % 20]);
//	queuePush(&q2, capitals[rand() % 20]);
//	queuePush(&q2, capitals[rand() % 20]);
//	queuePop(&q2); queuePop(&q2); queuePop(&q2);
//	queuePush(&q2, capitals[rand() % 20]);
//	queuePush(&q2, capitals[rand() % 20]);
//	queuePush(&q2, capitals[rand() % 20]);
//	queuePush(&q2, capitals[rand() % 20]);
//	queuePop(&q2);
//	queuePush(&q2, capitals[rand() % 20]);
//	queuePop(&q2); queuePop(&q2);
//
//	printf("==================================================================\n");
//
//	//!!!!!!!!!!!!!!!!!!!!!!�߰����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
////�������� ť�� ���� �ְ� ����ϴ� �ڵ�
//	srand(time(NULL));
//	for (int i = 0; i < 20; ) {
//		if (rand() % 2 == 0) {
//			queuePush(&q, capitals[i]);
//			i++;
//		}
//		if (rand() % 5 == 0) {
//			queuePop(&q);
//			i++;
//		}
//	}
//}
