// Write a C program to implement the following functions for single linked list. -createlist, insertatfirst, insertatlast, insertatanyposition, displaylist
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

// insert at first

void insertAtFirst()
{
    int data;
    printf("Enter element for insertion at the first: ");
    scanf("%d", &data);

    node *nw;
    nw = (node *)malloc(sizeof(node));
    nw->data = data;
    nw->next = NULL;

    if (head == NULL)
    {
        tail = head = nw;
    }
    else
    {
        nw->next = head;
        head = nw;
    }
    count++;
}

// insert at last
void insertAtLast()
{
    int data;
    printf("Enter element for insertion at the last: ");
    scanf("%d", &data);

    node *nw;
    nw = (node *)malloc(sizeof(node));
    nw->data = data;
    nw->next = NULL;

    if (head == NULL)
    {
        tail = head = nw;
    }
    else
    {
        tail->next = nw;
        tail = nw;
    }
    count++;
}

void insertAtAny()
{
    int data, pos;
    printf("Enter element for insertion at any position: ");
    scanf("%d", &data);
    printf("Enter the position if you add the element: ");
    scanf("%d", &pos);

    node *nw, *temp;
    nw = (node *)malloc(sizeof(node));
    nw->data = data;
    nw->next = NULL;
    temp = head;


    if(pos<1||pos>count+1)
    {
        printf("Not valid!!!");
        return;
    }
    if (pos == 1)
    {
        insertAtFirst();
        return;
    }
    if (pos == count + 1)
    {
        insertAtLast();
    }

    int i = 1;
    while (i < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    nw->next = temp->next;
    temp->next = nw;
    count++;
}

// display the linkedlist
void display()
{
    node *p;
    if (head == NULL)
    {
        printf("Invalid Linkedlist!...\n");
        return;
    }
    else
    {
        p = head;
        printf("\nTHE LINKEDLIST IS: \n");
        while (p != NULL)
        {
            printf("%d -> ", p->data);
            p = p->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    while (1)
    {
        printf("\n --MAIN MANU--\n");
        printf("1. Create a Linkedlist:\n");
        printf("2. Insert a Node at First: \n");
        printf("3. Insert a Node at Last: \n");
        printf("4. Insert a Node at any Position: \n");
        printf("5. Display of the Linkedlist: \n");
        printf("6. Exist: \n");
        int ops;
        printf("press 1 to 6: ");
        scanf("%d", &ops);
        switch (ops)
        {
        case 1:
        {
            int n;
            printf("how many node if you create: ");
            scanf("%d", &n);
            createlist(n);
            break;
        }
        case 2:
        {
            insertAtFirst();
            break;
        }
        case 3:
        {
            insertAtLast();
            break;
        }
        case 4:
        {
            insertAtAny();
            break;
        }
        case 5:
        {
            display();
            break;
        }
        case 6:
        {
            exit(0);
            break;
        }
        default:
        {
            printf("Enter valid number ):");
            break;
        }
        }
    }
}
