#include<stdio.h>
#include<stdlib.h>
#define NY 128
#define NX 128

int main(void) {
	int i, j, a, b, c, d;
	FILE *fp;
	char fn[] = "image.txt";
	int img[NY][NX];

	a = 20;
	b = 108;
	c = 20;
	d = 108;

	for (i=0; i<NY; i++) {
		for (j=0; j<NX; j++) {
			img[i][j] = 0;
		}
	}

	for (i=0; i<NY; i++) {
		for (j=0; j<NX; j++) {
			if (NX > a && NX < b && NY > c && NY < d) {
				img[i][j] = 1;
			}
		}
	}

	fp = fopen(fn, "wb");
	if (fp == NULL) {
		printf("File open error \n");
		exit(1);
	}

	for (i=0; i<NY; i++) {
		fwrite(img[j], NX, sizeof(int), fp);
	}

	fclose(fp);

	
	return 0;
}
