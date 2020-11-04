#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int n, m, k, ans;
char mmap[3005][3005];
int check[3005][3005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

struct node {
    int x, y;
};

queue<node> que;

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
        if (mmap[tx][ty] != mmap[x][y] && !check[tx][ty]) {
            ans += 1;
            check[tx][ty] = 1;
            que.push({tx, ty});
            func(tx, ty);
        }
    }
    return ;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> (&mmap[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!check[i][j]) {
                ans = 1;
                check[i][j] = 1;
                que.push({i, j});
                func(i, j);
                while (!que.empty()) {
                    node temp = que.front();
                    que.pop();
                    check[temp.x][temp.y] = ans;
                }
            }
        }
    }
    while (k--) {
        int x, y;
        cin >> x >> y;
        cout << check[x][y] << endl;
    }
    return 0;
}
