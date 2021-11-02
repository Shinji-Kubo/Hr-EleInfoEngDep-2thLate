#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 20
#define T 12

int genRand(int A, int B, int M, int X);
double genRegRand(double *xs);

main(void) {
	int i, j, n;

	static int A = 13;
	static int B = 2 * N + 1;
	int M = pow(2, N);
	int X = 0;
	double rand;
	double xs[T];
	int quantity[10];

	for (i=0; i<10; i++) {
		quantity[i] = 0;
	}

	for (i=0; i<M/T; i++) {
		for (j=0; j<T; j++) {
			X = genRand(A, B, M, X);
			xs[j] = 1.0 * X / M;
		}

		rand = genRegRand(xs);

		if (rand < 1.0 && rand > 0.0) {
			for (j=0; j<10; j++) {
				if (rand >= 0.1*j && rand < 0.1*(j+1)) {
					quantity[j]++;
				}
			}
		}
	}

	for (i=0; i<10; i++) {
		printf("%d : %d | ", i, quantity[i]);
		for (j=0; j<quantity[i]/100; j++) {
			printf("*");
		}
		printf(" \n");
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
