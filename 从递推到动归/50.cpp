#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAX_N 32
#define MAX_M 65536
long long dp[MAX_N + 5][MAX_M + 5]; //n个鸡蛋，k次，最多可以测多少层楼

int main() {
    long long n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << m << endl;
        return 0;
    }
    for (long long k = 1; k <= MAX_M; k++) dp[1][k] = k;
    for (long long i = 2; i <= n ; i++) {
        for (long long k = 1; k <= MAX_M; k++) {
            dp[i][k] = dp[i - 1][k - 1] + dp[i][k - 1] + 1;
        }
    }
    long long p = 1;
    while (dp[n][p] < m) p++;
    cout << p << endl;
    return 0;
}
