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
    char fn[] = "kadai2Img";
    char img[NY][NX];
    double size;

    size = 0.25;

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
            left  = ((j-64) * (j-64)) / ((28/size) * (28/size));
            right = ((i-64) * (i-64)) / ((20/size) * (20/size));
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
