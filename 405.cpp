#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
char mmap[3005][3005];
char check=[3005][3005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
queue<node> que;

void func(int x, int y) {
    for (int i = 0; i< 4; i++) {
        int tx = x + dir[i][0];
        int ty = x + dir[i][1];
        if (check[tx]t[y]) = 1;
        que.push({tx, ty});
        func(tx, ty);
}


int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> (&mmap[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check[i][j] == 0) {
                cheack[i][j] = 1;
                que.push({i, j});
                func(i, j);
                while (!que.empty())
            }
        }
    }
    return 0;
}
