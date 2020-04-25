#include <stdio.h>
#include <stdlib.h>

#define MAX_N 105

int main() {
    int n, arr[MAX_N] = {0}, num, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d ", &arr[i]);
    }
    scanf("%d", &num);
    for (int i = 1; i <= n; i++) {
        if (num == arr[i]) ans = i;
    }
    printf("%d\n", ans);
    return 0;
}
