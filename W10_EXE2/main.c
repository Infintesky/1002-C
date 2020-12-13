#include <stdio.h>
#include <stdlib.h>

int main()
{
    long value1 = 200000;
    long value2;
    //a
    long *lptr;
    //b
    lptr = &value1;
    //c
    printf("%d\n", *lptr);
    //d when using without * is address with * is value
    value2 = *lptr;
    //e
    printf("%d\n", value2);
    //f
    printf("%p\n", &value1);
    //g
    printf("%p\n", lptr);

    return 0;
}
