// Write a C program to delete a range of data from a dynamic array.
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int i, start, end;
    printf("enter a range of the array: ");
    scanf("%d", &n);

    int *arr=(int*)malloc(n*sizeof(int));

    for(i=0; i<n; i++)
    {
        printf("enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("enter a start or end value for delete element: ");
    scanf("%d%d",&start,&end);

    
}