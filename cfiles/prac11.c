#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *nextNum;
} * list;

struct node * createList();
void displayList(struct node *head);
void insertList(struct node **head, int pos);
void swapList(struct node **head, int pos);
// void ascendBubble(struct node **head);
void ascendSelection(struct node *head);
void deleteList(struct node **head, int pos);
void descendInsertion(struct node *head);

int main()
{
    struct node *head = createList();
    
    displayList(head);
    
    insertList(&head, 1);
    printf("\n\nAfter insertion\n\n");
    displayList(head);
    
    swapList(&head, 1);
    printf("\n\nAfter swapping\n\n");
    displayList(head);
    
    /*
    ascendBubble(&head);
    printf("\n\nAfter bubble ascending\n\n");
    displayList(head);
    */

    ascendSelection(head);
    printf("\n\nAfter bubble ascending\n\n");
    displayList(head);

    deleteList(&head, 3);
    printf("\n\nAfter deleting\n\n");
    displayList(head);

    descendInsertion(head);
    printf("\n\nAfter insertion descending\n\n");
    displayList(head);

    return 0;
}

struct node * createList()
{
    struct node *L = (struct node*)malloc(sizeof(struct node));
    L->num = 5;
    L->nextNum = (struct node*)malloc(sizeof(struct node));
    L->nextNum->num = 7;
    L->nextNum->nextNum = (struct node*)malloc(sizeof(struct node));
    L->nextNum->nextNum->num = 2;
    L->nextNum->nextNum->nextNum = (struct node*)malloc(sizeof(struct node));
    L->nextNum->nextNum->nextNum->num = 0;
    L->nextNum->nextNum->nextNum->nextNum = (struct node*)malloc(sizeof(struct node));
    L->nextNum->nextNum->nextNum->nextNum->num = 2;
    L->nextNum->nextNum->nextNum->nextNum->nextNum = NULL;

    return L;
}

void displayList(struct node *head)
{
    for( ; head != NULL; head = head->nextNum){
        printf("%d ", head->num);
    }
}

void insertList(struct node **head, int pos)
{
    int idx;
    struct node *temp;

    for(idx = 1; idx < pos; head = &(*head)->nextNum, idx++){}
    temp = *head;
    *head = (struct node*)malloc(sizeof(struct node));
    (*head)->num = 9;
    (*head)->nextNum = temp;
}

void swapList(struct node **head, int pos)
{
    int idx;
    struct node *temp, *temp2;

    for(idx = 1; idx < pos; head = &(*head)->nextNum, idx++){}
    temp = *head;
    *head = (*head)->nextNum;
    temp2 = (*head)->nextNum;
    (*head)->nextNum = temp;
    (*head)->nextNum->nextNum = temp2;
}

/*
void ascendBubble(struct node **head)
{
    struct node *outerLoop, *headptr = *head;
    int temp;

    for(outerLoop = *head; outerLoop != NULL; outerLoop = outerLoop->nextNum){
        for(*head = headptr; *head != NULL; head = &(*head)->nextNum){
            if((*head)->num > (*head)->nextNum->num){
                temp = (*head)->num;
                (*head)->num = (*head)->nextNum->num;
                (*head)->nextNum->num = temp;
            }
        }
    }
}
*/

void ascendSelection(struct node *head)
{
    struct node *outerLoop, *innerLoop;
    struct node *small;
    int temp;

    for(outerLoop = head; outerLoop != NULL; outerLoop = outerLoop->nextNum){
        small = outerLoop;
        for(innerLoop = outerLoop->nextNum; innerLoop != NULL; innerLoop = innerLoop->nextNum){
            if(small->num > innerLoop->num){
                small = innerLoop;
            }
        }
        if(outerLoop->num > small->num){
            temp = outerLoop->num;
            outerLoop->num = small->num;
            small->num = temp;
        }
    }
}

void deleteList(struct node **head, int pos)
{
    int idx;
    struct node *temp;

    for(idx = 1; idx < pos; head = &(*head)->nextNum, idx++){}
    temp = (*head)->nextNum;
    free(*head);
    *head = temp;
}

/*
void descendInsertion(struct node *head)
{
    int x, y;

    for(x = 0; x < count-1; x++){
        for(y = x; y > -1 && arr[y] < arr[y+1]; y--){
            temp - arr[y];
            arr[y] = arr[y-1];
            arr[y-1] = temp;
        }
    }

    struct node *outerLoop, *innerLoop;
    int temp;

    for(outerLoop = head; outerLoop != NULL; outerLoop = outerLoop->nextNum){
        for(innerLoop = outerLoop; y > -1 && innerLoop->num < innerLoop->nextNum->num; y--){
            temp = innerLoop->num;
            innerLoop->num; = innerLoop->nextNum->num;
            innerLoop->nextNum->num = temp;
        }
    }
}
*/
