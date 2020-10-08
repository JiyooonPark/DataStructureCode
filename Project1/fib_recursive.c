#include <stdio.h>

int fib_recursive(int n) {
	printf("on fib(%d)\n", n);
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib_recursive(n - 1) + fib_recursive(n - 2);
}
//int main() {
//	printf("%d", fib_recursive(4));
//}