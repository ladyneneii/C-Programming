// dfs not tested

#define MAX 6
#define visited 0
#define unvisited -1
typedef int vertex;
typedef struct cell {
	vertex v;
	struct cell *link;
} *VType;
typedef VType vertices[MAX];

void dfs(vertex v, int mark[], vertices L)
{
	VType trav;
	vertex w;

	mark[v] = visited;
	for (trav = L[v]; trav != NULL; trav = trav->link){
		w = trav->v;
		if (mark[w] == unvisited){
			dfs(w, mark, L);
		}
	}
}


// bfs & dfs cursor

#define visited 1
#define unvisited 0
#define MAX 6
#define MAX_CURSOR 20

typedef int vertex;
typedef int Head[MAX];
typedef struct {
	vertex Adj[MAX_CURSOR], last;
} CBNode;
typedef struct {
	vertex v[MAX];
	int front, rear;
} Queue;
typedef vertices Tree[MAX];

void dfs(Head h, CBNode *space, int mark[], vertex v)
{
	vertex w;
	int idx;

	mark[v] = visited;

	for (idx = h[v], w = space->Adj[idx]; w != -1; idx++, w = space->Adj[idx]){
		if (mark[w] == unvisited){
			dfs(h, space, mark, w);
		}
	}
}

void bfs(Head h, CBNode *space, int mark[], Tree T, vertex v)
{
	Queue Q;
	vertex x, y;
	int idx;

	Q.front = 1;
	Q.rear = 0;
	mark[v] = visited; 
	ENQUEUE(&Q, v);
	while (isEmpty(Q) == 0){
		x = FRONT(Q);
		DEQUEUE(&Q);
		for (idx = h[x], y = space->Adj[idx]; y != -1; idx++, y = space->Adj[idx]){
			if (mark[y] == unvisited){
				mark[y] == visited;
				ENQUEUE(&Q, y);
				INSERT(x, y, T);
			}
		}
	}
}

void ENQUEUE(Queue *Q, vertex v)
{
	Q->rear++;
	Q->v[Q->rear] = v;
}

int isEmpty(Queue Q)
{
	return (Q.rear+1 == Q.front) 1 : 0;
}

vertex FRONT(Queue Q)
{
	return Q.v[Q.front];
}

void DEQUEUE(Queue *Q)
{
	Q->front++;
}

void INSERT(vertex x, vertex y, Tree T)
{
	T[y] = x;
}