//#include <stdio.h>
//#define MAX_SIZE 100
//
////1876166 박지윤 과제1 - 스택 2개로 큐 구현하기
//
//typedef char* element;
//
////stack type를 정의한다. 
//typedef struct {
//	element* data;
//	int capacity;
//	int top;
//}stacktype;
//
////큐를 두개의 스택으로 정의한다. 
//typedef struct {
//	stacktype s1;
//	stacktype s2;
//}queue;
//
////스택의 초기화 함수
//void initstack(stacktype* s) {
//	s->top = -1;
//	s->capacity = 1;
//	s->data = (element*)malloc(s->capacity * sizeof(element));
//}
//
////스택이 비었는지 확인하는 함수
//int isempty(stacktype* s) {
//	return s->top == -1;
//}
//
////스택이 꽉 찼는지 확인하는 함수
//int isfull(stacktype* s) {
//	return s->top == MAX_SIZE - 1;
//}
//
////스택을 출력하는 함수
//void printstack(stacktype* s) {
//	for (int i = 0; i < s->top + 1; i++) {
//		//printf("?\n");
//		printf("%s | ", (s->data[i]));
//	}
//	printf("\n");
//}
//
////스택에 요소를 추가하는 함수
//void push(stacktype* s, element e) {
//	if (isfull(s)) {
//		s->capacity *= 2;
//		s->data = (element*)realloc(s->capacity * sizeof(element));
//	}
//	s->data[++(s->top)] = e;
//	//printstack(s);
//}
//
////스택의 요소를 제거하고 반환하는 함수
//element pop(stacktype* s) {
//	if (isempty(s)) {
//		printf("스택이 비어있습니다. ");
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}
//
////스택의 요소를 
//element peek(stacktype* s) {
//	return s->data[s->top];
//}
