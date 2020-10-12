#include <stdio.h>

int factorial_iter(int num) {
	int i, result = 1;
	for (int i = 0; i < num; i++) {
		result *= (i + 1);
	}
	return result;
}
//int main() {
//	printf("%d", factorial_iter(5));
//}