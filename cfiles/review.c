/*
#include <stdio.h>

LetterArrList delSuccess(LetterLinkList *head)
{
    LetterArrList newList;
    LetterLinkList temp;

    for (newList.count = 0; *head != NULL; ){
        if ((*head)->data.DeliveryStatus == SUCCESS){
            newList.letters[newList.count] = (*head)->data;
            newList.letters++;

            temp = *head;
            *head = (*head)->connect;
            free(temp);
        } else {
            *head = (*head)->connect;
        }
    }

    return newList;
}

int main()
{
    LetterLinkList head;

    LetterArrList successList = delSuccess(&head);
    return 0;
}
*/

/*
#include <stdio.h>
#include <string.h>

typedef struct {
    char LName[24];
    char FName[24];
    char Mi;
} nameType;

typedef struct {
    nameType name;
    int age;
    enum sexType {
        male, female, intersex, others
    } sexAtBirth;
} infoType;

typedef struct {
    infoType record[30];
    int count;
} list, *listPtr;

void descend(listPtr ptr);
void displayList(list people);

int main()
{
    list people = {
        {
            {{"Curativo", "Ernest", 'S'}, 19, male},
            {{"Piamonte", "Sean", 'T'}, 20, male},
            {{"Polis", "Lala", 'V'}, 15, intersex},
            {{"Croft", "Sebastian", 'D'}, 21, male},
            {{"Locke", "Joe", 'F'}, 18, others},
        }, 
        5
    };
    listPtr ptr = &people;

    displayList(people);
    printf("\n");

    descend(ptr);
    displayList(people);

    return 0;
}

void descend(listPtr ptr)
{
    int x, y, big;
    infoType temp;

    for(x = 0; x < ptr->count - 1; x++){
        big = x;
        for(y = x+1; y < ptr->count; y++){
            if (strcmp(ptr->record[big].name.FName, ptr->record[y].name.FName) < 0){
                big = y;
            }
        }
        if (strcmp(ptr->record[x].name.FName, ptr->record[big].name.FName) < 0){
            temp = ptr->record[x];
            ptr->record[x] = ptr->record[big];
            ptr->record[big] = temp;
        }
    }
}

void displayList(list people)
{
    int idx;

    for(idx = 0; idx < people.count; idx++){
        printf("%s, %s %c\n", people.record[idx].name.LName, people.record[idx].name.FName, people.record[idx].name.Mi);
        printf("%d\n", people.record[idx].age);
        if (people.record[idx].sexAtBirth == male){
            printf("male\n\n");
        } else if (people.record[idx].sexAtBirth == female){
            printf("female\n\n");
        } else if (people.record[idx].sexAtBirth == intersex){
            printf("intersex\n\n");
        } else {
            printf("others\n\n");
        }
    }
}
*/

/*
#include <stdio.h>

typedef struct {
    char FN[24];
    char LN[24];
    char Mi;
} nameType;

typedef struct {
    int age;
    char phoneNumber[15];
} otherInfoType;

struct student{
    nameType nameStudent;
    otherInfoType infoStudent;
};

struct prof{
    nameType nameProf;
    otherInfoType infoProf;
};

typedef struct {
    union studentOrProf {
        struct student Student;
        struct prof Prof;
    } person;
    int count;
} recordType;

int main()
{
    recordType BSCS = {
        {
            {
                {"Ernest", "Curativo", 'S'}, {19, "09473416245"}
            }
        },
        5
    }

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char LName[24];
    char FName[24];
    char Mi;
} nameType;

typedef struct {
    nameType name;
    int age;
    char degreeProgram[24];
} infoType;

typedef struct node {
    infoType personInfo;
    struct node *link;
} *llistPtr, personRecord;

void insertRecord(llistPtr *head, int pos);
void displayRecord(llistPtr head);
void deleteRecord(llistPtr *head, int pos);
void ascendRecord(llistPtr *head);

int main()
{
    llistPtr head = (llistPtr)malloc(sizeof(personRecord));

    strcpy(head->personInfo.name.LName, "Dalely");
    strcpy(head->personInfo.name.FName, "Tom");
    head->personInfo.name.Mi = 'M';
    head->personInfo.age = 31;
    strcpy(head->personInfo.degreeProgram, "Diving");

    head->link = (llistPtr)malloc(sizeof(personRecord));
    strcpy(head->link->personInfo.name.LName, "Croft");
    strcpy(head->link->personInfo.name.FName, "Sebastian");
    head->link->personInfo.name.Mi = 'F';
    head->link->personInfo.age = 20;
    strcpy(head->link->personInfo.degreeProgram, "Acting");

    head->link->link = (llistPtr)malloc(sizeof(personRecord));
    strcpy(head->link->link->personInfo.name.LName, "Locke");
    strcpy(head->link->link->personInfo.name.FName, "Joe");
    head->link->link->personInfo.name.Mi = 'D';
    head->link->link->personInfo.age = 18;
    strcpy(head->link->link->personInfo.degreeProgram, "Dancing");

    head->link->link->link = (llistPtr)malloc(sizeof(personRecord));
    strcpy(head->link->link->link->personInfo.name.LName, "Xu");
    strcpy(head->link->link->link->personInfo.name.FName, "Tao");
    head->link->link->link->personInfo.name.Mi = 'N';
    head->link->link->link->personInfo.age = 16;
    strcpy(head->link->link->link->personInfo.degreeProgram, "Talking");

    head->link->link->link->link = NULL;

    displayRecord(head);
    printf("\n\n\n");
    insertRecord(&head, 3);
    displayRecord(head);
    printf("\n\n\n");
    deleteRecord(&head, 1);
    displayRecord(head);
    printf("\n\n\n");
    ascendRecord(&head);
    displayRecord(head);
    printf("\n\n\n");

    return 0;
}

void insertRecord(llistPtr *head, int pos)
{
    int idx; 
    llistPtr temp;

    for (idx = 1; idx < pos; head = &((*head)->link), idx++){}
    temp = *head;
    *head = (llistPtr)malloc(sizeof(personRecord));
    strcpy((*head)->personInfo.name.LName, "Argent");
    strcpy((*head)->personInfo.name.FName, "Elle");
    (*head)->personInfo.name.Mi = 'K';
    (*head)->personInfo.age = 15;
    strcpy((*head)->personInfo.degreeProgram, "Drawing");

    (*head)->link = temp;
}

void displayRecord(llistPtr head)
{
    int idx; 

    for( ; head != NULL; head = head->link){
        printf("%s, %s %c\n", head->personInfo.name.LName, head->personInfo.name.FName, head->personInfo.name.Mi);
        printf("%d\n", head->personInfo.age);
        printf("%s\n\n", head->personInfo.degreeProgram);
    }
}

void deleteRecord(llistPtr *head, int pos)
{
    int idx; 
    llistPtr temp;

    for (idx = 1; idx < pos; head = &((*head)->link), idx++){}
    temp = *head;
    *head = (*head)->link;
    free(temp);
}

void ascendRecord(llistPtr *head)
{
    infoType temp;
    llistPtr small, y;

    for( ; *head != NULL; head = &(*head)->link){
        small = *head;
        for(y = (*head)->link; y != NULL; y = y->link){
            if(strcmp(small->personInfo.name.LName, y->personInfo.name.LName) > 0){
                small = y;
            }
        }
        if (strcmp((*head)->personInfo.name.LName, small->personInfo.name.LName) > 0){
            temp = (*head)->personInfo;
            (*head)->personInfo = small->personInfo;
            small->personInfo = temp;
        }
    }
}