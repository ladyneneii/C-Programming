#include <stdio.h>
#define Max 10

typedef struct {
    struct {
        char data;
        int link;
    } Nodes[Max];
    int Avail;
} VirtualHeap;

typedef int List;

int main()
{


    return 0;
}

void initVirtualHeap(VirtualHeap *VHptr)
{
    int idx;

    VHptr->Avail = 0;
    for (idx = 0; idx < 6; idx++){
        VHptr->Nodes[idx].link = idx+1;
    }
    VHptr->Nodes[idx].link = -1;
}

void initVirtualHeap2(VirtualHeap *VHptr)
{
    int idx;

    VHptr->Avail = 6;
    for (idx = 6; idx > 0; idx--){
        VHptr->Nodes[idx].link = idx-1;
    }
    VHptr->Nodes[idx].link = -1;
}

int allocSpace(VirtualHeap *VHptr)
{
    int freeIndex;

    if (VHptr->avail != -1){
        freeIndex = VHptr->avail;
        VHptr->avail = VHptr->Nodes[freeIndex].link;
    } else {
        freeIndex = -1;
    }

    return freeIndex;
}

void deallocSpace(int node, VirtualHeap *VHptr)
{
    VHptr->Nodes[node].link = VHptr->avail;
    VHptr->avail = node;
}