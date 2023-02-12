#include <stdio.h>
#include <string.h>
#define maximum 30

typedef struct {
	char LName[32], FName[32], MI;
} Nameinfo;

typedef struct {
	struct {
		Nameinfo name;
		int linkedCell;
	} Recordsinfo[maximum];
	int free;
} VirtualSpace;

typedef struct {
	int head, tail;
} queue;

void initialise(VirtualSpace *vs);
void enqueue(VirtualSpace *vs, queue *q, Nameinfo insertName);
int allocIndex(VirtualSpace *vs);
void displayqueue(VirtualSpace VS, queue q);
void dequeue(VirtualSpace *vs, queue *q);
void deallocIndex(int del, VirtualSpace *vs);
void deleteElem(VirtualSpace *VS, queue *q, char firstName[]);

int main()
{
	VirtualSpace VS;
	queue q = {-1, -1};

	initialise(&VS);

	Nameinfo insertName = {"Curativo", "Ernestina", 'S'};
	enqueue(&VS, &q, insertName);
	enqueue(&VS, &q, insertName);
	enqueue(&VS, &q, insertName);
	Nameinfo insertName2 = {"Curativo", "Ernest", 'S'};
	enqueue(&VS, &q, insertName2);
	displayqueue(VS, q);
	printf("value of head and tail: %d %d", q.head, q.tail);
	dequeue(&VS, &q);
	displayqueue(VS, q);
	printf("value of head and tail: %d %d", q.head, q.tail);
	deleteElem(&VS, &q, "Ernest");
	displayqueue(VS, q);
	printf("value of head and tail: %d %d", q.head, q.tail);
	
	return 0;
}

void initialise(VirtualSpace *vs)
{
	int idx;

	for (idx = maximum-1; idx > -1; idx--){
		vs->Recordsinfo[idx].linkedCell = idx-1;
	}
	vs->free = maximum-1;
}

void enqueue(VirtualSpace *vs, queue *q, Nameinfo insertName)
{
	int temp = allocIndex(vs);

	if (temp != -1){
		vs->Recordsinfo[temp].name = insertName;
		if (q->tail != -1){
			vs->Recordsinfo[temp].linkedCell = -1;
			vs->Recordsinfo[q->tail].linkedCell = temp;
			q->tail = temp;
		} else {
			q->tail = temp;
			q->head = temp;
		}
	}
}

int allocIndex(VirtualSpace *vs)
{
	int freeIndex;

	if (vs->free != -1){
		freeIndex = vs->free;
		vs->free = vs->Recordsinfo[freeIndex].linkedCell;
	} else {
		freeIndex = -1;
	}

	return freeIndex;
}

void displayqueue(VirtualSpace VS, queue q)
{
	printf("\nContent of queue:\n");
	for ( ; q.head != -1; q.head = VS.Recordsinfo[q.head].linkedCell){
		printf("%s, %s %c\n", VS.Recordsinfo[q.head].name.LName, VS.Recordsinfo[q.head].name.FName, VS.Recordsinfo[q.head].name.MI);
	}
}

void dequeue(VirtualSpace *vs, queue *q)
{
	int temp;
	
	temp = q->head;
	q->head = vs->Recordsinfo[q->head].linkedCell;
	deallocIndex(temp, vs);
}

void deallocIndex(int del, VirtualSpace *vs)
{
	vs->Recordsinfo[del].linkedCell = vs->free;
	vs->free = del;
}

void deleteElem(VirtualSpace *VS, queue *q, char firstName[])
{
	int *trav, temp;

	for (trav = &q->head ; *trav != -1 && strcmp(VS->Recordsinfo[*trav].name.FName, "Ernest") != 0; trav = &VS->Recordsinfo[*trav].linkedCell){}
	if (*trav != -1){
		temp = *trav;
		*trav = VS->Recordsinfo[*trav].linkedCell;
		deallocIndex(temp, VS);
	}
}
