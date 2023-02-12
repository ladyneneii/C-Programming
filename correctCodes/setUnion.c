#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} *SET;

SET unionSorted(SET A, SET B);
void displaySet(SET setSample);
// SET Union(SET A, SET B);

int main()
{
    SET setA = (SET)malloc(sizeof(struct node));

    //setA = NULL;

    
    setA->data = 'A';
    setA->link = (SET)malloc(sizeof(struct node));
    setA->link->data = 'C';
    setA->link->link = (SET)malloc(sizeof(struct node));
    setA->link->link->data = 'F';
    setA->link->link->link = (SET)malloc(sizeof(struct node));
    setA->link->link->link->data = 'G';
    setA->link->link->link->link = NULL;
    
    

    SET setB = (SET)malloc(sizeof(struct node));

    // setB = NULL;

    /*
    setB->data = 'A';
    setB->link = (SET)malloc(sizeof(struct node));
    setB->link->data = 'C';
    setB->link->link = (SET)malloc(sizeof(struct node));
    setB->link->link->data = 'F';
    setB->link->link->link = (SET)malloc(sizeof(struct node));
    setB->link->link->link->data = 'G';
    setB->link->link->link->link = NULL;
    */

    
    setB->data = 'B';
    setB->link = (SET)malloc(sizeof(struct node));
    setB->link->data = 'C';
    setB->link->link = (SET)malloc(sizeof(struct node));
    setB->link->link->data = 'D';
    setB->link->link->link = (SET)malloc(sizeof(struct node));
    setB->link->link->link->data = 'E';
    setB->link->link->link->link = (SET)malloc(sizeof(struct node));
    setB->link->link->link->link->data = 'F';
    setB->link->link->link->link->link = (SET)malloc(sizeof(struct node));
    setB->link->link->link->link->link->data = 'G';
    setB->link->link->link->link->link->link = (SET)malloc(sizeof(struct node));
    setB->link->link->link->link->link->link->data = 'I';
    setB->link->link->link->link->link->link->link = NULL;
    



    printf("\nContent of setA:\n");
    displaySet(setA);
    printf("\nContent of setB:\n");
    displaySet(setB);

    SET unionSet = unionSorted(setA, setB);

    printf("\nContent of unionSet:\n");
    displaySet(unionSet);

    return 0;
}

SET unionSorted(SET A, SET B)
{
	SET sortedUnion, *trav = &sortedUnion;
	
	for (*trav = NULL; A != NULL && B != NULL; trav = &(*trav)->link, *trav = NULL){ 
		*trav = (SET)malloc(sizeof(struct node));
		if (A->data < B->data){
			(*trav)->data = A->data;
			A = A->link;
		} else if (A->data > B->data){
			(*trav)->data = B->data;
			B = B->link;
		} else {
			(*trav)->data = A->data;
			A = A->link;
			B = B->link;
		}
	}
	if (A == NULL && B == NULL){

	} else if (A == NULL){
		for ( ; B != NULL; B = B->link){
			*trav = (SET)malloc(sizeof(struct node));
			(*trav)->data = B->data;
			trav = &(*trav)->link;
			*trav = NULL;
		}
	} else {
		for ( ; A != NULL; A = A->link){
			*trav = (SET)malloc(sizeof(struct node));
			(*trav)->data = A->data;
			trav = &(*trav)->link;
			*trav = NULL;
		}
	}

	return sortedUnion;
}


void displaySet(SET setSample)
{
    for ( ; setSample != NULL; setSample = setSample->link){
        printf("%c ", setSample->data);
    }
}

// not my code
/*
SET Union(SET A, SET B)
{
    SET out = NULL;
    SET *trav = &out;
    SET end = NULL;
    // while both A and B aren't equal to NULL
    while (A != B || A != NULL)
    {
        SET *least;
        if (A == NULL || B == NULL)
            // find available if one of A and B is NULL
            least = (A != NULL) ? &A : &B;
        else
            // otherwise find the least of them
            least = (A->data < B->data) ? &A : &B;
        // check duplicate
        if (end == NULL || end->data != (*least)->data)
        {
            // construct new set
            SET newSet = (SET)malloc(sizeof(struct node));
            newSet->data = (*least)->data;
            newSet->link = NULL;
            end = newSet;
            // update out set
            *trav = newSet;
            trav = &(newSet->link);
        }
        // traverse selected of either A and B
        *least = (*least)->link;
    }
    return out;
}
*/
