/*
#include <stdio.h>
#include <string.h>

typedef struct{
    int yas;
    int yup;
    char lala[20];
    float sam;
} code;

typedef struct{
    char haha[20];
    code nope[4];
} duh;

typedef struct {
    char sweet;
    duh yaoi[20];
} BL;

BL kween;

// strcpy(kween.yaoi[5].nope[3].lala, "lucky me"); NOT ALLOWED APPARENTLY. I THINK INITIALISATION IS NOT ALLOWED OUTSIDE FUNCTION

char *myStrrev(char arr[]);
int checkPalin(char arr[]);
int palindrome(int n);

int main()
{
    strcpy(kween.yaoi[5].nope[3].lala, "lucky me");
    strcpy(kween.yaoi[19].haha, "lmfaooo");
    strcpy(kween.yaoi[4].nope[2].lala, "racecar");
    kween.yaoi[15].nope[2].yas = 66;
    
    printf("%s\n", myStrrev(kween.yaoi[5].nope[3].lala));

    myStrrev(kween.yaoi[19].haha);
    printf("%s\n", kween.yaoi[19].haha);

    if (checkPalin(kween.yaoi[4].nope[2].lala) == 1) {
        printf("The word is a palindrome.\n");
    } else {
        printf("The word is not a palindrome.\n");
    }

    if(palindrome(kween.yaoi[15].nope[2].yas) == 1){
        printf("The number is a palindrome.\n");
    } else {
        printf("The number is not a palindrome.\n");
    }
    

    return 0;
}

char *myStrrev(char arr[])
{
    int x, y;
    char temp[20];

    for(x = 0; arr[x] != '\0'; x++){
        temp[x] = arr[x];
    }
    
    for(x -= 1, y = 0; x > -1; y++, x--){
        arr[y] = temp[x];
    }

    return arr;
}

int checkPalin(char arr[])
{
    char temp[20];
    int x, y;

    for(x = 0; arr[x] != '\0'; x++){
        temp[x] = arr[x];
    }
    for(x -= 1, y = 0; x > -1; x--, y++){
        arr[y] = temp[x];
    }

    return (strcmp(arr, temp) == 0) ? 1 : 0;
}

int palindrome(int n)
{
    int temp, temp2 = n;

    for(temp = 0; n != 0; n /= 10){
        temp += n % 10;
    }

    return (temp2 == temp) ? 1 : 0;
}

*/

/*

#include <stdio.h>

typedef union {
    char A;
    int B;
    float C;
} Utype;

Utype X;

int main()
{

    X.A = 'E';
    X.B = 10;
    X.C = 25.75;
    
    printf("%lu\n", sizeof(Utype));
    printf("%lu\n", sizeof(X));
    printf("%c\n", X.A);
    printf("%d\n", X.B);
    printf("%f\n", X.C);
}

*/

/*
#include <stdio.h>

typedef union {
    char A;
    int B;
    float C;
} Utype;

typedef struct{
    char memID;
    Utype memb;
} StructType;

void displayMember(int member, char indicator);

int main()
{
    StructType member; 

    member.memb.B = 67;
    member.memID = 'C';
    displayMember(member.memb.B, member.memID);

    return 0;
}

void displayMember(int member, char indicator)
{
    switch(indicator){
        case 'C' : printf("%c", member); break;
        case 'I' : printf("%d", member); break;
        default : printf("%f", (float)member); break;
    }

}
*/

/*

#include <stdio.h>

typedef struct{
    char FName[30];
    char LName[30];
    char Mi;
} nameInfo;

typedef struct{
    nameInfo name;
    int age;
    char course[30];
} studInfo;

typedef struct{
    studInfo stud[30];
    int count;
} studRecord;

void initRecord(int *count);
void getStudInfo(int count, studRecord *year);
void getNameInfo(nameInfo *name);
void displayInfo(int count, studRecord *year);
void deleteInfo(int count, studRecord *year);

int main()
{
    studRecord yearOne;

    initRecord(&yearOne.count);
    getStudInfo(yearOne.count, &yearOne);
    displayInfo(yearOne.count, &yearOne);
    //printf("%s, %s %c.\n", yearOne.stud[0].name.LName, yearOne.stud[0].name.FName, yearOne.stud[0].name.Mi);
    deleteInfo(yearOne.count, &yearOne);
    displayInfo(yearOne.count, &yearOne);

    return 0;
}

void initRecord(int *count)
{
    printf("Enter number of records: \n");
    scanf("%d", count);
}

void getStudInfo(int count, studRecord *year)
{
    int x;

    for(x = 0; x < count; x++){
        getNameInfo(&year->stud[x].name);
        printf("Enter age: \n");
        scanf("%d", &year->stud[x].age);
        printf("Enter course: \n");
        scanf("%s", year->stud[x].course);
        printf("\n");
    }
}

void getNameInfo(nameInfo *name)
{
    printf("Enter first name: \n");
    scanf("%s", name->FName);
    printf("Enter last name: \n");
    scanf("%s", name->LName);
    printf("Enter middle initial: \n");
    scanf(" %c", &name->Mi);
}


void displayInfo(int count, studRecord *year)
{
    int x;

    for(x = 0; x < count; x++){
        printf("%s, %s %c.\n", year->stud[x].name.LName, year->stud[x].name.FName, year->stud[x].name.Mi);
        printf("%d\n", year->stud[x].age);
        printf("%s\n\n", year->stud[x].course);
    }
    
}

void deleteInfo(int count, studRecord *year)
{
    int del;

    printf("What student number do you want to delete?\n");
    scanf("%d", &del);
    for (del -= 1 ; del < count; del++){
        (*year).stud[del] = (*year).stud[del+1];
    }
    
}
*/

