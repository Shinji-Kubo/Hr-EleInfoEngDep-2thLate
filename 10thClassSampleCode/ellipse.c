#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NY 128
#define NX 128

int main(void)
{
    int r, i, j, x, y;
    double left, right, theata;
    FILE *fp;
    char fn[] = "ellipseImg";
    char img[NY][NX];
    char rotImg[NY][NX];

    r = 32;
    theata = M_PI / 12;

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
            left = pow(j-74, 2) / pow(20, 2);
            right = pow(i-74, 2) / pow(30, 2);
            if (left + right <= 1.0) {
                x = (j * cos(theata)) - (i * sin(theata));
                y = (j * sin(theata)) + (i * cos(theata));
                img[y][x] = '255';
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
