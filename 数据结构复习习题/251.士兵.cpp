#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_N 10000
int x[MAX_N + 5];
int y[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    /*先排序*/
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    /*对x数组进行特殊处理*/
    for (int i = 1; i <= n; i++) x[i] -= i;//X - x -i = X - i - x ,X原来位置，x目标位置， i为每个新坐标相对于第一个元素的新坐标的相对距离（这样处理后相当于把所有X点移动到x点）

    sort(x + 1, x + n + 1);
    int tx = x[(n + 1) / 2], ty = y[(n + 1) / 2], ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(x[i] - tx);
        ans += abs(y[i] - ty);
    }
    cout << ans << endl;
    return 0;
}
