#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10
#define T 12

int genRand(int A, int B, int M, int X);
double genRegRand(double *xs);

main(void) {
	int i, j;

	static int A = 13;
	static int B = 2 * N + 1;
	int M = pow(2, N);
	int X = 1;
	double xs[T];
	double rand;

	for (i=0; i<M/T; i++) {

		for (j=0; j<T; j++) {
			X = genRand(A, B, M, X);
			xs[j] = 1.0 * X / M;
		}

		rand = genRegRand(xs);

		if (rand < 1.0 && rand > 0.0) {
			// printf("%d : ", i);
			printf("%f\n", rand);
		}
	}

	return 0;
}

int genRand(int A, int B, int M, int X) {
	return abs((A * X + B) % M);
}

double genRegRand(double *xs) {
	int i;
	double sum;

	for (i=0; i<T; i++) {
		sum += *(xs+i);
	}

	return sum - 6.0;
}
