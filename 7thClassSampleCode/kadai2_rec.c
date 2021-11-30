#include<stdio.h>
#include<math.h>

double calSin(double x);
double rec(int n, double a, double b);

int main(void) {
	int n;
	double area;

	for (n=2; n<101; n++) {
		area = rec(n, 0, M_PI);
		printf("%d %lf\n", n, area);
	}

	return 0;
}

double calSin(double x) {
	return sin(x);	
}

double rec(int n, double a, double b) {
	int i;
	double area = 0.0, x = a;
	double h = 1.0 * (b - a) / n;

	for (i=0; i<n; i++) {
		area += calSin(x) * h;
		x += h;
	}

	return area;
}
