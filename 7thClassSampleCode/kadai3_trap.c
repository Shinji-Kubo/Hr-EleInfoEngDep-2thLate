#include<stdio.h>
#include<math.h>

double napier(double x);
double trap(int n, int a, int b);

int main(void) {
	int n;
	double area;

	for (n=2; n<101; n++) {
		area = trap(n, 0, 1);
		printf("%d %lf\n", n, area);
	}

	return 0;
}

double napier(double x) {
	return pow(M_E, x);
}

double trap(int n, int a, int b) {
	int i;
	double area = 0.0, x = a;
	double h = 1.0 * (b - a) / n;

	for (i=0; i<n; i++) {
		area += ((napier(x) + napier(x+h)) / 2) * h;
		x += h; 
	}

	return area;
}
