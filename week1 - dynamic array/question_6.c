// Write a C program to find the minimum element in a 2D-array using dynamic memory allocation.
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j;
    int rows, cols, min;

    printf("Enter the rows: ");
    scanf("%d",&rows);
    printf("Enter the cols: ");
    scanf("%d", &cols);

    int **arr=(int**)malloc(rows*sizeof(int*));

    for(i=0; i<rows; i++)
    {
        arr[i]=(int*)malloc(cols*sizeof(int));
    }

    for(int i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            printf("element of (%d,%d): ",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    min=arr[0][0];
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(min>arr[i][j])
            {
                min=arr[i][j];
            }
        }
    }
    printf("minimum element of the array is : %d",min);

    for(int i=0; i<rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}