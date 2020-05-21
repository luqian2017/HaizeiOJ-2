#include <iostream>
using namespace std;

int m, t, ans;

int check(int x) {
    while (x) {
        if (x % 10 == t) return 1; //如果有诅咒数字 虚拟楼层就+1
            x /= 10;
    }
    return 0;
}

int main() {
    cin >> m >> t;
    for (int i = 1; i <= m; i++) {
        while (check(i)) i++;
        ans++;
    }
    cout << ans << endl;
    return 0;
    
}

