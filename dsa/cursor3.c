#include <stdio.h>
#include <stdlib.h>
#define Max 10

typedef struct {
    char data; 
    int link;
} Nodetype;

typedef struct {
    Nodetype Nodes[Max];
    int Avail;
} *VirtualHeap, VHType;

typedef int List;

void initVirtualHeap(VirtualHeap *VHPtr);
void visualizeVH(VirtualHeap VH);
void displayList(VirtualHeap VH, List list);
int allocSpace(VirtualHeap VH);
void deallocSpace(VirtualHeap VH, int deallocIdx);
void insertFirst(VirtualHeap VH, char elem, List *list);

int main()
{
    VirtualHeap VH;
    List list = -1;

    initVirtualHeap(&VH);
    visualizeVH(VH);
    displayList(VH, list);
    printf("\nAllocated Index: %d", allocSpace(VH));
    displayList(VH, list);
    deallocSpace(VH, 9);
    displayList(VH, list);
    insertFirst(VH, 'b', &list);
    insertFirst(VH, 'i', &list);
    visualizeVH(VH);
    displayList(VH, list);

    // another list

    List list2 = -1;
    insertFirst(VH, '3', &list2);
    insertFirst(VH, '7', &list2);
    visualizeVH(VH);
    displayList(VH, list2);

    // combine both lists
    insertFirst(VH, 'a', &list);
    insertFirst(VH, '6', &list2);
    insertFirst(VH, 'v', &list);
    insertFirst(VH, '9', &list2);
    visualizeVH(VH);

    printf("\nlist: \n");
    displayList(VH, list);
    printf("\nlist2: \n");
    displayList(VH, list2);

    return 0;
}

void initVirtualHeap(VirtualHeap *VHPtr)
{
    *VHPtr = (VirtualHeap)malloc(sizeof(VHType));
    int idx;

    for (idx = Max-1; idx > -1; idx--){
        (*VHPtr)->Nodes[idx].data = ' ';
        (*VHPtr)->Nodes[idx].link = idx-1;
    }
    (*VHPtr)->Avail = 9;
}

void visualizeVH(VirtualHeap VH)
{
    int idx;

    printf("%15s| %15s| %15s\n", "INDEX", "data", "link");
    for (idx = 0; idx < Max; idx++){
        printf("%15d| %15c| %15d\n", idx, VH->Nodes[idx].data, VH->Nodes[idx].link);
    }
}

void displayList(VirtualHeap VH, List list)
{
    int idx; 

    printf("\nL = %d {", list);
    for (idx = list; idx != -1; idx = VH->Nodes[idx].link){
        printf("%c ", VH->Nodes[idx].data);
    }
    printf("}\n");
    printf("Avail = %d\n", VH->Avail);
}

int allocSpace(VirtualHeap VH)
{
    int freeSpace;

    if (VH->Avail != -1){
        freeSpace = VH->Avail;
        VH->Avail = VH->Nodes[freeSpace].link;
    } else {
        freeSpace = -1;
    }

    return freeSpace;
}

void deallocSpace(VirtualHeap VH, int deallocIdx)
{
    VH->Nodes[deallocIdx].link = VH->Avail;
    VH->Avail = deallocIdx;
}

void insertFirst(VirtualHeap VH, char elem, List *list)
{
    int temp = allocSpace(VH);

    VH->Nodes[temp].data = elem;
    VH->Nodes[temp].link = *list;
    *list = temp;
}