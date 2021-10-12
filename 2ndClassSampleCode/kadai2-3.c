#include<stdio.h>
#include<stdlib.h>
#define N 256

typedef struct {
	int cnt;
} Quantity;

main(void) {
	int i;

	FILE *fp;
	char fname[] = "kadai2-3-1.txt";
	char str[N];
	double num;
	Quantity quantity[10];
	int cnt = 0;

	fp = fopen(fname, "r");
	if (fp == NULL) {
		printf("%s couldn't open.\n", fname);
		return -1;
	}

	while (fgets(str, N, fp) != NULL) {
		num = atof(str);
		printf("%d : %f\n", cnt, num);

		for (i=0; i<10; i++) {
			if (num >= 0.1*i && num < 0.1*i+1) {
				quantity[i].cnt++;
				break;
			}
		}

		cnt++;
	}

	fclose(fp);

	for (i=0; i<10; i++) {
		printf("%d : %d\n", i, quantity[i].cnt);
	}

	return 0;
}
