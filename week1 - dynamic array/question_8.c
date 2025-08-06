// Write a C program to merge two unsorted dynamic array in sorted order.
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,j;
    printf("Enter a range: ");
    scanf("%d",&n);

    int *arr1=(int*)malloc(n*sizeof(int));
    int *arr2=(int*)malloc(n*sizeof(int));
    int *arr3=(int*)malloc(2*n*sizeof(int));

    for(i=0; i<n; i++)
    {
        printf("arr1 element %d: ",i+1);
        scanf("%d",&arr1[i]);
    }
    for(i=0; i<n; i++)
    {
        printf("arr2 element %d: ",i+1);
        scanf("%d",&arr2[i]);
    }
    for(i=0; i<2*n; i++)
    {
        if(i<n)
        {
            arr3[i]=arr1[i];
        }
        else
        {
            arr3[i]=arr2[i-n];
        }
        
    }

    for(int i=0; i<2*n-1; i++)
    {
        for(int j=0; j<2*n-i-1;j++)
        {
            int temp;
            if(arr3[j]>arr3[j+1])
            {
                temp=arr3[j+1];
                arr3[j+1]=arr3[j];
                arr3[j]=temp;

            }
        }
    }
     for(i=0; i<2*n; i++)
    {
        printf("%d ",arr3[i]);
    }

    free(arr1);
    free(arr2);
    free(arr3);
    return 0;
}

