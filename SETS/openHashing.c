#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct cell {
	int elem;
	struct cell *next;
} *Cell;

typedef Cell Dictionary[MAX];

typedef enum {TRUE, FALSE} Boolean;

Dictionary *createDict(Cell head);
void initialize(Dictionary D);
void insertList(Cell *head, int num);
int Hash(int num);
Boolean isMember(int num, Dictionary D);
void deleteDict(Cell head, Dictionary *Dptr);
void displayList(Cell head);
void displaySet(Dictionary D);

int main()
{	
	Cell head = NULL;

	insertList(&head, 14);
	insertList(&head, 25);
	insertList(&head, 14);
    insertList(&head, 10);
	insertList(&head, 96);
	insertList(&head, 66);
    insertList(&head, 0);
	insertList(&head, 25);
	insertList(&head, 85);
    insertList(&head, 4);
	insertList(&head, 104);
	insertList(&head, 7);
    displayList(head);

	Dictionary *Dptr = createDict(head);

    displaySet(*Dptr);

	return 0;
}

Dictionary *createDict(Cell head)
{
	Dictionary *Dptr = (Dictionary *)malloc(sizeof(Dictionary));

	if (Dptr != NULL){
		initialize(*Dptr);
	
		int group;
		Cell *trav, temp;

		for ( ; head != NULL; head = head->next){
            group = Hash(head->elem);
			for (trav = (*Dptr)+group; *trav != NULL && (*trav)->elem < head->elem; trav = &(*trav)->next){}
			if (*trav == NULL || (*trav)->elem != head->elem){
				temp = (Cell)malloc(sizeof(struct cell));
				if (temp != NULL){
					temp->elem = head->elem;
					temp->next = *trav;
					*trav = temp;
				}
			}
		}
	}

	return Dptr;
}

void initialize(Dictionary D)
{
	int idx;

	for (idx = 0; idx < MAX; idx++){
		D[idx] = NULL;
	}
}

void insertList(Cell *head, int num)
{
	Cell temp = (Cell)malloc(sizeof(struct cell));

	if (temp != NULL){
		temp->elem = num;
		temp->next = *head;
		*head = temp;
	}
}

int Hash(int num)
{
	return num % 10;
}

Boolean isMember(int num, Dictionary D)
{
	int group = Hash(num);
	Cell trav;

	for (trav = D[group]; trav != NULL && trav->elem != num; trav = trav->next){}

	return (trav == NULL) ? FALSE : TRUE;
}

void deleteDict(Cell head, Dictionary *Dptr)
{
	int group;
	Cell *trav, temp;

	for ( ; head != NULL; head = head->next){
		group = Hash(head->elem);
		for (trav = (*Dptr)+group; *trav != NULL && (*trav)->elem != head->elem; trav = &(*trav)->next){}
		if (*trav != NULL){
			temp = *trav;
			*trav = (*trav)->next;
			free(temp);
		}
	}
}

void displayList(Cell head)
{
    for ( ; head != NULL; head = head->next){
        printf("%d ", head->elem);
    }
}

void displaySet(Dictionary D)
{
    int idx;
    Cell trav;

    for (idx = 0; idx < MAX; idx++){
        printf("\nD[%d] = ", idx);
        for (trav = D[idx]; trav != NULL; trav = trav->next){
            printf("%d ", trav->elem);
        }
    }
}
