#include <iostream>
using namespace std;

int n, m, num[15], cnt;

void func(int s, int left) {
    if (left == 0) { // 递归出口的return不能忘，否则会出现段错误
        for (int i = 0; i < cnt; i++) {
            if (i) cout << " ";
            cout << num[i];
        }
        cout << endl;
        return ; 
    }
    for (int i = s; i <= n; i++) {
        num[cnt++] = i;
        func(i + 1, left - 1);
        cnt--;
    }
    return ;
}

int main() {
    while (cin >> n >> m) {
        func(1, m);
    }
    return 0;
}