/*
#include <stdio.h>
#include <string.h>
#define SIZE 30

typedef enum{
    FALSE, TRUE
} boolean;

typedef struct{
    char lastName[20];
    char firstName[20];
    char Mi;
} name;

typedef struct{
    name n;
    int studID;
    int age;
    char course[20];
} record;

typedef struct{
    record r[SIZE];
    int count;
} list;

void initialise(int *i);
void fillOut(int count, record r[]);
void fillOutName(name *n);
void displayr(int count, record r[]);
boolean findID(int count, record r[]);

int main()
{
    list l;

    initialise(&l.count);
    fillOut(l.count, l.r);
    displayr(l.count, l.r);
    printf("%d", findID(l.count, l.r));

    return 0;
}

void initialise(int *i)
{
    printf("Enter number of student records: \n");
    scanf("%d", i);
}

void fillOut(int count, record r[])
{
    int idx;

    for(idx = 0; idx < count; idx++){
        fillOutName(&r[idx].n);
        printf("Enter age: \n");
        scanf("%d", &r[idx].age);
        printf("Enter student ID: \n");
        scanf("%d", &r[idx].studID);
        printf("Enter course: \n");
        scanf("%s", r[idx].course);
        printf("\n");
    }
}

void fillOutName(name *n){
    printf("Enter last name: \n");
    scanf("%s", n->lastName);
    printf("Enter first name: \n");
    scanf("%s", n->firstName);
    printf("Enter middle initial: \n");
    scanf(" %c", &n->Mi);
}

void displayr(int count, record r[])
{
    int idx;

    for(idx = 0; idx < count; idx++){
        printf("%s, %s %c\n", r[idx].n.lastName, r[idx].n.firstName, r[idx].n.Mi);
        printf("%d\n", r[idx].age);
        printf("%d\n", r[idx].studID);
        printf("%s\n\n", r[idx].course);
    }
}

boolean findID(int count, record r[])
{
    int ID, idx;
    char lName[20];

    printf("Enter student ID you are searching: \n");
    scanf("%d", &ID);
    printf("Enter last name you are searching: \n");
    scanf("%s", lName);
    for(idx = 0; idx < count && (ID != r[idx].studID || strcmp(lName, r[idx].n.lastName) != 0); idx++){}

    return (idx < count) ? TRUE : FALSE;
}
*/

/*
#include <stdio.h>

void ascend(int a[]);

int main()
{
    int a[20] = {3, 4, 2, 8, 9, 0, 7, 3}, idx;

    ascend(a);
    for(idx = 0; idx < 8; idx++){
        printf("%d ", a[idx]);
    }

    return 0;
}
*/

/*
void ascend(int a[])
{
    int outer, idx, temp;

    for(outer = 0; outer < 7; outer++){
        for(idx = 0; idx < 7; idx++){
            if(a[idx] > a[idx+1]){
                temp = a[idx];
                a[idx] = a[idx+1];
                a[idx+1] = temp;
            }
        }
    }
}
*/

/*
void ascend(int a[])
{
    int outer, idx, temp;

    for(outer = 0; outer < 7; outer++){
        for(idx = outer; idx > -1 && a[idx] > a[idx+1]; idx--){
            temp = a[idx];
            a[idx] = a[idx+1];
            a[idx+1] = temp;
        }
    }
}
*/

