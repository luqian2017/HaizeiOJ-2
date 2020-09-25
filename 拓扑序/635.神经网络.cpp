#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct edge {
    int to, val, next;
};

edge edg[10005];
int n, m, head[105], in_degress[105], out_degress[105], c[105], u[105];

int main() {
    memset(head, - 1, sizeof(head));
    queue<int> que;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> u[i];
        if (c[i] != 0) {
            que.push(i);
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edg[i].to = b;
        edg[i].val = c;
        edg[i].next = head[a];
        head[a] = i;
        in_degress[b]++;
        out_degress[a]++;
    }
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        for (int i = head[t]; i != -1; i = edg[i].next) {
            int e = edg[i].to, v = edg[i].val;
            if (c[t] > 0) {
                c[e] += v * c[t];
            }
            in_degress[e]--;
            if (in_degress[e] == 0) {
                que.push(e);
                c[e] -= u[e];
            }
        }
    }
    int f = 0;
    for (int i = 1; i <= n; i++) {
        if (out_degress[i] == 0 && c[i] > 0) {
            cout << i << " " << c[i] << endl;
            f = 1;
        }
    }
    if (f == 0) {
        cout << "NULL" << endl;
    }
    return 0;
}
