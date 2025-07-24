#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int n;
    Node* adjList[MAX];
} Graph;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int n) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    for (int i = 0; i < n; i++) {
        g->adjList[i] = NULL;
    }
    return g;
}

void addEdge(Graph* g, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = g->adjList[u];
    g->adjList[u] = newNode;
}

void matrixToAdjList(Graph* g, int matrix[MAX][MAX]) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            if (matrix[i][j] == 1) {
                addEdge(g, i, j);
            }
        }
    }
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->n; i++) {
        printf("Dinh %d: ", i);
        Node* temp = g->adjList[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(Graph* g) {
    for (int i = 0; i < g->n; i++) {
        Node* temp = g->adjList[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(g);
}

int main() {
    int n;
    int matrix[MAX][MAX];

    printf("Nhap so dinh (0 < n < 100): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 100) {
        printf("So dinh khong hop le.\n");
        return 1;
    }

    printf("Nhap ma tran ke (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    Graph* g = createGraph(n);
    matrixToAdjList(g, matrix);

    printf("\nDanh sach ke cua do thi:\n");
    printGraph(g);

    freeGraph(g);
    return 0;
}
