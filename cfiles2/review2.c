#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char FName[30], LName[30], Mi;
} nameType;

typedef enum {
    female, male, intersex
} sexType;

typedef struct {
    nameType name;
    sexType sex;
    int age;
} infoType;

typedef struct {
    infoType people[10];
    int count;
} recordType;


void getNames(nameType *name);
void getInfo(infoType *info);


int main()
{
    FILE *fptr = fopen("info.bin", "wb+");
    /*
    recordType records = {
        {{"Ernest", "Curativo", 'S', 0, 19}, {"Neil", "Sagun", 'T', 1, 29}, {"Sean", "Piamonte", 'V', 2, 99}},
        3
    };
    */
    recordType records, anotherrecords, *recordsptr;
    int idx;

    if (fptr == NULL){
        printf("Error loading file.\n");
        exit(1);
    } else {
        
        printf("Enter number of records: \n");
        scanf("%d", &records.count);
        for(idx = 0; idx < records.count; idx++){
            getNames(&records.people[idx].name);
            getInfo(records.people+idx);
            printf("\n\n");
        }
        

        // printf("%s, %s %c\n", records.people[0].name.LName, records.people[0].name.FName, records.people[0].name.Mi);

        fwrite(records.people, sizeof(infoType), records.count, fptr);
        // or fwrite(&records), sizeof(records), 1, fptr);
        rewind(fptr);
        // fread(recordsptr, sizeof(records), 1, fptr); -- this doesn't work
        fread(anotherrecords.people, sizeof(infoType), records.count, fptr);
        printf("%s", anotherrecords.people[1].name.LName);
        
    }
    

    return 0;
}


void getNames(nameType *name)
{
    printf("Enter first name: \n");
    scanf("%s", name->FName);
    printf("Enter last name: \n");
    scanf("%s", name->LName);
    printf("Enter middle initial: \n");
    scanf(" %c", &name->Mi);
}

void getInfo(infoType *info)
{
    printf("Enter sex assigned at birth (0 for female, 1 for male, 2 for intersex): \n");
    scanf("%d", &info->sex);
    printf("Enter age: \n");
    scanf("%d", &info->age);
}
