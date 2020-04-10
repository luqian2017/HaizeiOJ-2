#include <iostream>
#include <algorithm>
using namespace std;

void func(int s, int left) {
    if (left == 0) {
        return ;
    }
    for (int i = s; i < c; i++) {
        ans[ans_cnt] = let[i];
        ans_cnt++;
        if (let[i] == 'a' || let[i] == 'e' ||let[i] == 'i' ||let[i] == 'o' ||let[i] == 'u') {

        }
    }
}

int l, c, ans_cnt;
char let[30], ans[30];

int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> let[i];
    }
    sort(let, let + c);
    func(0, l);
    return 0;
}
