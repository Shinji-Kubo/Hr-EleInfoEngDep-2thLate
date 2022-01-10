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
    unsigned char img[NY][NX];
    double left, right, size;

    size = 0.25;

    fp = fopen(fn, "wb");
    if (fp == NULL)
    {
        printf("File open error \n");
        exit(1);
    }

    for (k = 0; k < NZ; k++)
    {
        // Initialize
        for (i = 0; i < NY; i++)
        {
            for (j = 0; j < NX; j++)
            {
                img[i][j] = 0;
            }
        }

        // Trunk
        if (0 <= k && 32 / size > k)
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
        if (0 <= k && 30 / size > k)
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

        // Left lung
        if (0 <= k && 30 / size > k)
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
        if (116 <= k && (6 / size) + 116 > k)
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
        if (0 <= k && (32 / size) > k)
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
        if (44 <= k && (10 / size) + 44 > k)
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

        // File write
        for (i = 0; i < NY; i++)
        {
            fwrite(img[i], NX, sizeof(unsigned char), fp);
        }
    }

    fclose(fp);

    return 0;
}
