#include <stdio.h>
#include <string.h>

typedef struct node {
    char LName[32];
    char FName[32];
    struct node *next;
} nameType;

typedef struct {
    nameType names[5];
    int count;
} nameRecords;

void ascend(nameRecords *people);
// void writeFile(nameRecords names);

int main()
{
    nameRecords names = {
        {
            {"Connor", "Kit"},
            {"Locke", "Joe", NULL}, 
            {"Croft", "Sebastian"},
            {"Hyde-Corrin", "Cormac"}, 
            {"Gao", "William"}
        },
        5
    }; int idx;

    // display
    for(idx = 0; idx < names.count; idx++){
        printf("%s, %s\n", names.names[idx].LName, names.names[idx].FName);
    }

    printf("\n\n");
    ascend(&names);

    for(idx = 0; idx < names.count; idx++){
        printf("%s, %s\n", names.names[idx].LName, names.names[idx].FName);
    }

    printf("\n\n");
    writeFile(names);

    return 0;
}

void ascend(nameRecords *people)
{
    int x, y, small;
    nameType temp;

    for(x = 0; x < people->count-1; x++){
        small = x;
        for(y = x+1; y < people->count; y++){
            if(strcmp(people->names[small].LName, people->names[y].LName) > 0){
                small = y;
            }
        }
        if((strcmp(people->names[x].LName, people->names[small].LName)) > 0){
            temp = people->names[x];
            people->names[x] = people->names[small];
            people->names[small] = temp;
        }
    }
}

/*
void writeFile(nameRecords names)
{
    FILE *fptr = fopen("recordOfNames.bin", "wb+");
    struct node *head = (struct node *)malloc(sizeof(struct node));
    int idx;

    if (fptr == NULL){
        printf("Error loading file.\n");
    } else {
        fwrite(&names, sizeof(names), 1, fptr);
        for(idx = 0; idx < names.count; idx++){
            rewind(fptr);
            fread(head, sizeof(nameType), 1, fptr);
        }
        for(; head != NULL; head = head->next)
    }

    fclose(fptr);
}
*/