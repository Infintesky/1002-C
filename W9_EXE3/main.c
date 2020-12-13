#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str1[255];
    char str2[255];

    printf("Enter a sentence, up to 255 characters:\n");
    fgets(str1, sizeof str1, stdin);

    for(int i=0; i<=(strlen(str1));i++){
        if (!ispunct((str1[i])) || str1[i]=='\0') {
            str2[i] = str1[i];
        }
    }

    char * token = strtok(str2, " ");

    while( token != NULL ) {
        printf( "%s %d\n", token, strlen(token) );
        token = strtok(NULL, " ");
    }




    return 0;
}
