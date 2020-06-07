#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
//Dijksta + 链式前向星

//链式用于前向星，存储边与边之间的关系
struct node {
    int e, dist, next; // 终点，权值（距离），下一条边的编号（起点决定）
};

//用于Dijkstra
struct point {
    int now, dist;
    bool operator< (const point &b) const {
        return this->dist > b.dist;
    }
};


int n, m, s, cnt,  ans[10005], head[10005];
node edge[500005];
char mark[10005][10005];

int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >>c;
        if (!mark[a][b]) {
            edge[cnt].e = b;
            edge[cnt].dist = c;
            edge[cnt].next = head[a];
            head[a] = cnt; //存储边的编号
            cnt++;
        } else { //输入中有重复的边
            int ind = head[a];
            while (edge[ind].e != b) {
                ind = edge[ind].next;
            }
            edge[ind].dist = min(edge[ind].dist, c);
        }
    }
    priority_queue<point> que;
    que.push({s, 0});
    while (!que.empty()) {
        point t = que.top();
        que.pop();
        if (ans[t.now] != 0x3f3f3f3f) continue;
        ans[t.now] = t.dist;
        for (int i = head[t.now]; i != -1; i = edge[i].next) { //有以i为起点的边存在
            if (ans[edge[i].e] == 0x3f3f3f3f) que.push({edge[i].e, t.dist + edge[i].dist}); //相应位置的终点未被计算过，原来的最短距离加上 目前存在的边，得到 到终点的最短距离
        }
    }
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        if (ans[i] == 0x3f3f3f3f) cout << 0x7fffffff;
        else cout << ans[i];
    }
    cout << endl;
    return 0;
}
