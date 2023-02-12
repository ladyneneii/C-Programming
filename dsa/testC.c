#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    char elem[SIZE];
    int front;
    int length;
} Queue;

void initializeQueue(Queue *qptr);
void enqueueIfUnique(Queue *qptr, char elem);
void displayQueue(Queue q);

int main()
{
    Queue Q;

    initializeQueue(&Q);
    enqueueIfUnique(&Q, 'a');
    enqueueIfUnique(&Q, 'b');
    enqueueIfUnique(&Q, 'c');
    enqueueIfUnique(&Q, 'd');
    enqueueIfUnique(&Q, 'b'); // not unique
    enqueueIfUnique(&Q, 'c'); // not unique
    enqueueIfUnique(&Q, 'e');
    enqueueIfUnique(&Q, 'f');
    enqueueIfUnique(&Q, 'g');
    enqueueIfUnique(&Q, 'h');
    enqueueIfUnique(&Q, 'i');
    enqueueIfUnique(&Q, 'j');
    enqueueIfUnique(&Q, 'k'); // queue is full
    enqueueIfUnique(&Q, 'l');
    enqueueIfUnique(&Q, 'm');
    enqueueIfUnique(&Q, 'n');
    displayQueue(Q);

    return 0;
}

void initializeQueue(Queue *qptr)
{
    qptr->length = 0;
    qptr->front = 8;
}

void enqueueIfUnique(Queue *qptr, char elem)
{
    int idx, count = 0;

    if (qptr->length < SIZE){
        // for (idx = qptr->front; count < qptr->length && qptr->elem[idx] != elem; idx = (idx+1)%SIZE, count++){}
        // if (count == qptr->length){
        //     qptr->elem[idx] = elem;
        //     qptr->length++; // I forgot to include this line in my answer code
        // }

        for (; qptr->elem[qptr->front] != elem; qptr->front = (qptr->front+1)%SIZE){}
    }
}

void displayQueue(Queue q)
{
    int idx, count = 0;

    for (idx = q.front; count < q.length; idx = (idx+1)%SIZE, count++){
        printf("elem[%d] = %c\n", idx, q.elem[idx]);
    }
}