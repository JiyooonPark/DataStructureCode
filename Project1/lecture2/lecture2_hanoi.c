#include <stdio.h>
int count = 0;
void hanoi_tower(int n, char from, char temp, char to) {
	count++;
	if (n == 1) {
		printf("���� 1�� %c���� %c�� �ű��. \n", from, to);
	}
	else {
		hanoi_tower(n - 1, from, to, temp);
		printf("���� %d�� %c���� %c�� �ű��. \n", n, from, to);
		hanoi_tower(n - 1, temp, from, to);
	}
}
//int main(void) {
//	hanoi_tower(4, 'A', 'B', 'C');
//	printf("count : %d", count);
//	return 0;
//}


// _______ _______ _______