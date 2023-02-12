#include <stdio.h>
#include <stdlib.h>
#define limit 10

typedef struct cell {
    char *elem;
    int front, rear;
} *Circ;

typedef struct junct {
    char elem;
    int next;
} *Nodetype;

typedef struct node {
    Nodetype nodes;
    int avail;
} *Vheap;

void initVirtualSpace(Vheap vptr);
void enqueueArr(Circ arrptr, char x);
int isFull(Circ arrptr);
int isEmpty(Circ arrptr);
char dequeueArr(Circ arrptr);
void transferVSpace(Circ arrptr, Vheap vptr, int *listPtr);
int allocSpace(Vheap vptr);
void makeEmpty(Circ arrptr, Vheap vptr, int *listPtr);
void makeFull(Circ arrptr);
void displayBoth(Circ arrptr, int list, Vheap vptr);

int main()
{
    Circ arrptr = (Circ)malloc(sizeof(struct cell));
    Vheap vptr = (Vheap)malloc(sizeof(struct node));
    int list = -1;

    if (arrptr != NULL && vptr != NULL){
        arrptr->front = 0;
        arrptr->rear = limit-1;
        arrptr->elem = (char *)malloc(limit*sizeof(char));
        vptr->nodes = (Nodetype)malloc(limit*sizeof(struct junct));
        initVirtualSpace(vptr);
        if (arrptr->elem != NULL && vptr->nodes != NULL){
            makeFull(arrptr);
            displayBoth(arrptr, list, vptr);
            makeEmpty(arrptr, vptr, &list);
            displayBoth(arrptr, list, vptr);
        }
    }

    return 0;
}

void initVirtualSpace(Vheap vptr)
{
	int idx;

	for (idx = limit-1; idx > -1; idx--){
		vptr->nodes[idx].next = idx-1;
	}
    vptr->avail = limit-1;
}

void enqueueArr(Circ arrptr, char x)
{
	arrptr->rear = (arrptr->rear+1)%limit;
	arrptr->elem[arrptr->rear] = x;
}

int isFull(Circ arrptr)
{
	return (arrptr->front == (arrptr->rear+2)%limit) ? 1 : 0;
}

int isEmpty(Circ arrptr)
{
	return (arrptr->front == (arrptr->rear+1)%limit) ? 1 : 0;
}

char dequeueArr(Circ arrptr)
{	
	char retval;

    retval = arrptr->elem[arrptr->front];
    arrptr->front = (arrptr->front+1)%limit;

	return retval;
}

void transferVSpace(Circ arrptr, Vheap vptr, int *listPtr)
{
	char item = dequeueArr(arrptr);

    *listPtr = allocSpace(vptr);
    
    if (*listPtr != -1){
        vptr->nodes[*listPtr].elem = item;
    }
}

int allocSpace(Vheap vptr)
{
	int freendx;

	if (vptr->avail != -1){
		freendx = vptr->avail;
		vptr->avail = vptr->nodes[freendx].next;
	} else {
		freendx = -1;
	}
	
	return freendx;
}

void makeEmpty(Circ arrptr, Vheap vptr, int *listPtr)
{
	for ( ; isEmpty(arrptr) != 1; transferVSpace(arrptr, vptr, listPtr)){
        listPtr = &vptr->nodes[*listPtr].next;
        *listPtr = -1;
    }
}

void makeFull(Circ arrptr)
{
	char idx;

	for (idx = 'A'; isFull(arrptr) != 1; enqueueArr(arrptr, idx), idx++){}
}

void displayBoth(Circ arrptr, int list, Vheap vptr)
{
    printf("\nContent of the circular array:\n");
    for ( ; arrptr->front != (arrptr->rear+1)%limit; arrptr->front = (arrptr->front+1)%limit){
        printf("%c ", arrptr->elem[arrptr->front]);
    }
    arrptr->front = 0;
    printf("\nContent of the cursor list:\n");
    printf("%d", list);
    for ( ; list != -1; list = vptr->nodes[list].next){
        printf("%c ", vptr->nodes[list].elem);
    }
}