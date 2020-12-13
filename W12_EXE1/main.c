#include <stdio.h>
#include <stdlib.h>
#define NAMSIZ 100

typedef struct header
{
    char name[NAMSIZ];
    char size[12];
} file_header;

char fsize(FILE *fp)
{
    int prev = ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz = ftell(fp);
    fseek(fp, prev, SEEK_SET); //go back to where we were
    char size = sz;
}

int main(int argc, char **argv)
{
    file_header fheader1;
    file_header fheader2;

    strcpy(fheader1.name, "File1.txt");
    strcpy(fheader2.name, "File2.txt");
    // fheader1.name = argv[1];
    // fheader2.name = argv[2];

    // Open two files to be merged
    FILE *fptr1 = fopen(fheader1.name, "r");
    FILE *fptr2 = fopen(fheader2.name, "r");

    strcpy(fheader1.size, fsize(fptr1));
    strcpy(fheader2.size, fsize(fptr2));

    // Open file to store the result
    FILE *fptr3 = fopen("result.tar", "wb");
    char c;

    if (fptr1 == NULL || fptr2 == NULL || fptr3 == NULL)
    {
        puts("Could not open files");
        exit(0);
    }

    // Copy contents of first file to result.tar
    while ((c = fgetc(fptr1)) != EOF)
        fputc(c, fptr3);

    // Copy contents of second file to result.tar
    while ((c = fgetc(fptr2)) != EOF)
        fputc(c, fptr3);

    printf("Merged file1.txt and file2.txt into result.tar");

    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    return 0;
}