/*
void ascend(int a[])
{
    int outer, small, idx, temp;

    for(outer = 0; outer < 7; outer++){
        small = outer;
        for(idx = outer+1; idx < 8; idx++){
            if(a[small] > a[idx]){
                small = idx;
            }
        }
        if(a[small] < a[outer]){
            temp = a[small];
            a[small] = a[outer];
            a[outer] = temp;
        }
    }
}
*/

/*
#include <stdio.h>
#include <string.h>
#define MAX 30

typedef struct{
    struct nameParts{
        char LName[32];
        char FName[32];
        char Mi;
    } name;
    int age;
    char course[32];
} studInfo;

typedef struct{
    studInfo student[MAX];
    int count;
} record;

void init(int *count);
void getInfo(studInfo studentForm[], int x);
void getNameParts(struct nameParts *nameInfo);
void getRestInfo(studInfo studentForm[]);
void displayInfo(studInfo studentForm[], int x);
void addStudInfo(studInfo studentForm[]);
void ascend(studInfo studentForm[], int x);

int main()
{
    record group4;

    init(&group4.count);
    getInfo(group4.student, group4.count);
    displayInfo(group4.student, group4.count);
    addStudInfo(group4.student+group4.count);
    ascend(group4.student, group4.count);
    group4.count += 1;
    displayInfo(group4.student, group4.count);
    return 0;
}

void init(int *count)
{
    printf("Enter number of students: \n");
    scanf("%d", count);
}

void getInfo(studInfo studentForm[], int x)
{
    int idx;

    for(idx = 0; idx < x; idx++){
        getNameParts(&studentForm[idx].name);
        getRestInfo(studentForm+idx);
        printf("\n");
    }
}

void getNameParts(struct nameParts *nameInfo)
{
    printf("Enter last name: \n");
    scanf("%s", nameInfo->LName);
    printf("Enter first name: \n");
    scanf("%s", nameInfo->FName);
    printf("Enter middle initial: \n");
    scanf(" %c", &nameInfo->Mi);
}

void getRestInfo(studInfo studentForm[])
{
    printf("Enter age: \n");
    scanf("%d", &studentForm->age);
    printf("Enter course: \n");
    scanf("%s", studentForm->course);
}

void displayInfo(studInfo studentForm[], int x)
{
    int idx;

    for(idx = 0; idx < x; idx++){
        printf("%s, %s %c\n", studentForm[idx].name.LName, studentForm[idx].name.FName, studentForm[idx].name.Mi);
        printf("%d\n", studentForm[idx].age);
        printf("%s\n", studentForm[idx].course);
        printf("\n");
    }
}

void addStudInfo(studInfo studentForm[])
{
    getNameParts(&studentForm->name);
    getRestInfo(studentForm);
    printf("%s, %s %c\n", studentForm->name.LName, studentForm->name.FName, studentForm->name.Mi);
    printf("%d\n", studentForm->age);
    printf("%s\n", studentForm->course);
    printf("\n");
}

void ascend(studInfo studentForm[], int x)
{
    int idx, idx2, small;
    studInfo temp;

    for(idx = 0, x += 1; idx < x-1; idx++){
        small = idx;
        for(idx2 = idx+1; idx2 < x; idx2++){
            if(strcmp(studentForm[small].name.LName, studentForm[idx2].name.LName) > 0){
                small = idx2;
            }
        }
        if(strcmp(studentForm[idx].name.LName, studentForm[small].name.LName) > 0){
            temp = studentForm[idx];
            studentForm[idx] = studentForm[small];
            studentForm[small] = temp;
        }
    }
}
*/

/*
#include <stdio.h>

typedef struct{
    char FName[32];
    char Mi;
    char LName[32];
    int age;
    char gender;
} INFO;

INFO getData();
void displayData(INFO S);

int main()
{
    INFO person = getData();
    displayData(person);
    return 0;
}

INFO getData()
{
    INFO person;
    printf("Enter last name: \n");
    scanf("%s", person.FName);
    printf("Enter middle initial: \n");
    scanf(" %c", &person.Mi);
    printf("Enter first name: \n");
    scanf("%s", person.LName);
    printf("Enter age: \n");
    scanf("%d", &person.age);
    printf("Enter gender: \n");
    scanf(" %c", &person.gender);

    return person;
}

void displayData(INFO S)
{
    printf("%s, %s %c\n", S.LName, S.FName, S.Mi);
    printf("%d\n", S.age);
    printf("%c\n", S.gender);
}
*/

