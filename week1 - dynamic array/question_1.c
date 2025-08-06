// Write a C program to search an element in an Array using dynamic memory allocation.
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int search,found=0,i;

    printf("enter a range of the array: ");
    scanf("%d",&n);

    int *arr = (int*)malloc(n * sizeof(int));

    if(arr==NULL)
    {
        printf("execution fail...");
        return 1;
    }

    for(int i=0; i<n; i++)
    {
        printf("element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    
    printf("enter your search element: ");
    scanf("%d",&search);

    for(i=0; i<n; i++)
    {
        if(arr[i]==search)
        {
            printf("the element at the position --> %d\n",i+1);
            found=1;
        }
    }
    if(!found)
    printf("not found %d", search);

    free(arr);

}