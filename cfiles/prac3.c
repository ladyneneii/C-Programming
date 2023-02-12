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
    char course[32];
} Infotype;

typedef struct{
    Infotype student[MAX];
    int count;
} Classtype;

void displayRecords(Classtype class);
void insertStudent(Classtype *class, int pos);
void ascendBubble(Classtype *class);
void ascendInsert(Classtype *class);

int main()
{
    Classtype blockA = {
        {
        {{"Curativo", 'S', "Ernest Joseph"}, 19, "BSCS"},
        {{"Sagun", 'S', "Neil"}, 19, "BSCS"},
        {{"Piamonte", 'T', "Sean Matthew"}, 18, "BSCS"},
        {{"Lamanilao", 'V', "Carlos Juan"}, 20, "BSIT"},
        {{"Bacatan", 'D', "Josh Ryanne"}, 20, "RadTech"},
        },
        5
        };

    displayRecords(blockA);
    insertStudent(&blockA, 5);
    printf("\n\n\n");
    displayRecords(blockA);
    // ascendBubble(&blockA);
    ascendInsert(&blockA);
    printf("\n\n\n");
    displayRecords(blockA);

    return 0;
}

void displayRecords(Classtype class)
{
    int idx;

    for(idx = 0; idx < class.count; idx++){
        printf("%s, %s %c\n", class.student[idx].name.LName, class.student[idx].name.FName, class.student[idx].name.Mi);
        printf("%d\n", class.student[idx].age);
        printf("%s\n\n", class.student[idx].course);
    }
}

void insertStudent(Classtype *class, int pos)
{
    int idx; 

    if(class->count++ < MAX){
        for(idx = class->count - 1; idx >= pos; idx--){
            class->student[idx] = class->student[idx-1];
        }
        strcpy(class->student[idx].name.LName, "Connor");
        strcpy(class->student[idx].name.FName, "Kit");
        class->student[idx].name.Mi = 'C';
        class->student[idx].age = 19;
        strcpy(class->student[idx].course, "BSArch");
    }
}

/*
void ascendBubble(Classtype *class)
{
    // int x, y, temp, arr[] = {2, 4, 7, 3, 6, 6, 3, 1, 0};
    
    
    int x, y;
    Infotype temp;
    

    
    for(x = 0; x < 9; x++){
        for(y = 0; y < 9; y++){
            if(arr[y] > arr[y+1]){
                temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;
            }
        }
    }

    for(x = 0; x < 9; x++){
        printf("%d ", arr[x]);
    }
    
    
    
    for(x = 0; x < class->count; x++){
        for(y = 0; y < class->count; y++){
            if(strcmp(class->student[y].name.LName, class->student[y+1].name.LName) > 0){
                temp = class->student[y];
                class->student[y] = class->student[y+1];
                class->student[y+1] = temp;
            }
        }
    }
    
    
}
*/

void ascendInsert(Classtype *class)
{
    int x, y, small;
    Infotype temp;

    /*
    for(x = 0; x < class->count; x++){
        small = x;
        for(y = x+1; y < class->count; y++){
            if(arr[small] > arr[y]){
                small = y;
            }
        }
        if(arr[small] < arr[x]){
            temp = arr[small];
            arr[small] = arr[x];
            arr[x] = temp;
        }
    }
    */

    for(x = 0; x < class->count; x++){
        small = x;
        for(y = x+1; y < class->count; y++){
            if(strcmp(class->student[small].name.LName, class->student[y].name.LName) > 0){
                small = y;
            }
        }
        if(strcmp(class->student[x].name.LName, class->student[small].name.LName) > 0){
            temp = class->student[small];
            class->student[small] = class->student[x];
            class->student[x] = temp;
        }
    }
}