#include <iostream>
using namespace std;
#define lowbit(x) ((x) & (-x))
#define MAX_N 200005

int a[MAX_N], c[MAX_N];

void add(int x, int val, int n) {
    while (x <= n) {
        c[x] += val;
        x += lowbit(x);
    }
    return ;
}

int query(int x) {
    int sum = 0;
    while (x) {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}

int main() {
    int n;
    long long int lnum, ans1 = 0, ans2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        lnum = query(a[i]);
        ans1 += (a[i] - 1 - lnum) * lnum;
        ans2 += (i - 1 - lnum) * (n - a[i] - i + 1 + lnum);
        add(a[i], 1, n);
    }
    cout << ans2 << " " << ans1 << endl;
    return 0;
}
