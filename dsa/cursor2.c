#include <stdio.h>
#define SIZE 10

typedef struct {
    char data;
    int link;
} Nodetype;

/*
typedef struct {
    Nodetype Nodes[SIZE];
    int avail;
} VirtualHeap;
*/

typedef struct {
    struct {
        char data;
        int link;
    } Nodes[7];
    int Avail;
} VirtualHeap;

typedef int List;

void initializeVH(VirtualHeap *space);
void visualizeVH(VirtualHeap space);
void displayList(VirtualHeap space, List list);
int allocSpace(VirtualHeap *space);
void deallocSpace(VirtualHeap *space, int returnSpace);
void initVirtualHeap(VirtualHeap *VHptr);
void initVirtualHeap2(VirtualHeap *VHptr);

int main()
{
    VirtualHeap VH, VH2, VH3;
    List L = -1;

    /*
    initializeVH(&VH);
    visualizeVH(VH);
    displayList(VH, L);

    int freeIndex = allocSpace(&VH);

    visualizeVH(VH);
    displayList(VH, L);
    deallocSpace(&VH, freeIndex);
    */

    initVirtualHeap(&VH2);
    initVirtualHeap2(&VH3);
    visualizeVH(VH2);
    visualizeVH(VH3);

    return 0;
}

/*
void initializeVH(VirtualHeap *space)
{
    int idx;

    for (idx = 0; idx < SIZE-1; idx++){
        space->Nodes[idx].link = idx+1;
        space->Nodes[idx].data = ' ';
    }
    space->Nodes[idx].data = ' ';
    space->Nodes[idx].link = -1;
    space->avail = 0;
}
*/
void visualizeVH(VirtualHeap space)
{
    int idx;

    printf("%15s| %15s| %15s\n", "INDEX", "data", "link");
    for (idx = 0; idx < 7; idx++){
        printf("%15d| %15c| %15d\n", idx, space.Nodes[idx].data, space.Nodes[idx].link);
    }
}
/*
void displayList(VirtualHeap space, List list)
{
    int idx; 

    printf("L = %d {", list);
    for (idx = list; idx != -1; idx = space.Nodes[idx].link){
        printf("%d ", space.Nodes[idx].data);
    }
    printf("}\n");
    printf("avail = %d\n", space.avail);
}

int allocSpace(VirtualHeap *space)
{
    int freeIndex;

    if (space->avail != -1){
        freeIndex = space->avail;
        space->avail = space->Nodes[freeIndex].link;
    } else {
        printf("No space available.\n");
    }

    return freeIndex;
}

void deallocSpace(VirtualHeap *space, int returnSpace)
{
    space->Nodes[returnSpace].data = ' ';
    space->avail = returnSpace;
}
*/
void initVirtualHeap(VirtualHeap *VHptr)
{
    int idx;

    VHptr->Avail = 0;
    for (idx = 0; idx < 6; idx++){
        VHptr->Nodes[idx].link = idx+1;
    }
    VHptr->Nodes[idx].link = -1;
}

void initVirtualHeap(VirtualHeap *VHptr)
{
    int idx;

    VHptr->Avail = 6;
    for (idx = Max-1; idx > Max; idx--){
        VHptr->Nodes[idx].link = idx-1;
    }
}