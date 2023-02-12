#define max 5
typedef int vertex;
typedef struct cell {
	int cost;
	vertex v;
	struct cell *link;
} VType;
typedef VType vertices[max];
typedef struct {
	int v[MAX], count;
} SET;

int Prims (vertices L, SET V)
{
	int cost = 0, min, temp, idx, ctr;
	SET U = {{1, 0, 0, 0, 0, 0}, 1}, X = {{0, 1, 1, 1, 1, 1}, 5};
	VType *trav, *tempdel, del;

	for (idx = 0; X.count >= 0; cost += min){
		for (ctr = idx = 0, min = 9999; ctr < U.count && idx <= MAX; idx++){
			if (U.v[idx] == 1){
				for (trav = L+idx; *trav != NULL; trav = &(*trav)->link){
					if (min > (*trav)->cost){
						min = (*trav)->cost;
						temp = (*trav)->v;
						tempdel = trav;
						del = *trav;
					}
				}
				ctr++;
			}
		}
		*tempdel = (*tempdel)->link;
		free(del);
		U.v[temp] = 1;
		X.v[temp] = 0;
		U.count++; 
		X.count--;
		for (trav = L+temp; *trav != NULL && (*trav)->v != temp; trav = &(*trav)->link){}
		del = *trav;
		*trav = del->link;
		free(del);
	}

	return cost;
}
