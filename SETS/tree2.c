#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int node;

typedef struct cell {
	node mem;
	struct cell *sib;
} *Celltype;

typedef Celltype Header[MAX];

typedef struct {
	Header H;
	node Root;
} Tree;

void INITIALIZE(Tree *T);
void CREATE1(Celltype *v, node T1);
void CREATE2(Celltype *v, node T1, node T2);
void CREATE3(Celltype *v, node T1, node T2, node T3);
void display(Tree T);
node PARENT(node n, Tree T);
node LEFTMOST_CHILD(node n, Tree T);
node RIGHTMOST_CHILD(node n, Tree T);
node LEFT_SIBLING(node n, Tree T);
node RIGHT_SIBLING(node n, Tree T);

int main()
{
	Tree T;

	INITIALIZE(&T);
	// create root 5 with children 0, 6, 2
	CREATE3(T.H+5, 0, 6, 2);
    CREATE2(T.H+6, 3, 1);
    CREATE2(T.H+1, 4, 7);
    CREATE1(T.H+2, 8);
    display(T);
	printf("Parent of node 8: %d\n", PARENT(8, T));
	printf("Parent of node 5: %d\n", PARENT(5, T));
	printf("Parent of node 13: %d\n", PARENT(13, T));
	printf("Leftmost child of node 1: %d\n", LEFTMOST_CHILD(1, T));
	printf("Leftmost child of node 5: %d\n", LEFTMOST_CHILD(5, T));
	printf("Leftmost child of node 7: %d\n", LEFTMOST_CHILD(7, T));
	printf("Rightmost child of node 1: %d\n", RIGHTMOST_CHILD(1, T));
	printf("Rightmost child of node 5: %d\n", RIGHTMOST_CHILD(5, T));
	printf("Rightmost child of node 7: %d\n", RIGHTMOST_CHILD(7, T));
	printf("Left sibling of node 2: %d\n", LEFT_SIBLING(2, T));
	printf("Left sibling of node 1: %d\n", LEFT_SIBLING(1, T));
	printf("Left sibling of node 4: %d\n", LEFT_SIBLING(4, T));
	printf("Right sibling of node 0: %d\n", RIGHT_SIBLING(0, T));
	printf("Right sibling of node 4: %d\n", RIGHT_SIBLING(4, T));
	printf("Right sibling of node 2: %d\n", RIGHT_SIBLING(2, T));

	return 0;
}

void INITIALIZE(Tree *T)
{
	int idx;

	for (idx = 0; idx < MAX; idx++){
		T->H[idx] = NULL;
	}
	T->Root = 5;
}

void CREATE1(Celltype *v, int T1)
{
	Celltype trav;
	int idx;

	for (idx = 0; idx < 1; idx++){
		*v = (Celltype)malloc(sizeof(struct cell));
		if (*v != NULL){
            if (idx == 0){
                trav = *v;
            }
            v = &(*v)->sib;
		}
	}
	*v = NULL;
	trav->mem = T1;
}

void CREATE2(Celltype *v, int T1, int T2)
{
	Celltype trav;
	int idx;

	for (idx = 0; idx < 2; idx++){
		*v = (Celltype)malloc(sizeof(struct cell));
		if (*v != NULL){
            if (idx == 0){
                trav = *v;
            }
            v = &(*v)->sib;
		}
	}
	*v = NULL;
	trav->mem = T1;
	trav = trav->sib;
	trav->mem = T2;
}

void CREATE3(Celltype *v, node T1, node T2, node T3)
{
	Celltype trav;
	int idx;

	for (idx = 0; idx < 3; idx++){
		*v = (Celltype)malloc(sizeof(struct cell));
		if (*v != NULL){
            if (idx == 0){
                trav = *v;
            }
            v = &(*v)->sib;
		}
	}
	*v = NULL;
	trav->mem = T1;
	trav = trav->sib;
	trav->mem = T2;
	trav = trav->sib;
	trav->mem = T3;
}

void display(Tree T)
{
	int idx;
	Celltype trav;

	for (idx = 0; idx < MAX; idx++){
		printf("T.H[%d] = ", idx);
		for (trav = T.H[idx]; trav != NULL; trav = trav->sib){
			printf("%d ", trav->mem);
		}
		printf("\n");
	}
}

node PARENT(node n, Tree T)
{
	int idx, stopTrav, retVal;
	Celltype trav;

	if (n != T.Root){
		for (stopTrav = idx = 0; stopTrav == 0 && idx < MAX; idx++){
			for (trav = T.H[idx]; trav != NULL && trav->mem != n; trav = trav->sib){}
			if (trav != NULL && trav->mem == n){
				stopTrav++;
			}
		}
		retVal = stopTrav == 0 ? -1 : idx-1;
	} else {
		retVal = '^';
	}

	return retVal;
}

node LEFTMOST_CHILD(node n, Tree T)
{
	Celltype trav = T.H[n];

	return trav == NULL ? '^' : trav->mem;
}

node RIGHTMOST_CHILD(node n, Tree T)
{
	Celltype trav = T.H[n];

	if (trav != NULL){
		for ( ; trav->sib != NULL; trav = trav->sib){}
	}

	return trav == NULL ? '^' : trav->mem;
}

node LEFT_SIBLING(node n, Tree T)
{
	int idx, stopTrav, retVal;
	Celltype trav;

	for (stopTrav = idx = 0; stopTrav == 0 && idx < MAX; idx++){
		for (trav = T.H[idx]; trav != NULL && trav->mem != n; trav = trav->sib){}
		if (trav != NULL && trav->mem == n){
			stopTrav++;
		}
	}
	trav = T.H[idx-1];
	if (trav->sib != NULL && trav->mem != n){
		for ( ; trav->sib->mem != n; trav = trav->sib){}
	}
	retVal = trav->mem;

	return retVal;
}

node RIGHT_SIBLING(node n, Tree T)
{
	int idx, stopTrav, retVal;
	Celltype trav;

	for (stopTrav = idx = 0; stopTrav == 0 && idx < MAX; idx++){
		for (trav = T.H[idx]; trav != NULL && trav->mem != n; trav = trav->sib){}
		if (trav != NULL && trav->mem == n){
			stopTrav++;
		}
	}
	if (trav->sib != NULL){
		retVal = trav->sib->mem;
	} else {
		retVal = trav->mem;
	}

	return retVal;
}