// segmentation fault

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

ComboList initQ();
void enqueue(ComboList *comboptr, Infodata toBeInserted);
void dequeue(ComboList *comboptr);
void displayLinked(ComboList newCombo);

int main()
{
    ComboList combo = initQ();

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
    };

    enqueue(&combo, elem1);
    enqueue(&combo, elem2);
    enqueue(&combo, elem10);
    enqueue(&combo, elem13);
    enqueue(&combo, elem3);
    enqueue(&combo, elem12);
    printf("\nContent of start:\n");
    displayLinked(combo);
    
    dequeue(&combo);
    dequeue(&combo);
    dequeue(&combo);
    printf("\nContent of start after dequeueing:\n");
    displayLinked(combo);
    

    return 0;
}

ComboList initQ()
{
	ComboList combo;

	combo.arr = NULL;
	combo.alt = -1;
	combo.lq = (linkQueue *)malloc(sizeof(linkQueue));
	combo.lq->start = NULL;
	combo.lq->end = NULL;

	return combo;
}

void enqueue(ComboList *comboptr, Infodata toBeInserted)
{
	Linked temp = (Linked)malloc(sizeof(struct node));
	Linked *trav;

	if (temp != NULL){
		comboptr->lq->ctr++;
		temp->personalInfo = toBeInserted;
		temp->connect = NULL;
		comboptr->lq->end = temp;
		if (comboptr->lq->ctr == 1){
			comboptr->lq->start = temp;
		} else {
			for(trav = &comboptr->lq->start; *trav != NULL; trav = &(*trav)->connect){}
			*trav = temp;
		}
	}
}

void dequeue(ComboList *comboptr)
{
	Linked temp; 
	
	if (comboptr->lq->ctr > 0){
		temp = comboptr->lq->start;
		comboptr->lq->start = comboptr->lq->start->connect;
		free(temp);
		if (comboptr->lq->ctr-- == 0){
			comboptr->lq->end = NULL;
		}
	}
}

void displayLinked(ComboList newCombo)
{   
    for ( ; newCombo.lq->start != NULL; newCombo.lq->start = newCombo.lq->start->connect){
        printf("\n%s, %s %c\n", newCombo.lq->start->personalInfo.name.LName, newCombo.lq->start->personalInfo.name.FName, newCombo.lq->start->personalInfo.name.MI);
		printf("%d\n", newCombo.lq->start->personalInfo.age);
		printf("%s\n", newCombo.lq->start->personalInfo.studID);
        switch(newCombo.lq->start->personalInfo.sex){
            case 'F' : printf("Female\n"); break;
            case 'M' : printf("Male\n"); break;
            default : printf("Intersex\n");
        }
		switch(newCombo.lq->start->personalInfo.SOGIE.SexualOrientation){
			case 0 : printf("Homosexual\n"); break;
			case 1 : printf("Heterosexual\n"); break;
			case 2 : printf("Bisexual\n"); break;
			case 3 : printf("Pansexual\n"); break;
			case 4 : printf("Asexual\n"); break;
			default : printf("Others\n");
		}
		switch(newCombo.lq->start->personalInfo.SOGIE.GenderIdentity){
			case 0 : printf("Woman\n"); break;
			case 1 : printf("Man\n"); break;
			case 2 : printf("Non-binary\n"); break;
			default : printf("Others\n");
		}
		switch(newCombo.lq->start->personalInfo.SOGIE.GenderExpression){
			case 0 : printf("Feminine\n"); break;
			case 1 : printf("Androgynous\n"); break;
			case 2 : printf("Maculine\n"); break;
			default : printf("Others\n");
		}
    }
}