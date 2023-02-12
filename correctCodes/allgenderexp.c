// abandoned
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
    Linked start, end;
    int ctr;
} linkQueue;

typedef struct {
	ArrImp arr;
	int alt;
	linkQueue *lq;
} ComboList;

void insertFirstArr(ComboList *comboptr, Infodata toBeInserted);
void initVirtualSpace(AltSpace vsptr);
void separateppl(ComboList *comboptr, AltSpace space);

int main()
{
    ComboList combo;

    combo.arr = (ArrImp)malloc(sizeof(struct junct));
	if (combo.arr != NULL){
		combo.arr->new = 0;
		combo.arr->data = (Infodata *)malloc(limit*sizeof(Infodata));
		if (combo.arr->data != NULL){
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
			insertFirstArr(&combo, elem1);
			insertFirstArr(&combo, elem2);
			insertFirstArr(&combo, elem3);
			insertFirstArr(&combo, elem4);
			insertFirstArr(&combo, elem5);
			insertFirstArr(&combo, elem6);
			insertFirstArr(&combo, elem7);
			insertFirstArr(&combo, elem8);
			insertFirstArr(&combo, elem9);
			insertFirstArr(&combo, elem10);
			insertFirstArr(&combo, elem11);
			insertFirstArr(&combo, elem12);
			insertFirstArr(&combo, elem13);
			insertFirstArr(&combo, elem14);

			struct cell virtualSpace;

			initVirtualSpace(&virtualSpace); 
		}
	}
    
    return 0;
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

void separateppl(ComboList *comboptr, AltSpace space)
{
	int idx, idx2;
	Linked *trav = &comboptr->lq->start;
	int *travAlt = &comboptr->alt;

	comboptr->alt = -1;
	comboptr->lq = (linkQueue *)malloc(sizeof(linkQueue));
	comboptr->lq->ctr = 0;
	comboptr->lq->start = NULL;
	comboptr->lq->end = NULL;
	for (idx = comboptr->arr->new-1; idx > -1; idx--){
		if (comboptr->arr->data[idx].SOGIE.GenderExpression == Masculine || comboptr->arr->data[idx].SOGIE.GenderExpression == Feminine){
			comboptr->arr->new--;
			if (comboptr->arr->data[idx].SOGIE.GenderExpression == Masculine){
				*trav = (Linked)malloc(sizeof(struct node));
		
				(*trav)->personalInfo = comboptr->arr->data[idx];
				(*trav)->connect = NULL;
				comboptr->lq->end = *trav;
				trav = &(*trav)->connect;
			} else {
				*travAlt = allocSpace();
	
				space->cursptr[*travAlt].cursorContent = comboptr->arr->data[idx];
				space->cursptr[*travAlt].link = -1;
				travAlt = &space->cursptr[*travAlt].link;
			}
			for (idx2 = idx; idx2 < comboptr->arr->new; idx2++){
				comboptr->arr->data[idx2] = comboptr->arr->data[idx2+1];
			}
		} 
	}
}

void insertFirstArr(ComboList *comboptr, Infodata toBeInserted)
{
	int idx;

	if (comboptr->arr->new < limit){
		for (idx = comboptr->arr->new; idx > 0; idx--){
			comboptr->arr->data[idx] = comboptr->arr->data[idx-1];
		}
		comboptr->arr->data[0] = toBeInserted;
		comboptr->arr->new++;
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