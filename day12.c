#include <stdio.h>

int main() {
    int m, n;

    // Read rows and columns
    scanf("%d %d", &m, &n);

    int a[100][100], b[100][100], sum[100][100];
    int i, j;

    // Read first matrix
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Read second matrix
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Add matrices
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    // Print result
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
