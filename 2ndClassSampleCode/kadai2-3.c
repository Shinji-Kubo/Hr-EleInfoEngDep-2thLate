#include<stdio.h>
#include<stdlib.h>
#define N 32

typedef struct {
	int cnt;
} Quantity;

int genRand(int A, int B, int M, int X) {
	return abs((A * X + B) % M);
}

main(void) {
	int i, j;
	
	static int A = 13;
	static int B = 2 * N + 1;
	static int M = pow(2, N);
	int X = 0;
	double rand;
	Quantity quantity[10];

	for(i=0; i<10; i++) {
		quantity[i].cnt = 0;
	}

	 for (i=0; i<M; i++) {

		X = genRand(A, B, M, X);
		rand = 1.0 * X / M;
		printf("%d : %f\n", i, rand);

		for (j=0; j<10; j++) {
			if (rand >= 0.1*j && rand < 0.1*(j+1)) {
				quantity[j].cnt++;
				break;
			}
		}

		printf("------------------------------------------------\n");
		for (j=0; j<10; j++) {
			printf("%f : %d\n", j, quantity[i].cnt);
		}
		printf("------------------------------------------------\n");

	}

	for (i=0; i<10; i++) {
		printf("%d : %d\n", i, quantity[i].cnt);
	}

	return 0;
}
