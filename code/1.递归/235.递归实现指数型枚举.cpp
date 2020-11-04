#include <iostream>
using namespace std;

int n, num[15], cnt;

void p() {
    for (int i = 0; i < cnt; i++) {
        if (i) cout << " ";
        cout << num[i];
    }
    cout << endl;
    return ;
}

void func(int s) { // 因为后面选的数不能超过前面选的数，所以选数时的起点显得尤为重要
    for (int i = s; i <= n; i++) {
        num[cnt++] = i;
        p();
        func(i + 1);
        cnt--;
    }
    return ;
}


int main() {
    while (cin >> n) {
        func(1);
    }
    return 0;
}
