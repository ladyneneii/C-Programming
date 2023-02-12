#include <stdio.h>
#define SIZE 10 // b.

typedef struct {
    char Elements[SIZE];
    int count;
} List; // a.

void initEmpty(int *count);

int main()
{
    List L; // c. 14 bytes

    initEmpty(&L.count);
    printf("The value of count is %d", L.count);

    return 0;
}

// 2.
void initEmpty(int *count)
{
    *count = 0;
}