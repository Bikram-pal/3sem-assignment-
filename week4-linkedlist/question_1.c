// Write a C program to reverse an already created single linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

void CreateList(int n)
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
    }
}

void reverse()
{
    if (head == NULL)
    {
        printf("empty linkedlist..\n");
        return;
    }
    node *prev = NULL, *cur = head, *nextnode = NULL;
    while (cur != NULL)
    {
        nextnode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextnode;
    }
    head = prev;
    printf("Reverse sucessfully!!\n");
    return;
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
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
    return;
}

int main()
{
    while(1)
    {
        int n;
        printf("1. create list: \n");
        printf("2. reverse: \n");
        printf("3. display list: \n");
        printf("4. exit: \n");
        printf("press any: ");
        int ops;
        scanf("%d",&ops);
        switch (ops)
        {
        case 1:
            printf("how many data you store: ");
            scanf("%d",&n);
            CreateList(n);
            break;
        case 2:
        {
            reverse();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
        default:
            break;
        }
    }
}