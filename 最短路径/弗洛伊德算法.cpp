#include <iostream>
#include <cstring>
using namespace std;

int n, m, s, ans[1005][1005];

int main() {
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ans[a][b] = c;
    }
    
    //对角线，自己到自己的距离为0
    for (int i = 1; i <= n; i++) {
        ans[i][i] = 0;
    }

    for (int i = 1; i <= n; i++) { //枚举中间经过了某个点的中转
        for (int j = 1; j <= n; j++) { // 起点
            for (int k = 1; k <= n; k++) {//终点
                ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]); //当经过中间点后，有可能因为距离变大，而导致原距离不更新
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        cout << ans[s][i];
    }
    return 0;
}
