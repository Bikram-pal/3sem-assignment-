// Given a singly linked list of size N. The task is to left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;

} node;
node *head = NULL;
node *tail = NULL;
int count = 0;

void createList(int n)
{
    int data;
    count = 0;
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element of the linked list: ", i + 1);
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
void sift(int k)
{
    node *kprv;
    kprv = head;
    for (int i = 0; i < k - 1; i++)
    {
        kprv = kprv->next;
    }
    node *newnode = kprv->next;
    kprv->next = NULL;
    tail->next = head;
    tail = kprv;
    head = newnode;
}

void kNode()
{
    int k;
    printf("Enter K node: ");
    scanf("%d", &k);
    if (k <= 0 || k >= count)
    {
        printf("Not possible!!!\n");
        return;
    }
    if (k == count - 1)
        return;
    if (k < count)
    {
        sift(k);
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
    while(1)
    {
        printf("1. create List: \n");
        printf("2. k node: \n");
        printf("3. display: \n");
        printf("4. exit:\n");

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
                createList(n);
                break;
            }
            case 2:
            {
                kNode();
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
