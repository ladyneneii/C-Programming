#include <stdio.h>

void ascendBubble(int arr[], int size);
void display(int arr[], int size);
void descendSelection(int arr[], int size);
void ascendInsertion(int arr[], int size);

int main()
{
    int arr[10] = {3, 5, 2, 5, 1, 9, 2, 1, 9, 0};
    int arr2[10] = {66, 33, 566, 12, 7, 0, 0, 24, 33, 100};
    int arr3[10] = {-5, -1, -22, 5, 3, -87, -12, 0, -65, -22};

    display(arr, 10);
    ascendBubble(arr, 10);
    display(arr, 10);
    descendSelection(arr2, 10);
    printf("\n");
    display(arr2, 10);
    ascendInsertion(arr3, 10);
    printf("\n");
    display(arr3, 10);

    return 0;
}

void ascendBubble(int arr[], int size)
{
    int x, y, temp;

    for (x = 0; x < size-1; x++){
        for (y = x+1; y < size; y++){
            if (arr[x] > arr[y]){
                temp = arr[x];
                arr[x] = arr[y];
                arr[y] = temp;
            }
        }
    }
}

void display(int arr[], int size)
{
    int idx;

    for (idx = 0; idx < size; idx++){
        printf("%d ", arr[idx]);
    }
}

void descendSelection(int arr[], int size)
{
    int x, y, big, temp;

    for (x = 0; x < size-1; x++){
        big = x;
        for (y = x+1; y < size; y++){
            if (arr[big] < arr[y]){
                big = y;
            }
        }
        if (arr[big] > arr[x]){
            temp = arr[big];
            arr[big] = arr[x];
            arr[x] = temp;
        }
    }
}

void ascendInsertion(int arr[], int size)
{
    int x, y, temp;

    for (x = 0; x < size-1; x++){
        for (y = x; y > -1 && arr[y] > arr[y+1]; y--){
            temp = arr[y];
            arr[y] = arr[y+1];
            arr[y+1] = temp;
        }
    }
}