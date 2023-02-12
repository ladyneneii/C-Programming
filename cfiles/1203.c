/*
#include <stdio.h>
#include <stdlib.h>

struct AdjListNode {
	int dest;
	struct AdjListNode* next;
};

struct AdjList {
	struct AdjListNode* head;
};

struct Graph {
	int V;
	struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest)
{
	struct AdjListNode* newNode
		= (struct AdjListNode*)malloc(
			sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int V)
{
	struct Graph* graph
		= (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;

	graph->array = (struct AdjList*)malloc(
		V * sizeof(struct AdjList));

	int i;
	for (i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
	struct AdjListNode* check = NULL;
	struct AdjListNode* newNode = newAdjListNode(dest);

	if (graph->array[src].head == NULL) {
		newNode->next = graph->array[src].head;
		graph->array[src].head = newNode;
	}
	else {

		check = graph->array[src].head;
		while (check->next != NULL) {
			check = check->next;
		}
		check->next = newNode;
	}

	newNode = newAdjListNode(src);
	if (graph->array[dest].head == NULL) {
		newNode->next = graph->array[dest].head;
		graph->array[dest].head = newNode;
	}
	else {
		check = graph->array[dest].head;
		while (check->next != NULL) {
			check = check->next;
		}
		check->next = newNode;
	}

}

void printGraph(struct Graph* graph)
{
	int v;
	for (v = 0; v < graph->V; ++v) {
		struct AdjListNode* pCrawl = graph->array[v].head;
		printf("\n Adjacency list of vertex %d\n head ", v);
		while (pCrawl) {
			printf("-> %d", pCrawl->dest);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}

int main()
{
	int V = 5;
	struct Graph* graph = createGraph(V);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	printGraph(graph);

	return 0;
}
*/

// Adjacency Matrix representation in C

#include <stdio.h>
#define V 4

// Initialize the matrix to zero
void init(int arr[][V]) {
  int i, j;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      arr[i][j] = 0;
}

// Add edges
void addEdge(int arr[][V], int i, int j) {
  arr[i][j] = 1;
  arr[j][i] = 1;
}

// Print the matrix
void printAdjMatrix(int arr[][V]) {
  int i, j;

  for (i = 0; i < V; i++) {
    printf("%d: ", i);
    for (j = 0; j < V; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int adjMatrix[V][V];

  init(adjMatrix);
  addEdge(adjMatrix, 0, 1);
  addEdge(adjMatrix, 0, 2);
  addEdge(adjMatrix, 1, 2);
  addEdge(adjMatrix, 2, 0);
  addEdge(adjMatrix, 2, 3);

  printAdjMatrix(adjMatrix);

  return 0;
}

