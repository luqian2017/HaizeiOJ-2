#include <iostream>
using namespace std;
#define MAX_N 100000
long long a[MAX_N + 5];
long long b[MAX_N + 5];

bool check(long long n, long long m, long long mid) {
    for (long long i = 1; i <= n; i++) {
        b[i] = a[i] - mid;
    }
    for (long long i = 1; i <= n; i++) b[i] += b[i - 1];
    long long pre = 0; //存储前面阴影部分中的最小值
    for (long long i = m; i <= n; i++) {
        pre = min(pre, b[i - m]); //更新阴影中的最小值 
        if (b[i] - pre >= 0) return true; //0相当于那个A值
    }
    return false;
}

long long bs(long long l, long long r, long long n, long long m) {
    if (l == r) return l;
    long long mid = (l + r + 1) >> 1;
    if (check(n, m, mid)) return bs(mid, r, n, m);
    return bs(l, mid - 1, n, m);
}

int main() {
    long long n, m, s, t;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] *= 1000;
        if (i == 1) {
            s = a[i];
            t = a[i];
        }
        s = min(s, a[i]);
        t = max(t, a[i]);
    }
    cout << bs(s, t, n, m) << endl;
    return 0;
}

