#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char FName[32];
    char Mi;
    char LName[32];
} Nametype;

typedef struct node {
    Nametype name;
    struct node *link;
} Celltype, *Cellptr;

Cellptr createList();
void displayList(Cellptr head);
void ascendList(Cellptr *head);
void insertList(Cellptr *head, char Fname[], char Mi, char LName[]);
void deleteList(Cellptr *head, char LName[]);

int main()
{
    Cellptr head = createList();
    displayList(head);
    ascendList(&head);
    printf("\n\n");
    displayList(head);
    insertList(&head, "Angela", 'D', "Anabhielat");
    printf("\n\n");
    displayList(head);
    deleteList(&head, "Piamonte");
    printf("\n\n");
    displayList(head);

    return 0;
}

Cellptr createList()
{
    Cellptr head = (Cellptr)malloc(sizeof(Celltype));

    strcpy(head->name.FName, "Kit");
    head->name.Mi = 'S';
    strcpy(head->name.LName, "Connor");
    head->link = (Cellptr)malloc(sizeof(Celltype));

    strcpy(head->link->name.FName, "Joe");
    head->link->name.Mi = 'W';
    strcpy(head->link->name.LName, "Locke");
    head->link->link = (Cellptr)malloc(sizeof(Celltype));

    strcpy(head->link->link->name.FName, "William");
    head->link->link->name.Mi = 'D';
    strcpy(head->link->link->name.LName, "Gao");
    head->link->link->link = (Cellptr)malloc(sizeof(Celltype));

    strcpy(head->link->link->link->name.FName, "Yasmin");
    head->link->link->link->name.Mi = 'T';
    strcpy(head->link->link->link->name.LName, "Finney");
    head->link->link->link->link = NULL;

    return head;
}

void displayList(Cellptr head)
{
    for ( ; head != NULL; head = head->link){
        printf("%s\n", head->name.LName);
        printf("%c\n", head->name.Mi);
        printf("%s\n\n", head->name.FName);
    }
}

void ascendList(Cellptr *head)
{
    Cellptr small, y;
    Nametype temp;

    for ( ; *head != NULL; head = &(*head)->link){
        small = *head;
        for (y = (*head)->link; y != NULL; y = y->link){
            if (strcmp(small->name.LName, y->name.LName) > 0){
                small = y;
            }
        }
        if (strcmp((*head)->name.LName, small->name.LName) > 0){
            temp = (*head)->name;
            (*head)->name = small->name;
            small->name = temp;
        }
    }
}

void insertList(Cellptr *head, char Fname[], char Mi, char LName[])
{
    Cellptr temp = (Cellptr)malloc(sizeof(Celltype));

    strcpy(temp->name.FName, Fname);
    temp->name.Mi = Mi;
    strcpy(temp->name.LName, LName);

    for ( ; strcmp((*head)->name.LName, LName) < 0; head = &(*head)->link){}
    temp->link = *head;
    *head = temp;
}

void deleteList(Cellptr *head, char LName[])
{
    Cellptr temp;

    for ( ; *head != NULL && strcmp((*head)->name.LName, LName) != 0; head = &(*head)->link){}
    if (*head != NULL){
        temp = *head;
        *head = (*head)->link;
        free(temp);
    } else {
        printf("Last name not found.\n");
    }
}