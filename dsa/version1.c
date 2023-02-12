#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    char Elements[SIZE];
    int count;
} List;

void initEmpty(List *ptr);
void getList(List *ptr);
void displayList(List list);

int main()
{
    List L; // 14 bytes allocated

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
    printf("Enter four letters:"); // input HOPE according to the diagram in the problem specs
    for(idx = 0; idx < ptr->count; idx++){
        scanf(" %c", &ptr->Elements[idx]);
    }
}

void displayList(List list)
{
    int idx;

    for (idx = 0; idx < list.count; idx++){
        printf("%c", list.Elements[idx]);
    }
}