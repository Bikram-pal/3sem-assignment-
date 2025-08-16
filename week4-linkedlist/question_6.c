// Write a C program to detect a loop in a single linked list.

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
int count = 0;
node *head = NULL;
node *tail = NULL;

void createList(int n)
{
    int data;
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d data: ", i + 1);
        scanf("%d", &data);
        node *nw = (node *)malloc(sizeof(node));
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
}

void circularAtGivenPos(int n)
{
    if (n >= count || n <= 0 || head == NULL)
    {
        printf("Not to impliment!!!\n");
        return;
    }
    int i = 1;
    node *h = head;
    while (i != n)
    {
        h = h->next;
        i++;
    }
    tail->next = h;
}

void detectLoop()
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            printf("Circular loop found!\n");
            return;
        }
    }
    printf("no Circular loop found!\n");
}

int main()
{
    while (1)
    {
        printf("1. create List: \n");
        printf("2. make it circuar a any position: \n");
        printf("3. Detect a circular loop present or not:\n");
        printf("4. exit:\n");

        int ops;
        printf("press 1-4: ");
        scanf("%d", &ops);

        switch (ops)
        {
        case 1:
        {
            int n;
            printf("How many element if you want: ");
            scanf("%d", &n);
            createList(n);
            break;
        }
        case 2:
        {
            int pos;
            printf("Enter a position: ");
            scanf("%d", &pos);
            circularAtGivenPos(pos);
            break;
        }
        case 3:
        {
            detectLoop();
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
        default:
            printf("Enter a valid number: ");
            break;
        }
    }
    return 0;
}