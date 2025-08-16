// Given a singly linked list of size N. The task is to swap elements in the linked list pairwise. For example, if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

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
    }
}

void swap()
{
    node *h;
    h = head;
    while (h != NULL && h->next != NULL)
    {
        int temp;
        temp = h->data;
        h->data = h->next->data;
        h->next->data = temp;
        h = h->next->next;
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
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
    return;
}

int main()
{
    while (1)
    {
        printf("1. create List: \n");
        printf("2. swap: \n");
        printf("3. display: \n");
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
            swap();
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
    return 0;
}
