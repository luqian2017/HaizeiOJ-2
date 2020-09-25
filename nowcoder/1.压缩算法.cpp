#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main() {
    string s;
    cin >> s;
    stack<char> sta;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] ==']') {
            char t[100005] = {0}; //用于存储 | 到 ] 的内容
            int cnt = 0;
            while (sta.top() != '|') {
                t[cnt++] = sta.top();
                sta.pop();
            }
            sta.pop();
            int times = 0, ind = 1;
            while (sta.top() != '[') {
                times += (sta.top() - '0') * ind;
                ind *= 10;
                sta.pop();
            }
            sta.pop();
            for (int j = 0; j < times; j++) {
                for (int k = cnt - 1; k >= 0; k--) {
                    sta.push(t[k]);
                }
            }
        } else {
            sta.push(s[i]);
        }
    }
    char ans[100005] = {0};
    int cnt = 0;
    while (!sta.empty()) {
        ans[cnt++] = sta.top();
        sta.pop();
    }
    for (int i = cnt - 1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}

