#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct Edge {
    int target;
    int weight;
    struct Edge *next;
} Edge;

typedef struct {
    int numVertices;
    Edge **adjList;
} Graph;

Graph* createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjList = (Edge **)malloc(vertices * sizeof(Edge *));
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest, int weight) {
    // Add edge from src to dest
    Edge *newEdge1 = (Edge *)malloc(sizeof(Edge));
    newEdge1->target = dest;
    newEdge1->weight = weight;
    newEdge1->next = graph->adjList[src];
    graph->adjList[src] = newEdge1;

}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Edge *edge = graph->adjList[i];
        while (edge) {
            Edge *tmp = edge;
            edge = edge->next;
            free(tmp);
        }
    }

}




typedef struct {
    int vertex;
    int dist;
} HeapNode;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}


int extractMin(HeapNode *heap, int size, int *inQueue) {
    int minIndex = -1;
    int minDist = INF;

    for (int i = 0; i < size; i++) {
        if (inQueue[i] && heap[i].dist < minDist) {
            minDist = heap[i].dist;
            minIndex = i;
        }
    }
    if (minIndex != -1) {
        inQueue[minIndex] = 0; 
    }
    return minIndex;
}

void dijkstra(Graph *graph, int src) {
    int V = graph->numVertices;
    int dist[V], inQueue[V];
    HeapNode heap[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        inQueue[i] = 1;  
        heap[i].vertex = i;
        heap[i].dist = INF;
    }

    dist[src] = 0;
    heap[src].dist = 0;

    while (1) {
        int u = extractMin(heap, V, inQueue);
        if (u == -1) break;

        for (Edge *edge = graph->adjList[u]; edge != NULL; edge = edge->next) {
            int v = edge->target;
            int weight = edge->weight;

            if (inQueue[v] && dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                heap[v].dist = dist[v];
            }
        }
    }

    printf("Vertex distance from source %d\n", src);
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}


int main() {
    int vertices = 5;
    Graph *graph = createGraph(vertices);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 3);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 4, 4);
    addEdge(graph, 2, 3, 9);
    addEdge(graph, 3, 2, 7);
    addEdge(graph, 4, 1, 1);
    addEdge(graph, 4, 2, 8);
    addEdge(graph, 4, 3, 2);

    dijkstra(graph, 0);

    freeGraph(graph);
    return 0;
}


