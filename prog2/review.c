#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int item[MAX];
    int count;
} Alist;

typedef struct {
    int *item;
    int count;
} AlistD;

void insert(Alist *list, int value);
Alist insertv2(Alist list, int value);
void insertD(AlistD *list, int value);
AlistD insertv2D(AlistD list, int value);


int main()
{
    Alist myList = {{2, 4, 5}, 3};

    insert(&myList, 9);

    int idx;

    printf("myList:\n");
    for (idx = 0; idx < myList.count; idx++){
        printf("%d ", myList.item[idx]);
    }

    printf("\n\n");
    myList = insertv2(myList, 0);

    for (idx = 0; idx < myList.count; idx++){
        printf("%d ", myList.item[idx]);
    }

    AlistD anotherList = {(int *)malloc(5 * sizeof(int)), 3};
    anotherList.item[0] = 66;
    anotherList.item[1] = 77;
    anotherList.item[2] = 88;

    printf("\n\n");
    printf("anotherList:\n");
    insertD(&anotherList, 99);
    for (idx = 0; idx < anotherList.count; idx++){
        printf("%d ", anotherList.item[idx]);
    }

    printf("\n\n");
    anotherList = insertv2D(anotherList, 100);

    for (idx = 0; idx < anotherList.count; idx++){
        printf("%d ", anotherList.item[idx]);
    }

    return 0;
}

void insert(Alist *list, int value)
{
    list->item[list->count] = value;
    list->count++;
}

Alist insertv2(Alist list, int value)
{
    list.item[list.count] = value;
    list.count++;

    return list;
}

void insertD(AlistD *list, int value)
{
    list->item[list->count] = value;
    list->count++;
}

AlistD insertv2D(AlistD list, int value)
{
    list.item[list.count] = value;
    list.count++;

    return list;
}