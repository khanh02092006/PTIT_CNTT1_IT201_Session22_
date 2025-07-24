#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int adj[MAX][MAX];
int v, e;

void DFS(int u) {
    visited[u] = 1;
    printf("%d ", u);
    for (int i = 0; i < v; i++) {
        if (adj[u][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int start;

    printf("Nhap so dinh (0 < v < 100): ");
    scanf("%d", &v);
    printf("Nhap so canh (0 < e < 100): ");
    scanf("%d", &e);

    if (v <= 0 || v >= 100 || e <= 0 || e >= 100) {
        printf("Gia tri khong hop le.\n");
        return 1;
    }

    for (int i = 0; i < v; i++) {
        visited[i] = 0;
        for (int j = 0; j < v; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Nhap danh sach %d canh (u v):\n", e);
    for (int i = 0; i < e; i++) {
        int u, vtx;
        scanf("%d %d", &u, &vtx);
        adj[u][vtx] = 1;
        adj[vtx][u] = 1;
    }

    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);

    printf("DFS bat dau tu dinh %d:\n", start);
    DFS(start);

    return 0;
}
