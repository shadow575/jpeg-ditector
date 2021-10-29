#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check usage
    if (argc != 2)
    {
        return 1;
    }
    //open file 
    FILE *file = fopen(argv[1],"r");
    if (!file)
    {
        return 1;
    }
    //read first three first
    BYTE bytes[3];
    fread(bytes,sizeof(BYTE),3,file);
    //check for first three bytes 
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        printf("maybe\n");
    }
    else
    {
        printf("No\n");
    }
    //close file.
    fclose(file);
}