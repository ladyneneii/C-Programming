#include <stdio.h>
#include <stdlib.h>

typedef struct binary {
	struct binary *lc, *rc;
	int elem;
} *bst;

void init(bst *t);
void insert(bst *t, int num);
void preorder(bst t);
void postorder(bst t);
void inorder(bst t);

int main()
{
	bst tree;

	init(&tree);
	insert(&tree, 5);
	insert(&tree, 2);
	insert(&tree, 4);
	insert(&tree, 1);
	insert(&tree, -8);
	insert(&tree, -5);
	insert(&tree, 4);
	insert(&tree, 1);
	insert(&tree, 7);
	insert(&tree, -1);
	insert(&tree, 6);
	insert(&tree, -6);
	insert(&tree, -1);
	insert(&tree, -2);
	insert(&tree, 3);
    printf("\nPreorder:\n");
	preorder(tree);
    printf("\nPostorder:\n");
	postorder(tree);
    printf("\nInorder:\n");
	inorder(tree);

	return 0;
}

void init(bst *t)
{
	*t = NULL;
}

void insert(bst *t, int num)
{
	while (*t != NULL && (*t)->elem != num){
		t = (num > (*t)->elem) ? &(*t)->rc : &(*t)->lc;
	}
	if (*t == NULL){
		*t = (bst)malloc(sizeof(struct binary));
		if (*t != NULL){
			(*t)->elem = num;
			(*t)->lc = (*t)->rc = NULL;
		}
	}
}

void preorder(bst t)
{
	if (t != NULL){
		printf("%d ", t->elem);
		preorder(t->lc);
		if (t->rc != NULL){
			preorder(t->rc);
		}
	} 
}

void postorder(bst t)
{
	if (t != NULL){
		//if (t->lc != NULL){
			postorder(t->lc);
		//}
		//if (t->rc != NULL){
			postorder(t->rc);
		//}
		printf("%d ", t->elem);
	}

    // commented out lines are optional
}

void inorder(bst t)
{
	if (t != NULL){
		inorder(t->lc);
		printf("%d ", t->elem);
		inorder(t->rc);
	}
}