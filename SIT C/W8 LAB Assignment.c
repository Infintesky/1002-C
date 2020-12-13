#include <stdio.h>
#include <stdlib.h>
#define COUNT 10
#define LOWERBOUND 1
#define UPPERBOUND 1000

int get_valid_P1_num()
{
    int player1_num;
    printf("Player 1,enter a  number between %d and %d:\n", LOWERBOUND, UPPERBOUND);
    scanf("%d", &player1_num);
    if (player1_num < UPPERBOUND && player1_num > LOWERBOUND)
    {
        return player1_num;
    }
    else
    {
        printf("That number is out of range.\n");
        return get_valid_P1_num();
    }
}

int main()
{
    int count = COUNT;

    int P1_num = get_valid_P1_num();
    int P2_num;

    while (1)
    {
        printf("Player 2, you have %d guesses remaining.\n", count);
        printf("Enter your guess:\n");
        scanf("%d", &P2_num);
        if (count == 0)
        {
            printf("Player 1 wins.\n");
            break;
        }
        else
        {
            if (P2_num > UPPERBOUND || P2_num < LOWERBOUND)
            {
                printf("That number is out of range,\n");
            }
            else if (P2_num < P1_num)
            {
                printf("Too low.\n");
                count--;
            }
            else if (P2_num > P1_num)
            {
                printf("Too high.\n");
                count--;
            }
            else
            {
                printf("Player 2 wins.");
                break;
            }
        }
    }
}
