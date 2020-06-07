#include <iostream>
using namespace std;
#define MAX_N 100000
int a[MAX_N + 5], dp[MAX_N + 5];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1; //自身的长度
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] >= a[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
