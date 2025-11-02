// Write a C program to implement stack using dynamic array and perform the following operation • PUSH() • POP() • PEEK() • DISPLAY(). Mention the necessary algorithm.

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node;

node*top=NULL;

void push(int x)
{
	int count=0;
	node * nw;
	nw=(node*)malloc(sizeof(node));
	
	nw->data=x;
	nw->next=NULL;
	
	if(!nw)
	{
		printf("Memory allocation failed!!!\n");
		return;
	}
	
	else
	{
		nw->next=top;
		top=nw;
		
	}
	
	count++;
	printf("The element %d is insert in top...\n",x);
	return;
}
void pop()
{
	if(top==NULL)
	{
		printf("Underflow error!!!\n");
		return;
	}
	node * temp;
	temp=top;
	top=top->next;
	free(temp);
	printf("Top data delete sucessfully!!!\n");
	return;
}
void peep()
{
	if(top==NULL)
	{
		printf("Empty Stack!!\n");
		return;
	}
	printf("top element: ");
	printf("%d\n",top->data);
	return;
}

void display()
{
	node * p;
	p=top;
	if(p==NULL)
	{
		printf("Empty stack!!!\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%d -> ",p->data);
		p=p->next;
	}
	printf("NULL\n");
}

int main()
{
	while(1)
	{
		printf("1. push: \n");
		printf("2. pop: \n");
		printf("3. peep: \n");
		printf("4. display: \n");
		printf("5. exit: \n ");
		printf("press any between 1 to 5: ");
		int ops;
		scanf("%d",&ops);
		switch (ops)
		{
		case 1:
		{
			int data;
			printf("enter a value: ");
			scanf("%d",&data);
			push(data);
			break;
		}
		case 2: 
		{
			pop();
			break;
		}
		case 3: 
		{
			peep();
			break;
		}
		case 4:
		{
			display();
			break;
		}
		case 5: 
		{
			node * p, *temp;
			p=top=temp;
			if(top==NULL)
			{
				exit(0);
			}
			while(p!=NULL)
			{
				p=p->next;
				free(temp);
				temp=p;
			}
			exit(0);
		}

		default:
			printf("Enter a valid number: ");
			break;
		}
	}
	return 0;
}