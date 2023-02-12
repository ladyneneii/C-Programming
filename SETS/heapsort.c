#include <stdio.h>
#define MAX 15

typedef struct {
	int elem[MAX];
	int lastndx, oldLast;
} Heap;

void initialise(Heap *hptr);
void insert(Heap *hptr, int num);
void deletemin(Heap *hptr);
void display(Heap h);
void heapify(Heap *hptr);

int main()
{
	Heap h;

	initialise(&h);
	// insert(&h, 2);
	// insert(&h, 3);
	// insert(&h, 6);
	// insert(&h, 7);
	// insert(&h, 0);
	// insert(&h, 4);
    // insert(&h, 1);
	insert(&h, 1);
	insert(&h, 2);
	insert(&h, 3);

	display(h);
	printf("\n\n");
	deletemin(&h);

	display(h);
	printf("\n\n");

	Heap h2 = {
		{4, 5, 9, 3, 1, 0, 10, 4},
		7,
     		7
	};

	display(h2);
	heapify(&h2);
	printf("\n\n");
	display(h2);
	printf("\n\n");
	deletemin(&h2);
	deletemin(&h2);
	deletemin(&h2);
	deletemin(&h2);
	deletemin(&h2);
	deletemin(&h2);
	deletemin(&h2);
	display(h2);

	return 0;
}

void initialise(Heap *hptr)
{
	hptr->lastndx = -1;
}


void insert(Heap *hptr, int num)
{
	int ci, pi, temp;

	hptr->lastndx++;
	hptr->oldLast = hptr->lastndx;
	hptr->elem[hptr->lastndx] = num;
	for (ci = hptr->lastndx, pi = (ci-1)/2; ci != 0 && hptr->elem[ci] < hptr->elem[pi]; ci = pi, pi = (ci-1)/2){
		temp = hptr->elem[ci];
		hptr->elem[ci] = hptr->elem[pi];
		hptr->elem[pi] = temp;
	}
}

void deletemin(Heap *hptr)
{
	int temp, pi, lci, rci;

	if (hptr->lastndx != -1){
		temp = hptr->elem[hptr->lastndx];
		hptr->elem[hptr->lastndx] = hptr->elem[0];
		hptr->elem[0] = temp;
		hptr->lastndx--;
		pi = 0;
		lci = 1;
		rci = 2;
		while (lci <= hptr->lastndx){
			if (hptr->elem[lci] < hptr->elem[pi] || (rci <= hptr->lastndx && hptr->elem[rci] < hptr->elem[pi])){
				if (hptr->elem[lci] < hptr->elem[pi]){
					if (rci <= hptr->lastndx && hptr->elem[rci] < hptr->elem[lci]){
						lci = rci;
					}
				} else if (rci <= hptr->lastndx && hptr->elem[rci] < hptr->elem[pi]){
					lci = rci;
				}
				temp = hptr->elem[lci];
				hptr->elem[lci] = hptr->elem[pi];
				hptr->elem[pi] = temp;
			}
			pi = lci;
            lci = pi*2+1;
            rci = lci+1;
		}
	}
}

void display(Heap h)
{
	int idx;

	for (idx = 0; idx <= h.oldLast; idx++){
		printf("%d ", h.elem[idx]);
	}
}

void heapify(Heap *hptr)
{
	int pi, oldpi, lci, rci, temp;

	pi = (hptr->lastndx-1)/2;
	lci = pi*2+1;
	rci = lci+1;
	oldpi = pi;
	while (pi > -1){
		while (lci <= hptr->lastndx){
			if (hptr->elem[lci] < hptr->elem[pi] || (rci <= hptr->lastndx && hptr->elem[rci] < hptr->elem[pi])){
				if (hptr->elem[lci] < hptr->elem[pi]){
					if (rci <= hptr->lastndx && hptr->elem[rci] < hptr->elem[lci]){
						lci = rci;
					}
				} else if (rci <= hptr->lastndx && hptr->elem[rci] < hptr->elem[pi]){
					lci = rci;
				}
				temp = hptr->elem[lci];
				hptr->elem[lci] = hptr->elem[pi];
				hptr->elem[pi] = temp;
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

