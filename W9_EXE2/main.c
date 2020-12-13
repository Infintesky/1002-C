#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *a = "abcdef";
    char b[7];
    strcpy(b, a);
    for (int i = 0; i < 3; i++){
        b[i] = b[i] + 1;
    }
    b[3] = '\0';

    printf("%d\n", a[0]);
    printf("%d\n", b[0]);
    printf("%d\n", b[4]);
    printf("%d\n", strlen(a));
    printf("%d\n", strlen(b));
    printf("%d\n", strcmp(a, b));

    return 0;
}
