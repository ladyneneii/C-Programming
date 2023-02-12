#include <stdio.h>
#include <stdlib.h>
#define MAX 30

typedef struct{
    char FName[32];
    char Mi;
    char LName[32];
} Nametype;

typedef struct{
    Nametype name;
    int age;
    char course[32];
} Infotype;

typedef struct{
    Infotype student[MAX];
    int count;
} Classtype;

void initList(int *num);
void populateList(Classtype *list);
void fillOutNametype(Nametype *nameInfo);
void fillOutInfotype(Infotype *studentInfo);
void displayRecords(Classtype Records);

int main()
{
    Classtype blockA;

    initList(&blockA.count);
    populateList(&blockA);
    displayRecords(blockA);
}

void initList(int *num)
{
    printf("Enter number of records: \n");
    scanf("%d", num);
}

void populateList(Classtype *list)
{
    int idx;

    for(idx = 0; idx < list->count; idx++){
        fillOutNametype(&list->student[idx].name);
        fillOutInfotype(list->student+idx);
        printf("\n");
    }
}

void fillOutNametype(Nametype *nameInfo)
{
    printf("Enter first name: \n");
    fgets(nameInfo->FName, 32, stdin);
    printf("Enter middle initial: \n");
    scanf(" %c", &nameInfo->Mi);
    printf("Enter last name: \n");
    fgets(nameInfo->LName, 32, stdin);
}

void fillOutInfotype(Infotype *studentInfo)
{
    printf("Enter age: \n");
    scanf("%d", &studentInfo->age);
    printf("Enter course: \n");
    fgets(studentInfo->course, 32, stdin);
}

void displayRecords(Classtype Records)
{
    int idx;

    for(idx = 0; idx < Records.count; idx++){
        printf("%s, %s %c\n", Records.student[idx].name.LName, Records.student[idx].name.FName, Records.student[idx].name.Mi);
        printf("%d years old\n", Records.student[idx].age);
        printf("%s\n\n", Records.student[idx].course);
    }
}