/*
#include <stdio.h>

typedef struct{
    char FName[32];
    char Mi;
    char LName[32];
    int age;
    char gender;
} INFO;

void getData(INFO *person);
void displayData(INFO S);

int main()
{
    INFO person;
    getData(&person);
    displayData(person);
    return 0;
}

void getData(INFO *person)
{
    printf("Enter last name: \n");
    scanf("%s", person->FName);
    printf("Enter middle initial: \n");
    scanf(" %c", &person->Mi);
    printf("Enter first name: \n");
    scanf("%s", person->LName);
    printf("Enter age: \n");
    scanf("%d", &person->age);
    printf("Enter gender: \n");
    scanf(" %c", &person->gender);
}

void displayData(INFO S)
{
    printf("%s, %s %c\n", S.LName, S.FName, S.Mi);
    printf("%d\n", S.age);
    printf("%c\n", S.gender);
}
*/

/*
#include <stdio.h>
#include <string.h>
#define MAX 30

typedef struct{
    char LName[32];
    char FName[32];
    char Mi;
} nameType;

typedef struct{
    nameType name;
    int age;
    char course[32];
} studInfo;

typedef struct{
    int count;
    studInfo student[MAX];
} studRecord;

void initRecord(int *count);
void getStudInfo(studRecord *list, int count);
void getNameInfo(nameType *nameParts);
void getAgeCourse(studInfo *student);
void displayInfo(studRecord record);
void descend(studRecord *record);

int main()
{
    studRecord record;
    
    initRecord(&record.count);
    getStudInfo(&record, record.count);
    displayInfo(record);
    descend(&record);
    displayInfo(record);

    return 0;
}

void initRecord(int *count)
{
    printf("Enter number of records: \n");
    scanf("%d", count);
}

void getStudInfo(studRecord *list, int count)
{
    int ndx;

    for(ndx = 0; ndx < count; ndx++){
        getNameInfo(&list->student[ndx].name);
        getAgeCourse(list->student+ndx);
        printf("\n");
    }
}

void getNameInfo(nameType *nameParts)
{
    printf("Enter last name: \n");
    scanf("%s", nameParts->LName);
    printf("Enter first name: \n");
    scanf("%s", nameParts->FName);
    printf("Enter middle initial: \n");
    scanf(" %c", &nameParts->Mi);
}

void getAgeCourse(studInfo *student)
{
    printf("Enter age: \n");
    scanf("%d", &student->age);
    printf("Enter course: \n");
    scanf("%s", student->course);
}

void displayInfo(studRecord record)
{
    int ndx;

    for(ndx = 0; ndx < record.count; ndx++){
        printf("%s, %s %c\n", record.student[ndx].name.LName, record.student[ndx].name.FName, record.student[ndx].name.Mi);
        printf("%d\n", record.student[ndx].age);
        printf("%s\n\n", record.student[ndx].course);
    }
}

void descend(studRecord *record)
{
    int ndx, ndx2;
    studInfo temp;

    for(ndx = 0; ndx < record->count-1; ndx++){
        for(ndx2 = ndx+1; ndx > -1 && (strcmp(record->student[ndx].name.LName, record->student[ndx2].name.LName) < 0); ndx2--, ndx--){
            temp = record->student[ndx];
            record->student[ndx] = record->student[ndx2];
            record->student[ndx2] = temp;
        }
    }
}
*/

/*
#include <stdio.h>

typedef struct{
    char FName[32];
    char LName[32];
    char Mi;
} Nametype;

typedef struct{
    Nametype name;
    int age;
    char course[32];
} StudInfo;

typedef struct{
    int count;
    StudInfo student[30];
} StudRecord;

void initRecord(int *x);
void getInfo(StudRecord *list);
void getData(Nametype *nameInfo);
void getAgeCourse(StudInfo *student);
void displayData(StudRecord list);
void deleteStudent(StudRecord *list);

int main()
{
    StudRecord record;

    initRecord(&record.count);
    getInfo(&record);
    displayData(record);
    deleteStudent(&record);
    displayData(record);

    return 0;
}

void getData(Nametype *nameInfo)
{
    printf("Enter first name: \n");
    scanf("%s", nameInfo->FName);
    printf("Enter last name: \n");
    scanf("%s", nameInfo->LName);
    printf("Enter middle initial: \n");
    scanf(" %c", &nameInfo->Mi);
}

void initRecord(int *x)
{
    *x = 3;
}

void getInfo(StudRecord *list)
{
    int ndx;

    for(ndx = 0; ndx < list->count; ndx++){
        getData(&list->student[ndx].name);
        getAgeCourse(&list->student[ndx]);
        printf("\n");
    }
}

void getAgeCourse(StudInfo *student)
{
    printf("Enter age: \n");
    scanf("%d", &student->age);
    printf("Enter course: \n");
    scanf("%s", student->course);
}

void displayData(StudRecord list)
{
    int ndx; 

    for(ndx = 0; ndx < list.count; ndx++){
        printf("%10s%10s%10c\n", list.student[ndx].name.LName, list.student[ndx].name.FName, list.student[ndx].name.Mi);
        printf("%d\n", list.student[ndx].age);
        printf("%s\n\n", list.student[ndx].course);
    }
}

void deleteStudent(StudRecord *list)
{
    int pos, idx;

    printf("Enter student number you want to delete: \n");
    scanf("%d", &pos);
    for(idx = pos-1; idx < list->count-1; idx++){
        list->student[idx] = list->student[idx+1];
    }
    


}
*/

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node *link;
} nodetype, * LIST;
*/

