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

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Edge *edge = graph->adjList[i];
        printf("Vertex %d:\n", i);
        while (edge) {
            printf(" -> %d (Weight %d)\n", edge->target, edge->weight);
            edge = edge->next;
        }
        printf("\n");
    }
}


void floydWarshall(Graph *graph) {
    int V = graph->numVertices;
    int dist[V][V];

    // Initialize the distance matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // Convert from adjacency list to adjacency matrix
    for (int i = 0; i < V; i++) {
        for (Edge *e = graph->adjList[i]; e != NULL; e = e->next) {
            dist[i][e->target] = e->weight;
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest path matrix
    printf("Shortest paths between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices = 4;
    Graph *graph = createGraph(vertices);

    // Add edges to the graph
    // Example graph:
    // 0 -> 1 (3)
    // 0 -> 3 (7)
    // 1 -> 3 (1)
    // 2 -> 0 (6)
    // 2 -> 3 (2)
    // 3 -> 0 (1)
    addEdge(graph, 0, 1, 3);
    addEdge(graph, 0, 3, 7);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 0, 6);
    addEdge(graph, 2, 3, 2);
    addEdge(graph, 3, 0, 1);

    // Print the graph's adjacency list
    printf("Graph's adjacency list:\n");
    printGraph(graph);
    
    // Run the Floyd-Warshall algorithm
    printf("\nRunning Floyd-Warshall algorithm...\n");
    floydWarshall(graph);

    // Clean up the graph
    freeGraph(graph);

    return 0;
}
