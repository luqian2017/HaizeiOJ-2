#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int l, r;
};

bool cmp(node &a, node &b) {
    return a.l < b.l;
}

node sw[100005];
int n, m, ans;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> sw[i].l >> sw[i].r;
    }
    sort(sw + 1, sw + n + 1, cmp);
    int last = -1, raw_i = -1;
    for (int i = 0; i < m; ) {
        if (last == n || raw_i == i) {
            ans = -1;
            break;
        }
        raw_i = i;
        for (int j = last + 1; j <= n && sw[j].l <= raw_i; j++) {
            if (sw[j].r > i) {
                i = sw[j].r;
            }
            last = j;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}

