#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char elem;
	struct node *link;
} *SET;

SET differenceSorted(SET X, SET Y);
void enqueue(SET *trav, char elem);
void display(SET set);

int main()
{
	SET A = NULL, B = NULL;

	enqueue(&A, 'A');
    enqueue(&A, 'B');
    enqueue(&A, 'C');
    enqueue(&A, 'D');
    enqueue(&A, 'E');
    enqueue(&B, 'A');
    enqueue(&B, 'C');
    enqueue(&B, 'E');
    printf("\nContent of Set A:\n");
	display(A);
    printf("\nContent of Set A:\n");
    display(B);

    SET C = differenceSorted(A, B);
    printf("\nContent of Set C:\n");
    display(C);

	return 0;
}

void enqueue(SET *trav, char elem)
{
	for ( ; *trav != NULL; trav = &(*trav)->link){}
	*trav = (SET)malloc(sizeof(struct node));
	if (*trav != NULL){
		(*trav)->elem = elem;
		(*trav)->link = NULL;
	}
}

void display(SET set)
{
	for ( ; set != NULL; set = set->link){
		printf("%c ", set->elem);
	}
}

SET differenceSorted(SET X, SET Y)
{
	SET C = NULL, *cptr, ytrav;

	for (cptr = &C; X != NULL; X = X->link){
		for (ytrav = Y; ytrav != NULL && X->elem != ytrav->elem; ytrav = ytrav->link){}
		if (ytrav == NULL){
			*cptr = (SET)malloc(sizeof(struct node));
			(*cptr)->elem = X->elem;
			cptr = &(*cptr)->link;
			*cptr = NULL;
		}
	}

	return C;
}

/*
setUnion (Cursor-based) UNCHECKED

List unionSorted(List A, List B, VSpace *vs)
{
	List C, *trav = &C;

	while (A != -1 && B != -1){
		if (vs->avail != -1){
			*trav = vs->avail;
			vs->avail = vs->data[*trav].next
			if (vs->data[A].elem < vs->data[B].elem){
				vs->data[*trav].elem = vs->data[A].elem;
				A = vs->data[A].next;
			} else {
				vs->data[*trav].elem = vs->data[B].elem;
				B = vs->data[B].next;
				if (vs->data[A].elem == vs->data[B].elem){
					A = vs->data[A].next;
				}
			}
			trav = &vs->data[*trav].next
		}
	}
	if (A == -1){
		A = B;
	}
	for ( ; A != -1; A = vs->data[A].next){
		if (vs->avail != -1){
			*trav = vs->avail;
			vs->avail = vs->data[*trav].next
			vs->data[*trav].elem = vs->data[A].elem;
			trav = &vs->data[*trav].next
		}
	}
	*trav = -1;

	return C;
}
*/