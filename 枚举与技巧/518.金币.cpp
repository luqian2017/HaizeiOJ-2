#include <iostream>
using namespace std;

int day, ans;

int main() {
    int x, ans = 0, num = 1, day= 0;
    cin >> x;
    while (1) {
        for (int i = 0; i < num; i++) { //循环条件
            ans += num;
            day++;
            if (x == day) {
                cout << ans << endl;
                return 0;
            }
        }
        num++;
    }
    return 0;
}

