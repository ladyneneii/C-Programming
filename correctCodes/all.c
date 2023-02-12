#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define limit 30

typedef struct {	
	char FName[32], MI, LName[32];
} Nametype;

typedef enum {
	Homosexual, Heterosexual, Bisexual, Pansexual, Asexual, Others
} SO;

typedef enum {
	Woman, Man, Nonbinary, etc
} GI;

typedef enum {
	Feminine, Androgynous, Masculine, others
} Exp;

typedef struct {
	SO SexualOrientation;
	GI GenderIdentity;
	Exp GenderExpression;
} SOGIEtype;

typedef struct {
	Nametype name;
	int age;
	char studID[10];
    char sex;
	SOGIEtype SOGIE;
} Infodata;

typedef struct node {
	Infodata personalInfo;
	struct node *connect;
} *Linked;

typedef struct {
	Infodata cursorContent;
	int link;
} Junction;

typedef struct cell {
	Junction *cursptr;
	int unoccupied;
} *AltSpace;

typedef struct junct {
	Infodata *data;
	int num;
} *ArrImp;

typedef struct {
	ArrImp arr;
	int alt;
	Linked link;
} ComboList;

void initList(ComboList *comboptr);
void initVirtualSpace(AltSpace vsptr); 
void insertFirstCursor(AltSpace vsptr, ComboList *comboptr, Infodata insert);
int allocIndex(AltSpace vsptr);
Infodata getStudRecord();
void displayCursor(ComboList combo, struct cell vs);
ComboList separatePeople(AltSpace vs, int *altptr);
void deallocSpace(int del, AltSpace vs);
void displayLinked(ComboList newCombo);
void displayArr(ComboList newCombo);

int main()
{
	ComboList combo;
	struct cell virtualSpace;

	initList(&combo);
	initVirtualSpace(&virtualSpace); 

	Infodata elem1 = {
		"Charlie", 'D', "Spring", 19, "0123456789", 'M', Homosexual, Man, Masculine
	}, elem2 = {
        "Nick", 'F', "Nelson", 19, "1234567890", 'M', Bisexual, Man, Masculine
    }, elem10 = {
        "Cormac", 'G', "Hyde-Corrin", 15, "82940356", 'M', Heterosexual, Man, Masculine
    }, elem13 = {
        "Mark", 'V', "Loon", 20, "93590356", 'M', Heterosexual, Man, Masculine
    }, elem3 = {
        "Joe", 'E', "Locke", 19, "13231547", 'M', Homosexual, Man, Masculine
    }, elem12 = {
        "Kaye", 'N', "Feralgo", 20, "93590356", 'M', Heterosexual, Woman, Feminine
    }, elem4 = {
        "Tara", 'Z', "Jones", 19, "5849892938", 'F', Pansexual, Woman, Feminine
    }, elem11 = {
        "Guava", 'Q', "Juice", 20, "12790356", 'F', Heterosexual, Man, Masculine
    }, elem5 = {
        "Darcy", 'C', "Welly", 20, "90390356", 'F', Others, Nonbinary, Androgynous
    }, elem6 = {
        "Toby", 'C', "Donovan", 20, "93590356", 'M', Heterosexual, Man, Androgynous
    }, elem7 = {
        "William", 'B', "Gao", 21, "02490356", 'F', Heterosexual, Woman, Masculine
    }, elem8 = {
        "Maria", 'P', "Milia", 20, "8245932", 'I', Others, Nonbinary, Androgynous
    }, elem14 = {
        "Lady", 'C', "Gaga", 20, "34590356", 'F', Heterosexual, Woman, Androgynous
    }, elem9 = {
        "Kween", 'E', "Slay", 20, "13824959", 'F', Heterosexual, Woman, Feminine
    };

	// Infodata elem2 = getStudRecord();

    insertFirstCursor(&virtualSpace, &combo, elem1);
	insertFirstCursor(&virtualSpace, &combo, elem2);
    insertFirstCursor(&virtualSpace, &combo, elem3);
	insertFirstCursor(&virtualSpace, &combo, elem4);
    insertFirstCursor(&virtualSpace, &combo, elem5);
    insertFirstCursor(&virtualSpace, &combo, elem6);
	insertFirstCursor(&virtualSpace, &combo, elem7);
    insertFirstCursor(&virtualSpace, &combo, elem8);
	insertFirstCursor(&virtualSpace, &combo, elem9);
    insertFirstCursor(&virtualSpace, &combo, elem10);
    insertFirstCursor(&virtualSpace, &combo, elem11);
	insertFirstCursor(&virtualSpace, &combo, elem12);
    insertFirstCursor(&virtualSpace, &combo, elem13);
	insertFirstCursor(&virtualSpace, &combo, elem14);
    printf("\nContent of combo.alt:\n");
    displayCursor(combo, virtualSpace);
    
    ComboList newCombo = separatePeople(&virtualSpace, &combo.alt);

    printf("\nContent of combo.alt after separatePeople():\n");
    displayCursor(newCombo, virtualSpace);
    printf("\nContent of combo.link:\n");
    displayLinked(newCombo);
    printf("\nContent of combo.arr:\n");
    displayArr(newCombo);

	return 0;
}

