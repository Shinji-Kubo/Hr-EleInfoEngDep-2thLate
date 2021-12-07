#include<stdio.h>
#include<string.h>

void selectionSort(char data[][20], int left, int right) {
	int start;
	int i;
	char min[20];
	int i_min;
	char tmp[20];

	if (left == right) {
		return;
	}

	start = left;

	for (start=left; start<right; start++) {
		i_min = start;
		strcpy(min, data[i_min]);

		for (i=start; i<=right; i++) {
			if (strcmp(min, data[i]) > 0) {
				strcpy(min, data[i]);
				i_min = i;
			}
		}

		if (start != i_min) {
			strcpy(tmp, data[start]);
			strcpy(data[start], data[i_min]);
			strcpy(data[i_min], tmp);
		}
	}
}

typedef struct {
	char word[20];
	int num;
} WordNum;

int main(void) {
	int judge = 1; // 0->false 1->true
	int is = 0; // 0->false 1->true
	char cha, c;
	int i, j;
	int strTop = 0;
	int wordTop = 0;
	char strStk[20], word[500][20];
	FILE *fp;
	char file[] = "sample2.txt";
	WordNum wordNum[500];

	fp = fopen(file, "r");
	if (fp == NULL) {
		printf("%s file not open.\n", file);
	}

	while ((cha = getc(fp)) != EOF) {
		c = tolower(cha);
		if ('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || '0' <= c && c <= '9') {
			strStk[strTop] = c;
			strTop++;
		} else {
			if (strTop != 0) {
				for (i=0; i<wordTop; i++) {
					for (j=0; j<strTop; j++) {
						if (strStk[j] != wordNum[i].word[j]) {
							judge = 0;
							break;
						}
					}
					if (judge == 1) {
						wordNum[i].num++;
						is = 1;
						break;
					} else {
						judge = 1;
					}
				}
				if (is == 0) {	
					for (j=0; j<strTop; j++) {
						wordNum[wordTop].word[j] = strStk[j];
					}
					wordNum[wordTop].num = 1;
					wordTop++;
				} else {
					is = 0;
				}
			}
			strTop = 0;
		}
	}

	for (i=0; i<wordTop; i++) {
		for (j=0; j<20; j++) {
			word[i][j] = wordNum[i].word[j];
		}
	}

	selectionSort(word, 0, wordTop - 1);

	for (i=0; i<wordTop; i++) {
		for (j=0; j<wordTop; j++) {
			if (strcmp(wordNum[j].word, word[i]) == 0) {
				printf("%s(%d)\n", wordNum[j].word, wordNum[j].num);
				break;
			}
		}
	}
	

	return 0;
}
