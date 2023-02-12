#include <stdio.h>
#define MAX 10

typedef struct {
    char letter;
    int nextIdx;
} Datatype;

typedef struct {
    Datatype records[MAX];
    int avail;
} Recordtype;

Recordtype initRecord();
void visualiseRecord(Recordtype record);
void displayRecord(Recordtype record, int list);
void insertFront(Recordtype *record, int *list, char letter);
int allocSpace(Recordtype *record);
void deleteFront(Recordtype *record, int *list);

int main()
{
    Recordtype record1 = initRecord();
    int list1 = -1;

    printf("After initialising: \n");
    visualiseRecord(record1);
    displayRecord(record1, list1);
    insertFront(&record1, &list1, 'B');
    insertFront(&record1, &list1, 'I');
    insertFront(&record1, &list1, 'T');
    insertFront(&record1, &list1, 'C');
    insertFront(&record1, &list1, 'H');
    visualiseRecord(record1);
    displayRecord(record1, list1);
    deleteFront(&record1, &list1);

    return 0;
}

Recordtype initRecord()
{
    Recordtype record = {{}, 9};
    int idx;

    for (idx = MAX-1; idx > -1; idx--){
        record.records[idx].letter = -1;
        record.records[idx].nextIdx = idx-1;
    }

    return record;
}

void visualiseRecord(Recordtype record)
{
    int idx;

    printf("%15s | %15s | %15s\n", "INDEX", "LETTER", "NEXTIDX");
    for (idx = 0; idx < MAX; idx++){
        printf("%15d | %15c | %15d\n", idx, record.records[idx].letter, record.records[idx].nextIdx);
    }
}

void displayRecord(Recordtype record, int list)
{
    int idx; 

    printf("{");
    for (idx = list; list != -1; list = record.records[list].nextIdx){
        printf("%c ", record.records[list].letter);
    }
    printf("}\n");

    printf("Current available space: %d\n", record.avail); 
}

void insertFront(Recordtype *record, int *list, char letter)
{
    int space = allocSpace(record); 

    if (space != -1){
        record->records[space].letter = letter;
        record->records[space].nextIdx = *list;
        *list = space;
    } else {
        printf("Space is full.\n");
    }
}

int allocSpace(Recordtype *record)
{
    int avail = record->avail;
    
    if (avail != -1){
        record->avail = record->records[avail].nextIdx;
    } else {
        printf("Space is full.\n");
    }
    
    return avail;
}

void deleteFront(Recordtype *record, int *list)
{
    // delete second to the front

    record->records[(*list)+1].letter = -1;
    record->avail = (*list)+1;
    record->records[list].nextIdx = (*list)+2; 
    record->records[(*list)+1].nextIdx = -1;
}