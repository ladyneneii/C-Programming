#include <stdio.h>
#define MAX 10

typedef struct {
    int elem, link;
} Nodetype;

typedef struct {
    Nodetype data[MAX];
    int avail;
} VSpace;

void createSpace(VSpace *space);
void visualiseSpace(VSpace space);
void displaySpace(VSpace space, int list);
void insertFront(VSpace *space, int *list, int item);
int allocSpace(VSpace *space);
void deleteFront(VSpace *space, int *list);
void freeSpace(VSpace *space, int del);
void insertRear(VSpace *space, int *list, int item);
void insertPos(VSpace *space, int *list, int pos, int item);

int main()
{
    VSpace space1;
    int list1 = -1, list2 = -1;

    createSpace(&space1);
    visualiseSpace(space1);
    displaySpace(space1, list1);
    insertFront(&space1, &list1, 90);
    insertFront(&space1, &list1, 80);
    insertFront(&space1, &list1, 70);
    insertFront(&space1, &list2, 999);
    insertFront(&space1, &list2, 998);
    insertFront(&space1, &list1, 60);
    visualiseSpace(space1);
    displaySpace(space1, list1);
    displaySpace(space1, list2);
    deleteFront(&space1, &list2);
    visualiseSpace(space1);
    displaySpace(space1, list1);
    displaySpace(space1, list2);
    printf("\n\nAfter insertion:\n\n");
    insertRear(&space1, &list1, 50);
    visualiseSpace(space1);
    displaySpace(space1, list1);
    insertRear(&space1, &list2, 980);
    insertRear(&space1, &list2, 991);
    visualiseSpace(space1);
    displaySpace(space1, list1);
    displaySpace(space1, list2);
    insertPos(&space1, &list1, 4, 10);

    return 0;
}

void createSpace(VSpace *space)
{
    int idx;

    space->avail = MAX-1;
    for (idx = MAX-1; idx > -1; idx--){
        space->data[idx].elem = -100;
        space->data[idx].link = idx-1;
    }
}

void visualiseSpace(VSpace space)
{
    int idx; 

    printf("%15s | %15s | %15s\n", "INDEX", "ELEM", "LINK");
    for (idx = 0; idx < MAX; idx++){
        printf("%15d | %15d | %15d\n", idx, space.data[idx].elem, space.data[idx].link);
    }
}

void displaySpace(VSpace space, int list)
{
    int idx;

    printf("{");
    for (idx = list; idx != -1; idx = space.data[idx].link){
        printf("%d ", space.data[idx].elem);
    }
    printf("}\n");
    printf("list = %d\n", list);
    printf("avail = %d\n", space.avail);
}

void insertFront(VSpace *space, int *list, int item)
{
    int temp = allocSpace(space);

    space->data[temp].elem = item;
    space->data[temp].link = *list;
    *list = temp;
}

int allocSpace(VSpace *space) // checks whether there is still available index. if there is, space->avail gets updated to the next available index or -1, then returns the current available index
{
    int avail = space->avail;

    if (avail != -1){
        space->avail = space->data[avail].link;
    } else {
        printf("No space available.\n");
    }

    return avail;
}

void deleteFront(VSpace *space, int *list) // updates the list1 variable in main() to the new first index, since the previous first index got deleted
{
    int del = *list;

    space->data[del].elem = -100;
    *list = space->data[*list].link;
    freeSpace(space, del);
}

void freeSpace(VSpace *space, int del) 
{
    if (del != -1){
        space->data[del].link = space->avail; // connects the deleted index to space->avail
        space->avail = del; // updates space->avail to the deleted index
    } else {
        printf("Space is already free or no space available.\n");
    }
}

/*
void insertRear(VSpace *space, int *list, int item)
{
    int idx, avail;

    avail = space->avail;
    space->avail = space->data[space->avail].link;
    *list = avail;
    for (idx = avail, space->data[idx].link = *list; idx != -1 && space->data[idx].link != -1; idx = space->data[idx].link){
        space->data[idx].elem = space->data[space->data[idx].link].elem;
    }
    space->data[idx].elem = item;
    

    // change list1 to 5
    
}
*/

void insertRear(VSpace *space, int *list, int item)
{
    int avail = space->avail, idx = avail; // create temporary variables because they are necessary; initialise idx to the new first index, which is 5

    space->avail = space->data[idx].link; // update the avail variable to the next available index, which is 3
    space->data[idx].link = *list; // connect the new first index to the current first index, which is 4
    *list = idx; // update the list in main() to the new first index, which is 5
    for ( ; space->data[idx].link != -1; idx = space->data[idx].link){
        space->data[idx].elem = space->data[space->data[idx].link].elem; // shift the content of the nodes to make space for the rear index, in which the item variable (50) will be placed
    }
    space->data[idx].elem = item;
}

void insertPos(VSpace *space, int *list, int pos, int item)
{
    int temp = allocSpace(space), idx;

    for (idx = 0; idx < 4; idx++){

    }
}