#include<stdio.h>
#include<math.h>
#define PI 3.14

typedef struct {
	int x;
	int y;
} POS;

double x2, y2;

void rotation(int x1, int y1, int degree);
void resize(int x1, int y1, double sx, double sy);
void skewx(int x1, int y1, int degree);
void skewy(int x1, int y1, int degree);

int main(void) {
	int x, y;
	int i = 0;
	POS pos[5];
	int *calRotPos, *calResPos, *calSkxPos, *calSkyPos;
	FILE *fp;
	char filename[] = "point.dat";
	
	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("%s file not open.\n", filename);
	}

	while (fscanf(fp, "%d %d", &pos[i].x, &pos[i].y) != EOF) {
		i++;
		if (i > 5) {
			break;
		}
	}

	fclose(fp);

	printf("original\n------------------------------------------\n");
	for (i=0; i<5; i++) {
		printf("%d %d\n", pos[i].x, pos[i].y);
	}
	printf("\n\n");
	
	printf("rotation\n------------------------------------------\n");
	for (i=0; i<5; i++) {
		rotation(pos[i].x, pos[i].y, 90);
		x = x2;
		y = y2;
		printf("%d %d\n", x, y);
	}
	printf("\n\n");
	
	printf("resize\n------------------------------------------\n");
	for (i=0; i<5; i++) {
		resize(pos[i].x, pos[i].y, 0.75, 1.5);
		x = x2;
		y = y2;
		printf("%d %d\n", x, y);
	}
	printf("\n\n");
	
	printf("skewx\n------------------------------------------\n");
	for (i=0; i<5; i++) {
		skewx(pos[i].x, pos[i].y, 10);
		x = x2;
		y = y2;
		printf("%d %d\n", x, y);
	}
	printf("\n\n");

	printf("skewy\n------------------------------------------\n");
	for (i=0; i<5; i++) {
		skewy(pos[i].x, pos[i].y, 10);
		x = x2;
		y = y2;
		printf("%d %d\n", x, y);
	}
	printf("\n\n");

	return 0;
}

void rotation(int x1, int y1, int degree) {

	x2 = cos(degree * PI / 180.0) * x1 - sin(degree * PI / 180.0) * y1 + 0.5;
	y2 = sin(degree * PI / 180.0) * x1 + cos(degree * PI / 180.0) * y1 + 0.5;
}

void resize(int x1, int y1, double sx, double sy) {

	x2 = sx * x1 + 0.5;
	y2 = sy * y1 + 0.5;	 
}

void skewx(int x1, int y1, int degree) {

	x2 = x1 + tan(degree * PI / 180.0) * y1 + 0.5;
	y2 = y1 + 0.5;
}

void skewy(int x1, int y1, int degree) {

	x2 = x1 + 0.5;
	y2 = tan(degree * PI / 180.0) * x1 + y1 + 0.5;
}
