#include <iostream>
using namespace std;

int f[25][10005], val[10005];

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> val[i];
    for (int i = 1; i <= m; i++) {
        f[i][0] = 1;
        for (int j = 1; j <= n; j++) { //易错, j 从1开始枚举
            f[i][j] = f[i - 1][j];
            if (j >= val[i]) f[i][j] += f[i][j - val[i]];
            f[i][j] %= 9973;
        }
    }
    cout << f[m][n] << endl;
    return 0;
}

