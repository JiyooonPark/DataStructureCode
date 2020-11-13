#include <stdio.h>
#define MAX_SIZE 100

//1876166 ������ ����1 - ���� 2���� ť �����ϱ�

//��Ҹ� ���ڿ��� �����ϱ� 
typedef int element;

//����Ÿ���� �����Ѵ�
typedef struct {
	element* data;
	int capacity;
	int top;
}StackType;

//����Ÿ�� 2���� ť�� �����Ѵ�
typedef struct {
	StackType s1;
	StackType s2;
}Queue;

//������ �ʱ�ȭ�ϴ� �Լ�
void initStack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

//������ ������� Ȯ���ϴ� �Լ�
int isEmpty(StackType* s) {
	return s->top == -1;
}

//������ ��ȭ�������� Ȯ���ϴ� �Լ�
int isFull(StackType* s) {
	return s->top == MAX_SIZE - 1;
}

//������ ����ϴ� �Լ�
void printStack(StackType* s) {
	for (int i = 0; i < s->top + 1; i++) {
		//printf("?\n");
		printf("%s | ", (s->data[i]));
	}
	printf("\n");
}

//���ÿ� ��Ҹ� �߰��ϴ� �Լ�
void push(StackType* s, element item)
{
	if (isFull(s)) {
		s->capacity *= 2;
		s->data =
			(element*)realloc(s->data, s->capacity * sizeof(element));
	}
	printf("%d", s->top);
	s->data[++(s->top)] = item;
}

//���ÿ� ��Ҹ� �����ϰ� ��ȯ�ϴ� �Լ�
element pop(StackType* s) {
	element p;
	if (isEmpty(s)) {
		printf("������ ����ֽ��ϴ�. ");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}

//������ ��Ҹ� ���ž��� ��ȯ�ϴ�/�����ִ� �Լ�
element peek(StackType* s) {
	return s->data[s->top];
}

//ť�� ���� ���¸� ����ϴ� �Լ�
void printCurrent(Queue* q) {
	printf("s1 >>>");
	printStack(&(q->s1));
	printf("s2 >>>");
	printStack(&(q->s2));
	printf("\n");
}

//ť�� ��Ҹ� �߰��ϴ� �Լ� => ť ���� s1���ÿ� ��Ҹ� �߰��ϴ� �Լ�
void queuePush(Queue* q, element e) {
	printf("[%s]�� �Է��մϴ�. \n", e);
	push(&(q->s1), e);
	printCurrent(q);
}

//ť ���� s1 ������ ��� ��Ҹ� s2�������� �ű�� �Լ�
void pushAll(Queue* q, StackType* s1, StackType* s2) {
	printf("����1->2 �ϴ��� \n");
	//	for (int i = 0; i < s1->top+1; i++) {
	//		push(&s2, pop(&s1));
	//	}
	while (!(s1->top == -1)) {
		//		printf("inside\n");
		push(s2, pop(s1));
	}
	printCurrent(q);
}

//ť���� ��Ҹ� �����ϰ� ��ȯ�ϴ� �Լ�
void queuePop(Queue* q) {
	if (isEmpty(&(q->s2))) {
		//		printf("s2�� ����ֽ��ϴ�\n");
		pushAll(q, &(q->s1), &(q->s2));
		//		printf("�ű� �Ϸ�\n");
	}
	printf("[%s] �� ��ȯ�Ǿ����ϴ�. \n", pop(&(q->s2)));
	printCurrent(q);
}

//ť�� �ʱ�ȭ�ϴ� �Լ�
void initQueue(Queue* q) {
	initStack(&(q->s1));
	initStack(&(q->s2));
}

//�����Լ�
int main() {
	Queue q;
	initQueue(&q);

	//element capitals[20] = { "����", "����", "��Ÿ��","������ ��","�����ϰ�","������","��ũ��","����" ,"�ϳ���"," ����",
		//"��ũ��", "����Ÿ��", "�ڳ�ũ��","����","�߷�","�ֹ�","������","�˷���", "����", "����" };
	element capitals[10] = { 1,2,3,3,3,3,3,1,1,10 };

	queuePush(&q, capitals[0]);
	queuePush(&q, capitals[0]);
	queuePush(&q, capitals[0]);
	//�������� ť�� ���� �ְ� ����ϴ� �ڵ�
	//srand(time(NULL));
	//printf("started\n");
	//for (int i = 0; i < 20; i++) {
	//	if (rand() % 2 == 0) {
	//		queuePush(&q, capitals[i]);
	//	}
	//	if (rand() % 4 == 0) {
	//		queuePop(&q);
	//	}
	//}
}