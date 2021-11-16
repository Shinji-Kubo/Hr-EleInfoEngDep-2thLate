#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MRXX 2
#define MRXY 3

typedef struct {
	int x;
	int y;
} POS;

void calInvMrx();
void calMrx();

int a[2][2], b[MRXX][MRXY], c[MRXX][MRXY];
float M[8][8];
double MT[8][8];

int main(void) {
	int i = 0, j;
	FILE *fp;
	POS origin[5];
	POS mv[5];
	char originFile[] = "original.dat";
	char mvFile[] = "move.dat";

	fp = fopen(originFile, "r");
	if (fp == NULL) {
		printf("%s file not open.\n", originFile);
	}

	while (fscanf(fp, "%d %d", &origin[i].x, &origin[i].y) != EOF) {
		i++;
		if (i > 5) {
			break;
		}
	}

	fclose(fp);

	i = 0;

	fp = fopen(mvFile, "r");
	if (fp == NULL) {
		printf("%s file not open.\n", mvFile);
	}

	while (fscanf(fp, "%d %d", &mv[i].x, &mv[i].y) != EOF) {
		i++;
		if (i > 5) {
			break;
		}
	}

	fclose(fp);

	M[0][0] = origin[0].x;
	M[0][1] = origin[0].y;
	M[0][2] = 1;
	M[0][3] = 0;
	M[0][4] = 0;
	M[0][5] = 0;
	M[0][6] = -mv[0].x * origin[0].x;
	M[0][7] = -mv[0].x * origin[0].y;
	M[1][0] = 0;
	M[1][1] = 0;
	M[1][2] = 0;
	M[1][3] = origin[0].x;
	M[1][4] = origin[0].y;
	M[1][5] = 1;
	M[1][6] = -mv[0].y * origin[0].x;
	M[1][7] = -mv[0].y * origin[0].y;
	M[2][0] = origin[1].x;
	M[2][1] = origin[1].y;
	M[2][2] = 1;
	M[2][3] = 0;
	M[2][4] = 0;
	M[2][5] = 0;
	M[2][6] = -mv[1].x * origin[1].x;
	M[2][7] = -mv[1].x * origin[1].y;
	M[3][0] = 0;
	M[3][1] = 0;
	M[3][2] = 0;
	M[3][3] = origin[1].x;
	M[3][4] = origin[1].y;
	M[3][5] = 1;
	M[3][6] = -mv[1].y * origin[1].x;
	M[3][7] = -mv[1].y * origin[1].y;
	M[4][0] = origin[2].x;
	M[4][1] = origin[2].y;
	M[4][2] = 1;
	M[4][3] = 0;
	M[4][4] = 0;
	M[4][5] = 0;
	M[4][6] = -mv[2].x * origin[2].x;
	M[4][7] = -mv[2].x * origin[2].y;
	M[5][0] = 0;
	M[5][1] = 0;
	M[5][2] = 0;
	M[5][3] = origin[2].x;
	M[5][4] = origin[2].y;
	M[5][5] = 1;
	M[5][6] = -mv[1].y * origin[2].x;
	M[5][7] = -mv[1].y * origin[2].y;
	M[6][0] = origin[3].x;
	M[6][1] = origin[3].y;
	M[6][2] = 1;
	M[6][3] = 0;
	M[6][4] = 0;
	M[6][5] = 0;
	M[6][6] = -mv[3].x * origin[3].x;
	M[6][7] = -mv[3].x * origin[3].y;
	M[7][0] = 0;
	M[7][1] = 0;
	M[7][2] = 0;
	M[7][3] = origin[3].x;
	M[7][4] = origin[3].y;
	M[7][5] = 1;
	M[7][6] = -mv[1].y * origin[3].x;
	M[7][7] = -mv[1].y * origin[3].y;

	for (i=0; i<8; i++) {
		for (j=0; j<8; j++) {
			printf("%lf ", M[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	cofactors(M, 8);

	for (i=0; i<8; i++) {
		for (j=0; j<8; j++) {
			printf("%lf ", MT[i][j]);
		}
		printf("\n");
	}


	// a[0][0] = 1;
	// a[0][1] = 2;
	// a[1][0] = 3;
	// a[1][1] = 4;

	// b[0][0] = 5;
	// b[0][1] = 6;
	// b[0][2] = 7;
	// b[1][0] = 8;
	// b[1][1] = 9;
	// b[1][2] = 10;

	// calMrx();

	// for (i=0; i<2; i++) {
	// 	for (j=0; j<3; j++) {
	// 		printf("%d ", c[i][j]);
	// 	}
	// 	printf("\n");
	// }

	return 0;
}

void calInvMrx() {
	 		
		
}

void calMrx() {
	int i, j, k, term;

	for (i=0; i<MRXX; ++i) {
		for (j=0; j<MRXY; ++j) {
			c[i][j] = a[i][j] * b[i][j];

			for (i=0; i<MRXX; i++) {
				for (j=0; j<MRXY; j++) {
					term = 0;
					for (k=0; k<2; k++) {
						term = term + a[i][k] * b[k][j];
					}
					c[i][j] = term;
				}
			}
		}
	}	
}
