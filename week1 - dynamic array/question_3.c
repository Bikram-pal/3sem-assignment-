// Write a C program to find the minimum element in an array using dynamic memory allocation.
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,min;
    int element,n,*arr;

    printf("enter the range of the array: ");
    scanf("%d",&n);
    
    if(arr==NULL)
    {
        printf("execution failed...");
        return 1;
    }

    arr = (int*)malloc( n * sizeof(int));

    for(int i=0; i<n; i++)
    {
        printf("%d element: ",i+1);
        scanf("%d", &arr[i]);
    }
    
    min=arr[0];
    
    for(int i=1; i<n; i++)
    {
        if(min>arr[i])
        {
            min=arr[i];
        }
    }

    printf("minium element of the array is: %d",min);

    return 0;
}