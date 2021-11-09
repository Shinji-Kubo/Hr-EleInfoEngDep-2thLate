#include<stdio.h>
#include<math.h>
#define PI 3.14

typedef struct {
	int x;
	int y;
} POS;

double x2, y2;

void SynTf(int x1, int y1, int rot, int expx, int expy, int skx, int sky, int mvx, int mvy);

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
		SynTf(pos[i].x, pos[i].y, 90, 1, 1, 0, 0, 0, 0);
		x = x2;
		y = y2;
		printf("%d %d\n", x, y);
	}

	return 0;

}

void SynTf(int x1, int y1, int rot, int expx, int expy, int skx, int sky, int mvx, int mvy) {
	double a, b, c, d, e, f;
	double degRot = rot * PI * 180.0;
	double degSkx = skx * PI * 180.0;
	double degSky = sky * PI * 180.0;

	a = cos(degRot) * expx + (-sin(degRot) * expy + tan(degSkx) * cos(degRot) * expx) * tan(degSky);
	b = -sin(degRot) * expx + tan(degSkx) * cos(degRot) * expx;
	c = (cos(degRot) * expx + (-sin(degRot) * expx + tan(degSkx) * cos(degRot) * expx) * tan(expy)) * mvx + (-sin(degRot) * expy + tan(degSkx) * cos(degRot) * expx) * mvy;
	d = sin(degRot) * expx + (cos(degRot) * expy + tan(degSkx) * sin(degRot) * expx) * tan(degSky);
	e = cos(degRot) * expy + tan(degSkx) * sin(degRot) * expx;
	f = (sin(degRot) * expx + (cos(degRot) * expy + tan(degSkx) * sin(degRot) * expx) * tan(degSky)) * mvx + (cos(degRot) * expy + tan(expx) * sin(degRot) * expx) * mvy;

	
	x2 = a * x1 + b * y1 + c + 0.5;
	y2 = d * x1 + e * y1 + f + 0.5;	

}
