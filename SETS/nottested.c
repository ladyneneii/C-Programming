#define SIZE 26

typedef struct {
	char FN[24], LN[24], M;
} Nametype;

typedef struct node {
	Nametype name;
	struct node *link;
} *List;

typedef List Dictionary[SIZE];

Dictionary *createDictionary(List head)
{
	Dictionary *new = (Dictionary *)malloc(sizeof(Dictionary));

	if (new != NULL){
		int idx, group;
		List *trav, temp;

		for (idx = 0; idx < SIZE; idx++){
			(*new)[idx] = NULL;
		}
		for ( ; head != NULL; head = head->link){
			group = Hash(head->name.LN);
			temp = (List)malloc(sizeof(struct node));
			if (temp != NULL){
				temp->name = head->name;
				for (trav = (*new)+group; *trav != NULL && strcmp(temp->name.LN, (*trav)->name.LN) > 0; trav = &(*trav)->link){}
				if (*trav == NULL || strcmp((*trav)->name.LN, head->name.LN) != 0 || strcmp((*trav)->name.FN, head->name.FN) > 0){
					temp->link = *trav;
					*trav = temp;
				} else {
					temp->link = (*trav)->link;	
					(*trav)->link = temp;
				}
			}
		}	
	}

	return new;
}

int Hash(char name[]){
	return toupper(name[0]) - 'A';
}

// cursor-based

#define SIZE 26

typedef struct {
	struct {
		int num, link;
	} Node[100];
	int avail;
} CBNode;

typedef int List;
typedef List Dictionary[SIZE];

Dictionary *createDictionary(List list, CBNode *vs)
{
	Dictionary *new = (Dictionary *)malloc(sizeof(Dictionary));

	if (new != NULL){
		initDictionary(*new);
		int group, *trav, temp;

		for ( ; list != -1; list = vs->Node[list].link){
			group = Hash(vs->Node[list].num);
			temp = vs->avail;
			if (temp != -1){
				vs->avail = vs->Node[temp].link;
				vs->Node[temp].num = vs->Node[list].num;
				for (trav = (*new)+group; *trav != -1 && vs->Node[temp].num > vs->Node[*trav].num; trav = &vs->Node[*trav].link){}
				if (*trav == -1 || vs->Node[temp].num != vs->Node[*trav].num){
					vs->Node[temp].link = *trav;
					*trav = temp;
				}
			}
		}
	}

	return new;
}

void initDictionary(Dictionary new)
{
	int idx; 

	for (idx = 0; idx < SIZE; idx++){
		new[idx] = -1;
	}
}

int Hash(int num)
{
	return num%10;
}
