#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 5
long long cnt[MAX_N + 5];
long long k;

void solve(long long k) {
    if (k == 0) return ;
    memset(cnt, 0, sizeof(cnt));
    for (long long i = 0; i < k; i++) cin >> cnt[i];
    long long f[cnt[0] + 1][cnt[1] + 1][cnt[2] + 1][cnt[3] + 1][cnt[4] + 1]; //根据需要大小开数组
    memset(f, 0, sizeof(f));
    f[0][0][0][0][0] = 1; //赋予初始值
    for (long long i0 = 0; i0 <= cnt[0]; i0++) {
        for (long long i1 = 0; i1 <= cnt[1]; i1++) {
            for (long long i2 = 0; i2 <= cnt[2]; i2++) {
                for (long long i3 = 0; i3 <= cnt[3]; i3++) {
                    for (long long i4 = 0; i4 <= cnt[4]; i4++) {
                        long long val = f[i0][i1][i2][i3][i4];
                        if (i0 >= i1 && i0 >= i2 && i0 >= i3 && i0 >= i4 && i0 < cnt[0])
                            f[i0 + 1][i1][i2][i3][i4] += val; //别加反了，注意累加的谁
                        if (i1 >= i2 && i1 >= i3 && i1 >= i4 && i1 < cnt[1])
                            f[i0][i1 + 1][i2][i3][i4] += val;
                        if (i2 >= i3 && i3 >= i4 && i2 < cnt[2])
                            f[i0][i1][i2 + 1][i3][i4] += val;
                        if (i3 >= i4 && i3 < cnt[3] && i3 < cnt[3])
                            f[i0][i1][i2][i3 + 1][i4] += val;
                        if (i4 < cnt[4] && i4 < cnt[4])
                            f[i0][i1][i2][i3][i4 + 1] += val;
                    }
                }
            }
        }
    }
    cout << f[cnt[0]][cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl;
    return ;
    }

int main() {
    while (cin >> k) solve(k);
    return 0;
}
