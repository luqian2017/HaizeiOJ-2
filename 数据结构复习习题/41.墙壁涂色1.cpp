#include <iostream>
using namespace std;

int f[1005][15][15];

int main() {
    int n, k;
    cin >> n >> k;
    /*先把f[1][i][j]求出来*/
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            f[1][i][j] = (i == j);
        }
    }

    for (int t = 2; t <= n; t++) { //枚举方块数
        for (int i = 0; i < k; i++) { //枚举首涂什么颜色
            for (int j = 0; j < k; j++) { //枚举尾涂什么颜色
                for (int l = 0; l < k; l++) { //枚举 n - 1 块涂什么颜色（k != j）
                    if (l - j) f[t][i][j] += f[t - 1][i][l];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (i - j) ans += f[n][i][j];
        }
    }
    cout << ans << endl;
    return 0;
}

