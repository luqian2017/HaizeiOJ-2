#include <iostream>
#include <cmath>
using namespace std;

int f[1005][1005]; //将f[i][i]数组与val数组和在一次，更加方便后面的计算
//f[i][j]从[i][j]点到第边的最大路径/从底边到[i][j]的最大路径
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) { //特别注意循环的边界条件
        for (int j = 1; j <= i; j++) {
            cin >> f[i][j];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= i; j++) {
            f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);//从上往下的状态定义，f[i][j] += max(f[i - 1][j], f[i - 1][j - 1])会出现该点上面的两个点中有一个点不存在（越界访问）
        }
    }
    cout << f[1][1] << endl;
    return 0;
}

