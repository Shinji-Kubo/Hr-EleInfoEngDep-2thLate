#include<stdio.h>

typedef struct {
	int num;
	int isPrime; //1 -> true 0 -> false
} Collect;

main(void) {

	int i, j, cnt;

	int min = 1000;
	int max = 9999;
	Collect collect[9000];

	cnt = 0;

	for (i=min; i<=max; i++) {
		collect[cnt].num = i;
		collect[cnt].isPrime = 1;
		cnt++;
	}

	for (i=2; i<max; i++) {
		for (j=0; j<9000; j++) {
			if(collect[j].num != i && collect[j].num % i == 0) {
				collect[j].isPrime = 0;	
			}
		}		
	}

	for (i=0; i<9000; i++) {
		if(collect[i].isPrime == 1) {
			printf("%d,", collect[i].num);
		}
	}

	printf("\n");

	return 0;
}
