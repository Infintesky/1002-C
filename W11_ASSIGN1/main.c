#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define WORD_LENGTH 32

struct node
{
    char word[WORD_LENGTH];
    struct node *link;
};

struct node *head = NULL;

void insertion(char word[WORD_LENGTH])
{
    struct node *temp = head;
    struct node *prev = NULL;
    struct node *ptr;

    ptr = (struct node *)malloc(sizeof(struct node));
    strcpy(ptr->word, word);
    ptr->link = NULL;

    if (temp == NULL)
    {
        // Executes when linked list is empty
        ptr->link = NULL;
        head = ptr;
        return;
    }

    if (strcmp(word, temp->word) < 0)
    {
        // Executes if given word is less than word in first node of linked list
        ptr->link = head;
        head = ptr;
        return;
    }
    else
    {
        while (temp != NULL)
        {
            if (strcmp(word, temp->word) > 0)
            {
                // Traverse to location we want to insert the node + 1 node
                prev = temp;
                temp = temp->link;
                continue;
            }
            else
            {
                // Insert the node
                prev->link = ptr;
                ptr->link = temp;
                return;
            }
        }
        prev->link = ptr;
        //Insert node at last
    }
}

void print_linked_list()
{
    struct node *temp = head;
    printf("All the entered words in order:\n");
    while (temp != NULL)
    {
        printf("%s\n", temp->word);
        temp = temp->link;
    }
}

int main()
{
    int invalid = 0;
    while (!invalid)
    {
        char word[WORD_LENGTH];
        //printf("Enter a word no longer than %d characters:\n", WORD_LENGTH);
        scanf("%s", word);

        if (strcmp(word, "***") == 0)
        {
            print_linked_list();
            return 0;
        }

        // loop to make sure user inputs a valid word
        for (int i = 0; i < strlen(word); i++)
        {

            if (isalpha(word[i]))
            {
                word[i] = tolower(word[i]);
                continue;
            }

            switch (word[i])
            {
            case '\'':
            case '-':
                break;

            default:
                invalid = 1;
                break;
            }

            if (invalid)
            {
                printf("Invalid word\n");
                continue;
            }
        }

        insertion(word);
    }
}
