#include <stdio.h>
#include <stdlib.h>
#define size 8

typedef int SET[size];

int *unionSet(SET A, SET B);
void displaySet(int *C);

int main()
{
    SET A = {1, 1, 0, 0, 0, 1, 0, 1};
    SET B = {1, 0, 0, 0, 1, 1, 0, 0};

    int *C = unionSet(A, B);
    displaySet(C);

    return 0;
}

int *unionSet(SET A, SET B)
{
	int *C = (int *)malloc(size*sizeof(int));
	int idx;

	for (idx = 0; idx < size; idx++){
		C[idx] = A[idx] == 1 || B[idx] == 1;
	}

	return C;
}

void displaySet(int *C)
{
    int idx;

    for (idx = 0; idx < size; idx++){
        printf("%d ", C[idx]);
    }
}