#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
//方法：
//每次取一个权值(距离)最小（近）的点，固定，然后以它为中心取松弛以下其他节点，看能不能然权值更小一些

struct node {
    int now, dist; //now 现在节点的位置， dist起点到该结点的最短路径
    bool operator<(const node &b) const { //重载<符，形成小顶堆
        return this->dist > b.dist;
    }
};

int n, m, s, dis[1005][1005], ans[1005]; //dis 存储的是边与边之间的关系

int main() {
    memset(dis, 0x3F, sizeof(dis));
    memset(ans, 0x3F, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], c); //可能重复输入，重复输入取最优的
    }
    priority_queue<node> que; //优先队列
    que.push({s, 0});
    while (!que.empty()) {
        node t = que.top();
        que.pop();
        if (ans[t.now] != 0x3F3F3F3F) continue; //到该结点的最短路径已经计算过
        ans[t.now]  = t.dist; //固定当前结点，用它去松弛到其他结点的权值（距离）
        for (int i = 1; i <= n; i++) {
            if (dis[t.now][i] != 0x3F3F3F3F && ans[i] == 0x3F3F3F3F) { //目前的点到枚举的i点可达，并且以前没计算过它们之间的最短距离
                que.push({i, t.dist + dis[t.now][i]});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        if (ans[i] != 0x3F3F3F3F) {
            cout << ans[i];
        } else {
            cout << 0x7FFFFFFF; //题目要求如果不可达，则输出2^31 - 1
        }
    }
    return 0;
}
