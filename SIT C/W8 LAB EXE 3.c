#include <stdio.h>
#include <stdlib.h>

int main()
{
    double weight, height, bmi;


    printf("Enter your weight in kilograms: ");
    scanf("%lf", &weight);
    printf("Enter your height in metres: ");
    scanf("%lf", &height);

    bmi = (weight) / (height * height);


    if (bmi < 18.5) {
        printf("Your BMI is %.1f. That is within the underweight range.\n", bmi);
    } else if (bmi >= 18.5 && bmi < 24.9) {
        printf("Your BMI is %.1f. That is within the normal range.\n", bmi);
    } else if (bmi >= 25.0 && bmi < 29.9) {
        printf("Your BMI is %.1f. That is within the overweight range.\n", bmi);
    } else {
        printf("Your BMI is %.1f. That is within the obese range.\n", bmi);
    }
    return 0;
}
