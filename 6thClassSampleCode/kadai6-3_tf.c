#include<stdio.h>

typedef struct {
    int x;
    int y;
} POS;

int calPosX(int x, int y);
int calPosY(int x, int y);

int A[8];

int main(void) {
    int i = 0;
    FILE *fp;
    POS origin[5];
    POS mv[5];
    char filename[] = "calMrxSqu.dat";
    char originFile[] = "move.dat";

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("%s file not open.\n", filename);
    }

    while (fscanf(fp, "%d", &A[i]) != EOF) {
		i++;
		if (i > 8) {
			break;
		}
	}

	fclose(fp);

    i = 0;

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

    for (i=0; i<5; i++) {
        mv[i].x = calPosX(origin[i].x, origin[i].y);
        mv[i].y = calPosY(origin[i].x, origin[i].y);
    }

    for (i=0; i<5; i++) {
        printf("%d %d\n", mv[i].x, mv[i].y);
    }

    return 0;
}

int calPosX(int x, int y) {
    return (A[0]*x + A[1]*y + A[2]) / (A[6]*x + A[7]*y + 1);
}

int calPosY(int x, int y) {
    return (A[3]*x + A[4]*y + A[5]) / (A[6]*x + A[7]*y + 1);
}