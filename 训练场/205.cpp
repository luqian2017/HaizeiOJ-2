#include <stdio.h>
#include <stdlib.h>

#define MAX_N 35

int main() {
    int n, m, arr[MAX_N][MAX_N];
    double sum = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += arr[i][j];
        }
        printf("%.6lf\n", sum / m);
        sum = 0;
    }
    return 0;
}
