#include <iostream>
using namespace std;

int f[1005][15];

int main() {
    int n, k;
    cin >> n >> k;
    for (int j = 0; j < k; j++) {
        f[1][j] = (j == 0);
    }

    for (int t = 2; t <= n; t++) { //枚举方块数
        for (int j = 0; j < k; j++) { //枚举尾涂什么颜色
            for (int l = 0; l < k; l++) { //枚举 n - 1 块涂什么颜色（k != j）
                if (l - j) f[t][j] += f[t - 1][l];
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < k; j++) {
        if (j != 0) ans += f[n][j];
    }
    cout << ans * k << endl;
    return 0;
}

