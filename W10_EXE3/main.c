#include <stdio.h>
#include <stdlib.h>

typedef struct INTL_MONEY_VALUE
{
    float value;
    char currency[];
} money;

typedef money *INTL_MONEY_VALUE_PTR;

int main()
{
    money sgd;
    sgd.value = 59.99;
    // sgd.currency = {"S","G","D"};
    INTL_MONEY_VALUE_PTR sgdPTR;
    sgdPTR = &sgd;

    return 0;
}
