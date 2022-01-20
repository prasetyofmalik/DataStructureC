// graf berarah tak berbobot
#include <stdio.h>
#include <stdlib.h>
#define N 6 // max node = 6

// data strucuture to store adjacency list
struct Node{
    int dest;
    struct Node* next;
};
typedef struct Node *ptrNode;
// data structure to store graph object
struct Graph{
    // array pointer to node for adj. list representation
    ptrNode head[N];
};
typedef struct Graph *ptrGraph;
// data structure to store graph edge
struct Edge{
    int src, dest;
};
// adj. list from edge
ptrGraph createGraph(struct Edge edges[], int n){
    ptrGraph graph = (ptrGraph)malloc(sizeof(struct Graph));
    for (int i=0; i<N; i++){
        graph->head[i] = NULL;
    }
    for (int i=0; i<n; i++){
        int src = edges[i].src;
        int dest = edges[i].dest;

        ptrNode newNode = (ptrNode)malloc(sizeof(struct Node));
        newNode->dest = dest;
        newNode->next = graph->head[src];
        graph->head[src] = newNode;
    }
    return graph;
}
// print the adj. list
void printGraph(ptrGraph graph){
    int i;
    for (i=0; i<N; i++){
        ptrNode ptr = graph->head[i];
        while (ptr != NULL){
            printf("%d -> %d\t", i, ptr->dest);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
void main(){
    struct Edge edges[] = 
        {{0,1}, {1,2}, {2,0}, {2,1}, {3,2}, {4,5}, {5,4}};
    int n = sizeof(edges)/sizeof(edges[0]);
    ptrGraph graph = createGraph(edges, n);
    printGraph(graph);
}