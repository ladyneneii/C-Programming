#include <stdio.h>
#include <string.h>
#define MAX 30

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

typedef struct{
    Infotype student[MAX];
    int count;
} Blocktype;

void displayRecords(Blocktype blockName);
void insertRecord(Blocktype *blockptr, char *LName, char Mi, char *FName, int age, char *degreeProgram);

int main()
{
    Blocktype blockA = {
        {
        {{"Connor", 'O', "Kit"}, 18, "BSIT"},
        {{"Croft", 'E', "Sebastian"}, 20, "BSCS"},
        {{"Gao", 'B', "William"}, 19, "BSArch"},
        {{"Locke", 'D', "Joe"}, 18, "BSIT"},
        {{"Rydings", 'L', "Edvin"}, 18, "MassCom"},
        },
        5
    };

    displayRecords(blockA);
    insertRecord(&blockA, "Oseman", 'F', "Alice", 32, "Multimedia"); // given LName, Mi, FName, age, and degreeProgram
    printf("\n\n\n");
    displayRecords(blockA);

    return 0;
}

void displayRecords(Blocktype blockName)
{
    int idx;

    for(idx = 0; idx < blockName.count; idx++){
        printf("%s, %s %c\n", blockName.student[idx].name.LName, blockName.student[idx].name.FName, blockName.student[idx].name.Mi);
        printf("%d\n", blockName.student[idx].age);
        printf("%s\n\n", blockName.student[idx].degreeProgram);
    }
}

void insertRecord(Blocktype *blockptr, char *LName, char Mi, char *FName, int age, char *degreeProgram)
{
    int idx, pos; 

    if (blockptr->count++ < MAX){
        for(idx = 0; idx < blockptr->count && strcmp(LName, blockptr->student[idx].name.LName) > 0; idx++){}
        for(pos = blockptr->count - 1; pos > idx; pos--){
            blockptr->student[pos] = blockptr->student[pos-1];
        }
        strcpy(blockptr->student[pos].name.LName, LName);
        blockptr->student[pos].name.Mi = Mi;
        strcpy(blockptr->student[pos].name.FName, FName);
        blockptr->student[pos].age = age;
        strcpy(blockptr->student[pos].degreeProgram, degreeProgram);
    } else {
        printf("No space available.\n");
    }
}