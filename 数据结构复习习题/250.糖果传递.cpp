#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_N 1000000
long long arr[MAX_N + 5];
long long s[MAX_N + 5];
long long f[MAX_N + 5];
long long n;

int main() {
    cin >> n;
    s[0] = 0;
    for (long long i = 1; i <= n; i++) cin >> arr[i], s[i] = arr[i] + s[i - 1];
    for (long long i = 1; i <= n; i++) f[i] = s[i] - i * (s[n] / n);
    sort(f + 1, f + n + 1); //注意排序的范围
    long long tf = f[(n + 1) / 2];
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        ans += abs(f[i] - tf);
    }
    cout << ans << endl;
    return 0;
}
