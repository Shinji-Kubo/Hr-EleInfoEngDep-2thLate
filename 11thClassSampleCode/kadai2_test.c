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
    char img[NY][NX];
    float size;
    float a, b;

    size = 0.25;

    fp = fopen(fn, "wb");
    if (fp == NULL) {
        printf("File open error\n");
        exit(1);
    }

    // Initialize
    for (j=0; j<NY; j++) {
        for (k=0; k<NX; k++) {
            img[j][k] = '0';
        }
    }

    // Trunk
    if (i >= 0 && i < 30/size) {
        for (j=0; j<NY; j++) {
            for (k=0; k<NX; k++) {
                a = 28 / size;
                b = 20 / size;
                left = pow(k-64, 2) / pow(a, 2);
                right = pow(j-64, 2) / pow(b, 2);
                if (left + right <= 1.0) {
                    img[j][k] = '120';
                }
            }
        }
    }

    // File write
    for (j=0; j<NY; j++) {
        fwrite(img[j], NX, sizeof(char), fp);
    }


    fclose(fp);

    return 0;
}
