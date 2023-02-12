#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    char *elemPtr;
    int count;
} record, *List;

void initEmpty(List listPtr);
void populateList(List listPtr);

int main()
{
    List L = (List)malloc(sizeof(record));

    L->elemPtr = (char *)malloc(SIZE*sizeof(char));
    initEmpty(L);
    printf("%d\n", L->count);
    populateList(L);
    printf("%s\n", L->elemPtr);

    return 0;
}

void initEmpty(List listPtr)
{
    listPtr->count = 0;
}

void populateList(List listPtr)
{
    int idx;

    listPtr->count = 4;
    listPtr->elemPtr = (char *)realloc(listPtr->elemPtr, 5*sizeof(char));
    printf("Enter a word:\n");
    for (idx = 0; idx < listPtr->count; idx++){
        scanf(" %c", listPtr->elemPtr+idx);
    }
    listPtr->elemPtr[idx] = '\0';
}

