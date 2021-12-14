#include<stdio.h>

long cvnMorse(char letter);

int main(void) {
	char c;
	FILE *fp;
	char file[] = "sample.txt";
	long morse;

	fp = fopen(file, "r");
	if (fp == NULL) {
		printf("%s file not open.\n", file);
	}

	while ((c = getc(fp)) != EOF) {
		morse = cvnMorse(c);
		printf("%ld000", morse);
	}

	printf("\n");

	close(fp);

	return 0;
}

long cvnMorse(char letter) {
	char c = tolower(letter);

	if (c == 'a') {
		return 102;
	} else if (c == 'b') {
		return 2010101;
	} else if (c == 'c') {
		return 2010201;
	} else if (c == 'd') {
		return 20101;
	} else if (c == 'e') {
		return 1;
	} else if (c == 'f') {
		return 1010201;
	} else if (c == 'g') {
		return 20201;
	} else if (c == 'h') {
		return 1010101;
	} else if (c == 'i') {
		return 101;
	} else if (c == 'j') {
		return 1020202;
	} else if (c == 'k') {
		return 20102;
	} else if (c == 'l') {
		return 1020101;
	} else if (c == 'm') {
		return 202;
	} else if (c == 'n') {
		return 201;
	} else if (c == 'o') {
		return 20202;
	} else if (c == 'p') {
		return 1020201;
	} else if (c == 'q') {
		return 2020102;
	} else if (c == 'r') {
		return 10201;
	} else if (c == 's') {
		return 10101;
	} else if (c == 't') {
		return 2;
	} else if (c == 'u') {
		return 10102;
	} else if (c == 'v') {
		return 1010102;
	} else if (c == 'w') {
		return 10202;
	} else if (c == 'x') {
		return 2010102;
	} else if (c == 'y') {
		return 2010202;
	} else if (c == 'z') {
		return 2020101;
	} else if (c == '.') {
		return 10201020102;
	} else if (c == ',') {
		return 20201010202;
	} else if (c == ':') {
		return 20202010101;
	} else if (c == '?') {
		return 10102020101;
	} else if (c == '-') {
		return 20101010102;
	} else if (c == '(') {
		return 201020201;
	} else if (c == ')') {
		return 20102020102;
	} else if (c == '/') {
		return 201010201;
	} else if (c == '[') {
		return 10101020201;
	} else if (c == ']') {
		return 10101020202;
	} else if (c == ';') {
		return 10101010102;
	} else if (c == '!') {
		return 20102010202;
	} else if (c == '1') {
		return 102020202;
	} else if (c == '2') {
		return 101020202;
	} else if (c == '3') {
		return 101010202;
	} else if (c == '4') {
		return 101010102;
	} else if (c == '5') {
		return 101010101;
	} else if (c == '6') {
		return 201010101;
	} else if (c == '7') {
		return 202010101;
	} else if (c == '8') {
		return 202020101;
	} else if (c == '9') {
		return 202020201;
	} else if (c == '0') {
		return 202020202;
	} else if (c == ' ') {
		return 0;
	} else if (c == '\n') {
		return 10201020101;
	}

	return 0;
}
