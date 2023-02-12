#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char LName[32];
    char Mi;
    char FName[32];
} Nametype;

typedef struct{
    Nametype name;
    int age;
    char degreeProgram[32];
} Infotype;

typedef struct node{
    Infotype student;
    struct node * next;
} Nodetype, * Nodeptr;

Nodeptr createLinkedList();
void displayLinkedList(Nodeptr head);
void insertLinkedList(Nodeptr *head, char *LName, char Mi, char *FName, int age, char *degreeProgram);

int main()
{
    Nodeptr list = createLinkedList();

    displayLinkedList(list);
    insertLinkedList(&list, "Oseman", 'F', "Alice", 32, "Multimedia");
    printf("After insertion:\n\n\n");
    displayLinkedList(list);

    return 0;
}

Nodeptr createLinkedList()
{
    Nodeptr head = (Nodeptr)malloc(sizeof(Nodetype));
    strcpy(head->student.name.LName, "Connor");
    strcpy(head->student.name.FName, "Kit");
    head->student.name.Mi = 'O';
    head->student.age = 18;
    strcpy(head->student.degreeProgram, "BSIT");

    head->next = (Nodeptr)malloc(sizeof(Nodetype));
    strcpy(head->next->student.name.LName, "Croft");
    strcpy(head->next->student.name.FName, "Sebastian");
    head->next->student.name.Mi = 'E';
    head->next->student.age = 20;
    strcpy(head->next->student.degreeProgram, "BSCS");

    head->next->next = (Nodeptr)malloc(sizeof(Nodetype));
    strcpy(head->next->next->student.name.LName, "Gao");
    strcpy(head->next->next->student.name.FName, "William");
    head->next->next->student.name.Mi = 'B';
    head->next->next->student.age = 19;
    strcpy(head->next->next->student.degreeProgram, "BSArch");

    head->next->next->next = (Nodeptr)malloc(sizeof(Nodetype));
    strcpy(head->next->next->next->student.name.LName, "Locke");
    strcpy(head->next->next->next->student.name.FName, "Joe");
    head->next->next->next->student.name.Mi = 'D';
    head->next->next->next->student.age = 18;
    strcpy(head->next->next->next->student.degreeProgram, "BSIT");

    head->next->next->next->next = (Nodeptr)malloc(sizeof(Nodetype));
    strcpy(head->next->next->next->next->student.name.LName, "Rydings");
    strcpy(head->next->next->next->next->student.name.FName, "Edvin");
    head->next->next->next->next->student.name.Mi = 'L';
    head->next->next->next->next->student.age = 18;
    strcpy(head->next->next->next->next->student.degreeProgram, "MassCom");

    head->next->next->next->next->next = NULL;

    return head;
}

void displayLinkedList(Nodeptr head)
{
    for( ; head != NULL; head = head->next){
        printf("%s, %s %c\n", head->student.name.LName, head->student.name.FName, head->student.name.Mi);
        printf("%d\n", head->student.age);
        printf("%s\n\n", head->student.degreeProgram);
    }
}

void insertLinkedList(Nodeptr *head, char *LName, char Mi, char *FName, int age, char *degreeProgram)
{
    Nodeptr new = (Nodeptr)malloc(sizeof(Nodetype));
    strcpy(new->student.name.LName, LName);
    strcpy(new->student.name.FName, FName);
    new->student.name.Mi = Mi;
    new->student.age = age;
    strcpy(new->student.degreeProgram, degreeProgram);

    for( ; *head != NULL && strcmp(LName, (*head)->student.name.LName) > 0; head = &(*head)->next){}
    Nodeptr temp = *head;
    *head = new;
    new->next = temp;
}


