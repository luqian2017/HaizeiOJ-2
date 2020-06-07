#include <iostream>
#include <cmath>

using namespace std;
#define MAX_N 100005
int n, num[MAX_N], ans;

int main() {
    cin >> n;
    int ind = (n + 1) / 2 - 1;
    for (int i = 0; i < n ;i++) {
        cin >> num[i];
    }
    for (int i = 0; i < n; i++) {
        ans += abs(num[i] - num[ind]);
    }
    cout << ans << endl;
    return 0;
}

