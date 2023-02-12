#include <stdio.h>

struct node {
    int x, y;
    char z;
};

struct node S;

void getNode(struct node *T)
{
	scanf("%d", &T->x);
	scanf("%d", &T->y);
	scanf(" %c", &T->z);
}

void displayNode(struct node *T)
{
    printf("%d, %d, %c", T->x, T->y, T->z);
}

int main()
{
    getNode(&S);
    displayNode(&S);
}