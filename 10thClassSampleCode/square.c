#include <stdio.h>
#include <stdlib.h>
#define NY 128
#define NX 128

int main(void)
{
	int i, j, a, b, c, d;
	FILE *fp;
	char fn[] = "squareImg";
	char img[NY][NX];

	a = 32;
	b = 96;
	c = 32;
	d = 96;

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
			if (j > a && j < b && i > c && i < d)
			{
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
