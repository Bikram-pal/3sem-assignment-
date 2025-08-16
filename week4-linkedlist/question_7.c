// Write a C program to perform multiplication of two polynomials using linked list.

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

node *head3 = NULL;
node *tail3 = NULL;

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
void sort(node *head3)
{
    node *h = head3;
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
    node * temp = h;
    while(temp!=NULL && temp->next!=NULL)
    {
        if(temp->exp== temp->next->exp)
        {
            temp->co += temp->next->co;
            node * dup = temp ->next;
            temp->next=temp->next->next;
            free(dup);
        }
        else
        {
            temp=temp->next;
        }
    }
}

void multi()
{
    sort(head1);
    sort(head2);
    node *h1 = head1;
    node *h2 = head2;
    
    if(h1==NULL||h2==NULL)
    {
        printf("multi not possible!!\n");
        return;
    }
    for(node*i=h2;i!=NULL;i=i->next)
    {
        for(node*j=h1;j!=NULL;j=j->next)
        {
            node *newnode = (node *)malloc(sizeof(node));
            newnode->next = NULL;
            newnode->exp = j->exp + i->exp;
            newnode->co = j->co * i->co;
            if(head3==NULL)
            {
                tail3=head3=newnode;
            }
            else
            {
                tail3->next=newnode;
                tail3=newnode;
            }
        }
    }
    
}


void display()
{
    node *p;
    p = head3;
    if (head3 == NULL)
    {
        printf("Empty list!!!\n");
        return;
    }
    while (p != NULL)
    {
        printf("%dX^%d ", p->co,p->exp);
        if(p->next!=NULL)
        {
            printf("+ ");
        }
        p = p->next;
        
    }
    return;
}

int main()
{
    while(1)
    {
        printf("\n1. create 1st polinomial List: \n");
        printf("2. create 2st polinomial List: \n");
        printf("3. multiplication of the two list: \n");
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
                multi();
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

