#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int x;
	int y;
} POS;

double inMrx[3][3];
double idMrx[][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

void calInvMrx();

int main(void) {
	int i, j, n = 1;

	printf("----------------------------------------------\n");

	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			printf("[%d]", n);
			n++;
		}
		printf("\n");
	}

	n = 1;
	
	printf("----------------------------------------------\n\n");


	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			printf("Please input %d : ", n);
			n++;
			scanf("%lf", &inMrx[i][j]);
		}
	}

	printf("----------------------------------------------\n");
	printf("ORIGINAL\n");
	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			printf("[%lf]", inMrx[i][j]);
		}
		printf("\n");
	}

	calInvMrx();

	printf("----------------------------------------------\n\n");
	printf("CALCULATION RESULT\n");
	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			printf("[%lf]", idMrx[i][j]);
		}
		printf("\n");
	}

	return 0;
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
