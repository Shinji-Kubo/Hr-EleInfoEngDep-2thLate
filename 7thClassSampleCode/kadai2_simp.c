#include<stdio.h>
#include<math.h>

double calSin(double x);
double simp(int n, double a, double b);

int main(void) {
	int n;
	double area;

	for (n=2; n<101; n++) {
		area = simp(n, 0, M_PI);
		printf("%d %lf\n", n, area);
	}

	return 0;
}

double calSin(double x) {
	return sin(x);
}

double simp(int n, double a, double b) {
	int i;
	double ans1, ans2;
	double area = 0.0, x[2 * n], pos = a;
	double h = 1.0 * (b - a) / (2 * n);

	for (i=0; i<2*n; i++) {
		x[i] = pos;
		pos += h;
	}

	for (i=1; i<=n; i++) {
		ans1 += calSin(x[2*i-1]);
	}

	for (i=1; i<n; i++) {
		ans2 += calSin(x[2*i]);
	}

	area = (h / 3) * (calSin(x[0]) + 4 * ans1 + 2 * ans2 + calSin(x[2*n]));

	return area;
}
