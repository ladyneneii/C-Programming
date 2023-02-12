#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char elem;
	struct node *prev, *next;
} *LinkList;

void initList(LinkList *head);
void enqueue(LinkList *head, char elem);
void displayq(LinkList head);
void dequeue(LinkList *head);

int main()
{
	LinkList head;

	initList(&head);
	enqueue(&head, 'k');
	enqueue(&head, 'w');
	enqueue(&head, 'e');
	enqueue(&head, 'e');
	enqueue(&head, 'n');
	displayq(head);
	dequeue(&head);
    dequeue(&head);
    displayq(head);
    dequeue(&head);
    dequeue(&head);
    dequeue(&head);
	displayq(head);
    printf("%p", head);

	return 0;
}

void initList(LinkList *head)
{
	*head = NULL;
}

void enqueue(LinkList *head, char elem)
{
	LinkList temp = (LinkList)malloc(sizeof(struct node));

	temp->elem = elem;
	if (*head != NULL){
		if ((*head)->next != NULL){
			temp->next = *head;
			temp->prev = (*head)->prev;
			(*head)->prev->next = temp;
			(*head)->prev = temp;
		} else {
			temp->next = *head;
			(*head)->next = temp;
			(*head)->prev = temp;
			temp->prev = *head;
		}
	} else {
		temp->next = *head;
		*head = temp;
	}
}

void displayq(LinkList head)
{
	LinkList trav;
	int count = 0;

	printf("\nTravelling forward:\n");
	for (trav = head; count < 1; ){
		printf("%c ", trav->elem);
        trav = trav->next;
        if (trav == head){
            count++;
        }
	}
	printf("\nTravelling backward:\n");
	for (trav = head = trav->prev; count > 0; ){
		printf("%c ", trav->elem);
        trav = trav->prev;
        if (trav == head){
            count--;
        }
	}
}

void dequeue(LinkList *head)
{
	LinkList temp;

	if ((*head != NULL){
		if ((*head)->next != NULL){
			temp = (*head)->prev;
			temp->prev->next = *head;
			(*head)->prev = temp->prev;
		} else {
			temp = *head;
			*head = NULL;
		}
		free(temp);
	} else {
		printf("\nQueue is already empty.\n");
	}
}