#include <iostream>
using namespace std;

long long int a, b, p, ans = 1;

int main() {
    cin >> a >> b >> p;
    int t = b;
    for (int i = 0; i < t; i++) {
        ans *= a;
        ans %= p;
    }
    cout << ans % p << endl;
    return 0;
}
