#include <stdio.h>
#define MAX 10

typedef struct {
    int elem, next;
} Nodetype;

typedef struct {
    int avail;
    Nodetype data[MAX];
} VSpace;

void initSpace(VSpace *spacePtr);
void visualiseSpace(VSpace space);
void displayList(VSpace space, int list);
void insertElem(VSpace *spacePtr, int *list, int num);
int allocSpace(VSpace *spacePtr);
void deleteFront(VSpace *spacePtr, int *list);
void freeSpace(int del, VSpace *spacePtr);

int main()
{
    VSpace space;
    int firstList = -1, secondList = -1;

    initSpace(&space);
    visualiseSpace(space);
    displayList(space, firstList);
    insertElem(&space, &firstList, 7);
    insertElem(&space, &secondList, -6);
    insertElem(&space, &secondList, -69);
    insertElem(&space, &firstList, 23);
    insertElem(&space, &secondList, -4);
    visualiseSpace(space);
    displayList(space, firstList);
    displayList(space, secondList);
    deleteFront(&space, &firstList);

    return 0;
}

void initSpace(VSpace *spacePtr)
{
    int idx;

    spacePtr->avail = MAX-1;
    for (idx = MAX-1; idx > -1; idx--){
        spacePtr->data[idx].elem = -999;
        spacePtr->data[idx].next = idx-1;
    }
}

void visualiseSpace(VSpace space)
{
    int idx;

    printf("%15s | %15s | %15s\n", "INDEX", "ELEM", "NEXT");
    for (idx = 0; idx < MAX; idx++){
        printf("%15d | %15d | %15d\n", idx, space.data[idx].elem, space.data[idx].next);
    }
    printf("avail: %d\n", space.avail);
}

void displayList(VSpace space, int list)
{
    int idx; 

    printf("list = %d {", list);
    for (idx = list; idx != -1; idx = space.data[idx].next){
        printf("%d ", space.data[idx].elem);
    }
    printf("}\n");
}

void insertElem(VSpace *spacePtr, int *list, int num)
{
    // the function creates the freeSpace variable that stores the current available index in VSpace. 
    // the function updates the elem variable with the inserted element and the next variable with the current value of list.

    int freeSpace = allocSpace(spacePtr);

    spacePtr->data[freeSpace].elem = num;
    spacePtr->data[freeSpace].next = *list;
    *list = freeSpace;
}

int allocSpace(VSpace *spacePtr)
{
    // the function creates the avail variable that stores the current available index in VSpace. 
    // if avail != -1, the function updates the avail variable in VSpace to the next available index.

    int avail = spacePtr->avail;

    if (avail != -1){
        spacePtr->avail = spacePtr->data[avail].next;
    } else {
        printf("No space available.");
    }

    return avail;
}

void deleteFront(VSpace *spacePtr, int *list)
{
    int del = *list;

    *list = spacePtr->data[del].next;
    freeSpace(del, spacePtr);
}

void freeSpace(int del, VSpace *spacePtr)
{
    spacePtr->data[del].next = spacePtr->avail;
    spacePtr->data[del].elem = -999;
    spacePtr->avail = del;
}