// Write a C function to count the number of node present in a linked list.

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

int createlist(int n)
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
    return count;
}

int main()
{
    int n;
    printf("How may element you create: ");
    scanf("%d",&n);
    int ans=createlist(n);
    printf("count is: %d",ans);
    return 0;
}

