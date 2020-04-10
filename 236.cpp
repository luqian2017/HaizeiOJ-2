#include <iostream>
using namespace std;

int n, m, num[15], cnt;

void func(int s, int left){
    if (left == 0) {
        for (int i = 0; i < cnt; i++) {
            if (i > 0) {
                cout << " ";
            }
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
}

int main() {
    cin >> n >> m;
    func(1, m);
    return 0;
}
