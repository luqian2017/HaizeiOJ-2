#include <iostream>
#include <stack>
using namespace std;

long long n, num[100005], ans1[100005], ans2[100005];

int main() {
    stack<int> qian, hou;
    cin >> n;
    qian.push(99999999);
    hou.push(999999999);
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        ans1[i] = qian.size();
        while (qian.top() <= num[i]) {
            qian.pop();
        }
        qian.push(num[i]);
    }
    for (int i = n; i >= 1; i--) {
        ans2[i] = hou.size();
        while (hou.top() <= num[i]) {
            hou.pop();
        }
        hou.push(num[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (i != 1) {
            cout << " ";
        }
        cout << ans1[i] + ans2[i] - 1;
    }
    cout << endl;
    return 0;
}

