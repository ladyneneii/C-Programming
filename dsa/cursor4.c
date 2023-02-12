#include <stdio.h>
#include <stdlib.h>
#define size 10

typedef struct {
    char item;
    int next;
} Nodetype;

typedef struct {
    Nodetype cells[size];
    int avail;
} VirtualHeap, *VH;

typedef int List;

VH createVH();
void initVH(VH record);
void visualizeVH(VH record);
void displayList(VH record, List list);
void insertFirst(VH record, List *list, char item);
int allocSpace(VH record);
void ascendSelection(VH record, List list);
void insertSorted(VH record, List *list, char item);

int main()
{
    VH recordptr = createVH();
    List list = -1;

    visualizeVH(recordptr);
    displayList(recordptr, list);
    insertFirst(recordptr, &list, 'h');
    insertFirst(recordptr, &list, 'c');
    insertFirst(recordptr, &list, 't');
    insertFirst(recordptr, &list, 'i');
    insertFirst(recordptr, &list, 'b');
    visualizeVH(recordptr);
    displayList(recordptr, list);
    ascendSelection(recordptr, list);
    visualizeVH(recordptr);
    displayList(recordptr, list);
    insertSorted(recordptr, &list, 'd');
    insertSorted(recordptr, &list, '0');
    insertSorted(recordptr, &list, 'z');
    insertSorted(recordptr, &list, 'g');
    insertSorted(recordptr, &list, '2');
    visualizeVH(recordptr);
    displayList(recordptr, list);

    return 0;
}

VH createVH()
{
    VH record = (VH)malloc(sizeof(VirtualHeap));

    initVH(record);

    return record;
}

void initVH(VH record)
{
    int idx;

    record->avail = size-1;
    for (idx = size-1; idx > -1; idx--){
        record->cells[idx].item = ' ';
        record->cells[idx].next = idx-1;
    }
}

void visualizeVH(VH record)
{
    int idx;

    printf("%15s| %15s| %15s\n", "INDEX", "data", "link");
    for (idx = 0; idx < size; idx++){
        printf("%15d| %15c| %15d\n", idx, record->cells[idx].item, record->cells[idx].next);
    }
}

void displayList(VH record, List list)
{
    int idx; 

    printf("\nlist = %d {", list);
    for (idx = list; idx != -1; idx = record->cells[idx].next){
        printf("%c ", record->cells[idx].item);
    }
    printf("}\n");
    printf("avail = %d\n", record->avail);
}

void insertFirst(VH record, List *list, char item)
{
    int temp = allocSpace(record);

    record->cells[temp].item = item;
    record->cells[temp].next = *list;
    *list = temp;
}

int allocSpace(VH record)
{
    int freeIndex;

    if (record->avail != -1){
        freeIndex = record->avail;
        record->avail = record->cells[freeIndex].next;
    } else {
        printf("No space left.\n");
        freeIndex = -1;
    }

    return freeIndex;
}

void ascendSelection(VH record, List list)
{
    int x, y, small;
    char temp;

    for (x = list; x != -1; x = record->cells[x].next){
        small = x;
        for (y = record->cells[x].next; y != -1; y = record->cells[y].next){
            if (record->cells[small].item > record->cells[y].item){
                small = y;
            }
        }
        if (record->cells[x].item > record->cells[small].item){
            temp = record->cells[x].item;
            record->cells[x].item = record->cells[small].item;
            record->cells[small].item = temp;
        }
    }
}

void insertSorted(VH record, List *list, char item)
{
    int freeIdx = allocSpace(record);

    if (freeIdx != -1){
        record->cells[freeIdx].item = item;
        record->cells[freeIdx].next = -1;
        for ( ; *list != -1 && record->cells[*list].item < item && record->cells[*list].item != item; list = &record->cells[*list].next){}
        if (record->cells[*list].item == item){
            printf("Element already exists.\n");
        } else if (record->cells[*list].item > item){
            record->cells[freeIdx].next = *list;
            *list = freeIdx;
        } else {
            *list = freeIdx;
        }
    } else {
        printf("Cannot perform insertFirst()");
    }
}