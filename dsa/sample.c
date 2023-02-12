// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int *doubleArrNoMalloc();
int *doubleArrWithMalloc();
void displayArr(int arr[], int size);

int main()
{
    
    int *arr = doubleArrNoMalloc();
    printf("\nArray without malloc:\n");
    displayArr(arr, 5);
    
    int *arr2 = doubleArrWithMalloc();
    printf("\nArray with malloc:\n");
    displayArr(arr2, 5);

    return 0;
}

int *doubleArrNoMalloc()
{
    int idx;
    int arr[5] = {2, 4, 5, 0, 3};
    
    for (idx = 0; idx < 5; idx++){
        arr[idx] *= 2;
    }
    
    return arr;
}

int *doubleArrWithMalloc()
{
    int *arr = (int *)malloc(5*sizeof(int));
    arr[0] = 2, arr[1] = 4, arr[2] = 5, arr[3] = 0, arr[4] = 3;
    int idx;
    
    for (idx = 0; idx < 5; idx++){
        arr[idx] *= 2;
    }
    
    return arr;
}

void displayArr(int array[], int size)
{
    int idx;

    for (idx = 0; idx < size; idx++){
        printf("%d ", array[idx]);
    }
}