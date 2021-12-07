#include<stdio.h>

typedef struct {
	char c;
	int num;
} CharNum;

int main(void) {
	int total = 0;
	char c;
	FILE *fp;
	char file[] = "sample1.txt";
	char str[10];
	int i, j = 0;
	CharNum charNum[93];

	for (i=33; i<=126; i++) {
		sprintf(str, "%c", i);
		charNum[j].c = str[0];
		charNum[j].num = 0;
		j++;	
	}

	fp = fopen(file, "r");
	if (fp == NULL) {
		printf("%s file not open.\n", file);
	}

	while ((c = getc(fp)) != EOF) {
		for (i=0; i<j; i++) {
			if (c == charNum[i].c) {
				total++;
				charNum[i].num++;
				break;
			}
		}
	}

	close(fp);

	printf("total : %d\n", total);
	for (i=0; i<j; i++) {
		printf("%c:%d(%lf)\n", charNum[i].c, charNum[i].num, (1.0 * charNum[i].num) / total);
	}

	return 0;
}
