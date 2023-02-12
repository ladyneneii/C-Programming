#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char elem;
    struct node *link;
} *LL;

typedef struct {
    LL start, end;
} Queue;

void enqueue(Queue *qptr, char elem);
void dequeue(Queue *qptr);
void display(Queue list);

int main()
{
    Queue head = {NULL, NULL};

    enqueue(&head, 'I');
    enqueue(&head, 'A');
    enqueue(&head, 'M');
    enqueue(&head, 'S');
    enqueue(&head, 'O');
    enqueue(&head, 'G');
    enqueue(&head, 'A');
    enqueue(&head, 'Y');
    display(head);
    dequeue(&head);
    dequeue(&head);
    dequeue(&head);
    dequeue(&head);
    display(head);
    dequeue(&head);
    dequeue(&head);
    dequeue(&head);
    dequeue(&head);
    dequeue(&head);
    dequeue(&head);
    display(head);

    return 0;
}

void enqueue(Queue *qptr, char elem)
{
	LL *trav;
    int count = 0;

	for (trav = &qptr->end; *trav != NULL; trav = &(*trav)->link, count++){}
	*trav = (LL)malloc(sizeof(struct node));
	(*trav)->elem = elem;
	(*trav)->link = NULL;
    qptr->end = *trav;
	if (count == 0){
		qptr->start = *trav; 
	}
}

void dequeue(Queue *qptr)
{
	LL temp = qptr->start;

    if (temp != NULL){
        qptr->start = qptr->start->link;
        free(temp);
        if (qptr->start == NULL){
            qptr->end = NULL;
        }
    } else {
        printf("\nQueue is already empty.\n");
    }
}

void display(Queue list)
{
    printf("\n");
    for ( ; list.start != NULL; list.start = list.start->link){
        printf("%c ", list.start->elem);
    }
    printf("\n");
}