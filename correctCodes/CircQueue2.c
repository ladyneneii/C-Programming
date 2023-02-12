#include <stdio.h>
#define size 8

typedef struct {
 	char Elem[size];
 	int front, rear, ctr;
} CircList;

void initq(CircList *q);
void enqueue(CircList *q, char x);
void displayq(CircList queue);
int fullq(CircList *q);
void dequeue(CircList *q);
int emptyq(CircList *q);

int main()
{
	CircList queue;

	initq(&queue);
	enqueue(&queue, 'b');
	enqueue(&queue, 'u');
	enqueue(&queue, 's');
	enqueue(&queue, 's');
	enqueue(&queue, 'y');
    enqueue(&queue, 'b');
	enqueue(&queue, 'u');
	enqueue(&queue, 's');
	enqueue(&queue, 's');
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
    dequeue(&queue);
    displayq(queue);

	return 0;
}

void initq(CircList *q)
{
	q->front = 1;
	q->rear = 0;
	q->ctr = 0;
}

void enqueue(CircList *q, char x)
{
	if (fullq(q) != 1){
		q->ctr++;
		q->rear = (q->rear+1)%size;
		q->Elem[q->rear] = x;
	} else {
		printf("\nQueue is already full.\n");
	}
}

int fullq(CircList *q)
{
	return (q->ctr == size) ? 1 : 0;
}

void displayq(CircList queue)
{
	int idx;

	printf("\nContent of queue:\n");
	if (queue.ctr > 0){
		for (idx = queue.front; idx != queue.rear; idx = (idx+1)%size){
			printf("queue.Elem[%d] = '%c';\n", idx, queue.Elem[idx]);
		}
        printf("queue.Elem[%d] = '%c';\n", queue.rear, queue.Elem[queue.rear]);
	} else {
		printf("\nQueue is empty.\n");
	}
	printf("queue.front = %d;\n", queue.front);
	printf("queue.rear = %d;\n", queue.rear);
    printf("queue.ctr = %d;\n", queue.ctr);
}

void dequeue(CircList *q)
{
	if (emptyq(q) != 1){
		q->ctr--;
		q->front = (q->front+1)%size;
	} else {
        printf("\nQueue is already empty.\n");
    }
}

int emptyq(CircList *q)
{
	return (q->ctr == 0) ? 1 : 0;
}