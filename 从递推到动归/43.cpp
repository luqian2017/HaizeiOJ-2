#include <iostream>
using namespace std;
//学习状态定义技巧
#define MAX_N 1000
int f[MAX_N + 5][MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> f[i][j];
        }
    }
    for (int i = n - 1; i >= 1; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] += max(f[i - 1][j], f[i - 1][j - 1]);//f[i][j]表示该点到最底行的最大路径
            //如果状态定义为f[i][j]表示顶点到该点的距离，那么可能会出现下一个阶段（下一行），推上一个阶段(上一行),会出现两端点不存在的情况
        }
    }
    cout << f[1][1] << endl;
    return 0;
}

