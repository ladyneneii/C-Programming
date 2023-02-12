#define limit 10

typedef struct junction {
	int member;
	struct junction *next;
} *LLNode;

typedef struct {
	int item, connect;
} Celltype;

typedef struct {
	int avail;
	Celltype numbers[limit];
} Spacetype;

typedef enum {TRUE, FALSE} Boolean;

typedef LLNode Dictionary[limit];
typedef int List;

Dictionary *createDict(Spacetype *vs, List *listptr)
{
	Dictionary *dict = (Dictionary *)malloc(sizeof(Dictionary));

	if (dict != NULL){
		initializeDict(*dict);
	
		int group, *trav;
		LLNode temp;

		for ( ; *listptr != -1; listptr = &vs->numbers[*listptr].connect){
			group = Hash(vs->numbers[temp].item);
			temp = (LLNode)malloc(sizeof(struct junction));
			if (temp != NULL){
				for (trav = (*dict)+group; *trav != NULL && (*trav)->member < vs->numbers[*listptr].item; trav = &(*trav)->next){}
				if (*trav == NULL || (*trav)->member != vs->numbers[*listptr].item){
					temp->member = vs->numbers[*listptr].item;
					temp->next = *trav;
					*trav = temp;
				}
			}
		}
	}
}

void initializeDict(Dictionary dict)
{
	int idx;

	for (idx = 0; idx < limit; idx++){
		dict[idx] = NULL;
	}
}

int Hash(int num)
{
	int retVal;
	for (retVal = num; num != 0; num /= 10){
		retVal = num % 10;
	}

	return retVal;
}

void deleteMember(Dictionary dict, int elem)
{
	int group = Hash(elem);
	LLNode *trav;

	for (trav = dict+group; *trav != NULL && elem != (*trav)->member; trav = &(*trav)->next){}
	if (*trav != NULL){
		LLNode temp;

		temp = *trav;
		*trav = (*trav)->next;
		free(temp);
	}
}

Boolean member(Dictionary dict, int elem)
{
	int group = Hash(elem);
	LLNode *trav;

	for (trav = dict+group; *trav != NULL && (*trav)->member != elem; trav = &(*trav)->next){}
	
	return (*trav == NULL) FALSE : TRUE;
}
