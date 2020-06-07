#include <iostream>
using namespace std;
#define MAX_N 200000
#define lowbit(x) (x)&(-x)
long long arr[MAX_N + 5];
long long c[MAX_N + 5];

void add(long long x, int val, int n) {
    while (x <= n) {
        c[x] += val;
        x += lowbit(x);
    }
}

long long query(int x) {
    long long sum = 0;
    while (x) {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}

int main() {
    long long n, lnum = 0, ans1 = 0, ans2 = 0;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> arr[i];
    for (long long i = 1; i <= n; i++) {
        lnum = query(arr[i]);
        ans1 += (arr[i] - 1 - lnum) * lnum;
        ans2 += (i - 1 - lnum) * (n - arr[i] - i + 1 + lnum);
        add(arr[i], 1, n);
    }
    cout << ans2 << " " << ans1;
    return 0;
}
