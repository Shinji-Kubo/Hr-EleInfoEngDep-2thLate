#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NY 128
#define NX 128

int main(void)
{
    int r, i, j;
    double left, right;
    FILE *fp;
    char fn[] = "twoEllipseImg";
    char img[NY][NX];

    r = 32;

    for (i = 0; i < NY; i++)
    {
        for (j = 0; j < NX; j++)
        {
            img[i][j] = '0';
        }
    }

    for (i = 0; i < NY; i++)
	{
		for (j = 0; j < NX; j++)
		{
            left  = pow(j-64, 2) / pow(56, 2);
            right = pow(i-64, 2) / pow(40, 2);
            if (left + right <= 1.0) {
                img[i][j] = '255';
            }
		}
	}

    fp = fopen(fn, "wb");
	if (fp == NULL)
	{
		printf("File open error \n");
		exit(1);
	}

	for (i = 0; i < NY; i++)
	{
		fwrite(img[i], NX, sizeof(char), fp);
	}

	fclose(fp);

    return 0;
}
