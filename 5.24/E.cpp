#include <iostream>
using namespace std;

int x, y, ans;

int check(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return 1;
    return 0;
}

int main() {
    cin >> x >> y;
    for (int i = x; i <= y; i++) {
        if(check(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}

