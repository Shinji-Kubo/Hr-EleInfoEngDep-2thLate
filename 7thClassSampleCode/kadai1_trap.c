#include<stdio.h>
#include<math.h>

double circle(double x);
double trap(int n, int a, int b);

int main(void) {
	int n;
	double area;

	for (n=2; n<101; n++) {
		area = trap(n, -1, 1) * 2.0;
		printf("%d %lf\n", n, area);
	}

	return 0;
}

double circle(double x) {
	if (x > 1) {
		return 0;
	}
	return sqrt(1 - (x * x));
}

double trap(int n, int a, int b) {
	int i;
	double area = 0.0, x = a;
	double h = 1.0 * (b - a) / n;

	for (i=0; i<n; i++) {
		area += ((circle(x) + circle(x+h)) / 2) * h;
		x += h; 
	}

	return area;
}
