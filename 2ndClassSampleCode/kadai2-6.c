#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define M 7

typedef struct {
	double pi;
	double dev;
	double dis;
} Number;

main(void) {
	int i, j;

	int x, y;
	int n = 0;
	int N = 0;
	double ave = 0.0;
	double regDev = 0.0;
	Number num[100];

	for (i=0; i<100; i++) {
		for (j=0; j<pow(10, M); j++) {
			x = -10 + (int)(rand() * (10 + 10 + 1.0) / (1.0 + RAND_MAX));
			y = -10 + (int)(rand() * (10 + 10 + 1.0) / (1.0 + RAND_MAX));

			if (x >= 0 && y >= 0) {
				n++;
			}

			N++;
		}

		num[i].pi = 1.0 * N / n;
		ave += num[i].pi;

		n = 0;
		N = 0;
	}

	ave /= 100.0;

	for (i=0; i<100; i++) {
		num[i].dev = ave - num[i].pi;
		num[i].dis = pow(num[i].dev, 2);
		regDev += num[i].dis;
	}

	regDev /= 100;
	regDev = sqrt(regDev);

	printf("regDev : %f\n", regDev);

	return 0;
}
