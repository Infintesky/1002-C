#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[4] = {-1,2,10,7};
    int b[4];
    for (int i = 0; i < 4; i++){
        b[i] = a[3 - i];
    }

    printf("%d\n", a[3]);
    printf("%d\n", b[3]);
    printf("%d\n", b[a[1]]);

    return 0;
}
