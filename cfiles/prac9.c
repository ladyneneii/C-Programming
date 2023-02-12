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

void displayRecords(Blocktype block);
void insertRecord(Blocktype *block, char *lastName, char middleInit, char *firstName, int age, char *degreeProg);
void ascendRecords(Blocktype *block);

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
    insertRecord(&blockA, "Oseman", 'F', "Alice", 32, "Multimedia");
    printf("\n\n\n");
    printf("After insertion:\n\n\n");
    displayRecords(blockA);
    ascendRecords(&blockA);
    printf("\n\n\n");
    printf("After insertion:\n\n\n");
    displayRecords(blockA);

    return 0;
}

void displayRecords(Blocktype block)
{
    int idx;

    for(idx = 0; idx < block.count; idx++){
        printf("%s, %s %c\n", block.student[idx].name.LName, block.student[idx].name.FName, block.student[idx].name.Mi);
        printf("%d\n", block.student[idx].age);
        printf("%s\n\n", block.student[idx].degreeProgram);
    }
}

void insertRecord(Blocktype *block, char *lastName, char middleInit, char *firstName, int age, char *degreeProg)
{
    int idx, pos;

    if(block->count++ < MAX){
        for(idx = 0; idx < block->count && strcmp(lastName, block->student[idx].name.LName) > 0; idx++){}
        for(pos = block->count - 1; pos > idx; pos--){
            block->student[pos] = block->student[pos-1];
        }
        strcpy(block->student[pos].name.LName, lastName);
        block->student[pos].name.Mi = middleInit;
        strcpy(block->student[pos].name.FName, firstName);
        block->student[pos].age = age;
        strcpy(block->student[pos].degreeProgram, degreeProg);
    } else {
        printf("No space available.\n");
    }
}

void ascendRecords(Blocktype *block)
{
    int x, y;
    Infotype temp;

    /*
    for(x = 0; x < block->count - 1; x++){
        for(y = 0; y < block->count; y++){
            if(strcmp(block->student[y].degreeProgram, block->student[y+1].degreeProgram) > 0){
                temp = block->student[y];
                block->student[y] = block->student[y+1];
                block->student[y+1] = temp;
            }
        }
    }
    */

    /*
    for(x = 0; x < block->count - 1; x++){
        big = x;
        for(y = x+1; y < block->count; y++){
            if(strcmp(block->student[y].name.LName, block->student[big].name.LName) > 0){
                big = y;
            }
        }
        if(strcmp(block->student[big].name.LName, block->student[x].name.LName) > 0){
            temp = block->student[big];
            block->student[big] = block->student[x];
            block->student[x] = temp;
        }
    }
    */

    for(x = 0; x < block->count - 1; x++){
        for(y = x; y > -1 && strcmp(block->student[y+1].name.LName, block->student[y].name.LName) > 0; y--){
            temp = block->student[y];
            block->student[y] = block->student[y+1];
            block->student[y+1] = temp;
        }
    }
}