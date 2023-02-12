// code of a queue implemented using a circular array with one cell sacrificed.
#include <stdio.h>
#define size 8

typedef struct {
	char Elem[size];
	int front, rear;
} CircList;

void initQ(CircList *q);
void enqueue(CircList *q, char x);
int fullq(CircList *q);
void displayq(CircList queue);
void dequeue(CircList *q);
int emptyq(CircList *q);

int main()
{
	CircList queue;

	initQ(&queue);
	enqueue(&queue, 's');
	enqueue(&queue, 'l');
	enqueue(&queue, 'a');
	enqueue(&queue, 'y');
    enqueue(&queue, 's');
	enqueue(&queue, 'l');
	enqueue(&queue, 'a');
	enqueue(&queue, 'y');
	displayq(queue);
	dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
	displayq(queue);

	return 0;
}

void initQ(CircList *q)
{
	q->front = 1;
	q->rear = 0;
}

void enqueue(CircList *q, char x)
{
	if (fullq(q) != 1){
        q->rear = (q->rear+1)%size;
		q->Elem[q->rear] = x;
	} else {
		printf("\nQueue is already full.\n");
	}
}

int fullq(CircList *q)
{
	return ((q->rear+2)%size == q->front) ? 1 : 0;
}

void displayq(CircList queue)
{
	int idx;
	
	printf("\nContent of queue:\n");
    if ((queue.rear+1)%size != queue.front){
        for (idx = queue.front; idx != (queue.rear+1)%size; idx = (idx+1)%size){
		    printf("queue.Elem[%d] = '%c';\n", idx, queue.Elem[idx]);
	    }
    } else {
        printf("\nQueue is empty.\n");
    }
    printf("queue.front = %d;\n", queue.front);
    printf("queue.rear = %d;\n", queue.rear);
}

void dequeue(CircList *q)
{
	if (emptyq(q) != 1){
		q->front = (q->front+1)%size;
	} else {
		printf("\nQueue is already empty.\n");
	}
}

int emptyq(CircList *q)
{
	return ((q->rear+1)%size == q->front) ? 1 : 0;
}