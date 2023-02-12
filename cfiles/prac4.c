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
void ascendBubble(Classtype *class);

int main()
{
    Classtype blockB = {
        {
        {{"Connor", 'D', "Kit"}, 18, "BSIT"},
        {{"Locke", 'B', "Joe"}, 19, "BSCS"},
        {{"Swift", 'F', "Taylor"}, 32, "BSCS"},
        {{"Croft", 'E', "Sebastian"}, 20, "BSIT"},
        {{"Sivan", 'Q', "Troye"}, 30, "BSIT"},
        {{"Ryding", 'T', "Edvin"}, 18, "BSArch"},
        {{"Rios", 'D', "Manu"}, 27, "BSIT"}
        },
        7
    };

    displayRecords(blockB);
    ascendBubble(&blockB);
    printf("\n\n\n");
    displayRecords(blockB);

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

void ascendBubble(Classtype *class)
{
    int x, y;
    Infotype temp;

    /*
    for(x = 0; x < class->count - 1; x++){
        for(y = 0; y < class->count; y++){
            if(arr[y] > arr[y+1]){
                temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;
            }
        }
    }
    */

    /*
    for(x = 0; x < class->count - 1; x++){
        for(y = 0; y < class->count; y++){
            if(strcmp(class->student[y].name.LName, class->student[y+1].name.LName) > 0){
                temp = class->student[y];
                class->student[y] = class->student[y+1];
                class->student[y+1] = temp;
            }
        }
    }
    */
    

    /*
    for(x = 0; x < class->count-1; x++){
        small = x;
        for(y = x+1; y < class->count; y++){
            if(strcmp(class->student[small].name.LName, class->student[y].name.LName) > 0){
                small = y;
            }
        }
        if(strcmp(class->student[x].name.LName, class->student[small].name.LName) > 0){
            temp = class->student[x];
            class->student[x] = class->student[small];
            class->student[small] = temp;
        }
    }
    */

    for(x = 0; x < class->count-1; x++){
        for(y = x; y > -1 && strcmp(class->student[y].name.LName, class->student[y+1].name.LName) > 0; y--){
            temp = class->student[y];
            class->student[y] = class->student[y+1];
            class->student[y+1] = temp;
        }
    }
    
}