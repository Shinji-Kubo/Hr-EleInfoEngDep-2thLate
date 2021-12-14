#include<stdio.h>
#include<stdlib.h>
#include<math.h>

char cnvMorse(long num);

int main(void) {
	int i;
	char c;
	char cint[100];
	char letter;
	FILE *fp;
	char file[] = "result1.txt";
	long morse;
	char stack[100];
	int top = 0;
	int num;
	
	fp = fopen(file, "r");
	if (fp == NULL) {
		printf("%s file not open.\n", file);
	}

	while ((c = getc(fp)) != EOF) {
		stack[top] = c;

		if (stack[top] == '0' && stack[top-1] == '0' && stack[top-2] == '0') {
			top -= 2;
			for (i=0; i<top; i++) {
				cint[i] = stack[i];
			}
			morse = atol(cint);
			letter = cnvMorse(morse);
			printf("%c", letter);
			for (i=0; i<top; i++) {
				cint[i] = "";
			}
			top = 0;
		} else {
			top++;
		}
	}

	return 0;
}

char cnvMorse(long num) {
	if (num == 102) {
		return 'a';
	} else if (num == 2010101) {
		return 'b';
	} else if (num == 2010201) {
		return 'c';
	} else if (num == 20101) {
		return 'd';
	} else if (num == 1) {
		return 'e';
	} else if (num == 1010201) {
		return 'f';
	} else if (num == 20201) {
		return 'g';
	} else if (num == 1010101) {
		return 'h';
	} else if (num == 101) {
		return 'i';
	} else if (num == 1020202) {
		return 'j';
	} else if (num == 20102) {
		return 'k';
	} else if (num == 1020101) {
		return 'l';
	} else if (num == 202) {
		return 'm';
	} else if (num == 201) {
		return 'n';
	} else if (num == 20202) {
		return 'o';
	} else if (num == 1020201) {
		return 'p';
	} else if (num == 2020102) {
		return 'q';
	} else if (num == 10201) {
		return 'r';
	} else if (num == 10101) {
		return 's';
	} else if (num == 2) {
		return 't';
	} else if (num == 10102) {
		return 'u';
	} else if (num == 1010102) {
		return 'v';
	} else if (num == 10202) {
		return 'w';
	} else if (num == 2010102) {
		return 'x';
	} else if (num == 2010202) {
		return 'y';
	} else if (num == 2020101) {
		return 'z';
	} else if (num == 10201020102) {
		return '.';
	} else if (num == 20201010202) {
		return ',';
	} else if (num == 20202010101) {
		return ':';
	} else if (num == 10102020101) {
		return '?';
	} else if (num == 20101010102) {
		return '-';
	} else if (num == 201020201) {
		return '(';
	} else if (num == 20102020102) {
		return ')';
	} else if (num == 201010201) {
		return '/';
	} else if (num == 10101020201) {
		return '[';
	} else if (num == 10101020202) {
		return ']';
	} else if (num == 10101010102) {
		return ';';
	} else if (num == 20102010202) {
		return '!';
	} else if (num == 102020202) {
		return '1';
	} else if (num == 101020202) {
		return '2';
	} else if (num == 101010202) {
		return '3';
	} else if (num == 101010102) {
		return '4';
	} else if (num == 101010101) {
		return '5';
	} else if (num == 201010101) {
		return '6';
	} else if (num == 202010101) {
		return '7';
	} else if (num == 202020101) {
		return '8';
	} else if (num == 202020201) {
		return '9';
	} else if (num == 202020202) {
		return '0';
	} else if (num == 0) {
		return ' ';
	} else if (num == 10201020101) {
		return '\n';
	}

	return "";
}
