#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NY 128
#define NX 128

int main(void) {
    int i, j;
    double left, right;
    FILE *fp;
    char fn[] = "kadai2Img";
    char img[NY][NX];
    float size;

    size = 0.25;

    for (i=0; i<NY; i++) {
        for (j=0; j<NX; j++) {
            img[i][j] = '0';
        }
    }

    for (i=0; i<NY; i++) {
        for (j=0; j<NX; j++) {
            left  = pow(j-64, 2) / pow(28/size, 2);
            right = pow(i-64, 2) / pow(20/size, 2);
            printf("%lf : %lf\n", left, right);
            if (left + right <= 1.0) {
                img[i][j] = '120';
            }
        }
    }

    fp = fopen(fn, "wb");
    if (fp == NULL) {
        printf("File open error \n");
        exit(1);
    }

    for (i=0; i<NY; i++) {
        fwrite(img[i], NX, sizeof(char), fp);
    }

    fclose(fp);

    return 0;
}
