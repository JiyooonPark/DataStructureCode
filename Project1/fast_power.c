#include <stdio.h>

double fast_power(double x, int n) {
	if (n == 0) return 1;
	else if ((n % 2) == 0) return fast_power(x * x, n / 2);
	else return x * fast_power(x * x, (n - 1) / 2);
}
//int main() {
//	printf("%.0f", fast_power(2, 10));
//}