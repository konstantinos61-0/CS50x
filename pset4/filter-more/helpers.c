#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg =
                round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // check if width is even
    if (width % 2 == 0)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width / 2; j++)
            {
                int b = image[i][j].rgbtBlue;
                int r = image[i][j].rgbtRed;
                int g = image[i][j].rgbtGreen;

                image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
                image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
                image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;

                image[i][width - j - 1].rgbtBlue = b;
                image[i][width - j - 1].rgbtRed = r;
                image[i][width - j - 1].rgbtGreen = g;
            }
        }
    }
    // if width odd
    else
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < (width - 1) / 2; j++)
            {
                int b = image[i][j].rgbtBlue;
                int r = image[i][j].rgbtRed;
                int g = image[i][j].rgbtGreen;

                image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
                image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
                image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;

                image[i][width - j - 1].rgbtBlue = b;
                image[i][width - j - 1].rgbtRed = r;
                image[i][width - j - 1].rgbtGreen = g;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create a copy of the image to use so that blured pixels wont affect their neighbour's
    // blurring
    RGBTRIPLE image2[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image2[i][j] = image[i][j];
        }
    }
    // access image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // for each image[i][j] add all the neighbouring pixels' color channels
            int sumb = 0, sumg = 0, sumr = 0, count = 0;
            for (int y = -1; y < 2; y++)
            {
                for (int x = -1; x < 2; x++)
                {
                    int ni = i + y, nj = j + x;
                    // check if neighbour pixel is in fact an image pixel inside the image's
                    // boundaries
                    if (ni > -1 && ni < height && nj > -1 && nj < width)
                    {
                        sumb += image2[ni][nj].rgbtBlue;
                        sumg += image2[ni][nj].rgbtGreen;
                        sumr += image2[ni][nj].rgbtRed;
                        count += 1;
                    }
                }
                // compute the average of all neighbours and assign blurred pixel color values
                image[i][j].rgbtBlue = round(sumb / (float) count);
                image[i][j].rgbtGreen = round(sumg / (float) count);
                image[i][j].rgbtRed = round(sumr / (float) count);
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // create a copy of the image to use so that altered pixels wont affect their neighbour's
    // altering
    RGBTRIPLE image2[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image2[i][j] = image[i][j];
        }
    }
    // create G(x,y) Kernels where gk[0] is gx and gk[1] is gy
    int Gk[2][3][3] = {
    {
        {-1,0,1},
        {-2,0,2},
        {-1,0,1}
    },
    {
        {-1,-2,-1},
        {0,0,0},
        {1,2,1}
    }
    };

    // access each pixel and update its values accordingly to sobel operator
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gxb = 0, gxg = 0, gxr = 0, gyb = 0, gyg = 0, gyr = 0;
            int G[2][3] = {
                {gxb, gxg, gxr},
                {gyb, gyg, gyr}
            };
            // loop through the neighbours of each pixel and add each color's coefficient to
            // the g(x,y) of each color
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int ni = i + x, nj = j + y;
                    // check if neighbour pixel is in fact an image pixel inside the image's
                    // boundaries
                    if (ni > -1 && ni < height && nj > -1 && nj < width)
                    {
                        // loop through each G kernel ( x an y) and update Gx and Gy
                        for (int k = 0; k < 2; k++)
                        {
                            G[k][0] += Gk[k][x + 1][y + 1] * image2[ni][nj].rgbtBlue;
                            G[k][1] += Gk[k][x + 1][y + 1] * image2[ni][nj].rgbtGreen;
                            G[k][2] += Gk[k][x + 1][y + 1] * image2[ni][nj].rgbtRed;
                        }
                    }
                }
            }
            // look through Gk(x,y) and create Gx^2+Gy^2 as temp variables for each color
            float tempb = 0, tempg = 0, tempr = 0;
            for (int k = 0; k < 2; k++)
            {
                tempb += pow(G[k][0], 2);
                tempg += pow(G[k][1], 2);
                tempr += pow(G[k][2], 2);
            }
            tempb = sqrt(tempb);
            tempg = sqrt(tempg);
            tempr = sqrt(tempr);
            if (tempb <= 255)
            {
                image[i][j].rgbtBlue = round(tempb);
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }
            if (tempg <= 255)
            {
                image[i][j].rgbtGreen = round(tempg);
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }
            if (tempr <= 255)
            {
                image[i][j].rgbtRed = round(tempr);
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }
        }
    }
    return;
}
