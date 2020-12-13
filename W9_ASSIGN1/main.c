#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int match(char text[], char pattern[])
{

    int text_length = strlen(text);
    int pattern_length = strlen(pattern);


    if (text_length < pattern_length)
    {
        return -1;
    }


    for (int i = 0; i <= text_length - pattern_length; i++)
    {
        int j;

        for (j = 0; j < pattern_length; j++)
        {
            if (pattern[j] == '.' || (pattern[j] == '_' && text[j + i] == ' '))
            {
                continue;
            }
            if (pattern[j] != text[j + i] || (pattern[j] == '_' && text[j + i] != ' '))
            {
                break;
            }
        }

        // j== pattern_length - 1 for partial strings in a word like 'at' or 't' in 'cat'
        // j== pattern_length for full strings like 'cat' in 'cat'
        if (j == pattern_length || j == pattern_length - 1)
        {

            return i;
        }
    }
    return -1;
}

int main()
{
    char mainstring[255], substring[255], caseSensitive, lowered_string;
    int result;

    printf("Enter a line of text, up to 255 characters:\n");
    fgets(mainstring, sizeof mainstring, stdin);

    printf("Enter a pattern, up to 255 characters:\n");
    fgets(substring, sizeof substring, stdin);

    printf("Case sensitive?:\n");
    scanf("%c", &caseSensitive);

    if (caseSensitive == 'Y')
    {
        if (match(mainstring, substring) == -1)
        {
            printf("No match.");
        }
        else
        {
            printf("Matches at position %d", match(mainstring, substring));
        }
    }

    else if (caseSensitive == 'N')
    {
        for (int i = 0; i <= strlen(mainstring); i++)
        {
            if (mainstring[i] >= 'A' && mainstring[i] <= 'Z')
            {
                mainstring[i] = mainstring[i] + 32;
            }
        }

        if (match(mainstring, substring) == -1)
        {
            printf("No match.");
        }
        else
        {
            printf("Matches at position %d", match(mainstring, substring));
        }
    }

    return 0;
}
