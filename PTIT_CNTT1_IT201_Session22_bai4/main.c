#include <stdio.h>

#define MAX 100

int main() {
    int n;
    int matrix[MAX][MAX];
    int count = 0;

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

    // Đếm cạnh (mỗi cạnh được tính 2 lần)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] == 1) {
                count++;
            }
        }
    }

    printf("So canh trong do thi vo huong: %d\n", count);

    return 0;
}
