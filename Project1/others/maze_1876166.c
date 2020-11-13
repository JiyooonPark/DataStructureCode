//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////1876166 박지윤 과제1 - 미로찾기
//
//#define MAX_STACK_SIZE 100
//#define MAZE_SIZE 16
//
////--------------------기본 STACK에 관한 함수 -----------------------
////요소를 정의한다. 
//typedef struct {
//	short r;
//	short c;
//} element;
//
////StackType를 정의한다. element 배열과 top을 가리키는 변수가 있다. 
//typedef struct {
//	element data[MAX_STACK_SIZE];
//	int top;
//} StackType;
//
//// 스택을 초기화 하는 함수
//void init_stack(StackType* s)
//{
//	s->top = -1;
//}
//
//// 스택이 비었는지 확인하는 함수
//int is_empty(StackType* s)
//{
//	return (s->top == -1);
//}
//// 스택이 꽉찼는지 확인하는 함수
//int is_full(StackType* s)
//{
//	return (s->top == (MAX_STACK_SIZE - 1));
//}
//// 스택에 요소를 넣는 함수
//void push(StackType* s, element item)
//{
//	if (is_full(s)) {
//		fprintf(stderr, "스택 포화 에러\n");
//		return;
//	}
//	else s->data[++(s->top)] = item;
//}
//// 스택의 요소를 삭제하고 반환하는 함수
//element pop(StackType* s)
//{
//	if (is_empty(s)) {
//		fprintf(stderr, "스택에 아무것도 들어있지 않습니다.\n");
//		exit(1);
//	}
//	else return s->data[(s->top)--];
//}
//// 스택의 요소를 삭제하지 않고 값 return하는 함수
//element peek(StackType* s)
//{
//	if (is_empty(s)) {
//		fprintf(stderr, "스택 공백 에러\n");
//		exit(1);
//	}
//	else return s->data[s->top];
//}
//
////--------------------미로에 관한 함수 -----------------------
//
////mouse의 현재위치를 표시하는 here과 입구를 표시하는 entry
//element here = { 2,0 }, entry = { 2,0 };
//
////보상과 함정에 들어갔을때를 기록하는 변수들 정의
//int point = 0, reward = 0, loss = 0;
//
////벽, 시작위치, 길만 표시한 미로를 정의한다. 
////미로의 크기는 16X16
//char maze[MAZE_SIZE][MAZE_SIZE] = {
//	{ '1', '1', '1', '1', '1', '1','1', '1', '1', '1', '1', '1','1', '1', '1', '1'},
//	{ '1', '0', '1', '1', '1', '1','1', '1', '0', '0', '0', '1','1', '1', '1', '1'},
//	{ 'e', '0', '0', '0', '0', '1','1', '1', '1', '1', '0', '1','1', '1', '1', '1'},
//	{ '1', '1', '1', '1', '0', '1','1', '1', '1', '1', '0', '0','0', '0', '1', '1'},
//	{ '1', '1', '1', '1', '0', '0','1', '1', '1', '1', '0', '1','1', '0', '1', '1'},
//	{ '1', '0', '1', '1', '0', '0','0', '1', '1', '1', '0', '1','1', '0', '1', '1'},
//	{ '1', '0', '1', '1', '1', '1','0', '0', '1', '1', '0', '1','0', '0', '0', 'x'},
//	{ '1', '0', '0', '1', '1', '1','1', '0', '0', '1', '0', '1','0', '1', '1', '1'},
//	{ '1', '1', '0', '0', '0', '1','1', '0', '0', '1', '0', '1','0', '1', '1', '1'},
//	{ '1', '1', '0', '1', '0', '1','1', '0', '1', '1', '0', '1','0', '1', '1', '1'},
//	{ '1', '1', '0', '1', '0', '0','0', '0', '1', '0', '0', '0','0', '1', '1', '1'},
//	{ '1', '1', '0', '0', '0', '1','1', '1', '1', '0', '1', '1','1', '1', '1', '1'},
//	{ '1', '1', '0', '1', '0', '0','1', '1', '1', '0', '1', '1','1', '1', '1', '1'},
//	{ '1', '1', '0', '0', '1', '0','1', '0', '1', '0', '1', '1','1', '1', '1', '1'},
//	{ '1', '1', '1', '1', '1', '0','0', '0', '0', '0', '1', '1','1', '1', '1', '1'},
//	{ '1', '1', '1', '1', '1', '1','1', '1', '1', '1', '1', '1','1', '1', '1', '1'},
//};
//
////!!!!!!!!!!!!추가기능!!!!!!!!!!!!!!!!
////보상이 있는 위치를 임의로 설정한다. 직접입력하는것이 아닌, 실행할 때마다 달라지게 한다. 
////보상은 'R'로 출력된다. 
//void randAward() {
//	int x = 0;
//	int y = 0;
//	for (int i = 0; i < 12; i++) {
//		srand(time(NULL));
//		x = rand() % MAZE_SIZE - 1;
//		y = (rand() * 132) % MAZE_SIZE - 1;
//		if (maze[x][y] == '1' || maze[x][y] == '0') {
//			//	printf("(%d,%d) %c\n",x,y, maze[x][y]);
//			maze[x][y] = 'R';
//		}
//		else {
//			i--;
//			continue;
//		}
//	}
//	printf("보상을 'R'로 추가\n");
//}
//
////!!!!!!!!!!!!추가기능!!!!!!!!!!!!!!!!
////함정이 있는 위치를 임의로 설정한다. 직접입력하는것이 아닌, 실행할 때마다 달라지게 한다. 
////함정은 'P'로 출력된다. 
//void randPenalty() {
//	int x = 0;
//	int y = 0;
//	for (int i = 0; i < 12; i++) {
//		srand(time(NULL));
//		x = rand() % MAZE_SIZE;
//		y = (rand() * 132) % MAZE_SIZE;
//		if (maze[x][y] == '1' || maze[x][y] == '0') {
//			maze[x][y] = 'P';
//		}
//		else {
//			i--;
//			continue;
//		}
//	}
//	printf("함정을 'P'로 추가\n");
//}
//
//// 현 위치를 기준으로 갈 수 있는 위치를 모두 스택에 삽입하는 함수
//void push_loc(StackType* s, int r, int c)
//{
//	if (r < 0 || c < 0) return;
//	if (maze[r][c] != '1' && maze[r][c] != '.') {
//		element tmp;
//		tmp.r = r;
//		tmp.c = c;
//		push(s, tmp);
//	}
//}
//
////pop + 보상/함정 손익 계산해주는 함수  
//element pop_reward(StackType* s) {
//	element p = pop(s);
//	if (maze[p.r][p.c] == 'R') {
//		reward++;
//		point++;
//	}
//	else if (maze[p.r][p.c] == 'P') {
//		loss++;
//		point--;
//	}
//	return p;
//}
//
//// 미로를 화면에 출력한다. 
//void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
//{
//	printf("\n");
//	for (int r = 0; r < MAZE_SIZE; r++) {
//		for (int c = 0; c < MAZE_SIZE; c++) {
//			printf("%c ", maze[r][c]);
//		}
//		printf("\n");
//	}
//}
//
//int main(void)
//{
//	int r, c;
//	StackType s;
//
//	init_stack(&s);
//	here = entry;
//	randAward();
//	randPenalty();
//
//	while (maze[here.r][here.c] != 'x') {
//		r = here.r;
//		c = here.c;
//		maze[r][c] = '.';
//		maze_print(maze);
//		push_loc(&s, r - 1, c);
//		push_loc(&s, r + 1, c);
//		push_loc(&s, r, c - 1);
//		push_loc(&s, r, c + 1);
//		if (is_empty(&s)) {
//			printf("실패\n");
//			return;
//		}
//		else
//			here = pop_reward(&s);
//	}
//	printf("성공\n");
//	printf("%d점의 보물점수를 획득했습니다. (만난 보상의 수 : %d, 만난 함정의 수 : %d)", point, reward, loss);
//	return 0;
//}