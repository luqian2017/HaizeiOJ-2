#include <cstdio>
using namespace std;
//输入数据多用scanf更合适，因为耗时更少，混用最慢
//方法：将行列数求和，然后类比两数之和的做法，但是枚举只能从左下或者右上开始
int n, m, t, num[3005][3005];

int main() {
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    int x = n, y = 1; //左下角
    while (x > 0 && y <= m) { //没找出去就一直找
        if (num[x][y] == t) {
            printf("%d %d\n", x, y);
            return 0;
        }
        if (num[x][y] > t) {
            x--;
        } else {
            y++;
        }
    }
    return 0;
}

