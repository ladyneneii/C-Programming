#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    char FN[32], MI, LN[32];
} Nametype;

typedef struct {
    Nametype name[MAX];
    int count;
} Recordtype;

Recordtype *createList();
void initList(Recordtype *records);
void populateList(Recordtype *records);
void displayList(Recordtype *records);

int main()
{
    Recordtype *records = createList();
    initList(records);
    populateList(records);
    displayList(records);

    return 0;
}

Recordtype *createList()
{
    Recordtype *recordPtr = (Recordtype *)malloc(sizeof(Recordtype));

    return recordPtr;
}

void initList(Recordtype *records)
{
    records->count = 3;
}

void populateList(Recordtype *records)
{
    int i;

    for (i = 0; i < records->count; i++){
        printf("Enter last name: \n");
        scanf("%s", records->name[i].LN);
        printf("Enter first name: \n");
        scanf("%s", records->name[i].FN);
        printf("Enter middle initial: \n");
        scanf(" %c", &records->name[i].MI);
    }
}

void displayList(Recordtype *records)
{
    int i;

    for (i = 0; i < records->count; i++){
        printf("%s, %s %c\n", records->name[i].LN, records->name[i].FN, records->name[i].MI);
        printf("\n");
    }
}