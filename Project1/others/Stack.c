//#include <stdio.h>
//#define MAX_SIZE 100
//
////1876166 ������ ����1 - ���� 2���� ť �����ϱ�
//
//typedef char* element;
//
////stack type�� �����Ѵ�. 
//typedef struct {
//	element* data;
//	int capacity;
//	int top;
//}stacktype;
//
////ť�� �ΰ��� �������� �����Ѵ�. 
//typedef struct {
//	stacktype s1;
//	stacktype s2;
//}queue;
//
////������ �ʱ�ȭ �Լ�
//void initstack(stacktype* s) {
//	s->top = -1;
//	s->capacity = 1;
//	s->data = (element*)malloc(s->capacity * sizeof(element));
//}
//
////������ ������� Ȯ���ϴ� �Լ�
//int isempty(stacktype* s) {
//	return s->top == -1;
//}
//
////������ �� á���� Ȯ���ϴ� �Լ�
//int isfull(stacktype* s) {
//	return s->top == MAX_SIZE - 1;
//}
//
////������ ����ϴ� �Լ�
//void printstack(stacktype* s) {
//	for (int i = 0; i < s->top + 1; i++) {
//		//printf("?\n");
//		printf("%s | ", (s->data[i]));
//	}
//	printf("\n");
//}
//
////���ÿ� ��Ҹ� �߰��ϴ� �Լ�
//void push(stacktype* s, element e) {
//	if (isfull(s)) {
//		s->capacity *= 2;
//		s->data = (element*)realloc(s->capacity * sizeof(element));
//	}
//	s->data[++(s->top)] = e;
//	//printstack(s);
//}
//
////������ ��Ҹ� �����ϰ� ��ȯ�ϴ� �Լ�
//element pop(stacktype* s) {
//	if (isempty(s)) {
//		printf("������ ����ֽ��ϴ�. ");
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}
//
////������ ��Ҹ� 
//element peek(stacktype* s) {
//	return s->data[s->top];
//}
