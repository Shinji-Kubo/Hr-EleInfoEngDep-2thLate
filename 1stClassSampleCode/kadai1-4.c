#include<stdio.h>
#define MAX 10000

int arr[MAX];

main(void) {
	int x, y, i;

	for(i=0; i<MAX; i++) {
		arr[i] = 0;
	}

	for(x=1; x<MAX/2; x++) {
		for(i=2; i*x < MAX; i++) {
			arr[i*x] += x;
		}
	}
	
	for (x=1; x<MAX; x++) {
		y = arr[x];
		if (y < MAX && x < y && arr[y] == x) {
			printf("(%d, %d)\n", x, y);
		}
	}

	return 0;
}
