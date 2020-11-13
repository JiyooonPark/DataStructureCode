#include <stdio.h>
#define MAX_SIZE 100

//1876166 박지윤 과제1 - 스택 2개로 큐 구현하기

//요소를 문자열로 정의하기 
typedef int element;

//스택타입을 정의한다
typedef struct {
	element* data;
	int capacity;
	int top;
}StackType;

//스택타입 2개로 큐를 정의한다
typedef struct {
	StackType s1;
	StackType s2;
}Queue;

//스택을 초기화하는 함수
void initStack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

//스택이 비었는지 확인하는 함수
int isEmpty(StackType* s) {
	return s->top == -1;
}

//스택이 포화상태인지 확인하는 함수
int isFull(StackType* s) {
	return s->top == MAX_SIZE - 1;
}

//스택을 출력하는 함수
void printStack(StackType* s) {
	for (int i = 0; i < s->top + 1; i++) {
		//printf("?\n");
		printf("%s | ", (s->data[i]));
	}
	printf("\n");
}

//스택에 요소를 추가하는 함수
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

//스택에 요소를 제거하고 반환하는 함수
element pop(StackType* s) {
	element p;
	if (isEmpty(s)) {
		printf("스택이 비어있습니다. ");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}

//스택의 요소를 제거없이 반환하는/보여주는 함수
element peek(StackType* s) {
	return s->data[s->top];
}

//큐의 현재 상태를 출력하는 함수
void printCurrent(Queue* q) {
	printf("s1 >>>");
	printStack(&(q->s1));
	printf("s2 >>>");
	printStack(&(q->s2));
	printf("\n");
}

//큐에 요소를 추가하는 함수 => 큐 내의 s1스택에 요소를 추가하는 함수
void queuePush(Queue* q, element e) {
	printf("[%s]를 입력합니다. \n", e);
	push(&(q->s1), e);
	printCurrent(q);
}

//큐 내의 s1 스택의 모든 요소를 s2스택으로 옮기는 함수
void pushAll(Queue* q, StackType* s1, StackType* s2) {
	printf("스택1->2 하는중 \n");
	//	for (int i = 0; i < s1->top+1; i++) {
	//		push(&s2, pop(&s1));
	//	}
	while (!(s1->top == -1)) {
		//		printf("inside\n");
		push(s2, pop(s1));
	}
	printCurrent(q);
}

//큐에서 요소를 제거하고 반환하는 함수
void queuePop(Queue* q) {
	if (isEmpty(&(q->s2))) {
		//		printf("s2가 비어있습니다\n");
		pushAll(q, &(q->s1), &(q->s2));
		//		printf("옮김 완료\n");
	}
	printf("[%s] 가 반환되었습니다. \n", pop(&(q->s2)));
	printCurrent(q);
}

//큐를 초기화하는 함수
void initQueue(Queue* q) {
	initStack(&(q->s1));
	initStack(&(q->s2));
}

//메인함수
int main() {
	Queue q;
	initQueue(&q);

	//element capitals[20] = { "서울", "도쿄", "오타와","워싱턴 디씨","코펜하겐","베를린","모스크바","모나코" ,"하노이"," 베른",
		//"아크라", "조지타운", "코나크리","비사우","야렌","주바","오슬로","알로피", "로조", "딜리" };
	element capitals[10] = { 1,2,3,3,3,3,3,1,1,10 };

	queuePush(&q, capitals[0]);
	queuePush(&q, capitals[0]);
	queuePush(&q, capitals[0]);
	//무작위로 큐에 값을 넣고 출력하는 코드
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