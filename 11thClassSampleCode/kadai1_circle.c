#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NY 128
#define NX 128

int main(void)
{
    int r, i, j, left, right;
    FILE *fp;
    char fn[] = "circleImg";
    char img[NY][NX];
		float att_tis_pix;
		float att_fac;
		float den;
		float size;

		att_fac = 0.2264;
		den = 1.06;
		size = 0.25;

		att_tis_pix = att_fac * den * size;

    r = 32;

    for (i = 0; i < NY; i++)
    {
        for (j = 0; j < NX; j++)
        {
            img[i][j] = 0;
        }
    }

    for (i = 0; i < NY; i++)
	{
		for (j = 0; j < NX; j++)
		{
            left = pow(i - 64, 2) + pow(j - 64, 2);
            right = pow(r, 2);
			if (left <= right)
			{
				img[i][j] = att_tis_pix;
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
		fwrite(img[i], NX, sizeof(float), fp);
	}

	fclose(fp);

    return 0;
}
