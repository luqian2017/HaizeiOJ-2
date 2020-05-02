#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step;
};

int n, m;
char mmap[1005][1005];
int ans[1005][1005];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

int main() {
    cin >> n >> m;
    queue<node> que;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '1') { //以1为起点搜索(广搜)，更快
                que.push({i, j, 0});
                ans[i][j] = -1; //解决 ans数组 1对应位置是0 的问题，用于表示已经搜索过
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 1 || y < 1 || x > n || y > m || ans[x][y]) continue; //越界或者已经搜过
            ans[x][y] = temp.step + 1;
            que.push({x, y, ans[x][y]});
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j != 1) cout << " ";
            if (ans[i][j] == -1) { //解决 ans数组 1对应位置是0 的问题，用于表示已经搜索过
                cout << 0;
            } else {
                cout << ans[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
