#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10005

int main() {
    int arr[MAX_N] = {0}, l, m, h, t, ans = 0;
    scanf("%d %d", &l, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &h, &t);
        for (int j = h; j <= t; j++) {
            arr[j] = 1;
        }
    }
    for (int i = 0; i <= l; i++) {
        if (arr[i] == 1) continue;
        ans += 1;
    }
    printf("%d\n", ans);
    return 0;
}
