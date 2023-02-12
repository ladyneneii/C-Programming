#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct node {
    struct {
        char elem;
        int link;
    } nodes[max];
    int avail;
} *VS;

typedef struct {
    int front, rear;
} Queue;

void enqueue(Queue *qptr, VS vptr, char x);
void dequeue (Queue *qptr, VS vptr);
void initialise(VS vsptr);
void display(VS vsptr, Queue q);

int main()
{
    Queue Q = {-1, -1};
    VS vs = (VS)malloc(sizeof(struct node));

    initialise(vs);
    enqueue(&Q, vs, 'I');
    enqueue(&Q, vs, 'A');
    enqueue(&Q, vs, 'M');
    enqueue(&Q, vs, 'S');
    enqueue(&Q, vs, 'O');
    enqueue(&Q, vs, 'G');
    enqueue(&Q, vs, 'A');
    enqueue(&Q, vs, 'Y');
    display(vs, Q);
    printf("\nQ.front = %d; Q.rear = %d\n", Q.front, Q.rear);
    dequeue(&Q, vs);
    dequeue(&Q, vs);
    dequeue(&Q, vs);
    display(vs, Q);
    printf("\nQ.front = %d; Q.rear = %d\n", Q.front, Q.rear);
    dequeue(&Q, vs);
    dequeue(&Q, vs);
    dequeue(&Q, vs);
    dequeue(&Q, vs);
    dequeue(&Q, vs);
    dequeue(&Q, vs);
    dequeue(&Q, vs);
    display(vs, Q);
    printf("\nQ.front = %d; Q.rear = %d\n", Q.front, Q.rear);

    return 0;
}

void initialise(VS vsptr)
{
	int idx;

	for (idx = max-1; idx > -1; idx--){
		vsptr->nodes[idx].link = idx-1;
	}
	vsptr->avail = max-1;
}

void enqueue(Queue *qptr, VS vptr, char x)
{
	int *trav, count = 0;

	for (trav = &qptr->rear; *trav != -1; trav = &vptr->nodes[*trav].link, count++){}
	*trav = vptr->avail;
	if (*trav != -1){
		vptr->avail = vptr->nodes[*trav].link;
		vptr->nodes[*trav].elem = x;
		vptr->nodes[*trav].link = -1;	
		qptr->rear = *trav;
		if (count == 0){
			qptr->front = *trav;
		}
	}
}

void dequeue (Queue *qptr, VS vptr)
{
	int temp = qptr->front;

	if (temp != -1){
		qptr->front = vptr->nodes[temp].link;
		vptr->nodes[temp].link = vptr->avail;
		vptr->avail = temp;
		if (qptr->front == -1){
			qptr->rear = -1;
		}
	} else {
		printf("\nQueue is already empty.\n");
	}
}

void display(VS vsptr, Queue q)
{
    printf("\n");
    for ( ; q.front != -1; q.front = vsptr->nodes[q.front].link){
        printf("%c ", vsptr->nodes[q.front].elem);
    }
    printf("\n");
}