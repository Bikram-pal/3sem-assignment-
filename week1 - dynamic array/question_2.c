// Write a C program to find the 3 rd /user defined position based maximum element in an array using dynamic memory allocation.
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i;
    int element,n,*arr;

    printf("enter the range of the array(min upto 3): ");
    scanf("%d",&n);
    if(n<3)
    {
        printf("enter minimum 3 in the range... ");
        return 1;
    }
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
    
    for(int i=0; i<n; i++)
    {
        if(i+1==3)
        {
            element=arr[i];
            printf("the %d element is: %d\n",i+1,element);
        }
    }
    return 0;
}