/*
LIST L, one, two;

L = (LIST)malloc(sizeof(nodetype));
L->data = 'U';
L->link = NULL;

one = (LIST)malloc(sizeof(nodetype));
one->data = 'S';
L->link = one;
one->link = two = (LIST)malloc(sizeof(nodetype));
two->data = 'C';
two->link = NULL;
*/

//do not declare and initialise them outside main

/*
int main()
{
    LIST L, one, two;

    L = (LIST)malloc(sizeof(nodetype));
    L->data='U';
    L->link = NULL;

    one = (nodetype*)malloc(sizeof(nodetype));
    one->data = 'S';
    L->link = one;
    one->link = two = (LIST)malloc(sizeof(nodetype));
    two->data = 'C';
    two->link = NULL;

    printf("%c\n", L->data);
    printf("%c\n", one->data);
    printf("%c\n", two->data);
    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node *link;
} nodetype, *LIST;

int main()
{
    LIST L;

    L=(LIST)malloc(sizeof(nodetype));
    L->data='U';
    L->link=(LIST)malloc(sizeof(nodetype));
    L->link->data='S';
    L->link->link=(LIST)malloc(sizeof(nodetype));
    L->link->link->data='C';
    L->link->link->link=NULL;

    printf("%c\n", L->data);
    printf("%c\n", L->link->data);
    printf("%c\n", L->link->link->data);

    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
    char data;
    struct cell *link;
} nodetype, *LIST;

void insertList(LIST L, char elem);

int main()
{
    LIST L;

    L=(LIST)malloc(sizeof(nodetype));
    L->data='U';
    L->link=(LIST)malloc(sizeof(nodetype));
    L->link->data='S';
    L->link->link=(LIST)malloc(sizeof(nodetype));
    L->link->link->data='C';
    L->link->link->link=NULL;

    insertList(L, 'a');
}

void insertList(LIST L, char elem)
{
    LIST node = (LIST)malloc(sizeof(nodetype));

    node->data = elem;
    node->link = L;
    L = node;
}
*/

/*
#include <stdio.h>

int main()
{
    char name[10];

    printf("Enter name: \n");
    fgets(name, 10, stdin);
    printf("The inputted name is: %s\n", name);
    puts(name);
}
*/

/*
#include <stdio.h>
#define maxNumSub 10
#define maxNumRec 100
#define maxNumStud 50
#define maxNumProf 50

typedef struct{
    char LName[30];
    char Mi;
    char FName[30];
} nameParts;

typedef struct{
    int age;
    char department[32];
    char schoolID[8];
} otherInfo

typedef struct{
    nameParts name;
    otherInfo info;
    char courseTaken[maxNumSub];
} studInfo;

typedef struct{
    nameParts name;
    otherInfo info;
    char courseTaught[maxNumSub];
} profInfo;

typedef struct{
    studInfo studentsInfo[maxNumStud];
    int count;
} studRecord;

typedef struct{
    profInfo professorsInfo[maxNumProf];
    int count;
} profRecord;

typedef struct{
    studRecord studentsRecord;
    profRecord professorsRecord;
} department;

void fillInDepartment(department *dep);
void fillInStudRecord(department *record);
void fillInProfRecord(department *dep);
void setNum(department *dep);

int main()
{
    department BSCS;
    department BSIT;
    department BSMath;

    fillInDepartment(&BSCS);

    return 0;
}

void fillInDepartment(department *dep)
{
    fillInStudRecord(&dep->studentsRecord);
    fillInProfRecord();
}

void fillInStudRecord(department *record)
{
    setNum(dep);
}

void setNum(department *dep)
{
    int n;

    do {
        printf("Enter number of students: \n");
        scanf("%d", &n);
    } while (n >= maxNumStud);
}
*/


