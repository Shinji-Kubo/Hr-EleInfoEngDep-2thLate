#include<stdio.h>

main(void) {

	int i, j, sum;

	int div[1000];
	int divCnt = 0;
	int pfNum[1000];
	int pfNumCnt = 0;

	for (i=2; i<=10000; i++) {
		for (j=i-1; j>0; j--) {
			if (i % j == 0) {
				div[divCnt] = j;
				divCnt++;
			}
		}
		
		for (j=0; j<divCnt; j++) {
			sum += div[j];
		}

		if (i == sum) {
			pfNum[pfNumCnt] = i;
			pfNumCnt++;
		}

		divCnt = 0;
		sum = 0;	
	}

	for (i=0; i<pfNumCnt; i++) {
		printf("%d ", pfNum[i]);
	}

	printf("\n");

	return 0;
}
