#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10

typedef struct {
    char LName[32], FName[32], MI; 
} Nametype;

typedef enum {
    Woman, Man, Nonbinary
} Gendertype;

typedef struct {
    Nametype fullName;
    int age;
    Gendertype gender;
} Infotype;

typedef struct cell {
    Infotype infoLink;
    struct cell *nextNode;
} *LinkList;

typedef struct {
    Infotype infoArr[max];
    int count;
} ArrList;

typedef struct {
    struct {
        Infotype infoCursor;
        int nextCell;
    } CursorRecord[max];
    int avail;
} CursorList;

typedef int List;

LinkList createLinkList();
void displayLinkList(LinkList head);
void AscendLinkListSelection(LinkList head);
void insertSortedLinkList(LinkList *head, Infotype insertInfo);
CursorList createCursorList();
void visualiseCursorList(CursorList VH);
List getNonbinary(CursorList *VHptr, LinkList *headptr);
int allocSpace(CursorList *VHptr);
void displayCursorList(CursorList VH, List list);
ArrList createArrList();
void getWomen(LinkList *headptr, ArrList *arrptr);
void displayArrList(ArrList arrimp);
void insertSortedCursor(CursorList *VHptr, List *listptr, Infotype insertInfo);

int main()
{
    LinkList head = createLinkList();

    printf("\nLinkList: \n");
    displayLinkList(head);
    printf("\nAscending LinkList\n");
    AscendLinkListSelection(head);
    displayLinkList(head);

    printf("\nInsert Sorted LinkList\n");
    Infotype insertInfo = {
        "Dean", "Alex", 'D', 15, Nonbinary
    };
    insertSortedLinkList(&head, insertInfo);
    Infotype insertInfo1 = {
        "Munsch", "Kween", 'V', 26, Nonbinary
    };
    insertSortedLinkList(&head, insertInfo1);
    Infotype insertInfo2 = {
        "Radwick", "Chad", 'F', 19, Man
    };
    insertSortedLinkList(&head, insertInfo2);
    displayLinkList(head);

    CursorList VH1 = createCursorList();

    visualiseCursorList(VH1);
    List nonbinaryList = getNonbinary(&VH1, &head);
    ArrList arrayimp = createArrList();
    getWomen(&head, &arrayimp);
    printf("\nLinked List after getting the non-binary people and women:\n");
    displayLinkList(head);
    printf("\nCursor List:\n");
    displayCursorList(VH1, nonbinaryList);
    printf("\nArray List:\n");
    displayArrList(arrayimp);

    Infotype insertInfo3 = {
        "Mary", "Ray", 'D', 19, Nonbinary
    };
    insertSortedCursor(&VH1, &nonbinaryList, insertInfo3);
    printf("\nCursor List:\n");
    displayCursorList(VH1, nonbinaryList);

    return 0;
}

LinkList createLinkList()
{
    LinkList head = (LinkList)malloc(sizeof(struct cell));

    strcpy(head->infoLink.fullName.LName, "Swift");
    strcpy(head->infoLink.fullName.FName, "Taylor");
    head->infoLink.fullName.MI = 'S';
    head->infoLink.age = 34;
    head->infoLink.gender = Woman;
    head->nextNode = (LinkList)malloc(sizeof(struct cell));

    strcpy(head->nextNode->infoLink.fullName.LName, "Perry");
    strcpy(head->nextNode->infoLink.fullName.FName, "Katy");
    head->nextNode->infoLink.fullName.MI = 'D';
    head->nextNode->infoLink.age = 40;
    head->nextNode->infoLink.gender = Woman;
    head->nextNode->nextNode = (LinkList)malloc(sizeof(struct cell));

    strcpy(head->nextNode->nextNode->infoLink.fullName.LName, "Mason");
    strcpy(head->nextNode->nextNode->infoLink.fullName.FName, "Alexander");
    head->nextNode->nextNode->infoLink.fullName.MI = 'F';
    head->nextNode->nextNode->infoLink.age = 24;
    head->nextNode->nextNode->infoLink.gender = Nonbinary;
    head->nextNode->nextNode->nextNode = (LinkList)malloc(sizeof(struct cell));

    strcpy(head->nextNode->nextNode->nextNode->infoLink.fullName.LName, "Locke");
    strcpy(head->nextNode->nextNode->nextNode->infoLink.fullName.FName, "Joe");
    head->nextNode->nextNode->nextNode->infoLink.fullName.MI = 'S';
    head->nextNode->nextNode->nextNode->infoLink.age = 19;
    head->nextNode->nextNode->nextNode->infoLink.gender = Man;
    head->nextNode->nextNode->nextNode->nextNode = NULL;

    return head;
}

void displayLinkList(LinkList head)
{
    for ( ; head != NULL; head = head->nextNode){
        printf("%s, %s %c\n", head->infoLink.fullName.LName, head->infoLink.fullName.FName, head->infoLink.fullName.MI);
        printf("%d\n", head->infoLink.age);
        switch (head->infoLink.gender){
            case Woman: printf("Woman"); break;
            case Nonbinary: printf("Non-binary"); break;
            default: printf("Man"); break;
        } 
        printf("\n");
    }
}

