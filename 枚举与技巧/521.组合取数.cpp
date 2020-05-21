#include <iostream>
using namespace std;

int prime[3000005] = {1, 1}, n, r, num[35] ,ans;

void func(int start, int sum , int deep) {
    if (deep == r) {
        if (prime[sum] == 0) ans++;
        return ;
    }
    for (int i = start; i < n - r + deep + 1; i++) {
        sum += num[i];
        func(i + 1, sum, deep + 1);
        sum -= num[i];
    }
}

int main() {
    for (int i = 2; i * i <= 3000000; i++) {
        if (!prime[i]) {
            for (int j = 2; i * j <= 3000000; j++) {
                prime[i * j] = 1;
            }
        }
    }
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    func(0, 0, 0);
    cout << ans << endl;
    return 0;
}

