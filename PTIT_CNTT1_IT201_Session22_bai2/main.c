#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int n;
    Node** adjList;
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
    g->adjList = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        g->adjList[i] = NULL;
    }
    return g;
}

void addEdge(Graph* g, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = g->adjList[u];
    g->adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = g->adjList[v];
    g->adjList[v] = newNode;
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
    free(g->adjList);
    free(g);
}

int main() {
    int n;
    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &n);

    Graph* g = createGraph(n);

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 3);

    printGraph(g);

    freeGraph(g);
    return 0;
}
