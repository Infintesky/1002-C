#include <stdio.h>
#include <stdlib.h>

int main()
{
    //*zPtr will reference array z
    int *zPtr;
    int *aPtr = NULL;
    void *sPtr = NULL;
    int number, i;
    int z[5] = {1, 2, 3, 4, 5};
    zPtr = z;
    sPtr = z;

    /* use a pointer to get the first value of array */
    number = zPtr[0];
    printf("%d\n", number);

    /* assign array element 2(the value 3) to number */
    printf("%d\n", *(zPtr + 2));

    /*print the entire array z*/
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", *(zPtr + i));
    }

    return 0;
}
