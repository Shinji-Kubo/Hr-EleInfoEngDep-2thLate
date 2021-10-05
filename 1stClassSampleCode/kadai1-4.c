#include<stdio.h>
#define MAX 10000

main(void) {
	int i, j, n;
	int sumX = 0;
	int sumY = 0;

	for(n=2; n<MAX; n++) {
		for (i=1; i<=n/2; i++) {
			if (n % i == 0) {
				sumX += i;
			}
		}
		for (j=1; j<=sumX/2; j++) {
			if (sumX % j == 0) {
				sumY += j;
			}
			if ((sumY==n) && (sumX != sumY)) {
				printf("(%d, %d\n)", n, sumX);
			}
		}
	}

	return 0;

	return 0;
}
