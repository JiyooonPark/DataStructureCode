#include <stdio.h>

int factorial(int num) {
	printf("on factorial(%d)\n", num);
	if (num == 0) return 1;
	else {
		
		return num * factorial(num - 1);
	}
}
/*int main() {
	printf("%d", factorial(5));
}*/