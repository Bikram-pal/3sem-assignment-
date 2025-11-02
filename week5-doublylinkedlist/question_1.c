    // 1. Write a C program to create a Double linked list along with the following functions:
    // a) to display the elements of a Double Linked List.
    // b) to add an element at beginning of a Double linked list.
    // c) to add an element at the end of a Double linked list.
    // d) to add an element at any user given position of a Double linked list.
    // e) to search a user given element in a Double linked list.
    // f) to count the number of nodes in a Double linked list.
    // g) to delete a node at beginning of a Double linked list.
    // h) to delete a node at end of a Double linked list.
    // i) to delete a node from any position of a Double linked list.
    // (Create a menu bar using switch case statement in the main)
    #include <stdio.h>
    #include <stdlib.h>

    typedef struct node
    {
        int data;
        struct node *next;
        struct node *prev;
    } node;

    node *head = NULL;
    node *tail = NULL;
    int count = 0;

    void createList(int n)
    {
        int x;
        for (int i = 0; i < n; i++)
        {
            printf("Enter your %d data: ", i + 1);
            scanf("%d", &x);
            node *nw = (node *)malloc(sizeof(node));
            nw->data = x;
            nw->next = NULL;
            nw->prev = NULL;

            if (head == NULL)
            {
                head = tail = nw;
            }
            else
            {
                tail->next = nw;
                nw->prev = tail;
                tail = nw;
            }
            count++;
        }
    }
    void insertAtFirst(int x)
    {
        if (head == NULL)
        {
            node *nw = (node *)malloc(sizeof(node));
            nw->data = x;
            nw->next = NULL;
            nw->prev = NULL;
            head = tail = nw;
            count++;
            return;
        }
        if (head != NULL)
        {
            node *nw = (node *)malloc(sizeof(node));
            nw->data = x;
            nw->next = NULL;
            nw->prev = NULL;
            nw->next = head;
            head->prev = nw;
            head = nw;
            count++;
            return;
        }
    }

    void insertAtLast(int x)
    {
        if (head == NULL)
        {
            node *nw = (node *)malloc(sizeof(node));
            nw->data = x;
            nw->next = NULL;
            nw->prev = NULL;
            head = tail = nw;
            count++;
            return;
        }
        if (head != NULL)
        {
            node *nw = (node *)malloc(sizeof(node));
            nw->data = x;
            nw->next = NULL;
            nw->prev = NULL;
            tail->next = nw;
            nw->prev = tail;
            tail = nw;
            count++;
            return;
        }
    }

    void insertAtAny(int x, int pos)
    {

        if (pos > count + 1 || pos < 1)
        {
            printf("Execution falied!!\n");
            return;
        }
        if (count + 1 == pos)
        {
            insertAtLast(x);
            return;
        }
        if (pos == 1)
        {
            insertAtFirst(x);
            return;
        }

        node *nw = (node *)malloc(sizeof(node));
        nw->data = x;
        nw->next = NULL;
        nw->prev = NULL;
        node *p;
        p = head;
        for (int i = 1; i < pos - 1; i++)
        {
            p = p->next;
        }
        nw->next = p->next;
        p->next->prev = nw;
        p->next = nw;
        nw->prev = p;
        count++;
        return;
    }

    void search(int s)
    {
        if (head == NULL)
        {
            printf("Empty List!!\n");
            return;
        }
        node *p = head;
        int pos = 1;
        while (p != NULL)
        {
            if (p->data == s)
            {
                printf("found at %d", pos);
                return;
            }
            p = p->next;
            pos++;
        }
        printf("Not found!!\n");
        return;
    }

    void countNode()
    {
        int c = 1;
        if (head == NULL)
        {
            printf("Empty list node 0");
            return;
        }
        node *p = head;
        while (p != NULL)
        {
            c++;
            p = p->next;
        }
        printf("Node number: %d", c);
        return;
    }

    void deleteAtFirst()
    {
        if (head == NULL)
        {
            printf("Empty list!!\n");
            return;
        }
        node *p = head;
        head = p->next;
        head->prev = NULL;
        free(p);
        count--;
    }

    void deleteAtLast()
    {
        if (head == NULL)
        {
            printf("Empty list!!\n");
            return;
        }
        if (head->next == NULL)
        {
            free(head);
            head = tail = NULL;
            count--;
            return;
        }
        node *temp = tail;
        tail = temp->prev;
        tail->next = NULL;
        free(temp);
        count--;
    }

    void deleteAtany()
    {
        if (head == NULL)
        {
            printf("Empty list!!\n");
            return;
        }

        int pos;
        printf("enter the position if you want to delete: ");
        scanf("%d", &pos);
        if (pos == 1)
        {
            deleteAtFirst();
            return;
        }
        if (pos == count + 1)
        {
            deleteAtLast();
            return;
        }
        if (pos > count + 1)
        {
            printf("Not exist the pos: ");
            return;
        }
        node *p = head;
        node *temp;
        for (int i = 1; i < count - 1; i++)
        {
            p = p->next;
        }
        temp = p->next;
        p->next = temp->next;
        temp->next->prev = p;
        free(temp);
    }

    void display()
    {
        if (head == NULL)
        {
            printf("Empty linkedlist!!\n");
            return;
        }
        node *p = head;
        while (p != NULL)
        {
            printf("%d <-> ", p->data);
            p = p->next;
        }
        printf("NULL\n");
        return;
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
            printf("5. delete a Node at First: \n");
            printf("6. delete a Node at Last: \n");
            printf("7. delete a Node at any Position: \n");
            printf("8. Find Data in Linkedlist: \n");
            printf("9. Count node: \n");
            printf("10. Display of the Linkedlist: \n");
            printf("11. Exit: \n");
            int ops;
            printf("press 1 to 11: ");
            scanf("%d", &ops);
            switch (ops)
            {
            case 1:
            {
                int n;
                printf("how many node if you create: ");
                scanf("%d", &n);
                createList(n);
                break;
            }
            case 2:
            {
                int x;
                printf("Enter data: ");
                scanf("%d", &x);
                insertAtFirst(x);
                break;
            }
            case 3:
            {
                int x;
                printf("Enter data: ");
                scanf("%d", &x);
                insertAtLast(x);
                break;
            }
            case 4:
            {
                int pos, x;
                printf("Enter the position of the linkedlist: ");
                scanf("%d", &pos);
                printf("Enter the data of %d this posititon: ", pos);
                scanf("%d", &x);
                insertAtAny(x, pos);
                break;
            }
            case 5:
            {

                deleteAtFirst();
                break;
            }
            case 6:
            {
                deleteAtLast();
                break;
            }
            case 7:
            {
                int pos;
                printf("Enter the position of the linkedlist: ");
                scanf("%d", &pos);

                deleteAtany(pos);
                break;
            }
            case 8:
            {
                int x;
                pritnf("Enter the data to find the list: ");
                scanf("%d",&x);
                search(x);
                break;
            }
            case 9:
            {
                countNode();
                break;
            }
            case 10:
            {
                display();
                break;
            }
            case 11:
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
