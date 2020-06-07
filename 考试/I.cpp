#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_N 10000
long long x[MAX_N + 5];
long long y[MAX_N + 5];
long long n;
int main() {
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> x[i];
        cin >> y[i];
    }
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    for (long long i = 1; i <= n; i++) x[i] -= i;
    sort(x + 1, x + n + 1);
    long long tx = x[(n + 1) / 2];
    long long ty = y[(n + 1) / 2];
    long long ans = 0;
    for (long long i = 1; i <= n ; i++) {
        ans += abs(x[i] - tx);
        ans += abs(y[i] - ty);
    }
    cout << ans << endl;
    return 0;
}
