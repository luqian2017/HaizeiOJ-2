#include <iostream>
using namespace std;

int n, m, num[100005], mmax;

int check(int mid) {
    int cnt = 1, now = 0;
    for (int i = 1; i < n; i++) {
        if (num[i] - num[now] >= mid) {
            cnt++;
            now = i;
        }
    }
    return cnt;
}

int func() {
    int l = 1, r = mmax;
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int cnt = check(mid);
        if (cnt >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return 1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        //主函数
    }
    return 0;
}
