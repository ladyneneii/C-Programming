#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int num;
	struct tree *lc, *rc;
} *bst;

void initialize(bst *tptr);
void insert(bst *tptr, int num);
void deleteLeaf(bst *tptr, int num);
void deleteInodeLeft(bst *tptr, int num);
void deleteInodeRight(bst *tptr, int num);
void display(bst t, int end);

int main()
{
	bst t;

	initialize(&t);
	insert(&t, 20);
	insert(&t, 26);
	insert(&t, 16);
	insert(&t, 22);
	insert(&t, 14);
	insert(&t, 23);
	insert(&t, 28);
	insert(&t, 21);
	insert(&t, 24);
	display(t, 21);
	display(t, 22);
	display(t, 14);
	display(t, 24);
	display(t, 23);
	deleteLeaf(&t, 23);
	display(t, 24);
	deleteInodeLeft(&t, 26);
	display(t, 22);
	display(t, 23);
	deleteInodeRight(&t, 20);
	display(t, 28);
    display(t, 14);

	return 0;
}

void initialize(bst *tptr)
{
	*tptr = NULL;
}

void insert(bst *tptr, int num)
{
	while (*tptr != NULL){
		tptr = (num > (*tptr)->num) ? &(*tptr)->rc : &(*tptr)->lc;
	}
	*tptr = (bst)malloc(sizeof(struct tree));
	if (*tptr != NULL){
		(*tptr)->num = num;
		(*tptr)->rc = (*tptr)->lc = NULL;
	}
}

void display(bst t, int end)
{
	int stop = 0;

    printf("Path to: %d\n", end);
	while (stop == 0 && t != NULL){
		printf("%d ", t->num);
		if (end != t->num){
			t = (end > t->num) ? t->rc: t->lc;
		} else {
			stop++;
		}
	}
	printf("\n\n");
}

void deleteLeaf(bst *tptr, int num)
{
	bst temp;

	while (num != (*tptr)->num){
		tptr = (num > (*tptr)->num) ? &(*tptr)->rc : &(*tptr)->lc;
	}
	temp = *tptr;
	*tptr = ((*tptr)->rc != NULL) ? (*tptr)->rc : (*tptr)->lc;
	free(temp);
}

void deleteInodeLeft(bst *tptr, int num)
{
	bst toReplace, temp;

	while (num != (*tptr)->num){
		tptr = (num > (*tptr)->num) ? &(*tptr)->rc : &(*tptr)->lc;
	}
	toReplace = *tptr;
	for (tptr = &(*tptr)->lc; (*tptr)->rc != NULL; tptr = &(*tptr)->rc){}
	toReplace->num = (*tptr)->num;
	temp = *tptr;
	*tptr = (*tptr)->lc;
	free(temp);
}

void deleteInodeRight(bst *tptr, int num)
{
	bst toReplace, temp;

	while (num != (*tptr)->num){
		tptr = (num > (*tptr)->num) ? &(*tptr)->rc : &(*tptr)->lc;
	}
	toReplace = *tptr;
	for (tptr = &(*tptr)->rc; (*tptr)->lc != NULL; tptr = &(*tptr)->lc){}
	toReplace->num = (*tptr)->num;
	temp = *tptr;
	*tptr = (*tptr)->rc;
	free(temp);
}

