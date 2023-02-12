#include <stdio.h>
#define MAX 10
#include <string.h>

typedef struct {
    char LName[24], FName[24], MI;
} Nametype;

typedef struct {
    Nametype name[MAX];
    int count;
} Recordtype;

void display(Recordtype records);
void descend(Recordtype *records);
void insertSorted(Nametype person, Recordtype *records);
void deleteSorted(char LName[], Recordtype *records);

int main()
{
    Recordtype records = {
        {
            {"Curativo", "Ernest", 'S'},
            {"Sagun", "Neil", 'T'},
            {"Besanez", "Reene", 'D'},
            {"Baynosa", "Gimari", 'F'},
            {"Borbajo", "Marc", 'G'}
        },
        5
    };
    Nametype person = {"Albino", "Adrian", 'J'};

    printf("Original list: \n");
    display(records);
    printf("\nList after descending: \n");
    descend(&records);
    display(records);
    printf("\nList after inserting person: \n");
    insertSorted(person, &records);
    display(records);
    printf("\nList after deleting Borbajo: \n");
    deleteSorted("Borbaj", &records);
    display(records);

    return 0;
}

void display(Recordtype records)
{
    int x;

    for (x = 0; x < records.count; x++){
        printf("%s, %s %c\n", records.name[x].LName, records.name[x].FName, records.name[x].MI);
    }
}

void descend(Recordtype *records)
{
    int x, y;
    Nametype temp;

    for (x = 0; x < records->count-1; x++){
        for (y = x; y > -1 && strcmp(records->name[y].LName, records->name[y+1].LName) < 0; y--){
            temp = records->name[y];
            records->name[y] = records->name[y+1];
            records->name[y+1] = temp;
        }
    }
}

void insertSorted(Nametype person, Recordtype *records)
{
    int idx, idx2;
    
    for (idx = 0; idx < records->count && strcmp(records->name[idx].LName, person.LName) > 0; idx++){}
    records->count++;
    for (idx2 = records->count-1; idx2 > idx; idx2--){
        records->name[idx2] = records->name[idx2-1];
    }
    records->name[idx] = person;
}

void deleteSorted(char LName[], Recordtype *records)
{
    int idx, idx2;

    for (idx = 0; idx < records->count && strcmp(LName, records->name[idx].LName) != 0; idx++){}
    if (strcmp(LName, records->name[idx].LName) == 0){
        records->count--;
        for (idx2 = idx; idx2 < records->count; idx2++){
            records->name[idx2] = records->name[idx2+1];
        }
    } else {
        printf("Last name not on the list.\n");
    }
}