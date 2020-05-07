#include <iostream>
using namespace std;
/*完全背包
 * 1、只要差别在同一个物品不再是只有一件，而是多件，所以可要可不要那种情况时，x就可以不用 -1 了
 * 2、因为没压缩，此代码过不了*/
int all, n, w[10005], v[10005], ans[10005][10005]; //状态定义，前x件物品，背包容量为y时的最大价值


int main() {
    cin >> n >> all;
    for (int i = 1; i <= n; i++) { //从1开始存，可以避免访问x-1时出现访问越界，同时也让第一行不够买时，从上一行抄下来的数是0
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= all; j++) {
            if (j < w[i]) { //买不起
                ans[i][j] = ans[i - 1][j];
            } else { //买得起，买得起的情况下又分两种情况，我可拿可，我也可不拿，选其中价值大的那个
                ans[i][j] = max(ans[i - 1][j], v[i] + ans[i][j - w[i]]);
            }
        }
    }
    cout << ans[n][all] << endl;
    return 0;
}
