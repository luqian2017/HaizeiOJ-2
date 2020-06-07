#include <iostream>
using namespace std;

int n, ans;

int main() {
    cin >> n;
    ans = n % 10;
    n /= 10;
    ans = ans * 10 + n;
    cout << ans << endl;
    return 0;
}

