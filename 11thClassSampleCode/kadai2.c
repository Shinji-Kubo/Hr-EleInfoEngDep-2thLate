#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NZ 128
#define NY 128
#define NX 128

int main(void) {
    int i, j, k;
    double left, right;
    FILE *fp;
    char fn[] = "kadai2Img";
    int img[NY][NX];
    float size;

    size = 0.25;

    fp = fopen(fn, "wb");
    if (fp == NULL) {
        printf("File open error\n");
        exit(1);
    }

    for (i=0; i<NZ; i++) {
        // Initialize
        for (j=0; j<NY; j++) {
            for (k=0; k<NX; k++) {
                img[j][k] = 0;
            }
        }

        // Trunk
        if (i >= 0 && i < 30/size) {
            for (j=0; j<NY; j++) {
                for (k=0; k<NX; k++) {
                    left = pow(k-64, 2) / pow(28/size, 2);
                    right = pow(j-64, 2) / pow(20/size, 2);
                    if (left + right <= 1.0) {
                        img[j][k] = 120;
                    }
                }
            }
        }

        // File write
        for (j=0; j<NY; j++) {
            fwrite(img[j], NX, sizeof(int), fp);
        }

    }

    fclose(fp);

    return 0;
}
