#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = -1, b = 2;
    float x = 0.1;
    float y = 1.5;
    char c = 'p';

    printf("Part a\n");
    printf("%d\n", a/b);
    printf("%d\n", a*b);
    printf("%d\n", (b*3)%4);
    printf("%f\n", x*a);
    printf("%f\n", x*y);
    printf("%f\n", y/x);
    printf("%c\n", c-3);


    printf("Part b\n");
    printf("%4d\n", a);
    printf("%04d\n", b);
    printf("a/b = %d\n", a / b);
    printf("%x\n", b);
    printf("%.2f\n", y);
    printf("%10.1f\n", x);
    printf("c =\t%c\n", c);

    return 0;
}
