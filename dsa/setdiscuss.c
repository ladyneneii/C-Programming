#include <stdio.h>
#include <stdlib.h>
#define size 10

typedef int SET[size];

SET *Union(SET A, SET B);
void display(SET *C);

int main()
{
    SET A = {1, 0, 0, 1, 1, 0, 0, 1, 0, 1};
    SET B = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1};

    SET *C = Union(A, B);
    display(C);

    return 0;
}

SET *Union(SET A, SET B)
{
    SET *result = (int *)malloc(size * sizeof(int));
    int idx;

    for (idx = 0; idx < size; idx++){
        result[idx] = (A[idx] == 1 || B[idx] == 1) ? 1 : 0;
    }

    return result;
}

void display(SET *C)
{
    int idx;

    for (idx = 0; idx < size; idx++){
        printf("%d ", C[idx]);
    }
}

/*
if (A[idx] == 1 || B[idx] == 1){
            result[idx] = 1;
        } else {
            result[idx] = 0;
        }
*/