void initList(ComboList *comboptr)
{
	comboptr->arr = NULL;
    comboptr->link = NULL;
	comboptr->alt = -1;
}

void initVirtualSpace(AltSpace vsptr)
{
	int idx;

	vsptr->cursptr = (Junction *)malloc(limit*sizeof(Junction));
	for (idx = limit-1; idx > -1; idx--){
		vsptr->cursptr[idx].link = idx-1;
	}
    vsptr->unoccupied = limit-1;
}

void insertFirstCursor(AltSpace vsptr, ComboList *comboptr, Infodata insert)
{
	int freeidx = allocIndex(vsptr);

	if (freeidx != -1){
		vsptr->cursptr[freeidx].cursorContent = insert;
		vsptr->cursptr[freeidx].link = comboptr->alt;
		comboptr->alt = freeidx;
	} else {
		printf("\nYou have run out of space!\n");
	}
}

int allocIndex(AltSpace vsptr)
{
	int freeidx;

	if (vsptr->unoccupied != -1){
		freeidx = vsptr->unoccupied;
		vsptr->unoccupied = vsptr->cursptr[freeidx].link;
	} else {
		freeidx = -1;
	}

	return freeidx;
}

Infodata getStudRecord()
{
	Infodata getInfo;

	printf("\nEnter the first name:\n");
	scanf("%s", getInfo.name.FName);
	printf("\nEnter the middle initial:\n");
	scanf(" %c", &getInfo.name.MI);
	printf("\nEnter the last name:\n");
	scanf("%s", getInfo.name.LName);
	printf("\nEnter the age:\n");
	scanf("%d", &getInfo.age);
	printf("\nEnter the student number:\n");
	scanf("%s", getInfo.studID);
    printf("\nEnter the sex assigned at birth:\n");
	scanf(" %c", &getInfo.sex);
	printf("\nEnter 0, 1, 2, 3, 4, 5 for Homosexual, Heterosexual, Bisexual, Pansexual, Asexual, and Others respectively:\n");
	scanf("%d", &getInfo.SOGIE.SexualOrientation);
	printf("\nEnter 0, 1, 2, 3 for Woman, Man, Non-binary, and Others respectively:\n");
	scanf("%d", &getInfo.SOGIE.GenderIdentity);
	printf("\nEnter 0, 1, 2, 3 for Feminine, Androgynous, Masculine, and Others respectively:\n");
	scanf("%d", &getInfo.SOGIE.GenderExpression);

	return getInfo;
}

void displayCursor(ComboList combo, struct cell vs)
{
	for ( ; combo.alt != -1; combo.alt = vs.cursptr[combo.alt].link){
		printf("\n%s, %s %c\n", vs.cursptr[combo.alt].cursorContent.name.LName, vs.cursptr[combo.alt].cursorContent.name.FName, vs.cursptr[combo.alt].cursorContent.name.MI);
		printf("%d\n", vs.cursptr[combo.alt].cursorContent.age);
		printf("%s\n", vs.cursptr[combo.alt].cursorContent.studID);
        switch(vs.cursptr[combo.alt].cursorContent.sex){
            case 'F' : printf("Female\n"); break;
            case 'M' : printf("Male\n"); break;
            default : printf("Intersex\n");
        }
		switch(vs.cursptr[combo.alt].cursorContent.SOGIE.SexualOrientation){
			case 0 : printf("Homosexual\n"); break;
			case 1 : printf("Heterosexual\n"); break;
			case 2 : printf("Bisexual\n"); break;
			case 3 : printf("Pansexual\n"); break;
			case 4 : printf("Asexual\n"); break;
			default : printf("Others\n");
		}
		switch(vs.cursptr[combo.alt].cursorContent.SOGIE.GenderIdentity){
			case 0 : printf("Woman\n"); break;
			case 1 : printf("Man\n"); break;
			case 2 : printf("Non-binary\n"); break;
			default : printf("Others\n");
		}
		switch(vs.cursptr[combo.alt].cursorContent.SOGIE.GenderExpression){
			case 0 : printf("Feminine\n"); break;
			case 1 : printf("Androgynous\n"); break;
			case 2 : printf("Maculine\n"); break;
			default : printf("Others\n");
		}
	}
}

