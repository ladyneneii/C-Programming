#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char item;
    struct node *link;
} *List;

void displayList(List head);
void connectList(List *head, List head2);
void ascendList(List head);

int main()
{
    List head = (List)malloc(sizeof(struct node));

    head->item = 'B';
    head->link = (List)malloc(sizeof(struct node));
    head->link->item = 'U';
    head->link->link = NULL;

    List head2 = (List)malloc(sizeof(struct node));

    head2->item = 'S';
    head2->link = (List)malloc(sizeof(struct node));
    head2->link->item = 'S';
    head2->link->link = (List)malloc(sizeof(struct node));
    head2->link->link->item = 'Y';
    head2->link->link->link = NULL;

    displayList(head);
    displayList(head2);
    connectList(&head, head2);
    displayList(head);
    ascendList(head);
    displayList(head);

    return 0;
}

void displayList(List head)
{
    for ( ; head != NULL; head = head->link){
        printf("%c", head->item);
    }
    printf("\n");
}

void connectList(List *head, List head2)
{
    for ( ; *head != NULL; head = &(*head)->link){}
    *head = head2;
}

void ascendList(List head)
{
    List x, y, small;
    char temp;

    for (x = head; x != NULL; x = x->link){
        small = x;
        for (y = x->link; y != NULL; y = y->link){
            if (small->item > y->item){
                small = y;
            }
        }
        if (small->item < x->item){
            temp = small->item;
            small->item = x->item;
            x->item = temp;
        }
    }
}