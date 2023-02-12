#include <stdio.h>
#define MAX 10

typedef struct {
    int elem, next;
} Nodetype;

typedef struct {
    int avail;
    Nodetype data[MAX];
} VSpace;

void createrecord(VSpace *record);
void visualiserecord(VSpace record);
void displayrecord(int list, VSpace space);
void insertrecord(int *list, VSpace *space, int item);
int allocSpace(VSpace *space);
void deletefront(int *list, VSpace *space);
void freespace(int del, VSpace *space);

int main()
{
    VSpace space;
    int firstList = -1, secondList = -1;
    
    createrecord(&space);
    visualiserecord(space);
    displayrecord(firstList, space);
    insertrecord(&firstList, &space, 3);
    visualiserecord(space);
    displayrecord(firstList, space);
    insertrecord(&firstList, &space, 6);
    insertrecord(&secondList, &space, 88);
    insertrecord(&firstList, &space, 9);
    insertrecord(&secondList, &space, 99);
    visualiserecord(space);
    displayrecord(firstList, space);
    displayrecord(secondList, space);
    deletefront(&firstList, &space);
    visualiserecord(space);
    displayrecord(firstList, space);
    

    return 0;
}

void createrecord(VSpace *record)
{
    int idx;

    record->avail = MAX-1;
    for (idx = MAX-1; idx > -1; idx--){
        record->data[idx].elem = -999;
        record->data[idx].next = idx-1;
    }
}

void visualiserecord(VSpace record)
{
    int idx;

    printf("%15s | %15s | %15s\n", "INDEX", "ELEM", "NEXT");
    for (idx = 0; idx < MAX; idx++){
        printf("%15d | %15d | %15d\n", idx, record.data[idx].elem, record.data[idx].next);
    }
}

void displayrecord(int list, VSpace space)
{
    int idx; 

    printf("{");
    for (idx = list; idx != -1; idx = space.data[idx].next){
        printf("%d, ", space.data[idx].elem);
    }
    printf("}");
}

void insertrecord(int *list, VSpace *space, int item)
{
    int freeindex = allocSpace(space);

    space->data[freeindex].elem = item;
    space->data[freeindex].next = *list;
    *list = freeindex;
}

int allocSpace(VSpace *space)
{
    int avail = space->avail;

    if (avail != -1){
        space->avail = space->data[avail].next;
    } else {
        printf("No space anymore.\n");
    }

    return avail;

    // creates avail variable that stores the current available space/index in VSpace. 
    // then checks if avail is -1. if it is not, it updates the avail variable in VSpace to the next available space/index.
}

void deletefront(int *list, VSpace *space)
{
    int del = *list;

    *list = space->data[*list].next;
    freespace(del, space);
}

void freespace(int del, VSpace *space)
{
    space->data[del].next = space->avail;
    space->data[del].elem = -999;
    space->avail = del;
}
