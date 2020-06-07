#include <iostream>
using namespace std;
#define MAX_M 25
#define MAX_N 10005
int m, n, val[MAX_M], f[MAX_M][MAX_N];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> val[i];
    }
    for (int i = 1; i <= m; i++) {
        f[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= val[i]) {
                f[i][j] += f[i][j - val[i]];
            }
            f[i][j] %= 9973;
        }
    }
    cout << f[m][n] << endl;
    return 0;
}

