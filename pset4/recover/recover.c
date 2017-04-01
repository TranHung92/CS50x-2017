#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cs50.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    // open input file
    FILE* inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Could not open 'card.raw'.\n");
        return 2;
    }
    
    unsigned char buffer[512];
    
    int count = 0;
    
    int isJpeg = 0;
    
    // open output file
    FILE* outptr = NULL;
    while (fread(buffer, 512, 1, inptr) == 1){
        // check if the file is jpeg
        if (buffer[0] == 0xff 
        && buffer[1] == 0xd8
        && buffer[2] == 0xff
        && (buffer[3] & 0xe0) == 0xe0)
        {
            if(isJpeg == 1)
            {
                fclose(outptr);
            }
            else
            {
                isJpeg = 1;
            }
            
            // make new JPEG
            char fileName[8];
            sprintf(fileName, "%03d.jpg", count);
            outptr = fopen(fileName, "w");
            count++;
        }
        if(isJpeg == 1)
        {
            fwrite(&buffer, 512, 1, outptr);
        }
        
    }
    
    fclose(outptr);
    
    fclose(inptr);
    
    return 0;
}