void AscendLinkListSelection(LinkList head)
{
    LinkList x, y, small;
    Infotype temp;

    for (x = head; x != NULL; x = x->nextNode){
        small = x;
        for (y = x->nextNode; y != NULL; y = y->nextNode){
            if (strcmp(small->infoLink.fullName.LName, y->infoLink.fullName.LName) > 0){
                small = y;
            }
        }
        if (strcmp(x->infoLink.fullName.LName, small->infoLink.fullName.LName) > 0){
            temp = x->infoLink;
            x->infoLink = small->infoLink;
            small->infoLink = temp;
        }
    }
}

void insertSortedLinkList(LinkList *head, Infotype insertInfo)
{
    LinkList temp = (LinkList)malloc(sizeof(struct cell));

    temp->infoLink = insertInfo;
    temp->nextNode = NULL;
    for ( ; *head != NULL && strcmp((*head)->infoLink.fullName.LName, insertInfo.fullName.LName) < 0; head = &(*head)->nextNode){}
    if (strcmp((*head)->infoLink.fullName.LName, insertInfo.fullName.LName) > 0){
        temp->nextNode = *head;
        *head = temp;
    } else if (*head == NULL){
        *head = temp;
    } else {
        printf("Last name match found.\n");
    }
}

CursorList createCursorList()
{
    CursorList VH;
    int idx;

    VH.avail = max-1;
    for (idx = max-1; idx > -1; idx--){
        VH.CursorRecord[idx].nextCell = idx-1;
    }

    return VH;
}

void visualiseCursorList(CursorList VH)
{
    int idx;

    printf("%15s| %15s\n", "INDEX", "nextCell");
    for (idx = 0; idx < max; idx++){
        printf("%15d| %15d\n", idx, VH.CursorRecord[idx].nextCell);
    }
}

List getNonbinary(CursorList *VHptr, LinkList *headptr)
{
    int freeSpace;
    List nonbinaryList = -1;
    LinkList temp;
    
    while(*headptr != NULL){
        if ((*headptr)->infoLink.gender == Nonbinary){
            freeSpace = allocSpace(VHptr);
            VHptr->CursorRecord[freeSpace].infoCursor = (*headptr)->infoLink;
            VHptr->CursorRecord[freeSpace].nextCell = nonbinaryList;
            nonbinaryList = freeSpace;

            temp = *headptr;
            *headptr = (*headptr)->nextNode;
            free(temp);
        } else {
            headptr = &(*headptr)->nextNode;
        }
    }

    return nonbinaryList;
}

int allocSpace(CursorList *VHptr)
{
    int freeSpace;

    if (VHptr->avail != -1){
        freeSpace = VHptr->avail;
        VHptr->avail = VHptr->CursorRecord[freeSpace].nextCell;
    } else {
        freeSpace = -1;
        printf("No space anymore.\n");
    }

    return freeSpace;
}

void displayCursorList(CursorList VH, List list)
{
    for ( ; list != -1; list = VH.CursorRecord[list].nextCell){
        printf("%s, %s %c\n", VH.CursorRecord[list].infoCursor.fullName.LName, VH.CursorRecord[list].infoCursor.fullName.FName, VH.CursorRecord[list].infoCursor.fullName.MI);
        printf("%d\n", VH.CursorRecord[list].infoCursor.age);
        switch (VH.CursorRecord[list].infoCursor.gender){
            case Woman: printf("Woman"); break;
            case Nonbinary: printf("Non-binary"); break;
            default: printf("Man"); break;
        } 
        printf("\n");
    }
}

ArrList createArrList()
{
    ArrList arrimp;

    arrimp.count = 0;

    return arrimp;
}

void getWomen(LinkList *headptr, ArrList *arrptr)
{
    LinkList temp;

    while (*headptr != NULL){
        if ((*headptr)->infoLink.gender == Woman){
            arrptr->count++;
            arrptr->infoArr[arrptr->count-1] = (*headptr)->infoLink;

            temp = *headptr;
            *headptr = (*headptr)->nextNode;
            free(temp);
        } else {
            headptr = &(*headptr)->nextNode;
        }
    }
}

void displayArrList(ArrList arrimp)
{
    int idx;

    for (idx = 0; idx < arrimp.count; idx++){
        printf("%s, %s %c\n", arrimp.infoArr[idx].fullName.LName, arrimp.infoArr[idx].fullName.FName, arrimp.infoArr[idx].fullName.MI);
        printf("%d\n", arrimp.infoArr[idx].age);
        switch (arrimp.infoArr[idx].gender){
            case Woman: printf("Woman"); break;
            case Nonbinary: printf("Non-binary"); break;
            default: printf("Man"); break;
        } 
        printf("\n");
    }
}

void insertSortedCursor(CursorList *VHptr, List *listptr, Infotype insertInfo)
{
    int freeIndex = allocSpace(VHptr);

    if (freeIndex != -1){
        VHptr->CursorRecord[freeIndex].infoCursor = insertInfo;
        for ( ; *listptr != -1 && strcmp(VHptr->CursorRecord[*listptr].infoCursor.fullName.LName, insertInfo.fullName.LName) > 0; listptr = &VHptr->CursorRecord[*listptr].nextCell){}
        if (*listptr == -1 || strcmp(VHptr->CursorRecord[*listptr].infoCursor.fullName.LName, insertInfo.fullName.LName) < 0){
            VHptr->CursorRecord[freeIndex].nextCell = *listptr;
            *listptr = freeIndex;
        } else {
            printf("\nA person with the same last name already exists on the list.\n");
        } 
    }
}

// i hope u learned something hehe xxxx
// compiler-tested
// coded with love <33