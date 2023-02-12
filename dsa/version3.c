#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    char *elemPtr;
    int count;
} List;

void initEmpty(List *ptr);
void getList(List *ptr);
void displayList(List list);

int main()
{
    List L;

    L.elemPtr = (char *)malloc(SIZE*sizeof(char));
    initEmpty(&L);
    getList(&L);
    displayList(L);

    return 0;
}

void initEmpty(List *ptr)
{
    ptr->count = 0;
}

void getList(List *ptr)
{
    int idx; 

    ptr->count = 4;
    printf("Enter four letters: \n");
    for (idx = 0; idx < ptr->count; idx++){
        scanf(" %c", ptr->elemPtr+idx);
    }
}

void displayList(List list)
{
    int idx; 

    for (idx = 0; idx < list.count; idx++){
        printf("%c", list.elemPtr[idx]);
    }
}