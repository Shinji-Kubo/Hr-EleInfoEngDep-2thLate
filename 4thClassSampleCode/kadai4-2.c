#include<stdio.h>
#include<math.h>
#define PI 3.14

typedef struct {
	int x;
	int y;
} POS;

double x2, y2;

void CompFunc(int x1, int y1, int rot, int expx, int expy, int skx, int sky, int mvx, int mvy);

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
		CompFunc(pos[i].x, pos[i].y, 45, 1, 1, 0, 0, 0, 0);
		x = x2;
		y = y2;
		printf("%d %d\n", x, y);
	}

	return 0;
}

void CompFunc(int x1, int y1, int rot, int expx, int expy, int skx, int sky, int mvx, int mvy) {
	double a, b, c, d, e, f, g, h, i;

	a = cos(rot * PI / 180.0) * expx + (-sin(rot) * expy + tan(skx) * cos(rot) * expx) * tan(sky);
	b = -sin(rot) * expy + tan(skx) * cos(rot) * expx;
	c = (cos(rot) * expx + (-sin(rot) * expy + tan(skx) * cos(rot) * expx) * tan(sky)) * mvx + (-sin(rot) * expy + tan(skx) * cos(rot) * expx) * mvy;
	d = sin(rot) * expx + (cos(rot) * expy + tan(skx) * sin(rot) * expx) * tan(sky);
	e = cos(rot) * expy + tan(skx) * sin(rot) * expx;
	f = (sin(rot) * expx + (cos(rot) * expy + tan(skx) * sin(rot) * expx) * tan(sky)) * mvx + (cos(rot) * expy + tan(skx) * sin(rot) * expx) * mvy;

	x2 = a * x1 + b * y1 + c + 0.5;
	y2 = d * x1 + e * y1 + f + 0.5;
}
