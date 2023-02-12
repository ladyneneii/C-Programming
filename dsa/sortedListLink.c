#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} *linkList;

linkList createList();
void displayList(linkList head);
int changeLetter(linkList head, char A, char B);
void sortListDescend(linkList head);
void insertSorted(linkList *head, char elem);

int main()
{
    linkList head = createList();

    printf("Original list: ");
    displayList(head);
    int total = changeLetter(head, 'd', 'x');
    printf("\nChange d to 0: ");
    displayList(head);
    printf("\nNumber of changes: %d", total);
    sortListDescend(head);
    printf("\nSorted list in descending order: ");
    displayList(head);
    insertSorted(&head, 'a');
    printf("\nSorted list after inserting 4: ");
    displayList(head);
    

    return 0;
}

linkList createList()
{
    linkList head = (linkList)malloc(sizeof(struct node));
    
    head->data = 'w';
    head->link = (linkList)malloc(sizeof(struct node));
    head->link->data = 'h';
    head->link->link = (linkList)malloc(sizeof(struct node));
    head->link->link->data = 'd';
    head->link->link->link = (linkList)malloc(sizeof(struct node));
    head->link->link->link->data = 'd';
    head->link->link->link->link = (linkList)malloc(sizeof(struct node));
    head->link->link->link->link->data = 'd';
    head->link->link->link->link->link = (linkList)malloc(sizeof(struct node));
    head->link->link->link->link->link->data = 'r';
    head->link->link->link->link->link->link = (linkList)malloc(sizeof(struct node));
    head->link->link->link->link->link->link->data = 'e';
    head->link->link->link->link->link->link->link = NULL;

    return head;
}

void displayList(linkList head)
{
    for ( ; head != NULL; head = head->link){
        printf("%c", head->data);
    }
}

int changeLetter(linkList head, char A, char B)
{
    int total = 0;

    for ( ; head != NULL; head = head->link){
        if (head->data == A){
            total++;
            head->data = B;
        }
    }

    return total;
}

void sortListDescend(linkList head)
{
    linkList x, y, big;
    char temp;

    for (x = head; x != NULL; x = x->link){
        big = x;
        for (y = x->link; y != NULL; y = y->link){
            if (big->data < y->data){
                big = y;
            }
        }
        if (x->data < big->data){
            temp = x->data;
            x->data = big->data;
            big->data = temp;
        }
    }
}

void insertSorted(linkList *head, char elem)
{
    linkList temp = (linkList)malloc(sizeof(struct node));

    temp->data = elem;
    temp->link = NULL;
    for ( ; *head != NULL && (*head)->data > elem && (*head)->data != elem; head = &(*head)->link){}
    if ((*head)->data < elem){
        temp->link = *head;
        *head = temp;
    } else {
        printf("\nElement already exists on the list.");
    }
}
