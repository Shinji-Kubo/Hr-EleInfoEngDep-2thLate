#include<stdio.h>
#include<math.h>
#define PI 3.14

typedef struct {
	int x;
	int y;
} POS;

double x2, y2;

void movement(int x1, int y1, int tx, int ty);

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

	for (i=0; i<5; i++) {
		movement(pos[i].x, pos[i].y, 3, 3);
		x = x2;
		y = y2;
		printf("%d %d\n", x, y);
	}

	return 0;
}

void movement(int x1, int y1, int tx, int ty) {

	x2 = x1 + tx + 0.5;
	y2 = y1 + ty + 0.5;
}
