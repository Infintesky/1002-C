#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int valid_word(char word[])
{
    // function returns -1 if word is not valid and 1 if word is valid
    for (int i = 0; i < (strlen(word)); i++)
    {
        if (isalpha(word[i]) == 0)
        {
            return -1;
        }
    }
    return 1;
}

int main()
{
    // Get word to guess
    char p1_word[12];
    printf("Player 1, enter a word of no more than 12 letters:\n");
    scanf("%s", p1_word);

    // keep looping till player 1 enters a valid word
    while (1)
    {
        if (valid_word(p1_word) < 0)
        {
            printf("Sorry, the word must contain only English letters.\n");
            printf("Player 1, enter a word of no more than 12 letters:\n");
            scanf("%s", p1_word);
        }
        else if (valid_word(p1_word) > 0)
        {
            break;
        }
    }

    //Once player 1 enters a valid word, lower case it all
    for (int i = 0; i <= strlen(p1_word); i++)
    {
        if (p1_word[i] >= 'A' && p1_word[i] <= 'Z')
        {
            p1_word[i] = p1_word[i] + 32;
        }
    }
    // Now we have a valid p1 word

    // mask[i] is true if character has been guessed and false if not guessed yet
    int N = strlen(p1_word);
    int mask[N];
    for (int i = 0; i < N; ++i)
    {
        mask[i] = 0;
    }

    // Loop over each round of guessing
    int gameover = 0;
    int guesses = 7;
    while (!gameover)
    {
        // Print word with '_' for unguessed letters
        printf("Player 2 has so far guessed:");
        for (int j = 0; j < N; ++j)
        {
            if (mask[j])
            {
                printf("%c", p1_word[j]);
            }
            else
            {
                printf(" _");
            }
        }
        printf("\n");

        // Get player 2 next guess
        char guess[1];
        printf("Player 2, you have %d guesses remaining. Enter your next guess:\n", guesses);
        scanf(" %c", guess);

        // once gotten a lower case it
        for (int i = 0; i <= strlen(guess); i++)
        {
            if (guess[i] >= 'A' && guess[i] <= 'Z')
            {
                guess[i] = guess[i] + 32;
            }
        }

        // Mark true all mask positions corresponding to guess
        for (int k = 0; k < N; ++k)
        {
            if (p1_word[k] == guess[0])
            {
                mask[k] = 1;
                break;
            }
            if (k == N - 1)
            {
                guesses--;
            }
        }

        // check if gameover or not
        // Determine whether the player has won!
        if (guesses < 0)
        {
            printf("Gameover player 2 ran out of guesses.Player 1 wins.");
            return 0;
        }
        gameover = 1;
        for (int m = 0; m < N; ++m)
        {
            if (!mask[m])
            {
                gameover = 0;
                break;
            }
        }
    }
    printf("Player 2 has so far guessed: %s\n", p1_word);
    printf("Player 2 wins!");
    return 0;
}