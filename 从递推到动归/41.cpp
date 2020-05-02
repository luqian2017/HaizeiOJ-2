#include <iostream>
using namespace std;

int f[1005][15][15];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            f[1][i][j] = (i == j); //只有一块砖，首尾颜色必须一致
        }
    }
    for (int t = 2; t <= n; t++) { //从第二块砖开始
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                for (int l = 0; l < k; l++) { //累加
                    if (l - j) f[t][i][j] += f[t - 1][i][l]; //不考虑环，求首尾颜色不同的方法总数
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