ComboList separatePeople(AltSpace vs, int *altptr)
{
	ComboList newCombo;
	int tempcurs;
	Linked templinked = NULL;

	newCombo.link = NULL;
	newCombo.alt = *altptr;
    altptr = &newCombo.alt;
	newCombo.arr = (ArrImp)malloc(sizeof(struct junct));
	newCombo.arr->num = 0;
	newCombo.arr->data = (Infodata *)malloc(limit*sizeof(Infodata));
	while (*altptr != -1){
		if ((vs->cursptr[*altptr].cursorContent.SOGIE.SexualOrientation != Heterosexual || ((vs->cursptr[*altptr].cursorContent.sex == 'F' && vs->cursptr[*altptr].cursorContent.SOGIE.GenderIdentity != Woman) || (vs->cursptr[*altptr].cursorContent.sex == 'M' && vs->cursptr[*altptr].cursorContent.SOGIE.GenderIdentity != Man))) ||  vs->cursptr[*altptr].cursorContent.sex == 'I'){
			templinked = (Linked)malloc(sizeof(struct node));
			templinked->personalInfo = vs->cursptr[*altptr].cursorContent;
			templinked->connect = newCombo.link;
			newCombo.link = templinked;

			tempcurs = *altptr;
			*altptr = vs->cursptr[*altptr].link;
			deallocSpace(tempcurs, vs);
		} else if (vs->cursptr[*altptr].cursorContent.sex != 'F'){
			newCombo.arr->data[newCombo.arr->num] = vs->cursptr[*altptr].cursorContent;
			newCombo.arr->num++;

			tempcurs = *altptr;
			*altptr = vs->cursptr[*altptr].link;
			deallocSpace(tempcurs, vs);
		} else {
			altptr = &vs->cursptr[*altptr].link;
		}
	}

	return newCombo;
}

void deallocSpace(int del, AltSpace vs)
{
    vs->cursptr[del].link = vs->unoccupied;
    vs->unoccupied = del;
}

void displayLinked(ComboList newCombo)
{   
    for ( ; newCombo.link != NULL; newCombo.link = newCombo.link->connect){
        printf("\n%s, %s %c\n", newCombo.link->personalInfo.name.LName, newCombo.link->personalInfo.name.FName, newCombo.link->personalInfo.name.MI);
		printf("%d\n", newCombo.link->personalInfo.age);
		printf("%s\n", newCombo.link->personalInfo.studID);
        switch(newCombo.link->personalInfo.sex){
            case 'F' : printf("Female\n"); break;
            case 'M' : printf("Male\n"); break;
            default : printf("Intersex\n");
        }
		switch(newCombo.link->personalInfo.SOGIE.SexualOrientation){
			case 0 : printf("Homosexual\n"); break;
			case 1 : printf("Heterosexual\n"); break;
			case 2 : printf("Bisexual\n"); break;
			case 3 : printf("Pansexual\n"); break;
			case 4 : printf("Asexual\n"); break;
			default : printf("Others\n");
		}
		switch(newCombo.link->personalInfo.SOGIE.GenderIdentity){
			case 0 : printf("Woman\n"); break;
			case 1 : printf("Man\n"); break;
			case 2 : printf("Non-binary\n"); break;
			default : printf("Others\n");
		}
		switch(newCombo.link->personalInfo.SOGIE.GenderExpression){
			case 0 : printf("Feminine\n"); break;
			case 1 : printf("Androgynous\n"); break;
			case 2 : printf("Maculine\n"); break;
			default : printf("Others\n");
		}
    }
}

void displayArr(ComboList newCombo)
{
    int idx;

    for (idx = 0; idx < newCombo.arr->num; idx++){
        printf("\n%s, %s %c\n", newCombo.arr->data[idx].name.LName, newCombo.arr->data[idx].name.FName, newCombo.arr->data[idx].name.MI);
		printf("%d\n", newCombo.arr->data[idx].age);
		printf("%s\n", newCombo.arr->data[idx].studID);
        switch(newCombo.arr->data[idx].sex){
            case 'F' : printf("Female\n"); break;
            case 'M' : printf("Male\n"); break;
            default : printf("Intersex\n");
        }
		switch(newCombo.arr->data[idx].SOGIE.SexualOrientation){
			case 0 : printf("Homosexual\n"); break;
			case 1 : printf("Heterosexual\n"); break;
			case 2 : printf("Bisexual\n"); break;
			case 3 : printf("Pansexual\n"); break;
			case 4 : printf("Asexual\n"); break;
			default : printf("Others\n");
		}
		switch(newCombo.arr->data[idx].SOGIE.GenderIdentity){
			case 0 : printf("Woman\n"); break;
			case 1 : printf("Man\n"); break;
			case 2 : printf("Non-binary\n"); break;
			default : printf("Others\n");
		}
		switch(newCombo.arr->data[idx].SOGIE.GenderExpression){
			case 0 : printf("Feminine\n"); break;
			case 1 : printf("Androgynous\n"); break;
			case 2 : printf("Maculine\n"); break;
			default : printf("Others\n");
		}
    }
}

