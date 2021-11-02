#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 20
#define T 12

int genRand(int A, int B, int M, int X);
double genRegRand(double *xs);

typedef struct {
	double clsVal;
	int num;
	double dev;
	double dis;
} Quantity;

main(void) {
	int i, j;

	static int A = 13;
	static int B = 2 * N + 1;
	int M = pow(2, N);
	int X = 0;
	double rand;
	double xs[T];
	Quantity quantity[10];
	double sumAve = 0;
	double ave;
	int cnt = 0;
	double stdDev;

	for (i=0; i<10; i++) {
		quantity[i].clsVal = (0.1*i+0.1*(i+1)) / 2;
		quantity[i].num = 0;
	}

	for (i=0; i<M/T; i++) {
		for (j=0; j<T; j++) {
			X = genRand(A, B, M, X);
			xs[j] = 1.0 * X / M;
		}

		rand  = genRegRand(xs);

		if (rand < 1.0 && rand > 0.0) {
			for (j=0; j<10; j++) {
				if (rand >= 0.1*j && rand < 0.1*(j+1)) {
					quantity[j].num++;
				}
			}
			cnt++;
		}
	}

	for (i=0; i<10; i++) {
		sumAve += quantity[i].clsVal * quantity[i].num;
	}

	ave = sumAve / cnt;

	for (i=0; i<10; i++) {
		quantity[i].dev = quantity[i].clsVal - ave;
		quantity[i].dis = pow(quantity[i].dev, 2);

		stdDev += quantity[i].dis;
	}

	stdDev = sqrt(stdDev);

	printf("minimum value      : %f\n", quantity[0].clsVal);
	printf("maximum value      : %f\n", quantity[9].clsVal);
	printf("average            : %f\n", ave);
	printf("standard deviation : %f\n", stdDev);

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
