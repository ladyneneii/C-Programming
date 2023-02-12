#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char LName[24], FName[24], Mi;
} Nametype;

typedef struct {
    Nametype *names;
    int max, count;
} Recordtype;

Recordtype *createRecords();
void displayRecords(Recordtype *records);
void descendRecords(Recordtype *records);
void insertRecord(Recordtype *records);

int main()
{
    Recordtype *records = createRecords();
    displayRecords(records);
    descendRecords(records);
    displayRecords(records);
    insertRecord(records);
    displayRecords(records);

    return 0;
}

Recordtype *createRecords()
{
    Recordtype *records = (Recordtype*)malloc(sizeof(Recordtype));

    records->max = 3;
    records->count = 3;
    records->names = (Nametype*)malloc(3*sizeof(Nametype));
    strcpy(records->names[0].LName, "Connor");
    strcpy(records->names[0].FName, "Kit");
    records->names[0].Mi = 'S';
    strcpy(records->names[1].LName, "Locke");
    strcpy(records->names[1].FName, "Joe");
    records->names[1].Mi = 'W';
    strcpy(records->names[2].LName, "Croft");
    strcpy(records->names[2].FName, "Sebastian");
    records->names[2].Mi = 'T';

    return records;
}

void displayRecords(Recordtype *records)
{
    int idx; 

    for(idx = 0; idx < records->count; idx++){
        printf("%s, %s %c\n", records->names[idx].LName, records->names[idx].FName, records->names[idx].Mi);
    }
    printf("\n\n");
}

void descendRecords(Recordtype *records)
{
    int x, y;
    Nametype temp;

    for(x = 0; x < records->count-1; x++){
        for(y = x; y > -1 && strcmp(records->names[y].LName, records->names[y+1].LName) < 0; y--){
            temp = records->names[y];
            records->names[y] = records->names[y+1];
            records->names[y+1] = temp;
        }
    }
}

void insertRecord(Recordtype *records)
{
    Nametype newName = {"Gao", "William", 'G'};
    int idx, idx2;

    records->count++;
    records->max = records->max*2;
    records->names = (Nametype *)realloc(records->names, records->max*sizeof(Nametype));
    for (idx = 0; strcmp(records->names[idx].LName, newName.LName) > 0; idx++){}
    for (idx2 = records->count-1; idx2 > idx; idx2--){
        records->names[idx2] = records->names[idx2-1];
    }
    records->names[idx] = newName;
}

