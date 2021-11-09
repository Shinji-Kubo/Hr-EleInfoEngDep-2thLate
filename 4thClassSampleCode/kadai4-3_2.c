#include<stdio.h>
#include<math.h>
#define PI 3.14

typedef struct {
	int x;
	int y;
} POS;

double x2, y2;

void rotation(int x1, int y1, int degree);
void mirrory(int x1, int y1);

int main(void) {
	int x, y;
	int i = 0;
	POS pos[5];
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
		mirrory(x2, y2);
		rotation(pos[i].x, pos[i].y, 45);
		x = x2;
		y = y2;
		printf("%d %d\n", x, y);
	}
}

void rotation(int x1, int y1, int degree) {

	x2 = cos(degree * PI / 180.0) * x1 - sin(degree * PI / 180.0) * y1 + 0.5;
	y2 = sin(degree * PI / 180.0) * x1 + cos(degree * PI / 180.0) * y1 + 0.5;
}

void mirrory(int x1, int y1) {

	x2 = -x1;
	y2 = -y1;
}
