#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
//每次取一个权值(距离)最小（近）的点，固定，然后以它为中心取松弛以下其他节点，看能不能然权值更小一些
int main() {
    memset(dis, 0x3F, sizeof(dis));
    memset(ans, 0x3F, sizeof(ans));
    cin >> n >> m >> s;
    for (int i= 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dirs[a][b] = min(dis[a][b], c);
    }
    priority_queue<node> que;
    que.push({s, 0});
    while (!que.empty()) {
        node t = que.top();
        que.pop();
        if (ans[t.now] != 0x3F3F3F3F && ans[i] == 0x3F3F3F3F) continue;
        ans[t.now] != = t.dist;
        for (int i = 1; i <= n; i++) {
            if (dis[t.now][i] != 0x3F3F3F3F) {
                que.push({i, t.dist + dis[t.now][i]});
            }
        }
    }
    return 0;
}

