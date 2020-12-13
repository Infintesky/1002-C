#include <stdio.h>
#include <stdlib.h>

struct grade_node
{
    char surname[20];
    double grade;
    struct grade_node *link;
};

typedef struct grade_node GRADE_NODE;
typedef GRADE_NODE *GRADE_NODE_PTR;

void print_data(GRADE_NODE *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    GRADE_NODE *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%s\n", ptr->surname);
        printf("%.1f\n", ptr->grade);
        ptr = ptr->link;
    }
}

int main()
{
    // 1

    GRADE_NODE_PTR head;

    // 2

    head = NULL;
    //address of head will be stored in head ptr
    head = (GRADE_NODE_PTR)malloc(sizeof(GRADE_NODE));
    strcpy(head->surname, "Adams");
    head->grade = 85.0;
    head->link = NULL;
    // printf("surname: %s \ngrade: %.1f \n", head->surname, head->grade);

    // 3
    GRADE_NODE_PTR temp;
    temp = (GRADE_NODE_PTR)malloc(sizeof(GRADE_NODE));
    strcpy(temp->surname, "Pritchard");
    temp->grade = 66.5;
    temp->link = NULL;
    head->link = temp;

    // 4
    GRADE_NODE_PTR ptr2 = (GRADE_NODE_PTR)malloc(sizeof(GRADE_NODE));
    strcpy(ptr2->surname, "Jones");
    ptr2->grade = 91.5;
    ptr2->link = temp;
    head->link = ptr2;

    // Print the content of the linked list
    print_data(head);
    free(head);
    free(temp);
    free(ptr2);

    return 0;
}
