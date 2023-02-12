#include <stdio.h>
#include <stdlib.h>

typedef int Matrix[5];

/*
Matrix * sampleFunct()
{
    Matrix *ptr;

    ptr = (Matrix *)malloc(sizeof(Matrix));
    ptr[0] = 3; // not assignable apparently

    return ptr;
}
*/

int * anotherFunction()
{
    int *pointer = (int*)malloc(sizeof(int)*5);

    pointer[0] = 6;

    return pointer;
}

int main()
{
    int idx, *pointer;

    Matrix x = {2, 5, 3, 7, 1}, *ptr;

    for(idx = 0; idx < 5; idx++){
        printf("%d\n", *(x+idx));
    }

    // ptr = sampleFunct();
    // printf("\n%d\n", ptr[0]);

    pointer = anotherFunction();
    printf("\n%d\n\n\n\n\n\n\n", pointer[0]);

    Matrix y[3] = {3, 4, 6, 2, 1, 9, 4};

    printf("%d\n", y[1][0]);
    printf("sizeof(y) = %lu\n", sizeof(y));
    printf("sizeof(x) = %lu\n", sizeof(x));

    return 0;
}