#include <iostream>
#include <cstring>
using namespace std;

int n, m, ans[105][105], x[105], y[105];

int main() {
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ans[a][b] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] != 0x3f3f3f3f) {
                x[i]++;
                y[i]++;
            }
        }
    }
    int fin = 0;
    for (int i = 1; i <= n; i++) {
        if (x[i] + y[i] == n - 1) {
            fin++;
        }
    }
    cout << fin << endl;
    return 0;
}

