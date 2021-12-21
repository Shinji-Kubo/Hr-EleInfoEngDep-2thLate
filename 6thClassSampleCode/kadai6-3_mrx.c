#include<stdio.h>

typedef struct {
    int x;
    int y;
} POS;

void calInvMrx();
void calMrx();
double exAbs(double value);

double V[8][1], A[8][1];
double M[8][8];
double MT[8][8];

int main(void) {
    int i = 0, j;
    FILE *fp;
    POS origin[5];
    POS mv[5];
    char originFile[] = "move.dat";
    char mvFile[] = "original.dat";

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

    calInvMrx();

	j = 0;
	for (i=0; i<8; i++) {
		V[j][0] = mv[i].x;
		j++;
		V[j][0] = mv[i].y;
		j++;
	}

	calMrx();

	printf("---MATRIX---\n");
	for (i=0; i<8; i++) {
		printf("%lf\n", A[i][0]);
	}
	printf("------------\n\n");

    return 0;
}

void calInvMrx() {
    int i, j, k, n, s;
	double max, buf;
	POS maxPos;

    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            if (i == j) {
                MT[i][j] = 1;
            } else {
                MT[i][j] = 0;
            }
        }
    }

    for (i=0; i<8; i++) {
        if (i < 7) {
			max = exAbs(M[i][i]);
			maxPos.x = i;
			maxPos.y = i;
			for (j=i+1; j<8; j++) {
				if (exAbs(M[j][i]) > max) {
					max = exAbs(M[j][i]);
					maxPos.x = j;
					maxPos.y = i;
				}
			}
			if (maxPos.x != i) {
				for (j=i; j<8; j++) {
					buf = M[maxPos.x][j];
					M[maxPos.x][j] = M[i][j];
					M[i][j] = buf;
					buf = MT[maxPos.x][j];
					MT[maxPos.x][j] = MT[i][j];
					MT[i][j] = buf;
				}
			}
        }
		
		buf = M[i][i];
		for (j=0; j<8; j++) {
			M[i][j] /= buf;
		}
		for (j=0; j<8; j++) {
			MT[i][j] /= buf;
		}

		for (j=0; j<8; j++) {
			if (i != j) {
				buf = M[j][i];
				for (k=0; k<8; k++) {
					M[j][k] -= M[i][k] * buf;
				}
				for (k=0; k<8; k++) {
					MT[j][k] -= MT[i][k] * buf;
				}
			}
		}
    }
}

void calMrx() {
	int i, j, k, term;

	for (i=0; i<8; i++) {
		for (j=0; j<8; j++) {
			A[i][j] = MT[i][j] * V[i][j];
		}

		for (i=0; i<8; i++) {
			for (j=0; j<8; j++) {
				term = 0;
				for (k=0; k<8; k++) {
					term = term + MT[i][k] * V[k][j];
				}
				A[i][j] = term;
			}
		}
	}
}

double exAbs(double value) {
	if (value < 0) {
		return -1 * value;
	}

	return value;
}