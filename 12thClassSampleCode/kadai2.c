#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NZ 128
#define NY 128
#define NX 128

int main(void)
{
    int i, j, k;
    FILE *fp;
    char fn[] = "kadai2Img";
    char img[NY][NX];
    float left, right, middle, size, z;
    float trunkBtm, trunkTop, lungBtm, lungTop, liverBtm, liverTop, spineBtm, spineTop, heartBtm, heartTop;

    trunkBtm = 16 - (32 / 2);
    trunkTop = 16 + (32 / 2);
    lungBtm = 16 - (30 / 2);
    lungTop = 16 + (30 / 2);
    liverBtm = 16 + 13 - (6 / 2);
    liverTop = 16 + 13 + (6 / 2);
    spineBtm = 16 - (32 / 2);
    spineTop = 16 + (32 / 2);
    heartBtm = 16 + 5 - (10 / 2);
    heartTop = 16 + 5 + (10 / 2);

    size = 0.25;

    fp = fopen(fn, "wb");
    if (fp == NULL)
    {
        printf("File open error \n");
        exit(1);
    }

    for (k = 0; k < NZ; k++)
    {
        z = k * 0.25;

        // Initialize
        for (i = 0; i < NY; i++)
        {
            for (j = 0; j < NX; j++)
            {
                img[i][j] = 0;
            }
        }

        // Trunk
        if (trunkBtm <= z && trunkTop > z)
        {
            for (i = 0; i < NY; i++)
            {
                for (j = 0; j < NX; j++)
                {
                    left = pow(j - 64, 2) / pow((28 / size) / 2, 2);
                    right = pow(i - 64, 2) / pow((20 / size) / 2, 2);
                    if (left + right <= 1.0)
                    {
                        img[i][j] = 120;
                    }
                }
            }
        }

        // Left lung
        if (lungBtm <= z && lungTop > z)
        {
            for (i = 0; i < NY; i++)
            {
                for (j = 0; j < NX; j++)
                {
                    left = pow(j - 40, 2) / pow((10 / size) / 2, 2);
                    right = pow(i - 64, 2) / pow((12 / size) / 2, 2);
                    if (left + right <= 1.0)
                    {
                        img[i][j] = 0;
                    }
                }
            }
        }

        // right lung
        if (lungBtm <= z && lungTop > z)
        {
            for (i = 0; i < NY; i++)
            {
                for (j = 0; j < NX; j++)
                {
                    left = pow(j - 88, 2) / pow((10 / size) / 2, 2);
                    right = pow(i - 64, 2) / pow((12 / size) / 2, 2);
                    if (left + right <= 1.0)
                    {
                        img[i][j] = 0;
                    }
                }
            }
        }

        // Liver
        if (liverBtm <= z && liverTop > z)
        {
            for (i = 0; i < NY; i++)
            {
                for (j = 0; j < NX; j++)
                {
                    left = pow(j - 64, 2) / pow((20 / size) / 2, 2);
                    right = pow(i - 64, 2) / pow((12 / size) / 2, 2);
                    if (left + right <= 1.0)
                    {
                        img[i][j] = 120;
                    }
                }
            }
        }

        // Spine
        if (spineBtm <= z && spineTop > z)
        {
            for (i = 0; i < NY; i++)
            {
                for (j = 0; j < NX; j++)
                {
                    left = pow(j - 64, 2) / pow((4 / size) / 2, 2);
                    right = pow(i - 38, 2) / pow((4 / size) / 2, 2);
                    if (left + right <= 1.0)
                    {
                        img[i][j] = 240;
                    }
                }
            }
        }

        // Heart
        if (heartBtm <= z && heartTop > z)
        {
            for (i = 0; i < NY; i++)
            {
                for (j = 0; j < NX; j++)
                {
                    left = pow(j - 64, 2) / pow((8.5 / size) / 2, 2);
                    right = pow(i - 64, 2) / pow((8.5 / size) / 2, 2);
                    if (left + right <= 1.0)
                    {
                        img[i][j] = 120;
                    }
                }
            }
        }

        // Tumor
        for (i = 0; i < NY; i++)
        {
            for (j = 0; j < NX; j++)
            {
                left = pow(j - 92, 2);
                middle = pow(i - 64, 2);
                right = pow(k - 48, 2);
                if (left + middle + right <= 36.0)
                {
                    img[i][j] = 240;
                }
            }
        }

        // File write
        for (i = 0; i < NY; i++)
        {
            fwrite(img[i], NX, sizeof(char), fp);
        }
    }

    fclose(fp);

    return 0;
}