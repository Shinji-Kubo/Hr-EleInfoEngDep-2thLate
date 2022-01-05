#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NZ 128
#define NY 128
#define NX 128

int main(void) {
    int i, j, k;
    FILE *fp;
    char fn[] = "kadai2Img";
    char img[NY][NX];
    double left, right, size;

    size = 0.25;

    fp = fopen(fn, "wb");
    if (fp == NULL) {
        printf("File open error \n");
        exit(1);
    }

    for (k=0; k<NZ; k++) {
        // Initialize
        for (i=0; i<NY; i++) {
            for (j=0; j<NX; j++) {
                img[i][j] = 0;
            }
        }

        // Trunk
        for (i=0; i<NY; i++) {
            for (j=0; j<NX; j++) {
                left = pow(j-64, 2) / pow((28/size) / 2, 2);
                right = pow(i-64, 2) / pow((20/size) / 2, 2);
                if (left + right <= 1.0) {
                    img[i][j] = 120;
                }
            }
        }

        // File write
        for (i=0; i<NY; i++) {
            fwrite(img[i], NX, sizeof(char), fp);
        }
    }

    fclose(fp);

    return 0;
}
