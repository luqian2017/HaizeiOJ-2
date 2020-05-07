#include <iostream>
#include <algorithm>
using namespace std;
/*01背包问题，最大的变化就是商品的价值，money，val，分别类比对应重量和价值*/
int money_all, n, money[30], val[30], ans[30005];

int main() {
    cin >> money_all >> n;
    for (int i = 1; i <= n; i++) {
        cin >> money[i] >> val[i];
        val[i] *= money[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = money_all; j > 0; j--) {
            if (j < money[i]) {
                break;
            } else {
                ans[j] = max(ans[j], ans[j - money[i]] + val[i]);
            }
        }
    }
    cout << ans[money_all] << endl;
    return 0;
}
