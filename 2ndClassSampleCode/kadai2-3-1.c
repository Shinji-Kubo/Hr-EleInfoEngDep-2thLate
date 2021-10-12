#include<stdio.h>
#include<math.h>
#define N 32

int genRand(int A, int B, int M, int X);

main(void) {
	int i;

	static int A = 13;
	static int B = 2 * N + 1;
	static int M = pow(2, N);
	int X = 0;
	double rand;
	double firTerm;
	double endTerm;

	for (i=0; i<M; i++) {
		X = genRand(A, B, M, X);
		rand = 1.0 * X / M;
		printf("%f\n", rand);
	}

	return 0;
}

int genRand(int A, int B, int M, int X) {
	return abs((A * X + B) % M);
}
