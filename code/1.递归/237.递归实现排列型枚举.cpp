#include <iostream>
using namespace std;

int n, num[15], mark[15], cnt;

void func(int left) {
    if (left == 0) {
        for (int i = 0; i < cnt; i++) {
            if (i) cout << " ";
            cout << num[i];
        }
        cout << endl;
        return ;
    }
    for (int i = 1; i <= n; i++) { // 后面的数不一定要比前面的数大，所以起点从 1 起，但是需要使用标记数组来避免重复使用某个数
        if (!mark[i]) {
            mark[i] = 1;
            num[cnt++] = i;
            func(left - 1);
            cnt--;
            mark[i] = 0;
        }
    }
    return ;
}

int main() {
    while (cin >> n) {
        func(n);
    }
    return 0;
}
