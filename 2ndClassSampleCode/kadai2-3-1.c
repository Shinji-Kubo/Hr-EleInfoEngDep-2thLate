#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 20

int genRand(int A, int B, int M, int X);

main(void) {
	int i, j;

	static int A = 13;
	static int B = 2 * N + 1;
	int M = pow(2, N);
	int X = 0;
	double rand;
	int quantity[10];

	for (i=0; i<10; i++) {
		quantity[i] = 0;
	}

	for (i=0; i<M; i++) {
		X = genRand(A, B, M, X);
		rand = 1.0 * X / M;

		// printf("%f\n", rand);

		for (j=0; j<10; j++) {
			if (rand >= 0.1*j && rand < 0.1*(j+1)) {
				quantity[j]++;
			}
		}

	}

	for (i=0; i<10; i++) {
		printf("%1.1f~%1.1f : %d | ", 0.1*i, 0.1*(i+1), quantity[i]);
		for (j=0; j<100*quantity[i]/M; j++) {
			printf("*");
		}
		printf(" \n");
	}

	return 0;
}

int genRand(int A, int B, int M, int X) {
	return abs((A * X + B) % M);
}


// 自然界の4つの力
// クーロン力 >> 万有引力
// 現在、物理学上の基本的な力は、全て「近接作用」と考えられている
// 電場の源は電荷である
// 電流と電場の時間変化(変位電流)が磁場を生む
