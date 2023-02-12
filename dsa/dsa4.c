#include <stdio.h>
#include <stdlib.h>
#define SIZE 30

typedef struct {
    char FName[32];
    char Mi;
    char LName[32];
} Nametype;

typedef struct {
    Nametype name;
    int yearLevel;
} Infotype;

typedef struct {
    Infotype *records;
    int count;
} Classtype;

void initList(Classtype *list);
void populateList(Classtype *list);
void getYearLevel(Infotype *list);
void displayList(Classtype *list);

int main()
{
    Classtype list = {
        (Infotype *)malloc(SIZE*sizeof(Infotype)),
        SIZE
    };

    initList(&list);
    populateList(&list);
    displayList(&list);

    return 0;
}

void initList(Classtype *list)
{
    printf("Enter number of students:\n");
    scanf("%d", &list->count);
}

void populateList(Classtype *list)
{
    int idx;

    for (idx = 0; idx < list->count; idx++){
        printf("Enter student's last name:\n");
        scanf("%s", list->records[idx].name.LName);
        printf("Enter student's first name:\n");
        scanf("%s", list->records[idx].name.FName);
        printf("Enter student's middle initial:\n");
        scanf(" %c", &list->records[idx].name.Mi);
        getYearLevel(list->records+idx);
    }
}

void getYearLevel(Infotype *list)
{
    printf("Enter year level:\n");
    scanf("%d", &list->yearLevel);
}

void displayList(Classtype *list)
{
    int idx;

    for (idx = 0; idx < list->count; idx++){
        printf("%s, %s %c\n", list->records[idx].name.LName, list->records[idx].name.FName, list->records[idx].name.Mi);
        printf("%d\n\n", list->records[idx].yearLevel);
    }
}

int x, y, temp, small;

for (x = 0; x < count-1; x++){
    
}