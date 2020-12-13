#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMSIZ 100

struct header
{
    char name[NAMSIZ];
    char size[12];
};

typedef struct header HEADER;
typedef HEADER *HEADER_PTR;

int main(int argc, char **argv)
{
    int s_header = sizeof(HEADER);
    FILE *archive;
    archive = fopen("a.out", "w");
    for (int i = 1; i < argc; i++)
    {
        char *filename = argv[i];
        FILE *fptr;
        fptr = fopen(filename, "r");
        if (fptr == NULL)
        {
            printf("Error opening file\n");
        }
        HEADER_PTR FILE_HEAD = malloc(s_header);
        memset(FILE_HEAD->name, 0, NAMSIZ * sizeof(char));
        memset(FILE_HEAD->size, 0, 12 * sizeof(char));
        snprintf(FILE_HEAD->name, NAMSIZ, "%s", filename);
        fseek(fptr, 0, SEEK_END);
        sprintf(FILE_HEAD->size, "%ld", ftell(fptr));
        fwrite(FILE_HEAD, s_header, 1, archive);

        fseek(fptr, 0, SEEK_SET);
        while (!feof(fptr))
        {
            char c = fgetc(fptr);
            if (c != EOF)
            {
                fputc(c, archive);
            }
        }

        fclose(fptr);
    }
    fclose(archive);
    return 0;
}
