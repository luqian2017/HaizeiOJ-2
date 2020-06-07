#include <iostream>
#include <cstring>
using namespace std;

int n, m, s, dis[100005][3], ans[10005];

int main() {
    memset(ans, 0x3F, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dis[i][0] = a;
        dis[i][1] = b;
        dis[i][2] = c;
    }
    ans[s] = 0;
    //遍历的是边的关系，但必须要遍历i次
    for (int i = 2; i <= n; i++) { //抛去起点外，剩下的点的个数
        for (int j = 0; j < m; j++) { //用边去松弛边到达的点
            ans[dis[j][1]] = min(ans[dis[j][1]], ans[dis[j][0]] + dis[j][2]);
            //终点 = 起点 加上 边上的权值
            //缺点：就算有些值已经被更新了，循环还是会去遍历和计算（还有后面未松动到的边）
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        cout << ans[i];
    }

    return 0;
}
