
#include <stdio.h>
#include <string.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;
char files[MAX][50];

// Breadth-First Search (BFS)
void BFS(int start, char target[]) {
    int queue[MAX];
    int front = 0, rear = 0;
    int found = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];

        printf("%s ", files[current]);

        if (strcmp(files[current], target) == 0)
            found = 1;

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    if (found)
        printf("\nBFS: File found!\n");
    else
        printf("\nBFS: File not found!\n");
}

// Depth-First Search (DFS)
void DFS(int current, char target[], int *found) {
    visited[current] = 1;

    printf("%s ", files[current]);

    if (strcmp(files[current], target) == 0)
        *found = 1;

    for (int i = 0; i < n; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            DFS(i, target, found);
        }
    }
}

int main() {
    int start;
    char target[50];

    printf("Enter number of files/folders (max %d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of files/folders!\n");
        return 1;
    }

    printf("\nEnter file/folder names (no spaces):\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i + 1);
        scanf("%49s", files[i]);
    }

    printf("\nEnter the adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] != 0 && graph[i][j] != 1) {
                printf("Matrix values must be 0 or 1!\n");
                return 1;
            }
        }
    }

    printf("\nEnter starting node number (1 to %d): ", n);
    scanf("%d", &start);

    if (start < 1 || start > n) {
        printf("Invalid starting node!\n");
        return 1;
    }

    start--;

    printf("Enter file/folder to search: ");
    scanf("%49s", target);

    BFS(start, target);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int found = 0;

    printf("\nDFS Traversal: ");
    DFS(start, target, &found);

    if (found)
        printf("\nDFS: File found!\n");
    else
        printf("\nDFS: File not found!\n");

    return 0;
}
