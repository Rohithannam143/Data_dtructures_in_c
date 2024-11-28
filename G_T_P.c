#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 5

// Structure for a graph
typedef struct Graph {
    int adj[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
    int visited[MAX_VERTICES]; // Array to track visited nodes
} Graph;

// Function to initialize the graph
void initGraph(Graph* g) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            g->adj[i][j] = 0; // Initialize all edges as 0 (no edges)
        }
        g->visited[i] = 0; // Initialize all vertices as unvisited
    }
}

// Function to add an edge between two vertices
void addEdge(Graph* g, int u, int v) {
    g->adj[u][v] = 1; // Create an edge from u to v
    g->adj[v][u] = 1; // Create an edge from v to u (undirected graph)
}

// Depth-First Search (DFS) using recursion
void dfs(Graph* g, int vertex) {
    printf("%d ", vertex);
    g->visited[vertex] = 1; // Mark the current vertex as visited

    // Recur for all the adjacent vertices
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (g->adj[vertex][i] == 1 && !g->visited[i]) {
            dfs(g, i);
        }
    }
}

// Breadth-First Search (BFS) using a queue
void bfs(Graph* g, int start) {
    int queue[MAX_VERTICES], front = 0, rear = 0;
    g->visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++]; // Dequeue
        printf("%d ", current);

        // Visit all the adjacent unvisited vertices
        for (int i = 0; i < MAX_VERTICES; i++) {
            if (g->adj[current][i] == 1 && !g->visited[i]) {
                g->visited[i] = 1; // Mark as visited
                queue[rear++] = i;  // Enqueue
            }
        }
    }
}

int main() {
    Graph g;
    initGraph(&g); // Initialize the graph

    // Add edges to the graph
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 4);

    printf("Depth-First Search (DFS) starting from vertex 0:\n");
    dfs(&g, 0);  // Perform DFS starting from vertex 0
    printf("\n");

    // Reset visited array before BFS
    for (int i = 0; i < MAX_VERTICES; i++) {
        g.visited[i] = 0;
    }

    printf("Breadth-First Search (BFS) starting from vertex 0:\n");
    bfs(&g, 0);  // Perform BFS starting from vertex 0
    printf("\n");

    return 0;
}

