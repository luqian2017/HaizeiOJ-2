#include <iostream>
using namespace std;
#define MAX_N 100000
long long a[MAX_N + 5];
long long b[MAX_N + 5];

bool check(long long mid, long long n, long long m) {
    for (long long i = 1; i <= n; i++) b[i] = a[i] - mid;
    for (long long i = 1; i <= n; i++) b[i] += b[i - 1];
    long long pre = 0;
    for (long long i = m; i <= n; i++) {
        pre = min(pre, b[i - m]);
        if (b[i] - pre >= 0) return true;
    }
    return false;
}

long long bs(long long l, long long r, long long n, long long m) {
    if (l == r) return l;
    long long mid = (l + r + 1) / 2;
    if (check(mid, n, m)) return bs(mid, r, n, m);
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
