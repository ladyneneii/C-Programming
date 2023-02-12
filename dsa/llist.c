#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} *linkList;

void insertSorted(linkList *head, char elem);
void displayList(linkList head);
void delElem(linkList *head, char elem);
void insertLast(linkList *head, char elem);

int main()
{
    linkList head = (linkList)malloc(sizeof(struct node));
    
    head->data = 'a';
    head->link = (linkList)malloc(sizeof(struct node));
    head->link->data = 'b';
    head->link->link = (linkList)malloc(sizeof(struct node));
    head->link->link->data = 'b';
    head->link->link->link = (linkList)malloc(sizeof(struct node));
    head->link->link->link->data = 'e';
    head->link->link->link->link = (linkList)malloc(sizeof(struct node));
    head->link->link->link->link->data = 'f';
    head->link->link->link->link->link = (linkList)malloc(sizeof(struct node));
    head->link->link->link->link->link->data = 'g';
    head->link->link->link->link->link->link = (linkList)malloc(sizeof(struct node));
    head->link->link->link->link->link->link->data = 'h';
    head->link->link->link->link->link->link->link = NULL;

    printf("\nOriginal list:\n");
    displayList(head);
    printf("\nList after inserting element:\n");
    insertSorted(&head, '1');
    displayList(head);
    printf("\nList after deleting element:\n");
    delElem(&head, 'b');
    displayList(head);

    return 0;
}

void displayList(linkList head)
{
    for ( ; head != NULL; head = head->link){
        printf("%c", head->data);
    }
}

void delElem(linkList *head, char elem)
{
    linkList temp;

    for ( ; *head != NULL; ){
        if ((*head)->data == elem){
            temp = *head;
            *head = (*head)->link;
            free(temp);
        } else {
            head = &(*head)->link;
        }
    }
}

void insertSorted(linkList *head, char elem)
{
    linkList temp = (linkList)malloc(sizeof(struct node));
    
    temp->data = elem;
    temp->link = NULL;

    for ( ; *head != NULL && elem > (*head)->data; head = &(*head)->link){}
    if (*head == NULL){
        *head = temp;
    } else if ((*head)->data > elem){
        temp->link = *head;
        *head = temp;
    } else {
        printf("Element to be inserted already exists on the list.\n");
    }
}