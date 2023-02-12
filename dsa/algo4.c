// bfs not tested

#define MAX 8
#define visited 1
#define unvisited 0
typedef struct {
	int index;
	char label;
} vertex;
typedef struct {
	vertex q[MAX];
	int front, rear;
} Queue;
typedef struct node {
	vertex v;
	struct node *next;
} *vertices;
typedef vertices GRAPH[MAX];
typedef vertex Tree[MAX];

void bfs(vertex v, GRAPH G, Tree t[])
{
	Queue Q;
	vertex x, y;
	int mark[MAX], idx;
	vertices *trav, *temp, del;

	Q.front = 1;
	Q.rear = 0;
	for (idx = 0; idx < MAX; idx++){
		mark[idx] = unvisited;
	}	

	mark[v.index] = visited;
	ENQUEUE(&Q, v);
	while (isEmpty(Q) == 0){
		x = FRONT(Q);
		DEQUEUE(&Q);
		for (trav = G+(x.index); *trav != NULL; trav = &(*trav)->next){
			if (mark[(*trav)->v.index] == unvisited){
				ENQUEUE(&Q, (*trav)->v);
				INSERT(x, (*trav)->v, t);
			}
		}
	}
}

void ENQUEUE(Queue *Q, char v)
{
	Q->rear = (Q->rear+1)%MAX;
	Q->q[Q->rear] = v;
}

int isEmpty(Queue Q)
{
	return (Q.front+1 == Q.rear) 1 : 0;
}

vertex FRONT(Queue Q)
{
	return Q.q[Q.front];
}

void DEQUEUE(Queue *Q)
{
	Q->front = (Q->front+1)%MAX;
}

void INSERT(vertex x, vertex y, Tree t)
{
	t[y.index] = x;
}