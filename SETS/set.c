#include <stdio.h>
#include <stdlib.h>
#define size 8

typedef int SET[size];

SET *unionSet(SET A, SET B);
void displaySet(SET *C);

int main()
{
    SET A = {1, 1, 0, 0, 0, 1, 0, 1};
    SET B = {1, 0, 0, 0, 1, 1, 0, 0};

    SET *C = unionSet(A, B);
    displaySet(C);

    return 0;
}

SET *unionSet(SET A, SET B)
{
	SET *C = (SET *)malloc(sizeof(SET));
	int idx;

	for (idx = 0; idx < size; idx++){
		(*C)[idx] = (A[idx] == 1 && B[idx] == 1) ? 1 : 0;
	}

	return C;
}

void displaySet(SET *C)
{
    int idx;

    for (idx = 0; idx < size; idx++){
        printf("%d ", (*C)[idx]);
    }
}