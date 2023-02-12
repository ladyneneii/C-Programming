typedef int Matrix[MAX][MAX];
typedef int RetVal[MAX];
typedef int Vertex;
typedef struct {
	Vertex vertices[MAX];
	int vctr;
} Vertices;

RetVal *Dijkstra(Matrix M, int source, Vertices V)
{
	RetVal *R = (RetVal *)malloc(sizeof(RetVal));

	if (*R != NULL){
        Vertices S;
        int idx, w, x, allow;

        // initialise R and S
        for (idx = 0; idx < MAX; idx++){
            if (idx != source){
                S.vertices[idx] = 0;
                (*R)[idx] = M[source][idx];
            }
        }
        S.vertices[source] = 1;

        for (idx = 0; idx < MAX-1; idx++){
            // a.
            for (allow = x = 0; x < MAX; x++){
                if (S[x] != V[x] && (allow == 0 || (*R)[w] > (*R)[x])){
                    w = x;
                    allow++;
                }
            }
            
            // b.
            S.vertices[w] = 1;
            S.vctr++;

            // c.
            for (x = 0; x < MAX; x++){
                if (S[x] != V[x]){
                    (*R)[x] = min((*R)[x], (*R)[w] + M[w][x]);
                }
            }
        }
    }

	return R;
}

int min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}