#include<stdio.h>
#include<math.h>
#define N 32
#define T 12

int genRand(int A, int B, int M, int X);

main(void) {
	int i, j;

	static int A = 13;
	static int B = 2 * N + 1;
	static int M = pow(2, N);
	int X = 1;
	double rand, sum;

	for (i=0; i<M/T; i++) {
		X = genRand(A, B, M, X);
		rand = 1.0 * X / M;

		for (j=0; j<T; j++) {
			X = genRand(A, B, M, X);
			rand = 1.0 * X / M;
			sum += rand;	
		}

		if (sum - 6 < 1.0 && sum - 6 > 0.0) {
			printf("%f\n", sum - 6);
		}

		sum = 0;
	}

	return 0;
}

int genRand(int A, int B, int M, int X) {
	return abs((A * X + B) % M);
}
