#include <stdio.h>
#include <stdlib.h>

#define MAX_N 35

int main() {
    int n;
    scanf("%d", &n);
    int arr[MAX_N][MAX_N] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        //for (int j = 1; j <= n; j++) {
            printf("%d\n", arr[i][i]);
        //}
    }
    return 0;
}
