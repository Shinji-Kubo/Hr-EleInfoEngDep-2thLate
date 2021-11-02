#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

main(void) {
	int i, j;

	int x, y;
	int n = 0;
	int N = 0;
	double pi[8];

	for (i=3; i<9; i++) {
		for(j=0; j<pow(10, i); j++) {
			x = -10 + (int)(rand() * (10 + 10 + 1.0) / (1.0 + RAND_MAX));
			y = -10 + (int)(rand() * (10 + 10 + 1.0) / (1.0 + RAND_MAX));

			// printf("%d : (%d, %d)\n", i, x, y);
			// printf("%d\n", n);
			// printf("%d\n", N);

			if (x >= 0 && y >= 0) {
				n++;
			}

			N++;
		}

		pi[i-3] = 1.0 * N / n;

		n = 0;
		N = 0;
	}

	for (i=0; i<8; i++) {
		printf("%f\n", pi[i]);
	}

	return 0;
}
