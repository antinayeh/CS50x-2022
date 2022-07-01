#include "helpers.h"
#include "math.h"
#include "ctype.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int red;
    int green;
    int blue;
    int grey;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = image[i][j].rgbtRed;
            green = image[i][j].rgbtGreen;
            blue = image[i][j].rgbtBlue;
            grey = round((red + green + blue)/3.0);
            image[i][j].rgbtRed = grey;
            image[i][j].rgbtGreen = grey;
            image[i][j].rgbtBlue = grey;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int red;
    int green;
    int blue;
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;
    int colors[3];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = image[i][j].rgbtRed;
            green = image[i][j].rgbtGreen;
            blue = image[i][j].rgbtBlue;
            sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            sepiaBlue = round(.272 * red + .534 * green + .131 * blue);
            colors[0] = sepiaRed;
            colors[1] = sepiaGreen;
            colors[2] = sepiaBlue;
            for (int x = 0; x < 3; x++)
            {
                if (colors[x] > 255)
                {
                    colors[x] = 255;
                }
            }
            image[i][j].rgbtRed = colors[0];
            image[i][j].rgbtGreen = colors[1];
            image[i][j].rgbtBlue = colors[2];
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    int w;
    int range;
    if (width%2 != 0)
    {
        range = round(width/2.0)-1;
    }
    else
    {
        range = width/2;
    }
     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < range; j++)
        {
            w = width - j - 1;
            temp = image[i][w];
            image[i][w] = image[i][j];
            image[i][j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE pixels[9];
    RGBTRIPLE copy[height][width];


    for (int i = 1; i <height; i++)
    {
        for (int j = 1; j < width; j++)
        {
            pixels[0] = image[i][j];
            pixels[1] = image[i][j+1];
            pixels[2] = image[i][j-1];
            pixels[3] = image[i+1][j];
            pixels[4] = image[i+1][j+1];
            pixels[5] = image[i+1][j-1];
            pixels[6] = image[i-1][j];
            pixels[7] = image[i-1][j+1];
            pixels[8] = image[i-1][j-1];

            int avgred = 0;
            int avgblue = 0;
            int avggreen = 0;
            double count = 0.0;
            for (int x = 0; x < sizeof(pixels); x++)
            {
                avgred += pixels[x].rgbtRed;
                avgblue += pixels[x].rgbtBlue;
                avggreen += pixels[x].rgbtGreen;
                count ++;
            }
            copy[i][j].rgbtRed = round(avgred/count);
            copy[i][j].rgbtBlue = round(avgblue/count);
            copy[i][j].rgbtGreen = round(avggreen/count);
        }
    }

    for (int y = 0; y < height; y++)
    {
        for (int z = 0; z < width; z++)
        {
            image[y][z] = copy[y][z];
        }
    }
    return;
}
