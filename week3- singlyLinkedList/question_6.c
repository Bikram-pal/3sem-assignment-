// Write a C program to print the odd number and even number nodes separately from a single linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;
int count = 0;

void createlist(int n)
{
    node *nw;
    int data;

    for (int i = 0; i < n; i++)
    {
        printf("Enter your %d element of the linkedList: ", i + 1);
        scanf("%d", &data);

        nw = (node *)malloc(sizeof(node));
        nw->data = data;
        nw->next = NULL;

        if (head == NULL)
        {
            head = nw;
            tail = nw;
        }
        else
        {
            tail->next = nw;
            tail = nw;
        }
        count++;
    }
}
void display()
{
    node *e,*o;
    e=o = head;
    if (head == NULL)
    {
        printf("Empty list!!!\n");
        return;
    }
    printf("even list print:->\n");
    while (e != NULL)
    {
        if(e->data%2==0)
        {
            printf("%d -> ",e->data);
            e=e->next;
        }
        else
        {
            e=e->next;
        }

    }
    printf("NULL\n");
    printf("odd list print:->\n");
    while (o != NULL)
    {
        if(o->data%2!=0)
        {
            printf("%d -> ",o->data);
            o=o->next;
        }
        else
        {
            o=o->next;
        }

    }
    printf("NULL\n");
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

            createlist(numberOfnode);
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