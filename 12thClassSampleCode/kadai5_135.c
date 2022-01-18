#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NZ 128
#define NY 128
#define NX 128

int main(void)
{
    int i, j, k, x, y, x1, y1;
    FILE *fp;
    char fn[] = "kadai5Img135";
    float img[NY][NX];
    float img_rot[NY][NX];
    float proj_att[NX];
    float bone_att_tis_pix, att_tis_pix, size, left, right, middle, z;
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

    bone_att_tis_pix = 0.4242 * 1.92 * size;
    att_tis_pix = 0.2264 * 1.06 * size;

    fp = fopen(fn, "wb");
    if (fp == NULL)
    {
        printf("File open error \n");
        exit(1);
    }

    for (k = NZ; k > 0; k--)
    {
        z = k * size;

        // Initialize
        for (i = 0; i < NY; i++)
        {
            for (j = 0; j < NX; j++)
            {
                img[i][j] = 0.0;
                img_rot[i][j] = 0.0;
            }
            proj_att[i] = 0.0;
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
                        img[i][j] = att_tis_pix;
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
                        img[i][j] = 0.0;
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
                        img[i][j] = 0.0;
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
                        img[i][j] = bone_att_tis_pix;
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
                        img[i][j] = att_tis_pix;
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
                        img[i][j] = att_tis_pix;
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
                    img[i][j] = bone_att_tis_pix;
                }
            }
        }

        for (i = 0; i < NY; i++)
        {
            for (j = 0; j < NX; j++)
            {
                x1 = i - 64;
                y1 = j - 64;
                x = y1 * cos((180 / M_PI) * 135) - x1 * sin((180 / M_PI) * 135);
                y = y1 * sin((180 / M_PI) * 135) + x1 * cos((180 / M_PI) * 135);
                if (y + 64 < 128 && x + 64 < 128) {
                    img_rot[y+64][x+64] = img[i][j];
                }
            }
        }

        // File write
        for (i = 0; i < NX; i++)
        {
            for (j = 0; j < NY; j++)
            {
                proj_att[i] += img_rot[j][i];
            }
        }

        fwrite(proj_att, NX, sizeof(float), fp);
    }

    fclose(fp);

    return 0;
}