// Write a C program to implement the following functions for single linked list. createList, deleteFromFirst, deleteFromLast, deleteFromAny, displayList

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

// create list
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

// delete an element at the first

void deleteAtFirst()
{
    node *d, *temp;
    temp = d = head;
    if (head == NULL)
    {
        printf("Already the Linkedlist is Empty!!!\n");
        return;
    }

    temp = head->next;
    free(d);
    head = temp;
    count--;
    if (head == NULL)
    {
        tail = NULL;
    }
    printf("First node delete successfully!!\n");
}

// delete an element at Last

void deleteAtLast()
{
    node *temp;
    temp = head;
    if (tail == NULL)
    {
        printf("Already the Linkedlist is Empty!!!\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        tail = NULL;
        count--;
        printf("Last node delete successfully!!\n");
        return;
    }

    while (temp->next != tail)
    {
        temp = temp->next;
    }
    free(tail);
    tail = temp;
    count--;
    tail->next = NULL;

    printf("Last node delete successfully!!\n");
}

// delete an element at any position
void deleteAtAny(int pos)
{
    if (pos < 1 || pos > count)
    {
        printf("deletion is failed because %d is not a valid position!!!\n", pos);
        return;
    }
    if (pos == 1)
    {
        deleteAtFirst();
        printf("delete at %d is done successfully!!\n", pos);
        return;
    }
    if (pos == count)
    {
        deleteAtLast();
        printf("delete at %d is done successfully!!\n", pos);
        return;
    }

    node *d, *h;
    d = h = head;
    int i = 1;
    int j = i;
    while (i < pos)
    {
        d = d->next;
        i++;
    }
    while (j < i)
    {
        h = h->next;
        j++;
    }
    h->next = d->next;
    free(d);
    count--;
    printf("delete at %d is done successfully!!\n", pos);
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
        printf("\n --MAIN MENU--\n");
        printf("1. Create a Linkedlist:\n");
        printf("2. delete a Node at First: \n");
        printf("3. delete a Node at Last: \n");
        printf("4. delete a Node at any Position: \n");
        printf("5. Display of the Linkedlist: \n");
        printf("6. Exit: \n");
        int ops;
        printf("press 1 to 6: ");
        scanf("%d", &ops);
        switch (ops)
        {
        case 1:
        {
            int n;
            printf("How many nodes do you want to create: ");
            scanf("%d", &n);
            createlist(n);
            break;
        }
        case 2:
        {
            deleteAtFirst();
            break;
        }
        case 3:
        {
            deleteAtLast();
            break;
        }
        case 4:
        {
            int pos;
            printf("enter position to delete the node: \n");
            scanf("%d",&pos);
            deleteAtAny(pos);
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


