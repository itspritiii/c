/*
   Graph algorithms in C:
   a) Adjacency Matrix for a 4x4 input matrix
   b) Adjacency List for a 4x4 input matrix
   c) BFS traversal of a given graph G
   d) DFS traversal of a given graph G
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define SIZE 4

void inputMatrix(int graph[SIZE][SIZE]) {
    int i, j;
    printf("Enter the 4x4 adjacency matrix (0/1 values):\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

void printMatrix(int graph[SIZE][SIZE]) {
    int i, j;
    printf("\nAdjacency Matrix:\n");
    printf("    0  1  2  3\n");
    printf("   ------------\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d | ", i);
        for (j = 0; j < SIZE; j++) {
            printf("%2d ", graph[i][j]);
        }
        printf("\n");
    }
}

void buildAdjacencyList(int graph[SIZE][SIZE], int adjList[SIZE][MAX], int count[SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        count[i] = 0;
        for (j = 0; j < SIZE; j++) {
            if (graph[i][j] != 0) {
                adjList[i][count[i]++] = j;
            }
        }
    }
}

void printAdjacencyList(int adjList[SIZE][MAX], int count[SIZE]) {
    int i, j;
    printf("\nAdjacency List:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d -> ", i);
        if (count[i] == 0) {
            printf("NULL\n");
        } else {
            for (j = 0; j < count[i]; j++) {
                printf("%d", adjList[i][j]);
                if (j != count[i] - 1) {
                    printf(" -> ");
                }
            }
            printf("\n");
        }
    }
}

void BFS(int graph[SIZE][SIZE], int start) {
    int queue[SIZE], front = 0, rear = 0;
    int visited[SIZE] = {0};
    int current, neighbor;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS traversal starting from vertex %d: ", start);
    while (front < rear) {
        current = queue[front++];
        printf("%d ", current);
        for (neighbor = 0; neighbor < SIZE; neighbor++) {
            if (graph[current][neighbor] && !visited[neighbor]) {
                visited[neighbor] = 1;
                queue[rear++] = neighbor;
            }
        }
    }
    printf("\n");
}

void DFSUtil(int graph[SIZE][SIZE], int vertex, int visited[SIZE]) {
    int neighbor;
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (neighbor = 0; neighbor < SIZE; neighbor++) {
        if (graph[vertex][neighbor] && !visited[neighbor]) {
            DFSUtil(graph, neighbor, visited);
        }
    }
}

void DFS(int graph[SIZE][SIZE], int start) {
    int visited[SIZE] = {0};
    printf("\nDFS traversal starting from vertex %d: ", start);
    DFSUtil(graph, start, visited);
    printf("\n");
}

int main() {
    int graph[SIZE][SIZE];
    int adjList[SIZE][MAX];
    int count[SIZE];
    int start;
    clock_t start_time, end_time;
    double elapsed_time;

    start_time = clock();

    printf("\nGraph Algorithms Program\n");
    printf("\nEnter the starting vertex for BFS/DFS (0 to 3): ");
    scanf("%d", &start);
    inputMatrix(graph);
    printMatrix(graph);
    buildAdjacencyList(graph, adjList, count);
    printAdjacencyList(adjList, count);
    if (start < 0 || start >= SIZE) {
        printf("Invalid vertex. Using 0 as default starting vertex.\n");
        start = 0;
    }
    BFS(graph, start);
    DFS(graph, start);
    end_time = clock();
    elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTotal completion time: %.6f seconds\n", elapsed_time);

    return 0;
}

