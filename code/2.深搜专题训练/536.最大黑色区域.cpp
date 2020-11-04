#include <iostream>
#include <cmath>
#include <cinttypes>
using namespace std;

int n, m, ans, mmax, dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[105][105];

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (mmap[tx][ty] == '1') {
            ans += 1;
            mmap[tx][ty] = '0';
            func(tx, ty);
        }
    }
    return ;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (&mmap[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mmap[i][j] == '1') {
                mmap[i][j] = '0';
                ans = 1;
                func(i, j);
                mmax = max(mmax, ans);
            }
        }
    }
    cout << mmax << endl;
    return 0;
}
