// Write a C program to store polynomial using linked list. Store the term in ascending order.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int co;
    int exp;
    struct node *next;

} node;

node *head = NULL;
node *tail = NULL;

// create list

void createList(int n)
{
    for (int i = 0; i < n; i++)
    {
        node *nw;
        int co, exp;
        nw = (node *)malloc(sizeof(node));
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &co, &exp);
        printf("you write %dX^%d \n", co, exp);
        nw->co = co;
        nw->exp = exp;
        nw->next = NULL;

        if (head == NULL)
        {
            head = tail = nw;
        }
        else
        {
            tail->next = nw;
            tail = nw;
        }
    }
}

void display()
{
    node *p;
    p = head;
    if (head == NULL)
    {
        printf("Empty list!!!\n");
        return;
    }
    while (p != NULL)
    {
        printf("%dX^%d + ", p->co, p->exp);
        p = p->next;
    }
    printf("0\n");
}

int main()
{
    while (1)
    {
        printf("\n\t--MIAN MENU--\t\n");
        printf("1. create a list\n");
        printf("2. display of the list\n");
        printf("3. exit\n");

        int ops;
        printf("press 1 to 3: ");
        scanf("%d", &ops);

        switch (ops)
        {
        case 1:
        {
            int numberOfnode;
            printf("How many nodes you create: ");
            scanf("%d", &numberOfnode);

            createList(numberOfnode);
            break;
        }

        case 2:
        {
            display();
            break;
        }

        case 3:
        {
            exit(0);
            break;
        }

        default:
        {
            printf("please enter valid number or digit....");
            break;
        }
        }
    }
    return 0;
}
