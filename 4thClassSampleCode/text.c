#include<stdio.h>
#include<math.h>
#define PI 3.14

int main(void) {
	int degree = 180;
	double x2;

	x2 = cos(degree * PI / 180.0);

	printf("%lf\n", x2);

	return 0;
}

