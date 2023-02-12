#include <stdio.h>
#define size 15

typedef struct {
	int data[size], count, oldCount;
} pot;

void init(pot *treeptr);
void insert(pot *treeptr, int elem);
void display(pot tree);
void deletemax(pot *treeptr);
void heapify(pot *treeptr);

int main()
{
	pot tree;

	init(&tree);
	insert(&tree, 6);
    insert(&tree, 2);
    insert(&tree, 3);
    insert(&tree, 4);
    insert(&tree, 7);
    insert(&tree, 0);
    insert(&tree, 3);
    insert(&tree, 8);
	display(tree);
	deletemax(&tree);
	deletemax(&tree);
	deletemax(&tree);
	deletemax(&tree);
	deletemax(&tree);
	deletemax(&tree);
	deletemax(&tree);
	display(tree);

    pot tree2 = {
        {6, 2, 3, 4, 7, 0, 3, 8},
        8,
        8
    };
    heapify(&tree2);
    display(tree2);
    deletemax(&tree2);
	deletemax(&tree2);
	deletemax(&tree2);
	deletemax(&tree2);
	deletemax(&tree2);
	deletemax(&tree2);
	deletemax(&tree2);
    display(tree2);

	return 0;
}

void init(pot *treeptr)
{
	treeptr->count = treeptr->oldCount = 0;
}

void insert(pot *treeptr, int elem)
{
	int pi, ci, temp;

	ci = treeptr->count;
	treeptr->data[ci] = elem;
	for (pi = (ci-1)/2; pi >= 0 && treeptr->data[ci] > treeptr->data[pi]; ci = pi, pi = (ci-1)/2){
		temp = treeptr->data[ci];
		treeptr->data[ci] = treeptr->data[pi];
		treeptr->data[pi] = temp;
	}
    treeptr->oldCount = ++treeptr->count;
}

void display(pot tree)
{
	int idx;

	printf("\n\n");
	for (idx = 0; idx < tree.oldCount; idx++){
		printf("%d ", tree.data[idx]); 
	}
}

void deletemax(pot *treeptr)
{
	int pi, lci, rci, temp;

	if (treeptr->count > 0){
		treeptr->count--;
		temp = treeptr->data[treeptr->count];
		treeptr->data[treeptr->count] = treeptr->data[0];
		treeptr->data[0] = temp;
		pi = 0;
		lci = 1;
		rci = 2;
		while (lci < treeptr->count){
            if (treeptr->data[lci] > treeptr->data[pi] || (rci < treeptr->count && treeptr->data[pi] < treeptr->data[rci])){
                if (treeptr->data[lci] > treeptr->data[pi]){
                    if (rci < treeptr->count && treeptr->data[lci] < treeptr->data[rci]){
                        lci = rci;
                    }  
                } else if (rci < treeptr->count && treeptr->data[pi] < treeptr->data[rci]){
                    lci = rci;
                }
                temp = treeptr->data[lci];
                treeptr->data[lci] = treeptr->data[pi];
                treeptr->data[pi] = temp;
            }
            pi = lci;
            lci = pi*2+1;
            rci = lci+1;
        }
	}
}

void heapify(pot *treeptr)
{
    int pi, oldpi, lci, rci, temp;

	pi = (treeptr->count-2)/2;
	lci = pi*2+1;
	rci = lci+1;
	oldpi = pi;
	while (pi > -1){
		while (lci < treeptr->count){
			if (treeptr->data[lci] > treeptr->data[pi] || (rci < treeptr->count && treeptr->data[rci] > treeptr->data[pi])){
				if (treeptr->data[lci] > treeptr->data[pi]){
					if (rci < treeptr->count && treeptr->data[lci] < treeptr->data[rci]){
						lci = rci;
					}
				} else if (rci < treeptr->count && treeptr->data[rci] > treeptr->data[pi]){
					lci = rci;
				}
				temp = treeptr->data[lci];
				treeptr->data[lci] = treeptr->data[pi];
				treeptr->data[pi] = temp;
            }
			pi = lci;
			lci = pi*2+1;
			rci = lci+1;
		}
		pi = --oldpi;
		lci = pi*2+1;
		rci = lci+1;
	}
}

