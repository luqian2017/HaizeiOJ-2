#include <iostream>
using namespace std;

int n, m, num[15], cnt;

int func(int s, int left_num, int left_cnt) {
    if (left_cnt == 0) {
        if (left_num == 0) {
            for (int i = 0; i < cnt; i++) {
                if (i) cout << " ";
                cout << num[i];
            }
            cout << endl;
            return 1;
        }
        return 0;
    }
    int ans = 0;
    for (int i = s; i <= left_num; i++) {
        num[cnt++] = i;
        ans += func(i, left_num - i, left_cnt - 1);
        cnt--;
    }
    return ans;
}

int main() {
    while (cin >> n >> m) {
        cout << func(1, n, m) << endl;
    }
    return 0;
}
