#include <stdio.h>
#define SIZE 10 // b.

typedef struct {
    char Elements[SIZE];
    int count;
} *List, Record; // a.

void initEmpty(List listPtr);

int main()
{
    Record list;
    List L; // c. 8 bytes

    L = &list;

    initEmpty(L);
    printf("The value of count is %d", list.count);

    return 0;
}


// 2.
void initEmpty(List listPtr)
{
    listPtr->count = 0;
}