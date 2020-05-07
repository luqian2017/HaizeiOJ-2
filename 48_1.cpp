#include <iostream>
using namespace std;
/*完全背包数组压缩
 * 1、从第推公式能发现，下一行x的状态与它所在这行前面的某个数据和它头顶的数据有关
 *    所以必须从前往后算，这样才能知道前面的数值*/
int all, n, w[10005], v[10005], ans[10005]; //状态定义，前x件物品，背包容量为y时的最大价值


int main() {
    cin >> n >> all;
    for (int i = 1; i <= n; i++) { //从1开始存，可以避免访问x-1时出现访问越界，同时也让第一行不够买时，从上一行抄下来的数是0
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= all; j++) {
            if (j >= w[i]) { //小于不用改,本来就没变化
                ans[j] = max(ans[j], ans[j - w[i]] + v[i]);
            }
        }
    }
    cout << ans[all] << endl;
    return 0;
}
