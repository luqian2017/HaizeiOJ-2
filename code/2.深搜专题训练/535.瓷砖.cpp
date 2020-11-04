#include <iostream>
using namespace std;

int m, n, sx, sy, ans;
char mmap[55][55];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};


void func(int sx, int sy) {
    for (int i = 0; i < 4; i++) {
        int dx = sx + dir[i][0];
        int dy = sy + dir[i][1];
        if (mmap[dx][dy] == '.') {
            ans += 1;
            mmap[dx][dy] = '0';
            func(dx, dy);
        }
    }
    return ;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '@') {
                sx = i;
                sy = j;
                ans += 1;
            }
        }
    }
    func(sx, sy);
    cout << ans << endl;
    return 0;
}
