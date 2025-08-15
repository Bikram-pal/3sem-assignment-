// Write a C program to perform addition of two polynomials using linked list.
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int co;
    int exp;
    struct node *next;
} node;

node *head1 = NULL;
node *tail1 = NULL;

node *head2 = NULL;
node *tail2 = NULL;

node *head = NULL;
node *tail = NULL;

int count=0;

void createList1(int n)
{
    int co, exp;
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d coefficient of the 1st list: ",i+1);
        scanf("%d", &co);
        printf("Enter %d exponent of the 1st list: ",i+1);
        scanf("%d", &exp);
        node *nw = (node *)malloc(sizeof(node));
        nw->co = co;
        nw->exp = exp;
        nw->next = NULL;

        if (head1 == NULL)
        {
            head1 = nw;
            tail1 = nw;
        }
        else
        {
            tail1->next = nw;
            tail1=nw;
        }
    }
}

void createList2(int n)
{
    int co, exp;
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d coefficient of the 1st list: ",i+1);
        scanf("%d", &co);
        printf("Enter %d exponent of the 1st list: ",i+1);
        scanf("%d", &exp);
        node *nw = (node *)malloc(sizeof(node));
        nw->co = co;
        nw->exp = exp;
        nw->next = NULL;

        if (head2 == NULL)
        {
            head2 = nw;
            tail2 = nw;
        }
        else
        {
            tail2->next = nw;
            tail2=nw;
        }
    }
}
void sort(node *head)
{
    node *h = head;
    if(h==NULL)
    {
        printf("the %d is empty List!!\n",count);
        count++;
        return;
    }
    for (node *i = h; i != NULL; i = i->next)
    {
        for (node *j = i->next; j != NULL; j = j->next)
        {
            int tempe;
            int tempc;
            if (j->exp > i->exp)
            {
                tempe = i->exp;
                i->exp = j->exp;
                j->exp = tempe;

                tempc = i->co;
                i->co = j->co;
                j->co = tempc;
            }
        }
    }
}

void addition()
{
    sort(head1);
    sort(head2);
    node *h1 = head1;
    node *h2 = head2;

    while (h1 != NULL && h2 != NULL)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;

        if (h1->exp == h2->exp)
        {
            newnode->co = h1->co + h2->co;
            newnode->exp = h1->exp;
            h1 = h1->next;
            h2 = h2->next;
        }

        else if (h1->exp > h2->exp)
        {
            newnode->co = h1->co;
            newnode->exp = h1->exp;
            h1 = h1->next;
        }

        else
        {
            newnode->co = h2->co;
            newnode->exp = h2->exp;
            h2 = h2->next;
        }
        if (head == NULL)
        {
            tail = head = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    while (h1 != NULL)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->co = h1->co;
        newnode->exp = h1->exp;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            tail = head;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        h1 = h1->next;
    }

    while (h2 != NULL)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->co = h2->co;
        newnode->exp = h2->exp;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            tail = head;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        h2 = h2->next;
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
        printf("%dX^%d +", p->co,p->exp);
        p = p->next;
    }
    printf("0\n");
    return;
}

int main()
{
    while(1)
    {
        printf("1. create 1st polinomial List: \n");
        printf("2. create 2st polinomial List: \n");
        printf("3. addition of the two list: \n");
        printf("4. display: \n");
        printf("5. exit: \n");

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
                addition();
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

