#include <stdio.h>
#define size 20

typedef struct {
	int left, item, right;
} Node;

typedef struct {
	Node data[size];
	int avail;
} treeSpace;

void init(treeSpace *treeptr);
void insert(treeSpace *treeptr, int *head, int elem);
void display(treeSpace tree, int head);
void preorder(treeSpace tree, int head);
void postorder(treeSpace tree, int head);
void inorder(treeSpace tree, int head);
void deleteLeaf(treeSpace *treeptr, int *head, int elem);
void deleteInode1Child(treeSpace *treeptr, int *head, int elem);
void deleteInode2ChildOption1(treeSpace *treeptr, int *head, int elem);
void deleteInode2ChildOption2(treeSpace *treeptr, int *head, int elem);

int main()
{
	treeSpace treeCursor;
	int bst = -1;

	init(&treeCursor);
	insert(&treeCursor, &bst, 7);
	insert(&treeCursor, &bst, 6);
	insert(&treeCursor, &bst, 1);
	insert(&treeCursor, &bst, 8);
	insert(&treeCursor, &bst, 12);
	insert(&treeCursor, &bst, 3);
	insert(&treeCursor, &bst, 8);
	insert(&treeCursor, &bst, 6);
	insert(&treeCursor, &bst, 5);
	insert(&treeCursor, &bst, 2);
	insert(&treeCursor, &bst, 9);
	insert(&treeCursor, &bst, 10);
	insert(&treeCursor, &bst, 15);
	insert(&treeCursor, &bst, 13);
	insert(&treeCursor, &bst, 16);
	insert(&treeCursor, &bst, 4);
	display(treeCursor, bst);
	deleteLeaf(&treeCursor, &bst, 10);
	deleteLeaf(&treeCursor, &bst, 99);
	deleteLeaf(&treeCursor, &bst, 13);
	printf("\n\nAfter deleting 10, 99, and 13:\n");
	display(treeCursor, bst);
	deleteInode1Child(&treeCursor, &bst, 8);
	deleteInode1Child(&treeCursor, &bst, 90);
	printf("\n\nAfter deleting 8 and 90:\n");
	display(treeCursor, bst);
     insert(&treeCursor, &bst, 11);
	insert(&treeCursor, &bst, 14);
	printf("\n\nAfter inserting 11 and 14:\n");
	display(treeCursor, bst);
	deleteInode2ChildOption1(&treeCursor, &bst, 7);
	deleteInode2ChildOption1(&treeCursor, &bst, 15);
	printf("\n\nAfter deleting 7 and 15:\n");
	display(treeCursor, bst);
	deleteInode2ChildOption2(&treeCursor, &bst, 6);
	deleteInode2ChildOption2(&treeCursor, &bst, 3);
	printf("\n\nAfter deleting 6 and 3:\n");
	display(treeCursor, bst);
    insert(&treeCursor, &bst, -6);
	insert(&treeCursor, &bst, 15);
	insert(&treeCursor, &bst, 10);
    printf("\n\nAfter inserting -6, 15 and 10:\n");
	display(treeCursor, bst);

	return 0;
}

void init(treeSpace *treeptr)
{
	int idx;

	for (idx = size-1; idx > -1; idx--){
		treeptr->data[idx].left = treeptr->data[idx].right = idx-1;
	}
	treeptr->avail = size-1;
}

void insert(treeSpace *treeptr, int *head, int elem)
{
	while (*head != -1 && elem != treeptr->data[*head].item){
		head = (elem > treeptr->data[*head].item) ? &treeptr->data[*head].right : &treeptr->data[*head].left;
	}
	if (*head == -1){
		int temp;

		if (treeptr->avail != -1){
			temp = treeptr->avail;
			treeptr->avail = treeptr->data[temp].right;
			treeptr->data[temp].item = elem;
			treeptr->data[temp].left = treeptr->data[temp].right = -1;
			*head = temp;
		}
	}
}

void deleteLeaf(treeSpace *treeptr, int *head, int elem)
{
	while (*head != -1 && treeptr->data[*head].item != elem){
		head = (treeptr->data[*head].item < elem) ? &treeptr->data[*head].right : &treeptr->data[*head].left;
	}
	if (*head != -1){
		int temp;

		temp = *head;
		*head = -1;
		treeptr->data[temp].left = treeptr->data[temp].right = treeptr->avail;
		treeptr->avail = temp;
	}
}

void deleteInode1Child(treeSpace *treeptr, int *head, int elem)
{
	while (*head != -1 && treeptr->data[*head].item != elem){
		head = (treeptr->data[*head].item < elem) ? &treeptr->data[*head].right : &treeptr->data[*head].left;
	}
	if (*head != -1){
		int temp;

		temp = *head;
		*head = (treeptr->data[temp].left == -1) ? treeptr->data[temp].right : treeptr->data[*head].left;
		treeptr->data[temp].left = treeptr->data[temp].right = treeptr->avail;
		treeptr->avail = temp;
	}
}

void display(treeSpace tree, int head)
{
	printf("\n");
	preorder(tree, head);
	printf("\n");
	postorder(tree, head);
	printf("\n");
	inorder(tree, head);
}

void preorder(treeSpace tree, int head)
{
	if (head != -1){
		printf("%d ", tree.data[head].item);
		preorder(tree, tree.data[head].left);
		preorder(tree, tree.data[head].right);
	}
}

void postorder(treeSpace tree, int head)
{
	if (head != -1){
		postorder(tree, tree.data[head].left);
		postorder(tree, tree.data[head].right);
		printf("%d ", tree.data[head].item);
	}
}

void inorder(treeSpace tree, int head)
{
	if (head != -1){
		inorder(tree, tree.data[head].left);
		printf("%d ", tree.data[head].item);
		inorder(tree, tree.data[head].right);
	}
}

void deleteInode2ChildOption1(treeSpace *treeptr, int *head, int elem)
{
	while (*head != -1 && treeptr->data[*head].item != elem){
		head = (treeptr->data[*head].item < elem) ? &treeptr->data[*head].right : &treeptr->data[*head].left; 
	}
	if (*head != -1){
		int temp, tempVal, del;

		temp = *head;
		for (head = &treeptr->data[*head].left; treeptr->data[*head].right != -1; head = &treeptr->data[*head].right){}
		del = *head;
		tempVal = treeptr->data[del].item;
		treeptr->data[del].item = treeptr->data[temp].item;
		treeptr->data[temp].item = tempVal;
		*head = (treeptr->data[del].left == -1) ? treeptr->data[*head].right : treeptr->data[*head].left;
		treeptr->data[del].left = treeptr->data[del].right = treeptr->avail;
		treeptr->avail = del;
	}
}

void deleteInode2ChildOption2(treeSpace *treeptr, int *head, int elem)
{
	while (*head != -1 && treeptr->data[*head].item != elem){
		head = (treeptr->data[*head].item < elem) ? &treeptr->data[*head].right : &treeptr->data[*head].left;
	}
	if (*head != -1){
		int temp, tempVal, del;

		temp = *head;
		for (head = &treeptr->data[*head].right; treeptr->data[*head].left != -1; head = &treeptr->data[*head].left){}
		del = *head;
		tempVal = treeptr->data[del].item;
		treeptr->data[del].item = treeptr->data[temp].item;
		treeptr->data[temp].item = tempVal;
		*head = (treeptr->data[del].left == -1) ? treeptr->data[del].right : treeptr->data[del].left;
		treeptr->data[del].left = treeptr->data[del].right = treeptr->avail;
		treeptr->avail = del;
	}
}



