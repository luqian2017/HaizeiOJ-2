#include <iostream>
#include <algorithm>
using namespace std;

int l, c, ans_cnt, yuan, fu, cnt;
char let[30], ans[30];

int func(int s, int left) {
    if (left == 0) {
        //符合条件
        if (yuan >= 1 && fu >= 2) {
            for (int i = 0; i < ans_cnt; i++) {
                cout << ans[i];
            }
            cout << endl;
            cnt++;
            if (cnt == 25000) {
                return -1;
            }
        }
        return 0;
    }
    for (int i = s; i < c; i++) { //注意起点的赋值
        ans[ans_cnt++] = let[i];
        int f = 0;
        if (let[i] == 'a' || let[i] == 'e' || let[i] == 'i' || let[i] == 'o' || let[i] == 'u') {
            yuan++;
            f = 1;
        } else {
            fu++;
        }
        if (func(i + 1, left - 1) == -1) return -1;
        if (f) {
            yuan--;
        } else {
            fu--;
        }
        ans_cnt--;
    }
    return 0;
}

int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) cin >> let[i];
    sort(let, let + c);
    func(0, l);
    return 0;
}
