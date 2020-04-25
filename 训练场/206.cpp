#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, sum = 0;
    double arr[35][35];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &arr[i][j]);
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            sum += arr[i][j];
        }
        printf("%d\n", sum);
        sum = 0;
    }
    return 0;
}
