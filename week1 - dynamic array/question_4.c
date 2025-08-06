// Write a C program to search an element in a 2D-Array using dynamic memory allocation.
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int rows,cols,**arr;
    int i, j, search, found=0;

    // input number of rows and columns
    printf("enter your rows number: ");
    scanf("%d", &rows);
    printf("enter your number of column: ");
    scanf("%d", &cols);

    // dynamic memeory allocation for rows(pointers)
    int arr=(int **)malloc(rows * sizeof(int *));

    // alocate memory for columns in each rows
    for(i=0; i<rows; i++)
    {
        arr[i]=(int*)malloc(cols * sizeof(int));
    }

    // input array element 
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            printf("enter your (%d, %d) element of the array: ",i+1,j+1);
            scanf("%d", &arr[i][j]);
        }
    }
    

    // search 
    printf("enter a search element:");
    scanf("%d",&search);
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            if(search==arr[i][j])
            {
                printf("found the element at the position of (%d, %d)\n",i+1,j+1);
                found=1;
            }
        }
    }
    if(found==0)
    printf("not found the element..");

    // free the dynamic element 
    for(i=0; i<rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}