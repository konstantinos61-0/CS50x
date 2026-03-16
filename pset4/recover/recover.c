#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// nickname BYTE
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // check for correct usage
    if (argc != 2)
    {
        printf("Correct Usage: ./recover forensic_image_filename\n");
        return 1;
    }
    // open input file of raw memory
    FILE *inpt_f = fopen(argv[1], "rb");
    if (inpt_f == NULL)
    {
        printf("Forensic image cannon be opened for reading\n");
        return 2;
    }
    // 512 B buffer
    BYTE jpgbuff[512];
    // count for the number of jpegs found
    int count = 0;
    int flag = 0;
    // loop through the raw data file
    while (1)
    {
        if (flag == 0)
        {
            if (fread(jpgbuff, sizeof(jpgbuff), 1, inpt_f) == 0)
            {
                fclose(inpt_f);
                printf("Couldnt' read from input file\n");
                return 3;
            }
        }
        // jpeg signature found
        if (jpgbuff[0] == 0xff && jpgbuff[1] == 0xd8 && jpgbuff[2] == 0xff &&
            (jpgbuff[3] & 0xf0) == 0xe0)
        {
            flag = 1;
            // create the ###.jpeg output file
            char filename[8];
            sprintf(filename, "%03i.jpg", count);
            FILE *outpt_f = fopen(filename, "wb");
            if (outpt_f == NULL)
            {
                fclose(inpt_f);
                printf("Could not create output file\n");
                return 4;
            }
            int new_jpeg_detected = 0;
            // write the jpeg data into the outpt_f
            fwrite(jpgbuff, sizeof(jpgbuff), 1, outpt_f);
            while (fread(jpgbuff, sizeof(jpgbuff), 1, inpt_f) != 0)
            {
                int c = jpgbuff[0] == 0xff && jpgbuff[1] == 0xd8 && jpgbuff[2] == 0xff &&
                        (jpgbuff[3] & 0xf0) == 0xe0;
                if (c == 0)
                {
                    fwrite(jpgbuff, sizeof(jpgbuff), 1, outpt_f);
                }
                else
                {
                    new_jpeg_detected = 1;
                    fclose(outpt_f);
                    break;
                }
            }
            if (new_jpeg_detected == 0)
            {
                fclose(outpt_f);
            }
            // increment count to name your nexdt file
            count++;
        }
        if (feof(inpt_f))
        {
            break;
        }
    }
    fclose(inpt_f);
}
