#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int n;
    int **matrix;
} Graph;

Graph* createGraph(int n) {
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->n = n;
    g->matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g->matrix[i] = (int*)calloc(n, sizeof(int));
    }
    return g;
}

void addEdge(Graph *g, int u, int v) {
    if (u >= 0 && u < g->n && v >= 0 && v < g->n) {
        g->matrix[u][v] = 1;
        g->matrix[v][u] = 1;
    } else {
        printf("Loi: dinh khong hop le.\n");
    }
}

void printGraph(Graph *g) {
    printf("Ma tran ke cua do thi:\n");
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        free(g->matrix[i]);
    }
    free(g->matrix);
    free(g);
}

int main() {
    int n;
    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &n);

    Graph *g = createGraph(n);

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 3);

    printGraph(g);

    freeGraph(g);
    return 0;
}
