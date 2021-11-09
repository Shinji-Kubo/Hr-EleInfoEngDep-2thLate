#include<stdio.h>
#include<math.h>
#define PI 3.14

typedef struct {
	int x;
	int y;
} POS;

double a, b, c, d, e, f, g, h, i;
double inMrx[3][3];
double idMrx[][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

void SynTf(int rot, int expx, int expy, int skx, int sky, int mvx, int mvy);
void calInvMrx();

int main(void) {
	int x, y;
	int i = 0, j;
	POS pos[5];
	FILE *fp;
	char filename[] = "kadai5-1.dat";

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
	
	SynTf(90, 1, 1, 0, 0, 0, 0);
	inMrx[0][0] = a;
	inMrx[0][1] = b;
	inMrx[0][2] = c;
	inMrx[1][0] = d;
	inMrx[1][1] = e;
	inMrx[1][2] = f;
	inMrx[2][0] = g;
	inMrx[2][1] = h;
	inMrx[2][2] = i;
	calInvMrx();

	for (i=0; i<5; i++) {
		x = idMrx[0][0] * pos[i].x + idMrx[0][1] * pos[i].y + idMrx[0][2] + 0.5;
		y = idMrx[1][0] * pos[i].x + idMrx[1][1] * pos[i].y + idMrx[1][2] + 0.5;
		printf("%d %d\n", x, y);
	}	

	return 0;
}

void SynTf(int rot, int expx, int expy, int skx, int sky, int mvx, int mvy) {
	double degRot = rot * PI * 180.0;
	double degSkx = skx * PI * 180.0;
	double degSky = sky * PI * 180.0;

	a = cos(degRot) * expx + (-sin(degRot) * expy + tan(degSkx) * cos(degRot) * expx) * tan(degSky);
	b = -sin(degRot) * expx + tan(degSkx) * cos(degRot) * expx;
	c = (cos(degRot) * expx + (-sin(degRot) * expx + tan(degSkx) * cos(degRot) * expx) * tan(expy)) * mvx + (-sin(degRot) * expy + tan(degSkx) * cos(degRot) * expx) * mvy;
	d = sin(degRot) * expx + (cos(degRot) * expy + tan(degSkx) * sin(degRot) * expx) * tan(degSky);
	e = cos(degRot) * expy + tan(degSkx) * sin(degRot) * expx;
	f = (sin(degRot) * expx + (cos(degRot) * expy + tan(degSkx) * sin(degRot) * expx) * tan(degSky)) * mvx + (cos(degRot) * expy + tan(expx) * sin(degRot) * expx) * mvy;

	g = 0;
	h = 0;
	i = 1;	

}

void calInvMrx() {
	int i, j;
	double max, buf;
	POS maxPos;

	// Find Max Item
	max = abs(inMrx[0][0]);
	maxPos.x = 0;
	maxPos.y = 0;
	for (i=1; i<3; i++) {
		if (abs(inMrx[i][0]) > max) {
			max = abs(inMrx[i][0]);
			maxPos.x = i;
			maxPos.y = 0;
		}
	}
	if (maxPos.x != 0) {
		for (i=0; i<3; i++) {
			buf = inMrx[maxPos.x][i];
			inMrx[maxPos.x][i] = inMrx[0][i];
			inMrx[0][i] = buf;
			buf = idMrx[maxPos.x][i];
			idMrx[maxPos.x][i] = idMrx[0][i];
			idMrx[0][i] = buf;
		}
	}

	// [0][0] == 0
	buf = inMrx[0][0];
	for (i=0; i<3; i++) {
		inMrx[0][i] /= buf;
	}
	for (i=0; i<3; i++) {
		idMrx[0][i] /= buf;
	}


	// [1][0] == 0
	buf = inMrx[1][0];
	for (i=0; i<3; i++) {
		inMrx[1][i] -= inMrx[0][i] * buf;
	}
	for (i=0; i<3; i++) {
		idMrx[1][i] -= idMrx[0][i] * buf;
	}

	// [2][0] == 0
	buf = inMrx[2][0];
	for (i=0; i<3; i++) {
		inMrx[2][i] -= inMrx[0][i] * buf;
	}
	for (i=0; i<3; i++) {
		idMrx[2][i] -= idMrx[0][i] * buf;
	}

	// Find Max Item
	max = abs(inMrx[1][1]);
	maxPos.x = 1;
	maxPos.y = 1;
	for (i=2; i<3; i++) {
		if (abs(inMrx[i][1]) > max) {
			max = abs(inMrx[i][1]);
			maxPos.x = i;
			maxPos.y = 1;
		}
	}
	if (maxPos.x != 1) {
		for (i=0; i<3; i++) {
			buf = inMrx[maxPos.x][i];
			inMrx[maxPos.x][i] = inMrx[1][i];
			inMrx[1][i] = buf;
			buf = idMrx[maxPos.x][i];
			idMrx[maxPos.x][i] = idMrx[1][i];
			idMrx[1][i] = buf;
		}
	}

	// [1][1] == 1
	buf = inMrx[1][1];
	for (i=0; i<3; i++) {
		inMrx[1][i] /= buf;
	}
	for (i=0; i<3; i++) {
		idMrx[1][i] /= buf;
	}

	// [0][1] == 0
	buf = inMrx[0][1];
	for (i=0; i<3; i++) {
		inMrx[0][i] -= inMrx[1][i] * buf;
	}
	for (i=0; i<3; i++) {
		idMrx[0][i] -= idMrx[1][i] * buf;
	}

	// [2][1] == 0
	buf = inMrx[2][1];
	for (i=0; i<3; i++) {
		inMrx[2][i] -= inMrx[1][i] * buf;
	}
	for (i=0; i<3; i++) {
		idMrx[2][i] -= idMrx[1][i] * buf;
	}

	// [2][2] == 1
	buf = inMrx[2][2];
	for (i=0; i<3; i++) {
		inMrx[2][i] /= buf;
	}
	for (i=0; i<3; i++) {
		idMrx[2][i] /= buf;
	}

	// [0][2] == 0
	buf = inMrx[0][2];
	for (i=0; i<3; i++) {
		inMrx[0][i] -= inMrx[2][i] * buf;
	}
	for (i=0; i<3; i++) {
		idMrx[0][i] -= idMrx[2][i] * buf;
	}

	// [1][2] == 0
	buf = inMrx[1][2];
	for (i=0; i<3; i++) {
		inMrx[1][i] -= inMrx[2][i] * buf;
	}
	for (i=0; i<3; i++) {
		idMrx[1][i] -= idMrx[2][i] * buf;
	}	
}
