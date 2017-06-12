/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bmp.h"


//Do float conversion first
int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize decimal-number infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    
    int resValues = atoi(argv[1]);
    //resValues = roundf(resValues * 100) / 100;
    
    if (resValues < 0.0 || resValues > 100) {
        fprintf(stderr, "Please provide a value in the range of (0.0,100,0]\n");
        return 1;
    }
    //float conversion
    
    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, res;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    res = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, resi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    resi = bi; 
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    resi.biWidth = bi.biWidth * resValues;
    resi.biHeight = bi.biHeight * resValues;
    
    
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int new_padding = (4 - (resi.biWidth * sizeof(RGBTRIPLE)) %4) % 4;
    
    resi.biSizeImage = ((sizeof(RGBTRIPLE) * resi.biWidth) + new_padding) * abs(resi.biHeight);
    res.bfSize = resi.biSizeImage + 54;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&res, sizeof(BITMAPFILEHEADER), 1, outptr);
    

    // write outfile's BITMAPINFOHEADER
    fwrite(&resi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {


        RGBTRIPLE newtriple[resi.biWidth + 2];
        int c = 0;
    
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

      
            for (int s = 0; s < resValues; s++)
            {
                newtriple[c] = triple;
                c++;
            }
        }
		    

        for (int t = 0; t < resValues; t++)
        {
            for (int v = 0; v < resi.biWidth; v++)
            {
                fwrite (&newtriple[v], sizeof(RGBTRIPLE), 1, outptr);
		    }
	
            for (int k = 0; k < new_padding; k++)
            {
                fputc(0x00, outptr);
            }
        }
		    
        // skip over padding, if any in infile
        fseek(inptr, padding, SEEK_CUR);

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}