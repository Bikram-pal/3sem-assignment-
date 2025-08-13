// Write a C program to merge two already sorted list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head1 = NULL;
node *tail1 = NULL;

node *head2 = NULL;
node *tail2 = NULL;

node *head = NULL;
node *tail = NULL;

void createList1(int n1)
{
    int data, count1 = 0;
    for (int i = 0; i < n1; i++)
    {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &data);
        node *nw = (node *)malloc(sizeof(node));
        nw->data = data;
        nw->next = NULL;
        if (head1 == NULL)
        {
            tail1 = head1 = nw;
        }
        else
        {
            tail1->next = nw;
            tail1 = nw;
        }
        count1++;
    }
}

void createList2(int n2)
{
    int data, count2 = 0;
    for (int i = 0; i < n2; i++)
    {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &data);
        node *nw = (node *)malloc(sizeof(node));
        nw->data = data;
        nw->next = NULL;
        if (head2 == NULL)
        {
            tail2 = head2 = nw;
        }
        else
        {
            tail2->next = nw;
            tail2 = nw;
        }
        count2++;
    }
}
void sort()
{
    if (head == NULL)
        {
            printf("Empty list!!\n");
            return;

        }

    for (node *i = head; i != NULL; i = i->next)
    {
        for (node *j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                int temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
        }
    }
    printf("successfully murged two linkedlist and also sorted!!!\n");
}

void murgeLinked()
{
    if (head1 == NULL && head2 != NULL)
    {
        head = head2;
        tail = tail2;
        return;
    }
    if (head1 != NULL && head2 == NULL)
    {
        tail1->next = NULL;
        head = head1;
        tail = tail1;
        return;
    }
    tail1->next = head2;
    head = head1;
    tail = tail2;
    sort();
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
        printf("1. create 1st List: \n");
        printf("2. create 2st List: \n");
        printf("3. murgeList: \n");
        printf("4. display: \n");
        printf("5. exit:\n");

        int ops;
        printf("press 1-5: ");
        scanf("%d",&ops);

        switch (ops)
        {
            case 1:
            {
                int n;
                printf("How many element if you want: ");
                scanf("%d",&n);
                createList1(n);
                break;
            }
            case 2:
            {
                int n;
                printf("How many element if you want: ");
                scanf("%d",&n);
                createList2(n);
                break;
            }
            case 3:
            {
                murgeLinked();
                break;
            }
            case 4: 
            {
                display();
                break;
            }
            case 5:
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
